// This file has been automatically produced by makehxx.pl
// do not edit it.
// from file(s) dm65ce02.lst D:\Users\Dominic\Documents\GitHub\beebem-windows\cpu65x\m6502\om65ce02.lst
#include "m65ce02.h"
// --- op adc_aba --- 
void m65ce02_device_adc_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_aba_1;return; // READ
}

void m65ce02_device_adc_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_aba_2;return; // READ
}

void m65ce02_device_adc_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_aba_3;return; // READ
}

void m65ce02_device_adc_aba_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_abx --- 
void m65ce02_device_adc_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_abx_1;return; // READ
}

void m65ce02_device_adc_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_abx_2;return; // READ
}

void m65ce02_device_adc_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_abx_3;return; // READ
}

void m65ce02_device_adc_abx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_aby --- 
void m65ce02_device_adc_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_aby_1;return; // READ
}

void m65ce02_device_adc_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_aby_2;return; // READ
}

void m65ce02_device_adc_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_aby_3;return; // READ
}

void m65ce02_device_adc_aby_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_idx --- 
void m65ce02_device_adc_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idx_1;return; // READ
}

void m65ce02_device_adc_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idx_2;return; // READ
}

void m65ce02_device_adc_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idx_3;return; // READ
}

void m65ce02_device_adc_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idx_4;return; // READ
}

void m65ce02_device_adc_idx_4(m65ce02_device &cpu) {
  cpu.do_adc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_idy --- 
void m65ce02_device_adc_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idy_1;return; // READ
}

void m65ce02_device_adc_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idy_2;return; // READ
}

void m65ce02_device_adc_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idy_3;return; // READ
}

void m65ce02_device_adc_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idy_4;return; // READ
}

void m65ce02_device_adc_idy_4(m65ce02_device &cpu) {
  cpu.do_adc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_idz --- 
void m65ce02_device_adc_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idz_1;return; // READ
}

void m65ce02_device_adc_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idz_2;return; // READ
}

void m65ce02_device_adc_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idz_3;return; // READ
}

void m65ce02_device_adc_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_idz_4;return; // READ
}

void m65ce02_device_adc_idz_4(m65ce02_device &cpu) {
  cpu.do_adc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_imm --- 
void m65ce02_device_adc_imm_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_imm_1;return; // READ
}

void m65ce02_device_adc_imm_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_zpg --- 
void m65ce02_device_adc_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_zpg_1;return; // READ
}

void m65ce02_device_adc_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_zpg_2;return; // READ
}

void m65ce02_device_adc_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op adc_zpx --- 
void m65ce02_device_adc_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_zpx_1;return; // READ
}

void m65ce02_device_adc_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_adc_zpx_2;return; // READ
}

void m65ce02_device_adc_zpx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_adc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_abx --- 
void m65ce02_device_and_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_abx_1;return; // READ
}

void m65ce02_device_and_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_abx_2;return; // READ
}

void m65ce02_device_and_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_abx_3;return; // READ
}

void m65ce02_device_and_abx_3(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_aby --- 
void m65ce02_device_and_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_aby_1;return; // READ
}

void m65ce02_device_and_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_aby_2;return; // READ
}

void m65ce02_device_and_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_aby_3;return; // READ
}

void m65ce02_device_and_aby_3(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_idx --- 
void m65ce02_device_and_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idx_1;return; // READ
}

void m65ce02_device_and_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idx_2;return; // READ
}

void m65ce02_device_and_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idx_3;return; // READ
}

void m65ce02_device_and_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idx_4;return; // READ
}

void m65ce02_device_and_idx_4(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_idy --- 
void m65ce02_device_and_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idy_1;return; // READ
}

void m65ce02_device_and_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idy_2;return; // READ
}

void m65ce02_device_and_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idy_3;return; // READ
}

void m65ce02_device_and_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idy_4;return; // READ
}

void m65ce02_device_and_idy_4(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_idz --- 
void m65ce02_device_and_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idz_1;return; // READ
}

void m65ce02_device_and_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idz_2;return; // READ
}

void m65ce02_device_and_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idz_3;return; // READ
}

void m65ce02_device_and_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_idz_4;return; // READ
}

void m65ce02_device_and_idz_4(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_zpg --- 
void m65ce02_device_and_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_zpg_1;return; // READ
}

void m65ce02_device_and_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_zpg_2;return; // READ
}

void m65ce02_device_and_zpg_2(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op and_zpx --- 
void m65ce02_device_and_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_zpx_1;return; // READ
}

void m65ce02_device_and_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_and_zpx_2;return; // READ
}

void m65ce02_device_and_zpx_2(m65ce02_device &cpu) {
  cpu.A &= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asl_aba --- 
void m65ce02_device_asl_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_aba_1;return; // READ
}

void m65ce02_device_asl_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_aba_2;return; // READ
}

void m65ce02_device_asl_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_aba_3;return; // READ
}

void m65ce02_device_asl_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asl_aba_4;return; // WRITE
}

void m65ce02_device_asl_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asl_abx --- 
void m65ce02_device_asl_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_abx_1;return; // READ
}

void m65ce02_device_asl_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_abx_2;return; // READ
}

void m65ce02_device_asl_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_abx_3;return; // READ
}

void m65ce02_device_asl_abx_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asl_abx_4;return; // WRITE
}

void m65ce02_device_asl_abx_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asl_acc --- 
void m65ce02_device_asl_acc_0(m65ce02_device &cpu) {
  cpu.A = cpu.do_asl(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asl_zpg --- 
void m65ce02_device_asl_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_zpg_1;return; // READ
}

void m65ce02_device_asl_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_zpg_2;return; // READ
}

void m65ce02_device_asl_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asl_zpg_3;return; // WRITE
}

void m65ce02_device_asl_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asl_zpx --- 
void m65ce02_device_asl_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_zpx_1;return; // READ
}

void m65ce02_device_asl_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asl_zpx_2;return; // READ
}

void m65ce02_device_asl_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_asl(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asl_zpx_3;return; // WRITE
}

void m65ce02_device_asl_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asr_acc --- 
void m65ce02_device_asr_acc_0(m65ce02_device &cpu) {
  cpu.A = cpu.do_asr(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asr_zpg --- 
void m65ce02_device_asr_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asr_zpg_1;return; // READ
}

void m65ce02_device_asr_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asr_zpg_2;return; // READ
}

void m65ce02_device_asr_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_asr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asr_zpg_3;return; // WRITE
}

void m65ce02_device_asr_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asr_zpx --- 
void m65ce02_device_asr_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asr_zpx_1;return; // READ
}

void m65ce02_device_asr_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asr_zpx_2;return; // READ
}

void m65ce02_device_asr_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_asr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asr_zpx_3;return; // WRITE
}

void m65ce02_device_asr_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op asw_aba --- 
void m65ce02_device_asw_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asw_aba_1;return; // READ
}

void m65ce02_device_asw_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asw_aba_2;return; // READ
}

void m65ce02_device_asw_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asw_aba_3;return; // READ
}

void m65ce02_device_asw_aba_3(m65ce02_device &cpu) {
  cpu.TMP3 = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_asw_aba_4;return; // READ
}

void m65ce02_device_asw_aba_4(m65ce02_device &cpu) {
  cpu.TMP3 = cpu.set_h(cpu.TMP3, cpu.DAT);
  cpu.P &= ~(cpu.F_C|cpu.F_N|cpu.F_Z);
  if (cpu.TMP3 & 0x8000) {
    cpu.P |= cpu.F_C;
  }
  cpu.TMP3 <<= 1;
  if (!cpu.TMP3) {
    cpu.P |= cpu.F_Z;
  } else {
    if (cpu.TMP3 & 0x8000) {
      cpu.P |= cpu.F_N;
    }
  }
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP3;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asw_aba_5;return; // WRITE
}

void m65ce02_device_asw_aba_5(m65ce02_device &cpu) {
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP3 >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_asw_aba_6;return; // WRITE
}

void m65ce02_device_asw_aba_6(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op aug_iw3 --- 
void m65ce02_device_aug_iw3_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_aug_iw3_1;return; // READ
}

void m65ce02_device_aug_iw3_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_aug_iw3_2;return; // READ
}

void m65ce02_device_aug_iw3_2(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_aug_iw3_3;return; // READ
}

void m65ce02_device_aug_iw3_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bbr_zpb --- 
void m65ce02_device_bbr_zpb_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bbr_zpb_1;return; // READ
}

void m65ce02_device_bbr_zpb_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bbr_zpb_2;return; // READ
}

void m65ce02_device_bbr_zpb_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bbr_zpb_3;return; // READ
}

void m65ce02_device_bbr_zpb_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (!(cpu.TMP2 & (1 << ((cpu.IR >> 4) & 7)))) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bbs_zpb --- 
void m65ce02_device_bbs_zpb_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bbs_zpb_1;return; // READ
}

void m65ce02_device_bbs_zpb_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bbs_zpb_2;return; // READ
}

void m65ce02_device_bbs_zpb_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bbs_zpb_3;return; // READ
}

void m65ce02_device_bbs_zpb_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.TMP2 & (1 << ((cpu.IR >> 4) & 7))) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bcc_rel --- 
void m65ce02_device_bcc_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bcc_rel_1;return; // READ
}

void m65ce02_device_bcc_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (!(cpu.P & cpu.F_C)) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bcc_rw2 --- 
void m65ce02_device_bcc_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bcc_rw2_1;return; // READ
}

void m65ce02_device_bcc_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bcc_rw2_2;return; // READ
}

void m65ce02_device_bcc_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (!(cpu.P & cpu.F_C)) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bcs_rel --- 
void m65ce02_device_bcs_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bcs_rel_1;return; // READ
}

void m65ce02_device_bcs_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_C) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bcs_rw2 --- 
void m65ce02_device_bcs_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bcs_rw2_1;return; // READ
}

void m65ce02_device_bcs_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bcs_rw2_2;return; // READ
}

void m65ce02_device_bcs_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.P & cpu.F_C) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op beq_rel --- 
void m65ce02_device_beq_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_beq_rel_1;return; // READ
}

void m65ce02_device_beq_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_Z) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op beq_rw2 --- 
void m65ce02_device_beq_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_beq_rw2_1;return; // READ
}

void m65ce02_device_beq_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_beq_rw2_2;return; // READ
}

void m65ce02_device_beq_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.P & cpu.F_Z) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bit_abx --- 
void m65ce02_device_bit_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_abx_1;return; // READ
}

void m65ce02_device_bit_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_abx_2;return; // READ
}

void m65ce02_device_bit_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_abx_3;return; // READ
}

