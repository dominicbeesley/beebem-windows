// This file has been automatically produced by makehxx.pl
// do not edit it.
// from file(s) dm65c02.lst D:\Users\Dominic\Documents\GitHub\beebem-windows\cpu65x\m6502\om65c02.lst
#include "m65c02.h"
// --- op adc_c_aba --- 
void m65c02_device::adc_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_aba_1;return; // READ
}

void m65c02_device::adc_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_aba_2;return; // READ
}

void m65c02_device::adc_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_aba_3;return; // READ
}

void m65c02_device::adc_c_aba_3() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_aba_4;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_aba_4() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_abx --- 
void m65c02_device::adc_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_abx_1;return; // READ
}

void m65c02_device::adc_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_abx_2;return; // READ
}

void m65c02_device::adc_c_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m65c02_device::adc_c_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_abx_4;return; // READ
}

void m65c02_device::adc_c_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m65c02_device::adc_c_abx_4;return; // READ
}

void m65c02_device::adc_c_abx_4() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_abx_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_abx_5() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_aby --- 
void m65c02_device::adc_c_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_aby_1;return; // READ
}

void m65c02_device::adc_c_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_aby_2;return; // READ
}

void m65c02_device::adc_c_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m65c02_device::adc_c_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_aby_4;return; // READ
}

void m65c02_device::adc_c_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m65c02_device::adc_c_aby_4;return; // READ
}

void m65c02_device::adc_c_aby_4() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_aby_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_aby_5() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_idx --- 
void m65c02_device::adc_c_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idx_1;return; // READ
}

void m65c02_device::adc_c_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idx_2;return; // READ
}

void m65c02_device::adc_c_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idx_3;return; // READ
}

void m65c02_device::adc_c_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idx_4;return; // READ
}

void m65c02_device::adc_c_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idx_5;return; // READ
}

void m65c02_device::adc_c_idx_5() {
  do_adc(DAT);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_idx_6;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_idx_6() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_idy --- 
void m65c02_device::adc_c_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idy_1;return; // READ
}

void m65c02_device::adc_c_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idy_2;return; // READ
}

void m65c02_device::adc_c_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idy_3;return; // READ
}

void m65c02_device::adc_c_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m65c02_device::adc_c_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65c02_device::adc_c_idy_5;return; // READ
}

void m65c02_device::adc_c_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m65c02_device::adc_c_idy_5;return; // READ
}

void m65c02_device::adc_c_idy_5() {
  do_adc(DAT);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_idy_6;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_idy_6() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_imm --- 
void m65c02_device::adc_c_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_imm_1;return; // READ
}

void m65c02_device::adc_c_imm_1() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_imm_2;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_imm_2() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_zpg --- 
void m65c02_device::adc_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpg_1;return; // READ
}

void m65c02_device::adc_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpg_2;return; // READ
}

void m65c02_device::adc_c_zpg_2() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_zpg_3;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_zpg_3() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_zpi --- 
void m65c02_device::adc_c_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpi_1;return; // READ
}

void m65c02_device::adc_c_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpi_2;return; // READ
}

void m65c02_device::adc_c_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpi_3;return; // READ
}

void m65c02_device::adc_c_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpi_4;return; // READ
}

void m65c02_device::adc_c_zpi_4() {
  do_adc(DAT);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_zpi_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_zpi_5() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op adc_c_zpx --- 
void m65c02_device::adc_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpx_1;return; // READ
}

void m65c02_device::adc_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpx_2;return; // READ
}

void m65c02_device::adc_c_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65c02_device::adc_c_zpx_3;return; // READ
}

void m65c02_device::adc_c_zpx_3() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::adc_c_zpx_4;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::adc_c_zpx_4() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op and_zpi --- 
void m65c02_device::and_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::and_zpi_1;return; // READ
}

void m65c02_device::and_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::and_zpi_2;return; // READ
}

void m65c02_device::and_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::and_zpi_3;return; // READ
}

void m65c02_device::and_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::and_zpi_4;return; // READ
}

void m65c02_device::and_zpi_4() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op asl_c_aba --- 
void m65c02_device::asl_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::asl_c_aba_1;return; // READ
}

void m65c02_device::asl_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::asl_c_aba_2;return; // READ
}

void m65c02_device::asl_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_aba_3;return; // READ
}

void m65c02_device::asl_c_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_aba_4;return; // READ
}

void m65c02_device::asl_c_aba_4() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::asl_c_aba_5;return; // WRITE
}

void m65c02_device::asl_c_aba_5() {
  fetch();return; // fetch
}

// --- op asl_c_abx --- 
void m65c02_device::asl_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::asl_c_abx_1;return; // READ
}

void m65c02_device::asl_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::asl_c_abx_2;return; // READ
}

void m65c02_device::asl_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::asl_c_abx_3;return; // READ
}

void m65c02_device::asl_c_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_abx_4;return; // READ
}

void m65c02_device::asl_c_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_abx_5;return; // READ
}

void m65c02_device::asl_c_abx_5() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::asl_c_abx_6;return; // WRITE
}

void m65c02_device::asl_c_abx_6() {
  fetch();return; // fetch
}

// --- op asl_c_zpg --- 
void m65c02_device::asl_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpg_1;return; // READ
}

void m65c02_device::asl_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpg_2;return; // READ
}

void m65c02_device::asl_c_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpg_3;return; // READ
}

void m65c02_device::asl_c_zpg_3() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::asl_c_zpg_4;return; // WRITE
}

void m65c02_device::asl_c_zpg_4() {
  fetch();return; // fetch
}

// --- op asl_c_zpx --- 
void m65c02_device::asl_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpx_1;return; // READ
}

void m65c02_device::asl_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpx_2;return; // READ
}

void m65c02_device::asl_c_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpx_3;return; // READ
}

void m65c02_device::asl_c_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::asl_c_zpx_4;return; // READ
}

void m65c02_device::asl_c_zpx_4() {
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::asl_c_zpx_5;return; // WRITE
}

void m65c02_device::asl_c_zpx_5() {
  fetch();return; // fetch
}

// --- op bbr_zpb --- 
void m65c02_device::bbr_zpb_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bbr_zpb_1;return; // READ
}

void m65c02_device::bbr_zpb_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::bbr_zpb_2;return; // READ
}

void m65c02_device::bbr_zpb_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::bbr_zpb_3;return; // READ
}

void m65c02_device::bbr_zpb_3() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bbr_zpb_4;return; // READ
}

void m65c02_device::bbr_zpb_4() {
  TMP = DAT;
  if (!(TMP2 & (1 << ((IR >> 4) & 7)))) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::bbr_zpb_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::bbr_zpb_5() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m65c02_device::bbr_zpb_6;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m65c02_device::bbr_zpb_6() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bbs_zpb --- 
void m65c02_device::bbs_zpb_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bbs_zpb_1;return; // READ
}

