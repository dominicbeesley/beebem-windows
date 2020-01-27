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

/* 6502Core - header - David Alan Gilbert 16/10/94 */

#ifndef CORE6502_HEADER
#define CORE6502_HEADER

#include "port.h"
#include <stdio.h>
#include <iostream>

void DumpRegs(void);

typedef enum IRQ_Nums {
	SysIrq_SysVia,
	SysIrq_UserVia,
	SysIrq_Serial,
	SysIrq_Tube,
	SysIrq_Teletext,
	SysIrq_Hdc,
} SysIrq_Nums;

typedef enum NMI_Nums {
	SysNmi_floppy,
	SysNmi_econet,
} SysNmi_Nums;

typedef enum PSR_Flags
{
	Flag65C = 1,
	Flag65Z = 2,
	Flag65I = 4,
	Flag65D = 8,
	Flag65B = 16,
	Flag65V = 64,
	Flag65N = 128
} PSR6502_Flags;

extern std::ofstream *hog_o;
extern unsigned char SysIntStatus;
extern unsigned char SysNMIStatus;
extern unsigned int SysCycles;
extern int SysPrevSyncPC;
extern CycleCountT TotalCycles;
extern int DisplayCycles;
extern int CyclesToInt;
#define NO_TIMER_INT_DUE -1000000

#define SetTrigger(after, var) var = TotalCycles + (after)
#define IncTrigger(after, var) var += (after)
#define ClearTrigger(var) var=CycleCountTMax;
#define AdjustTrigger(var) if (var!=CycleCountTMax) var-=CycleCountWrap;

/*-------------------------------------------------------------------------*/
/* Initialise 6502core                                                     */
void InitSys(void);

/*-------------------------------------------------------------------------*/
/* Execute one 6502 instruction, move program counter on                   */
void ExecSys2MCycles(void);
void ExecSys2MCycles(int n);

void core_dumpstate(void);
void Save6502UEF(FILE *SUEF);
void Load6502UEF(FILE *SUEF);
void SyncIO(void);
void AdjustForIORead(void);
void AdjustForIOWrite(void);

#ifdef M512COPRO_ENABLED
int i186_execute(int num_cycles);
#endif

extern bool BHardware;
#endif
