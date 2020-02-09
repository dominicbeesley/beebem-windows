#ifndef _FB_PAULA_H_
#define _FB_PAULA_H_

#pragma once


#include "fb_abs_tickable.h"
#include "fb_abs_master.h"
#include "fb_abs_slave.h"


/* Much simplified compared to real hardware:

	- single master interface and arbitration done here
	- combined slave interface for all channels and global registers

*/

class fb_paula;


class fb_paula_sla : public fb_abs_slave {

public:

	fb_paula_sla(fb_paula& _paula) : paula(_paula) {};

	// Inherited via fb_abs_slave
	virtual void init(fb_abs_master & mas) override;
	virtual void fb_set_cyc(fb_cyc_action cyc) override;
	virtual void fb_set_A(uint32_t addr, bool we) override;
	virtual void fb_set_D_wr(uint8_t dat) override;

private:
	fb_paula& paula;
};

class fb_paula_mas : public fb_abs_master {

public:

	fb_paula_mas(fb_paula &_paula) : paula(_paula) {};

	// Inherited via fb_abs_master
	virtual void init(fb_abs_slave & sla) override;
	virtual void fb_set_ACK(fb_ack ack) override;
	virtual void fb_set_D_rd(uint8_t dat) override;

private:
	fb_paula& paula;

};

class fb_paula : public fb_abs_tickable
{
public:
	fb_paula() : sla(*this), mas(*this) {};
	virtual ~fb_paula();

	// Inherited via fb_abs_tickable
	virtual void reset() override;
	virtual void tick(bool sys) override;

	fb_paula_sla& getSlave() { return sla; }
	fb_paula_mas& getMaster() { return mas; }

private:
	fb_paula_sla sla;
	fb_paula_mas mas;

};


#endif //!_FB_PAULA_H_