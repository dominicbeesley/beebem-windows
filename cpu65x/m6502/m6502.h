// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m6502.h

    MOS Technology 6502, original NMOS variant

***************************************************************************/

#ifndef MAME_CPU_M6502_M6502_H
#define MAME_CPU_M6502_M6502_H

//DB:
#include "emu.h"
#include <iostream>

class m6502_device : public cpu_device {
public:

	enum {
		IRQ_LINE = INPUT_LINE_IRQ0,
		NMI_LINE = INPUT_LINE_NMI,
		V_LINE = INPUT_LINE_IRQ0 + 16
	};

	/*m6502_device();*/
	   
	friend std::ostream& operator<<(std::ostream& o, m6502_device &dev);

	bool get_sync() const { return sync; }
	uint16_t getPC() { return PC; }
	uint16_t getADDR() { return ADDR; }
	uint8_t getDATA() { return DAT; }
	bool getRNW() { return RNW; }
	void setDATA(uint8_t val) { DAT = val; }

	virtual void execute_set_input(int inputnum, int state) override;
	virtual bool execute_input_edge_triggered(int inputnum) const noexcept override;

	virtual void tick() override;

protected:


	enum {
		F_N = 0x80,
		F_V = 0x40,
		F_E = 0x20, // 65ce02
		F_T = 0x20, // M740: replaces A with $00,X in some opcodes when set
		F_B = 0x10,
		F_D = 0x08,
		F_I = 0x04,
		F_Z = 0x02,
		F_C = 0x01
	};

	virtual void init();

	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

	uint16_t  PPC;                    /* previous program counter */
	uint16_t  NPC;                    /* next start-of-instruction program counter */
	uint16_t  PC;                     /* program counter */
	uint16_t  SP;                     /* stack pointer (always 100 - 1FF) */
	uint16_t  TMP;                    /* temporary internal values */
	uint8_t   TMP2;                   /* another temporary internal value, 8 bits this time */
	uint8_t   A;                      /* Accumulator */
	uint8_t   X;                      /* X index register */
	uint8_t   Y;                      /* Y index register */
	uint8_t   P;                      /* Processor status */
	uint8_t   IR;                     /* Prefetched instruction register */

	uint16_t  ADDR;
	uint8_t   DAT;
	bool	  RNW;
	bool	  skip_ints_next;			  /* Do not check for interrupts on this fetch*/

	
	bool nmi_state, irq_state, v_state;
	bool irq_taken, sync, inhibit_interrupts;

	virtual void postfetch();
	virtual void prefetch();
	virtual void fetch();
	virtual void fetch_noirq();

	void set_nz(uint8_t v);


	// inline helpers
	bool page_changing(uint16_t base, int delta) { return ((base + delta) ^ base) & 0xff00; }
	uint16_t set_l(uint16_t base, uint8_t val) { return (base & 0xff00) | val; }
	uint16_t set_h(uint16_t base, uint8_t val) { return (base & 0x00ff) | (val << 8); }

	void dec_SP() { SP = set_l(SP, SP - 1); }
	void inc_SP() { SP = set_l(SP, SP + 1); }

	void do_adc_d(uint8_t val);
	void do_adc_nd(uint8_t val);
	void do_sbc_d(uint8_t val);
	void do_sbc_nd(uint8_t val);
	void do_arr_d();
	void do_arr_nd();

	void do_adc(uint8_t val);
	void do_cmp(uint8_t val1, uint8_t val2);
	void do_sbc(uint8_t val);
	void do_bit(uint8_t val);
	void do_arr();
	uint8_t do_asl(uint8_t v);
	uint8_t do_lsr(uint8_t v);
	uint8_t do_ror(uint8_t v);
	uint8_t do_rol(uint8_t v);
	uint8_t do_asr(uint8_t v);

#include "m6502.hxx"

private:
	typedef void (m6502_device::*StatFn)();
	StatFn	  NextFn;
	StatFn	  PrefetchNextFn;


};

enum {
	M6502_IRQ_LINE = m6502_device::IRQ_LINE,
	M6502_NMI_LINE = m6502_device::NMI_LINE,
	M6502_SET_OVERFLOW = m6502_device::V_LINE
};



#endif // MAME_CPU_M6502_M6502_H
