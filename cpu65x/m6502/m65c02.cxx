// This file has been automatically produced by makehxx.pl
// do not edit it.
// from file(s) dm65c02.lst D:\Users\Dominic\Documents\GitHub\beebem-windows\cpu65x\m6502\om65c02.lst
#include "m65c02.h"
// --- op adc_aba --- 
void m65c02_device_adc_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_aba_1;return; // READ
}

void m65c02_device_adc_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_aba_2;return; // READ
}

void m65c02_device_adc_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_aba_3;return; // READ
}

void m65c02_device_adc_aba_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_aba_4;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_aba_4(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_abx --- 
void m65c02_device_adc_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_abx_1;return; // READ
}

void m65c02_device_adc_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_abx_2;return; // READ
}

void m65c02_device_adc_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.X)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_abx_3;return; // READ
  }
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_abx_4;return; // READ
}

void m65c02_device_adc_abx_3(m65c02_device &cpu) {
    cpu.TMP += cpu.X;
    cpu.ADDR = cpu.TMP;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_abx_4;return; // READ
}

void m65c02_device_adc_abx_4(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_abx_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_abx_5(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_aby --- 
void m65c02_device_adc_aby_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_aby_1;return; // READ
}

void m65c02_device_adc_aby_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_aby_2;return; // READ
}

void m65c02_device_adc_aby_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.Y)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.Y);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_aby_3;return; // READ
  }
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_aby_4;return; // READ
}

void m65c02_device_adc_aby_3(m65c02_device &cpu) {
    cpu.TMP += cpu.Y;
    cpu.ADDR = cpu.TMP;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_aby_4;return; // READ
}

void m65c02_device_adc_aby_4(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_aby_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_aby_5(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_idx --- 
void m65c02_device_adc_idx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idx_1;return; // READ
}

void m65c02_device_adc_idx_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idx_2;return; // READ
}

void m65c02_device_adc_idx_2(m65c02_device &cpu) {
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idx_3;return; // READ
}

void m65c02_device_adc_idx_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idx_4;return; // READ
}

void m65c02_device_adc_idx_4(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idx_5;return; // READ
}

void m65c02_device_adc_idx_5(m65c02_device &cpu) {
  cpu.do_adc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_idx_6;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_idx_6(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_idy --- 
void m65c02_device_adc_idy_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idy_1;return; // READ
}

void m65c02_device_adc_idy_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idy_2;return; // READ
}

void m65c02_device_adc_idy_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idy_3;return; // READ
}

void m65c02_device_adc_idy_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.Y)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.Y);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_idy_4;return; // READ
  }
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_idy_5;return; // READ
}

void m65c02_device_adc_idy_4(m65c02_device &cpu) {
    cpu.ADDR = cpu.TMP+cpu.Y;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_idy_5;return; // READ
}

void m65c02_device_adc_idy_5(m65c02_device &cpu) {
  cpu.do_adc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_idy_6;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_idy_6(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_imm --- 
void m65c02_device_adc_imm_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_imm_1;return; // READ
}

void m65c02_device_adc_imm_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_imm_2;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_imm_2(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_zpg --- 
void m65c02_device_adc_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpg_1;return; // READ
}

void m65c02_device_adc_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpg_2;return; // READ
}

void m65c02_device_adc_zpg_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_zpg_3;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_zpg_3(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_zpi --- 
void m65c02_device_adc_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpi_1;return; // READ
}

void m65c02_device_adc_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpi_2;return; // READ
}

void m65c02_device_adc_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpi_3;return; // READ
}

void m65c02_device_adc_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpi_4;return; // READ
}

void m65c02_device_adc_zpi_4(m65c02_device &cpu) {
  cpu.do_adc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_zpi_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_zpi_5(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op adc_zpx --- 
void m65c02_device_adc_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpx_1;return; // READ
}

void m65c02_device_adc_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpx_2;return; // READ
}

void m65c02_device_adc_zpx_2(m65c02_device &cpu) {
  cpu.ADDR = uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_adc_zpx_3;return; // READ
}

void m65c02_device_adc_zpx_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_adc_zpx_4;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_adc_zpx_4(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op and_zpi --- 
void m65c02_device_and_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_and_zpi_1;return; // READ
}

void m65c02_device_and_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_and_zpi_2;return; // READ
}

void m65c02_device_and_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_and_zpi_3;return; // READ
}

void m65c02_device_and_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_and_zpi_4;return; // READ
}

void m65c02_device_and_zpi_4(m65c02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op asl_aba --- 
void m65c02_device_asl_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_aba_1;return; // READ
}

void m65c02_device_asl_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_aba_2;return; // READ
}

void m65c02_device_asl_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_aba_3;return; // READ
}

void m65c02_device_asl_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_aba_4;return; // READ
}

void m65c02_device_asl_aba_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_asl_aba_5;return; // WRITE
}

void m65c02_device_asl_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op asl_abx --- 
void m65c02_device_asl_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_abx_1;return; // READ
}

void m65c02_device_asl_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_abx_2;return; // READ
}

void m65c02_device_asl_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_abx_3;return; // READ
}

void m65c02_device_asl_abx_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_abx_4;return; // READ
}

void m65c02_device_asl_abx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_abx_5;return; // READ
}

void m65c02_device_asl_abx_5(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_asl_abx_6;return; // WRITE
}

void m65c02_device_asl_abx_6(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op asl_zpg --- 
void m65c02_device_asl_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpg_1;return; // READ
}

void m65c02_device_asl_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpg_2;return; // READ
}

void m65c02_device_asl_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpg_3;return; // READ
}

void m65c02_device_asl_zpg_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_asl_zpg_4;return; // WRITE
}

void m65c02_device_asl_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op asl_zpx --- 
void m65c02_device_asl_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpx_1;return; // READ
}

void m65c02_device_asl_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpx_2;return; // READ
}

void m65c02_device_asl_zpx_2(m65c02_device &cpu) {
  cpu.TMP = uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpx_3;return; // READ
}

void m65c02_device_asl_zpx_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_asl_zpx_4;return; // READ
}

void m65c02_device_asl_zpx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_asl_zpx_5;return; // WRITE
}

void m65c02_device_asl_zpx_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op bbr_zpb --- 
void m65c02_device_bbr_zpb_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbr_zpb_1;return; // READ
}

void m65c02_device_bbr_zpb_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbr_zpb_2;return; // READ
}

void m65c02_device_bbr_zpb_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbr_zpb_3;return; // READ
}

void m65c02_device_bbr_zpb_3(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbr_zpb_4;return; // READ
}

void m65c02_device_bbr_zpb_4(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (!(cpu.TMP2 & (1 << ((cpu.IR >> 4) & 7)))) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_bbr_zpb_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_bbr_zpb_5(m65c02_device &cpu) {
    if (cpu.page_changing(cpu.PC, int8_t(cpu.TMP))) {
      cpu.ADDR = cpu.set_l(cpu.PC, cpu.PC+int8_t(cpu.TMP));
      cpu.RNW = true;
      cpu.NextFn = (void *)&m65c02_device_bbr_zpb_6;return; // READ
    }
    cpu.PC += int8_t(cpu.TMP);
    m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_bbr_zpb_6(m65c02_device &cpu) {
      cpu.PC += int8_t(cpu.TMP);
      m65x_device_fetch(cpu);return; // fetch
}

// --- op bbs_zpb --- 
void m65c02_device_bbs_zpb_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbs_zpb_1;return; // READ
}

void m65c02_device_bbs_zpb_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbs_zpb_2;return; // READ
}