void m65ce02_device_bit_abx_3(m65ce02_device &cpu) {
  cpu.do_bit(cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bit_imm --- 
void m65ce02_device_bit_imm_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_imm_1;return; // READ
}

void m65ce02_device_bit_imm_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_bit(cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bit_zpg --- 
void m65ce02_device_bit_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_zpg_1;return; // READ
}

void m65ce02_device_bit_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_zpg_2;return; // READ
}

void m65ce02_device_bit_zpg_2(m65ce02_device &cpu) {
  cpu.do_bit(cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bit_zpx --- 
void m65ce02_device_bit_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_zpx_1;return; // READ
}

void m65ce02_device_bit_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bit_zpx_2;return; // READ
}

void m65ce02_device_bit_zpx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_bit(cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bmi_rel --- 
void m65ce02_device_bmi_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bmi_rel_1;return; // READ
}

void m65ce02_device_bmi_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_N) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bmi_rw2 --- 
void m65ce02_device_bmi_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bmi_rw2_1;return; // READ
}

void m65ce02_device_bmi_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bmi_rw2_2;return; // READ
}

void m65ce02_device_bmi_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.P & cpu.F_N) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bne_rel --- 
void m65ce02_device_bne_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bne_rel_1;return; // READ
}

void m65ce02_device_bne_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (!(cpu.P & cpu.F_Z)) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bne_rw2 --- 
void m65ce02_device_bne_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bne_rw2_1;return; // READ
}

void m65ce02_device_bne_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bne_rw2_2;return; // READ
}

void m65ce02_device_bne_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (!(cpu.P & cpu.F_Z)) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bpl_rel --- 
void m65ce02_device_bpl_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bpl_rel_1;return; // READ
}

void m65ce02_device_bpl_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (!(cpu.P & cpu.F_N)) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bpl_rw2 --- 
void m65ce02_device_bpl_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bpl_rw2_1;return; // READ
}

void m65ce02_device_bpl_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bpl_rw2_2;return; // READ
}

void m65ce02_device_bpl_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (!(cpu.P & cpu.F_N)) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bra_rel --- 
void m65ce02_device_bra_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bra_rel_1;return; // READ
}

void m65ce02_device_bra_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.PC += int8_t(cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bra_rw2 --- 
void m65ce02_device_bra_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bra_rw2_1;return; // READ
}

void m65ce02_device_bra_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bra_rw2_2;return; // READ
}

void m65ce02_device_bra_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.PC += cpu.TMP - 1;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op brk_imp --- 
void m65ce02_device_brk_imp_0(m65ce02_device &cpu) {
  if (cpu.irq_taken) {
    cpu.ADDR = cpu.PC;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_1;return; // READ
  } else {
    cpu.ADDR = cpu.PC++;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_2;return; // READ
  }
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_brk_imp_3;return; // WRITE
}

void m65ce02_device_brk_imp_1(m65ce02_device &cpu) {
    cpu.ADDR = cpu.SP;
    cpu.DAT =  cpu.PC >> 8;
    cpu.RNW = false;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_3;return; // WRITE
}

void m65ce02_device_brk_imp_2(m65ce02_device &cpu) {
    cpu.ADDR = cpu.SP;
    cpu.DAT =  cpu.PC >> 8;
    cpu.RNW = false;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_3;return; // WRITE
}

void m65ce02_device_brk_imp_3(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_brk_imp_4;return; // WRITE
}

void m65ce02_device_brk_imp_4(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.irq_taken || cpu.nmi_state ? cpu.P & ~cpu.F_B : cpu.P;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_brk_imp_5;return; // WRITE
}

void m65ce02_device_brk_imp_5(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  if (cpu.nmi_state) {
    cpu.ADDR = 0xfffa;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_6;return; // READ
  } else {
    cpu.ADDR = 0xfffe;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_8;return; // READ
  }
  cpu.irq_taken = false;
  cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
  m6502_device_fetch(cpu);return; // fetch
}

void m65ce02_device_brk_imp_6(m65ce02_device &cpu) {
    cpu.PC = cpu.DAT;
    cpu.ADDR = 0xfffb;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_7;return; // READ
}

void m65ce02_device_brk_imp_8(m65ce02_device &cpu) {
    cpu.PC = cpu.DAT;
    cpu.ADDR = 0xffff;
    cpu.RNW = true;
    cpu.NextFn = (void *)&m65ce02_device_brk_imp_9;return; // READ
}

void m65ce02_device_brk_imp_7(m65ce02_device &cpu) {
    cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
    cpu.nmi_state = false;
    cpu.irq_taken = false;
    cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
    m6502_device_fetch(cpu);return; // fetch
}

void m65ce02_device_brk_imp_9(m65ce02_device &cpu) {
    cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
    cpu.irq_taken = false;
    cpu.P = (cpu.P | cpu.F_I) & ~cpu.F_D;
    m6502_device_fetch(cpu);return; // fetch
}

// --- op bsr_rw2 --- 
void m65ce02_device_bsr_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bsr_rw2_1;return; // READ
}

void m65ce02_device_bsr_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC>>8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_bsr_rw2_2;return; // WRITE
}

void m65ce02_device_bsr_rw2_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_bsr_rw2_3;return; // WRITE
}

void m65ce02_device_bsr_rw2_3(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bsr_rw2_4;return; // READ
}

void m65ce02_device_bsr_rw2_4(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.PC += cpu.TMP-1;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bvc_rel --- 
void m65ce02_device_bvc_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bvc_rel_1;return; // READ
}

void m65ce02_device_bvc_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (!(cpu.P & cpu.F_V)) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bvc_rw2 --- 
void m65ce02_device_bvc_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bvc_rw2_1;return; // READ
}

void m65ce02_device_bvc_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bvc_rw2_2;return; // READ
}

void m65ce02_device_bvc_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (!(cpu.P & cpu.F_V)) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bvs_rel --- 
void m65ce02_device_bvs_rel_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bvs_rel_1;return; // READ
}

void m65ce02_device_bvs_rel_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_V) {
    cpu.PC += int8_t(cpu.TMP);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op bvs_rw2 --- 
void m65ce02_device_bvs_rw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bvs_rw2_1;return; // READ
}

void m65ce02_device_bvs_rw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_bvs_rw2_2;return; // READ
}

void m65ce02_device_bvs_rw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  if (cpu.P & cpu.F_V) {
    cpu.PC += cpu.TMP-1;
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op clc_imp --- 
void m65ce02_device_clc_imp_0(m65ce02_device &cpu) {
  cpu.P &= ~cpu.F_C;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cld_imp --- 
void m65ce02_device_cld_imp_0(m65ce02_device &cpu) {
  cpu.P &= ~cpu.F_D;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cle_imp --- 
void m65ce02_device_cle_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cle_imp_1;return; // READ
}

void m65ce02_device_cle_imp_1(m65ce02_device &cpu) {
  cpu.P &= ~cpu.F_E;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cli_imp --- 
void m65ce02_device_cli_imp_0(m65ce02_device &cpu) {
  cpu.PrefetchNextFn = (void *)&m65ce02_device_cli_imp_1;
  m6502_device_prefetch(cpu);return; // prefetch
}

void m65ce02_device_cli_imp_1(m65ce02_device &cpu) {
  cpu.P &= ~cpu.F_I;
  m6502_device_postfetch(cpu);return; // postfetch
}

// --- op clv_imp --- 
void m65ce02_device_clv_imp_0(m65ce02_device &cpu) {
  cpu.P &= ~cpu.F_V;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_abx --- 
void m65ce02_device_cmp_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_abx_1;return; // READ
}

void m65ce02_device_cmp_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_abx_2;return; // READ
}

void m65ce02_device_cmp_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_abx_3;return; // READ
}

void m65ce02_device_cmp_abx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.A, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_aby --- 
void m65ce02_device_cmp_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_aby_1;return; // READ
}

void m65ce02_device_cmp_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_aby_2;return; // READ
}

void m65ce02_device_cmp_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_aby_3;return; // READ
}

void m65ce02_device_cmp_aby_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.A, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_idx --- 
void m65ce02_device_cmp_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idx_1;return; // READ
}

void m65ce02_device_cmp_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idx_2;return; // READ
}

void m65ce02_device_cmp_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idx_3;return; // READ
}

void m65ce02_device_cmp_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idx_4;return; // READ
}

void m65ce02_device_cmp_idx_4(m65ce02_device &cpu) {
  cpu.do_cmp(cpu.A, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_idy --- 
void m65ce02_device_cmp_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idy_1;return; // READ
}

void m65ce02_device_cmp_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idy_2;return; // READ
}

void m65ce02_device_cmp_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idy_3;return; // READ
}

void m65ce02_device_cmp_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idy_4;return; // READ
}

void m65ce02_device_cmp_idy_4(m65ce02_device &cpu) {
  cpu.do_cmp(cpu.A, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_idz --- 
void m65ce02_device_cmp_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idz_1;return; // READ
}

void m65ce02_device_cmp_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idz_2;return; // READ
}

void m65ce02_device_cmp_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idz_3;return; // READ
}

void m65ce02_device_cmp_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_idz_4;return; // READ
}

void m65ce02_device_cmp_idz_4(m65ce02_device &cpu) {
  cpu.do_cmp(cpu.A, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_zpg --- 
void m65ce02_device_cmp_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_zpg_1;return; // READ
}

void m65ce02_device_cmp_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_zpg_2;return; // READ
}

void m65ce02_device_cmp_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.A, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cmp_zpx --- 
void m65ce02_device_cmp_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_zpx_1;return; // READ
}

void m65ce02_device_cmp_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_zpx_2;return; // READ
}

void m65ce02_device_cmp_zpx_2(m65ce02_device &cpu) {
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cmp_zpx_3;return; // READ
}

void m65ce02_device_cmp_zpx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.A, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cpx_zpg --- 
void m65ce02_device_cpx_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpx_zpg_1;return; // READ
}

void m65ce02_device_cpx_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpx_zpg_2;return; // READ
}

void m65ce02_device_cpx_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.X, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cpy_zpg --- 
void m65ce02_device_cpy_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpy_zpg_1;return; // READ
}

void m65ce02_device_cpy_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpy_zpg_2;return; // READ
}

void m65ce02_device_cpy_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.Y, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cpz_aba --- 
void m65ce02_device_cpz_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpz_aba_1;return; // READ
}

void m65ce02_device_cpz_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpz_aba_2;return; // READ
}

void m65ce02_device_cpz_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpz_aba_3;return; // READ
}

void m65ce02_device_cpz_aba_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.Z, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cpz_imm --- 
void m65ce02_device_cpz_imm_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpz_imm_1;return; // READ
}

