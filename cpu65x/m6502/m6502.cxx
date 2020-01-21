// This file has been automatically produced by makehxx.pl
// do not edit it.
// from file(s) dm6502.lst D:\Users\Dominic\Documents\GitHub\beebem-windows\cpu65x\m6502\om6502.lst
#include "m6502.h"
// --- op adc_aba --- 
void m6502_device::adc_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_aba_1;return; // READ
}

void m6502_device::adc_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_aba_2;return; // READ
}

void m6502_device::adc_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::adc_aba_3;return; // READ
}

void m6502_device::adc_aba_3() {
  TMP = DAT;
  do_adc(TMP);
  fetch();return; // fetch
}

// --- op adc_abx --- 
void m6502_device::adc_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_abx_1;return; // READ
}

void m6502_device::adc_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_abx_2;return; // READ
}

void m6502_device::adc_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::adc_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::adc_abx_4;return; // READ
}

void m6502_device::adc_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::adc_abx_4;return; // READ
}

void m6502_device::adc_abx_4() {
  TMP = DAT;
  do_adc(TMP);
  fetch();return; // fetch
}

// --- op adc_aby --- 
void m6502_device::adc_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_aby_1;return; // READ
}

void m6502_device::adc_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_aby_2;return; // READ
}

void m6502_device::adc_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::adc_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::adc_aby_4;return; // READ
}

void m6502_device::adc_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::adc_aby_4;return; // READ
}

void m6502_device::adc_aby_4() {
  TMP = DAT;
  do_adc(TMP);
  fetch();return; // fetch
}

// --- op adc_idx --- 
void m6502_device::adc_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_idx_1;return; // READ
}

void m6502_device::adc_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::adc_idx_2;return; // READ
}

void m6502_device::adc_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::adc_idx_3;return; // READ
}

void m6502_device::adc_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::adc_idx_4;return; // READ
}

void m6502_device::adc_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::adc_idx_5;return; // READ
}

void m6502_device::adc_idx_5() {
  do_adc(DAT);
  fetch();return; // fetch
}

// --- op adc_idy --- 
void m6502_device::adc_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_idy_1;return; // READ
}

void m6502_device::adc_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::adc_idy_2;return; // READ
}

void m6502_device::adc_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::adc_idy_3;return; // READ
}

void m6502_device::adc_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::adc_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::adc_idy_5;return; // READ
}

void m6502_device::adc_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::adc_idy_5;return; // READ
}

void m6502_device::adc_idy_5() {
  do_adc(DAT);
  fetch();return; // fetch
}

// --- op adc_imm --- 
void m6502_device::adc_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_imm_1;return; // READ
}

void m6502_device::adc_imm_1() {
  TMP = DAT;
  do_adc(TMP);
  fetch();return; // fetch
}

// --- op adc_zpg --- 
void m6502_device::adc_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_zpg_1;return; // READ
}

void m6502_device::adc_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::adc_zpg_2;return; // READ
}

void m6502_device::adc_zpg_2() {
  TMP = DAT;
  do_adc(TMP);
  fetch();return; // fetch
}

// --- op adc_zpx --- 
void m6502_device::adc_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::adc_zpx_1;return; // READ
}

void m6502_device::adc_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::adc_zpx_2;return; // READ
}

void m6502_device::adc_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::adc_zpx_3;return; // READ
}

void m6502_device::adc_zpx_3() {
  TMP = DAT;
  do_adc(TMP);
  fetch();return; // fetch
}

// --- op anc_imm --- 
void m6502_device::anc_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::anc_imm_1;return; // READ
}

void m6502_device::anc_imm_1() {
  A &= DAT;
  set_nz(A);
  if (A & 0x80) {
    P |= F_C;
  } else {
    P &= ~F_C;
  }
  fetch();return; // fetch
}

// --- op and_aba --- 
void m6502_device::and_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_aba_1;return; // READ
}

void m6502_device::and_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_aba_2;return; // READ
}

void m6502_device::and_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::and_aba_3;return; // READ
}

void m6502_device::and_aba_3() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_abx --- 
void m6502_device::and_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_abx_1;return; // READ
}

void m6502_device::and_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_abx_2;return; // READ
}

void m6502_device::and_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::and_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::and_abx_4;return; // READ
}

void m6502_device::and_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::and_abx_4;return; // READ
}

void m6502_device::and_abx_4() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_aby --- 
void m6502_device::and_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_aby_1;return; // READ
}

void m6502_device::and_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_aby_2;return; // READ
}

void m6502_device::and_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::and_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::and_aby_4;return; // READ
}

void m6502_device::and_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::and_aby_4;return; // READ
}

void m6502_device::and_aby_4() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_idx --- 
void m6502_device::and_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_idx_1;return; // READ
}

void m6502_device::and_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::and_idx_2;return; // READ
}

void m6502_device::and_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::and_idx_3;return; // READ
}

void m6502_device::and_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::and_idx_4;return; // READ
}

void m6502_device::and_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::and_idx_5;return; // READ
}

void m6502_device::and_idx_5() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_idy --- 
void m6502_device::and_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_idy_1;return; // READ
}

void m6502_device::and_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::and_idy_2;return; // READ
}

void m6502_device::and_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::and_idy_3;return; // READ
}

void m6502_device::and_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::and_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::and_idy_5;return; // READ
}

void m6502_device::and_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::and_idy_5;return; // READ
}

void m6502_device::and_idy_5() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_imm --- 
void m6502_device::and_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_imm_1;return; // READ
}

void m6502_device::and_imm_1() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_zpg --- 
void m6502_device::and_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_zpg_1;return; // READ
}

void m6502_device::and_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::and_zpg_2;return; // READ
}

void m6502_device::and_zpg_2() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_zpx --- 
void m6502_device::and_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::and_zpx_1;return; // READ
}

void m6502_device::and_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::and_zpx_2;return; // READ
}

void m6502_device::and_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::and_zpx_3;return; // READ
}

void m6502_device::and_zpx_3() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ane_imm --- 
void m6502_device::ane_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ane_imm_1;return; // READ
}

void m6502_device::ane_imm_1() {
  TMP2 = DAT;
  A &= TMP2 & X;
  set_nz(A);
  fetch();return; // fetch
}

// --- op arr_imm --- 
void m6502_device::arr_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::arr_imm_1;return; // READ
}

void m6502_device::arr_imm_1() {
  A &= DAT;
  do_arr();
  fetch();return; // fetch
}

// --- op asl_aba --- 
void m6502_device::asl_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asl_aba_1;return; // READ
}

void m6502_device::asl_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asl_aba_2;return; // READ
}

void m6502_device::asl_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::asl_aba_3;return; // READ
}

void m6502_device::asl_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_aba_4;return; // WRITE
}

void m6502_device::asl_aba_4() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_aba_5;return; // WRITE
}

void m6502_device::asl_aba_5() {
  fetch();return; // fetch
}

// --- op asl_abx --- 
void m6502_device::asl_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asl_abx_1;return; // READ
}

void m6502_device::asl_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asl_abx_2;return; // READ
}

void m6502_device::asl_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::asl_abx_3;return; // READ
}

void m6502_device::asl_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::asl_abx_4;return; // READ
}

void m6502_device::asl_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_abx_5;return; // WRITE
}

void m6502_device::asl_abx_5() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_abx_6;return; // WRITE
}

void m6502_device::asl_abx_6() {
  fetch();return; // fetch
}

// --- op asl_acc --- 
void m6502_device::asl_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::asl_acc_1;return; // READ
}

void m6502_device::asl_acc_1() {
  A = do_asl(A);
  fetch();return; // fetch
}

// --- op asl_zpg --- 
void m6502_device::asl_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asl_zpg_1;return; // READ
}

void m6502_device::asl_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::asl_zpg_2;return; // READ
}

void m6502_device::asl_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_zpg_3;return; // WRITE
}

void m6502_device::asl_zpg_3() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_zpg_4;return; // WRITE
}

void m6502_device::asl_zpg_4() {
  fetch();return; // fetch
}

// --- op asl_zpx --- 
void m6502_device::asl_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asl_zpx_1;return; // READ
}

void m6502_device::asl_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::asl_zpx_2;return; // READ
}

void m6502_device::asl_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::asl_zpx_3;return; // READ
}

void m6502_device::asl_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_zpx_4;return; // WRITE
}

void m6502_device::asl_zpx_4() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::asl_zpx_5;return; // WRITE
}

void m6502_device::asl_zpx_5() {
  fetch();return; // fetch
}

// --- op asr_imm --- 
void m6502_device::asr_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::asr_imm_1;return; // READ
}

void m6502_device::asr_imm_1() {
  A &= DAT;
  A = do_lsr(A);
  fetch();return; // fetch
}

// --- op bcc_rel --- 
void m6502_device::bcc_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bcc_rel_1;return; // READ
}

void m6502_device::bcc_rel_1() {
  TMP = DAT;
  if (!(P & F_C)) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bcc_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bcc_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bcc_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bcc_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bcs_rel --- 
void m6502_device::bcs_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bcs_rel_1;return; // READ
}

void m6502_device::bcs_rel_1() {
  TMP = DAT;
  if (P & F_C) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bcs_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bcs_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bcs_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bcs_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op beq_rel --- 
void m6502_device::beq_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::beq_rel_1;return; // READ
}

void m6502_device::beq_rel_1() {
  TMP = DAT;
  if (P & F_Z) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::beq_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::beq_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::beq_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::beq_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bit_aba --- 
void m6502_device::bit_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bit_aba_1;return; // READ
}

void m6502_device::bit_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bit_aba_2;return; // READ
}

void m6502_device::bit_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::bit_aba_3;return; // READ
}

void m6502_device::bit_aba_3() {
  do_bit(DAT);
  fetch();return; // fetch
}

// --- op bit_zpg --- 
void m6502_device::bit_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bit_zpg_1;return; // READ
}

void m6502_device::bit_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::bit_zpg_2;return; // READ
}

void m6502_device::bit_zpg_2() {
  do_bit(DAT);
  fetch();return; // fetch
}

// --- op bmi_rel --- 
void m6502_device::bmi_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bmi_rel_1;return; // READ
}

void m6502_device::bmi_rel_1() {
  TMP = DAT;
  if (P & F_N) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bmi_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bmi_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bmi_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bmi_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bne_rel --- 
void m6502_device::bne_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bne_rel_1;return; // READ
}

void m6502_device::bne_rel_1() {
  TMP = DAT;
  if (!(P & F_Z)) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bne_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bne_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bne_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bne_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bpl_rel --- 
void m6502_device::bpl_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bpl_rel_1;return; // READ
}

void m6502_device::bpl_rel_1() {
  TMP = DAT;
  if (!(P & F_N)) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bpl_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bpl_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bpl_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bpl_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op brk_imp --- 
void m6502_device::brk_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::brk_imp_1;return; // READ
}

void m6502_device::brk_imp_1() {
  if (!irq_taken) {
    PC++;
  }
  ADDR = SP;
  DAT =  PC >> 8;
  RNW = false;
  NextFn = &m6502_device::brk_imp_2;return; // WRITE
}

void m6502_device::brk_imp_2() {
  dec_SP();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m6502_device::brk_imp_3;return; // WRITE
}

void m6502_device::brk_imp_3() {
  dec_SP();
  ADDR = SP;
  DAT =  irq_taken ? P & ~F_B : P;
  RNW = false;
  NextFn = &m6502_device::brk_imp_4;return; // WRITE
}

void m6502_device::brk_imp_4() {
  dec_SP();
  if (nmi_state) {
    ADDR = 0xfffa;
    RNW = true;
    NextFn = &m6502_device::brk_imp_5;return; // READ
  } else {
    ADDR = 0xfffe;
    RNW = true;
    NextFn = &m6502_device::brk_imp_7;return; // READ
  }
  irq_taken = false;
  P |= F_I;
  fetch();return; // fetch
}

void m6502_device::brk_imp_5() {
    PC = DAT;
    ADDR = 0xfffb;
    RNW = true;
    NextFn = &m6502_device::brk_imp_6;return; // READ
}

void m6502_device::brk_imp_7() {
    PC = DAT;
    ADDR = 0xffff;
    RNW = true;
    NextFn = &m6502_device::brk_imp_8;return; // READ
}

void m6502_device::brk_imp_6() {
    PC = set_h(PC, DAT);
    nmi_state = false;
    standard_irq_callback(NMI_LINE);
    irq_taken = false;
    P |= F_I;
    fetch();return; // fetch
}

