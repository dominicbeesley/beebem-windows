#include "stdafx.h"
#include "fb_cpu.h"

#include "fb_abs_slave.h"

void fb_cpu::tick(bool sys)
{
	if (!sla)
		return;

	if (state == acked) {
		if (cpu.getRNW()) {
			cpu.setDATA(D_rd);
		}
		cpu.tick();
		state = idle;
		sla->fb_set_cyc(stop);
	}
}

void fb_cpu::tock() {
	if (state == idle)
	{
		sla->fb_set_A(0xFF0000 | (uint32_t)cpu.getADDR(), !cpu.getRNW());
		sla->fb_set_cyc(start);
		if (!cpu.getRNW())
			sla->fb_set_D_wr(cpu.getDATA());
	}
}


void fb_cpu::init(fb_abs_slave & sla)
{
	this->sla = &sla;
}

void fb_cpu::fb_set_ACK(fb_ack ack)
{
	state = acked;	//we don't care about nuls just blunder on
}

void fb_cpu::fb_set_D_rd(uint8_t dat)
{
	D_rd = dat;
}


void fb_cpu::reset()
{
	cpu.reset();
	state = idle;
}
