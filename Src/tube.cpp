/****************************************************************
BeebEm - BBC Micro and Master 128 Emulator
Copyright (C) 1994  David Alan Gilbert
Copyright (C) 1997  Mike Wyatt
Copyright (C) 2001  Richard Gellman

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public 
License along with this program; if not, write to the Free 
Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
Boston, MA  02110-1301, USA.
****************************************************************/

/* 6502 core - 6502 emulator core - David Alan Gilbert 16/10/94 */
/* Mike Wyatt 7/6/97 - Added undocumented instructions */
/* Copied for 65C02 Tube core - 13/04/01 */

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "6502core.h"
#include "log.h"
#include "main.h"
#include "beebmem.h"
#include "tube.h"
#include "debug.h"
#include "uefstate.h"
#include "z80mem.h"
#include "z80.h"
#include "Arm.h"
#include "sprowcopro.h"

#include "r65c02.h"
#include <string>
#include <iostream>
#include <fstream>

#ifdef WIN32
#include <windows.h>
#define INLINE inline
#else
#define INLINE
#endif

// Some interrupt set macros
#define SETTUBEINT(a) TubeintStatus|=1<<a
#define RESETTUBEINT(a) TubeintStatus&=~(1<<a)

static int CurrentInstruction;
unsigned char TubeRam[65536];
bool TubeEnabled, AcornZ80, EnableTube;
#ifdef M512COPRO_ENABLED
bool Tube186Enabled;
#endif

CycleCountT TotalTubeCycles = 0;

unsigned char TubeintStatus=0; /* bit set (nums in IRQ_Nums) if interrupt being caused */
unsigned char TubeNMIStatus=0; /* bit set (nums in NMI_Nums) if NMI being caused */

r65c02_device cpu;


// Staus bits
enum TubeFlags {
	TubeQ=1,         // Host IRQ from reg 4
	TubeI=2,         // Parasite IRQ from reg 1
	TubeJ=4,         // Parasite IRQ from reg 4
	TubeM=8,         // Parasite NMI from reg 3
	TubeV=16,        // Two byte op for reg 3
	TubeP=32,        // Parasite processor reset
	TubeT=64,        // Tube reset (write only)
	TubeNotFull=64,  // Reg not full (read only)
	TubeS=128,       // Set control flags mask (write only)
	TubeDataAv=128   // Data available (read only)
};

// Tube registers
unsigned char R1Status; // Q,I,J,M,V,P flags

unsigned char R1PHData[TubeBufferLength * 2];
int R1PHPtr;
unsigned char R1HStatus;
unsigned char R1HPData;
unsigned char R1PStatus;

unsigned char R2PHData;
unsigned char R2HStatus;
unsigned char R2HPData;
unsigned char R2PStatus;

unsigned char R3PHData[2];
unsigned char R3PHPtr;
unsigned char R3HStatus;
unsigned char R3HPData[2];
unsigned char R3HPPtr;
unsigned char R3PStatus;

unsigned char R4PHData;
unsigned char R4HStatus;
unsigned char R4HPData;
unsigned char R4PStatus;

/*-------------------------------------------------------------------*/
// Tube interupt functions
void UpdateR1Interrupt(void) {
	if ((R1Status & TubeI) && (R1PStatus & TubeDataAv))
		SETTUBEINT(R1);
	else
		RESETTUBEINT(R1);
}

void UpdateR4Interrupt(void) {
	if ((R1Status & TubeJ) && (R4PStatus & TubeDataAv))
		SETTUBEINT(R4);
	else
		RESETTUBEINT(R4);
}

void UpdateR3Interrupt(void) {
	if ((R1Status & TubeM) && !(R1Status & TubeV) &&
		( (R3HPPtr > 0) || (R3PHPtr == 0) ))
		TubeNMIStatus|=(1<<R3);
	else if ((R1Status & TubeM) && (R1Status & TubeV) &&
		( (R3HPPtr > 1) || (R3PHPtr == 0) ))
		TubeNMIStatus|=(1<<R3);
	else
		TubeNMIStatus&=~(1<<R3);
}

void UpdateHostR4Interrupt(void) {
	setIRQ(SysIrq_Tube, ((R1Status & TubeQ) != 0) && ((R4HStatus & TubeDataAv) != 0));
}


