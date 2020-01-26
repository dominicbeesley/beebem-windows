// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m65c02.c

    MOS Technology 6502, CMOS variant with some additional instructions
    (but not the bitwise ones)

***************************************************************************/

#include "emu.h"
#include "m65c02.h"


m65c02_device::m65c02_device() :
	m6502_device()
{
}

void m65c02_device::prefetch()
{
	sync = true;
	//sync_w(ASSERT_LINE);
	NPC = PC;
	ADDR = PC;
	RNW = true;
	NextFn = PrefetchNextFn;
}

void m65c02_device::fetch() {
	PrefetchNextFn = &m65c02_device::postfetch;
	prefetch();
}

void m65c02_device::fetch_noirq() {
	skip_ints_next = true;
	PrefetchNextFn = &m65c02_device::postfetch;
	prefetch();
}


void m65c02_device::postfetch()
{
	IR = DAT;
	sync = false;
	//sync_w(CLEAR_LINE);

	if (!skip_ints_next && (nmi_state || (irq_state && !(P & F_I))) && !inhibit_interrupts) {
		irq_taken = true;
		IR = 0x00;
	}
	else
		PC++;
	skip_ints_next = false;
	postfetch_int();
}

#include "m65c02.cxx"