void m6502_device::brk_imp_8() {
    PC = set_h(PC, DAT);
    if (irq_taken) {
      standard_irq_callback(IRQ_LINE);
    }
    irq_taken = false;
    P |= F_I;
    fetch();return; // fetch
}

// --- op bvc_rel --- 
void m6502_device::bvc_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bvc_rel_1;return; // READ
}

void m6502_device::bvc_rel_1() {
  TMP = DAT;
  if (!(P & F_V)) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bvc_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bvc_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bvc_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bvc_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bvs_rel --- 
void m6502_device::bvs_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::bvs_rel_1;return; // READ
}

void m6502_device::bvs_rel_1() {
  TMP = DAT;
  if (P & F_V) {
    ADDR = PC;
    RNW = true;
    NextFn = &m6502_device::bvs_rel_2;return; // READ
  }
  fetch();return; // fetch
}

void m6502_device::bvs_rel_2() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m6502_device::bvs_rel_3;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m6502_device::bvs_rel_3() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op clc_imp --- 
void m6502_device::clc_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::clc_imp_1;return; // READ
}

void m6502_device::clc_imp_1() {
  P &= ~F_C;
  fetch();return; // fetch
}

// --- op cld_imp --- 
void m6502_device::cld_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::cld_imp_1;return; // READ
}

void m6502_device::cld_imp_1() {
  P &= ~F_D;
  fetch();return; // fetch
}

// --- op cli_imp --- 
void m6502_device::cli_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::cli_imp_1;return; // READ
}

void m6502_device::cli_imp_1() {
  PrefetchNextFn = &m6502_device::cli_imp_2;
  prefetch();return; // prefetch
}

void m6502_device::cli_imp_2() {
  P &= ~F_I;
  postfetch();return; // postfetch
}

// --- op clv_imp --- 
void m6502_device::clv_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::clv_imp_1;return; // READ
}

void m6502_device::clv_imp_1() {
  P &= ~F_V;
  fetch();return; // fetch
}

// --- op cmp_aba --- 
void m6502_device::cmp_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_aba_1;return; // READ
}

void m6502_device::cmp_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_aba_2;return; // READ
}

void m6502_device::cmp_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cmp_aba_3;return; // READ
}

void m6502_device::cmp_aba_3() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_abx --- 
void m6502_device::cmp_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_abx_1;return; // READ
}

void m6502_device::cmp_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_abx_2;return; // READ
}

void m6502_device::cmp_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::cmp_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cmp_abx_4;return; // READ
}

void m6502_device::cmp_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::cmp_abx_4;return; // READ
}

void m6502_device::cmp_abx_4() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_aby --- 
void m6502_device::cmp_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_aby_1;return; // READ
}

void m6502_device::cmp_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_aby_2;return; // READ
}

void m6502_device::cmp_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::cmp_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cmp_aby_4;return; // READ
}

void m6502_device::cmp_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::cmp_aby_4;return; // READ
}

void m6502_device::cmp_aby_4() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_idx --- 
void m6502_device::cmp_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_idx_1;return; // READ
}

void m6502_device::cmp_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::cmp_idx_2;return; // READ
}

void m6502_device::cmp_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::cmp_idx_3;return; // READ
}

void m6502_device::cmp_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::cmp_idx_4;return; // READ
}

void m6502_device::cmp_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cmp_idx_5;return; // READ
}

void m6502_device::cmp_idx_5() {
  do_cmp(A, DAT);
  fetch();return; // fetch
}

// --- op cmp_idy --- 
void m6502_device::cmp_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_idy_1;return; // READ
}

void m6502_device::cmp_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::cmp_idy_2;return; // READ
}

void m6502_device::cmp_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::cmp_idy_3;return; // READ
}

void m6502_device::cmp_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::cmp_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::cmp_idy_5;return; // READ
}

void m6502_device::cmp_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::cmp_idy_5;return; // READ
}

void m6502_device::cmp_idy_5() {
  do_cmp(A, DAT);
  fetch();return; // fetch
}

// --- op cmp_imm --- 
void m6502_device::cmp_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_imm_1;return; // READ
}

void m6502_device::cmp_imm_1() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_zpg --- 
void m6502_device::cmp_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_zpg_1;return; // READ
}

void m6502_device::cmp_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cmp_zpg_2;return; // READ
}

void m6502_device::cmp_zpg_2() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_zpx --- 
void m6502_device::cmp_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cmp_zpx_1;return; // READ
}

void m6502_device::cmp_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cmp_zpx_2;return; // READ
}

void m6502_device::cmp_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::cmp_zpx_3;return; // READ
}

void m6502_device::cmp_zpx_3() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cpx_aba --- 
void m6502_device::cpx_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpx_aba_1;return; // READ
}

void m6502_device::cpx_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpx_aba_2;return; // READ
}

void m6502_device::cpx_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cpx_aba_3;return; // READ
}

void m6502_device::cpx_aba_3() {
  TMP = DAT;
  do_cmp(X, TMP);
  fetch();return; // fetch
}

// --- op cpx_imm --- 
void m6502_device::cpx_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpx_imm_1;return; // READ
}

void m6502_device::cpx_imm_1() {
  TMP = DAT;
  do_cmp(X, TMP);
  fetch();return; // fetch
}

// --- op cpx_zpg --- 
void m6502_device::cpx_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpx_zpg_1;return; // READ
}

void m6502_device::cpx_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cpx_zpg_2;return; // READ
}

void m6502_device::cpx_zpg_2() {
  TMP = DAT;
  do_cmp(X, TMP);
  fetch();return; // fetch
}

// --- op cpy_aba --- 
void m6502_device::cpy_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpy_aba_1;return; // READ
}

void m6502_device::cpy_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpy_aba_2;return; // READ
}

void m6502_device::cpy_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cpy_aba_3;return; // READ
}

void m6502_device::cpy_aba_3() {
  TMP = DAT;
  do_cmp(Y, TMP);
  fetch();return; // fetch
}

// --- op cpy_imm --- 
void m6502_device::cpy_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpy_imm_1;return; // READ
}

void m6502_device::cpy_imm_1() {
  TMP = DAT;
  do_cmp(Y, TMP);
  fetch();return; // fetch
}

// --- op cpy_zpg --- 
void m6502_device::cpy_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::cpy_zpg_1;return; // READ
}

void m6502_device::cpy_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::cpy_zpg_2;return; // READ
}

void m6502_device::cpy_zpg_2() {
  TMP = DAT;
  do_cmp(Y, TMP);
  fetch();return; // fetch
}

// --- op dcp_aba --- 
void m6502_device::dcp_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_aba_1;return; // READ
}

void m6502_device::dcp_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_aba_2;return; // READ
}

void m6502_device::dcp_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_aba_3;return; // READ
}

void m6502_device::dcp_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_aba_4;return; // WRITE
}

void m6502_device::dcp_aba_4() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_aba_5;return; // WRITE
}

void m6502_device::dcp_aba_5() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dcp_abx --- 
void m6502_device::dcp_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_abx_1;return; // READ
}

void m6502_device::dcp_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_abx_2;return; // READ
}

void m6502_device::dcp_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::dcp_abx_3;return; // READ
}

void m6502_device::dcp_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_abx_4;return; // READ
}

void m6502_device::dcp_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_abx_5;return; // WRITE
}

void m6502_device::dcp_abx_5() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_abx_6;return; // WRITE
}

void m6502_device::dcp_abx_6() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dcp_aby --- 
void m6502_device::dcp_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_aby_1;return; // READ
}

void m6502_device::dcp_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_aby_2;return; // READ
}

void m6502_device::dcp_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::dcp_aby_3;return; // READ
}

void m6502_device::dcp_aby_3() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_aby_4;return; // READ
}

void m6502_device::dcp_aby_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_aby_5;return; // WRITE
}

void m6502_device::dcp_aby_5() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_aby_6;return; // WRITE
}

void m6502_device::dcp_aby_6() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dcp_idx --- 
void m6502_device::dcp_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_idx_1;return; // READ
}

void m6502_device::dcp_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::dcp_idx_2;return; // READ
}

void m6502_device::dcp_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::dcp_idx_3;return; // READ
}

void m6502_device::dcp_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::dcp_idx_4;return; // READ
}

void m6502_device::dcp_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_idx_5;return; // READ
}

void m6502_device::dcp_idx_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_idx_6;return; // WRITE
}

void m6502_device::dcp_idx_6() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_idx_7;return; // WRITE
}

void m6502_device::dcp_idx_7() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dcp_idy --- 
void m6502_device::dcp_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_idy_1;return; // READ
}

void m6502_device::dcp_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::dcp_idy_2;return; // READ
}

void m6502_device::dcp_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::dcp_idy_3;return; // READ
}

void m6502_device::dcp_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::dcp_idy_4;return; // READ
}

void m6502_device::dcp_idy_4() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_idy_5;return; // READ
}

void m6502_device::dcp_idy_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_idy_6;return; // WRITE
}

void m6502_device::dcp_idy_6() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_idy_7;return; // WRITE
}

void m6502_device::dcp_idy_7() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dcp_zpg --- 
void m6502_device::dcp_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_zpg_1;return; // READ
}

void m6502_device::dcp_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_zpg_2;return; // READ
}

void m6502_device::dcp_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_zpg_3;return; // WRITE
}

void m6502_device::dcp_zpg_3() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_zpg_4;return; // WRITE
}

void m6502_device::dcp_zpg_4() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dcp_zpx --- 
void m6502_device::dcp_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dcp_zpx_1;return; // READ
}

void m6502_device::dcp_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_zpx_2;return; // READ
}

void m6502_device::dcp_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dcp_zpx_3;return; // READ
}

void m6502_device::dcp_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_zpx_4;return; // WRITE
}

void m6502_device::dcp_zpx_4() {
  TMP2--;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dcp_zpx_5;return; // WRITE
}

void m6502_device::dcp_zpx_5() {
  do_cmp(A, TMP2);
  fetch();return; // fetch
}

// --- op dec_aba --- 
void m6502_device::dec_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dec_aba_1;return; // READ
}

void m6502_device::dec_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dec_aba_2;return; // READ
}

void m6502_device::dec_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dec_aba_3;return; // READ
}

void m6502_device::dec_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_aba_4;return; // WRITE
}

void m6502_device::dec_aba_4() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_aba_5;return; // WRITE
}

void m6502_device::dec_aba_5() {
  fetch();return; // fetch
}

// --- op dec_abx --- 
void m6502_device::dec_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dec_abx_1;return; // READ
}

void m6502_device::dec_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dec_abx_2;return; // READ
}

void m6502_device::dec_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::dec_abx_3;return; // READ
}

void m6502_device::dec_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dec_abx_4;return; // READ
}

void m6502_device::dec_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_abx_5;return; // WRITE
}

void m6502_device::dec_abx_5() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_abx_6;return; // WRITE
}

void m6502_device::dec_abx_6() {
  fetch();return; // fetch
}

// --- op dec_zpg --- 
void m6502_device::dec_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dec_zpg_1;return; // READ
}

void m6502_device::dec_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dec_zpg_2;return; // READ
}

void m6502_device::dec_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_zpg_3;return; // WRITE
}

void m6502_device::dec_zpg_3() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_zpg_4;return; // WRITE
}

void m6502_device::dec_zpg_4() {
  fetch();return; // fetch
}

// --- op dec_zpx --- 
void m6502_device::dec_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::dec_zpx_1;return; // READ
}

void m6502_device::dec_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dec_zpx_2;return; // READ
}

void m6502_device::dec_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::dec_zpx_3;return; // READ
}

void m6502_device::dec_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_zpx_4;return; // WRITE
}

void m6502_device::dec_zpx_4() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::dec_zpx_5;return; // WRITE
}

void m6502_device::dec_zpx_5() {
  fetch();return; // fetch
}

// --- op dex_imp --- 
void m6502_device::dex_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::dex_imp_1;return; // READ
}

void m6502_device::dex_imp_1() {
  X--;
  set_nz(X);
  fetch();return; // fetch
}

// --- op dey_imp --- 
void m6502_device::dey_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::dey_imp_1;return; // READ
}

void m6502_device::dey_imp_1() {
  Y--;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op eor_aba --- 
void m6502_device::eor_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_aba_1;return; // READ
}

