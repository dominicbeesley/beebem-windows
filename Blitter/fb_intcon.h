#ifndef _FB_INTCON_H_
#define _FB_INTCON_H_


#pragma once
#include "fb_fishbone.h"
#include "fb_abs_master.h"
#include "fb_abs_slave.h"
#include <vector>


using namespace std;

class blitter_top;
class fb_intcon;
class fb_intcon_mas;

class fb_intcon_sla : public fb_abs_slave {
public:
	fb_intcon_sla(fb_intcon& _intcon) :
		intcon(_intcon), mas(0)  {
		reset();
	}

	// Inherited via fb_abs_slave
	virtual void init(fb_abs_master & _mas) override;
	virtual void fb_set_cyc(fb_cyc_action cyc) override;
	virtual void fb_set_A(uint32_t addr, bool we) override;
	virtual void fb_set_D_wr(uint8_t dat) override;

	friend class fb_intcon_mas;
	friend class fb_intcon;

protected:
	void reset();

private:
	fb_intcon& intcon;
	fb_abs_master* mas;

	fb_intcon_mas* crossbar_mas;
	uint32_t crossbar_addr;
	bool crossbar_we;
	int crossbar_idx;	//index of pend slave dev no
	bool crossbar_connected;
	bool crossbar_pend;
	bool crossbar_d_wr_pend;
	uint8_t crossbar_d_wr;

	void do_discon();
	void do_try_connect();
};

class fb_intcon_mas : public fb_abs_master {
public:
	fb_intcon_mas(fb_intcon& _intcon) :
		intcon(_intcon), sla(0) 
	{
		reset();
	}
	// Inherited via fb_abs_master
	virtual void init(fb_abs_slave & _sla) override;
	virtual void fb_set_ACK(fb_ack ack) override;
	virtual void fb_set_D_rd(uint8_t dat) override;

	friend class fb_intcon_sla;
	friend class fb_intcon;

protected:
	void reset();

private:
	fb_intcon& intcon;
	fb_abs_slave* sla;

	fb_intcon_sla* crossbar_sla;

};

class fb_intcon : public fb_abs_tickable {

public:
	fb_intcon(blitter_top& _top, int slaves, int masters) :
		top(_top)
	{
		for (int i = 0; i < slaves; i++)
			sla_v.push_back(fb_intcon_sla(*this));
		for (int i = 0; i < masters; i++)
			mas_v.push_back(fb_intcon_mas(*this));

	}
	   
	vector<fb_intcon_mas>& getMas() { return mas_v; };
	vector<fb_intcon_sla>& getSla() { return sla_v; };

	friend class fb_intcon_mas;
	friend class fb_intcon_sla;

	// Inherited via fb_abs_tickable
	virtual void tick(bool sys) override;

	virtual void tock() override;

	virtual void reset() override;


protected:
	blitter_top& top;

private:

	vector<fb_intcon_mas> mas_v;
	vector<fb_intcon_sla> sla_v;



};



#endif // !_FB_INTCON_H_