/*-------------------------------------------------------------------*/
// Torch tube memory/io handling functions

bool TorchTubeActive = false;

void UpdateInterrupts()
{
	UpdateR1Interrupt();
	UpdateR3Interrupt();
	UpdateR4Interrupt();
	UpdateHostR4Interrupt();
}

unsigned char ReadTorchTubeFromHostSide(unsigned char IOAddr) 
{
	unsigned char TmpData;

	TmpData = 0xff;
	
	if (!TorchTubeActive) 
		return MachineType == Model::Master128 ? 0xff : 0xfe;

	switch (IOAddr) {
	case 0:
		TmpData=R1HStatus | R1Status;
		break;
	case 1:
		TmpData=R1PHData[0];
		R1HStatus&=~TubeDataAv;
		R1PStatus|=TubeNotFull;
		break;

// Data available in Z80 tube ?
// Bit #2 says data available to read in 0xfee1
// Bit #10 says room available to write to 0xfee1

	case 0x0d:
		TmpData = 0;
		
		if (R1HStatus & TubeDataAv) TmpData |= 0x02;
		if (R1HStatus & TubeNotFull) TmpData |= 0x10;
		
		break;

	case 0x10:

//		trace = 1;
		
		break;
	}

	// WriteLog("ReadTorchTubeFromHostSide - Addr = %02x, Value = %02x\n", (int)IOAddr, (int)TmpData);

	if (DebugEnabled) {
		char info[200];
		sprintf(info, "Tube: Read from host, addr %X value %02X\r\n", (int)IOAddr, (int)TmpData);
		DebugDisplayTrace(DebugType::Tube, true, info);
	}

	return TmpData;
}

void WriteTorchTubeFromHostSide(unsigned char IOAddr,unsigned char IOData) 
{
	// WriteLog("WriteTorchTubeFromHostSide - Addr = %02x, Value = %02x\n", (int)IOAddr, (int)IOData);

	if (DebugEnabled) {
		char info[200];
		sprintf(info, "Tube: Write from host, addr %X value %02X\r\n", (int)IOAddr, (int)IOData);
		DebugDisplayTrace(DebugType::Tube, true, info);
	}

	if (IOAddr == 0x02 && IOData == 0xff) TorchTubeActive = true;

	switch (IOAddr) {
	case 1:
		// S bit controls write of status flags
		if (IOData & TubeS)
			R1Status|=(IOData & 0x3f);
		else
			R1Status&=~IOData;

		// Reset required?
		if (R1Status & TubeP)
			ResetTube65C02();
		if (R1Status & TubeT)
			ResetTube();

		// Update interrupt flags
		UpdateR1Interrupt();
		UpdateR3Interrupt();
		UpdateR4Interrupt();
		UpdateHostR4Interrupt();
		break;
	case 0:
		R1HPData = IOData;
		R1PStatus|=TubeDataAv;
		R1HStatus&=~TubeNotFull;
		UpdateR1Interrupt();
		break;

// Echo back to tube ?

	case 0x08 :
//		WriteTorchTubeFromHostSide(1, IOData);
		break;
		
	case 0x0c :
		if (IOData == 0xaa)
		{
			init_z80();
			Enable_Z80 = true;
		}
		break;
		
	case 0x0e:
		break;
	}
}

unsigned char ReadTorchTubeFromParasiteSide(unsigned char IOAddr) 
{
	unsigned char TmpData;

	switch (IOAddr) {
	case 0:
		TmpData=R1PStatus | R1Status;
		break;
	case 1:
		TmpData = R1HPData;
		R1PStatus&=~TubeDataAv;
		R1HStatus|=TubeNotFull;
		UpdateR1Interrupt();
		break;
	}

	// WriteLog("ReadTorchTubeFromParasiteSide - Addr = %02x, Value = %02x\n", (int)IOAddr, (int)TmpData);

	if (DebugEnabled) {
		char info[200];
		sprintf(info, "Tube: Read from para, addr %X value %02X\r\n", (int)IOAddr, (int)TmpData);
		DebugDisplayTrace(DebugType::Tube, false, info);
	}

	return TmpData;
}

