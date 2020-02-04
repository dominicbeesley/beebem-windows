#include "stdafx.h"
#include "fb_cpu.h"

#include "fb_abs_slave.h"
#include "blitter_top.h"
#include "blitter_const.h"

void fb_cpu::tick(bool sys)
{
	if (!sla)
		return;

	if (state == acked) {
		if (cpu.getRNW()) {
			cpu.setDATA(D_rd);
		}
		else {
			if (physAddr == 0xFFFCFF) {
				top.set_JIMEN(cpu.getDATA() == JIM_DEVNO);				
			}
		}
		cpu.tick();
		state = idle;
		sla->fb_set_cyc(stop);
	}
}

void fb_cpu::tock() {
	if (state == idle)
	{
		bool rnw = cpu.getRNW();
		physAddr = top.log2phys(0x00FF0000 | cpu.getADDR());
		if (physAddr == 0xFFFCFF && rnw && top.get_JIMEN()) {
			D_rd = (uint8_t)~JIM_DEVNO;
			state = acked;
		}
		else {
			state = act;
			sla->fb_set_A(physAddr, !cpu.getRNW());
			sla->fb_set_cyc(start);
			if (!rnw)
				sla->fb_set_D_wr(cpu.getDATA());
		}
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
