#include "stdafx.h"
#include "fb_intcon.h"
#include "blitter_top.h"

void fb_intcon_sla::init(fb_abs_master & _mas)
{
	this->mas = &_mas;
}

void fb_intcon_sla::do_discon() {
	if (crossbar_connected && crossbar_mas) {
		crossbar_connected = false;
		if (crossbar_mas->sla)
			crossbar_mas->sla->fb_set_cyc(stop);
		crossbar_mas->crossbar_sla = NULL;
	}
	crossbar_connected = false;
}

void fb_intcon_sla::do_try_connect() {
	if (crossbar_idx < 0 || crossbar_idx >= intcon.masters)
	{
		if (mas)
			mas->fb_set_ACK(nul);
		crossbar_connected = false;
		crossbar_pend = false;
	}
	else {
		crossbar_connected = false;
		crossbar_pend = false;
		crossbar_mas = intcon.mas_a[crossbar_idx];
		if (crossbar_mas->sla) {
			if (crossbar_mas->crossbar_sla)
				//busy
				crossbar_pend = true;
			else
			{
				crossbar_connected = true;
				crossbar_mas->crossbar_sla = this;
				crossbar_mas->sla->fb_set_A(crossbar_addr, crossbar_we);
				crossbar_mas->sla->fb_set_cyc(start);
				if (crossbar_d_wr_pend)
					crossbar_mas->sla->fb_set_D_wr(crossbar_d_wr);
			}
		}
		else {
			// slave not connected
			if (mas)
				mas->fb_set_ACK(nul);
		}
	}
}

void fb_intcon_sla::tick(bool sys)
{
	if (mas) mas->tick(sys);
}

void fb_intcon_sla::tock()
{
	if (mas) mas->tock();
}

void fb_intcon_sla::fb_set_cyc(fb_cyc_action cyc)
{
	if (cyc == start) {
		crossbar_d_wr_pend = false;
		do_discon();
		do_try_connect();
	} else {
		do_discon();
	}
}

void fb_intcon_sla::fb_set_A(uint32_t addr, bool we)
{
	crossbar_addr = addr;
	crossbar_we = we;
	crossbar_idx = intcon.top.addr2slaveno(addr);
}

void fb_intcon_sla::fb_set_D_wr(uint8_t dat)
{
	crossbar_d_wr = dat;
	if (crossbar_connected)
		crossbar_mas->sla->fb_set_D_wr(dat);
}

void fb_intcon_sla::reset()
{
	crossbar_addr = 0;
	crossbar_connected = false;
	crossbar_pend = false;
	crossbar_mas = NULL;
	crossbar_we = false;
	crossbar_idx = -1;
	crossbar_d_wr_pend = false;
	crossbar_d_wr = 0;
}

void fb_intcon_mas::init(fb_abs_slave & _sla)
{
	this->sla = &_sla;
}

void fb_intcon_mas::fb_set_ACK(fb_ack ack)
{
	if (crossbar_sla)
		crossbar_sla->mas->fb_set_ACK(ack);
}

void fb_intcon_mas::fb_set_D_rd(uint8_t dat)
{
	if (crossbar_sla)
		crossbar_sla->mas->fb_set_D_rd(dat);
}

void fb_intcon_mas::reset()
{
	crossbar_sla = NULL;
}

void fb_intcon_mas::tick(bool sys)
{
	if (sla) sla->tick(sys);
}

void fb_intcon_mas::tock()
{
	if (sla) sla->tock();
}

void fb_intcon::tick(bool sys)
{
	fb_intcon_sla **p = sla_a;
	for (int i = 0; i < slaves; i++)
	{
		(*(p++))->tick(sys);
	}
	fb_intcon_mas **p2 = mas_a;
	for (int i = 0; i < masters; i++)
	{
		(*(p2++))->tick(sys);
	}
}

void fb_intcon::tock()
{
	fb_intcon_mas **p2 = mas_a;
	for (int i = 0; i < masters; i++)
	{
		(*(p2++))->tock();
	}
	fb_intcon_sla **p = sla_a;
	for (int i = 0; i < slaves; i++)
	{
		(*(p++))->tock();
	}
}

void fb_intcon::reset()
{
	for (int i = 0; i < masters; i++)
	{
		mas_a[i]->reset();
	}
	for (int i = 0; i < slaves; i++)
	{
		sla_a[i]->reset();
	}
}
