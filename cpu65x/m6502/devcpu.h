// license:BSD-3-Clause
// copyright-holders:Aaron Giles
/***************************************************************************

    devcpu.h

    CPU device definitions.

***************************************************************************/
#ifndef MAME_EMU_DEVCPU_H
#define MAME_EMU_DEVCPU_H

#pragma once

#include "mametypes.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> cpu_device

class cpu_device //:  //public device_t,
//					public device_execute_interface,
//					public device_memory_interface//,
//					public device_state_interface,
//					public device_disasm_interface
{
public:

	virtual void start() = 0;
	virtual void reset() = 0;

	virtual void execute_set_input(int inputnum, int state) = 0;

	virtual bool tick() = 0;

protected:


};

#endif // MAME_EMU_DEVCPU_H
