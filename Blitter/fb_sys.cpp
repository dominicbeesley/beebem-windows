#include "stdafx.h"
#include "fb_sys.h"
#include "blitter_top.h"

void fb_sys::init(fb_abs_master & mas)
{
	this->mas = &mas;
}

void fb_sys::fb_set_cyc(fb_cyc_action cyc)
{
	if (cyc == start) {
		cyc_pend = true;
	} else {
		if (state == act_rd) {
			state = idle;
		} else if (state == act_wr) {
			state = wait_sys_tick;
		} else if (state == act_wr_gotdata) {
			state = wait_sys_tick;
		} else if (state == wait_mas_rel) {
			state = idle;
		}

		cyc_pend = false;
		d_wr_pend = false;
	}
}

void fb_sys::fb_set_A(uint32_t addr, bool we)
{
	this->addr = addr;
	this->we = we;
}

void fb_sys::fb_set_D_wr(uint8_t dat)
{
	if (!mas)
		return;

	d_wr = dat;
	d_wr_pend = true;

	if (state == act_wr)
	{
		top.setDATA(dat);
		state = act_wr_gotdata;
		mas->fb_set_ACK(ack);
	}
}

void fb_sys::tick(bool sys)
{
	if (!mas)
		return;
	if (sys) {
		if (state == act_rd) {
			mas->fb_set_D_rd(top.getDATA());
			mas->fb_set_ACK(ack);
			state = idle;
		}
		else if (state == wait_sys_tick)
		{
			state = idle;
		}
	}

	sys_tock = sys;
	sys_tick_dly = sys;
}

void fb_sys::tock() {

	if (!mas)
		return;
	if (sys_tock_dly)
	{
		if (state == idle && cyc_pend) {
			top.ADDR = addr;
			top.RNW = !we;
			if (we) {
				if (d_wr_pend) {
					top.setDATA(d_wr);
					state = act_wr_gotdata;
					mas->fb_set_ACK(ack);
				} else {
					state = act_wr;
				}
			}
			else {
				state = act_rd;
			}
		}
	}


	sys_tock_dly = sys_tock;
}

void fb_sys::reset()
{
	state = idle;
	sys_tock_dly = false;
	sys_tick_dly = false;
	we = false;
	addr = 0;
	reg_rompage = 0;
}