void m65c02_device_bbs_zpb_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbs_zpb_3;return; // READ
}

void m65c02_device_bbs_zpb_3(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bbs_zpb_4;return; // READ
}

void m65c02_device_bbs_zpb_4(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.TMP2 & (1 << ((cpu.IR >> 4) & 7))) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_bbs_zpb_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_bbs_zpb_5(m65c02_device &cpu) {
    if (cpu.page_changing(cpu.PC, int8_t(cpu.TMP))) {
      cpu.ADDR = cpu.set_l(cpu.PC, cpu.PC+int8_t(cpu.TMP));
      cpu.RNW = true;
      cpu.NextFn = (void *)&m65c02_device_bbs_zpb_6;return; // READ
    }
    cpu.PC += int8_t(cpu.TMP);
    m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_bbs_zpb_6(m65c02_device &cpu) {
      cpu.PC += int8_t(cpu.TMP);
      m65x_device_fetch(cpu);return; // fetch
}

// --- op bit_abx --- 
void m65c02_device_bit_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_abx_1;return; // READ
}

void m65c02_device_bit_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_abx_2;return; // READ
}

void m65c02_device_bit_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.X)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_bit_abx_3;return; // READ
  }
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_abx_4;return; // READ
}

void m65c02_device_bit_abx_3(m65c02_device &cpu) {
    cpu.TMP += cpu.X;
    cpu.ADDR = cpu.TMP;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_bit_abx_4;return; // READ
}

void m65c02_device_bit_abx_4(m65c02_device &cpu) {
  cpu.do_bit(cpu.DAT);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op bit_imm --- 
void m65c02_device_bit_imm_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_imm_1;return; // READ
}

void m65c02_device_bit_imm_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.A & cpu.TMP) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  m65x_device_fetch(cpu);return; // fetch
}

// --- op bit_zpx --- 
void m65c02_device_bit_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_zpx_1;return; // READ
}

void m65c02_device_bit_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_zpx_2;return; // READ
}

void m65c02_device_bit_zpx_2(m65c02_device &cpu) {
  cpu.ADDR = uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bit_zpx_3;return; // READ
}

void m65c02_device_bit_zpx_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_bit(cpu.TMP);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op bra_rel --- 
void m65c02_device_bra_rel_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bra_rel_1;return; // READ
}

void m65c02_device_bra_rel_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_bra_rel_2;return; // READ
}

void m65c02_device_bra_rel_2(m65c02_device &cpu) {
  if (cpu.page_changing(cpu.PC, int8_t(cpu.TMP))) {
    cpu.ADDR = cpu.set_l(cpu.PC, cpu.PC+int8_t(cpu.TMP));
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_bra_rel_3;return; // READ
  }
  cpu.PC += int8_t(cpu.TMP);
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_bra_rel_3(m65c02_device &cpu) {
    cpu.PC += int8_t(cpu.TMP);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op brk_imp --- 
void m65c02_device_brk_imp_0(m65c02_device &cpu) {
  if (cpu.irq_taken || cpu.nmi_state) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_1;return; // READ
  } else {
    cpu.ADDR = cpu.PC++;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_2;return; // READ
  }
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_brk_imp_3;return; // WRITE
}

void m65c02_device_brk_imp_1(m65c02_device &cpu) {
    cpu.ADDR = cpu.SP;
    cpu.DAT =  cpu.PC >> 8;
    cpu.RNW = false;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_3;return; // WRITE
}

void m65c02_device_brk_imp_2(m65c02_device &cpu) {
    cpu.ADDR = cpu.SP;
    cpu.DAT =  cpu.PC >> 8;
    cpu.RNW = false;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_3;return; // WRITE
}

void m65c02_device_brk_imp_3(m65c02_device &cpu) {
  cpu.dec_SP();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_brk_imp_4;return; // WRITE
}

void m65c02_device_brk_imp_4(m65c02_device &cpu) {
  cpu.dec_SP();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.irq_taken || cpu.nmi_state ? cpu.P & ~cpu.F_B : cpu.P;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_brk_imp_5;return; // WRITE
}

void m65c02_device_brk_imp_5(m65c02_device &cpu) {
  cpu.dec_SP();
  if (cpu.irq_taken && cpu.nmi_state) {
    cpu.ADDR = 0xfffa;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_6;return; // READ
  } else {
    cpu.ADDR = 0xfffe;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_8;return; // READ
  }
  cpu.irq_taken = false;
  cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_brk_imp_6(m65c02_device &cpu) {
    cpu.PC = cpu.DAT;
    cpu.ADDR = 0xfffb;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_7;return; // READ
}

void m65c02_device_brk_imp_8(m65c02_device &cpu) {
    cpu.PC = cpu.DAT;
    cpu.ADDR = 0xffff;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_brk_imp_9;return; // READ
}

void m65c02_device_brk_imp_7(m65c02_device &cpu) {
    cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
    cpu.nmi_state = false;
    cpu.standard_irq_callback(cpu.NMI_LINE);
    cpu.irq_taken = false;
    cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
    m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_brk_imp_9(m65c02_device &cpu) {
    cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
    if (cpu.irq_taken) {
      cpu.standard_irq_callback(cpu.IRQ_LINE);
    }
    cpu.irq_taken = false;
    cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
    m65x_device_fetch(cpu);return; // fetch
}

// --- op cmp_zpi --- 
void m65c02_device_cmp_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_cmp_zpi_1;return; // READ
}

void m65c02_device_cmp_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_cmp_zpi_2;return; // READ
}

void m65c02_device_cmp_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_cmp_zpi_3;return; // READ
}

void m65c02_device_cmp_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_cmp_zpi_4;return; // READ
}

void m65c02_device_cmp_zpi_4(m65c02_device &cpu) {
  cpu.do_cmp(cpu.A, cpu.DAT);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op dec_aba --- 
void m65c02_device_dec_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_aba_1;return; // READ
}

void m65c02_device_dec_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_aba_2;return; // READ
}

void m65c02_device_dec_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_aba_3;return; // READ
}

void m65c02_device_dec_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_aba_4;return; // READ
}

void m65c02_device_dec_aba_4(m65c02_device &cpu) {
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_dec_aba_5;return; // WRITE
}

void m65c02_device_dec_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op dec_abx --- 
void m65c02_device_dec_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_abx_1;return; // READ
}

void m65c02_device_dec_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_abx_2;return; // READ
}

void m65c02_device_dec_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_abx_3;return; // READ
}

void m65c02_device_dec_abx_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_abx_4;return; // READ
}

void m65c02_device_dec_abx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_abx_5;return; // READ
}

void m65c02_device_dec_abx_5(m65c02_device &cpu) {
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_dec_abx_6;return; // WRITE
}

void m65c02_device_dec_abx_6(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op dec_acc --- 
void m65c02_device_dec_acc_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_acc_1;return; // READ
}

void m65c02_device_dec_acc_1(m65c02_device &cpu) {
  cpu.A--;
  cpu.set_nz(cpu.A);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op dec_zpg --- 
void m65c02_device_dec_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpg_1;return; // READ
}