void WriteTorchTubeFromParasiteSide(unsigned char IOAddr,unsigned char IOData) 
{
	// WriteLog("WriteTorchTubeFromParasiteSide - Addr = %02x, Value = %02x\n", (int)IOAddr, (int)IOData);

	if (DebugEnabled) {
		char info[200];
		sprintf(info, "Tube: Write from para, addr %X value %02X\r\n", (int)IOAddr, (int)IOData);
		DebugDisplayTrace(DebugType::Tube, false, info);
	}

	switch (IOAddr) {
	case 1:
		R1PHData[0]=IOData;
		R1HStatus|=TubeDataAv;
		R1PStatus&=~TubeNotFull;
		break;
	}
}

/*-------------------------------------------------------------------*/
// Tube memory/io handling functions

unsigned char ReadTubeFromHostSide(unsigned char IOAddr) {
	unsigned char TmpData,TmpCntr;

	if (! (EnableTube ||
#ifdef M512COPRO_ENABLED
		   Tube186Enabled ||
#endif
		   AcornZ80 || ArmTube || ArmCoProTube) ) 
		return MachineType == Model::Master128 ? 0xff : 0xfe;

	switch (IOAddr) {
	case 0:
		TmpData=R1HStatus | R1Status;
		break;
	case 1:
		TmpData=R1PHData[0];
		if (R1PHPtr>0) {
			for (TmpCntr=1;TmpCntr<TubeBufferLength;TmpCntr++)
				R1PHData[TmpCntr-1]=R1PHData[TmpCntr]; // Shift FIFO Buffer
			R1PHPtr--; // Shift FIFO Pointer
			if (R1PHPtr == 0)
				R1HStatus&=~TubeDataAv;
			R1PStatus|=TubeNotFull;
		}
		break;
	case 2:
		TmpData=R2HStatus;
		break;
	case 3:
		TmpData=R2PHData;
		if (R2HStatus & TubeDataAv) {
			R2HStatus&=~TubeDataAv;
			R2PStatus|=TubeNotFull;
		}
		break;
	case 4:
		TmpData=R3HStatus;
		break;
	case 5:
		TmpData=R3PHData[0];
		if (R3PHPtr>0) {
			R3PHData[0]=R3PHData[1]; // Shift FIFO Buffer
			R3PHPtr--; // Shift FIFO Pointer
			if (R3PHPtr == 0) {
				R3HStatus&=~TubeDataAv;
				R3PStatus|=TubeNotFull;
			}
		}
		UpdateR3Interrupt();
		break;
	case 6:
		TmpData=R4HStatus;
		break;
	case 7:
		TmpData=R4PHData;
		if (R4HStatus & TubeDataAv) {
			R4HStatus&=~TubeDataAv;
			R4PStatus|=TubeNotFull;
		}
		UpdateHostR4Interrupt();
		break;
	}
	/*TODO: DB: put back
	if (DebugEnabled && (old_readHIOAddr != IOAddr || old_readHTmpData != TmpData)) {
		char info[200];
		sprintf(info, "Tube: Read from host, addr %X value %02X\r\n", (int)IOAddr, (int)TmpData);
		DebugDisplayTrace(DebugType::Tube, true, info);
	}

	old_readHTmpData = TmpData;
	old_readHIOAddr = IOAddr;
	*/

	return TmpData;
}

void WriteTubeFromHostSide(unsigned char IOAddr,unsigned char IOData) {
	if (! (EnableTube ||
#ifdef M512COPRO_ENABLED
		   Tube186Enabled ||
#endif
		   AcornZ80 || ArmTube || ArmCoProTube) ) 
		return;

	if (DebugEnabled) {
		char info[200];
		sprintf(info, "Tube: Write from host, addr %X value %02X\r\n", (int)IOAddr, (int)IOData);
		DebugDisplayTrace(DebugType::Tube, true, info);
	}

	switch (IOAddr) {
	case 0:
		// S bit controls write of status flags
		if (IOData & TubeS)
			R1Status|=(IOData & 0x3f);
		else
			R1Status&=~IOData;

		// Reset required?
		if (R1Status & TubeP)
			ResetTube65C02();
		if (R1Status & TubeT)
			ResetTube();

		// Update interrupt flags
		UpdateR1Interrupt();
		UpdateR3Interrupt();
		UpdateR4Interrupt();
		UpdateHostR4Interrupt();
		break;
	case 1:
		R1HPData=IOData;
		R1PStatus|=TubeDataAv;
		R1HStatus&=~TubeNotFull;
		UpdateR1Interrupt();
		break;
	case 3:
		R2HPData=IOData;
		R2PStatus|=TubeDataAv;
		R2HStatus&=~TubeNotFull;
		break;
	case 5:
		if (R1Status & TubeV) {
			if (R3HPPtr < 2)
				R3HPData[R3HPPtr++]=IOData;
			if (R3HPPtr == 2) {
				R3PStatus|=TubeDataAv;
				R3HStatus&=~TubeNotFull;
			}
		}
		else {
			R3HPPtr=0;
			R3HPData[R3HPPtr++]=IOData;
			R3PStatus|=TubeDataAv;
			R3HStatus&=~TubeNotFull;
		}
		UpdateR3Interrupt();
		break;
	case 7:
		R4HPData=IOData;
		R4PStatus|=TubeDataAv;
		R4HStatus&=~TubeNotFull;
		UpdateR4Interrupt();
		break;
	}
    //UpdateInterrupts();
}

