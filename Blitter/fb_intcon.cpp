#include "stdafx.h"
#include "fb_intcon.h"

void fb_intcon_sla::init(fb_abs_master & _mas)
{
	this->mas = &_mas;
}

void fb_intcon_sla::fb_set_cyc(fb_cyc_action cyc)
{
	intcon.getMas().at(0).sla->fb_set_cyc(cyc);
}

void fb_intcon_sla::fb_set_A(uint32_t addr, bool we)
{
	intcon.getMas().at(0).sla->fb_set_A(addr, we);
}

void fb_intcon_sla::fb_set_D_wr(uint8_t dat)
{
	intcon.getMas().at(0).sla->fb_set_D_wr(dat);
}

void fb_intcon_mas::init(fb_abs_slave & _sla)
{
	this->sla = &_sla;
}

void fb_intcon_mas::fb_set_ACK(fb_ack ack)
{
	intcon.getSla().at(0).mas->fb_set_ACK(ack);
}

void fb_intcon_mas::fb_set_D_rd(uint8_t dat)
{
	intcon.getSla().at(0).mas->fb_set_D_rd(dat);
}

void fb_intcon::tick(bool sys)
{
}

void fb_intcon::tock()
{
}

void fb_intcon::reset()
{
}