void m65c02_device::bbs_zpb_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::bbs_zpb_2;return; // READ
}

void m65c02_device::bbs_zpb_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::bbs_zpb_3;return; // READ
}

void m65c02_device::bbs_zpb_3() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bbs_zpb_4;return; // READ
}

void m65c02_device::bbs_zpb_4() {
  TMP = DAT;
  if (TMP2 & (1 << ((IR >> 4) & 7))) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::bbs_zpb_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::bbs_zpb_5() {
    if (page_changing(PC, int8_t(TMP))) {
      ADDR = set_l(PC, PC+int8_t(TMP));
      RNW = true;
      NextFn = &m65c02_device::bbs_zpb_6;return; // READ
    }
    PC += int8_t(TMP);
    fetch();return; // fetch
}

void m65c02_device::bbs_zpb_6() {
      PC += int8_t(TMP);
      fetch();return; // fetch
}

// --- op bit_abx --- 
void m65c02_device::bit_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bit_abx_1;return; // READ
}

void m65c02_device::bit_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bit_abx_2;return; // READ
}

void m65c02_device::bit_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m65c02_device::bit_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::bit_abx_4;return; // READ
}

void m65c02_device::bit_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m65c02_device::bit_abx_4;return; // READ
}

void m65c02_device::bit_abx_4() {
  do_bit(DAT);
  fetch();return; // fetch
}

// --- op bit_imm --- 
void m65c02_device::bit_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bit_imm_1;return; // READ
}

void m65c02_device::bit_imm_1() {
  TMP = DAT;
  if (A & TMP) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  fetch();return; // fetch
}

// --- op bit_zpx --- 
void m65c02_device::bit_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bit_zpx_1;return; // READ
}

void m65c02_device::bit_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::bit_zpx_2;return; // READ
}

void m65c02_device::bit_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65c02_device::bit_zpx_3;return; // READ
}

void m65c02_device::bit_zpx_3() {
  TMP = DAT;
  do_bit(TMP);
  fetch();return; // fetch
}

// --- op bra_rel --- 
void m65c02_device::bra_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::bra_rel_1;return; // READ
}

void m65c02_device::bra_rel_1() {
  TMP = DAT;
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::bra_rel_2;return; // READ
}

void m65c02_device::bra_rel_2() {
  if (page_changing(PC, int8_t(TMP))) {
    ADDR = set_l(PC, PC+int8_t(TMP));
    RNW = true;
    NextFn = &m65c02_device::bra_rel_3;return; // READ
  }
  PC += int8_t(TMP);
  fetch();return; // fetch
}

void m65c02_device::bra_rel_3() {
    PC += int8_t(TMP);
    fetch();return; // fetch
}

// --- op brk_c_imp --- 
void m65c02_device::brk_c_imp_0() {
  if (irq_taken || nmi_state) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::brk_c_imp_1;return; // READ
  } else {
    ADDR = PC++;
    RNW = true;
    NextFn = &m65c02_device::brk_c_imp_2;return; // READ
  }
  ADDR = SP;
  DAT =  PC >> 8;
  RNW = false;
  NextFn = &m65c02_device::brk_c_imp_3;return; // WRITE
}

void m65c02_device::brk_c_imp_1() {
    ADDR = SP;
    DAT =  PC >> 8;
    RNW = false;
    NextFn = &m65c02_device::brk_c_imp_3;return; // WRITE
}

void m65c02_device::brk_c_imp_2() {
    ADDR = SP;
    DAT =  PC >> 8;
    RNW = false;
    NextFn = &m65c02_device::brk_c_imp_3;return; // WRITE
}

void m65c02_device::brk_c_imp_3() {
  dec_SP();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m65c02_device::brk_c_imp_4;return; // WRITE
}

void m65c02_device::brk_c_imp_4() {
  dec_SP();
  ADDR = SP;
  DAT =  irq_taken || nmi_state ? P & ~F_B : P;
  RNW = false;
  NextFn = &m65c02_device::brk_c_imp_5;return; // WRITE
}

void m65c02_device::brk_c_imp_5() {
  dec_SP();
  if (irq_taken && nmi_state) {
    ADDR = 0xfffa;
    RNW = true;
    NextFn = &m65c02_device::brk_c_imp_6;return; // READ
  } else {
    ADDR = 0xfffe;
    RNW = true;
    NextFn = &m65c02_device::brk_c_imp_8;return; // READ
  }
  irq_taken = false;
  P = (P | F_I) & ~F_D;
  fetch();return; // fetch
}

void m65c02_device::brk_c_imp_6() {
    PC = DAT;
    ADDR = 0xfffb;
    RNW = true;
    NextFn = &m65c02_device::brk_c_imp_7;return; // READ
}

void m65c02_device::brk_c_imp_8() {
    PC = DAT;
    ADDR = 0xffff;
    RNW = true;
    NextFn = &m65c02_device::brk_c_imp_9;return; // READ
}

void m65c02_device::brk_c_imp_7() {
    PC = set_h(PC, DAT);
    nmi_state = false;
    standard_irq_callback(NMI_LINE);
    irq_taken = false;
    P = (P | F_I) & ~F_D;
    fetch();return; // fetch
}

void m65c02_device::brk_c_imp_9() {
    PC = set_h(PC, DAT);
    if (irq_taken) {
      standard_irq_callback(IRQ_LINE);
    }
    irq_taken = false;
    P = (P | F_I) & ~F_D;
    fetch();return; // fetch
}

// --- op cmp_zpi --- 
void m65c02_device::cmp_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::cmp_zpi_1;return; // READ
}

void m65c02_device::cmp_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::cmp_zpi_2;return; // READ
}

void m65c02_device::cmp_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::cmp_zpi_3;return; // READ
}

void m65c02_device::cmp_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::cmp_zpi_4;return; // READ
}

void m65c02_device::cmp_zpi_4() {
  do_cmp(A, DAT);
  fetch();return; // fetch
}

// --- op dec_acc --- 
void m65c02_device::dec_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::dec_acc_1;return; // READ
}

void m65c02_device::dec_acc_1() {
  A--;
  set_nz(A);
  fetch();return; // fetch
}

// --- op dec_c_aba --- 
void m65c02_device::dec_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::dec_c_aba_1;return; // READ
}

void m65c02_device::dec_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::dec_c_aba_2;return; // READ
}

void m65c02_device::dec_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_aba_3;return; // READ
}

void m65c02_device::dec_c_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_aba_4;return; // READ
}

void m65c02_device::dec_c_aba_4() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::dec_c_aba_5;return; // WRITE
}

void m65c02_device::dec_c_aba_5() {
  fetch();return; // fetch
}

