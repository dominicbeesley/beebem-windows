// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m6502.c

    MOS Technology 6502, original NMOS variant

***************************************************************************/

#include "emu.h"
#include "m6502.h"
#include <iomanip>


std::ostream& operator<<(std::ostream& o, m6502_device &dev) 
{
	int oldflags = o.flags();
	char oldfill = o.fill();

	o << std::hex;
	o.fill('0');
	
	o << "A:" << std::setw(2) << (int)dev.A;
	o << ", X:" << std::setw(2) << (int)dev.X;
	o << ", Y:" << std::setw(2) << (int)dev.Y;
	o << ", S:" << std::setw(2) << (int)dev.SP;
	o.width(4);
	o << ",PC:" << std::setw(4) << (int)dev.PC;
	o << ",ADR:" << std::setw(4) << (int)dev.ADDR;
	o << ",RnW:" << (dev.RNW)?"R":"W";
	o << ",D:" << std::setw(2) << (int)dev.DAT;
	o << ",IR:" << std::setw(2) << (int)dev.IR;

	o << ", P:";

	int f = dev.P;
	const char flagsTempl[] = "nvobdizc";
	const char *p = flagsTempl;
	for (int i = 0; i < 8; i++) {
		if (f & 0x80)
			o << (char)toupper(*p);
		else
			o << *p;
		*p++;
		f = f << 1;
	}

	//o << ",st:" << std::setw(2) << (int)dev.inst_state << ":" << std::setw(2) << dev.inst_substate;

	if (dev.get_sync()) {
		o << " SYNC";
	}

	o << std::endl;

	o.flags(oldflags);
	o.fill(oldfill);

	return o;
}



m6502_device::m6502_device(void) :
	cpu_device(),
	//sync_w(*this),
	PPC(0), NPC(0), PC(0), SP(0), TMP(0), TMP2(0), A(0), X(0), Y(0), P(0), IR(0), DAT(0),
	NextFn(&m6502_device::reset_0), nmi_state(false), irq_state(false), v_state(false), irq_taken(false), sync(false), inhibit_interrupts(false)
{
}

void m6502_device::device_start()
{
	init();
}

void m6502_device::init()
{
	/*
	mintf->program  = &space(AS_PROGRAM);
	mintf->sprogram = has_space(AS_OPCODES) ? &space(AS_OPCODES) : mintf->program;

	mintf->cache  = mintf->program->cache<0, 0, ENDIANNESS_LITTLE>();
	mintf->scache = mintf->sprogram->cache<0, 0, ENDIANNESS_LITTLE>();
	*/

	//sync_w.resolve_safe();

	/*
	state_add(STATE_GENPC,     "GENPC",     XPC).callexport().noshow();
	state_add(STATE_GENPCBASE, "CURPC",     XPC).callexport().noshow();
	state_add(STATE_GENSP,     "GENSP",     SP).noshow();
	state_add(STATE_GENFLAGS,  "GENFLAGS",  P).callimport().formatstr("%6s").noshow();
	state_add(M6502_PC,        "PC",        NPC).callimport();
	state_add(M6502_A,         "A",         A);
	state_add(M6502_X,         "X",         X);
	state_add(M6502_Y,         "Y",         Y);
	state_add(M6502_P,         "P",         P).callimport();
	state_add(M6502_S,         "SP",        SP);
	state_add(M6502_IR,        "IR",        IR);

	save_item(NAME(PC));
	save_item(NAME(NPC));
	save_item(NAME(PPC));
	save_item(NAME(A));
	save_item(NAME(X));
	save_item(NAME(Y));
	save_item(NAME(P));
	save_item(NAME(SP));
	save_item(NAME(TMP));
	save_item(NAME(TMP2));
	save_item(NAME(IR));
	save_item(NAME(nmi_state));
	save_item(NAME(irq_state));
	save_item(NAME(apu_irq_state));
	save_item(NAME(v_state));
	save_item(NAME(inst_state));
	save_item(NAME(inst_substate));
	save_item(NAME(inst_state_base));
	save_item(NAME(irq_taken));
	save_item(NAME(inhibit_interrupts));
	*/


	PC = 0x0000;
	NPC = 0x0000;
	A = 0x00;
	X = 0x80;
	Y = 0x00;
	P = 0x36;
	SP = 0x0100;
	TMP = 0x0000;
	TMP2 = 0x00;
	IR = 0x00;
	nmi_state = false;
	irq_state = false;
	irq_taken = false;
	v_state = false;
	sync = false;
	inhibit_interrupts = false;
	skip_ints_next = false;
	NextFn = &m6502_device::reset_0;
	ADDR = 0;
	DAT = 0;
}