void m65ce02_device_cpz_imm_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.Z, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op cpz_zpg --- 
void m65ce02_device_cpz_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpz_zpg_1;return; // READ
}

void m65ce02_device_cpz_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_cpz_zpg_2;return; // READ
}

void m65ce02_device_cpz_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_cmp(cpu.Z, cpu.TMP);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dec_aba --- 
void m65ce02_device_dec_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_aba_1;return; // READ
}

void m65ce02_device_dec_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_aba_2;return; // READ
}

void m65ce02_device_dec_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_aba_3;return; // READ
}

void m65ce02_device_dec_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_dec_aba_4;return; // WRITE
}

void m65ce02_device_dec_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dec_abx --- 
void m65ce02_device_dec_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_abx_1;return; // READ
}

void m65ce02_device_dec_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_abx_2;return; // READ
}

void m65ce02_device_dec_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_abx_3;return; // READ
}

void m65ce02_device_dec_abx_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_dec_abx_4;return; // WRITE
}

void m65ce02_device_dec_abx_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dec_acc --- 
void m65ce02_device_dec_acc_0(m65ce02_device &cpu) {
  cpu.A--;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dec_zpg --- 
void m65ce02_device_dec_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_zpg_1;return; // READ
}

void m65ce02_device_dec_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_zpg_2;return; // READ
}

void m65ce02_device_dec_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_dec_zpg_3;return; // WRITE
}

void m65ce02_device_dec_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dec_zpx --- 
void m65ce02_device_dec_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_zpx_1;return; // READ
}

void m65ce02_device_dec_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dec_zpx_2;return; // READ
}

void m65ce02_device_dec_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2--;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_dec_zpx_3;return; // WRITE
}

void m65ce02_device_dec_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dew_zpg --- 
void m65ce02_device_dew_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dew_zpg_1;return; // READ
}

void m65ce02_device_dew_zpg_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dew_zpg_2;return; // READ
}

void m65ce02_device_dew_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_dew_zpg_3;return; // READ
}

void m65ce02_device_dew_zpg_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.P &= ~(cpu.F_N|cpu.F_Z);
  cpu.TMP++;
  if (!cpu.TMP) {
    cpu.P |= cpu.F_Z;
  } else {
    if (cpu.TMP & 0x8000) {
      cpu.P |= cpu.F_N;
    }
  }
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.DAT =  cpu.TMP;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_dew_zpg_4;return; // WRITE
}

void m65ce02_device_dew_zpg_4(m65ce02_device &cpu) {
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.DAT =  cpu.TMP >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_dew_zpg_5;return; // WRITE
}

void m65ce02_device_dew_zpg_5(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dex_imp --- 
void m65ce02_device_dex_imp_0(m65ce02_device &cpu) {
  cpu.X--;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dey_imp --- 
void m65ce02_device_dey_imp_0(m65ce02_device &cpu) {
  cpu.Y--;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op dez_imp --- 
void m65ce02_device_dez_imp_0(m65ce02_device &cpu) {
  cpu.Z--;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_abx --- 
void m65ce02_device_eor_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_abx_1;return; // READ
}

void m65ce02_device_eor_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_abx_2;return; // READ
}

void m65ce02_device_eor_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_abx_3;return; // READ
}

void m65ce02_device_eor_abx_3(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_aby --- 
void m65ce02_device_eor_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_aby_1;return; // READ
}

void m65ce02_device_eor_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_aby_2;return; // READ
}

void m65ce02_device_eor_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_aby_3;return; // READ
}

void m65ce02_device_eor_aby_3(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_idx --- 
void m65ce02_device_eor_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idx_1;return; // READ
}

void m65ce02_device_eor_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idx_2;return; // READ
}

void m65ce02_device_eor_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idx_3;return; // READ
}

void m65ce02_device_eor_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idx_4;return; // READ
}

void m65ce02_device_eor_idx_4(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_idy --- 
void m65ce02_device_eor_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idy_1;return; // READ
}

void m65ce02_device_eor_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idy_2;return; // READ
}

void m65ce02_device_eor_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idy_3;return; // READ
}

void m65ce02_device_eor_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idy_4;return; // READ
}

void m65ce02_device_eor_idy_4(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_idz --- 
void m65ce02_device_eor_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idz_1;return; // READ
}

void m65ce02_device_eor_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idz_2;return; // READ
}

void m65ce02_device_eor_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idz_3;return; // READ
}

void m65ce02_device_eor_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_idz_4;return; // READ
}

void m65ce02_device_eor_idz_4(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_zpg --- 
void m65ce02_device_eor_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_zpg_1;return; // READ
}

void m65ce02_device_eor_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_zpg_2;return; // READ
}

void m65ce02_device_eor_zpg_2(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op eor_zpx --- 
void m65ce02_device_eor_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_zpx_1;return; // READ
}

void m65ce02_device_eor_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_eor_zpx_2;return; // READ
}

void m65ce02_device_eor_zpx_2(m65ce02_device &cpu) {
  cpu.A ^= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inc_aba --- 
void m65ce02_device_inc_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_aba_1;return; // READ
}

void m65ce02_device_inc_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_aba_2;return; // READ
}

void m65ce02_device_inc_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_aba_3;return; // READ
}

void m65ce02_device_inc_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_inc_aba_4;return; // WRITE
}

void m65ce02_device_inc_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inc_abx --- 
void m65ce02_device_inc_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_abx_1;return; // READ
}

void m65ce02_device_inc_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_abx_2;return; // READ
}

void m65ce02_device_inc_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_abx_3;return; // READ
}

void m65ce02_device_inc_abx_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_inc_abx_4;return; // WRITE
}

void m65ce02_device_inc_abx_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inc_acc --- 
void m65ce02_device_inc_acc_0(m65ce02_device &cpu) {
  cpu.A++;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inc_zpg --- 
void m65ce02_device_inc_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_zpg_1;return; // READ
}

void m65ce02_device_inc_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_zpg_2;return; // READ
}

void m65ce02_device_inc_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_inc_zpg_3;return; // WRITE
}

void m65ce02_device_inc_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inc_zpx --- 
void m65ce02_device_inc_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_zpx_1;return; // READ
}

void m65ce02_device_inc_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inc_zpx_2;return; // READ
}

void m65ce02_device_inc_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2++;
  cpu.set_nz(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_inc_zpx_3;return; // WRITE
}

void m65ce02_device_inc_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inw_zpg --- 
void m65ce02_device_inw_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inw_zpg_1;return; // READ
}

void m65ce02_device_inw_zpg_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inw_zpg_2;return; // READ
}

void m65ce02_device_inw_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_inw_zpg_3;return; // READ
}

void m65ce02_device_inw_zpg_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.P &= ~(cpu.F_N|cpu.F_Z);
  cpu.TMP++;
  if (!cpu.TMP) {
    cpu.P |= cpu.F_Z;
  } else {
    if (cpu.TMP & 0x8000) {
      cpu.P |= cpu.F_N;
    }
  }
  cpu.TMP2--;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.DAT =  cpu.TMP;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_inw_zpg_4;return; // WRITE
}

void m65ce02_device_inw_zpg_4(m65ce02_device &cpu) {
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.DAT =  cpu.TMP >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_inw_zpg_5;return; // WRITE
}

void m65ce02_device_inw_zpg_5(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inx_imp --- 
void m65ce02_device_inx_imp_0(m65ce02_device &cpu) {
  cpu.X++;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op iny_imp --- 
void m65ce02_device_iny_imp_0(m65ce02_device &cpu) {
  cpu.Y++;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op inz_imp --- 
void m65ce02_device_inz_imp_0(m65ce02_device &cpu) {
  cpu.Z++;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op jmp_iax --- 
void m65ce02_device_jmp_iax_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_iax_1;return; // READ
}

void m65ce02_device_jmp_iax_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_iax_2;return; // READ
}

void m65ce02_device_jmp_iax_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_iax_3;return; // READ
}

void m65ce02_device_jmp_iax_3(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_iax_4;return; // READ
}

void m65ce02_device_jmp_iax_4(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op jmp_ind --- 
void m65ce02_device_jmp_ind_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_ind_1;return; // READ
}

void m65ce02_device_jmp_ind_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_ind_2;return; // READ
}

void m65ce02_device_jmp_ind_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_ind_3;return; // READ
}

void m65ce02_device_jmp_ind_3(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jmp_ind_4;return; // READ
}

void m65ce02_device_jmp_ind_4(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op jsr_adr --- 
void m65ce02_device_jsr_adr_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_adr_1;return; // READ
}

void m65ce02_device_jsr_adr_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC>>8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_jsr_adr_2;return; // WRITE
}

void m65ce02_device_jsr_adr_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_jsr_adr_3;return; // WRITE
}

void m65ce02_device_jsr_adr_3(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_adr_4;return; // READ
}

void m65ce02_device_jsr_adr_4(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.PC = cpu.TMP;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op jsr_iax --- 
void m65ce02_device_jsr_iax_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_iax_1;return; // READ
}

void m65ce02_device_jsr_iax_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC>>8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_jsr_iax_2;return; // WRITE
}

void m65ce02_device_jsr_iax_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_jsr_iax_3;return; // WRITE
}

void m65ce02_device_jsr_iax_3(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_iax_4;return; // READ
}

void m65ce02_device_jsr_iax_4(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_iax_5;return; // READ
}

void m65ce02_device_jsr_iax_5(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_iax_6;return; // READ
}

void m65ce02_device_jsr_iax_6(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  cpu.PC += cpu.X;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op jsr_ind --- 
void m65ce02_device_jsr_ind_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_ind_1;return; // READ
}

void m65ce02_device_jsr_ind_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC>>8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_jsr_ind_2;return; // WRITE
}

void m65ce02_device_jsr_ind_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.PC;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_jsr_ind_3;return; // WRITE
}

void m65ce02_device_jsr_ind_3(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_ind_4;return; // READ
}

void m65ce02_device_jsr_ind_4(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_ind_5;return; // READ
}

void m65ce02_device_jsr_ind_5(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_jsr_ind_6;return; // READ
}

void m65ce02_device_jsr_ind_6(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_abx --- 
void m65ce02_device_lda_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_abx_1;return; // READ
}

void m65ce02_device_lda_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_abx_2;return; // READ
}

void m65ce02_device_lda_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP + cpu.X;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_abx_3;return; // READ
}

void m65ce02_device_lda_abx_3(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_aby --- 
void m65ce02_device_lda_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_aby_1;return; // READ
}

void m65ce02_device_lda_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_aby_2;return; // READ
}

void m65ce02_device_lda_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP + cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_aby_3;return; // READ
}