unsigned char ReadTubeFromParasiteSide(unsigned char IOAddr) {
	unsigned char TmpData;

	if (TorchTube) 
		return ReadTorchTubeFromHostSide(IOAddr);

	switch (IOAddr) {
	case 0:
		TmpData=R1PStatus | R1Status;
		break;
	case 1:
		TmpData=R1HPData;
		if (R1PStatus & TubeDataAv) {
			R1PStatus&=~TubeDataAv;
			R1HStatus|=TubeNotFull;
		}
		UpdateR1Interrupt();
		break;
	case 2:
		TmpData=R2PStatus;
		break;
	case 3:
		TmpData=R2HPData;
		if (R2PStatus & TubeDataAv) {
			R2PStatus&=~TubeDataAv;
			R2HStatus|=TubeNotFull;
		}
		break;
	case 4:
		TmpData=R3PStatus;
		// Tube Spec says top bit in R3PStatus has value 'N', which looks like it is
		// the same as the PNMI status (i.e. H->P data available OR P->H not full).
		if (R3PHPtr == 0)
			TmpData |= 128;
		break;
	case 5:
		TmpData=R3HPData[0];
		if (R3HPPtr>0) {
			R3HPData[0]=R3HPData[1]; // Shift FIFO Buffer
			R3HPPtr--; // Shift FIFO Pointer
			if (R3HPPtr == 0) {
				R3PStatus&=~TubeDataAv;
				R3HStatus|=TubeNotFull;
			}
		}
		UpdateR3Interrupt();
		break;
	case 6:
		TmpData=R4PStatus;
		break;
	case 7:
		TmpData=R4HPData;
		if (R4PStatus & TubeDataAv) {
			R4PStatus&=~TubeDataAv;
			R4HStatus|=TubeNotFull;
		}
		UpdateR4Interrupt();
		break;
	}
//UpdateInterrupts();
/* TODO: DB: put back
	if (DebugEnabled && (old_readPIOAddr != IOAddr || old_readPTmpData != TmpData)) {
		char info[200];
		sprintf(info, "Tube: Read from para, addr %X value %02X\r\n", (int)IOAddr, (int)TmpData);
		DebugDisplayTrace(DebugType::Tube, false, info);
	}

	old_readPTmpData = TmpData;
	old_readPIOAddr = IOAddr;
*/

	// UpdateInterrupts();
	return TmpData;
}

