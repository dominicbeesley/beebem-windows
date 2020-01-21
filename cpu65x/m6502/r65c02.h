// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    r65c02.h

    Rockwell 65c02, CMOS variant with bitwise instructions

***************************************************************************/

#ifndef MAME_CPU_M6502_R65C02_H
#define MAME_CPU_M6502_R65C02_H

#include "m65c02.h"

class r65c02_device : public m65c02_device {
public:
	r65c02_device();

protected:

	void prefetch() override;
	void fetch() override;

	#include "r65c02.hxx"

private:
	typedef void (r65c02_device::*StatFn)();
	StatFn	  NextFn;
	StatFn	  PrefetchNextFn;


};

enum {
	R65C02_IRQ_LINE = m6502_device::IRQ_LINE,
	R65C02_NMI_LINE = m6502_device::NMI_LINE,
	R65C02_SET_OVERFLOW = m6502_device::V_LINE
};

#endif // MAME_CPU_M6502_R65C02_H