// --- op dec_c_abx --- 
void m65c02_device::dec_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::dec_c_abx_1;return; // READ
}

void m65c02_device::dec_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::dec_c_abx_2;return; // READ
}

void m65c02_device::dec_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::dec_c_abx_3;return; // READ
}

void m65c02_device::dec_c_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_abx_4;return; // READ
}

void m65c02_device::dec_c_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_abx_5;return; // READ
}

void m65c02_device::dec_c_abx_5() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::dec_c_abx_6;return; // WRITE
}

void m65c02_device::dec_c_abx_6() {
  fetch();return; // fetch
}

// --- op dec_c_zpg --- 
void m65c02_device::dec_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpg_1;return; // READ
}

void m65c02_device::dec_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpg_2;return; // READ
}

void m65c02_device::dec_c_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpg_3;return; // READ
}

void m65c02_device::dec_c_zpg_3() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::dec_c_zpg_4;return; // WRITE
}

void m65c02_device::dec_c_zpg_4() {
  fetch();return; // fetch
}

// --- op dec_c_zpx --- 
void m65c02_device::dec_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpx_1;return; // READ
}

void m65c02_device::dec_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpx_2;return; // READ
}

void m65c02_device::dec_c_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpx_3;return; // READ
}

void m65c02_device::dec_c_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::dec_c_zpx_4;return; // READ
}

void m65c02_device::dec_c_zpx_4() {
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::dec_c_zpx_5;return; // WRITE
}

void m65c02_device::dec_c_zpx_5() {
  fetch();return; // fetch
}

// --- op eor_zpi --- 
void m65c02_device::eor_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::eor_zpi_1;return; // READ
}

void m65c02_device::eor_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::eor_zpi_2;return; // READ
}

void m65c02_device::eor_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::eor_zpi_3;return; // READ
}

void m65c02_device::eor_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::eor_zpi_4;return; // READ
}

void m65c02_device::eor_zpi_4() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op inc_acc --- 
void m65c02_device::inc_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::inc_acc_1;return; // READ
}

void m65c02_device::inc_acc_1() {
  A++;
  set_nz(A);
  fetch();return; // fetch
}

// --- op inc_c_aba --- 
void m65c02_device::inc_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::inc_c_aba_1;return; // READ
}

void m65c02_device::inc_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::inc_c_aba_2;return; // READ
}

void m65c02_device::inc_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_aba_3;return; // READ
}

void m65c02_device::inc_c_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_aba_4;return; // READ
}

void m65c02_device::inc_c_aba_4() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::inc_c_aba_5;return; // WRITE
}

void m65c02_device::inc_c_aba_5() {
  fetch();return; // fetch
}

// --- op inc_c_abx --- 
void m65c02_device::inc_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::inc_c_abx_1;return; // READ
}

void m65c02_device::inc_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::inc_c_abx_2;return; // READ
}

void m65c02_device::inc_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::inc_c_abx_3;return; // READ
}

void m65c02_device::inc_c_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_abx_4;return; // READ
}

void m65c02_device::inc_c_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_abx_5;return; // READ
}

void m65c02_device::inc_c_abx_5() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::inc_c_abx_6;return; // WRITE
}

void m65c02_device::inc_c_abx_6() {
  fetch();return; // fetch
}

// --- op inc_c_zpg --- 
void m65c02_device::inc_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpg_1;return; // READ
}

void m65c02_device::inc_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpg_2;return; // READ
}

void m65c02_device::inc_c_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpg_3;return; // READ
}

void m65c02_device::inc_c_zpg_3() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::inc_c_zpg_4;return; // WRITE
}

void m65c02_device::inc_c_zpg_4() {
  fetch();return; // fetch
}

// --- op inc_c_zpx --- 
void m65c02_device::inc_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpx_1;return; // READ
}

void m65c02_device::inc_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpx_2;return; // READ
}

void m65c02_device::inc_c_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpx_3;return; // READ
}

void m65c02_device::inc_c_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::inc_c_zpx_4;return; // READ
}

void m65c02_device::inc_c_zpx_4() {
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::inc_c_zpx_5;return; // WRITE
}

void m65c02_device::inc_c_zpx_5() {
  fetch();return; // fetch
}

// --- op jmp_c_ind --- 
void m65c02_device::jmp_c_ind_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::jmp_c_ind_1;return; // READ
}

void m65c02_device::jmp_c_ind_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::jmp_c_ind_2;return; // READ
}

void m65c02_device::jmp_c_ind_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::jmp_c_ind_3;return; // READ
}

void m65c02_device::jmp_c_ind_3() {
  PC = DAT;
  ADDR = set_l(TMP, TMP+1);
  RNW = true;
  NextFn = &m65c02_device::jmp_c_ind_4;return; // READ
}

void m65c02_device::jmp_c_ind_4() {
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65c02_device::jmp_c_ind_5;return; // READ
}

void m65c02_device::jmp_c_ind_5() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op jmp_iax --- 
void m65c02_device::jmp_iax_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::jmp_iax_1;return; // READ
}

void m65c02_device::jmp_iax_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::jmp_iax_2;return; // READ
}

void m65c02_device::jmp_iax_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::jmp_iax_3;return; // READ
}

void m65c02_device::jmp_iax_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::jmp_iax_4;return; // READ
}

void m65c02_device::jmp_iax_4() {
  PC = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65c02_device::jmp_iax_5;return; // READ
}

void m65c02_device::jmp_iax_5() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op lda_zpi --- 
void m65c02_device::lda_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lda_zpi_1;return; // READ
}

void m65c02_device::lda_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::lda_zpi_2;return; // READ
}

void m65c02_device::lda_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::lda_zpi_3;return; // READ
}

void m65c02_device::lda_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lda_zpi_4;return; // READ
}

void m65c02_device::lda_zpi_4() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lsr_c_aba --- 
void m65c02_device::lsr_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_aba_1;return; // READ
}

void m65c02_device::lsr_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_aba_2;return; // READ
}

void m65c02_device::lsr_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_aba_3;return; // READ
}

void m65c02_device::lsr_c_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_aba_4;return; // READ
}

void m65c02_device::lsr_c_aba_4() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::lsr_c_aba_5;return; // WRITE
}

void m65c02_device::lsr_c_aba_5() {
  fetch();return; // fetch
}

// --- op lsr_c_abx --- 
void m65c02_device::lsr_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_abx_1;return; // READ
}

void m65c02_device::lsr_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_abx_2;return; // READ
}

void m65c02_device::lsr_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::lsr_c_abx_3;return; // READ
}

void m65c02_device::lsr_c_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_abx_4;return; // READ
}

void m65c02_device::lsr_c_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_abx_5;return; // READ
}

void m65c02_device::lsr_c_abx_5() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::lsr_c_abx_6;return; // WRITE
}

