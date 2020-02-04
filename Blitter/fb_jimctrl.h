#ifndef _FB_JIMCTRL_H_
#define _FB_JIMCTRL_H_

#pragma once
#include "emu.h"
#include "fb_abs_slave.h"

class blitter_top;

class fb_jimctrl :public fb_abs_slave, fb_abs_tickable
{
public:
	fb_jimctrl(blitter_top& _top) : top(_top) {};

	enum fb_mem_chipram_state { idle, actrd, actwaitwr, actwr } state;

	// Inherited via fb_abs_slave
	virtual void init(fb_abs_master & mas) override;
	virtual void fb_set_cyc(fb_cyc_action cyc) override;
	virtual void fb_set_A(uint32_t addr, bool we) override;
	virtual void fb_set_D_wr(uint8_t dat) override;

	// Inherited via fb_abs_tickable
	virtual void tick(bool sys) override;
	virtual void tock() override;
	virtual void reset() override;

protected:
	blitter_top& top;
	fb_abs_master* mas;

	uint32_t addr;
	bool we;
	uint8_t D_wr;
	bool D_wr_pend;
};

#endif // !_FB_JIMCTRL_H_