void m65ce02_device_lda_aby_3(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_idx --- 
void m65ce02_device_lda_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idx_1;return; // READ
}

void m65ce02_device_lda_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idx_2;return; // READ
}

void m65ce02_device_lda_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idx_3;return; // READ
}

void m65ce02_device_lda_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idx_4;return; // READ
}

void m65ce02_device_lda_idx_4(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_idy --- 
void m65ce02_device_lda_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idy_1;return; // READ
}

void m65ce02_device_lda_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idy_2;return; // READ
}

void m65ce02_device_lda_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idy_3;return; // READ
}

void m65ce02_device_lda_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idy_4;return; // READ
}

void m65ce02_device_lda_idy_4(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_idz --- 
void m65ce02_device_lda_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idz_1;return; // READ
}

void m65ce02_device_lda_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idz_2;return; // READ
}

void m65ce02_device_lda_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idz_3;return; // READ
}

void m65ce02_device_lda_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_idz_4;return; // READ
}

void m65ce02_device_lda_idz_4(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_isy --- 
void m65ce02_device_lda_isy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_isy_1;return; // READ
}

void m65ce02_device_lda_isy_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_isy_2;return; // READ
}

void m65ce02_device_lda_isy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_E) {
    cpu.TMP = cpu.set_l(cpu.SP, cpu.SP+cpu.TMP);
  } else {
    cpu.TMP = cpu.SP + cpu.TMP;
  }
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_isy_3;return; // READ
}

void m65ce02_device_lda_isy_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP++;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_isy_4;return; // READ
}

void m65ce02_device_lda_isy_4(m65ce02_device &cpu) {
  cpu.TMP = cpu.TMP2 | (cpu.DAT << 8);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_isy_5;return; // READ
}

void m65ce02_device_lda_isy_5(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_zpg --- 
void m65ce02_device_lda_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_zpg_1;return; // READ
}

void m65ce02_device_lda_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_zpg_2;return; // READ
}

void m65ce02_device_lda_zpg_2(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lda_zpx --- 
void m65ce02_device_lda_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_zpx_1;return; // READ
}

void m65ce02_device_lda_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lda_zpx_2;return; // READ
}

void m65ce02_device_lda_zpx_2(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldx_aby --- 
void m65ce02_device_ldx_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_aby_1;return; // READ
}

void m65ce02_device_ldx_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_aby_2;return; // READ
}

void m65ce02_device_ldx_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP + cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_aby_3;return; // READ
}

void m65ce02_device_ldx_aby_3(m65ce02_device &cpu) {
  cpu.X = cpu.DAT;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldx_zpg --- 
void m65ce02_device_ldx_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_zpg_1;return; // READ
}

void m65ce02_device_ldx_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_zpg_2;return; // READ
}

void m65ce02_device_ldx_zpg_2(m65ce02_device &cpu) {
  cpu.X = cpu.DAT;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldx_zpy --- 
void m65ce02_device_ldx_zpy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_zpy_1;return; // READ
}

void m65ce02_device_ldx_zpy_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.Y);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldx_zpy_2;return; // READ
}

void m65ce02_device_ldx_zpy_2(m65ce02_device &cpu) {
  cpu.X = cpu.DAT;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldy_abx --- 
void m65ce02_device_ldy_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_abx_1;return; // READ
}

void m65ce02_device_ldy_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_abx_2;return; // READ
}

void m65ce02_device_ldy_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_abx_3;return; // READ
}

void m65ce02_device_ldy_abx_3(m65ce02_device &cpu) {
  cpu.Y = cpu.DAT;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldy_zpg --- 
void m65ce02_device_ldy_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_zpg_1;return; // READ
}

void m65ce02_device_ldy_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_zpg_2;return; // READ
}

void m65ce02_device_ldy_zpg_2(m65ce02_device &cpu) {
  cpu.Y = cpu.DAT;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldy_zpx --- 
void m65ce02_device_ldy_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_zpx_1;return; // READ
}

void m65ce02_device_ldy_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldy_zpx_2;return; // READ
}

void m65ce02_device_ldy_zpx_2(m65ce02_device &cpu) {
  cpu.Y = cpu.DAT;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldz_aba --- 
void m65ce02_device_ldz_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_aba_1;return; // READ
}

void m65ce02_device_ldz_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_aba_2;return; // READ
}

void m65ce02_device_ldz_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_aba_3;return; // READ
}

void m65ce02_device_ldz_aba_3(m65ce02_device &cpu) {
  cpu.Z = cpu.DAT;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldz_abx --- 
void m65ce02_device_ldz_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_abx_1;return; // READ
}

void m65ce02_device_ldz_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_abx_2;return; // READ
}

void m65ce02_device_ldz_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP + cpu.X;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_abx_3;return; // READ
}

void m65ce02_device_ldz_abx_3(m65ce02_device &cpu) {
  cpu.Z = cpu.DAT;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ldz_imm --- 
void m65ce02_device_ldz_imm_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ldz_imm_1;return; // READ
}

void m65ce02_device_ldz_imm_1(m65ce02_device &cpu) {
  cpu.Z = cpu.DAT;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lsr_aba --- 
void m65ce02_device_lsr_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_aba_1;return; // READ
}

void m65ce02_device_lsr_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_aba_2;return; // READ
}

void m65ce02_device_lsr_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_aba_3;return; // READ
}

void m65ce02_device_lsr_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_lsr_aba_4;return; // WRITE
}

void m65ce02_device_lsr_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lsr_abx --- 
void m65ce02_device_lsr_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_abx_1;return; // READ
}

void m65ce02_device_lsr_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_abx_2;return; // READ
}

void m65ce02_device_lsr_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.set_l(cpu.TMP, cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_abx_3;return; // READ
}

void m65ce02_device_lsr_abx_3(m65ce02_device &cpu) {
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_abx_4;return; // READ
}

void m65ce02_device_lsr_abx_4(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_lsr_abx_5;return; // WRITE
}

void m65ce02_device_lsr_abx_5(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lsr_acc --- 
void m65ce02_device_lsr_acc_0(m65ce02_device &cpu) {
  cpu.A = cpu.do_lsr(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lsr_zpg --- 
void m65ce02_device_lsr_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_zpg_1;return; // READ
}

void m65ce02_device_lsr_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_zpg_2;return; // READ
}

void m65ce02_device_lsr_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_lsr_zpg_3;return; // WRITE
}

void m65ce02_device_lsr_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op lsr_zpx --- 
void m65ce02_device_lsr_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_zpx_1;return; // READ
}

void m65ce02_device_lsr_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_lsr_zpx_2;return; // READ
}

void m65ce02_device_lsr_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_lsr(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_lsr_zpx_3;return; // WRITE
}

void m65ce02_device_lsr_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op neg_acc --- 
void m65ce02_device_neg_acc_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_neg_acc_1;return; // READ
}

void m65ce02_device_neg_acc_1(m65ce02_device &cpu) {
  cpu.A = -cpu.A;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_abx --- 
void m65ce02_device_ora_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_abx_1;return; // READ
}

void m65ce02_device_ora_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_abx_2;return; // READ
}

void m65ce02_device_ora_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_abx_3;return; // READ
}

void m65ce02_device_ora_abx_3(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_aby --- 
void m65ce02_device_ora_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_aby_1;return; // READ
}

void m65ce02_device_ora_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_aby_2;return; // READ
}

void m65ce02_device_ora_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_aby_3;return; // READ
}

void m65ce02_device_ora_aby_3(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_idx --- 
void m65ce02_device_ora_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idx_1;return; // READ
}

void m65ce02_device_ora_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idx_2;return; // READ
}

void m65ce02_device_ora_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idx_3;return; // READ
}

void m65ce02_device_ora_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idx_4;return; // READ
}

void m65ce02_device_ora_idx_4(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_idy --- 
void m65ce02_device_ora_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idy_1;return; // READ
}

void m65ce02_device_ora_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idy_2;return; // READ
}

void m65ce02_device_ora_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idy_3;return; // READ
}

void m65ce02_device_ora_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idy_4;return; // READ
}

void m65ce02_device_ora_idy_4(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_idz --- 
void m65ce02_device_ora_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idz_1;return; // READ
}

void m65ce02_device_ora_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idz_2;return; // READ
}

void m65ce02_device_ora_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idz_3;return; // READ
}

void m65ce02_device_ora_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_idz_4;return; // READ
}

void m65ce02_device_ora_idz_4(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_zpg --- 
void m65ce02_device_ora_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_zpg_1;return; // READ
}

void m65ce02_device_ora_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_zpg_2;return; // READ
}

void m65ce02_device_ora_zpg_2(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ora_zpx --- 
void m65ce02_device_ora_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_zpx_1;return; // READ
}

void m65ce02_device_ora_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ora_zpx_2;return; // READ
}

void m65ce02_device_ora_zpx_2(m65ce02_device &cpu) {
  cpu.A |= cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op pha_imp --- 
void m65ce02_device_pha_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_pha_imp_1;return; // READ
}

void m65ce02_device_pha_imp_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_pha_imp_2;return; // WRITE
}

void m65ce02_device_pha_imp_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  m6502_device_fetch(cpu);return; // fetch
}

// --- op php_imp --- 
void m65ce02_device_php_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_php_imp_1;return; // READ
}

void m65ce02_device_php_imp_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.P;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_php_imp_2;return; // WRITE
}

void m65ce02_device_php_imp_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  m6502_device_fetch(cpu);return; // fetch
}

// --- op phw_aba --- 
void m65ce02_device_phw_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phw_aba_1;return; // READ
}

void m65ce02_device_phw_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phw_aba_2;return; // READ
}

void m65ce02_device_phw_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phw_aba_3;return; // READ
}

void m65ce02_device_phw_aba_3(m65ce02_device &cpu) {
  cpu.TMP3 = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phw_aba_4;return; // READ
}

void m65ce02_device_phw_aba_4(m65ce02_device &cpu) {
  cpu.TMP3 = cpu.set_h(cpu.TMP3, cpu.DAT);
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.TMP3;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phw_aba_5;return; // WRITE
}

void m65ce02_device_phw_aba_5(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.TMP3 >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phw_aba_6;return; // WRITE
}

void m65ce02_device_phw_aba_6(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op phw_iw2 --- 
void m65ce02_device_phw_iw2_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phw_iw2_1;return; // READ
}

void m65ce02_device_phw_iw2_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phw_iw2_2;return; // READ
}

void m65ce02_device_phw_iw2_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.TMP;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phw_iw2_3;return; // WRITE
}

void m65ce02_device_phw_iw2_3(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.TMP >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phw_iw2_4;return; // WRITE
}