void m65c02_device::lsr_c_abx_6() {
  fetch();return; // fetch
}

// --- op lsr_c_zpg --- 
void m65c02_device::lsr_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpg_1;return; // READ
}

void m65c02_device::lsr_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpg_2;return; // READ
}

void m65c02_device::lsr_c_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpg_3;return; // READ
}

void m65c02_device::lsr_c_zpg_3() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::lsr_c_zpg_4;return; // WRITE
}

void m65c02_device::lsr_c_zpg_4() {
  fetch();return; // fetch
}

// --- op lsr_c_zpx --- 
void m65c02_device::lsr_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpx_1;return; // READ
}

void m65c02_device::lsr_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpx_2;return; // READ
}

void m65c02_device::lsr_c_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpx_3;return; // READ
}

void m65c02_device::lsr_c_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::lsr_c_zpx_4;return; // READ
}

void m65c02_device::lsr_c_zpx_4() {
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::lsr_c_zpx_5;return; // WRITE
}

void m65c02_device::lsr_c_zpx_5() {
  fetch();return; // fetch
}

// --- op nop_c_aba --- 
void m65c02_device::nop_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_1;return; // READ
}

void m65c02_device::nop_c_aba_1() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_2;return; // READ
}

void m65c02_device::nop_c_aba_2() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_3;return; // READ
}

void m65c02_device::nop_c_aba_3() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_4;return; // READ
}

void m65c02_device::nop_c_aba_4() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_5;return; // READ
}

void m65c02_device::nop_c_aba_5() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_6;return; // READ
}

void m65c02_device::nop_c_aba_6() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::nop_c_aba_7;return; // READ
}

void m65c02_device::nop_c_aba_7() {
  fetch();return; // fetch
}

// --- op nop_c_abx --- 
void m65c02_device::nop_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::nop_c_abx_1;return; // READ
}

void m65c02_device::nop_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::nop_c_abx_2;return; // READ
}

void m65c02_device::nop_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::nop_c_abx_3;return; // READ
}

void m65c02_device::nop_c_abx_3() {
  fetch();return; // fetch
}

// --- op nop_c_imp --- 
void m65c02_device::nop_c_imp_0() {
  fetch();return; // fetch
}

// --- op ora_zpi --- 
void m65c02_device::ora_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ora_zpi_1;return; // READ
}

void m65c02_device::ora_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::ora_zpi_2;return; // READ
}

void m65c02_device::ora_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::ora_zpi_3;return; // READ
}

void m65c02_device::ora_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ora_zpi_4;return; // READ
}

void m65c02_device::ora_zpi_4() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op phx_imp --- 
void m65c02_device::phx_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::phx_imp_1;return; // READ
}

void m65c02_device::phx_imp_1() {
  ADDR = SP;
  DAT =  X;
  RNW = false;
  NextFn = &m65c02_device::phx_imp_2;return; // WRITE
}

void m65c02_device::phx_imp_2() {
  dec_SP();
  fetch();return; // fetch
}

// --- op phy_imp --- 
void m65c02_device::phy_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::phy_imp_1;return; // READ
}

void m65c02_device::phy_imp_1() {
  ADDR = SP;
  DAT =  Y;
  RNW = false;
  NextFn = &m65c02_device::phy_imp_2;return; // WRITE
}

void m65c02_device::phy_imp_2() {
  dec_SP();
  fetch();return; // fetch
}

// --- op plx_imp --- 
void m65c02_device::plx_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::plx_imp_1;return; // READ
}

void m65c02_device::plx_imp_1() {
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::plx_imp_2;return; // READ
}

void m65c02_device::plx_imp_2() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::plx_imp_3;return; // READ
}

void m65c02_device::plx_imp_3() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ply_imp --- 
void m65c02_device::ply_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::ply_imp_1;return; // READ
}

void m65c02_device::ply_imp_1() {
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::ply_imp_2;return; // READ
}

void m65c02_device::ply_imp_2() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::ply_imp_3;return; // READ
}

void m65c02_device::ply_imp_3() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op reset_c --- 
void m65c02_device::reset_c_0() {
  ADDR = 0xffff;
  RNW = true;
  NextFn = &m65c02_device::reset_c_1;return; // READ
}

void m65c02_device::reset_c_1() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::reset_c_2;return; // READ
}

void m65c02_device::reset_c_2() {
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::reset_c_3;return; // READ
}

void m65c02_device::reset_c_3() {
  DAT; dec_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::reset_c_4;return; // READ
}

void m65c02_device::reset_c_4() {
  DAT; dec_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m65c02_device::reset_c_5;return; // READ
}

void m65c02_device::reset_c_5() {
  DAT; dec_SP();
  P = (P | F_I) & ~F_D;
  ADDR = 0xfffc;
  RNW = true;
  NextFn = &m65c02_device::reset_c_6;return; // READ
}

void m65c02_device::reset_c_6() {
  PC = DAT;
  ADDR = 0xfffd;
  RNW = true;
  NextFn = &m65c02_device::reset_c_7;return; // READ
}

void m65c02_device::reset_c_7() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op rmb_bzp --- 
void m65c02_device::rmb_bzp_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rmb_bzp_1;return; // READ
}

void m65c02_device::rmb_bzp_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rmb_bzp_2;return; // READ
}

void m65c02_device::rmb_bzp_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rmb_bzp_3;return; // READ
}

void m65c02_device::rmb_bzp_3() {
  TMP2 &= ~(1 << ((IR >> 4) & 7));
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::rmb_bzp_4;return; // WRITE
}

void m65c02_device::rmb_bzp_4() {
  fetch();return; // fetch
}

// --- op rol_c_aba --- 
void m65c02_device::rol_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rol_c_aba_1;return; // READ
}

void m65c02_device::rol_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rol_c_aba_2;return; // READ
}

void m65c02_device::rol_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_aba_3;return; // READ
}

void m65c02_device::rol_c_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_aba_4;return; // READ
}

void m65c02_device::rol_c_aba_4() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::rol_c_aba_5;return; // WRITE
}

void m65c02_device::rol_c_aba_5() {
  fetch();return; // fetch
}

// --- op rol_c_abx --- 
void m65c02_device::rol_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rol_c_abx_1;return; // READ
}

void m65c02_device::rol_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rol_c_abx_2;return; // READ
}

void m65c02_device::rol_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::rol_c_abx_3;return; // READ
}

void m65c02_device::rol_c_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_abx_4;return; // READ
}

void m65c02_device::rol_c_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_abx_5;return; // READ
}

void m65c02_device::rol_c_abx_5() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::rol_c_abx_6;return; // WRITE
}

void m65c02_device::rol_c_abx_6() {
  fetch();return; // fetch
}

// --- op rol_c_zpg --- 
void m65c02_device::rol_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpg_1;return; // READ
}

