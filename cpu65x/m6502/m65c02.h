// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m65c02.h

    MOS Technology 6502, CMOS variant with some additional instructions
    (but not the bitwise ones)

***************************************************************************/
#ifndef MAME_CPU_M6502_M65C02_H
#define MAME_CPU_M6502_M65C02_H

#pragma once

#include "m6502.h"

class m65c02_device : public m6502_device {
public:
	m65c02_device();

protected:

	void postfetch() override;
	void prefetch() override;
	void fetch() override;
	void fetch_noirq() override;

	#include "m65c02.hxx"

private:
	typedef void (m65c02_device::*StatFn)();
	StatFn	  NextFn;
	StatFn	  PrefetchNextFn;

};

enum {
	M65C02_IRQ_LINE = m6502_device::IRQ_LINE,
	M65C02_NMI_LINE = m6502_device::NMI_LINE,
	M65C02_SET_OVERFLOW = m6502_device::V_LINE
};

#endif // MAME_CPU_M6502_M65C02_H