void m65c02_device_dec_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpg_2;return; // READ
}

void m65c02_device_dec_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpg_3;return; // READ
}

void m65c02_device_dec_zpg_3(m65c02_device &cpu) {
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_dec_zpg_4;return; // WRITE
}

void m65c02_device_dec_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op dec_zpx --- 
void m65c02_device_dec_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpx_1;return; // READ
}

void m65c02_device_dec_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpx_2;return; // READ
}

void m65c02_device_dec_zpx_2(m65c02_device &cpu) {
  cpu.TMP = uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpx_3;return; // READ
}

void m65c02_device_dec_zpx_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_dec_zpx_4;return; // READ
}

void m65c02_device_dec_zpx_4(m65c02_device &cpu) {
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_dec_zpx_5;return; // WRITE
}

void m65c02_device_dec_zpx_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op eor_zpi --- 
void m65c02_device_eor_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_eor_zpi_1;return; // READ
}

void m65c02_device_eor_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_eor_zpi_2;return; // READ
}

void m65c02_device_eor_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_eor_zpi_3;return; // READ
}

void m65c02_device_eor_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_eor_zpi_4;return; // READ
}

void m65c02_device_eor_zpi_4(m65c02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op inc_aba --- 
void m65c02_device_inc_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_aba_1;return; // READ
}

void m65c02_device_inc_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_aba_2;return; // READ
}

void m65c02_device_inc_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_aba_3;return; // READ
}

void m65c02_device_inc_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_aba_4;return; // READ
}

void m65c02_device_inc_aba_4(m65c02_device &cpu) {
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_inc_aba_5;return; // WRITE
}

void m65c02_device_inc_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op inc_abx --- 
void m65c02_device_inc_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_abx_1;return; // READ
}

void m65c02_device_inc_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_abx_2;return; // READ
}

void m65c02_device_inc_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_abx_3;return; // READ
}

void m65c02_device_inc_abx_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_abx_4;return; // READ
}

void m65c02_device_inc_abx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_abx_5;return; // READ
}

void m65c02_device_inc_abx_5(m65c02_device &cpu) {
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_inc_abx_6;return; // WRITE
}

void m65c02_device_inc_abx_6(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op inc_acc --- 
void m65c02_device_inc_acc_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_acc_1;return; // READ
}

void m65c02_device_inc_acc_1(m65c02_device &cpu) {
  cpu.A++;
  cpu.set_nz(cpu.A);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op inc_zpg --- 
void m65c02_device_inc_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpg_1;return; // READ
}

void m65c02_device_inc_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpg_2;return; // READ
}

void m65c02_device_inc_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpg_3;return; // READ
}

void m65c02_device_inc_zpg_3(m65c02_device &cpu) {
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_inc_zpg_4;return; // WRITE
}

void m65c02_device_inc_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op inc_zpx --- 
void m65c02_device_inc_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpx_1;return; // READ
}

void m65c02_device_inc_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpx_2;return; // READ
}

void m65c02_device_inc_zpx_2(m65c02_device &cpu) {
  cpu.TMP = uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpx_3;return; // READ
}

void m65c02_device_inc_zpx_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_inc_zpx_4;return; // READ
}

void m65c02_device_inc_zpx_4(m65c02_device &cpu) {
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_inc_zpx_5;return; // WRITE
}

void m65c02_device_inc_zpx_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op jmp_iax --- 
void m65c02_device_jmp_iax_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_iax_1;return; // READ
}

void m65c02_device_jmp_iax_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_iax_2;return; // READ
}

void m65c02_device_jmp_iax_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_iax_3;return; // READ
}

void m65c02_device_jmp_iax_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_iax_4;return; // READ
}

void m65c02_device_jmp_iax_4(m65c02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_iax_5;return; // READ
}

void m65c02_device_jmp_iax_5(m65c02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op jmp_ind --- 
void m65c02_device_jmp_ind_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_ind_1;return; // READ
}

void m65c02_device_jmp_ind_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_ind_2;return; // READ
}

void m65c02_device_jmp_ind_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_ind_3;return; // READ
}

void m65c02_device_jmp_ind_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_ind_4;return; // READ
}

void m65c02_device_jmp_ind_4(m65c02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_jmp_ind_5;return; // READ
}

void m65c02_device_jmp_ind_5(m65c02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op lda_zpi --- 
void m65c02_device_lda_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lda_zpi_1;return; // READ
}

void m65c02_device_lda_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lda_zpi_2;return; // READ
}

void m65c02_device_lda_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lda_zpi_3;return; // READ
}

void m65c02_device_lda_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lda_zpi_4;return; // READ
}

void m65c02_device_lda_zpi_4(m65c02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op lsr_aba --- 
void m65c02_device_lsr_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_aba_1;return; // READ
}

void m65c02_device_lsr_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_aba_2;return; // READ
}

void m65c02_device_lsr_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_aba_3;return; // READ
}

void m65c02_device_lsr_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_aba_4;return; // READ
}

void m65c02_device_lsr_aba_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_lsr_aba_5;return; // WRITE
}

void m65c02_device_lsr_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op lsr_abx --- 
void m65c02_device_lsr_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_abx_1;return; // READ
}

void m65c02_device_lsr_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_abx_2;return; // READ
}

void m65c02_device_lsr_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_abx_3;return; // READ
}

void m65c02_device_lsr_abx_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_abx_4;return; // READ
}

void m65c02_device_lsr_abx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_abx_5;return; // READ
}

void m65c02_device_lsr_abx_5(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_lsr_abx_6;return; // WRITE
}

void m65c02_device_lsr_abx_6(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op lsr_zpg --- 
void m65c02_device_lsr_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpg_1;return; // READ
}

void m65c02_device_lsr_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpg_2;return; // READ
}

void m65c02_device_lsr_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpg_3;return; // READ
}

void m65c02_device_lsr_zpg_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpg_4;return; // WRITE
}

void m65c02_device_lsr_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op lsr_zpx --- 
void m65c02_device_lsr_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpx_1;return; // READ
}

void m65c02_device_lsr_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpx_2;return; // READ
}

void m65c02_device_lsr_zpx_2(m65c02_device &cpu) {
  cpu.TMP = uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpx_3;return; // READ
}

void m65c02_device_lsr_zpx_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpx_4;return; // READ
}

void m65c02_device_lsr_zpx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_lsr_zpx_5;return; // WRITE
}

void m65c02_device_lsr_zpx_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op nop_aba --- 
void m65c02_device_nop_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_1;return; // READ
}

void m65c02_device_nop_aba_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_2;return; // READ
}

void m65c02_device_nop_aba_2(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_3;return; // READ
}

void m65c02_device_nop_aba_3(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_4;return; // READ
}

void m65c02_device_nop_aba_4(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_5;return; // READ
}

void m65c02_device_nop_aba_5(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_6;return; // READ
}

void m65c02_device_nop_aba_6(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_aba_7;return; // READ
}

void m65c02_device_nop_aba_7(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op nop_abx --- 
void m65c02_device_nop_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_abx_1;return; // READ
}

void m65c02_device_nop_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_abx_2;return; // READ
}

void m65c02_device_nop_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_nop_abx_3;return; // READ
}

