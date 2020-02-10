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

#ifdef WIN32
#include <windows.h>
#endif

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "6502core.h"
#include "beebmem.h"
#include "beebsound.h"
#include "music5000.h"
#include "hog1mpaula.h"
#include "SIDwrap.h"
#include "disc8271.h"
#include "via.h"
#include "sysvia.h"
#include "uservia.h"
#include "video.h"
#include "atodconv.h"
#include "log.h"
#include "main.h"
#include "disc1770.h"
#include "serial.h"
#include "tube.h"
#include "debug.h"
#include "uefstate.h"
#include "z80mem.h"
#include "z80.h"
#include "econet.h"
#include "scsi.h"
#include "ide.h"
#include "debug.h"
#include "Arm.h"
#include "sprowcopro.h"
#include "m6502.h"
#include "m65c02.h"
#include "blitter_top.h"

#ifdef WIN32
#define INLINE inline
#else
#define INLINE
#endif

using namespace std;

int CyclesToInt = 0;
unsigned char SysIntStatus;
unsigned char SysNMIStatus;
bool BHardware;

void PollVIAs();
void PollHardware(int nCycles);

extern CArm *arm;
extern CSprowCoPro *sprow;

CycleCountT TotalCycles=0;

int DisplayCycles=0;
int SysPrevSyncPC;


m65x_device *m6502;

ofstream *hog_o;

void AdjustForIOWrite() {

}

void AdjustForIORead() {

}


void SyncIO() {

}

void ExecSys2MCycles(int n) {
	for (int i = 0; i < n; i++)
		ExecSys2MCycles();
}

void ExecSys2MCycles() {

	/* TODO: DB: put back debugger stuff*/

	z80_execute();
	if (Enable_Arm)
		arm->exec(4);

	if (Enable_ArmCoPro)
	{
#if _DEBUG
		sprow->exec(2);
#else
		sprow->exec(8);
#endif
	}
#ifdef M512COPRO_ENABLED
	if (Tube186Enabled)
		i186_execute(12 * 4);
#endif

	if (m6502 != NULL) {
		static bool prevNMI = false;
		bool nowNMI = (SysNMIStatus != 0) ? true : false;

		m6502->execute_set_input(M6502_IRQ_LINE, (SysIntStatus) ? ASSERT_LINE : CLEAR_LINE);
		if (prevNMI == false && nowNMI == true)
			m6502->execute_set_input(M6502_NMI_LINE, ASSERT_LINE);
		prevNMI = nowNMI;

		//hoglet decoder binary out
		if (hog_o) {
			uint8_t d = m6502->getDATA();
			hog_o->write((const char *)&d, 1);
			d =
				(m6502->getRNW() ? 0x01 : 00)
				+ (m6502->get_sync() ? 0x02 : 00)
				;
			hog_o->write((const char *)&d, 1);
		}

		m6502->tick();

		uint16_t a = m6502->getADDR();
		if (m6502->get_sync())
			SysPrevSyncPC = a;
		if (m6502->getRNW())
			m6502->setDATA(BeebReadMem(a));
		else
			BeebWriteMem(a, m6502->getDATA());
	}
	/*TODO: DB: Put back
	// Check for WRCHV, send char to speech output
	if (mainWin->m_TextToSpeechEnabled &&
		ProgramCounter == (WholeRam[0x20e] + (WholeRam[0x20f] << 8)))
		mainWin->SpeakChar(Accumulator);
	*/

	TotalCycles ++;

	PollVIAs();
	PollHardware(1);
	
	if (EnableTube)
		SyncTubeProcessor();

}

bool blitter_enabled = false;

void InitSys(bool powerReset) {
	if (m6502 == NULL
		|| (blitter_enable != blitter_enabled)
		) {

		if (m6502)
			delete m6502;

		if (blitter_enable)
			m6502 = new blitter_top(&SoundVolume);
		else if (MachineType == Model::Master128)
			m6502 = new m65c02_device();
		else
			m6502 = new m6502_device();
		blitter_enabled = blitter_enable;
	}
	else {
		if (blitter_enable && powerReset) {
			((blitter_top *)m6502)->powerReset();
		}
	}
	m6502->start();
	m6502->reset();

	
}

void PollVIAs()
{
	if (CyclesToInt != NO_TIMER_INT_DUE)
		CyclesToInt --;

	SysVIA_poll();
	UserVIA_poll();

}

void PollHardware(int nCycles)
{

	if (TotalCycles > CycleCountWrap)
	{
		TotalCycles -= CycleCountWrap;
		AdjustTrigger(AtoDTrigger);
		AdjustTrigger(SoundTrigger);
		AdjustTrigger(Disc8271Trigger);
		AdjustTrigger(AMXTrigger);
		AdjustTrigger(PrinterTrigger);
		AdjustTrigger(VideoTriggerCount);
		AdjustTrigger(TapeTrigger);
		AdjustTrigger(EconetTrigger);
		AdjustTrigger(EconetFlagFillTimeoutTrigger);
		AdjustTrigger(IP232RxTrigger);
		if (EnableTube)
			WrapTubeCycles();
	}

	VideoPoll(nCycles);
	if (!BHardware) {
		AtoD_poll(nCycles);
		Serial_Poll();
	}
	Disc8271Poll(nCycles);
	Music5000Poll(nCycles);
	Hog1MPaulaPoll(nCycles);
	SIDPoll(nCycles);
	Sound_Trigger(nCycles);
	if (DisplayCycles > 0) DisplayCycles-=nCycles; // Countdown time till end of display of info.
	if (MachineType == Model::Master128 || !NativeFDC) Poll1770(1); // Do 1770 Background stuff

	if (EconetEnabled && EconetPoll()) {
		if (EconetNMIenabled) {
			SysNMIStatus |= 1 << SysNmi_econet;
			if (DebugEnabled)
				DebugDisplayTrace(DebugType::Econet, true, "Econet: NMI asserted");
		}
		else {
			if (DebugEnabled)
				DebugDisplayTrace(DebugType::Econet, true, "Econet: NMI requested but supressed");
		}
	}
}



/*-------------------------------------------------------------------------*/
void Save6502UEF(FILE *SUEF) {
	/*TODO: DB: put back*/
}

void Load6502UEF(FILE *SUEF) {
	/*TODO: DB: put back*/
}

/*-------------------------------------------------------------------------*/
/* Dump state                                                              */
void core_dumpstate(void) {
  cerr << "core:\n";
}
