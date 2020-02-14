#include "stdafx.h"
#include "fb_dmac_dma.h"
#include "blitter_top.h"

void fb_dmac_dma::reset()
{
	channel_sel = 0;
	
	dma_channelreg_t *p = channel_regs;

	for (int i = 0; i < DMA_CHANNELS; i++) {

		p->ctl_act = false;
		p->ctl_step_src = step_none;
		p->ctl_step_dest = step_none;
		p->ctl_halt = false;
		p->ctl_extend = false;
		p->ctl2_pause = false;
		p->ctl2_if = false;
		p->ctl2_ie = false;
		p->ctl2_stepsize = stepsize_byte;
		p->src_addr = 0;
		p->dest_addr = 0;
		p->data = 0;
		p->count = 0;
		p->pause_val = 0;
		p->count_finish = false;
		p->count_clken = false;
		p->pause_ct_dn = 0;
		p->pause_ct_dn_finished = false;
		p->mas_cyc = false;

		p++;
	}
	sla.reset();
	mas.reset();

}

void fb_dmac_dma::tick(bool sys)
{


	dma_channelreg_t *curchan = channel_regs;



	//this is a very rough approximation of what really happens in terms of prioritisation
	//but should be close enough - normally data accesses that clash will be queued up
	//by intcon and could take many 8M cycles but here we just always deliver the data!
	for (int i = 0; i < DMA_CHANNELS; i++)
	{

/*		if (curchan->clken_sam_next)
		{
			int addr = (((int)curchan->addr_bank) << 16) + (int)curchan->addr + (int)curchan->sam_ctr;
			if (mas.getByte(addr, i))
				curchan->clken_sam_next = false;

			if (curchan->sam_ctr == curchan->len)
			{
				if (curchan->repeat)
				{
					curchan->sam_ctr = curchan->repoff;
				}
				else
				{
					curchan->act = false;
					curchan->sam_ctr = 0;
				}
			}
			else
			{
				curchan->sam_ctr++;
			}

			break;
		}*/
		curchan++;
	}
}


void fb_dmac_dma::init() {
	reset();
}

void fb_dmac_dma::byte_got(uint8_t channel, int8_t dat)
{
	channel_regs[channel].data = dat;

	///!!!! state machine advance...
}

void fb_dmac_dma::write_regs(uint8_t addr, uint8_t dat)
{

	uint8_t a = addr & 0x0F;

	if (a == A_SEL)
	{
		channel_sel = dat % DMA_CHANNELS;
		return;
	}
	else {
		dma_channelreg_t *curchan = &channel_regs[channel_sel];
				//note registers are all exposed big-endian style
		switch (addr & 0x0F)
		{
		case A_CTL:
			curchan->ctl_act = (dat & 0x80) != 0;
			curchan->ctl_extend = (dat & 0x20) != 0;
			curchan->ctl_halt = (dat & 0x10) != 0;
			curchan->ctl_step_src = to_step(dat);
			curchan->ctl_step_dest = to_step(dat >> 2);
			curchan->ctl2_if = false;
			update_cpu();
		case A_SRC_ADDR_BANK:
			curchan->src_addr = (((uint32_t)dat) << 16) | (curchan->src_addr & 0x0000FFFF);
		case A_SRC_ADDR:
			curchan->src_addr = (((uint32_t)dat) << 8) | (curchan->src_addr & 0x00FF00FF);
		case A_SRC_ADDR+1:
			curchan->src_addr = (((uint32_t)dat)) | (curchan->src_addr & 0x00FFFF00);
		case A_DEST_ADDR_BANK:
			curchan->dest_addr = (((uint32_t)dat) << 16) | (curchan->dest_addr & 0x0000FFFF);
		case A_DEST_ADDR:
			curchan->dest_addr = (((uint32_t)dat) << 8) | (curchan->dest_addr & 0x00FF00FF);
		case A_DEST_ADDR + 1:
			curchan->dest_addr = (((uint32_t)dat)) | (curchan->dest_addr & 0x00FFFF00);
		case A_COUNT:
			curchan->count = (((uint16_t)dat) << 8) | (curchan->count & 0x00FF);
			curchan->count_finish = false;
		case A_COUNT+1:
			curchan->count = (((uint16_t)dat)) | (curchan->count & 0xFF00);
			curchan->count_finish = false;
		case A_DATA:
			curchan->data = (((uint16_t)dat) << 8) | ((uint16_t)dat);
		case A_CTL2:
			curchan->ctl2_if = false;
			curchan->ctl2_ie = (dat & 0x02) != 0;
			curchan->ctl2_pause = dat & 0x01;
			curchan->ctl2_stepsize = to_stepsize(dat >> 2);
			update_cpu();
		case A_PAUSE_VAL:
			curchan->pause_val = dat;
		}

	}
}