void m65c02_device_nop_abx_3(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op nop_imp --- 
void m65c02_device_nop_imp_0(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op ora_zpi --- 
void m65c02_device_ora_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ora_zpi_1;return; // READ
}

void m65c02_device_ora_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ora_zpi_2;return; // READ
}

void m65c02_device_ora_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ora_zpi_3;return; // READ
}

void m65c02_device_ora_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ora_zpi_4;return; // READ
}

void m65c02_device_ora_zpi_4(m65c02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op phx_imp --- 
void m65c02_device_phx_imp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_phx_imp_1;return; // READ
}

void m65c02_device_phx_imp_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.X;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_phx_imp_2;return; // WRITE
}

void m65c02_device_phx_imp_2(m65c02_device &cpu) {
  cpu.dec_SP();
  m65x_device_fetch(cpu);return; // fetch
}

// --- op phy_imp --- 
void m65c02_device_phy_imp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_phy_imp_1;return; // READ
}

void m65c02_device_phy_imp_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.Y;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_phy_imp_2;return; // WRITE
}

void m65c02_device_phy_imp_2(m65c02_device &cpu) {
  cpu.dec_SP();
  m65x_device_fetch(cpu);return; // fetch
}

// --- op plx_imp --- 
void m65c02_device_plx_imp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_plx_imp_1;return; // READ
}

void m65c02_device_plx_imp_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_plx_imp_2;return; // READ
}

void m65c02_device_plx_imp_2(m65c02_device &cpu) {
  cpu.inc_SP();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_plx_imp_3;return; // READ
}

void m65c02_device_plx_imp_3(m65c02_device &cpu) {
  cpu.X = cpu.DAT;
  cpu.set_nz(cpu.X);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op ply_imp --- 
void m65c02_device_ply_imp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ply_imp_1;return; // READ
}

void m65c02_device_ply_imp_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ply_imp_2;return; // READ
}

void m65c02_device_ply_imp_2(m65c02_device &cpu) {
  cpu.inc_SP();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ply_imp_3;return; // READ
}

void m65c02_device_ply_imp_3(m65c02_device &cpu) {
  cpu.Y = cpu.DAT;
  cpu.set_nz(cpu.Y);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op reset --- 
void m65c02_device_reset_0(m65c02_device &cpu) {
  cpu.ADDR = 0xffff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_1;return; // READ
}

void m65c02_device_reset_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_2;return; // READ
}

void m65c02_device_reset_2(m65c02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_3;return; // READ
}

void m65c02_device_reset_3(m65c02_device &cpu) {
  cpu.DAT; cpu.dec_SP();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_4;return; // READ
}

void m65c02_device_reset_4(m65c02_device &cpu) {
  cpu.DAT; cpu.dec_SP();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_5;return; // READ
}

void m65c02_device_reset_5(m65c02_device &cpu) {
  cpu.DAT; cpu.dec_SP();
  cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
  cpu.ADDR = 0xfffc;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_6;return; // READ
}

void m65c02_device_reset_6(m65c02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = 0xfffd;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_reset_7;return; // READ
}

void m65c02_device_reset_7(m65c02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m65x_device_fetch(cpu);return; // fetch
}

// --- op rmb_bzp --- 
void m65c02_device_rmb_bzp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rmb_bzp_1;return; // READ
}

void m65c02_device_rmb_bzp_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rmb_bzp_2;return; // READ
}

void m65c02_device_rmb_bzp_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rmb_bzp_3;return; // READ
}

void m65c02_device_rmb_bzp_3(m65c02_device &cpu) {
  cpu.TMP2 &= ~(1 << ((cpu.IR >> 4) & 7));
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_rmb_bzp_4;return; // WRITE
}

void m65c02_device_rmb_bzp_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op rol_aba --- 
void m65c02_device_rol_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_aba_1;return; // READ
}

void m65c02_device_rol_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_aba_2;return; // READ
}

void m65c02_device_rol_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_aba_3;return; // READ
}

void m65c02_device_rol_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_aba_4;return; // READ
}

void m65c02_device_rol_aba_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_rol_aba_5;return; // WRITE
}

void m65c02_device_rol_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op rol_abx --- 
void m65c02_device_rol_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_abx_1;return; // READ
}

void m65c02_device_rol_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_abx_2;return; // READ
}

void m65c02_device_rol_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_abx_3;return; // READ
}

void m65c02_device_rol_abx_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_abx_4;return; // READ
}

void m65c02_device_rol_abx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_abx_5;return; // READ
}

void m65c02_device_rol_abx_5(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_rol_abx_6;return; // WRITE
}

void m65c02_device_rol_abx_6(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op rol_zpg --- 
void m65c02_device_rol_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpg_1;return; // READ
}

void m65c02_device_rol_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpg_2;return; // READ
}

void m65c02_device_rol_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpg_3;return; // READ
}

void m65c02_device_rol_zpg_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_rol_zpg_4;return; // WRITE
}

void m65c02_device_rol_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op rol_zpx --- 
void m65c02_device_rol_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpx_1;return; // READ
}

void m65c02_device_rol_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpx_2;return; // READ
}

void m65c02_device_rol_zpx_2(m65c02_device &cpu) {
  cpu.TMP = uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpx_3;return; // READ
}

void m65c02_device_rol_zpx_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_rol_zpx_4;return; // READ
}

void m65c02_device_rol_zpx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_rol_zpx_5;return; // WRITE
}

void m65c02_device_rol_zpx_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op ror_aba --- 
void m65c02_device_ror_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_aba_1;return; // READ
}

void m65c02_device_ror_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_aba_2;return; // READ
}

void m65c02_device_ror_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_aba_3;return; // READ
}

void m65c02_device_ror_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_aba_4;return; // READ
}

void m65c02_device_ror_aba_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_ror_aba_5;return; // WRITE
}

void m65c02_device_ror_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op ror_abx --- 
void m65c02_device_ror_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_abx_1;return; // READ
}

void m65c02_device_ror_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_abx_2;return; // READ
}

void m65c02_device_ror_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_abx_3;return; // READ
}

void m65c02_device_ror_abx_3(m65c02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_abx_4;return; // READ
}

void m65c02_device_ror_abx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_abx_5;return; // READ
}

void m65c02_device_ror_abx_5(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_ror_abx_6;return; // WRITE
}

void m65c02_device_ror_abx_6(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op ror_zpg --- 
void m65c02_device_ror_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpg_1;return; // READ
}

void m65c02_device_ror_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpg_2;return; // READ
}

void m65c02_device_ror_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpg_3;return; // READ
}

void m65c02_device_ror_zpg_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_ror_zpg_4;return; // WRITE
}

void m65c02_device_ror_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op ror_zpx --- 
void m65c02_device_ror_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpx_1;return; // READ
}

void m65c02_device_ror_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpx_2;return; // READ
}

void m65c02_device_ror_zpx_2(m65c02_device &cpu) {
  cpu.TMP = uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpx_3;return; // READ
}

void m65c02_device_ror_zpx_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_ror_zpx_4;return; // READ
}

void m65c02_device_ror_zpx_4(m65c02_device &cpu) {
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_ror_zpx_5;return; // WRITE
}

