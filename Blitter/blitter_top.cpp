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

	intcon.getMas().at(0).init(sys);
	sys.init(intcon.getMas().at(0));

	intcon.getSla().at(0).init(cpu);
	cpu.init(intcon.getSla().at(0));


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

uint32_t blitter_top::log2phys(uint32_t ain) {
	bool map0n1 = true;	//TODO: choose processor

//	A_o <=
//		x"8D3F" & A_i(7 downto 0)
//		when A_i(23 downto 8) = x"0000" and m68k_boot_i = '1'
	if (ain & 0xFF0000 == 0xFF0000)
	{
		uint16_t ain16 = (uint16_t)ain;
		if (ain16 >= 0x8000 && ain16 < 0xC000 && get_cfg_swram_en())
		{
			if ((reg_ROMPG & 0x0F) < 4 || (reg_ROMPG & 0x0F) >= 8) {

				if (map0n1) {
					if (reg_ROMPG & 0x01) {
						//SWROM from eerpom 8E 0000 - 8F FFFF
						return 0x8E0000 + ((reg_ROMPG & 0x0E) << 13) + (ain & 0x3FFF);
					}
					else {
						//SWRAM from chipram 7E 0000 - 7F FFFF
						return 0x7E0000 + ((reg_ROMPG & 0x0E) << 13) + (ain & 0x3FFF);

					}
				}
				else {
					if (reg_ROMPG & 0x01) {
						//SWROM from eerpom 8C 0000 - 8D FFFF
						return 0x8C0000 + ((reg_ROMPG & 0x0E) << 13) + (ain & 0x3FFF);
					}
					else {
						//SWRAM from chipram 7C 0000 - 7D FFFF
						return 0x7C0000 + ((reg_ROMPG & 0x0E) << 13) + (ain & 0x3FFF);

					}

				}
			}
		}
		else if ((ain16 >= 0xC000 && ain16 < 0xFC00) || (ain16 >= 0xFF00)) {
			// MOS
			
			if (get_nioice_debug_shadow()) {
				if ((ain16 & 0xF000) == 0xC000) {
					//NOICE shadow ram from hidden slot #4 of map 0
					return 0x7E8000 + ain16 & 0x0FFF;
				}
				else {
					if (map0n1)
						return 0x9FC000 + ain16 & 0x3FFF; //NOICE shadow MOS from slot #F map 0
					else
						return 0x9DC000 + ain16 & 0x3FFF; //NOICE shadow MOS from slot #F map 1
				}
			}
			else if (get_swmos_shadow()) {
				if (map0n1)
					return 0x7F0000 + ain16 & 0x3FFF; //SWMOS from slot #8 map 0
				else
					return 0x7D0000 + ain16 & 0x3FFF; //SWMOS from slot #8 map 1
			}
			else if (!map0n1) {
				// normal mos map 1 from slot 9
				return 0x9D0000 + ain16 & 0x3FFF; //SWMOS from slot #8 map 1
			}
		}
		else if (ain16 < 0x8000) {
			if (get_blturbo() & 1 < ((ain16 & 0x7000) >> 12))
				return ain16 & 0x7FFF;
		}
		else if ((ain16 & 0xFF00) == 0xFD00 && get_JIMEN()) {
			return (get_JIMPAGE() << 8) | (ain16 & 0xFF);

		}
	}

	return ain & 0xFFFFFF;
}