void m65ce02_device_phw_iw2_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op phx_imp --- 
void m65ce02_device_phx_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phx_imp_1;return; // READ
}

void m65ce02_device_phx_imp_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.X;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phx_imp_2;return; // WRITE
}

void m65ce02_device_phx_imp_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  m6502_device_fetch(cpu);return; // fetch
}

// --- op phy_imp --- 
void m65ce02_device_phy_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phy_imp_1;return; // READ
}

void m65ce02_device_phy_imp_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.Y;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phy_imp_2;return; // WRITE
}

void m65ce02_device_phy_imp_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  m6502_device_fetch(cpu);return; // fetch
}

// --- op phz_imp --- 
void m65ce02_device_phz_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_phz_imp_1;return; // READ
}

void m65ce02_device_phz_imp_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.DAT =  cpu.Z;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_phz_imp_2;return; // WRITE
}

void m65ce02_device_phz_imp_2(m65ce02_device &cpu) {
  cpu.dec_SP_ce();
  m6502_device_fetch(cpu);return; // fetch
}

// --- op pla_imp --- 
void m65ce02_device_pla_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_pla_imp_1;return; // READ
}

void m65ce02_device_pla_imp_1(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_pla_imp_2;return; // READ
}

void m65ce02_device_pla_imp_2(m65ce02_device &cpu) {
  cpu.A = cpu.DAT;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op plp_imp --- 
void m65ce02_device_plp_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_plp_imp_1;return; // READ
}

void m65ce02_device_plp_imp_1(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_plp_imp_2;return; // READ
}

void m65ce02_device_plp_imp_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT | cpu.F_B;
  cpu.PrefetchNextFn = (void *)&m65ce02_device_plp_imp_3;
  m6502_device_prefetch(cpu);return; // prefetch
}

void m65ce02_device_plp_imp_3(m65ce02_device &cpu) {
  cpu.P = cpu.TMP;
  m6502_device_postfetch(cpu);return; // postfetch
}

// --- op plx_imp --- 
void m65ce02_device_plx_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_plx_imp_1;return; // READ
}

void m65ce02_device_plx_imp_1(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_plx_imp_2;return; // READ
}

void m65ce02_device_plx_imp_2(m65ce02_device &cpu) {
  cpu.X = cpu.DAT;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ply_imp --- 
void m65ce02_device_ply_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ply_imp_1;return; // READ
}

void m65ce02_device_ply_imp_1(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ply_imp_2;return; // READ
}

void m65ce02_device_ply_imp_2(m65ce02_device &cpu) {
  cpu.Y = cpu.DAT;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op plz_imp --- 
void m65ce02_device_plz_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_plz_imp_1;return; // READ
}

void m65ce02_device_plz_imp_1(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_plz_imp_2;return; // READ
}

void m65ce02_device_plz_imp_2(m65ce02_device &cpu) {
  cpu.Z = cpu.DAT;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rmb_bzp --- 
void m65ce02_device_rmb_bzp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rmb_bzp_1;return; // READ
}

void m65ce02_device_rmb_bzp_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rmb_bzp_2;return; // READ
}

void m65ce02_device_rmb_bzp_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 &= ~(1 << ((cpu.IR >> 4) & 7));
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_rmb_bzp_3;return; // WRITE
}

void m65ce02_device_rmb_bzp_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rol_aba --- 
void m65ce02_device_rol_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_aba_1;return; // READ
}

void m65ce02_device_rol_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_aba_2;return; // READ
}

void m65ce02_device_rol_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_aba_3;return; // READ
}

void m65ce02_device_rol_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_rol_aba_4;return; // WRITE
}

void m65ce02_device_rol_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rol_abx --- 
void m65ce02_device_rol_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_abx_1;return; // READ
}

void m65ce02_device_rol_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_abx_2;return; // READ
}

void m65ce02_device_rol_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_abx_3;return; // READ
}

void m65ce02_device_rol_abx_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_rol_abx_4;return; // WRITE
}

void m65ce02_device_rol_abx_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rol_acc --- 
void m65ce02_device_rol_acc_0(m65ce02_device &cpu) {
  cpu.A = cpu.do_rol(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rol_zpg --- 
void m65ce02_device_rol_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_zpg_1;return; // READ
}

void m65ce02_device_rol_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_zpg_2;return; // READ
}

void m65ce02_device_rol_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_rol_zpg_3;return; // WRITE
}

void m65ce02_device_rol_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rol_zpx --- 
void m65ce02_device_rol_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_zpx_1;return; // READ
}

void m65ce02_device_rol_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rol_zpx_2;return; // READ
}

void m65ce02_device_rol_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_rol(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_rol_zpx_3;return; // WRITE
}

void m65ce02_device_rol_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ror_aba --- 
void m65ce02_device_ror_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_aba_1;return; // READ
}

void m65ce02_device_ror_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_aba_2;return; // READ
}

void m65ce02_device_ror_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_aba_3;return; // READ
}

void m65ce02_device_ror_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_ror_aba_4;return; // WRITE
}

void m65ce02_device_ror_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ror_abx --- 
void m65ce02_device_ror_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_abx_1;return; // READ
}

void m65ce02_device_ror_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_abx_2;return; // READ
}

void m65ce02_device_ror_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_abx_3;return; // READ
}

void m65ce02_device_ror_abx_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_ror_abx_4;return; // WRITE
}

void m65ce02_device_ror_abx_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ror_acc --- 
void m65ce02_device_ror_acc_0(m65ce02_device &cpu) {
  cpu.A = cpu.do_ror(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ror_zpg --- 
void m65ce02_device_ror_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_zpg_1;return; // READ
}

void m65ce02_device_ror_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.B|cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_zpg_2;return; // READ
}

void m65ce02_device_ror_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_ror_zpg_3;return; // WRITE
}

void m65ce02_device_ror_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op ror_zpx --- 
void m65ce02_device_ror_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_zpx_1;return; // READ
}

void m65ce02_device_ror_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_ror_zpx_2;return; // READ
}

void m65ce02_device_ror_zpx_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 = cpu.do_ror(cpu.TMP2);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_ror_zpx_3;return; // WRITE
}

void m65ce02_device_ror_zpx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op row_aba --- 
void m65ce02_device_row_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_row_aba_1;return; // READ
}

void m65ce02_device_row_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_row_aba_2;return; // READ
}

void m65ce02_device_row_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_row_aba_3;return; // READ
}

void m65ce02_device_row_aba_3(m65ce02_device &cpu) {
  cpu.TMP3 = cpu.DAT;
  cpu.ADDR = cpu.TMP+1;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_row_aba_4;return; // READ
}

void m65ce02_device_row_aba_4(m65ce02_device &cpu) {
  cpu.TMP3 = cpu.set_h(cpu.TMP3, cpu.DAT);
  cpu.TMP2 = cpu.P;
  cpu.P &= ~(cpu.F_C|cpu.F_N|cpu.F_Z);
  if (cpu.TMP3 & 0x8000) {
    cpu.P |= cpu.F_C;
  }
  cpu.TMP3 <<= 1;
  if (cpu.TMP2 & cpu.F_C) {
    cpu.TMP3 |= 0x0001;
  }
  if (!cpu.TMP3) {
    cpu.P |= cpu.F_Z;
  } else {
    if (cpu.TMP3 & 0x8000) {
      cpu.P |= cpu.F_N;
    }
  }
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP3;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_row_aba_5;return; // WRITE
}

void m65ce02_device_row_aba_5(m65ce02_device &cpu) {
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP3 >> 8;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_row_aba_6;return; // WRITE
}

void m65ce02_device_row_aba_6(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rti_imp --- 
void m65ce02_device_rti_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rti_imp_1;return; // READ
}

void m65ce02_device_rti_imp_1(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rti_imp_2;return; // READ
}

void m65ce02_device_rti_imp_2(m65ce02_device &cpu) {
  cpu.P = cpu.DAT | cpu.F_B;
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rti_imp_3;return; // READ
}

void m65ce02_device_rti_imp_3(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rti_imp_4;return; // READ
}

void m65ce02_device_rti_imp_4(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rtn_imm --- 
void m65ce02_device_rtn_imm_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rtn_imm_1;return; // READ
}

void m65ce02_device_rtn_imm_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_E) {
    cpu.SP = cpu.set_l(cpu.SP, cpu.SP+cpu.TMP);
  } else {
    cpu.SP += cpu.TMP;
  }
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rtn_imm_2;return; // READ
}

void m65ce02_device_rtn_imm_2(m65ce02_device &cpu) {
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rtn_imm_3;return; // READ
}

void m65ce02_device_rtn_imm_3(m65ce02_device &cpu) {
  cpu.inc_SP();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rtn_imm_4;return; // READ
}

void m65ce02_device_rtn_imm_4(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.inc_SP();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rtn_imm_5;return; // READ
}

void m65ce02_device_rtn_imm_5(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rtn_imm_6;return; // READ
}

void m65ce02_device_rtn_imm_6(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op rts_imp --- 
void m65ce02_device_rts_imp_0(m65ce02_device &cpu) {
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rts_imp_1;return; // READ
}

void m65ce02_device_rts_imp_1(m65ce02_device &cpu) {
  cpu.PC = cpu.DAT;
  cpu.inc_SP_ce();
  cpu.ADDR = cpu.SP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rts_imp_2;return; // READ
}

void m65ce02_device_rts_imp_2(m65ce02_device &cpu) {
  cpu.PC = cpu.set_h(cpu.PC, cpu.DAT);
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_rts_imp_3;return; // READ
}

void m65ce02_device_rts_imp_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_aba --- 
void m65ce02_device_sbc_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_aba_1;return; // READ
}

void m65ce02_device_sbc_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_aba_2;return; // READ
}

void m65ce02_device_sbc_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_aba_3;return; // READ
}

void m65ce02_device_sbc_aba_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_abx --- 
void m65ce02_device_sbc_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_abx_1;return; // READ
}

void m65ce02_device_sbc_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_abx_2;return; // READ
}

void m65ce02_device_sbc_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.X;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_abx_3;return; // READ
}

void m65ce02_device_sbc_abx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_aby --- 
void m65ce02_device_sbc_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_aby_1;return; // READ
}

void m65ce02_device_sbc_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_aby_2;return; // READ
}

void m65ce02_device_sbc_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.TMP += cpu.Y;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_aby_3;return; // READ
}

void m65ce02_device_sbc_aby_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_idx --- 
void m65ce02_device_sbc_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idx_1;return; // READ
}

void m65ce02_device_sbc_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idx_2;return; // READ
}

void m65ce02_device_sbc_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idx_3;return; // READ
}