void m6502_device::eor_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_aba_2;return; // READ
}

void m6502_device::eor_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::eor_aba_3;return; // READ
}

void m6502_device::eor_aba_3() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_abx --- 
void m6502_device::eor_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_abx_1;return; // READ
}

void m6502_device::eor_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_abx_2;return; // READ
}

void m6502_device::eor_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::eor_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::eor_abx_4;return; // READ
}

void m6502_device::eor_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::eor_abx_4;return; // READ
}

void m6502_device::eor_abx_4() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_aby --- 
void m6502_device::eor_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_aby_1;return; // READ
}

void m6502_device::eor_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_aby_2;return; // READ
}

void m6502_device::eor_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::eor_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::eor_aby_4;return; // READ
}

void m6502_device::eor_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::eor_aby_4;return; // READ
}

void m6502_device::eor_aby_4() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_idx --- 
void m6502_device::eor_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_idx_1;return; // READ
}

void m6502_device::eor_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::eor_idx_2;return; // READ
}

void m6502_device::eor_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::eor_idx_3;return; // READ
}

void m6502_device::eor_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::eor_idx_4;return; // READ
}

void m6502_device::eor_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::eor_idx_5;return; // READ
}

void m6502_device::eor_idx_5() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_idy --- 
void m6502_device::eor_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_idy_1;return; // READ
}

void m6502_device::eor_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::eor_idy_2;return; // READ
}

void m6502_device::eor_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::eor_idy_3;return; // READ
}

void m6502_device::eor_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::eor_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::eor_idy_5;return; // READ
}

void m6502_device::eor_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::eor_idy_5;return; // READ
}

void m6502_device::eor_idy_5() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_imm --- 
void m6502_device::eor_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_imm_1;return; // READ
}

void m6502_device::eor_imm_1() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_zpg --- 
void m6502_device::eor_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_zpg_1;return; // READ
}

void m6502_device::eor_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::eor_zpg_2;return; // READ
}

void m6502_device::eor_zpg_2() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_zpx --- 
void m6502_device::eor_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::eor_zpx_1;return; // READ
}

void m6502_device::eor_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::eor_zpx_2;return; // READ
}

void m6502_device::eor_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::eor_zpx_3;return; // READ
}

void m6502_device::eor_zpx_3() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op inc_aba --- 
void m6502_device::inc_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::inc_aba_1;return; // READ
}

void m6502_device::inc_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::inc_aba_2;return; // READ
}

void m6502_device::inc_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::inc_aba_3;return; // READ
}

void m6502_device::inc_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_aba_4;return; // WRITE
}

void m6502_device::inc_aba_4() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_aba_5;return; // WRITE
}

void m6502_device::inc_aba_5() {
  fetch();return; // fetch
}

// --- op inc_abx --- 
void m6502_device::inc_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::inc_abx_1;return; // READ
}

void m6502_device::inc_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::inc_abx_2;return; // READ
}

void m6502_device::inc_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::inc_abx_3;return; // READ
}

void m6502_device::inc_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::inc_abx_4;return; // READ
}

void m6502_device::inc_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_abx_5;return; // WRITE
}

void m6502_device::inc_abx_5() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_abx_6;return; // WRITE
}

void m6502_device::inc_abx_6() {
  fetch();return; // fetch
}

// --- op inc_zpg --- 
void m6502_device::inc_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::inc_zpg_1;return; // READ
}

void m6502_device::inc_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::inc_zpg_2;return; // READ
}

void m6502_device::inc_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_zpg_3;return; // WRITE
}

void m6502_device::inc_zpg_3() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_zpg_4;return; // WRITE
}

void m6502_device::inc_zpg_4() {
  fetch();return; // fetch
}

// --- op inc_zpx --- 
void m6502_device::inc_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::inc_zpx_1;return; // READ
}

void m6502_device::inc_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::inc_zpx_2;return; // READ
}

void m6502_device::inc_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::inc_zpx_3;return; // READ
}

void m6502_device::inc_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_zpx_4;return; // WRITE
}

void m6502_device::inc_zpx_4() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::inc_zpx_5;return; // WRITE
}

void m6502_device::inc_zpx_5() {
  fetch();return; // fetch
}

// --- op inx_imp --- 
void m6502_device::inx_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::inx_imp_1;return; // READ
}

void m6502_device::inx_imp_1() {
  X++;
  set_nz(X);
  fetch();return; // fetch
}

// --- op iny_imp --- 
void m6502_device::iny_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::iny_imp_1;return; // READ
}

void m6502_device::iny_imp_1() {
  Y++;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op isb_aba --- 
void m6502_device::isb_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_aba_1;return; // READ
}

void m6502_device::isb_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_aba_2;return; // READ
}

void m6502_device::isb_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_aba_3;return; // READ
}

void m6502_device::isb_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_aba_4;return; // WRITE
}

void m6502_device::isb_aba_4() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_aba_5;return; // WRITE
}

void m6502_device::isb_aba_5() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op isb_abx --- 
void m6502_device::isb_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_abx_1;return; // READ
}

void m6502_device::isb_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_abx_2;return; // READ
}

void m6502_device::isb_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::isb_abx_3;return; // READ
}

void m6502_device::isb_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_abx_4;return; // READ
}

void m6502_device::isb_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_abx_5;return; // WRITE
}

void m6502_device::isb_abx_5() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_abx_6;return; // WRITE
}

void m6502_device::isb_abx_6() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op isb_aby --- 
void m6502_device::isb_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_aby_1;return; // READ
}

void m6502_device::isb_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_aby_2;return; // READ
}

void m6502_device::isb_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::isb_aby_3;return; // READ
}

void m6502_device::isb_aby_3() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_aby_4;return; // READ
}

void m6502_device::isb_aby_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_aby_5;return; // WRITE
}

void m6502_device::isb_aby_5() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_aby_6;return; // WRITE
}

void m6502_device::isb_aby_6() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op isb_idx --- 
void m6502_device::isb_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_idx_1;return; // READ
}

void m6502_device::isb_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::isb_idx_2;return; // READ
}

void m6502_device::isb_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::isb_idx_3;return; // READ
}

void m6502_device::isb_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::isb_idx_4;return; // READ
}

void m6502_device::isb_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_idx_5;return; // READ
}

void m6502_device::isb_idx_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_idx_6;return; // WRITE
}

void m6502_device::isb_idx_6() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_idx_7;return; // WRITE
}

void m6502_device::isb_idx_7() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op isb_idy --- 
void m6502_device::isb_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_idy_1;return; // READ
}

void m6502_device::isb_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::isb_idy_2;return; // READ
}

void m6502_device::isb_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::isb_idy_3;return; // READ
}

void m6502_device::isb_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::isb_idy_4;return; // READ
}

void m6502_device::isb_idy_4() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_idy_5;return; // READ
}

void m6502_device::isb_idy_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_idy_6;return; // WRITE
}

void m6502_device::isb_idy_6() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_idy_7;return; // WRITE
}

void m6502_device::isb_idy_7() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op isb_zpg --- 
void m6502_device::isb_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_zpg_1;return; // READ
}

void m6502_device::isb_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_zpg_2;return; // READ
}

void m6502_device::isb_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_zpg_3;return; // WRITE
}

void m6502_device::isb_zpg_3() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_zpg_4;return; // WRITE
}

void m6502_device::isb_zpg_4() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op isb_zpx --- 
void m6502_device::isb_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::isb_zpx_1;return; // READ
}

void m6502_device::isb_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_zpx_2;return; // READ
}

void m6502_device::isb_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::isb_zpx_3;return; // READ
}

void m6502_device::isb_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_zpx_4;return; // WRITE
}

void m6502_device::isb_zpx_4() {
  TMP2++;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::isb_zpx_5;return; // WRITE
}

void m6502_device::isb_zpx_5() {
  do_sbc(TMP2);
  fetch();return; // fetch
}

// --- op jmp_adr --- 
void m6502_device::jmp_adr_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::jmp_adr_1;return; // READ
}

void m6502_device::jmp_adr_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::jmp_adr_2;return; // READ
}

void m6502_device::jmp_adr_2() {
  TMP = set_h(TMP, DAT);
  PC = TMP;
  fetch();return; // fetch
}

// --- op jmp_ind --- 
void m6502_device::jmp_ind_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::jmp_ind_1;return; // READ
}

void m6502_device::jmp_ind_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::jmp_ind_2;return; // READ
}

void m6502_device::jmp_ind_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::jmp_ind_3;return; // READ
}

void m6502_device::jmp_ind_3() {
  PC = DAT;
  ADDR = set_l(TMP, TMP+1);
  RNW = true;
  NextFn = &m6502_device::jmp_ind_4;return; // READ
}

void m6502_device::jmp_ind_4() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op jsr_adr --- 
void m6502_device::jsr_adr_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::jsr_adr_1;return; // READ
}

void m6502_device::jsr_adr_1() {
  TMP = DAT;
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::jsr_adr_2;return; // READ
}

void m6502_device::jsr_adr_2() {
  ADDR = SP;
  DAT =  PC>>8;
  RNW = false;
  NextFn = &m6502_device::jsr_adr_3;return; // WRITE
}

void m6502_device::jsr_adr_3() {
  dec_SP();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m6502_device::jsr_adr_4;return; // WRITE
}

void m6502_device::jsr_adr_4() {
  dec_SP();
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::jsr_adr_5;return; // READ
}

void m6502_device::jsr_adr_5() {
  TMP = set_h(TMP, DAT);
  PC = TMP;
  fetch();return; // fetch
}

// --- op kil_non --- 
void m6502_device::kil_non_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::kil_non_1;return; // READ
}

void m6502_device::kil_non_1() {
  ADDR = 0xffff;
  RNW = true;
  NextFn = &m6502_device::kil_non_2;return; // READ
}

void m6502_device::kil_non_2() {
  ADDR = 0xfffe;
  RNW = true;
  NextFn = &m6502_device::kil_non_3;return; // READ
}

void m6502_device::kil_non_3() {
  ADDR = 0xfffe;
  RNW = true;
  NextFn = &m6502_device::kil_non_4;return; // READ
}

void m6502_device::kil_non_4() {
  kil_non_while_1();return;
}

void m6502_device::kil_non_while_1() {
  if (!true) m6502_device::kil_non_whilenot_1();return;
  ADDR = 0xffff;
  RNW = true;
  NextFn = &m6502_device::kil_non_5;return; // READ
}

void m6502_device::kil_non_whilenot_1() {
  fetch();return; // fetch
}

void m6502_device::kil_non_5() {
  kil_non_while_1();return;
}

// --- op las_aby --- 
void m6502_device::las_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::las_aby_1;return; // READ
}

void m6502_device::las_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::las_aby_2;return; // READ
}

void m6502_device::las_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::las_aby_3;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::las_aby_4;return; // READ
}

void m6502_device::las_aby_3() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::las_aby_4;return; // READ
}

void m6502_device::las_aby_4() {
  TMP2 = DAT;
  A = TMP2 | 0x51;
  X = 0xff;
  set_nz(TMP2);
  fetch();return; // fetch
}

// --- op lax_aba --- 
void m6502_device::lax_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_aba_1;return; // READ
}

void m6502_device::lax_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_aba_2;return; // READ
}

void m6502_device::lax_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lax_aba_3;return; // READ
}

void m6502_device::lax_aba_3() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lax_aby --- 
void m6502_device::lax_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_aby_1;return; // READ
}

void m6502_device::lax_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_aby_2;return; // READ
}

void m6502_device::lax_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::lax_aby_3;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::lax_aby_4;return; // READ
}

void m6502_device::lax_aby_3() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::lax_aby_4;return; // READ
}

void m6502_device::lax_aby_4() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lax_idx --- 
void m6502_device::lax_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_idx_1;return; // READ
}

void m6502_device::lax_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::lax_idx_2;return; // READ
}

void m6502_device::lax_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::lax_idx_3;return; // READ
}

void m6502_device::lax_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::lax_idx_4;return; // READ
}

void m6502_device::lax_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lax_idx_5;return; // READ
}

void m6502_device::lax_idx_5() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lax_idy --- 
void m6502_device::lax_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_idy_1;return; // READ
}

void m6502_device::lax_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::lax_idy_2;return; // READ
}

void m6502_device::lax_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::lax_idy_3;return; // READ
}

void m6502_device::lax_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::lax_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::lax_idy_5;return; // READ
}

