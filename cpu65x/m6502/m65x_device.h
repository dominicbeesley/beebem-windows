// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

	m65x_device.h

	BASE MOS Technology 65xx

***************************************************************************/

#ifndef MAME_CPU_M65X_DEVICE_H
#define MAME_CPU_M65X_DEVICE_H

//DB:
#include "emu.h"
#include <iostream>

class m65x_device;


class m65x_device : public cpu_device {
public:

	//typedef void(*StatFn)(m65x_device &cpu);
	typedef void *StatFn;

	enum {
		IRQ_LINE = INPUT_LINE_IRQ0,
		NMI_LINE = INPUT_LINE_NMI,
		HALT_LINE = INPUT_LINE_HALT,
		V_LINE = INPUT_LINE_V
	};

	bool get_sync() const { return sync; }
	uint16_t getADDR() const { return ADDR; }
	uint8_t getDATA() const { return DAT; }
	bool getRNW() const { return RNW; }
	void setDATA(uint8_t val) { DAT = val; }
	


	m65x_device(void) : cpu_device(),
		//sync_w(*this),
		DAT(0),
		sync(false),
		ADDR(0),
		RNW(true)
	{};

	virtual void init() {

		RNW = true;
		sync = false;
		ADDR = 0;
		DAT = 0;
	};



protected:

	virtual void device_start() override;
	virtual void device_reset() override;


	uint16_t	ADDR;
	uint8_t		DAT;
	bool		RNW;
	bool		sync;

	virtual void postfetch_int() = 0;

};

enum {
	M6502_IRQ_LINE = m65x_device::IRQ_LINE,
	M6502_NMI_LINE = m65x_device::NMI_LINE,
	M6502_SET_OVERFLOW = m65x_device::V_LINE
};



#endif // MAME_CPU_M65X_DEVICE_H
