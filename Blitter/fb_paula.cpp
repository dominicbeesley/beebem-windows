#include "stdafx.h"
#include "fb_paula.h"



fb_paula::~fb_paula()
{
}

void fb_paula::reset()
{
}

void fb_paula::tick(bool sys)
{
}



void fb_paula_sla::init(fb_abs_master & mas)
{
}

void fb_paula_sla::fb_set_cyc(fb_cyc_action cyc)
{
}

void fb_paula_sla::fb_set_A(uint32_t addr, bool we)
{
}

void fb_paula_sla::fb_set_D_wr(uint8_t dat)
{
}

void fb_paula_mas::init(fb_abs_slave & sla)
{
}

void fb_paula_mas::fb_set_ACK(fb_ack ack)
{
}

void fb_paula_mas::fb_set_D_rd(uint8_t dat)
{
}