void m6502_device::lax_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::lax_idy_5;return; // READ
}

void m6502_device::lax_idy_5() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lax_zpg --- 
void m6502_device::lax_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_zpg_1;return; // READ
}

void m6502_device::lax_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lax_zpg_2;return; // READ
}

void m6502_device::lax_zpg_2() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lax_zpy --- 
void m6502_device::lax_zpy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lax_zpy_1;return; // READ
}

void m6502_device::lax_zpy_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lax_zpy_2;return; // READ
}

void m6502_device::lax_zpy_2() {
  TMP = uint8_t(TMP+Y);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lax_zpy_3;return; // READ
}

void m6502_device::lax_zpy_3() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_aba --- 
void m6502_device::lda_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_aba_1;return; // READ
}

void m6502_device::lda_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_aba_2;return; // READ
}

void m6502_device::lda_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lda_aba_3;return; // READ
}

void m6502_device::lda_aba_3() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_abx --- 
void m6502_device::lda_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_abx_1;return; // READ
}

void m6502_device::lda_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_abx_2;return; // READ
}

void m6502_device::lda_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::lda_abx_3;return; // READ
  }
  ADDR = TMP + X;
  RNW = true;
  NextFn = &m6502_device::lda_abx_4;return; // READ
}

void m6502_device::lda_abx_3() {
    ADDR = TMP + X;
    RNW = true;
    NextFn = &m6502_device::lda_abx_4;return; // READ
}

void m6502_device::lda_abx_4() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_aby --- 
void m6502_device::lda_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_aby_1;return; // READ
}

void m6502_device::lda_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_aby_2;return; // READ
}

void m6502_device::lda_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::lda_aby_3;return; // READ
  }
  ADDR = TMP + Y;
  RNW = true;
  NextFn = &m6502_device::lda_aby_4;return; // READ
}

void m6502_device::lda_aby_3() {
    ADDR = TMP + Y;
    RNW = true;
    NextFn = &m6502_device::lda_aby_4;return; // READ
}

void m6502_device::lda_aby_4() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_idx --- 
void m6502_device::lda_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_idx_1;return; // READ
}

void m6502_device::lda_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::lda_idx_2;return; // READ
}

void m6502_device::lda_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::lda_idx_3;return; // READ
}

void m6502_device::lda_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::lda_idx_4;return; // READ
}

void m6502_device::lda_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lda_idx_5;return; // READ
}

void m6502_device::lda_idx_5() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_idy --- 
void m6502_device::lda_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_idy_1;return; // READ
}

void m6502_device::lda_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::lda_idy_2;return; // READ
}

void m6502_device::lda_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::lda_idy_3;return; // READ
}

void m6502_device::lda_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::lda_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::lda_idy_5;return; // READ
}

void m6502_device::lda_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::lda_idy_5;return; // READ
}

void m6502_device::lda_idy_5() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_imm --- 
void m6502_device::lda_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_imm_1;return; // READ
}

void m6502_device::lda_imm_1() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_zpg --- 
void m6502_device::lda_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_zpg_1;return; // READ
}

void m6502_device::lda_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lda_zpg_2;return; // READ
}

void m6502_device::lda_zpg_2() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_zpx --- 
void m6502_device::lda_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lda_zpx_1;return; // READ
}

void m6502_device::lda_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lda_zpx_2;return; // READ
}

void m6502_device::lda_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::lda_zpx_3;return; // READ
}

void m6502_device::lda_zpx_3() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ldx_aba --- 
void m6502_device::ldx_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_aba_1;return; // READ
}

void m6502_device::ldx_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_aba_2;return; // READ
}

void m6502_device::ldx_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldx_aba_3;return; // READ
}

void m6502_device::ldx_aba_3() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldx_aby --- 
void m6502_device::ldx_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_aby_1;return; // READ
}

void m6502_device::ldx_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_aby_2;return; // READ
}

void m6502_device::ldx_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::ldx_aby_3;return; // READ
  }
  ADDR = TMP + Y;
  RNW = true;
  NextFn = &m6502_device::ldx_aby_4;return; // READ
}

void m6502_device::ldx_aby_3() {
    ADDR = TMP + Y;
    RNW = true;
    NextFn = &m6502_device::ldx_aby_4;return; // READ
}

void m6502_device::ldx_aby_4() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldx_imm --- 
void m6502_device::ldx_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_imm_1;return; // READ
}

void m6502_device::ldx_imm_1() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldx_zpg --- 
void m6502_device::ldx_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_zpg_1;return; // READ
}

void m6502_device::ldx_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldx_zpg_2;return; // READ
}

void m6502_device::ldx_zpg_2() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldx_zpy --- 
void m6502_device::ldx_zpy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldx_zpy_1;return; // READ
}

void m6502_device::ldx_zpy_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldx_zpy_2;return; // READ
}

void m6502_device::ldx_zpy_2() {
  ADDR = uint8_t(TMP+Y);
  RNW = true;
  NextFn = &m6502_device::ldx_zpy_3;return; // READ
}

void m6502_device::ldx_zpy_3() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldy_aba --- 
void m6502_device::ldy_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_aba_1;return; // READ
}

void m6502_device::ldy_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_aba_2;return; // READ
}

void m6502_device::ldy_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldy_aba_3;return; // READ
}

void m6502_device::ldy_aba_3() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldy_abx --- 
void m6502_device::ldy_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_abx_1;return; // READ
}

void m6502_device::ldy_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_abx_2;return; // READ
}

void m6502_device::ldy_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::ldy_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldy_abx_4;return; // READ
}

void m6502_device::ldy_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::ldy_abx_4;return; // READ
}

void m6502_device::ldy_abx_4() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldy_imm --- 
void m6502_device::ldy_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_imm_1;return; // READ
}

void m6502_device::ldy_imm_1() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldy_zpg --- 
void m6502_device::ldy_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_zpg_1;return; // READ
}

void m6502_device::ldy_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldy_zpg_2;return; // READ
}

void m6502_device::ldy_zpg_2() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldy_zpx --- 
void m6502_device::ldy_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ldy_zpx_1;return; // READ
}

void m6502_device::ldy_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ldy_zpx_2;return; // READ
}

void m6502_device::ldy_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::ldy_zpx_3;return; // READ
}

void m6502_device::ldy_zpx_3() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op lsr_aba --- 
void m6502_device::lsr_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lsr_aba_1;return; // READ
}

void m6502_device::lsr_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lsr_aba_2;return; // READ
}

void m6502_device::lsr_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lsr_aba_3;return; // READ
}

void m6502_device::lsr_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_aba_4;return; // WRITE
}

void m6502_device::lsr_aba_4() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_aba_5;return; // WRITE
}

void m6502_device::lsr_aba_5() {
  fetch();return; // fetch
}

// --- op lsr_abx --- 
void m6502_device::lsr_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lsr_abx_1;return; // READ
}

void m6502_device::lsr_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lsr_abx_2;return; // READ
}

void m6502_device::lsr_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::lsr_abx_3;return; // READ
}

void m6502_device::lsr_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lsr_abx_4;return; // READ
}

void m6502_device::lsr_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_abx_5;return; // WRITE
}

void m6502_device::lsr_abx_5() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_abx_6;return; // WRITE
}

void m6502_device::lsr_abx_6() {
  fetch();return; // fetch
}

// --- op lsr_acc --- 
void m6502_device::lsr_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::lsr_acc_1;return; // READ
}

void m6502_device::lsr_acc_1() {
  A = do_lsr(A);
  fetch();return; // fetch
}

// --- op lsr_zpg --- 
void m6502_device::lsr_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lsr_zpg_1;return; // READ
}

void m6502_device::lsr_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lsr_zpg_2;return; // READ
}

void m6502_device::lsr_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_zpg_3;return; // WRITE
}

void m6502_device::lsr_zpg_3() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_zpg_4;return; // WRITE
}

void m6502_device::lsr_zpg_4() {
  fetch();return; // fetch
}

// --- op lsr_zpx --- 
void m6502_device::lsr_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lsr_zpx_1;return; // READ
}

void m6502_device::lsr_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lsr_zpx_2;return; // READ
}

void m6502_device::lsr_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::lsr_zpx_3;return; // READ
}

void m6502_device::lsr_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_zpx_4;return; // WRITE
}

void m6502_device::lsr_zpx_4() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::lsr_zpx_5;return; // WRITE
}

void m6502_device::lsr_zpx_5() {
  fetch();return; // fetch
}

// --- op lxa_imm --- 
void m6502_device::lxa_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::lxa_imm_1;return; // READ
}

void m6502_device::lxa_imm_1() {
  A = X = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op nop_aba --- 
void m6502_device::nop_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_aba_1;return; // READ
}

void m6502_device::nop_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_aba_2;return; // READ
}

void m6502_device::nop_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::nop_aba_3;return; // READ
}

void m6502_device::nop_aba_3() {
  fetch();return; // fetch
}

// --- op nop_abx --- 
void m6502_device::nop_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_abx_1;return; // READ
}

void m6502_device::nop_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_abx_2;return; // READ
}

void m6502_device::nop_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::nop_abx_3;return; // READ
  }
  ADDR = TMP + X;
  RNW = true;
  NextFn = &m6502_device::nop_abx_4;return; // READ
}

void m6502_device::nop_abx_3() {
    ADDR = TMP + X;
    RNW = true;
    NextFn = &m6502_device::nop_abx_4;return; // READ
}

void m6502_device::nop_abx_4() {
  fetch();return; // fetch
}

// --- op nop_imm --- 
void m6502_device::nop_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_imm_1;return; // READ
}

void m6502_device::nop_imm_1() {
  fetch();return; // fetch
}

// --- op nop_imp --- 
void m6502_device::nop_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::nop_imp_1;return; // READ
}

void m6502_device::nop_imp_1() {
  fetch();return; // fetch
}

// --- op nop_zpg --- 
void m6502_device::nop_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_zpg_1;return; // READ
}

void m6502_device::nop_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::nop_zpg_2;return; // READ
}

void m6502_device::nop_zpg_2() {
  fetch();return; // fetch
}

// --- op nop_zpx --- 
void m6502_device::nop_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::nop_zpx_1;return; // READ
}

void m6502_device::nop_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::nop_zpx_2;return; // READ
}

void m6502_device::nop_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::nop_zpx_3;return; // READ
}

void m6502_device::nop_zpx_3() {
  fetch();return; // fetch
}

// --- op ora_aba --- 
void m6502_device::ora_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_aba_1;return; // READ
}

void m6502_device::ora_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_aba_2;return; // READ
}

void m6502_device::ora_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ora_aba_3;return; // READ
}

void m6502_device::ora_aba_3() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_abx --- 
void m6502_device::ora_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_abx_1;return; // READ
}

void m6502_device::ora_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_abx_2;return; // READ
}

void m6502_device::ora_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::ora_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ora_abx_4;return; // READ
}

void m6502_device::ora_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::ora_abx_4;return; // READ
}

void m6502_device::ora_abx_4() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_aby --- 
void m6502_device::ora_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_aby_1;return; // READ
}

void m6502_device::ora_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_aby_2;return; // READ
}

void m6502_device::ora_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::ora_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ora_aby_4;return; // READ
}

void m6502_device::ora_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::ora_aby_4;return; // READ
}

void m6502_device::ora_aby_4() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_idx --- 
void m6502_device::ora_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_idx_1;return; // READ
}

void m6502_device::ora_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::ora_idx_2;return; // READ
}

void m6502_device::ora_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::ora_idx_3;return; // READ
}

void m6502_device::ora_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::ora_idx_4;return; // READ
}

void m6502_device::ora_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ora_idx_5;return; // READ
}

void m6502_device::ora_idx_5() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_idy --- 
void m6502_device::ora_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_idy_1;return; // READ
}

void m6502_device::ora_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::ora_idy_2;return; // READ
}

void m6502_device::ora_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::ora_idy_3;return; // READ
}

void m6502_device::ora_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::ora_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::ora_idy_5;return; // READ
}

void m6502_device::ora_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::ora_idy_5;return; // READ
}

void m6502_device::ora_idy_5() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_imm --- 
void m6502_device::ora_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_imm_1;return; // READ
}

void m6502_device::ora_imm_1() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_zpg --- 
void m6502_device::ora_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_zpg_1;return; // READ
}

void m6502_device::ora_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ora_zpg_2;return; // READ
}