void m65c02_device_ror_zpx_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_aba --- 
void m65c02_device_sbc_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_aba_1;return; // READ
}

void m65c02_device_sbc_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_aba_2;return; // READ
}

void m65c02_device_sbc_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_aba_3;return; // READ
}

void m65c02_device_sbc_aba_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_aba_4;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_aba_4(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_abx --- 
void m65c02_device_sbc_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_abx_1;return; // READ
}

void m65c02_device_sbc_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_abx_2;return; // READ
}

void m65c02_device_sbc_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.X)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_abx_3;return; // READ
  }
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_abx_4;return; // READ
}

void m65c02_device_sbc_abx_3(m65c02_device &cpu) {
    cpu.TMP += cpu.X;
    cpu.ADDR = cpu.TMP;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_abx_4;return; // READ
}

void m65c02_device_sbc_abx_4(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_abx_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_abx_5(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_aby --- 
void m65c02_device_sbc_aby_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_aby_1;return; // READ
}

void m65c02_device_sbc_aby_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_aby_2;return; // READ
}

void m65c02_device_sbc_aby_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.Y)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.Y);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_aby_3;return; // READ
  }
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_aby_4;return; // READ
}

void m65c02_device_sbc_aby_3(m65c02_device &cpu) {
    cpu.TMP += cpu.Y;
    cpu.ADDR = cpu.TMP;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_aby_4;return; // READ
}

void m65c02_device_sbc_aby_4(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_aby_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_aby_5(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_idx --- 
void m65c02_device_sbc_idx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idx_1;return; // READ
}

void m65c02_device_sbc_idx_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idx_2;return; // READ
}

void m65c02_device_sbc_idx_2(m65c02_device &cpu) {
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idx_3;return; // READ
}

void m65c02_device_sbc_idx_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idx_4;return; // READ
}

void m65c02_device_sbc_idx_4(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idx_5;return; // READ
}

void m65c02_device_sbc_idx_5(m65c02_device &cpu) {
  cpu.do_sbc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_idx_6;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_idx_6(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_idy --- 
void m65c02_device_sbc_idy_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idy_1;return; // READ
}

void m65c02_device_sbc_idy_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idy_2;return; // READ
}

void m65c02_device_sbc_idy_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idy_3;return; // READ
}

void m65c02_device_sbc_idy_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.page_changing(cpu.TMP, cpu.Y)) {
    cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.Y);
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_idy_4;return; // READ
  }
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_idy_5;return; // READ
}

void m65c02_device_sbc_idy_4(m65c02_device &cpu) {
    cpu.ADDR = cpu.TMP+cpu.Y;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_idy_5;return; // READ
}

void m65c02_device_sbc_idy_5(m65c02_device &cpu) {
  cpu.do_sbc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_idy_6;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_idy_6(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_imm --- 
void m65c02_device_sbc_imm_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_imm_1;return; // READ
}

void m65c02_device_sbc_imm_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_imm_2;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_imm_2(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_zpg --- 
void m65c02_device_sbc_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpg_1;return; // READ
}

void m65c02_device_sbc_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpg_2;return; // READ
}

void m65c02_device_sbc_zpg_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_zpg_3;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_zpg_3(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_zpi --- 
void m65c02_device_sbc_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpi_1;return; // READ
}

void m65c02_device_sbc_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpi_2;return; // READ
}

void m65c02_device_sbc_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpi_3;return; // READ
}

void m65c02_device_sbc_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpi_4;return; // READ
}

void m65c02_device_sbc_zpi_4(m65c02_device &cpu) {
  cpu.do_sbc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_zpi_5;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_zpi_5(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op sbc_zpx --- 
void m65c02_device_sbc_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpx_1;return; // READ
}

void m65c02_device_sbc_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpx_2;return; // READ
}

void m65c02_device_sbc_zpx_2(m65c02_device &cpu) {
  cpu.ADDR = uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sbc_zpx_3;return; // READ
}

void m65c02_device_sbc_zpx_3(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65c02_device_sbc_zpx_4;return; // READ
  }
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_sbc_zpx_4(m65c02_device &cpu) {
    cpu.set_nz(cpu.A);
    m65x_device_fetch(cpu);return; // fetch
}

// --- op smb_bzp --- 
void m65c02_device_smb_bzp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_smb_bzp_1;return; // READ
}

void m65c02_device_smb_bzp_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_smb_bzp_2;return; // READ
}

void m65c02_device_smb_bzp_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_smb_bzp_3;return; // READ
}

void m65c02_device_smb_bzp_3(m65c02_device &cpu) {
  cpu.TMP2 |= 1 << ((cpu.IR >> 4) & 7);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_smb_bzp_4;return; // WRITE
}

void m65c02_device_smb_bzp_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op sta_zpi --- 
void m65c02_device_sta_zpi_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sta_zpi_1;return; // READ
}

void m65c02_device_sta_zpi_1(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP2 & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sta_zpi_2;return; // READ
}

void m65c02_device_sta_zpi_2(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = (cpu.TMP2+1) & 0xff;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_sta_zpi_3;return; // READ
}

void m65c02_device_sta_zpi_3(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_sta_zpi_4;return; // WRITE
}

void m65c02_device_sta_zpi_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op stp_imp --- 
void m65c02_device_stp_imp_0(m65c02_device &cpu) {
  m65c02_device_stp_imp_while_1(cpu);return;
}

void m65c02_device_stp_imp_while_1(m65c02_device &cpu) {
  if (!(true)) m65c02_device_stp_imp_whilenot_1(cpu);return;
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stp_imp_1;return; // READ
}

void m65c02_device_stp_imp_whilenot_1(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_stp_imp_1(m65c02_device &cpu) {
  m65c02_device_stp_imp_while_1(cpu);return;
}

// --- op stz_aba --- 
void m65c02_device_stz_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_aba_1;return; // READ
}

void m65c02_device_stz_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_aba_2;return; // READ
}

void m65c02_device_stz_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  0x00;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_stz_aba_3;return; // WRITE
}

void m65c02_device_stz_aba_3(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op stz_abx --- 
void m65c02_device_stz_abx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_abx_1;return; // READ
}

void m65c02_device_stz_abx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_abx_2;return; // READ
}

void m65c02_device_stz_abx_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_abx_3;return; // READ
}

void m65c02_device_stz_abx_3(m65c02_device &cpu) {
  cpu.ADDR = cpu.TMP+cpu.X;
  cpu.DAT =  0x00;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_stz_abx_4;return; // WRITE
}

void m65c02_device_stz_abx_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op stz_zpg --- 
void m65c02_device_stz_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_zpg_1;return; // READ
}

void m65c02_device_stz_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  0x00;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_stz_zpg_2;return; // WRITE
}

void m65c02_device_stz_zpg_2(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op stz_zpx --- 
void m65c02_device_stz_zpx_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_zpx_1;return; // READ
}

void m65c02_device_stz_zpx_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_stz_zpx_2;return; // READ
}

void m65c02_device_stz_zpx_2(m65c02_device &cpu) {
  cpu.ADDR = uint8_t(cpu.TMP+cpu.X);
  cpu.DAT =  0x00;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_stz_zpx_3;return; // WRITE
}

void m65c02_device_stz_zpx_3(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op trb_aba --- 
void m65c02_device_trb_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_aba_1;return; // READ
}

