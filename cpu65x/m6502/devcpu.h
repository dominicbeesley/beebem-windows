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
	virtual ~cpu_device();

	void start() {
		device_start();
	}

	void reset() {
		device_reset();
	}

	virtual void execute_set_input(int inputnum, int state) = 0;

	virtual bool tick() = 0;

protected:
	// construction/destruction
	cpu_device();

	virtual void device_start() =0;
	virtual void device_reset() =0;

	void standard_irq_callback(int i) {};
	void logerror(const char *err) {};

};

#endif // MAME_EMU_DEVCPU_H