void m6502_device::ora_zpg_2() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_zpx --- 
void m6502_device::ora_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ora_zpx_1;return; // READ
}

void m6502_device::ora_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ora_zpx_2;return; // READ
}

void m6502_device::ora_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::ora_zpx_3;return; // READ
}

void m6502_device::ora_zpx_3() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op pha_imp --- 
void m6502_device::pha_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::pha_imp_1;return; // READ
}

void m6502_device::pha_imp_1() {
  ADDR = SP;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::pha_imp_2;return; // WRITE
}

void m6502_device::pha_imp_2() {
  dec_SP();
  fetch();return; // fetch
}

// --- op php_imp --- 
void m6502_device::php_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::php_imp_1;return; // READ
}

void m6502_device::php_imp_1() {
  ADDR = SP;
  DAT =  P;
  RNW = false;
  NextFn = &m6502_device::php_imp_2;return; // WRITE
}

void m6502_device::php_imp_2() {
  dec_SP();
  fetch();return; // fetch
}

// --- op pla_imp --- 
void m6502_device::pla_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::pla_imp_1;return; // READ
}

void m6502_device::pla_imp_1() {
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::pla_imp_2;return; // READ
}

void m6502_device::pla_imp_2() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::pla_imp_3;return; // READ
}

void m6502_device::pla_imp_3() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op plp_imp --- 
void m6502_device::plp_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::plp_imp_1;return; // READ
}

void m6502_device::plp_imp_1() {
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::plp_imp_2;return; // READ
}

void m6502_device::plp_imp_2() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::plp_imp_3;return; // READ
}

void m6502_device::plp_imp_3() {
  TMP = DAT | (F_B|F_E);
  PrefetchNextFn = &m6502_device::plp_imp_4;
  prefetch();return; // prefetch
}

void m6502_device::plp_imp_4() {
  P = TMP;
  postfetch();return; // postfetch
}

// --- op reset --- 
void m6502_device::reset_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::reset_1;return; // READ
}

void m6502_device::reset_1() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::reset_2;return; // READ
}

void m6502_device::reset_2() {
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::reset_3;return; // READ
}

void m6502_device::reset_3() {
  DAT; dec_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::reset_4;return; // READ
}

void m6502_device::reset_4() {
  DAT; dec_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::reset_5;return; // READ
}

void m6502_device::reset_5() {
  DAT; dec_SP();
  ADDR = 0xfffc;
  RNW = true;
  NextFn = &m6502_device::reset_6;return; // READ
}

void m6502_device::reset_6() {
  P |= F_I; PC = DAT;
  ADDR = 0xfffd;
  RNW = true;
  NextFn = &m6502_device::reset_7;return; // READ
}

void m6502_device::reset_7() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op rla_aba --- 
void m6502_device::rla_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_aba_1;return; // READ
}

void m6502_device::rla_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_aba_2;return; // READ
}

void m6502_device::rla_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_aba_3;return; // READ
}

void m6502_device::rla_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_aba_4;return; // WRITE
}

void m6502_device::rla_aba_4() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_aba_5;return; // WRITE
}

void m6502_device::rla_aba_5() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rla_abx --- 
void m6502_device::rla_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_abx_1;return; // READ
}

void m6502_device::rla_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_abx_2;return; // READ
}

void m6502_device::rla_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::rla_abx_3;return; // READ
}

void m6502_device::rla_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_abx_4;return; // READ
}

void m6502_device::rla_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_abx_5;return; // WRITE
}

void m6502_device::rla_abx_5() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_abx_6;return; // WRITE
}

void m6502_device::rla_abx_6() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rla_aby --- 
void m6502_device::rla_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_aby_1;return; // READ
}

void m6502_device::rla_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_aby_2;return; // READ
}

void m6502_device::rla_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::rla_aby_3;return; // READ
}

void m6502_device::rla_aby_3() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_aby_4;return; // READ
}

void m6502_device::rla_aby_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_aby_5;return; // WRITE
}

void m6502_device::rla_aby_5() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_aby_6;return; // WRITE
}

void m6502_device::rla_aby_6() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rla_idx --- 
void m6502_device::rla_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_idx_1;return; // READ
}

void m6502_device::rla_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::rla_idx_2;return; // READ
}

void m6502_device::rla_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::rla_idx_3;return; // READ
}

void m6502_device::rla_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::rla_idx_4;return; // READ
}

void m6502_device::rla_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_idx_5;return; // READ
}

void m6502_device::rla_idx_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_idx_6;return; // WRITE
}

void m6502_device::rla_idx_6() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_idx_7;return; // WRITE
}

void m6502_device::rla_idx_7() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rla_idy --- 
void m6502_device::rla_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_idy_1;return; // READ
}

void m6502_device::rla_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::rla_idy_2;return; // READ
}

void m6502_device::rla_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::rla_idy_3;return; // READ
}

void m6502_device::rla_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::rla_idy_4;return; // READ
}

void m6502_device::rla_idy_4() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_idy_5;return; // READ
}

void m6502_device::rla_idy_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_idy_6;return; // WRITE
}

void m6502_device::rla_idy_6() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_idy_7;return; // WRITE
}

void m6502_device::rla_idy_7() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rla_zpg --- 
void m6502_device::rla_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_zpg_1;return; // READ
}

void m6502_device::rla_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_zpg_2;return; // READ
}

void m6502_device::rla_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_zpg_3;return; // WRITE
}

void m6502_device::rla_zpg_3() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_zpg_4;return; // WRITE
}

void m6502_device::rla_zpg_4() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rla_zpx --- 
void m6502_device::rla_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rla_zpx_1;return; // READ
}

void m6502_device::rla_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_zpx_2;return; // READ
}

void m6502_device::rla_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rla_zpx_3;return; // READ
}

void m6502_device::rla_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_zpx_4;return; // WRITE
}

void m6502_device::rla_zpx_4() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rla_zpx_5;return; // WRITE
}

void m6502_device::rla_zpx_5() {
  A &= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op rol_aba --- 
void m6502_device::rol_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rol_aba_1;return; // READ
}

void m6502_device::rol_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rol_aba_2;return; // READ
}

void m6502_device::rol_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rol_aba_3;return; // READ
}

void m6502_device::rol_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_aba_4;return; // WRITE
}

void m6502_device::rol_aba_4() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_aba_5;return; // WRITE
}

void m6502_device::rol_aba_5() {
  fetch();return; // fetch
}

// --- op rol_abx --- 
void m6502_device::rol_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rol_abx_1;return; // READ
}

void m6502_device::rol_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rol_abx_2;return; // READ
}

void m6502_device::rol_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::rol_abx_3;return; // READ
}

void m6502_device::rol_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rol_abx_4;return; // READ
}

void m6502_device::rol_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_abx_5;return; // WRITE
}

void m6502_device::rol_abx_5() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_abx_6;return; // WRITE
}

void m6502_device::rol_abx_6() {
  fetch();return; // fetch
}

// --- op rol_acc --- 
void m6502_device::rol_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::rol_acc_1;return; // READ
}

void m6502_device::rol_acc_1() {
  A = do_rol(A);
  fetch();return; // fetch
}

// --- op rol_zpg --- 
void m6502_device::rol_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rol_zpg_1;return; // READ
}

void m6502_device::rol_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rol_zpg_2;return; // READ
}

void m6502_device::rol_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_zpg_3;return; // WRITE
}

void m6502_device::rol_zpg_3() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_zpg_4;return; // WRITE
}

void m6502_device::rol_zpg_4() {
  fetch();return; // fetch
}

// --- op rol_zpx --- 
void m6502_device::rol_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rol_zpx_1;return; // READ
}

void m6502_device::rol_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rol_zpx_2;return; // READ
}

void m6502_device::rol_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rol_zpx_3;return; // READ
}

void m6502_device::rol_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_zpx_4;return; // WRITE
}

void m6502_device::rol_zpx_4() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rol_zpx_5;return; // WRITE
}

void m6502_device::rol_zpx_5() {
  fetch();return; // fetch
}

// --- op ror_aba --- 
void m6502_device::ror_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ror_aba_1;return; // READ
}

void m6502_device::ror_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ror_aba_2;return; // READ
}

void m6502_device::ror_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ror_aba_3;return; // READ
}

void m6502_device::ror_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_aba_4;return; // WRITE
}

void m6502_device::ror_aba_4() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_aba_5;return; // WRITE
}

void m6502_device::ror_aba_5() {
  fetch();return; // fetch
}

// --- op ror_abx --- 
void m6502_device::ror_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ror_abx_1;return; // READ
}

void m6502_device::ror_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ror_abx_2;return; // READ
}

void m6502_device::ror_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::ror_abx_3;return; // READ
}

void m6502_device::ror_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ror_abx_4;return; // READ
}

void m6502_device::ror_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_abx_5;return; // WRITE
}

void m6502_device::ror_abx_5() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_abx_6;return; // WRITE
}

void m6502_device::ror_abx_6() {
  fetch();return; // fetch
}

// --- op ror_acc --- 
void m6502_device::ror_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::ror_acc_1;return; // READ
}

void m6502_device::ror_acc_1() {
  A = do_ror(A);
  fetch();return; // fetch
}

// --- op ror_zpg --- 
void m6502_device::ror_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ror_zpg_1;return; // READ
}

void m6502_device::ror_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ror_zpg_2;return; // READ
}

void m6502_device::ror_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_zpg_3;return; // WRITE
}

void m6502_device::ror_zpg_3() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_zpg_4;return; // WRITE
}

void m6502_device::ror_zpg_4() {
  fetch();return; // fetch
}

// --- op ror_zpx --- 
void m6502_device::ror_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::ror_zpx_1;return; // READ
}

void m6502_device::ror_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ror_zpx_2;return; // READ
}

void m6502_device::ror_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::ror_zpx_3;return; // READ
}

void m6502_device::ror_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_zpx_4;return; // WRITE
}

void m6502_device::ror_zpx_4() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::ror_zpx_5;return; // WRITE
}

void m6502_device::ror_zpx_5() {
  fetch();return; // fetch
}

// --- op rra_aba --- 
void m6502_device::rra_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_aba_1;return; // READ
}

void m6502_device::rra_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_aba_2;return; // READ
}

void m6502_device::rra_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_aba_3;return; // READ
}

void m6502_device::rra_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_aba_4;return; // WRITE
}

void m6502_device::rra_aba_4() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_aba_5;return; // WRITE
}

void m6502_device::rra_aba_5() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rra_abx --- 
void m6502_device::rra_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_abx_1;return; // READ
}

void m6502_device::rra_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_abx_2;return; // READ
}

void m6502_device::rra_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::rra_abx_3;return; // READ
}

void m6502_device::rra_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_abx_4;return; // READ
}

void m6502_device::rra_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_abx_5;return; // WRITE
}

void m6502_device::rra_abx_5() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_abx_6;return; // WRITE
}

void m6502_device::rra_abx_6() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rra_aby --- 
void m6502_device::rra_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_aby_1;return; // READ
}

void m6502_device::rra_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_aby_2;return; // READ
}

void m6502_device::rra_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::rra_aby_3;return; // READ
}

void m6502_device::rra_aby_3() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_aby_4;return; // READ
}

void m6502_device::rra_aby_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_aby_5;return; // WRITE
}

void m6502_device::rra_aby_5() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_aby_6;return; // WRITE
}

void m6502_device::rra_aby_6() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rra_idx --- 
void m6502_device::rra_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_idx_1;return; // READ
}

void m6502_device::rra_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::rra_idx_2;return; // READ
}

void m6502_device::rra_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::rra_idx_3;return; // READ
}

void m6502_device::rra_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::rra_idx_4;return; // READ
}

void m6502_device::rra_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_idx_5;return; // READ
}

void m6502_device::rra_idx_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_idx_6;return; // WRITE
}

void m6502_device::rra_idx_6() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_idx_7;return; // WRITE
}

void m6502_device::rra_idx_7() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rra_idy --- 
void m6502_device::rra_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_idy_1;return; // READ
}

void m6502_device::rra_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::rra_idy_2;return; // READ
}

void m6502_device::rra_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::rra_idy_3;return; // READ
}

void m6502_device::rra_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::rra_idy_4;return; // READ
}

void m6502_device::rra_idy_4() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_idy_5;return; // READ
}

void m6502_device::rra_idy_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_idy_6;return; // WRITE
}

