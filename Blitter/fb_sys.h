#ifndef _FB_SYS_H_
#define _FB_SYS_H_

#pragma once
#include "fb_abs_slave.h"
#include "fb_abs_master.h"
#include "fb_abs_tickable.h"

class blitter_top;

class fb_sys : public fb_abs_slave, public fb_abs_tickable
{

public:

	uint8_t get_reg_rompage() { return reg_rompage; };

	enum sys_state { idle, act_rd, act_wr, act_wr_gotdata, wait_sys_tick, wait_mas_rel } state;

	fb_sys(blitter_top& _top) : top(_top) {};

	// Inherited via fb_abs_slave
	virtual void init(fb_abs_master & mas) override;

	virtual void fb_set_cyc(fb_cyc_action cyc) override;

	virtual void fb_set_A(uint32_t addr, bool we) override;

	virtual void fb_set_D_wr(uint8_t dat) override;

	// Inherited via fb_abs_tickable
	virtual void tick(bool sys) override;
	virtual void tock() override;

	virtual void reset() override;



private:
	bool we;
	uint32_t addr;
	bool cyc_pend;

	bool sys_tock;
	bool sys_tick_dly;
	bool sys_tock_dly;

	bool d_wr_pend;
	uint8_t d_wr;

	blitter_top& top;
	fb_abs_master *mas;

	uint8_t reg_rompage;
};

#endif //!_FB_SYS_H_