void WriteTubeFromParasiteSide(unsigned char IOAddr,unsigned char IOData)
{
	if (TorchTube) 
	{
		WriteTorchTubeFromParasiteSide(IOAddr, IOData);
		return;
	}

	if (DebugEnabled) {
		char info[200];
		sprintf(info, "Tube: Write from para, addr %X value %02X\r\n", (int)IOAddr, (int)IOData);
		DebugDisplayTrace(DebugType::Tube, false, info);
	}

	switch (IOAddr) {
	case 0:
		// Cannot write status flags from parasite
		break;
	case 1:
		if (R1PHPtr<TubeBufferLength) {
			R1PHData[R1PHPtr++]=IOData;
			R1HStatus|=TubeDataAv;
			if (R1PHPtr==TubeBufferLength)
				R1PStatus&=~TubeNotFull;
		}
		break;
	case 3:
		R2PHData=IOData;
		R2HStatus|=TubeDataAv;
		R2PStatus&=~TubeNotFull;
		break;
	case 5:
		if (R1Status & TubeV) {
			if (R3PHPtr < 2)
				R3PHData[R3PHPtr++]=IOData;
			if (R3PHPtr == 2) {
				R3HStatus|=TubeDataAv;
				R3PStatus&=~TubeNotFull;
			}
		}
		else {
			R3PHPtr=0;
			R3PHData[R3PHPtr++]=IOData;
			R3HStatus|=TubeDataAv;
			R3PStatus&=~TubeNotFull;
		}
		UpdateR3Interrupt();
		break;
	case 7:
		R4PHData=IOData;
		R4HStatus|=TubeDataAv;
		R4PStatus&=~TubeNotFull;
		UpdateHostR4Interrupt();
		break;
	}
    //UpdateInterrupts();
}

/*----------------------------------------------------------------------------*/
void TubeWriteMem(unsigned int IOAddr,unsigned char IOData) {
	if (IOAddr>=0xff00 || IOAddr<0xfef8)
		TubeRam[IOAddr]=IOData;
	else
		WriteTubeFromParasiteSide(IOAddr-0xfef8,IOData);
}

unsigned char TubeReadMem(unsigned int IOAddr) {
	if (IOAddr>=0xff00 || IOAddr<0xfef8)
		return(TubeRam[IOAddr]);
	else
		return(ReadTubeFromParasiteSide(IOAddr-0xfef8));
}


void ResetTube65C02() {
	cpu.reset();
}

/* Reset Tube */
void ResetTube(void) 
{
  memset(R1PHData,0,TubeBufferLength * 2);
  R1PHPtr=0;
  R1HStatus=TubeNotFull;
  R1HPData=0;
  R1PStatus=TubeNotFull;

  R2PHData=0;
  R2HStatus=TubeNotFull;
  R2HPData=0;
  R2PStatus=TubeNotFull;

  R3PHData[0]=0;
  R3PHData[1]=0;
  R3PHPtr=1; // To prevent NMI on reset
  R3HStatus=TubeDataAv | TubeNotFull;
  R3HPData[0]=0;
  R3HPData[1]=0;
  R3HPPtr=0;
  R3PStatus=TubeNotFull;

  R4PHData=0;
  R4HStatus=TubeNotFull;
  R4HPData=0;
  R4PStatus=TubeNotFull;

  TubeintStatus=0;
  TubeNMIStatus=0;
}


/* Initialise 6502core */
void InitTube65C02(void) {

  R1Status=0;
  ResetTube();

  std::string tubeRomName(RomPath);
  tubeRomName += "beebfile/6502Tube.rom";
  //tubeRomName += "beebfile/Client65v2.rom";

  //The fun part, the tube OS is copied from ROM to tube RAM before the processor starts processing
  //This makes the OS "ROM" writable in effect, but must be restored on each reset.
  
  std::ifstream TubeRom(tubeRomName, std::istream::binary);
  
  if (!TubeRom.fail()) {
	  TubeRom.read((char *)(TubeRam + 0xf800), 2048);
	  TubeRom.close();
  }
  else {
	  std::string err = "Failed to load tube rom image at" + tubeRomName;
	  MessageBox(GETHWND, err.c_str(), "Cannot load tube rom", MB_OK | MB_ICONERROR);
  }
  
  cpu.init();
  cpu.reset();
}

#include "via.h"




/*TODO: DB: remove?*/
/*-------------------------------------------------------------------------*/
void WrapTubeCycles(void) {
	TotalTubeCycles -= CycleCountWrap / 2 * 3;
}


/*-------------------------------------------------------------------------*/
/* Execute one 6502 instruction, move program counter on                   */
void ExecTube65C02Cycle(void) {

	cpu.execute_set_input(M6502_IRQ_LINE, TubeintStatus ? ASSERT_LINE : CLEAR_LINE);
	static bool prevNMI = false;
	bool nowNMI = (TubeNMIStatus != 0) ? true : false;

	if (prevNMI == false && nowNMI == true)
		cpu.execute_set_input(M6502_NMI_LINE, ASSERT_LINE);
	prevNMI = nowNMI;

	cpu.tick();
	if (cpu.getRNW())
	{
		cpu.setDATA(TubeReadMem(cpu.getADDR()));
	}
	else {
		TubeWriteMem(cpu.getADDR(), cpu.getDATA());
	}

	TotalTubeCycles++;

} /* Exec6502Instruction */