void m6502_device::rra_idy_6() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_idy_7;return; // WRITE
}

void m6502_device::rra_idy_7() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rra_zpg --- 
void m6502_device::rra_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_zpg_1;return; // READ
}

void m6502_device::rra_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_zpg_2;return; // READ
}

void m6502_device::rra_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_zpg_3;return; // WRITE
}

void m6502_device::rra_zpg_3() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_zpg_4;return; // WRITE
}

void m6502_device::rra_zpg_4() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rra_zpx --- 
void m6502_device::rra_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rra_zpx_1;return; // READ
}

void m6502_device::rra_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_zpx_2;return; // READ
}

void m6502_device::rra_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::rra_zpx_3;return; // READ
}

void m6502_device::rra_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_zpx_4;return; // WRITE
}

void m6502_device::rra_zpx_4() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::rra_zpx_5;return; // WRITE
}

void m6502_device::rra_zpx_5() {
  do_adc(TMP2);
  fetch();return; // fetch
}

// --- op rti_imp --- 
void m6502_device::rti_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::rti_imp_1;return; // READ
}

void m6502_device::rti_imp_1() {
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rti_imp_2;return; // READ
}

void m6502_device::rti_imp_2() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rti_imp_3;return; // READ
}

void m6502_device::rti_imp_3() {
  P = DAT | (F_B|F_E);
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rti_imp_4;return; // READ
}

void m6502_device::rti_imp_4() {
  PC = DAT;
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rti_imp_5;return; // READ
}

void m6502_device::rti_imp_5() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op rts_imp --- 
void m6502_device::rts_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::rts_imp_1;return; // READ
}

void m6502_device::rts_imp_1() {
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rts_imp_2;return; // READ
}

void m6502_device::rts_imp_2() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rts_imp_3;return; // READ
}

void m6502_device::rts_imp_3() {
  PC = DAT;
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m6502_device::rts_imp_4;return; // READ
}

void m6502_device::rts_imp_4() {
  PC = set_h(PC, DAT);
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::rts_imp_5;return; // READ
}

void m6502_device::rts_imp_5() {
  fetch();return; // fetch
}

// --- op sax_aba --- 
void m6502_device::sax_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sax_aba_1;return; // READ
}

void m6502_device::sax_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sax_aba_2;return; // READ
}

void m6502_device::sax_aba_2() {
  TMP = set_h(TMP, DAT);
  TMP2 = A & X;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sax_aba_3;return; // WRITE
}

void m6502_device::sax_aba_3() {
  fetch();return; // fetch
}

// --- op sax_idx --- 
void m6502_device::sax_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sax_idx_1;return; // READ
}

void m6502_device::sax_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sax_idx_2;return; // READ
}

void m6502_device::sax_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::sax_idx_3;return; // READ
}

void m6502_device::sax_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sax_idx_4;return; // READ
}

void m6502_device::sax_idx_4() {
  TMP = set_h(TMP, DAT);
  TMP2 = A & X;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sax_idx_5;return; // WRITE
}

void m6502_device::sax_idx_5() {
  fetch();return; // fetch
}

// --- op sax_zpg --- 
void m6502_device::sax_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sax_zpg_1;return; // READ
}

void m6502_device::sax_zpg_1() {
  TMP = DAT;
  TMP2 = A & X;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sax_zpg_2;return; // WRITE
}

void m6502_device::sax_zpg_2() {
  fetch();return; // fetch
}

// --- op sax_zpy --- 
void m6502_device::sax_zpy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sax_zpy_1;return; // READ
}

void m6502_device::sax_zpy_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sax_zpy_2;return; // READ
}

void m6502_device::sax_zpy_2() {
  TMP = uint8_t(TMP+Y);
  TMP2 = A & X;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sax_zpy_3;return; // WRITE
}

void m6502_device::sax_zpy_3() {
  fetch();return; // fetch
}

// --- op sbc_aba --- 
void m6502_device::sbc_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_aba_1;return; // READ
}

void m6502_device::sbc_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_aba_2;return; // READ
}

void m6502_device::sbc_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sbc_aba_3;return; // READ
}

void m6502_device::sbc_aba_3() {
  TMP = DAT;
  do_sbc(TMP);
  fetch();return; // fetch
}

// --- op sbc_abx --- 
void m6502_device::sbc_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_abx_1;return; // READ
}

void m6502_device::sbc_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_abx_2;return; // READ
}

void m6502_device::sbc_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m6502_device::sbc_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sbc_abx_4;return; // READ
}

void m6502_device::sbc_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::sbc_abx_4;return; // READ
}

void m6502_device::sbc_abx_4() {
  TMP = DAT;
  do_sbc(TMP);
  fetch();return; // fetch
}

// --- op sbc_aby --- 
void m6502_device::sbc_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_aby_1;return; // READ
}

void m6502_device::sbc_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_aby_2;return; // READ
}

void m6502_device::sbc_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::sbc_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sbc_aby_4;return; // READ
}

void m6502_device::sbc_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m6502_device::sbc_aby_4;return; // READ
}

void m6502_device::sbc_aby_4() {
  TMP = DAT;
  do_sbc(TMP);
  fetch();return; // fetch
}

// --- op sbc_idx --- 
void m6502_device::sbc_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_idx_1;return; // READ
}

void m6502_device::sbc_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sbc_idx_2;return; // READ
}

void m6502_device::sbc_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::sbc_idx_3;return; // READ
}

void m6502_device::sbc_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sbc_idx_4;return; // READ
}

void m6502_device::sbc_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sbc_idx_5;return; // READ
}

void m6502_device::sbc_idx_5() {
  do_sbc(DAT);
  fetch();return; // fetch
}

// --- op sbc_idy --- 
void m6502_device::sbc_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_idy_1;return; // READ
}

void m6502_device::sbc_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sbc_idy_2;return; // READ
}

void m6502_device::sbc_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sbc_idy_3;return; // READ
}

void m6502_device::sbc_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m6502_device::sbc_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m6502_device::sbc_idy_5;return; // READ
}

void m6502_device::sbc_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m6502_device::sbc_idy_5;return; // READ
}

void m6502_device::sbc_idy_5() {
  do_sbc(DAT);
  fetch();return; // fetch
}

// --- op sbc_imm --- 
void m6502_device::sbc_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_imm_1;return; // READ
}

void m6502_device::sbc_imm_1() {
  TMP = DAT;
  do_sbc(TMP);
  fetch();return; // fetch
}

// --- op sbc_zpg --- 
void m6502_device::sbc_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_zpg_1;return; // READ
}

void m6502_device::sbc_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sbc_zpg_2;return; // READ
}

void m6502_device::sbc_zpg_2() {
  TMP = DAT;
  do_sbc(TMP);
  fetch();return; // fetch
}

// --- op sbc_zpx --- 
void m6502_device::sbc_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbc_zpx_1;return; // READ
}

void m6502_device::sbc_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sbc_zpx_2;return; // READ
}

void m6502_device::sbc_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m6502_device::sbc_zpx_3;return; // READ
}

void m6502_device::sbc_zpx_3() {
  TMP = DAT;
  do_sbc(TMP);
  fetch();return; // fetch
}

// --- op sbx_imm --- 
void m6502_device::sbx_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sbx_imm_1;return; // READ
}

void m6502_device::sbx_imm_1() {
  TMP2 = DAT;
  X &= A;
  if (X < TMP2) {
    P &= ~F_C;
  } else {
    P |= F_C;
  }
  X -= TMP2;
  set_nz(X);
  fetch();return; // fetch
}

// --- op sec_imp --- 
void m6502_device::sec_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::sec_imp_1;return; // READ
}

void m6502_device::sec_imp_1() {
  P |= F_C;
  fetch();return; // fetch
}

// --- op sed_imp --- 
void m6502_device::sed_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::sed_imp_1;return; // READ
}

void m6502_device::sed_imp_1() {
  P |= F_D;
  fetch();return; // fetch
}

// --- op sei_imp --- 
void m6502_device::sei_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::sei_imp_1;return; // READ
}

void m6502_device::sei_imp_1() {
  PrefetchNextFn = &m6502_device::sei_imp_2;
  prefetch();return; // prefetch
}

void m6502_device::sei_imp_2() {
  P |= F_I;
  postfetch();return; // postfetch
}

// --- op sha_aby --- 
void m6502_device::sha_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sha_aby_1;return; // READ
}

void m6502_device::sha_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sha_aby_2;return; // READ
}

void m6502_device::sha_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::sha_aby_3;return; // READ
}

void m6502_device::sha_aby_3() {
  TMP2 = A & X & ((TMP >> 8)+1);
  if (page_changing(TMP, Y)) {
    TMP = set_h(TMP+Y, TMP2);
  } else {
    TMP += Y;
  }
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sha_aby_4;return; // WRITE
}

void m6502_device::sha_aby_4() {
  fetch();return; // fetch
}

// --- op sha_idy --- 
void m6502_device::sha_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sha_idy_1;return; // READ
}

void m6502_device::sha_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sha_idy_2;return; // READ
}

void m6502_device::sha_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sha_idy_3;return; // READ
}

void m6502_device::sha_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::sha_idy_4;return; // READ
}

void m6502_device::sha_idy_4() {
  TMP2 = A & X & ((TMP >> 8)+1);
  if (page_changing(TMP, Y)) {
    TMP = set_h(TMP+Y, TMP2);
  } else {
    TMP += Y;
  }
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sha_idy_5;return; // WRITE
}

void m6502_device::sha_idy_5() {
  fetch();return; // fetch
}

// --- op shs_aby --- 
void m6502_device::shs_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::shs_aby_1;return; // READ
}

void m6502_device::shs_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::shs_aby_2;return; // READ
}

void m6502_device::shs_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::shs_aby_3;return; // READ
}

void m6502_device::shs_aby_3() {
  SP = set_l(SP, A & X);
  TMP2 = A & X & ((TMP >> 8)+1);
  if (page_changing(TMP, Y)) {
    TMP = set_h(TMP+Y, TMP2);
  } else {
    TMP += Y;
  }
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::shs_aby_4;return; // WRITE
}

void m6502_device::shs_aby_4() {
  fetch();return; // fetch
}

// --- op shx_aby --- 
void m6502_device::shx_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::shx_aby_1;return; // READ
}

void m6502_device::shx_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::shx_aby_2;return; // READ
}

void m6502_device::shx_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::shx_aby_3;return; // READ
}

void m6502_device::shx_aby_3() {
  TMP2 = X & ((TMP >> 8)+1);
  if (page_changing(TMP, Y)) {
    TMP = set_h(TMP+Y, TMP2);
  } else {
    TMP += Y;
  }
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::shx_aby_4;return; // WRITE
}

void m6502_device::shx_aby_4() {
  fetch();return; // fetch
}

// --- op shy_abx --- 
void m6502_device::shy_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::shy_abx_1;return; // READ
}

void m6502_device::shy_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::shy_abx_2;return; // READ
}

void m6502_device::shy_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::shy_abx_3;return; // READ
}

void m6502_device::shy_abx_3() {
  TMP2 = Y & ((TMP >> 8)+1);
  if (page_changing(TMP, X)) {
    TMP = set_h(TMP+X, TMP2);
  } else {
    TMP += X;
  }
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::shy_abx_4;return; // WRITE
}

void m6502_device::shy_abx_4() {
  fetch();return; // fetch
}

// --- op slo_aba --- 
void m6502_device::slo_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_aba_1;return; // READ
}

void m6502_device::slo_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_aba_2;return; // READ
}

void m6502_device::slo_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_aba_3;return; // READ
}

void m6502_device::slo_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_aba_4;return; // WRITE
}

void m6502_device::slo_aba_4() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_aba_5;return; // WRITE
}

void m6502_device::slo_aba_5() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op slo_abx --- 
void m6502_device::slo_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_abx_1;return; // READ
}

void m6502_device::slo_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_abx_2;return; // READ
}

void m6502_device::slo_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::slo_abx_3;return; // READ
}

void m6502_device::slo_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_abx_4;return; // READ
}

void m6502_device::slo_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_abx_5;return; // WRITE
}

void m6502_device::slo_abx_5() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_abx_6;return; // WRITE
}

void m6502_device::slo_abx_6() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op slo_aby --- 
void m6502_device::slo_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_aby_1;return; // READ
}

void m6502_device::slo_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_aby_2;return; // READ
}