void m6502_device::device_reset()
{
	NextFn = &m6502_device::reset_0;
	nmi_state = false;
	irq_state = false;
	irq_taken = false;
	v_state = false;
	sync = false;
	//sync_w(CLEAR_LINE);
	inhibit_interrupts = false;
	skip_ints_next = false;
}


bool m6502_device::execute_input_edge_triggered(int inputnum) const noexcept
{
	return inputnum == NMI_LINE;
}

void m6502_device::do_adc_d(uint8_t val)
{
	uint8_t c = P & F_C ? 1 : 0;
	P &= ~(F_N|F_V|F_Z|F_C);
	uint8_t al = (A & 15) + (val & 15) + c;
	if(al > 9)
		al += 6;
	uint8_t ah = (A >> 4) + (val >> 4) + (al > 15);
	if(!uint8_t(A + val + c))
		P |= F_Z;
	else if(ah & 8)
		P |= F_N;
	if(~(A^val) & (A^(ah << 4)) & 0x80)
		P |= F_V;
	if(ah > 9)
		ah += 6;
	if(ah > 15)
		P |= F_C;
	A = (ah << 4) | (al & 15);
}

void m6502_device::do_adc_nd(uint8_t val)
{
	uint16_t sum;
	sum = A + val + (P & F_C ? 1 : 0);
	P &= ~(F_N|F_V|F_Z|F_C);
	if(!uint8_t(sum))
		P |= F_Z;
	else if(int8_t(sum) < 0)
		P |= F_N;
	if(~(A^val) & (A^sum) & 0x80)
		P |= F_V;
	if(sum & 0xff00)
		P |= F_C;
	A = sum;
}

void m6502_device::do_adc(uint8_t val)
{
	if(P & F_D)
		do_adc_d(val);
	else
		do_adc_nd(val);
}

void m6502_device::do_arr_nd()
{
	bool c = P & F_C;
	P &= ~(F_N|F_Z|F_C|F_V);
	A >>= 1;
	if(c)
		A |= 0x80;
	if(!A)
		P |= F_Z;
	else if(int8_t(A)<0)
		P |= F_N;
	if(A & 0x40)
		P |= F_V|F_C;
	if(A & 0x20)
		P ^= F_V;
}

void m6502_device::do_arr_d()
{
	// The adc/ror interaction gives an extremely weird result
	bool c = P & F_C;
	P &= ~(F_N|F_Z|F_C|F_V);
	uint8_t a = A >> 1;
	if(c)
		a |= 0x80;
	if(!a)
		P |= F_Z;
	else if(int8_t(a) < 0)
		P |= F_N;
	if((a ^ A) & 0x40)
		P |= F_V;

	if((A & 0x0f) >= 0x05)
		a = ((a + 6) & 0x0f) | (a & 0xf0);

	if((A & 0xf0) >= 0x50) {
		a += 0x60;
		P |= F_C;
	}
	A = a;
}

void m6502_device::do_arr()
{
	if(P & F_D)
		do_arr_d();
	else
		do_arr_nd();
}

void m6502_device::do_cmp(uint8_t val1, uint8_t val2)
{
	P &= ~(F_N|F_Z|F_C);
	uint16_t r = val1-val2;
	if(!r)
		P |= F_Z;
	else if(int8_t(r) < 0)
		P |= F_N;
	if(!(r & 0xff00))
		P |= F_C;
}

void m6502_device::do_sbc_d(uint8_t val)
{
	uint8_t c = P & F_C ? 0 : 1;
	P &= ~(F_N|F_V|F_Z|F_C);
	uint16_t diff = A - val - c;
	uint8_t al = (A & 15) - (val & 15) - c;
	if(int8_t(al) < 0)
		al -= 6;
	uint8_t ah = (A >> 4) - (val >> 4) - (int8_t(al) < 0);
	if(!uint8_t(diff))
		P |= F_Z;
	else if(diff & 0x80)
		P |= F_N;
	if((A^val) & (A^diff) & 0x80)
		P |= F_V;
	if(!(diff & 0xff00))
		P |= F_C;
	if(int8_t(ah) < 0)
		ah -= 6;
	A = (ah << 4) | (al & 15);
}