uint8_t fb_dmac_dma::read_regs(uint8_t addr) {
	uint8_t a = addr & 0x0F;

	if (a == A_SEL)
		return channel_sel;
	else {
		dma_channelreg_t *curchan = &channel_regs[channel_sel];
		//note registers are all exposed big-endian style
		switch (a)
		{
		case A_CTL:
			return
				(curchan->ctl_act ? 0x80 : 0)
				| (curchan->ctl_extend ? 0x20 : 0)
				| (curchan->ctl_halt? 0x10 : 0)
				| step_to_int(curchan->ctl_step_dest) << 2
				| step_to_int(curchan->ctl_step_src);
		case A_SRC_ADDR_BANK:
			return curchan->src_addr >> 16;
		case A_SRC_ADDR:
			return curchan->src_addr >> 8;
		case A_SRC_ADDR+1:
			return curchan->src_addr;
		case A_DEST_ADDR_BANK:
			return curchan->dest_addr >> 16;
		case A_DEST_ADDR:
			return curchan->dest_addr >> 8;
		case A_DEST_ADDR + 1:
			return curchan->dest_addr;
		case A_COUNT:
			return curchan->count >> 8;
		case A_COUNT+1:
			return (uint8_t)curchan->count;
		case A_DATA:
			return curchan->data >> 8;
		case A_CTL2:
			return 
				(curchan->ctl2_if ? 0x80 : 0)
				| (stepsize_to_int(curchan->ctl2_stepsize) << 2)
				| (curchan->ctl2_ie ? 0x02 : 0)
				| (curchan->ctl2_pause ? 0x01 : 0)
				;
		case A_PAUSE_VAL:
			return curchan->pause_val;
		default:
			return 255;
			break;
		}
	}

}

void fb_dmac_dma::update_cpu() {


	dma_channelreg_t *p = channel_regs;
	bool halt = false, irq = false;
	for (int i = 0; i < DMA_CHANNELS; i++)
	{
		halt |= p->ctl_act && p->ctl_halt;
		irq |= p->ctl2_ie && p->ctl2_if;
	}
}

void fb_dma_sla::init(fb_abs_master & mas)
{
	this->mas = &mas;
}

void fb_dma_sla::fb_set_cyc(fb_cyc_action cyc)
{
	if (cyc == stop) {
		state = idle;
	}
	else {
		if (we)
			state = actwaitwr;
		else if (mas)
		{
			mas->fb_set_D_rd(dma.read_regs(addr));
			mas->fb_set_ACK(ack);
		}
	}

}

void fb_dma_sla::fb_set_A(uint32_t addr, bool we)
{
	this->addr = addr;
	this->we = we;

}

void fb_dma_sla::fb_set_D_wr(uint8_t dat)
{
	if (state == actwaitwr) {
		dma.write_regs(addr, dat);
		mas->fb_set_ACK(ack);
		state = idle;
	}
}

void fb_dma_sla::reset()
{
	state = idle;
}

void fb_dma_mas::init(fb_abs_slave & sla)
{
	this->sla = &sla;
	reset();
}

void fb_dma_mas::fb_set_ACK(fb_ack ack)
{
	state = idle;
	if (sla)
		sla->fb_set_cyc(stop);
}

void fb_dma_mas::fb_set_D_rd(uint8_t dat)
{
	if (state == actrd) {
		dma.byte_got(cur_chan, dat);
	}
}

void fb_dma_mas::reset()
{
	state = idle;
}

bool fb_dma_mas::get_byte(uint32_t addr, uint8_t channel)
{
	if (state == idle) {
		if (sla) {
			cur_addr = addr;
			cur_chan = channel;
			state = actrd;
			sla->fb_set_A(addr, 0);
			sla->fb_set_cyc(start);
		}
		else {
			dma.byte_got(channel, 0);
		}
		return true;
	}

	return false;
}

bool fb_dma_mas::set_byte(uint32_t addr, uint8_t dat)
{
	if (state == idle) {
		if (sla) {
			cur_addr = addr;
			state = actwr;
			sla->fb_set_A(addr, true);
			sla->fb_set_cyc(start);
			sla->fb_set_D_wr(dat);
		}
		return true;
	}

	return false;
}
