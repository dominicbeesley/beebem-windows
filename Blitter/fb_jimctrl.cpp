#include "stdafx.h"
#include "fb_jimctrl.h"
#include "blitter_top.h"


void fb_jimctrl::init(fb_abs_master & mas)
{
	this->mas = &mas;
	reset();
}

void fb_jimctrl::fb_set_cyc(fb_cyc_action cyc)
{
	if (cyc = stop) {
		state = idle;
	}
	else {
		if (we)
			state = actwaitwr;
		else
			state = actrd;
	}

}

void fb_jimctrl::fb_set_A(uint32_t addr, bool we)
{
	this->addr = addr;
	this->we = we;
}

void fb_jimctrl::fb_set_D_wr(uint8_t dat)
{
	D_wr = dat;
	if (state == actwaitwr)
		state = actwr;
}

void fb_jimctrl::tick(bool sys)
{
	if (state == actwr)
	{
		if (addr & 0x0F == 0x0E)
			top.set_JIMPAGE_L(D_wr);
		else if (addr & 0x0F == 0x0E)
			top.set_JIMPAGE_H(D_wr);
		mas->fb_set_ACK(ack);
	}
	else if (state == actrd && mas)
	{
		if (addr & 0x0F == 0x0E)
			mas->fb_set_D_rd(top.get_JIMPAGE_L());
		else if (addr & 0x0F == 0x0F)
			mas->fb_set_D_rd(top.get_JIMPAGE_H());
		mas->fb_set_ACK(ack);
	}
}

void fb_jimctrl::tock()
{
}

void fb_jimctrl::reset()
{
	state = idle;
}