void m65c02_device::rol_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpg_2;return; // READ
}

void m65c02_device::rol_c_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpg_3;return; // READ
}

void m65c02_device::rol_c_zpg_3() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::rol_c_zpg_4;return; // WRITE
}

void m65c02_device::rol_c_zpg_4() {
  fetch();return; // fetch
}

// --- op rol_c_zpx --- 
void m65c02_device::rol_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpx_1;return; // READ
}

void m65c02_device::rol_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpx_2;return; // READ
}

void m65c02_device::rol_c_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpx_3;return; // READ
}

void m65c02_device::rol_c_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::rol_c_zpx_4;return; // READ
}

void m65c02_device::rol_c_zpx_4() {
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::rol_c_zpx_5;return; // WRITE
}

void m65c02_device::rol_c_zpx_5() {
  fetch();return; // fetch
}

// --- op ror_c_aba --- 
void m65c02_device::ror_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ror_c_aba_1;return; // READ
}

void m65c02_device::ror_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ror_c_aba_2;return; // READ
}

void m65c02_device::ror_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_aba_3;return; // READ
}

void m65c02_device::ror_c_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_aba_4;return; // READ
}

void m65c02_device::ror_c_aba_4() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::ror_c_aba_5;return; // WRITE
}

void m65c02_device::ror_c_aba_5() {
  fetch();return; // fetch
}

// --- op ror_c_abx --- 
void m65c02_device::ror_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ror_c_abx_1;return; // READ
}

void m65c02_device::ror_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ror_c_abx_2;return; // READ
}

void m65c02_device::ror_c_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::ror_c_abx_3;return; // READ
}

void m65c02_device::ror_c_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_abx_4;return; // READ
}

void m65c02_device::ror_c_abx_4() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_abx_5;return; // READ
}

void m65c02_device::ror_c_abx_5() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::ror_c_abx_6;return; // WRITE
}

void m65c02_device::ror_c_abx_6() {
  fetch();return; // fetch
}

// --- op ror_c_zpg --- 
void m65c02_device::ror_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpg_1;return; // READ
}

void m65c02_device::ror_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpg_2;return; // READ
}

void m65c02_device::ror_c_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpg_3;return; // READ
}

void m65c02_device::ror_c_zpg_3() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::ror_c_zpg_4;return; // WRITE
}

void m65c02_device::ror_c_zpg_4() {
  fetch();return; // fetch
}

// --- op ror_c_zpx --- 
void m65c02_device::ror_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpx_1;return; // READ
}

void m65c02_device::ror_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpx_2;return; // READ
}

void m65c02_device::ror_c_zpx_2() {
  TMP = uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpx_3;return; // READ
}

void m65c02_device::ror_c_zpx_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::ror_c_zpx_4;return; // READ
}

void m65c02_device::ror_c_zpx_4() {
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::ror_c_zpx_5;return; // WRITE
}

void m65c02_device::ror_c_zpx_5() {
  fetch();return; // fetch
}

// --- op sbc_c_aba --- 
void m65c02_device::sbc_c_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_aba_1;return; // READ
}

void m65c02_device::sbc_c_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_aba_2;return; // READ
}

void m65c02_device::sbc_c_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_aba_3;return; // READ
}

void m65c02_device::sbc_c_aba_3() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_aba_4;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_aba_4() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_abx --- 
void m65c02_device::sbc_c_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_abx_1;return; // READ
}

void m65c02_device::sbc_c_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_abx_2;return; // READ
}

void m65c02_device::sbc_c_abx_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, X)) {
    ADDR = set_l(TMP, TMP+X);
    RNW = true;
    NextFn = &m65c02_device::sbc_c_abx_3;return; // READ
  }
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_abx_4;return; // READ
}

void m65c02_device::sbc_c_abx_3() {
    TMP += X;
    ADDR = TMP;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_abx_4;return; // READ
}

void m65c02_device::sbc_c_abx_4() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_abx_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_abx_5() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_aby --- 
void m65c02_device::sbc_c_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_aby_1;return; // READ
}

void m65c02_device::sbc_c_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_aby_2;return; // READ
}

void m65c02_device::sbc_c_aby_2() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m65c02_device::sbc_c_aby_3;return; // READ
  }
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_aby_4;return; // READ
}

void m65c02_device::sbc_c_aby_3() {
    TMP += Y;
    ADDR = TMP;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_aby_4;return; // READ
}

void m65c02_device::sbc_c_aby_4() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_aby_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_aby_5() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_idx --- 
void m65c02_device::sbc_c_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idx_1;return; // READ
}

void m65c02_device::sbc_c_idx_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idx_2;return; // READ
}

void m65c02_device::sbc_c_idx_2() {
  TMP2 += X;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idx_3;return; // READ
}

void m65c02_device::sbc_c_idx_3() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idx_4;return; // READ
}

void m65c02_device::sbc_c_idx_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idx_5;return; // READ
}

void m65c02_device::sbc_c_idx_5() {
  do_sbc(DAT);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_idx_6;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_idx_6() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_idy --- 
void m65c02_device::sbc_c_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idy_1;return; // READ
}

void m65c02_device::sbc_c_idy_1() {
  TMP2 = DAT;
  ADDR = TMP2;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idy_2;return; // READ
}

void m65c02_device::sbc_c_idy_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idy_3;return; // READ
}

void m65c02_device::sbc_c_idy_3() {
  TMP = set_h(TMP, DAT);
  if (page_changing(TMP, Y)) {
    ADDR = set_l(TMP, TMP+Y);
    RNW = true;
    NextFn = &m65c02_device::sbc_c_idy_4;return; // READ
  }
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_idy_5;return; // READ
}

void m65c02_device::sbc_c_idy_4() {
    ADDR = TMP+Y;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_idy_5;return; // READ
}

void m65c02_device::sbc_c_idy_5() {
  do_sbc(DAT);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_idy_6;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_idy_6() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_imm --- 
void m65c02_device::sbc_c_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_imm_1;return; // READ
}

void m65c02_device::sbc_c_imm_1() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_imm_2;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_imm_2() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_zpg --- 
void m65c02_device::sbc_c_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpg_1;return; // READ
}

void m65c02_device::sbc_c_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpg_2;return; // READ
}

void m65c02_device::sbc_c_zpg_2() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_zpg_3;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_zpg_3() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_zpi --- 
void m65c02_device::sbc_c_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpi_1;return; // READ
}

void m65c02_device::sbc_c_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpi_2;return; // READ
}

void m65c02_device::sbc_c_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpi_3;return; // READ
}

void m65c02_device::sbc_c_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpi_4;return; // READ
}

void m65c02_device::sbc_c_zpi_4() {
  do_sbc(DAT);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_zpi_5;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_zpi_5() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op sbc_c_zpx --- 
void m65c02_device::sbc_c_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpx_1;return; // READ
}

