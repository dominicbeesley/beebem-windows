#ifndef _FB_INTCON_H_
#define _FB_INTCON_H_


#pragma once
#include "fb_fishbone.h"
#include "fb_abs_master.h"
#include "fb_abs_slave.h"
#include <vector>

using namespace std;

class fb_intcon;

class fb_intcon_sla : public fb_abs_slave {
public:
	fb_intcon_sla(fb_intcon& _intcon) :
		intcon(_intcon) {}

	// Inherited via fb_abs_slave
	virtual void init(fb_abs_master & _mas) override;
	virtual void fb_set_cyc(fb_cyc_action cyc) override;
	virtual void fb_set_A(uint32_t addr, bool we) override;
	virtual void fb_set_D_wr(uint8_t dat) override;

	friend class fb_intcon_mas;

private:
	fb_intcon& intcon;
	fb_abs_master* mas;

};

class fb_intcon_mas : public fb_abs_master {
public:
	fb_intcon_mas(fb_intcon& _intcon) :
		intcon(_intcon) {}
	// Inherited via fb_abs_master
	virtual void init(fb_abs_slave & _sla) override;
	virtual void fb_set_ACK(fb_ack ack) override;
	virtual void fb_set_D_rd(uint8_t dat) override;

	friend class fb_intcon_sla;

private:
	fb_intcon& intcon;
	fb_abs_slave* sla;

};

class fb_intcon : public fb_abs_tickable {

public:
	fb_intcon(int slaves, int masters) 
	{
		for (int i = 0; i < slaves; i++)
			sla_v.push_back(fb_intcon_sla(*this));
		for (int i = 0; i < masters; i++)
			mas_v.push_back(fb_intcon_mas(*this));

	}
	   
	vector<fb_intcon_mas>& getMas() { return mas_v; };
	vector<fb_intcon_sla>& getSla() { return sla_v; };

private:

	vector<fb_intcon_mas> mas_v;
	vector<fb_intcon_sla> sla_v;


	// Inherited via fb_abs_tickable
	virtual void tick(bool sys) override;

	virtual void tock() override;

	virtual void reset() override;

};



#endif // !_FB_INTCON_H_
