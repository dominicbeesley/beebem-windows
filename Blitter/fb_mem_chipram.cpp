#include "stdafx.h"
#include "fb_mem_chipram.h"

void fb_mem_chipram::init(fb_abs_master & mas)
{
	this->mas = &mas;
	reset();
}

void fb_mem_chipram::fb_set_cyc(fb_cyc_action cyc)
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

void fb_mem_chipram::fb_set_A(uint32_t addr, bool we)
{
	this->addr = addr;
	this->we = we;
}

void fb_mem_chipram::fb_set_D_wr(uint8_t dat)
{
	D_wr = dat;
	if (state == actwaitwr)
		state = actwr;
}

void fb_mem_chipram::tick(bool sys)
{
	if (state == actwr)
	{
		mem[addr & 0x1FFFFF] = D_wr;
		mas->fb_set_ACK(ack);
	}
	else if (state == actrd && mas) 
	{
		mas->fb_set_D_rd(mem[addr & 0x1FFFFF]);
		mas->fb_set_ACK(ack);
	}
}

void fb_mem_chipram::tock()
{
}

void fb_mem_chipram::reset()
{
	state = idle;
}
