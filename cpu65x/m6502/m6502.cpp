// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m6502.c

    MOS Technology 6502, original NMOS variant

***************************************************************************/

#include "emu.h"
#include "m6502.h"






void m6502_device::init()
{
	m65x_device::init();

	NextFn = &m6502_device_reset_0;
}

void m6502_device::device_reset()
{
	NextFn = &m6502_device_reset_0;
	m65x_device::device_reset();

}









#include "m6502.cxx"

