#include "stdafx.h"
#include "blitter_top.h"

blit_SLAVE_NO addr2slaveno(uint32_t addr, bool jimEn) {
	addr = addr & 0x00FFFFFF;
	if (addr = 0xFFFE30) {
		// ROMPG on sys always passed to fb_SYS
		return SLAVE_NO_SYS;
	}
	else if (addr = 0xFFFE36) {
		// EEPROM i2c
		return SLAVE_NO_EEPROM;
	}
	else if ((addr & 0xFFFFF0) == 0xFFFE30 && (addr & 0x0F) != 0x4) {
		// other memctl regs FE31-FE37
		return SLAVE_NO_MEMCTL;
	}
	else if ((addr & 0xFFFFF0) == 0xFEFC90) {
		// FF FC9x DMA
		return SLAVE_NO_DMA;
	}
	else if ((addr & 0xFFFFF0) == 0xFEFC80) {
		// FF FC8x SOUND
		return SLAVE_NO_SOUND;
	}
	else if ((addr & 0xFFFFF0) == 0xFEFC60 
		|| (addr & 0xFFFFF0)   == 0xFEFC70 
		|| (addr & 0xFFFFF0)   == 0xFEFCA0) {
		// FF FC6x, FF FC7x, FF FCAx BLITTER
		return SLAVE_NO_BLIT;
	}
	else if ((addr & 0xFFFFF0) == 0xFEFCB0) {
		// FF FC0x - AERIS
		return SLAVE_NO_AERIS;
	}
	else if ((addr == 0xFFFCFD || addr == 0xFFFCFE) && jimEn) {
		// jim extended paging registers
		// note FCFF is a special case and is always passed on to SYS!
		return SLAVE_NO_JIMCTL;
	}
	else if ((addr & 0xFF0000) == 0xFF0000) {
		// FF xxxx SYS
		return SLAVE_NO_SYS;
	}
	else {
		// everything else to chipram
		return SLAVE_NO_CHIPRAM;
	}
}

void blitter_top::init()
{
	cpu.init(sys);
	sys.init(cpu);
}

void blitter_top::tick()
{
	sys.tick(true);
	cpu.tick(true);
	sys.tock();
	cpu.tock();

	sys.tick(false);
	cpu.tick(false);
	sys.tock();
	cpu.tock();

	sys.tick(false);
	cpu.tick(false);
	sys.tock();
	cpu.tock();

	sys.tick(false);
	cpu.tick(false);
	sys.tock();
	cpu.tock();

}

void blitter_top::execute_set_input(int inputnum, int state)
{
	cpu.execute_set_input(inputnum, state);
}

bool blitter_top::execute_input_edge_triggered(int inputnum)
{
	return cpu.execute_input_edge_triggered(inputnum);
}

void blitter_top::device_reset()
{
	sys.reset();
	cpu.reset();
}