void m65ce02_device_sbc_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idx_4;return; // READ
}

void m65ce02_device_sbc_idx_4(m65ce02_device &cpu) {
  cpu.do_sbc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_idy --- 
void m65ce02_device_sbc_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idy_1;return; // READ
}

void m65ce02_device_sbc_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idy_2;return; // READ
}

void m65ce02_device_sbc_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idy_3;return; // READ
}

void m65ce02_device_sbc_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idy_4;return; // READ
}

void m65ce02_device_sbc_idy_4(m65ce02_device &cpu) {
  cpu.do_sbc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_idz --- 
void m65ce02_device_sbc_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idz_1;return; // READ
}

void m65ce02_device_sbc_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idz_2;return; // READ
}

void m65ce02_device_sbc_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idz_3;return; // READ
}

void m65ce02_device_sbc_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_idz_4;return; // READ
}

void m65ce02_device_sbc_idz_4(m65ce02_device &cpu) {
  cpu.do_sbc(cpu.DAT);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_imm --- 
void m65ce02_device_sbc_imm_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_imm_1;return; // READ
}

void m65ce02_device_sbc_imm_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_zpg --- 
void m65ce02_device_sbc_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_zpg_1;return; // READ
}

void m65ce02_device_sbc_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_zpg_2;return; // READ
}

void m65ce02_device_sbc_zpg_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sbc_zpx --- 
void m65ce02_device_sbc_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_zpx_1;return; // READ
}

void m65ce02_device_sbc_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_zpx_2;return; // READ
}

void m65ce02_device_sbc_zpx_2(m65ce02_device &cpu) {
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sbc_zpx_3;return; // READ
}

void m65ce02_device_sbc_zpx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.do_sbc(cpu.TMP);
  if (cpu.P & cpu.F_D) {
    cpu.set_nz(cpu.A);
  }
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sec_imp --- 
void m65ce02_device_sec_imp_0(m65ce02_device &cpu) {
  cpu.P |= cpu.F_C;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sed_imp --- 
void m65ce02_device_sed_imp_0(m65ce02_device &cpu) {
  cpu.P |= cpu.F_D;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op see_imp --- 
void m65ce02_device_see_imp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_see_imp_1;return; // READ
}

void m65ce02_device_see_imp_1(m65ce02_device &cpu) {
  cpu.P |= cpu.F_E;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sei_imp --- 
void m65ce02_device_sei_imp_0(m65ce02_device &cpu) {
  cpu.PrefetchNextFn = (void *)&m65ce02_device_sei_imp_1;
  m6502_device_prefetch(cpu);return; // prefetch
}

void m65ce02_device_sei_imp_1(m65ce02_device &cpu) {
  cpu.P |= cpu.F_I;
  m6502_device_postfetch(cpu);return; // postfetch
}

// --- op smb_bzp --- 
void m65ce02_device_smb_bzp_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_smb_bzp_1;return; // READ
}

void m65ce02_device_smb_bzp_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_smb_bzp_2;return; // READ
}

void m65ce02_device_smb_bzp_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 |= 1 << ((cpu.IR >> 4) & 7);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_smb_bzp_3;return; // WRITE
}

void m65ce02_device_smb_bzp_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_abx --- 
void m65ce02_device_sta_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_abx_1;return; // READ
}

void m65ce02_device_sta_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_abx_2;return; // READ
}

void m65ce02_device_sta_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.X;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_abx_3;return; // WRITE
}

void m65ce02_device_sta_abx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_aby --- 
void m65ce02_device_sta_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_aby_1;return; // READ
}

void m65ce02_device_sta_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_aby_2;return; // READ
}

void m65ce02_device_sta_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_aby_3;return; // WRITE
}

void m65ce02_device_sta_aby_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_idx --- 
void m65ce02_device_sta_idx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idx_1;return; // READ
}

void m65ce02_device_sta_idx_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP2 += cpu.X;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idx_2;return; // READ
}

void m65ce02_device_sta_idx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idx_3;return; // READ
}

void m65ce02_device_sta_idx_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_idx_4;return; // WRITE
}

void m65ce02_device_sta_idx_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_idy --- 
void m65ce02_device_sta_idy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idy_1;return; // READ
}

void m65ce02_device_sta_idy_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idy_2;return; // READ
}

void m65ce02_device_sta_idy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idy_3;return; // READ
}

void m65ce02_device_sta_idy_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_idy_4;return; // WRITE
}

void m65ce02_device_sta_idy_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_idz --- 
void m65ce02_device_sta_idz_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idz_1;return; // READ
}

void m65ce02_device_sta_idz_1(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idz_2;return; // READ
}

void m65ce02_device_sta_idz_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.TMP2++;
  cpu.ADDR = cpu.B|cpu.TMP2;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_idz_3;return; // READ
}

void m65ce02_device_sta_idz_3(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Z;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_idz_4;return; // WRITE
}

void m65ce02_device_sta_idz_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_isy --- 
void m65ce02_device_sta_isy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_isy_1;return; // READ
}

void m65ce02_device_sta_isy_1(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_isy_2;return; // READ
}

void m65ce02_device_sta_isy_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  if (cpu.P & cpu.F_E) {
    cpu.TMP = cpu.set_l(cpu.SP, cpu.SP+cpu.TMP);
  } else {
    cpu.TMP = cpu.SP + cpu.TMP;
  }
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_isy_3;return; // READ
}

void m65ce02_device_sta_isy_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  cpu.TMP++;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_isy_4;return; // READ
}

void m65ce02_device_sta_isy_4(m65ce02_device &cpu) {
  cpu.TMP = cpu.TMP2 | (cpu.DAT << 8);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_isy_5;return; // WRITE
}

void m65ce02_device_sta_isy_5(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_zpg --- 
void m65ce02_device_sta_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_zpg_1;return; // READ
}

void m65ce02_device_sta_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_zpg_2;return; // WRITE
}

void m65ce02_device_sta_zpg_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sta_zpx --- 
void m65ce02_device_sta_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sta_zpx_1;return; // READ
}

void m65ce02_device_sta_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sta_zpx_2;return; // WRITE
}

void m65ce02_device_sta_zpx_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stx_aby --- 
void m65ce02_device_stx_aby_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stx_aby_1;return; // READ
}

void m65ce02_device_stx_aby_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stx_aby_2;return; // READ
}

void m65ce02_device_stx_aby_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.Y;
  cpu.DAT =  cpu.X;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stx_aby_3;return; // WRITE
}

void m65ce02_device_stx_aby_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stx_zpg --- 
void m65ce02_device_stx_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stx_zpg_1;return; // READ
}

void m65ce02_device_stx_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.DAT =  cpu.X;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stx_zpg_2;return; // WRITE
}

void m65ce02_device_stx_zpg_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stx_zpy --- 
void m65ce02_device_stx_zpy_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stx_zpy_1;return; // READ
}

void m65ce02_device_stx_zpy_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.Y);
  cpu.DAT =  cpu.X;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stx_zpy_2;return; // WRITE
}

void m65ce02_device_stx_zpy_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sty_abx --- 
void m65ce02_device_sty_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sty_abx_1;return; // READ
}

void m65ce02_device_sty_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sty_abx_2;return; // READ
}

void m65ce02_device_sty_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.X;
  cpu.DAT =  cpu.Y;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sty_abx_3;return; // WRITE
}

void m65ce02_device_sty_abx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sty_zpg --- 
void m65ce02_device_sty_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sty_zpg_1;return; // READ
}

void m65ce02_device_sty_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.DAT =  cpu.Y;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sty_zpg_2;return; // WRITE
}

void m65ce02_device_sty_zpg_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op sty_zpx --- 
void m65ce02_device_sty_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_sty_zpx_1;return; // READ
}

void m65ce02_device_sty_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.DAT =  cpu.Y;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_sty_zpx_2;return; // WRITE
}

void m65ce02_device_sty_zpx_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stz_aba --- 
void m65ce02_device_stz_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stz_aba_1;return; // READ
}

void m65ce02_device_stz_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stz_aba_2;return; // READ
}

void m65ce02_device_stz_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stz_aba_3;return; // WRITE
}

void m65ce02_device_stz_aba_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stz_abx --- 
void m65ce02_device_stz_abx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stz_abx_1;return; // READ
}

void m65ce02_device_stz_abx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stz_abx_2;return; // READ
}

void m65ce02_device_stz_abx_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP+cpu.X;
  cpu.DAT =  cpu.A;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stz_abx_3;return; // WRITE
}

void m65ce02_device_stz_abx_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stz_zpg --- 
void m65ce02_device_stz_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stz_zpg_1;return; // READ
}

void m65ce02_device_stz_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|cpu.TMP;
  cpu.DAT =  cpu.Z;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stz_zpg_2;return; // WRITE
}

void m65ce02_device_stz_zpg_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op stz_zpx --- 
void m65ce02_device_stz_zpx_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_stz_zpx_1;return; // READ
}

void m65ce02_device_stz_zpx_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.B|uint8_t(cpu.TMP+cpu.X);
  cpu.DAT =  cpu.Z;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_stz_zpx_2;return; // WRITE
}

void m65ce02_device_stz_zpx_2(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tab_imp --- 
void m65ce02_device_tab_imp_0(m65ce02_device &cpu) {
  cpu.B = cpu.A << 8;
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tax_imp --- 
void m65ce02_device_tax_imp_0(m65ce02_device &cpu) {
  cpu.X = cpu.A;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tay_imp --- 
void m65ce02_device_tay_imp_0(m65ce02_device &cpu) {
  cpu.Y = cpu.A;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op taz_imp --- 
void m65ce02_device_taz_imp_0(m65ce02_device &cpu) {
  cpu.Z = cpu.A;
  cpu.set_nz(cpu.Z);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tba_imp --- 
void m65ce02_device_tba_imp_0(m65ce02_device &cpu) {
  cpu.A = cpu.B >> 8;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op trb_aba --- 
void m65ce02_device_trb_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_trb_aba_1;return; // READ
}

void m65ce02_device_trb_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_trb_aba_2;return; // READ
}

void m65ce02_device_trb_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_trb_aba_3;return; // READ
}

void m65ce02_device_trb_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 &= ~cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_trb_aba_4;return; // WRITE
}

void m65ce02_device_trb_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op trb_zpg --- 
void m65ce02_device_trb_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_trb_zpg_1;return; // READ
}

void m65ce02_device_trb_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_trb_zpg_2;return; // READ
}

void m65ce02_device_trb_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 &= ~cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_trb_zpg_3;return; // WRITE
}

void m65ce02_device_trb_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tsb_aba --- 
void m65ce02_device_tsb_aba_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_tsb_aba_1;return; // READ
}