void m65c02_device::sbc_c_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpx_2;return; // READ
}

void m65c02_device::sbc_c_zpx_2() {
  ADDR = uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65c02_device::sbc_c_zpx_3;return; // READ
}

void m65c02_device::sbc_c_zpx_3() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65c02_device::sbc_c_zpx_4;return; // READ
  }
  fetch();return; // fetch
}

void m65c02_device::sbc_c_zpx_4() {
    set_nz(A);
    fetch();return; // fetch
}

// --- op smb_bzp --- 
void m65c02_device::smb_bzp_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::smb_bzp_1;return; // READ
}

void m65c02_device::smb_bzp_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::smb_bzp_2;return; // READ
}

void m65c02_device::smb_bzp_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::smb_bzp_3;return; // READ
}

void m65c02_device::smb_bzp_3() {
  TMP2 |= 1 << ((IR >> 4) & 7);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::smb_bzp_4;return; // WRITE
}

void m65c02_device::smb_bzp_4() {
  fetch();return; // fetch
}

// --- op sta_zpi --- 
void m65c02_device::sta_zpi_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::sta_zpi_1;return; // READ
}

void m65c02_device::sta_zpi_1() {
  TMP2 = DAT;
  ADDR = TMP2 & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sta_zpi_2;return; // READ
}

void m65c02_device::sta_zpi_2() {
  TMP = DAT;
  ADDR = (TMP2+1) & 0xff;
  RNW = true;
  NextFn = &m65c02_device::sta_zpi_3;return; // READ
}

void m65c02_device::sta_zpi_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m65c02_device::sta_zpi_4;return; // WRITE
}

void m65c02_device::sta_zpi_4() {
  fetch();return; // fetch
}

// --- op stp_imp --- 
void m65c02_device::stp_imp_0() {
  stp_imp_while_1();return;
}

void m65c02_device::stp_imp_while_1() {
  if (!true) m65c02_device::stp_imp_whilenot_1();return;
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::stp_imp_1;return; // READ
}

void m65c02_device::stp_imp_whilenot_1() {
  fetch();return; // fetch
}

void m65c02_device::stp_imp_1() {
  stp_imp_while_1();return;
}

// --- op stz_aba --- 
void m65c02_device::stz_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::stz_aba_1;return; // READ
}

void m65c02_device::stz_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::stz_aba_2;return; // READ
}

void m65c02_device::stz_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  0x00;
  RNW = false;
  NextFn = &m65c02_device::stz_aba_3;return; // WRITE
}

void m65c02_device::stz_aba_3() {
  fetch();return; // fetch
}

// --- op stz_abx --- 
void m65c02_device::stz_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::stz_abx_1;return; // READ
}

void m65c02_device::stz_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::stz_abx_2;return; // READ
}

void m65c02_device::stz_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65c02_device::stz_abx_3;return; // READ
}

void m65c02_device::stz_abx_3() {
  ADDR = TMP+X;
  DAT =  0x00;
  RNW = false;
  NextFn = &m65c02_device::stz_abx_4;return; // WRITE
}

void m65c02_device::stz_abx_4() {
  fetch();return; // fetch
}

// --- op stz_zpg --- 
void m65c02_device::stz_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::stz_zpg_1;return; // READ
}

void m65c02_device::stz_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  DAT =  0x00;
  RNW = false;
  NextFn = &m65c02_device::stz_zpg_2;return; // WRITE
}

void m65c02_device::stz_zpg_2() {
  fetch();return; // fetch
}

// --- op stz_zpx --- 
void m65c02_device::stz_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::stz_zpx_1;return; // READ
}

void m65c02_device::stz_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::stz_zpx_2;return; // READ
}

void m65c02_device::stz_zpx_2() {
  ADDR = uint8_t(TMP+X);
  DAT =  0x00;
  RNW = false;
  NextFn = &m65c02_device::stz_zpx_3;return; // WRITE
}

void m65c02_device::stz_zpx_3() {
  fetch();return; // fetch
}

// --- op trb_aba --- 
void m65c02_device::trb_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::trb_aba_1;return; // READ
}

void m65c02_device::trb_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::trb_aba_2;return; // READ
}

void m65c02_device::trb_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::trb_aba_3;return; // READ
}

void m65c02_device::trb_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::trb_aba_4;return; // READ
}

void m65c02_device::trb_aba_4() {
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 &= ~A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::trb_aba_5;return; // WRITE
}

void m65c02_device::trb_aba_5() {
  fetch();return; // fetch
}

// --- op trb_zpg --- 
void m65c02_device::trb_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::trb_zpg_1;return; // READ
}

void m65c02_device::trb_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::trb_zpg_2;return; // READ
}

void m65c02_device::trb_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::trb_zpg_3;return; // READ
}

void m65c02_device::trb_zpg_3() {
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 &= ~A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::trb_zpg_4;return; // WRITE
}

void m65c02_device::trb_zpg_4() {
  fetch();return; // fetch
}

// --- op tsb_aba --- 
void m65c02_device::tsb_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::tsb_aba_1;return; // READ
}

void m65c02_device::tsb_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::tsb_aba_2;return; // READ
}

void m65c02_device::tsb_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::tsb_aba_3;return; // READ
}

void m65c02_device::tsb_aba_3() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::tsb_aba_4;return; // READ
}

void m65c02_device::tsb_aba_4() {
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 |= A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::tsb_aba_5;return; // WRITE
}

void m65c02_device::tsb_aba_5() {
  fetch();return; // fetch
}

// --- op tsb_zpg --- 
void m65c02_device::tsb_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65c02_device::tsb_zpg_1;return; // READ
}

void m65c02_device::tsb_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::tsb_zpg_2;return; // READ
}

void m65c02_device::tsb_zpg_2() {
  TMP2 = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65c02_device::tsb_zpg_3;return; // READ
}

void m65c02_device::tsb_zpg_3() {
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 |= A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65c02_device::tsb_zpg_4;return; // WRITE
}

void m65c02_device::tsb_zpg_4() {
  fetch();return; // fetch
}

// --- op wai_imp --- 
void m65c02_device::wai_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::wai_imp_1;return; // READ
}

void m65c02_device::wai_imp_1() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::wai_imp_2;return; // READ
}

void m65c02_device::wai_imp_2() {
  wai_imp_while_1();return;
}

void m65c02_device::wai_imp_while_1() {
  if (!!nmi_state && !irq_state) m65c02_device::wai_imp_whilenot_1();return;
  ADDR = PC;
  RNW = true;
  NextFn = &m65c02_device::wai_imp_3;return; // READ
}

void m65c02_device::wai_imp_whilenot_1() {
  fetch();return; // fetch
}

