// license:BSD-3-Clause
// copyright-holders:Aaron Giles
/***************************************************************************

	devcpu.h

	CPU device definitions.

***************************************************************************/
#ifndef BLITTER_TOP_H
#define BLITTER_TOP_H

#pragma once

#include "emu.h"
#include "devcpu.h"
#include "m65x_device.h"
#include "m65c02.h"
#include "fb_cpu.h"
#include "fb_sys.h"

typedef enum blit_SLAVE_NO {
	SLAVE_NO_JIMCTL,
	SLAVE_NO_SYS,
	SLAVE_NO_CHIPRAM,
	SLAVE_NO_MEMCTL,
	SLAVE_NO_EEPROM,
	SLAVE_NO_DMA,
	SLAVE_NO_SOUND,
	SLAVE_NO_BLIT,
	SLAVE_NO_AERIS
} blit_SLAVE_NO;

extern blit_SLAVE_NO addr2slaveno(uint32_t addr, bool jimEn);


class blitter_top : public m65x_device {
public:

	blitter_top(void) :
		m65x_device(),
		sys(*this)
	{
	};

	virtual void init() override;

	void tick() override;

	virtual void execute_set_input(int inputnum, int state) override;
	virtual bool execute_input_edge_triggered(int inputnum) override;

	friend class fb_sys;

protected:
	virtual void device_reset() override;

	fb_sys sys;
	fb_cpu cpu;

};



#endif BLITTER_TOP_H