void m65ce02_device_tsb_aba_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_tsb_aba_2;return; // READ
}

void m65ce02_device_tsb_aba_2(m65ce02_device &cpu) {
  cpu.TMP = cpu.set_h(cpu.TMP, cpu.DAT);
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_tsb_aba_3;return; // READ
}

void m65ce02_device_tsb_aba_3(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 |= cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_tsb_aba_4;return; // WRITE
}

void m65ce02_device_tsb_aba_4(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tsb_zpg --- 
void m65ce02_device_tsb_zpg_0(m65ce02_device &cpu) {
  cpu.ADDR = cpu.PC++;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_tsb_zpg_1;return; // READ
}

void m65ce02_device_tsb_zpg_1(m65ce02_device &cpu) {
  cpu.TMP = cpu.DAT;
  cpu.ADDR = cpu.TMP;
  cpu.RNW = true;
  cpu.NextFn = (void *)&m65ce02_device_tsb_zpg_2;return; // READ
}

void m65ce02_device_tsb_zpg_2(m65ce02_device &cpu) {
  cpu.TMP2 = cpu.DAT;
  if (cpu.A & cpu.TMP2) {
    cpu.P &= ~cpu.F_Z;
  } else {
    cpu.P |= cpu.F_Z;
  }
  cpu.TMP2 |= cpu.A;
  cpu.ADDR = cpu.TMP;
  cpu.DAT =  cpu.TMP2;
  cpu.RNW = false;
  cpu.NextFn = (void *)&m65ce02_device_tsb_zpg_3;return; // WRITE
}

void m65ce02_device_tsb_zpg_3(m65ce02_device &cpu) {
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tsx_imp --- 
void m65ce02_device_tsx_imp_0(m65ce02_device &cpu) {
  cpu.X = cpu.SP;
  cpu.set_nz(cpu.X);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tsy_imp --- 
void m65ce02_device_tsy_imp_0(m65ce02_device &cpu) {
  cpu.Y = cpu.SP >> 8;
  cpu.set_nz(cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op txa_imp --- 
void m65ce02_device_txa_imp_0(m65ce02_device &cpu) {
  cpu.A = cpu.X;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op txs_imp --- 
void m65ce02_device_txs_imp_0(m65ce02_device &cpu) {
  cpu.SP = cpu.set_l(cpu.SP, cpu.X);
  m6502_device_fetch_noirq(cpu);return; // fetch_noirq
}

// --- op tya_imp --- 
void m65ce02_device_tya_imp_0(m65ce02_device &cpu) {
  cpu.A = cpu.Y;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tys_imp --- 
void m65ce02_device_tys_imp_0(m65ce02_device &cpu) {
  cpu.SP = cpu.set_h(cpu.SP, cpu.Y);
  m6502_device_fetch(cpu);return; // fetch
}

// --- op tza_imp --- 
void m65ce02_device_tza_imp_0(m65ce02_device &cpu) {
  cpu.A = cpu.Z;
  cpu.set_nz(cpu.A);
  m6502_device_fetch(cpu);return; // fetch
}

void m65ce02_device::postfetch_int() {
  switch(IR) {
  case 0x00: m65ce02_device_brk_imp_0(*this); break;
  case 0x01: m65ce02_device_ora_idx_0(*this); break;
  case 0x02: m65ce02_device_cle_imp_0(*this); break;
  case 0x03: m65ce02_device_see_imp_0(*this); break;
  case 0x04: m65ce02_device_tsb_zpg_0(*this); break;
  case 0x05: m65ce02_device_ora_zpg_0(*this); break;
  case 0x06: m65ce02_device_asl_zpg_0(*this); break;
  case 0x07: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x08: m65ce02_device_php_imp_0(*this); break;
  case 0x09: m6502_device_ora_imm_0(*this); break;
  case 0x0a: m65ce02_device_asl_acc_0(*this); break;
  case 0x0b: m65ce02_device_tsy_imp_0(*this); break;
  case 0x0c: m65ce02_device_tsb_aba_0(*this); break;
  case 0x0d: m6502_device_ora_aba_0(*this); break;
  case 0x0e: m65ce02_device_asl_aba_0(*this); break;
  case 0x0f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x10: m65ce02_device_bpl_rel_0(*this); break;
  case 0x11: m65ce02_device_ora_idy_0(*this); break;
  case 0x12: m65ce02_device_ora_idz_0(*this); break;
  case 0x13: m65ce02_device_bpl_rw2_0(*this); break;
  case 0x14: m65ce02_device_trb_zpg_0(*this); break;
  case 0x15: m65ce02_device_ora_zpx_0(*this); break;
  case 0x16: m65ce02_device_asl_zpx_0(*this); break;
  case 0x17: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x18: m65ce02_device_clc_imp_0(*this); break;
  case 0x19: m65ce02_device_ora_aby_0(*this); break;
  case 0x1a: m65ce02_device_inc_acc_0(*this); break;
  case 0x1b: m65ce02_device_inz_imp_0(*this); break;
  case 0x1c: m65ce02_device_trb_aba_0(*this); break;
  case 0x1d: m65ce02_device_ora_abx_0(*this); break;
  case 0x1e: m65ce02_device_asl_abx_0(*this); break;
  case 0x1f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x20: m65ce02_device_jsr_adr_0(*this); break;
  case 0x21: m65ce02_device_and_idx_0(*this); break;
  case 0x22: m65ce02_device_jsr_ind_0(*this); break;
  case 0x23: m65ce02_device_jsr_iax_0(*this); break;
  case 0x24: m65ce02_device_bit_zpg_0(*this); break;
  case 0x25: m65ce02_device_and_zpg_0(*this); break;
  case 0x26: m65ce02_device_rol_zpg_0(*this); break;
  case 0x27: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x28: m65ce02_device_plp_imp_0(*this); break;
  case 0x29: m6502_device_and_imm_0(*this); break;
  case 0x2a: m65ce02_device_rol_acc_0(*this); break;
  case 0x2b: m65ce02_device_tys_imp_0(*this); break;
  case 0x2c: m6502_device_bit_aba_0(*this); break;
  case 0x2d: m6502_device_and_aba_0(*this); break;
  case 0x2e: m65ce02_device_rol_aba_0(*this); break;
  case 0x2f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x30: m65ce02_device_bmi_rel_0(*this); break;
  case 0x31: m65ce02_device_and_idy_0(*this); break;
  case 0x32: m65ce02_device_and_idz_0(*this); break;
  case 0x33: m65ce02_device_bmi_rw2_0(*this); break;
  case 0x34: m65ce02_device_bit_zpx_0(*this); break;
  case 0x35: m65ce02_device_and_zpx_0(*this); break;
  case 0x36: m65ce02_device_rol_zpx_0(*this); break;
  case 0x37: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x38: m65ce02_device_sec_imp_0(*this); break;
  case 0x39: m65ce02_device_and_aby_0(*this); break;
  case 0x3a: m65ce02_device_dec_acc_0(*this); break;
  case 0x3b: m65ce02_device_dez_imp_0(*this); break;
  case 0x3c: m65ce02_device_bit_abx_0(*this); break;
  case 0x3d: m65ce02_device_and_abx_0(*this); break;
  case 0x3e: m65ce02_device_rol_abx_0(*this); break;
  case 0x3f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x40: m65ce02_device_rti_imp_0(*this); break;
  case 0x41: m65ce02_device_eor_idx_0(*this); break;
  case 0x42: m65ce02_device_neg_acc_0(*this); break;
  case 0x43: m65ce02_device_asr_acc_0(*this); break;
  case 0x44: m65ce02_device_asr_zpg_0(*this); break;
  case 0x45: m65ce02_device_eor_zpg_0(*this); break;
  case 0x46: m65ce02_device_lsr_zpg_0(*this); break;
  case 0x47: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x48: m65ce02_device_pha_imp_0(*this); break;
  case 0x49: m6502_device_eor_imm_0(*this); break;
  case 0x4a: m65ce02_device_lsr_acc_0(*this); break;
  case 0x4b: m65ce02_device_taz_imp_0(*this); break;
  case 0x4c: m6502_device_jmp_adr_0(*this); break;
  case 0x4d: m6502_device_eor_aba_0(*this); break;
  case 0x4e: m65ce02_device_lsr_aba_0(*this); break;
  case 0x4f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x50: m65ce02_device_bvc_rel_0(*this); break;
  case 0x51: m65ce02_device_eor_idy_0(*this); break;
  case 0x52: m65ce02_device_eor_idz_0(*this); break;
  case 0x53: m65ce02_device_bvc_rw2_0(*this); break;
  case 0x54: m65ce02_device_asr_zpx_0(*this); break;
  case 0x55: m65ce02_device_eor_zpx_0(*this); break;
  case 0x56: m65ce02_device_lsr_zpx_0(*this); break;
  case 0x57: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x58: m65ce02_device_cli_imp_0(*this); break;
  case 0x59: m65ce02_device_eor_aby_0(*this); break;
  case 0x5a: m65ce02_device_phy_imp_0(*this); break;
  case 0x5b: m65ce02_device_tab_imp_0(*this); break;
  case 0x5c: m65ce02_device_aug_iw3_0(*this); break;
  case 0x5d: m65ce02_device_eor_abx_0(*this); break;
  case 0x5e: m65ce02_device_lsr_abx_0(*this); break;
  case 0x5f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x60: m65ce02_device_rts_imp_0(*this); break;
  case 0x61: m65ce02_device_adc_idx_0(*this); break;
  case 0x62: m65ce02_device_rtn_imm_0(*this); break;
  case 0x63: m65ce02_device_bsr_rw2_0(*this); break;
  case 0x64: m65ce02_device_stz_zpg_0(*this); break;
  case 0x65: m65ce02_device_adc_zpg_0(*this); break;
  case 0x66: m65ce02_device_ror_zpg_0(*this); break;
  case 0x67: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x68: m65ce02_device_pla_imp_0(*this); break;
  case 0x69: m65ce02_device_adc_imm_0(*this); break;
  case 0x6a: m65ce02_device_ror_acc_0(*this); break;
  case 0x6b: m65ce02_device_tza_imp_0(*this); break;
  case 0x6c: m65ce02_device_jmp_ind_0(*this); break;
  case 0x6d: m65ce02_device_adc_aba_0(*this); break;
  case 0x6e: m65ce02_device_ror_aba_0(*this); break;
  case 0x6f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x70: m65ce02_device_bvs_rel_0(*this); break;
  case 0x71: m65ce02_device_adc_idy_0(*this); break;
  case 0x72: m65ce02_device_adc_idz_0(*this); break;
  case 0x73: m65ce02_device_bvs_rw2_0(*this); break;
  case 0x74: m65ce02_device_stz_zpx_0(*this); break;
  case 0x75: m65ce02_device_adc_zpx_0(*this); break;
  case 0x76: m65ce02_device_ror_zpx_0(*this); break;
  case 0x77: m65ce02_device_rmb_bzp_0(*this); break;
  case 0x78: m65ce02_device_sei_imp_0(*this); break;
  case 0x79: m65ce02_device_adc_aby_0(*this); break;
  case 0x7a: m65ce02_device_ply_imp_0(*this); break;
  case 0x7b: m65ce02_device_tba_imp_0(*this); break;
  case 0x7c: m65ce02_device_jmp_iax_0(*this); break;
  case 0x7d: m65ce02_device_adc_abx_0(*this); break;
  case 0x7e: m65ce02_device_ror_abx_0(*this); break;
  case 0x7f: m65ce02_device_bbr_zpb_0(*this); break;
  case 0x80: m65ce02_device_bra_rel_0(*this); break;
  case 0x81: m65ce02_device_sta_idx_0(*this); break;
  case 0x82: m65ce02_device_sta_isy_0(*this); break;
  case 0x83: m65ce02_device_bra_rw2_0(*this); break;
  case 0x84: m65ce02_device_sty_zpg_0(*this); break;
  case 0x85: m65ce02_device_sta_zpg_0(*this); break;
  case 0x86: m65ce02_device_stx_zpg_0(*this); break;
  case 0x87: m65ce02_device_smb_bzp_0(*this); break;
  case 0x88: m65ce02_device_dey_imp_0(*this); break;
  case 0x89: m65ce02_device_bit_imm_0(*this); break;
  case 0x8a: m65ce02_device_txa_imp_0(*this); break;
  case 0x8b: m65ce02_device_sty_abx_0(*this); break;
  case 0x8c: m6502_device_sty_aba_0(*this); break;
  case 0x8d: m6502_device_sta_aba_0(*this); break;
  case 0x8e: m6502_device_stx_aba_0(*this); break;
  case 0x8f: m65ce02_device_bbs_zpb_0(*this); break;
  case 0x90: m65ce02_device_bcc_rel_0(*this); break;
  case 0x91: m65ce02_device_sta_idy_0(*this); break;
  case 0x92: m65ce02_device_sta_idz_0(*this); break;
  case 0x93: m65ce02_device_bcc_rw2_0(*this); break;
  case 0x94: m65ce02_device_sty_zpx_0(*this); break;
  case 0x95: m65ce02_device_sta_zpx_0(*this); break;
  case 0x96: m65ce02_device_stx_zpy_0(*this); break;
  case 0x97: m65ce02_device_smb_bzp_0(*this); break;
  case 0x98: m65ce02_device_tya_imp_0(*this); break;
  case 0x99: m65ce02_device_sta_aby_0(*this); break;
  case 0x9a: m65ce02_device_txs_imp_0(*this); break;
  case 0x9b: m65ce02_device_stx_aby_0(*this); break;
  case 0x9c: m65ce02_device_stz_aba_0(*this); break;
  case 0x9d: m65ce02_device_sta_abx_0(*this); break;
  case 0x9e: m65ce02_device_stz_abx_0(*this); break;
  case 0x9f: m65ce02_device_bbs_zpb_0(*this); break;
  case 0xa0: m6502_device_ldy_imm_0(*this); break;
  case 0xa1: m65ce02_device_lda_idx_0(*this); break;
  case 0xa2: m6502_device_ldx_imm_0(*this); break;
  case 0xa3: m65ce02_device_ldz_imm_0(*this); break;
  case 0xa4: m65ce02_device_ldy_zpg_0(*this); break;
  case 0xa5: m65ce02_device_lda_zpg_0(*this); break;
  case 0xa6: m65ce02_device_ldx_zpg_0(*this); break;
  case 0xa7: m65ce02_device_smb_bzp_0(*this); break;
  case 0xa8: m65ce02_device_tay_imp_0(*this); break;
  case 0xa9: m6502_device_lda_imm_0(*this); break;
  case 0xaa: m65ce02_device_tax_imp_0(*this); break;
  case 0xab: m65ce02_device_ldz_aba_0(*this); break;
  case 0xac: m6502_device_ldy_aba_0(*this); break;
  case 0xad: m6502_device_lda_aba_0(*this); break;
  case 0xae: m6502_device_ldx_aba_0(*this); break;
  case 0xaf: m65ce02_device_bbs_zpb_0(*this); break;
  case 0xb0: m65ce02_device_bcs_rel_0(*this); break;
  case 0xb1: m65ce02_device_lda_idy_0(*this); break;
  case 0xb2: m65ce02_device_lda_idz_0(*this); break;
  case 0xb3: m65ce02_device_bcs_rw2_0(*this); break;
  case 0xb4: m65ce02_device_ldy_zpx_0(*this); break;
  case 0xb5: m65ce02_device_lda_zpx_0(*this); break;
  case 0xb6: m65ce02_device_ldx_zpy_0(*this); break;
  case 0xb7: m65ce02_device_smb_bzp_0(*this); break;
  case 0xb8: m65ce02_device_clv_imp_0(*this); break;
  case 0xb9: m65ce02_device_lda_aby_0(*this); break;
  case 0xba: m65ce02_device_tsx_imp_0(*this); break;
  case 0xbb: m65ce02_device_ldz_abx_0(*this); break;
  case 0xbc: m65ce02_device_ldy_abx_0(*this); break;
  case 0xbd: m65ce02_device_lda_abx_0(*this); break;
  case 0xbe: m65ce02_device_ldx_aby_0(*this); break;
  case 0xbf: m65ce02_device_bbs_zpb_0(*this); break;
  case 0xc0: m6502_device_cpy_imm_0(*this); break;
  case 0xc1: m65ce02_device_cmp_idx_0(*this); break;
  case 0xc2: m65ce02_device_cpz_imm_0(*this); break;
  case 0xc3: m65ce02_device_dew_zpg_0(*this); break;
  case 0xc4: m65ce02_device_cpy_zpg_0(*this); break;
  case 0xc5: m65ce02_device_cmp_zpg_0(*this); break;
  case 0xc6: m65ce02_device_dec_zpg_0(*this); break;
  case 0xc7: m65ce02_device_smb_bzp_0(*this); break;
  case 0xc8: m65ce02_device_iny_imp_0(*this); break;
  case 0xc9: m6502_device_cmp_imm_0(*this); break;
  case 0xca: m65ce02_device_dex_imp_0(*this); break;
  case 0xcb: m65ce02_device_asw_aba_0(*this); break;
  case 0xcc: m6502_device_cpy_aba_0(*this); break;
  case 0xcd: m6502_device_cmp_aba_0(*this); break;
  case 0xce: m65ce02_device_dec_aba_0(*this); break;
  case 0xcf: m65ce02_device_bbs_zpb_0(*this); break;
  case 0xd0: m65ce02_device_bne_rel_0(*this); break;
  case 0xd1: m65ce02_device_cmp_idy_0(*this); break;
  case 0xd2: m65ce02_device_cmp_idz_0(*this); break;
  case 0xd3: m65ce02_device_bne_rw2_0(*this); break;
  case 0xd4: m65ce02_device_cpz_zpg_0(*this); break;
  case 0xd5: m65ce02_device_cmp_zpx_0(*this); break;
  case 0xd6: m65ce02_device_dec_zpx_0(*this); break;
  case 0xd7: m65ce02_device_smb_bzp_0(*this); break;
  case 0xd8: m65ce02_device_cld_imp_0(*this); break;
  case 0xd9: m65ce02_device_cmp_aby_0(*this); break;
  case 0xda: m65ce02_device_phx_imp_0(*this); break;
  case 0xdb: m65ce02_device_phz_imp_0(*this); break;
  case 0xdc: m65ce02_device_cpz_aba_0(*this); break;
  case 0xdd: m65ce02_device_cmp_abx_0(*this); break;
  case 0xde: m65ce02_device_dec_abx_0(*this); break;
  case 0xdf: m65ce02_device_bbs_zpb_0(*this); break;
  case 0xe0: m6502_device_cpx_imm_0(*this); break;
  case 0xe1: m65ce02_device_sbc_idx_0(*this); break;
  case 0xe2: m65ce02_device_lda_isy_0(*this); break;
  case 0xe3: m65ce02_device_inw_zpg_0(*this); break;
  case 0xe4: m65ce02_device_cpx_zpg_0(*this); break;
  case 0xe5: m65ce02_device_sbc_zpg_0(*this); break;
  case 0xe6: m65ce02_device_inc_zpg_0(*this); break;
  case 0xe7: m65ce02_device_smb_bzp_0(*this); break;
  case 0xe8: m65ce02_device_inx_imp_0(*this); break;
  case 0xe9: m65ce02_device_sbc_imm_0(*this); break;
  case 0xea: m65c02_device_nop_imp_0(*this); break;
  case 0xeb: m65ce02_device_row_aba_0(*this); break;
  case 0xec: m6502_device_cpx_aba_0(*this); break;
  case 0xed: m65ce02_device_sbc_aba_0(*this); break;
  case 0xee: m65ce02_device_inc_aba_0(*this); break;
  case 0xef: m65ce02_device_bbs_zpb_0(*this); break;
  case 0xf0: m65ce02_device_beq_rel_0(*this); break;
  case 0xf1: m65ce02_device_sbc_idy_0(*this); break;
  case 0xf2: m65ce02_device_sbc_idz_0(*this); break;
  case 0xf3: m65ce02_device_beq_rw2_0(*this); break;
  case 0xf4: m65ce02_device_phw_iw2_0(*this); break;
  case 0xf5: m65ce02_device_sbc_zpx_0(*this); break;
  case 0xf6: m65ce02_device_inc_zpx_0(*this); break;
  case 0xf7: m65ce02_device_smb_bzp_0(*this); break;
  case 0xf8: m65ce02_device_sed_imp_0(*this); break;
  case 0xf9: m65ce02_device_sbc_aby_0(*this); break;
  case 0xfa: m65ce02_device_plx_imp_0(*this); break;
  case 0xfb: m65ce02_device_plz_imp_0(*this); break;
  case 0xfc: m65ce02_device_phw_aba_0(*this); break;
  case 0xfd: m65ce02_device_sbc_abx_0(*this); break;
  case 0xfe: m65ce02_device_inc_abx_0(*this); break;
  case 0xff: m65ce02_device_bbs_zpb_0(*this); break;
  default:   m65c02_device_reset_0(*this); break;
  }
}