void m6502_device::do_sbc_nd(uint8_t val)
{
	uint16_t diff = A - val - (P & F_C ? 0 : 1);
	P &= ~(F_N|F_V|F_Z|F_C);
	if(!uint8_t(diff))
		P |= F_Z;
	else if(int8_t(diff) < 0)
		P |= F_N;
	if((A^val) & (A^diff) & 0x80)
		P |= F_V;
	if(!(diff & 0xff00))
		P |= F_C;
	A = diff;
}

void m6502_device::do_sbc(uint8_t val)
{
	if(P & F_D)
		do_sbc_d(val);
	else
		do_sbc_nd(val);
}

void m6502_device::do_bit(uint8_t val)
{
	P &= ~(F_N|F_Z|F_V);
	uint8_t r = A & val;
	if(!r)
		P |= F_Z;
	if(val & 0x80)
		P |= F_N;
	if(val & 0x40)
		P |= F_V;
}

uint8_t m6502_device::do_asl(uint8_t v)
{
	P &= ~(F_N|F_Z|F_C);
	uint8_t r = v<<1;
	if(!r)
		P |= F_Z;
	else if(int8_t(r) < 0)
		P |= F_N;
	if(v & 0x80)
		P |= F_C;
	return r;
}

uint8_t m6502_device::do_lsr(uint8_t v)
{
	P &= ~(F_N|F_Z|F_C);
	if(v & 1)
		P |= F_C;
	v >>= 1;
	if(!v)
		P |= F_Z;
	return v;
}

uint8_t m6502_device::do_ror(uint8_t v)
{
	bool c = P & F_C;
	P &= ~(F_N|F_Z|F_C);
	if(v & 1)
		P |= F_C;
	v >>= 1;
	if(c)
		v |= 0x80;
	if(!v)
		P |= F_Z;
	else if(int8_t(v)<0)
		P |= F_N;
	return v;
}

uint8_t m6502_device::do_rol(uint8_t v)
{
	bool c = P & F_C;
	P &= ~(F_N|F_Z|F_C);
	if(v & 0x80)
		P |= F_C;
	v <<= 1;
	if(c)
		v |= 0x01;
	if(!v)
		P |= F_Z;
	else if(int8_t(v)<0)
		P |= F_N;
	return v;
}

uint8_t m6502_device::do_asr(uint8_t v)
{
	P &= ~(F_N|F_Z|F_C);
	if(v & 1)
		P |= F_C;
	v >>= 1;
	if(!v)
		P |= F_Z;
	else if(v & 0x40) {
		P |= F_N;
		v |= 0x80;
	}
	return v;
}


void m6502_device::execute_set_input(int inputnum, int state)
{
	switch(inputnum) {
	case IRQ_LINE: irq_state = state == ASSERT_LINE; break;
	case NMI_LINE: nmi_state = nmi_state || (state == ASSERT_LINE); break;
	case V_LINE:
		if(!v_state && state == ASSERT_LINE)
			P |= F_V;
		v_state = state == ASSERT_LINE;
		break;
	}
}

void m6502_device::tick() {
	(this->*NextFn)();
}

void m6502_device::prefetch()
{
	sync = true;
	//sync_w(ASSERT_LINE);
	NPC = PC;
	ADDR = PC;
	RNW = true;
	NextFn = PrefetchNextFn;
}

void m6502_device::fetch() {
	PrefetchNextFn = &m6502_device::postfetch;
	prefetch();
}

void m6502_device::fetch_noirq() {
	skip_ints_next = true;
	PrefetchNextFn = &m6502_device::postfetch;
	prefetch();
}


void m6502_device::postfetch()
{
	IR = DAT;
	sync = false;
	//sync_w(CLEAR_LINE);

	if(!skip_ints_next && (nmi_state || (irq_state  && !(P & F_I))) && !inhibit_interrupts) {
		irq_taken = true;
		IR = 0x00;
	} else
		PC++;
	skip_ints_next = false;
	postfetch_int();
}


void m6502_device::set_nz(uint8_t v)
{
	P &= ~(F_Z|F_N);
	if(v & 0x80)
		P |= F_N;
	if(!v)
		P |= F_Z;
}


#include "m6502.cxx"

