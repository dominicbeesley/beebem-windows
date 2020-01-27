// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m6502.h

    MOS Technology 6502, original NMOS variant

***************************************************************************/

#ifndef MAME_CPU_M6502_M6502_H
#define MAME_CPU_M6502_M6502_H


#include "emu.h"
#include "m65x_device.h"
#include <iostream>

class m6502_device;
#include "m6502.top.hxx"

class m6502_device : public m65x_device {
public:


	m6502_device(void) :
		m65x_device()
	{
	};

	virtual void init() override;

protected:

	virtual void device_reset() override;

	//virtual StatFn resetFn() override { return (void *)&m6502_device_reset_0; }
	virtual StatFn postFetchIntFn() override { return (void *)&m6502_device_postfetch_int; }



#include "m6502.hxx"



};




#endif // MAME_CPU_M6502_M6502_H