void m65c02_device_trb_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_aba_2;return; // READ
}

void m65c02_device_trb_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_aba_3;return; // READ
}

void m65c02_device_trb_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_aba_4;return; // READ
}

void m65c02_device_trb_aba_4(m65c02_device &cpu) {
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 &= ~cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_trb_aba_5;return; // WRITE
}

void m65c02_device_trb_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op trb_zpg --- 
void m65c02_device_trb_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_zpg_1;return; // READ
}

void m65c02_device_trb_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_zpg_2;return; // READ
}

void m65c02_device_trb_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_trb_zpg_3;return; // READ
}

void m65c02_device_trb_zpg_3(m65c02_device &cpu) {
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 &= ~cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_trb_zpg_4;return; // WRITE
}

void m65c02_device_trb_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op tsb_aba --- 
void m65c02_device_tsb_aba_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_aba_1;return; // READ
}

void m65c02_device_tsb_aba_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_aba_2;return; // READ
}

void m65c02_device_tsb_aba_2(m65c02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_aba_3;return; // READ
}

void m65c02_device_tsb_aba_3(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_aba_4;return; // READ
}

void m65c02_device_tsb_aba_4(m65c02_device &cpu) {
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 |= cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_tsb_aba_5;return; // WRITE
}

void m65c02_device_tsb_aba_5(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op tsb_zpg --- 
void m65c02_device_tsb_zpg_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_zpg_1;return; // READ
}

void m65c02_device_tsb_zpg_1(m65c02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_zpg_2;return; // READ
}

void m65c02_device_tsb_zpg_2(m65c02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_tsb_zpg_3;return; // READ
}

void m65c02_device_tsb_zpg_3(m65c02_device &cpu) {
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 |= cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65c02_device_tsb_zpg_4;return; // WRITE
}