void m65c02_device::wai_imp_3() {
  wai_imp_while_1();return;
}

void m65c02_device::postfetch_int() {
  switch(IR) {
  case 0x00: brk_c_imp_0(); break;
  case 0x01: ora_idx_0(); break;
  case 0x02: nop_imm_0(); break;
  case 0x03: nop_c_imp_0(); break;
  case 0x04: tsb_zpg_0(); break;
  case 0x05: ora_zpg_0(); break;
  case 0x06: asl_c_zpg_0(); break;
  case 0x07: nop_c_imp_0(); break;
  case 0x08: php_imp_0(); break;
  case 0x09: ora_imm_0(); break;
  case 0x0a: asl_acc_0(); break;
  case 0x0b: nop_c_imp_0(); break;
  case 0x0c: tsb_aba_0(); break;
  case 0x0d: ora_aba_0(); break;
  case 0x0e: asl_c_aba_0(); break;
  case 0x0f: nop_c_imp_0(); break;
  case 0x10: bpl_rel_0(); break;
  case 0x11: ora_idy_0(); break;
  case 0x12: ora_zpi_0(); break;
  case 0x13: nop_c_imp_0(); break;
  case 0x14: trb_zpg_0(); break;
  case 0x15: ora_zpx_0(); break;
  case 0x16: asl_c_zpx_0(); break;
  case 0x17: nop_c_imp_0(); break;
  case 0x18: clc_imp_0(); break;
  case 0x19: ora_aby_0(); break;
  case 0x1a: inc_acc_0(); break;
  case 0x1b: nop_c_imp_0(); break;
  case 0x1c: trb_aba_0(); break;
  case 0x1d: ora_abx_0(); break;
  case 0x1e: asl_c_abx_0(); break;
  case 0x1f: nop_c_imp_0(); break;
  case 0x20: jsr_adr_0(); break;
  case 0x21: and_idx_0(); break;
  case 0x22: nop_imm_0(); break;
  case 0x23: nop_c_imp_0(); break;
  case 0x24: bit_zpg_0(); break;
  case 0x25: and_zpg_0(); break;
  case 0x26: rol_c_zpg_0(); break;
  case 0x27: nop_c_imp_0(); break;
  case 0x28: plp_imp_0(); break;
  case 0x29: and_imm_0(); break;
  case 0x2a: rol_acc_0(); break;
  case 0x2b: nop_c_imp_0(); break;
  case 0x2c: bit_aba_0(); break;
  case 0x2d: and_aba_0(); break;
  case 0x2e: rol_c_aba_0(); break;
  case 0x2f: nop_c_imp_0(); break;
  case 0x30: bmi_rel_0(); break;
  case 0x31: and_idy_0(); break;
  case 0x32: and_zpi_0(); break;
  case 0x33: nop_c_imp_0(); break;
  case 0x34: bit_zpx_0(); break;
  case 0x35: and_zpx_0(); break;
  case 0x36: rol_c_zpx_0(); break;
  case 0x37: nop_c_imp_0(); break;
  case 0x38: sec_imp_0(); break;
  case 0x39: and_aby_0(); break;
  case 0x3a: dec_acc_0(); break;
  case 0x3b: nop_c_imp_0(); break;
  case 0x3c: bit_abx_0(); break;
  case 0x3d: and_abx_0(); break;
  case 0x3e: rol_c_abx_0(); break;
  case 0x3f: nop_c_imp_0(); break;
  case 0x40: rti_imp_0(); break;
  case 0x41: eor_idx_0(); break;
  case 0x42: nop_imm_0(); break;
  case 0x43: nop_c_imp_0(); break;
  case 0x44: nop_zpg_0(); break;
  case 0x45: eor_zpg_0(); break;
  case 0x46: lsr_c_zpg_0(); break;
  case 0x47: nop_c_imp_0(); break;
  case 0x48: pha_imp_0(); break;
  case 0x49: eor_imm_0(); break;
  case 0x4a: lsr_acc_0(); break;
  case 0x4b: nop_c_imp_0(); break;
  case 0x4c: jmp_adr_0(); break;
  case 0x4d: eor_aba_0(); break;
  case 0x4e: lsr_c_aba_0(); break;
  case 0x4f: nop_c_imp_0(); break;
  case 0x50: bvc_rel_0(); break;
  case 0x51: eor_idy_0(); break;
  case 0x52: eor_zpi_0(); break;
  case 0x53: nop_c_imp_0(); break;
  case 0x54: nop_zpx_0(); break;
  case 0x55: eor_zpx_0(); break;
  case 0x56: lsr_c_zpx_0(); break;
  case 0x57: nop_c_imp_0(); break;
  case 0x58: cli_imp_0(); break;
  case 0x59: eor_aby_0(); break;
  case 0x5a: phy_imp_0(); break;
  case 0x5b: nop_c_imp_0(); break;
  case 0x5c: nop_c_aba_0(); break;
  case 0x5d: eor_abx_0(); break;
  case 0x5e: lsr_c_abx_0(); break;
  case 0x5f: nop_c_imp_0(); break;
  case 0x60: rts_imp_0(); break;
  case 0x61: adc_c_idx_0(); break;
  case 0x62: nop_imm_0(); break;
  case 0x63: nop_c_imp_0(); break;
  case 0x64: stz_zpg_0(); break;
  case 0x65: adc_c_zpg_0(); break;
  case 0x66: ror_c_zpg_0(); break;
  case 0x67: nop_c_imp_0(); break;
  case 0x68: pla_imp_0(); break;
  case 0x69: adc_c_imm_0(); break;
  case 0x6a: ror_acc_0(); break;
  case 0x6b: nop_c_imp_0(); break;
  case 0x6c: jmp_c_ind_0(); break;
  case 0x6d: adc_c_aba_0(); break;
  case 0x6e: ror_c_aba_0(); break;
  case 0x6f: nop_c_imp_0(); break;
  case 0x70: bvs_rel_0(); break;
  case 0x71: adc_c_idy_0(); break;
  case 0x72: adc_c_zpi_0(); break;
  case 0x73: nop_c_imp_0(); break;
  case 0x74: stz_zpx_0(); break;
  case 0x75: adc_c_zpx_0(); break;
  case 0x76: ror_c_zpx_0(); break;
  case 0x77: nop_c_imp_0(); break;
  case 0x78: sei_imp_0(); break;
  case 0x79: adc_c_aby_0(); break;
  case 0x7a: ply_imp_0(); break;
  case 0x7b: nop_c_imp_0(); break;
  case 0x7c: jmp_iax_0(); break;
  case 0x7d: adc_c_abx_0(); break;
  case 0x7e: ror_c_abx_0(); break;
  case 0x7f: nop_c_imp_0(); break;
  case 0x80: bra_rel_0(); break;
  case 0x81: sta_idx_0(); break;
  case 0x82: nop_imm_0(); break;
  case 0x83: nop_c_imp_0(); break;
  case 0x84: sty_zpg_0(); break;
  case 0x85: sta_zpg_0(); break;
  case 0x86: stx_zpg_0(); break;
  case 0x87: nop_c_imp_0(); break;
  case 0x88: dey_imp_0(); break;
  case 0x89: bit_imm_0(); break;
  case 0x8a: txa_imp_0(); break;
  case 0x8b: nop_c_imp_0(); break;
  case 0x8c: sty_aba_0(); break;
  case 0x8d: sta_aba_0(); break;
  case 0x8e: stx_aba_0(); break;
  case 0x8f: nop_c_imp_0(); break;
  case 0x90: bcc_rel_0(); break;
  case 0x91: sta_idy_0(); break;
  case 0x92: sta_zpi_0(); break;
  case 0x93: nop_c_imp_0(); break;
  case 0x94: sty_zpx_0(); break;
  case 0x95: sta_zpx_0(); break;
  case 0x96: stx_zpy_0(); break;
  case 0x97: nop_c_imp_0(); break;
  case 0x98: tya_imp_0(); break;
  case 0x99: sta_aby_0(); break;
  case 0x9a: txs_imp_0(); break;
  case 0x9b: nop_c_imp_0(); break;
  case 0x9c: stz_aba_0(); break;
  case 0x9d: sta_abx_0(); break;
  case 0x9e: stz_abx_0(); break;
  case 0x9f: nop_c_imp_0(); break;
  case 0xa0: ldy_imm_0(); break;
  case 0xa1: lda_idx_0(); break;
  case 0xa2: ldx_imm_0(); break;
  case 0xa3: nop_c_imp_0(); break;
  case 0xa4: ldy_zpg_0(); break;
  case 0xa5: lda_zpg_0(); break;
  case 0xa6: ldx_zpg_0(); break;
  case 0xa7: nop_c_imp_0(); break;
  case 0xa8: tay_imp_0(); break;
  case 0xa9: lda_imm_0(); break;
  case 0xaa: tax_imp_0(); break;
  case 0xab: nop_c_imp_0(); break;
  case 0xac: ldy_aba_0(); break;
  case 0xad: lda_aba_0(); break;
  case 0xae: ldx_aba_0(); break;
  case 0xaf: nop_c_imp_0(); break;
  case 0xb0: bcs_rel_0(); break;
  case 0xb1: lda_idy_0(); break;
  case 0xb2: lda_zpi_0(); break;
  case 0xb3: nop_c_imp_0(); break;
  case 0xb4: ldy_zpx_0(); break;
  case 0xb5: lda_zpx_0(); break;
  case 0xb6: ldx_zpy_0(); break;
  case 0xb7: nop_c_imp_0(); break;
  case 0xb8: clv_imp_0(); break;
  case 0xb9: lda_aby_0(); break;
  case 0xba: tsx_imp_0(); break;
  case 0xbb: nop_c_imp_0(); break;
  case 0xbc: ldy_abx_0(); break;
  case 0xbd: lda_abx_0(); break;
  case 0xbe: ldx_aby_0(); break;
  case 0xbf: nop_c_imp_0(); break;
  case 0xc0: cpy_imm_0(); break;
  case 0xc1: cmp_idx_0(); break;
  case 0xc2: nop_imm_0(); break;
  case 0xc3: nop_c_imp_0(); break;
  case 0xc4: cpy_zpg_0(); break;
  case 0xc5: cmp_zpg_0(); break;
  case 0xc6: dec_c_zpg_0(); break;
  case 0xc7: nop_c_imp_0(); break;
  case 0xc8: iny_imp_0(); break;
  case 0xc9: cmp_imm_0(); break;
  case 0xca: dex_imp_0(); break;
  case 0xcb: nop_c_imp_0(); break;
  case 0xcc: cpy_aba_0(); break;
  case 0xcd: cmp_aba_0(); break;
  case 0xce: dec_c_aba_0(); break;
  case 0xcf: nop_c_imp_0(); break;
  case 0xd0: bne_rel_0(); break;
  case 0xd1: cmp_idy_0(); break;
  case 0xd2: cmp_zpi_0(); break;
  case 0xd3: nop_c_imp_0(); break;
  case 0xd4: nop_zpx_0(); break;
  case 0xd5: cmp_zpx_0(); break;
  case 0xd6: dec_c_zpx_0(); break;
  case 0xd7: nop_c_imp_0(); break;
  case 0xd8: cld_imp_0(); break;
  case 0xd9: cmp_aby_0(); break;
  case 0xda: phx_imp_0(); break;
  case 0xdb: nop_c_imp_0(); break;
  case 0xdc: nop_c_abx_0(); break;
  case 0xdd: cmp_abx_0(); break;
  case 0xde: dec_c_abx_0(); break;
  case 0xdf: nop_c_imp_0(); break;
  case 0xe0: cpx_imm_0(); break;
  case 0xe1: sbc_c_idx_0(); break;
  case 0xe2: nop_imm_0(); break;
  case 0xe3: nop_c_imp_0(); break;
  case 0xe4: cpx_zpg_0(); break;
  case 0xe5: sbc_c_zpg_0(); break;
  case 0xe6: inc_c_zpg_0(); break;
  case 0xe7: nop_c_imp_0(); break;
  case 0xe8: inx_imp_0(); break;
  case 0xe9: sbc_c_imm_0(); break;
  case 0xea: nop_imp_0(); break;
  case 0xeb: nop_c_imp_0(); break;
  case 0xec: cpx_aba_0(); break;
  case 0xed: sbc_c_aba_0(); break;
  case 0xee: inc_c_aba_0(); break;
  case 0xef: nop_c_imp_0(); break;
  case 0xf0: beq_rel_0(); break;
  case 0xf1: sbc_c_idy_0(); break;
  case 0xf2: sbc_c_zpi_0(); break;
  case 0xf3: nop_c_imp_0(); break;
  case 0xf4: nop_zpx_0(); break;
  case 0xf5: sbc_c_zpx_0(); break;
  case 0xf6: inc_c_zpx_0(); break;
  case 0xf7: nop_c_imp_0(); break;
  case 0xf8: sed_imp_0(); break;
  case 0xf9: sbc_c_aby_0(); break;
  case 0xfa: plx_imp_0(); break;
  case 0xfb: nop_c_imp_0(); break;
  case 0xfc: nop_c_abx_0(); break;
  case 0xfd: sbc_c_abx_0(); break;
  case 0xfe: inc_c_abx_0(); break;
  case 0xff: nop_c_imp_0(); break;
  default:   reset_c_0(); break;
  }
}