void m6502_device::slo_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::slo_aby_3;return; // READ
}

void m6502_device::slo_aby_3() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_aby_4;return; // READ
}

void m6502_device::slo_aby_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_aby_5;return; // WRITE
}

void m6502_device::slo_aby_5() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_aby_6;return; // WRITE
}

void m6502_device::slo_aby_6() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op slo_idx --- 
void m6502_device::slo_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_idx_1;return; // READ
}

void m6502_device::slo_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::slo_idx_2;return; // READ
}

void m6502_device::slo_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::slo_idx_3;return; // READ
}

void m6502_device::slo_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::slo_idx_4;return; // READ
}

void m6502_device::slo_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_idx_5;return; // READ
}

void m6502_device::slo_idx_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_idx_6;return; // WRITE
}

void m6502_device::slo_idx_6() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_idx_7;return; // WRITE
}

void m6502_device::slo_idx_7() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op slo_idy --- 
void m6502_device::slo_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_idy_1;return; // READ
}

void m6502_device::slo_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::slo_idy_2;return; // READ
}

void m6502_device::slo_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::slo_idy_3;return; // READ
}

void m6502_device::slo_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::slo_idy_4;return; // READ
}

void m6502_device::slo_idy_4() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_idy_5;return; // READ
}

void m6502_device::slo_idy_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_idy_6;return; // WRITE
}

void m6502_device::slo_idy_6() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_idy_7;return; // WRITE
}

void m6502_device::slo_idy_7() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op slo_zpg --- 
void m6502_device::slo_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_zpg_1;return; // READ
}

void m6502_device::slo_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_zpg_2;return; // READ
}

void m6502_device::slo_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_zpg_3;return; // WRITE
}

void m6502_device::slo_zpg_3() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_zpg_4;return; // WRITE
}

void m6502_device::slo_zpg_4() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op slo_zpx --- 
void m6502_device::slo_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::slo_zpx_1;return; // READ
}

void m6502_device::slo_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_zpx_2;return; // READ
}

void m6502_device::slo_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::slo_zpx_3;return; // READ
}

void m6502_device::slo_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_zpx_4;return; // WRITE
}

void m6502_device::slo_zpx_4() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::slo_zpx_5;return; // WRITE
}

void m6502_device::slo_zpx_5() {
  A |= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_aba --- 
void m6502_device::sre_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_aba_1;return; // READ
}

void m6502_device::sre_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_aba_2;return; // READ
}

void m6502_device::sre_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_aba_3;return; // READ
}

void m6502_device::sre_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_aba_4;return; // WRITE
}

void m6502_device::sre_aba_4() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_aba_5;return; // WRITE
}

void m6502_device::sre_aba_5() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_abx --- 
void m6502_device::sre_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_abx_1;return; // READ
}

void m6502_device::sre_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_abx_2;return; // READ
}

void m6502_device::sre_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::sre_abx_3;return; // READ
}

void m6502_device::sre_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_abx_4;return; // READ
}

void m6502_device::sre_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_abx_5;return; // WRITE
}

void m6502_device::sre_abx_5() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_abx_6;return; // WRITE
}

void m6502_device::sre_abx_6() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_aby --- 
void m6502_device::sre_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_aby_1;return; // READ
}

void m6502_device::sre_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_aby_2;return; // READ
}

void m6502_device::sre_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::sre_aby_3;return; // READ
}

void m6502_device::sre_aby_3() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_aby_4;return; // READ
}

void m6502_device::sre_aby_4() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_aby_5;return; // WRITE
}

void m6502_device::sre_aby_5() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_aby_6;return; // WRITE
}

void m6502_device::sre_aby_6() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_idx --- 
void m6502_device::sre_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_idx_1;return; // READ
}

void m6502_device::sre_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sre_idx_2;return; // READ
}

void m6502_device::sre_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::sre_idx_3;return; // READ
}

void m6502_device::sre_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sre_idx_4;return; // READ
}

void m6502_device::sre_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_idx_5;return; // READ
}

void m6502_device::sre_idx_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_idx_6;return; // WRITE
}

void m6502_device::sre_idx_6() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_idx_7;return; // WRITE
}

void m6502_device::sre_idx_7() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_idy --- 
void m6502_device::sre_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_idy_1;return; // READ
}

void m6502_device::sre_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sre_idy_2;return; // READ
}

void m6502_device::sre_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sre_idy_3;return; // READ
}

void m6502_device::sre_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::sre_idy_4;return; // READ
}

void m6502_device::sre_idy_4() {
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_idy_5;return; // READ
}

void m6502_device::sre_idy_5() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_idy_6;return; // WRITE
}

void m6502_device::sre_idy_6() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_idy_7;return; // WRITE
}

void m6502_device::sre_idy_7() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_zpg --- 
void m6502_device::sre_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_zpg_1;return; // READ
}

void m6502_device::sre_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_zpg_2;return; // READ
}

void m6502_device::sre_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_zpg_3;return; // WRITE
}

void m6502_device::sre_zpg_3() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_zpg_4;return; // WRITE
}

void m6502_device::sre_zpg_4() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sre_zpx --- 
void m6502_device::sre_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sre_zpx_1;return; // READ
}

void m6502_device::sre_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_zpx_2;return; // READ
}

void m6502_device::sre_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sre_zpx_3;return; // READ
}

void m6502_device::sre_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_zpx_4;return; // WRITE
}

void m6502_device::sre_zpx_4() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m6502_device::sre_zpx_5;return; // WRITE
}

void m6502_device::sre_zpx_5() {
  A ^= TMP2;
  set_nz(A);
  fetch();return; // fetch
}

// --- op sta_aba --- 
void m6502_device::sta_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_aba_1;return; // READ
}

void m6502_device::sta_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_aba_2;return; // READ
}

void m6502_device::sta_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_aba_3;return; // WRITE
}

void m6502_device::sta_aba_3() {
  fetch();return; // fetch
}

// --- op sta_abx --- 
void m6502_device::sta_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_abx_1;return; // READ
}

void m6502_device::sta_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_abx_2;return; // READ
}

void m6502_device::sta_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m6502_device::sta_abx_3;return; // READ
}

void m6502_device::sta_abx_3() {
  ADDR = TMP+X;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_abx_4;return; // WRITE
}

void m6502_device::sta_abx_4() {
  fetch();return; // fetch
}

// --- op sta_aby --- 
void m6502_device::sta_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_aby_1;return; // READ
}

void m6502_device::sta_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_aby_2;return; // READ
}

void m6502_device::sta_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::sta_aby_3;return; // READ
}

void m6502_device::sta_aby_3() {
  ADDR = TMP+Y;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_aby_4;return; // WRITE
}

void m6502_device::sta_aby_4() {
  fetch();return; // fetch
}

// --- op sta_idx --- 
void m6502_device::sta_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_idx_1;return; // READ
}

void m6502_device::sta_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sta_idx_2;return; // READ
}

void m6502_device::sta_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m6502_device::sta_idx_3;return; // READ
}

void m6502_device::sta_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sta_idx_4;return; // READ
}

void m6502_device::sta_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_idx_5;return; // WRITE
}

void m6502_device::sta_idx_5() {
  fetch();return; // fetch
}

// --- op sta_idy --- 
void m6502_device::sta_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_idy_1;return; // READ
}

void m6502_device::sta_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m6502_device::sta_idy_2;return; // READ
}

void m6502_device::sta_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m6502_device::sta_idy_3;return; // READ
}

void m6502_device::sta_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+Y);
  RNW = true;
  NextFn = &m6502_device::sta_idy_4;return; // READ
}

void m6502_device::sta_idy_4() {
  ADDR = TMP+Y;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_idy_5;return; // WRITE
}

void m6502_device::sta_idy_5() {
  fetch();return; // fetch
}

// --- op sta_zpg --- 
void m6502_device::sta_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_zpg_1;return; // READ
}

void m6502_device::sta_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_zpg_2;return; // WRITE
}

void m6502_device::sta_zpg_2() {
  fetch();return; // fetch
}

// --- op sta_zpx --- 
void m6502_device::sta_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sta_zpx_1;return; // READ
}

void m6502_device::sta_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sta_zpx_2;return; // READ
}

void m6502_device::sta_zpx_2() {
  ADDR = uint8_t(TMP+X);
  DAT =  A;
  RNW = false;
  NextFn = &m6502_device::sta_zpx_3;return; // WRITE
}

void m6502_device::sta_zpx_3() {
  fetch();return; // fetch
}

// --- op stx_aba --- 
void m6502_device::stx_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::stx_aba_1;return; // READ
}

void m6502_device::stx_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::stx_aba_2;return; // READ
}

void m6502_device::stx_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  X;
  RNW = false;
  NextFn = &m6502_device::stx_aba_3;return; // WRITE
}

void m6502_device::stx_aba_3() {
  fetch();return; // fetch
}

// --- op stx_zpg --- 
void m6502_device::stx_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::stx_zpg_1;return; // READ
}

void m6502_device::stx_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  DAT =  X;
  RNW = false;
  NextFn = &m6502_device::stx_zpg_2;return; // WRITE
}

void m6502_device::stx_zpg_2() {
  fetch();return; // fetch
}

// --- op stx_zpy --- 
void m6502_device::stx_zpy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::stx_zpy_1;return; // READ
}

void m6502_device::stx_zpy_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::stx_zpy_2;return; // READ
}

void m6502_device::stx_zpy_2() {
  ADDR = uint8_t(TMP+Y);
  DAT =  X;
  RNW = false;
  NextFn = &m6502_device::stx_zpy_3;return; // WRITE
}

void m6502_device::stx_zpy_3() {
  fetch();return; // fetch
}

// --- op sty_aba --- 
void m6502_device::sty_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sty_aba_1;return; // READ
}

void m6502_device::sty_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sty_aba_2;return; // READ
}

void m6502_device::sty_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  Y;
  RNW = false;
  NextFn = &m6502_device::sty_aba_3;return; // WRITE
}

void m6502_device::sty_aba_3() {
  fetch();return; // fetch
}

// --- op sty_zpg --- 
void m6502_device::sty_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sty_zpg_1;return; // READ
}

void m6502_device::sty_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  DAT =  Y;
  RNW = false;
  NextFn = &m6502_device::sty_zpg_2;return; // WRITE
}

void m6502_device::sty_zpg_2() {
  fetch();return; // fetch
}

// --- op sty_zpx --- 
void m6502_device::sty_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m6502_device::sty_zpx_1;return; // READ
}

void m6502_device::sty_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m6502_device::sty_zpx_2;return; // READ
}

void m6502_device::sty_zpx_2() {
  ADDR = uint8_t(TMP+X);
  DAT =  Y;
  RNW = false;
  NextFn = &m6502_device::sty_zpx_3;return; // WRITE
}

void m6502_device::sty_zpx_3() {
  fetch();return; // fetch
}

// --- op tax_imp --- 
void m6502_device::tax_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::tax_imp_1;return; // READ
}

void m6502_device::tax_imp_1() {
  X = A;
  set_nz(X);
  fetch();return; // fetch
}

// --- op tay_imp --- 
void m6502_device::tay_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::tay_imp_1;return; // READ
}

void m6502_device::tay_imp_1() {
  Y = A;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op tsx_imp --- 
void m6502_device::tsx_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::tsx_imp_1;return; // READ
}

void m6502_device::tsx_imp_1() {
  X = SP;
  set_nz(X);
  fetch();return; // fetch
}

// --- op txa_imp --- 
void m6502_device::txa_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::txa_imp_1;return; // READ
}

void m6502_device::txa_imp_1() {
  A = X;
  set_nz(A);
  fetch();return; // fetch
}

// --- op txs_imp --- 
void m6502_device::txs_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::txs_imp_1;return; // READ
}

void m6502_device::txs_imp_1() {
  SP = set_l(SP, X);
  fetch();return; // fetch
}

// --- op tya_imp --- 
void m6502_device::tya_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m6502_device::tya_imp_1;return; // READ
}

void m6502_device::tya_imp_1() {
  A = Y;
  set_nz(A);
  fetch();return; // fetch
}