void m65c02_device_tsb_zpg_4(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

// --- op wai_imp --- 
void m65c02_device_wai_imp_0(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_wai_imp_1;return; // READ
}

void m65c02_device_wai_imp_1(m65c02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_wai_imp_2;return; // READ
}

void m65c02_device_wai_imp_2(m65c02_device &cpu) {
  m65c02_device_wai_imp_while_1(cpu);return;
}

void m65c02_device_wai_imp_while_1(m65c02_device &cpu) {
  if (!(!cpu.nmi_state && !cpu.irq_state)) m65c02_device_wai_imp_whilenot_1(cpu);return;
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65c02_device_wai_imp_3;return; // READ
}

void m65c02_device_wai_imp_whilenot_1(m65c02_device &cpu) {
  m65x_device_fetch(cpu);return; // fetch
}

void m65c02_device_wai_imp_3(m65c02_device &cpu) {
  m65c02_device_wai_imp_while_1(cpu);return;
}

void m65c02_device_postfetch_int(m65c02_device &cpu) {
  switch(cpu.IR) {
  case 0x00: m65c02_device_brk_imp_0(cpu); break;
  case 0x01: m6502_device_ora_idx_0(cpu); break;
  case 0x02: m6502_device_nop_imm_0(cpu); break;
  case 0x03: m65c02_device_nop_imp_0(cpu); break;
  case 0x04: m65c02_device_tsb_zpg_0(cpu); break;
  case 0x05: m6502_device_ora_zpg_0(cpu); break;
  case 0x06: m65c02_device_asl_zpg_0(cpu); break;
  case 0x07: m65c02_device_nop_imp_0(cpu); break;
  case 0x08: m6502_device_php_imp_0(cpu); break;
  case 0x09: m6502_device_ora_imm_0(cpu); break;
  case 0x0a: m6502_device_asl_acc_0(cpu); break;
  case 0x0b: m65c02_device_nop_imp_0(cpu); break;
  case 0x0c: m65c02_device_tsb_aba_0(cpu); break;
  case 0x0d: m6502_device_ora_aba_0(cpu); break;
  case 0x0e: m65c02_device_asl_aba_0(cpu); break;
  case 0x0f: m65c02_device_nop_imp_0(cpu); break;
  case 0x10: m6502_device_bpl_rel_0(cpu); break;
  case 0x11: m6502_device_ora_idy_0(cpu); break;
  case 0x12: m65c02_device_ora_zpi_0(cpu); break;
  case 0x13: m65c02_device_nop_imp_0(cpu); break;
  case 0x14: m65c02_device_trb_zpg_0(cpu); break;
  case 0x15: m6502_device_ora_zpx_0(cpu); break;
  case 0x16: m65c02_device_asl_zpx_0(cpu); break;
  case 0x17: m65c02_device_nop_imp_0(cpu); break;
  case 0x18: m6502_device_clc_imp_0(cpu); break;
  case 0x19: m6502_device_ora_aby_0(cpu); break;
  case 0x1a: m65c02_device_inc_acc_0(cpu); break;
  case 0x1b: m65c02_device_nop_imp_0(cpu); break;
  case 0x1c: m65c02_device_trb_aba_0(cpu); break;
  case 0x1d: m6502_device_ora_abx_0(cpu); break;
  case 0x1e: m65c02_device_asl_abx_0(cpu); break;
  case 0x1f: m65c02_device_nop_imp_0(cpu); break;
  case 0x20: m6502_device_jsr_adr_0(cpu); break;
  case 0x21: m6502_device_and_idx_0(cpu); break;
  case 0x22: m6502_device_nop_imm_0(cpu); break;
  case 0x23: m65c02_device_nop_imp_0(cpu); break;
  case 0x24: m6502_device_bit_zpg_0(cpu); break;
  case 0x25: m6502_device_and_zpg_0(cpu); break;
  case 0x26: m65c02_device_rol_zpg_0(cpu); break;
  case 0x27: m65c02_device_nop_imp_0(cpu); break;
  case 0x28: m6502_device_plp_imp_0(cpu); break;
  case 0x29: m6502_device_and_imm_0(cpu); break;
  case 0x2a: m6502_device_rol_acc_0(cpu); break;
  case 0x2b: m65c02_device_nop_imp_0(cpu); break;
  case 0x2c: m6502_device_bit_aba_0(cpu); break;
  case 0x2d: m6502_device_and_aba_0(cpu); break;
  case 0x2e: m65c02_device_rol_aba_0(cpu); break;
  case 0x2f: m65c02_device_nop_imp_0(cpu); break;
  case 0x30: m6502_device_bmi_rel_0(cpu); break;
  case 0x31: m6502_device_and_idy_0(cpu); break;
  case 0x32: m65c02_device_and_zpi_0(cpu); break;
  case 0x33: m65c02_device_nop_imp_0(cpu); break;
  case 0x34: m65c02_device_bit_zpx_0(cpu); break;
  case 0x35: m6502_device_and_zpx_0(cpu); break;
  case 0x36: m65c02_device_rol_zpx_0(cpu); break;
  case 0x37: m65c02_device_nop_imp_0(cpu); break;
  case 0x38: m6502_device_sec_imp_0(cpu); break;
  case 0x39: m6502_device_and_aby_0(cpu); break;
  case 0x3a: m65c02_device_dec_acc_0(cpu); break;
  case 0x3b: m65c02_device_nop_imp_0(cpu); break;
  case 0x3c: m65c02_device_bit_abx_0(cpu); break;
  case 0x3d: m6502_device_and_abx_0(cpu); break;
  case 0x3e: m65c02_device_rol_abx_0(cpu); break;
  case 0x3f: m65c02_device_nop_imp_0(cpu); break;
  case 0x40: m6502_device_rti_imp_0(cpu); break;
  case 0x41: m6502_device_eor_idx_0(cpu); break;
  case 0x42: m6502_device_nop_imm_0(cpu); break;
  case 0x43: m65c02_device_nop_imp_0(cpu); break;
  case 0x44: m6502_device_nop_zpg_0(cpu); break;
  case 0x45: m6502_device_eor_zpg_0(cpu); break;
  case 0x46: m65c02_device_lsr_zpg_0(cpu); break;
  case 0x47: m65c02_device_nop_imp_0(cpu); break;
  case 0x48: m6502_device_pha_imp_0(cpu); break;
  case 0x49: m6502_device_eor_imm_0(cpu); break;
  case 0x4a: m6502_device_lsr_acc_0(cpu); break;
  case 0x4b: m65c02_device_nop_imp_0(cpu); break;
  case 0x4c: m6502_device_jmp_adr_0(cpu); break;
  case 0x4d: m6502_device_eor_aba_0(cpu); break;
  case 0x4e: m65c02_device_lsr_aba_0(cpu); break;
  case 0x4f: m65c02_device_nop_imp_0(cpu); break;
  case 0x50: m6502_device_bvc_rel_0(cpu); break;
  case 0x51: m6502_device_eor_idy_0(cpu); break;
  case 0x52: m65c02_device_eor_zpi_0(cpu); break;
  case 0x53: m65c02_device_nop_imp_0(cpu); break;
  case 0x54: m6502_device_nop_zpx_0(cpu); break;
  case 0x55: m6502_device_eor_zpx_0(cpu); break;
  case 0x56: m65c02_device_lsr_zpx_0(cpu); break;
  case 0x57: m65c02_device_nop_imp_0(cpu); break;
  case 0x58: m6502_device_cli_imp_0(cpu); break;
  case 0x59: m6502_device_eor_aby_0(cpu); break;
  case 0x5a: m65c02_device_phy_imp_0(cpu); break;
  case 0x5b: m65c02_device_nop_imp_0(cpu); break;
  case 0x5c: m65c02_device_nop_aba_0(cpu); break;
  case 0x5d: m6502_device_eor_abx_0(cpu); break;
  case 0x5e: m65c02_device_lsr_abx_0(cpu); break;
  case 0x5f: m65c02_device_nop_imp_0(cpu); break;
  case 0x60: m6502_device_rts_imp_0(cpu); break;
  case 0x61: m65c02_device_adc_idx_0(cpu); break;
  case 0x62: m6502_device_nop_imm_0(cpu); break;
  case 0x63: m65c02_device_nop_imp_0(cpu); break;
  case 0x64: m65c02_device_stz_zpg_0(cpu); break;
  case 0x65: m65c02_device_adc_zpg_0(cpu); break;
  case 0x66: m65c02_device_ror_zpg_0(cpu); break;
  case 0x67: m65c02_device_nop_imp_0(cpu); break;
  case 0x68: m6502_device_pla_imp_0(cpu); break;
  case 0x69: m65c02_device_adc_imm_0(cpu); break;
  case 0x6a: m6502_device_ror_acc_0(cpu); break;
  case 0x6b: m65c02_device_nop_imp_0(cpu); break;
  case 0x6c: m65c02_device_jmp_ind_0(cpu); break;
  case 0x6d: m65c02_device_adc_aba_0(cpu); break;
  case 0x6e: m65c02_device_ror_aba_0(cpu); break;
  case 0x6f: m65c02_device_nop_imp_0(cpu); break;
  case 0x70: m6502_device_bvs_rel_0(cpu); break;
  case 0x71: m65c02_device_adc_idy_0(cpu); break;
  case 0x72: m65c02_device_adc_zpi_0(cpu); break;
  case 0x73: m65c02_device_nop_imp_0(cpu); break;
  case 0x74: m65c02_device_stz_zpx_0(cpu); break;
  case 0x75: m65c02_device_adc_zpx_0(cpu); break;
  case 0x76: m65c02_device_ror_zpx_0(cpu); break;
  case 0x77: m65c02_device_nop_imp_0(cpu); break;
  case 0x78: m6502_device_sei_imp_0(cpu); break;
  case 0x79: m65c02_device_adc_aby_0(cpu); break;
  case 0x7a: m65c02_device_ply_imp_0(cpu); break;
  case 0x7b: m65c02_device_nop_imp_0(cpu); break;
  case 0x7c: m65c02_device_jmp_iax_0(cpu); break;
  case 0x7d: m65c02_device_adc_abx_0(cpu); break;
  case 0x7e: m65c02_device_ror_abx_0(cpu); break;
  case 0x7f: m65c02_device_nop_imp_0(cpu); break;
  case 0x80: m65c02_device_bra_rel_0(cpu); break;
  case 0x81: m6502_device_sta_idx_0(cpu); break;
  case 0x82: m6502_device_nop_imm_0(cpu); break;
  case 0x83: m65c02_device_nop_imp_0(cpu); break;
  case 0x84: m6502_device_sty_zpg_0(cpu); break;
  case 0x85: m6502_device_sta_zpg_0(cpu); break;
  case 0x86: m6502_device_stx_zpg_0(cpu); break;
  case 0x87: m65c02_device_nop_imp_0(cpu); break;
  case 0x88: m6502_device_dey_imp_0(cpu); break;
  case 0x89: m65c02_device_bit_imm_0(cpu); break;
  case 0x8a: m6502_device_txa_imp_0(cpu); break;
  case 0x8b: m65c02_device_nop_imp_0(cpu); break;
  case 0x8c: m6502_device_sty_aba_0(cpu); break;
  case 0x8d: m6502_device_sta_aba_0(cpu); break;
  case 0x8e: m6502_device_stx_aba_0(cpu); break;
  case 0x8f: m65c02_device_nop_imp_0(cpu); break;
  case 0x90: m6502_device_bcc_rel_0(cpu); break;
  case 0x91: m6502_device_sta_idy_0(cpu); break;
  case 0x92: m65c02_device_sta_zpi_0(cpu); break;
  case 0x93: m65c02_device_nop_imp_0(cpu); break;
  case 0x94: m6502_device_sty_zpx_0(cpu); break;
  case 0x95: m6502_device_sta_zpx_0(cpu); break;
  case 0x96: m6502_device_stx_zpy_0(cpu); break;
  case 0x97: m65c02_device_nop_imp_0(cpu); break;
  case 0x98: m6502_device_tya_imp_0(cpu); break;
  case 0x99: m6502_device_sta_aby_0(cpu); break;
  case 0x9a: m6502_device_txs_imp_0(cpu); break;
  case 0x9b: m65c02_device_nop_imp_0(cpu); break;
  case 0x9c: m65c02_device_stz_aba_0(cpu); break;
  case 0x9d: m6502_device_sta_abx_0(cpu); break;
  case 0x9e: m65c02_device_stz_abx_0(cpu); break;
  case 0x9f: m65c02_device_nop_imp_0(cpu); break;
  case 0xa0: m6502_device_ldy_imm_0(cpu); break;
  case 0xa1: m6502_device_lda_idx_0(cpu); break;
  case 0xa2: m6502_device_ldx_imm_0(cpu); break;
  case 0xa3: m65c02_device_nop_imp_0(cpu); break;
  case 0xa4: m6502_device_ldy_zpg_0(cpu); break;
  case 0xa5: m6502_device_lda_zpg_0(cpu); break;
  case 0xa6: m6502_device_ldx_zpg_0(cpu); break;
  case 0xa7: m65c02_device_nop_imp_0(cpu); break;
  case 0xa8: m6502_device_tay_imp_0(cpu); break;
  case 0xa9: m6502_device_lda_imm_0(cpu); break;
  case 0xaa: m6502_device_tax_imp_0(cpu); break;
  case 0xab: m65c02_device_nop_imp_0(cpu); break;
  case 0xac: m6502_device_ldy_aba_0(cpu); break;
  case 0xad: m6502_device_lda_aba_0(cpu); break;
  case 0xae: m6502_device_ldx_aba_0(cpu); break;
  case 0xaf: m65c02_device_nop_imp_0(cpu); break;
  case 0xb0: m6502_device_bcs_rel_0(cpu); break;
  case 0xb1: m6502_device_lda_idy_0(cpu); break;
  case 0xb2: m65c02_device_lda_zpi_0(cpu); break;
  case 0xb3: m65c02_device_nop_imp_0(cpu); break;
  case 0xb4: m6502_device_ldy_zpx_0(cpu); break;
  case 0xb5: m6502_device_lda_zpx_0(cpu); break;
  case 0xb6: m6502_device_ldx_zpy_0(cpu); break;
  case 0xb7: m65c02_device_nop_imp_0(cpu); break;
  case 0xb8: m6502_device_clv_imp_0(cpu); break;
  case 0xb9: m6502_device_lda_aby_0(cpu); break;
  case 0xba: m6502_device_tsx_imp_0(cpu); break;
  case 0xbb: m65c02_device_nop_imp_0(cpu); break;
  case 0xbc: m6502_device_ldy_abx_0(cpu); break;
  case 0xbd: m6502_device_lda_abx_0(cpu); break;
  case 0xbe: m6502_device_ldx_aby_0(cpu); break;
  case 0xbf: m65c02_device_nop_imp_0(cpu); break;
  case 0xc0: m6502_device_cpy_imm_0(cpu); break;
  case 0xc1: m6502_device_cmp_idx_0(cpu); break;
  case 0xc2: m6502_device_nop_imm_0(cpu); break;
  case 0xc3: m65c02_device_nop_imp_0(cpu); break;
  case 0xc4: m6502_device_cpy_zpg_0(cpu); break;
  case 0xc5: m6502_device_cmp_zpg_0(cpu); break;
  case 0xc6: m65c02_device_dec_zpg_0(cpu); break;
  case 0xc7: m65c02_device_nop_imp_0(cpu); break;
  case 0xc8: m6502_device_iny_imp_0(cpu); break;
  case 0xc9: m6502_device_cmp_imm_0(cpu); break;
  case 0xca: m6502_device_dex_imp_0(cpu); break;
  case 0xcb: m65c02_device_nop_imp_0(cpu); break;
  case 0xcc: m6502_device_cpy_aba_0(cpu); break;
  case 0xcd: m6502_device_cmp_aba_0(cpu); break;
  case 0xce: m65c02_device_dec_aba_0(cpu); break;
  case 0xcf: m65c02_device_nop_imp_0(cpu); break;
  case 0xd0: m6502_device_bne_rel_0(cpu); break;
  case 0xd1: m6502_device_cmp_idy_0(cpu); break;
  case 0xd2: m65c02_device_cmp_zpi_0(cpu); break;
  case 0xd3: m65c02_device_nop_imp_0(cpu); break;
  case 0xd4: m6502_device_nop_zpx_0(cpu); break;
  case 0xd5: m6502_device_cmp_zpx_0(cpu); break;
  case 0xd6: m65c02_device_dec_zpx_0(cpu); break;
  case 0xd7: m65c02_device_nop_imp_0(cpu); break;
  case 0xd8: m6502_device_cld_imp_0(cpu); break;
  case 0xd9: m6502_device_cmp_aby_0(cpu); break;
  case 0xda: m65c02_device_phx_imp_0(cpu); break;
  case 0xdb: m65c02_device_nop_imp_0(cpu); break;
  case 0xdc: m65c02_device_nop_abx_0(cpu); break;
  case 0xdd: m6502_device_cmp_abx_0(cpu); break;
  case 0xde: m65c02_device_dec_abx_0(cpu); break;
  case 0xdf: m65c02_device_nop_imp_0(cpu); break;
  case 0xe0: m6502_device_cpx_imm_0(cpu); break;
  case 0xe1: m65c02_device_sbc_idx_0(cpu); break;
  case 0xe2: m6502_device_nop_imm_0(cpu); break;
  case 0xe3: m65c02_device_nop_imp_0(cpu); break;
  case 0xe4: m6502_device_cpx_zpg_0(cpu); break;
  case 0xe5: m65c02_device_sbc_zpg_0(cpu); break;
  case 0xe6: m65c02_device_inc_zpg_0(cpu); break;
  case 0xe7: m65c02_device_nop_imp_0(cpu); break;
  case 0xe8: m6502_device_inx_imp_0(cpu); break;
  case 0xe9: m65c02_device_sbc_imm_0(cpu); break;
  case 0xea: m6502_device_nop_imp_0(cpu); break;
  case 0xeb: m65c02_device_nop_imp_0(cpu); break;
  case 0xec: m6502_device_cpx_aba_0(cpu); break;
  case 0xed: m65c02_device_sbc_aba_0(cpu); break;
  case 0xee: m65c02_device_inc_aba_0(cpu); break;
  case 0xef: m65c02_device_nop_imp_0(cpu); break;
  case 0xf0: m6502_device_beq_rel_0(cpu); break;
  case 0xf1: m65c02_device_sbc_idy_0(cpu); break;
  case 0xf2: m65c02_device_sbc_zpi_0(cpu); break;
  case 0xf3: m65c02_device_nop_imp_0(cpu); break;
  case 0xf4: m6502_device_nop_zpx_0(cpu); break;
  case 0xf5: m65c02_device_sbc_zpx_0(cpu); break;
  case 0xf6: m65c02_device_inc_zpx_0(cpu); break;
  case 0xf7: m65c02_device_nop_imp_0(cpu); break;
  case 0xf8: m6502_device_sed_imp_0(cpu); break;
  case 0xf9: m65c02_device_sbc_aby_0(cpu); break;
  case 0xfa: m65c02_device_plx_imp_0(cpu); break;
  case 0xfb: m65c02_device_nop_imp_0(cpu); break;
  case 0xfc: m65c02_device_nop_abx_0(cpu); break;
  case 0xfd: m65c02_device_sbc_abx_0(cpu); break;
  case 0xfe: m65c02_device_inc_abx_0(cpu); break;
  case 0xff: m65c02_device_nop_imp_0(cpu); break;
  default:   m65c02_device_reset_0(cpu); break;
  }
}