/*-------------------------------------------------------------------------*/

void SyncTubeProcessor(void) {
	// This proc syncronises the two processors on a cycle based timing.
	// Second pro runs at 3MHz
	while (TotalTubeCycles<(TotalCycles/2*3)) {
		ExecTube65C02Cycle();
	}
}

/*-------------------------------------------------------------------------*/
void DebugTubeState(void)
{
	DebugDisplayInfo("");

	DebugDisplayInfoF("HostTube: R1=%02X R2=%02X R3=%02X R4=%02X R1n=%02X R3n=%02X",
		(int)R1HStatus | R1Status,
		(int)R2HStatus,
		(int)R3HStatus,
		(int)R4HStatus,
		(int)R1PHPtr,
		(int)R3PHPtr);

	DebugDisplayInfoF("ParaTube: R1=%02X R2=%02X R3=%02X R4=%02X R3n=%02X",
		(int)R1PStatus | R1Status,
		(int)R2PStatus,
		(int)R3PStatus,
		(int)R4PStatus,
		(int)R3HPPtr);
}

/*-------------------------------------------------------------------------*/
void SaveTubeUEF(FILE *SUEF) {
	fput16(0x0470,SUEF);
	fput32(45,SUEF);
	fputc(R1Status,SUEF);
	fwrite(R1PHData,1,TubeBufferLength,SUEF);
	fputc(R1PHPtr,SUEF);
	fputc(R1HStatus,SUEF);
	fputc(R1HPData,SUEF);
	fputc(R1PStatus,SUEF);
	fputc(R2PHData,SUEF);
	fputc(R2HStatus,SUEF);
	fputc(R2HPData,SUEF);
	fputc(R2PStatus,SUEF);
	fputc(R3PHData[0],SUEF);
	fputc(R3PHData[1],SUEF);
	fputc(R3PHPtr,SUEF);
	fputc(R3HStatus,SUEF);
	fputc(R3HPData[0],SUEF);
	fputc(R3HPData[1],SUEF);
	fputc(R3HPPtr,SUEF);
	fputc(R3PStatus,SUEF);
	fputc(R4PHData,SUEF);
	fputc(R4HStatus,SUEF);
	fputc(R4HPData,SUEF);
	fputc(R4PStatus,SUEF);
}

void Save65C02UEF(FILE *SUEF) {
	/*TODO: DB: add savestate into cpu models / helper and call here 0x0471*/
}

void Save65C02MemUEF(FILE *SUEF) {
	fput16(0x0472,SUEF);
	fput32(65536,SUEF);
	fwrite(TubeRam,1,65536,SUEF);
}

void LoadTubeUEF(FILE *SUEF) {
	R1Status=fgetc(SUEF);
	fread(R1PHData,1,TubeBufferLength,SUEF);
	R1PHPtr=fgetc(SUEF);
	R1HStatus=fgetc(SUEF);
	R1HPData=fgetc(SUEF);
	R1PStatus=fgetc(SUEF);
	R2PHData=fgetc(SUEF);
	R2HStatus=fgetc(SUEF);
	R2HPData=fgetc(SUEF);
	R2PStatus=fgetc(SUEF);
	R3PHData[0]=fgetc(SUEF);
	R3PHData[1]=fgetc(SUEF);
	R3PHPtr=fgetc(SUEF);
	R3HStatus=fgetc(SUEF);
	R3HPData[0]=fgetc(SUEF);
	R3HPData[1]=fgetc(SUEF);
	R3HPPtr=fgetc(SUEF);
	R3PStatus=fgetc(SUEF);
	R4PHData=fgetc(SUEF);
	R4HStatus=fgetc(SUEF);
	R4HPData=fgetc(SUEF);
	R4PStatus=fgetc(SUEF);
}

void Load65C02UEF(FILE *SUEF) {
	/*TODO: DB: add savestate into cpu models / helper and call here 0x0471*/
}

void Load65C02MemUEF(FILE *SUEF) {
	fread(TubeRam,1,65536,SUEF);
}