void m6502_device::postfetch_int() {
  switch(IR) {
  case 0x00: brk_imp_0(); break;
  case 0x01: ora_idx_0(); break;
  case 0x02: kil_non_0(); break;
  case 0x03: slo_idx_0(); break;
  case 0x04: nop_zpg_0(); break;
  case 0x05: ora_zpg_0(); break;
  case 0x06: asl_zpg_0(); break;
  case 0x07: slo_zpg_0(); break;
  case 0x08: php_imp_0(); break;
  case 0x09: ora_imm_0(); break;
  case 0x0a: asl_acc_0(); break;
  case 0x0b: anc_imm_0(); break;
  case 0x0c: nop_aba_0(); break;
  case 0x0d: ora_aba_0(); break;
  case 0x0e: asl_aba_0(); break;
  case 0x0f: slo_aba_0(); break;
  case 0x10: bpl_rel_0(); break;
  case 0x11: ora_idy_0(); break;
  case 0x12: kil_non_0(); break;
  case 0x13: slo_idy_0(); break;
  case 0x14: nop_zpx_0(); break;
  case 0x15: ora_zpx_0(); break;
  case 0x16: asl_zpx_0(); break;
  case 0x17: slo_zpx_0(); break;
  case 0x18: clc_imp_0(); break;
  case 0x19: ora_aby_0(); break;
  case 0x1a: nop_imp_0(); break;
  case 0x1b: slo_aby_0(); break;
  case 0x1c: nop_abx_0(); break;
  case 0x1d: ora_abx_0(); break;
  case 0x1e: asl_abx_0(); break;
  case 0x1f: slo_abx_0(); break;
  case 0x20: jsr_adr_0(); break;
  case 0x21: and_idx_0(); break;
  case 0x22: kil_non_0(); break;
  case 0x23: rla_idx_0(); break;
  case 0x24: bit_zpg_0(); break;
  case 0x25: and_zpg_0(); break;
  case 0x26: rol_zpg_0(); break;
  case 0x27: rla_zpg_0(); break;
  case 0x28: plp_imp_0(); break;
  case 0x29: and_imm_0(); break;
  case 0x2a: rol_acc_0(); break;
  case 0x2b: anc_imm_0(); break;
  case 0x2c: bit_aba_0(); break;
  case 0x2d: and_aba_0(); break;
  case 0x2e: rol_aba_0(); break;
  case 0x2f: rla_aba_0(); break;
  case 0x30: bmi_rel_0(); break;
  case 0x31: and_idy_0(); break;
  case 0x32: kil_non_0(); break;
  case 0x33: rla_idy_0(); break;
  case 0x34: nop_zpx_0(); break;
  case 0x35: and_zpx_0(); break;
  case 0x36: rol_zpx_0(); break;
  case 0x37: rla_zpx_0(); break;
  case 0x38: sec_imp_0(); break;
  case 0x39: and_aby_0(); break;
  case 0x3a: nop_imp_0(); break;
  case 0x3b: rla_aby_0(); break;
  case 0x3c: nop_abx_0(); break;
  case 0x3d: and_abx_0(); break;
  case 0x3e: rol_abx_0(); break;
  case 0x3f: rla_abx_0(); break;
  case 0x40: rti_imp_0(); break;
  case 0x41: eor_idx_0(); break;
  case 0x42: kil_non_0(); break;
  case 0x43: sre_idx_0(); break;
  case 0x44: nop_zpg_0(); break;
  case 0x45: eor_zpg_0(); break;
  case 0x46: lsr_zpg_0(); break;
  case 0x47: sre_zpg_0(); break;
  case 0x48: pha_imp_0(); break;
  case 0x49: eor_imm_0(); break;
  case 0x4a: lsr_acc_0(); break;
  case 0x4b: asr_imm_0(); break;
  case 0x4c: jmp_adr_0(); break;
  case 0x4d: eor_aba_0(); break;
  case 0x4e: lsr_aba_0(); break;
  case 0x4f: sre_aba_0(); break;
  case 0x50: bvc_rel_0(); break;
  case 0x51: eor_idy_0(); break;
  case 0x52: kil_non_0(); break;
  case 0x53: sre_idy_0(); break;
  case 0x54: nop_zpx_0(); break;
  case 0x55: eor_zpx_0(); break;
  case 0x56: lsr_zpx_0(); break;
  case 0x57: sre_zpx_0(); break;
  case 0x58: cli_imp_0(); break;
  case 0x59: eor_aby_0(); break;
  case 0x5a: nop_imp_0(); break;
  case 0x5b: sre_aby_0(); break;
  case 0x5c: nop_abx_0(); break;
  case 0x5d: eor_abx_0(); break;
  case 0x5e: lsr_abx_0(); break;
  case 0x5f: sre_abx_0(); break;
  case 0x60: rts_imp_0(); break;
  case 0x61: adc_idx_0(); break;
  case 0x62: kil_non_0(); break;
  case 0x63: rra_idx_0(); break;
  case 0x64: nop_zpg_0(); break;
  case 0x65: adc_zpg_0(); break;
  case 0x66: ror_zpg_0(); break;
  case 0x67: rra_zpg_0(); break;
  case 0x68: pla_imp_0(); break;
  case 0x69: adc_imm_0(); break;
  case 0x6a: ror_acc_0(); break;
  case 0x6b: arr_imm_0(); break;
  case 0x6c: jmp_ind_0(); break;
  case 0x6d: adc_aba_0(); break;
  case 0x6e: ror_aba_0(); break;
  case 0x6f: rra_aba_0(); break;
  case 0x70: bvs_rel_0(); break;
  case 0x71: adc_idy_0(); break;
  case 0x72: kil_non_0(); break;
  case 0x73: rra_idy_0(); break;
  case 0x74: nop_zpx_0(); break;
  case 0x75: adc_zpx_0(); break;
  case 0x76: ror_zpx_0(); break;
  case 0x77: rra_zpx_0(); break;
  case 0x78: sei_imp_0(); break;
  case 0x79: adc_aby_0(); break;
  case 0x7a: nop_imp_0(); break;
  case 0x7b: rra_aby_0(); break;
  case 0x7c: nop_abx_0(); break;
  case 0x7d: adc_abx_0(); break;
  case 0x7e: ror_abx_0(); break;
  case 0x7f: rra_abx_0(); break;
  case 0x80: nop_imm_0(); break;
  case 0x81: sta_idx_0(); break;
  case 0x82: nop_imm_0(); break;
  case 0x83: sax_idx_0(); break;
  case 0x84: sty_zpg_0(); break;
  case 0x85: sta_zpg_0(); break;
  case 0x86: stx_zpg_0(); break;
  case 0x87: sax_zpg_0(); break;
  case 0x88: dey_imp_0(); break;
  case 0x89: nop_imm_0(); break;
  case 0x8a: txa_imp_0(); break;
  case 0x8b: ane_imm_0(); break;
  case 0x8c: sty_aba_0(); break;
  case 0x8d: sta_aba_0(); break;
  case 0x8e: stx_aba_0(); break;
  case 0x8f: sax_aba_0(); break;
  case 0x90: bcc_rel_0(); break;
  case 0x91: sta_idy_0(); break;
  case 0x92: kil_non_0(); break;
  case 0x93: sha_idy_0(); break;
  case 0x94: sty_zpx_0(); break;
  case 0x95: sta_zpx_0(); break;
  case 0x96: stx_zpy_0(); break;
  case 0x97: sax_zpy_0(); break;
  case 0x98: tya_imp_0(); break;
  case 0x99: sta_aby_0(); break;
  case 0x9a: txs_imp_0(); break;
  case 0x9b: shs_aby_0(); break;
  case 0x9c: shy_abx_0(); break;
  case 0x9d: sta_abx_0(); break;
  case 0x9e: shx_aby_0(); break;
  case 0x9f: sha_aby_0(); break;
  case 0xa0: ldy_imm_0(); break;
  case 0xa1: lda_idx_0(); break;
  case 0xa2: ldx_imm_0(); break;
  case 0xa3: lax_idx_0(); break;
  case 0xa4: ldy_zpg_0(); break;
  case 0xa5: lda_zpg_0(); break;
  case 0xa6: ldx_zpg_0(); break;
  case 0xa7: lax_zpg_0(); break;
  case 0xa8: tay_imp_0(); break;
  case 0xa9: lda_imm_0(); break;
  case 0xaa: tax_imp_0(); break;
  case 0xab: lxa_imm_0(); break;
  case 0xac: ldy_aba_0(); break;
  case 0xad: lda_aba_0(); break;
  case 0xae: ldx_aba_0(); break;
  case 0xaf: lax_aba_0(); break;
  case 0xb0: bcs_rel_0(); break;
  case 0xb1: lda_idy_0(); break;
  case 0xb2: kil_non_0(); break;
  case 0xb3: lax_idy_0(); break;
  case 0xb4: ldy_zpx_0(); break;
  case 0xb5: lda_zpx_0(); break;
  case 0xb6: ldx_zpy_0(); break;
  case 0xb7: lax_zpy_0(); break;
  case 0xb8: clv_imp_0(); break;
  case 0xb9: lda_aby_0(); break;
  case 0xba: tsx_imp_0(); break;
  case 0xbb: las_aby_0(); break;
  case 0xbc: ldy_abx_0(); break;
  case 0xbd: lda_abx_0(); break;
  case 0xbe: ldx_aby_0(); break;
  case 0xbf: lax_aby_0(); break;
  case 0xc0: cpy_imm_0(); break;
  case 0xc1: cmp_idx_0(); break;
  case 0xc2: nop_imm_0(); break;
  case 0xc3: dcp_idx_0(); break;
  case 0xc4: cpy_zpg_0(); break;
  case 0xc5: cmp_zpg_0(); break;
  case 0xc6: dec_zpg_0(); break;
  case 0xc7: dcp_zpg_0(); break;
  case 0xc8: iny_imp_0(); break;
  case 0xc9: cmp_imm_0(); break;
  case 0xca: dex_imp_0(); break;
  case 0xcb: sbx_imm_0(); break;
  case 0xcc: cpy_aba_0(); break;
  case 0xcd: cmp_aba_0(); break;
  case 0xce: dec_aba_0(); break;
  case 0xcf: dcp_aba_0(); break;
  case 0xd0: bne_rel_0(); break;
  case 0xd1: cmp_idy_0(); break;
  case 0xd2: kil_non_0(); break;
  case 0xd3: dcp_idy_0(); break;
  case 0xd4: nop_zpx_0(); break;
  case 0xd5: cmp_zpx_0(); break;
  case 0xd6: dec_zpx_0(); break;
  case 0xd7: dcp_zpx_0(); break;
  case 0xd8: cld_imp_0(); break;
  case 0xd9: cmp_aby_0(); break;
  case 0xda: nop_imp_0(); break;
  case 0xdb: dcp_aby_0(); break;
  case 0xdc: nop_abx_0(); break;
  case 0xdd: cmp_abx_0(); break;
  case 0xde: dec_abx_0(); break;
  case 0xdf: dcp_abx_0(); break;
  case 0xe0: cpx_imm_0(); break;
  case 0xe1: sbc_idx_0(); break;
  case 0xe2: nop_imm_0(); break;
  case 0xe3: isb_idx_0(); break;
  case 0xe4: cpx_zpg_0(); break;
  case 0xe5: sbc_zpg_0(); break;
  case 0xe6: inc_zpg_0(); break;
  case 0xe7: isb_zpg_0(); break;
  case 0xe8: inx_imp_0(); break;
  case 0xe9: sbc_imm_0(); break;
  case 0xea: nop_imp_0(); break;
  case 0xeb: sbc_imm_0(); break;
  case 0xec: cpx_aba_0(); break;
  case 0xed: sbc_aba_0(); break;
  case 0xee: inc_aba_0(); break;
  case 0xef: isb_aba_0(); break;
  case 0xf0: beq_rel_0(); break;
  case 0xf1: sbc_idy_0(); break;
  case 0xf2: kil_non_0(); break;
  case 0xf3: isb_idy_0(); break;
  case 0xf4: nop_zpx_0(); break;
  case 0xf5: sbc_zpx_0(); break;
  case 0xf6: inc_zpx_0(); break;
  case 0xf7: isb_zpx_0(); break;
  case 0xf8: sed_imp_0(); break;
  case 0xf9: sbc_aby_0(); break;
  case 0xfa: nop_imp_0(); break;
  case 0xfb: isb_aby_0(); break;
  case 0xfc: nop_abx_0(); break;
  case 0xfd: sbc_abx_0(); break;
  case 0xfe: inc_abx_0(); break;
  case 0xff: isb_abx_0(); break;
  default:   reset_0(); break;
  }
}

