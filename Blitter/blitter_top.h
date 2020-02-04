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
#include "fb_intcon.h"

typedef enum blit_SLAVE_NO {
	SLAVE_NO_JIMCTL,
	SLAVE_NO_SYS,
	SLAVE_NO_CHIPRAM,
	SLAVE_NO_MEMCTL,
	SLAVE_NO_EEPROM,
	SLAVE_NO_DMA,
	SLAVE_NO_SOUND,
	SLAVE_NO_BLIT,
	SLAVE_NO_AERIS,
	SLAVE_NO__COUNT
} blit_SLAVE_NO;



class blitter_top : public m65x_device {
public:

	blitter_top(void) :
		m65x_device(),
		sys(*this),
		cpu(*this),
		intcon(*this, 1, SLAVE_NO__COUNT)
	{
	};

	virtual void init() override;

	void tick() override;

	virtual void execute_set_input(int inputnum, int state) override;
	virtual bool execute_input_edge_triggered(int inputnum) override;

	friend class fb_sys;

	void set_ROMPG(uint8_t d) {
		reg_ROMPG = d;
	};
	uint8_t get_ROMPG() { return reg_ROMPG; };
	void set_JIMEN(bool b) {
		reg_jimEn = b;
	};
	bool get_JIMEN() {
		return reg_jimEn;
	};
	void set_JIMPAGE_L(uint8_t d) {
		reg_jimPage = (reg_jimPage & 0xFF00) | (uint16_t)d;
	}
	void set_JIMPAGE_H(uint8_t d) {
		reg_jimPage = (reg_jimPage & 0xFF) | ((uint16_t)d) << 8;
	}
	uint8_t get_JIMPAGE_L() { return (uint8_t)reg_jimPage; }
	uint8_t get_JIMPAGE_H() { return (uint8_t)(reg_jimPage >> 8); }
	uint8_t get_JIMPAGE() { return reg_jimPage; }

	uint32_t log2phys(uint32_t ain);
	blit_SLAVE_NO addr2slaveno(uint32_t addr);

	bool get_cfg_swram_en() { return true;}
	bool get_nioice_debug_shadow() { return false; }
	bool get_swmos_shadow() { return false; }
	uint8_t get_blturbo() { return 0x00; }

protected:
	virtual void device_reset() override;

	fb_sys sys;
	fb_cpu cpu;

	fb_intcon intcon;

	uint8_t reg_ROMPG;
	bool	reg_jimEn;
	uint16_t reg_jimPage;

};



#endif BLITTER_TOP_H
