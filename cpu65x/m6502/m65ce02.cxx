// This file has been automatically produced by makehxx.pl
// do not edit it.
// from file(s) dm65ce02.lst D:\Users\Dominic\Documents\GitHub\beebem-windows\cpu65x\m6502\om65ce02.lst
#include "m65ce02.h"
// --- op adc_ce_aba --- 
void m65ce02_device::adc_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_aba_1;return; // READ
}

void m65ce02_device::adc_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_aba_2;return; // READ
}

void m65ce02_device::adc_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_aba_3;return; // READ
}

void m65ce02_device::adc_ce_aba_3() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_abx --- 
void m65ce02_device::adc_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_abx_1;return; // READ
}

void m65ce02_device::adc_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_abx_2;return; // READ
}

void m65ce02_device::adc_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_abx_3;return; // READ
}

void m65ce02_device::adc_ce_abx_3() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_aby --- 
void m65ce02_device::adc_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_aby_1;return; // READ
}

void m65ce02_device::adc_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_aby_2;return; // READ
}

void m65ce02_device::adc_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_aby_3;return; // READ
}

void m65ce02_device::adc_ce_aby_3() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_idx --- 
void m65ce02_device::adc_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idx_1;return; // READ
}

void m65ce02_device::adc_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idx_2;return; // READ
}

void m65ce02_device::adc_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idx_3;return; // READ
}

void m65ce02_device::adc_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idx_4;return; // READ
}

void m65ce02_device::adc_ce_idx_4() {
  do_adc(DAT);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_idy --- 
void m65ce02_device::adc_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idy_1;return; // READ
}

void m65ce02_device::adc_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idy_2;return; // READ
}

void m65ce02_device::adc_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idy_3;return; // READ
}

void m65ce02_device::adc_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_idy_4;return; // READ
}

void m65ce02_device::adc_ce_idy_4() {
  do_adc(DAT);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_imm --- 
void m65ce02_device::adc_ce_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_imm_1;return; // READ
}

void m65ce02_device::adc_ce_imm_1() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_zpg --- 
void m65ce02_device::adc_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_zpg_1;return; // READ
}

void m65ce02_device::adc_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_zpg_2;return; // READ
}

void m65ce02_device::adc_ce_zpg_2() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_ce_zpx --- 
void m65ce02_device::adc_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_zpx_1;return; // READ
}

void m65ce02_device::adc_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::adc_ce_zpx_2;return; // READ
}

void m65ce02_device::adc_ce_zpx_2() {
  TMP = DAT;
  do_adc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op adc_idz --- 
void m65ce02_device::adc_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::adc_idz_1;return; // READ
}

void m65ce02_device::adc_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::adc_idz_2;return; // READ
}

void m65ce02_device::adc_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::adc_idz_3;return; // READ
}

void m65ce02_device::adc_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::adc_idz_4;return; // READ
}

void m65ce02_device::adc_idz_4() {
  do_adc(DAT);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op and_ce_abx --- 
void m65ce02_device::and_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_abx_1;return; // READ
}

void m65ce02_device::and_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_abx_2;return; // READ
}

void m65ce02_device::and_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_abx_3;return; // READ
}

void m65ce02_device::and_ce_abx_3() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_ce_aby --- 
void m65ce02_device::and_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_aby_1;return; // READ
}

void m65ce02_device::and_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_aby_2;return; // READ
}

void m65ce02_device::and_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_aby_3;return; // READ
}

void m65ce02_device::and_ce_aby_3() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_ce_idx --- 
void m65ce02_device::and_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idx_1;return; // READ
}

void m65ce02_device::and_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idx_2;return; // READ
}

void m65ce02_device::and_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idx_3;return; // READ
}

void m65ce02_device::and_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idx_4;return; // READ
}

void m65ce02_device::and_ce_idx_4() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_ce_idy --- 
void m65ce02_device::and_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idy_1;return; // READ
}

void m65ce02_device::and_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idy_2;return; // READ
}

void m65ce02_device::and_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idy_3;return; // READ
}

void m65ce02_device::and_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_idy_4;return; // READ
}

void m65ce02_device::and_ce_idy_4() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_ce_zpg --- 
void m65ce02_device::and_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_zpg_1;return; // READ
}

void m65ce02_device::and_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_zpg_2;return; // READ
}

void m65ce02_device::and_ce_zpg_2() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_ce_zpx --- 
void m65ce02_device::and_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_ce_zpx_1;return; // READ
}

void m65ce02_device::and_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::and_ce_zpx_2;return; // READ
}

void m65ce02_device::and_ce_zpx_2() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op and_idz --- 
void m65ce02_device::and_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::and_idz_1;return; // READ
}

void m65ce02_device::and_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::and_idz_2;return; // READ
}

void m65ce02_device::and_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::and_idz_3;return; // READ
}

void m65ce02_device::and_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::and_idz_4;return; // READ
}

void m65ce02_device::and_idz_4() {
  A &= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op asl_ce_aba --- 
void m65ce02_device::asl_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_aba_1;return; // READ
}

void m65ce02_device::asl_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_aba_2;return; // READ
}

void m65ce02_device::asl_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_aba_3;return; // READ
}

void m65ce02_device::asl_ce_aba_3() {
  TMP2 = DAT;
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::asl_ce_aba_4;return; // WRITE
}

void m65ce02_device::asl_ce_aba_4() {
  fetch();return; // fetch
}

// --- op asl_ce_abx --- 
void m65ce02_device::asl_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_abx_1;return; // READ
}

void m65ce02_device::asl_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_abx_2;return; // READ
}

void m65ce02_device::asl_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_abx_3;return; // READ
}

void m65ce02_device::asl_ce_abx_3() {
  TMP2 = DAT;
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::asl_ce_abx_4;return; // WRITE
}

void m65ce02_device::asl_ce_abx_4() {
  fetch();return; // fetch
}

// --- op asl_ce_acc --- 
void m65ce02_device::asl_ce_acc_0() {
  A = do_asl(A);
  fetch();return; // fetch
}

// --- op asl_ce_zpg --- 
void m65ce02_device::asl_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_zpg_1;return; // READ
}

void m65ce02_device::asl_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_zpg_2;return; // READ
}

void m65ce02_device::asl_ce_zpg_2() {
  TMP2 = DAT;
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::asl_ce_zpg_3;return; // WRITE
}

void m65ce02_device::asl_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op asl_ce_zpx --- 
void m65ce02_device::asl_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_zpx_1;return; // READ
}

void m65ce02_device::asl_ce_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asl_ce_zpx_2;return; // READ
}

void m65ce02_device::asl_ce_zpx_2() {
  TMP2 = DAT;
  TMP2 = do_asl(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::asl_ce_zpx_3;return; // WRITE
}

void m65ce02_device::asl_ce_zpx_3() {
  fetch();return; // fetch
}

// --- op asr_acc --- 
void m65ce02_device::asr_acc_0() {
  A = do_asr(A);
  fetch();return; // fetch
}

// --- op asr_zpg --- 
void m65ce02_device::asr_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asr_zpg_1;return; // READ
}

void m65ce02_device::asr_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asr_zpg_2;return; // READ
}

void m65ce02_device::asr_zpg_2() {
  TMP2 = DAT;
  TMP2 = do_asr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::asr_zpg_3;return; // WRITE
}

void m65ce02_device::asr_zpg_3() {
  fetch();return; // fetch
}

// --- op asr_zpx --- 
void m65ce02_device::asr_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asr_zpx_1;return; // READ
}

void m65ce02_device::asr_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asr_zpx_2;return; // READ
}

void m65ce02_device::asr_zpx_2() {
  TMP2 = DAT;
  TMP2 = do_asr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::asr_zpx_3;return; // WRITE
}

void m65ce02_device::asr_zpx_3() {
  fetch();return; // fetch
}

// --- op asw_aba --- 
void m65ce02_device::asw_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asw_aba_1;return; // READ
}

void m65ce02_device::asw_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::asw_aba_2;return; // READ
}

void m65ce02_device::asw_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::asw_aba_3;return; // READ
}

void m65ce02_device::asw_aba_3() {
  TMP3 = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::asw_aba_4;return; // READ
}

void m65ce02_device::asw_aba_4() {
  TMP3 = set_h(TMP3, DAT);
  P &= ~(F_C|F_N|F_Z);
  if (TMP3 & 0x8000) {
    P |= F_C;
  }
  TMP3 <<= 1;
  if (!TMP3) {
    P |= F_Z;
  } else {
    if (TMP3 & 0x8000) {
      P |= F_N;
    }
  }
  ADDR = TMP;
  DAT =  TMP3;
  RNW = false;
  NextFn = &m65ce02_device::asw_aba_5;return; // WRITE
}

void m65ce02_device::asw_aba_5() {
  ADDR = TMP;
  DAT =  TMP3 >> 8;
  RNW = false;
  NextFn = &m65ce02_device::asw_aba_6;return; // WRITE
}

void m65ce02_device::asw_aba_6() {
  fetch();return; // fetch
}

// --- op aug_iw3 --- 
void m65ce02_device::aug_iw3_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::aug_iw3_1;return; // READ
}

void m65ce02_device::aug_iw3_1() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::aug_iw3_2;return; // READ
}

void m65ce02_device::aug_iw3_2() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::aug_iw3_3;return; // READ
}

void m65ce02_device::aug_iw3_3() {
  fetch();return; // fetch
}

// --- op bbr_ce_zpb --- 
void m65ce02_device::bbr_ce_zpb_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bbr_ce_zpb_1;return; // READ
}

void m65ce02_device::bbr_ce_zpb_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::bbr_ce_zpb_2;return; // READ
}

void m65ce02_device::bbr_ce_zpb_2() {
  TMP2 = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bbr_ce_zpb_3;return; // READ
}

void m65ce02_device::bbr_ce_zpb_3() {
  TMP = DAT;
  if (!(TMP2 & (1 << ((IR >> 4) & 7)))) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bbs_ce_zpb --- 
void m65ce02_device::bbs_ce_zpb_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bbs_ce_zpb_1;return; // READ
}

void m65ce02_device::bbs_ce_zpb_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::bbs_ce_zpb_2;return; // READ
}

void m65ce02_device::bbs_ce_zpb_2() {
  TMP2 = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bbs_ce_zpb_3;return; // READ
}

void m65ce02_device::bbs_ce_zpb_3() {
  TMP = DAT;
  if (TMP2 & (1 << ((IR >> 4) & 7))) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bcc_ce_rel --- 
void m65ce02_device::bcc_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bcc_ce_rel_1;return; // READ
}

void m65ce02_device::bcc_ce_rel_1() {
  TMP = DAT;
  if (!(P & F_C)) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bcc_rw2 --- 
void m65ce02_device::bcc_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bcc_rw2_1;return; // READ
}

void m65ce02_device::bcc_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bcc_rw2_2;return; // READ
}

void m65ce02_device::bcc_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (!(P & F_C)) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op bcs_ce_rel --- 
void m65ce02_device::bcs_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bcs_ce_rel_1;return; // READ
}

void m65ce02_device::bcs_ce_rel_1() {
  TMP = DAT;
  if (P & F_C) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bcs_rw2 --- 
void m65ce02_device::bcs_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bcs_rw2_1;return; // READ
}

void m65ce02_device::bcs_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bcs_rw2_2;return; // READ
}

void m65ce02_device::bcs_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (P & F_C) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op beq_ce_rel --- 
void m65ce02_device::beq_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::beq_ce_rel_1;return; // READ
}

void m65ce02_device::beq_ce_rel_1() {
  TMP = DAT;
  if (P & F_Z) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op beq_rw2 --- 
void m65ce02_device::beq_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::beq_rw2_1;return; // READ
}

void m65ce02_device::beq_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::beq_rw2_2;return; // READ
}

void m65ce02_device::beq_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (P & F_Z) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op bit_ce_abx --- 
void m65ce02_device::bit_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_abx_1;return; // READ
}

void m65ce02_device::bit_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_abx_2;return; // READ
}

void m65ce02_device::bit_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_abx_3;return; // READ
}

void m65ce02_device::bit_ce_abx_3() {
  do_bit(DAT);
  fetch();return; // fetch
}

// --- op bit_ce_imm --- 
void m65ce02_device::bit_ce_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_imm_1;return; // READ
}

void m65ce02_device::bit_ce_imm_1() {
  TMP = DAT;
  do_bit(TMP);
  fetch();return; // fetch
}

// --- op bit_ce_zpg --- 
void m65ce02_device::bit_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_zpg_1;return; // READ
}

void m65ce02_device::bit_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_zpg_2;return; // READ
}

void m65ce02_device::bit_ce_zpg_2() {
  do_bit(DAT);
  fetch();return; // fetch
}

// --- op bit_ce_zpx --- 
void m65ce02_device::bit_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_zpx_1;return; // READ
}

void m65ce02_device::bit_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::bit_ce_zpx_2;return; // READ
}

void m65ce02_device::bit_ce_zpx_2() {
  TMP = DAT;
  do_bit(TMP);
  fetch();return; // fetch
}

// --- op bmi_ce_rel --- 
void m65ce02_device::bmi_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bmi_ce_rel_1;return; // READ
}

void m65ce02_device::bmi_ce_rel_1() {
  TMP = DAT;
  if (P & F_N) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bmi_rw2 --- 
void m65ce02_device::bmi_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bmi_rw2_1;return; // READ
}

void m65ce02_device::bmi_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bmi_rw2_2;return; // READ
}

void m65ce02_device::bmi_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (P & F_N) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op bne_ce_rel --- 
void m65ce02_device::bne_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bne_ce_rel_1;return; // READ
}

void m65ce02_device::bne_ce_rel_1() {
  TMP = DAT;
  if (!(P & F_Z)) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bne_rw2 --- 
void m65ce02_device::bne_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bne_rw2_1;return; // READ
}

void m65ce02_device::bne_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bne_rw2_2;return; // READ
}

void m65ce02_device::bne_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (!(P & F_Z)) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op bpl_ce_rel --- 
void m65ce02_device::bpl_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bpl_ce_rel_1;return; // READ
}

void m65ce02_device::bpl_ce_rel_1() {
  TMP = DAT;
  if (!(P & F_N)) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bpl_rw2 --- 
void m65ce02_device::bpl_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bpl_rw2_1;return; // READ
}

void m65ce02_device::bpl_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bpl_rw2_2;return; // READ
}

void m65ce02_device::bpl_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (!(P & F_N)) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op bra_ce_rel --- 
void m65ce02_device::bra_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bra_ce_rel_1;return; // READ
}

void m65ce02_device::bra_ce_rel_1() {
  TMP = DAT;
  PC += int8_t(TMP);
  fetch();return; // fetch
}

// --- op bra_rw2 --- 
void m65ce02_device::bra_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bra_rw2_1;return; // READ
}

void m65ce02_device::bra_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bra_rw2_2;return; // READ
}

void m65ce02_device::bra_rw2_2() {
  TMP = set_h(TMP, DAT);
  PC += TMP - 1;
  fetch();return; // fetch
}

// --- op brk_ce_imp --- 
void m65ce02_device::brk_ce_imp_0() {
  if (irq_taken) {
    ADDR = PC;
    RNW = true;
    NextFn = &m65ce02_device::brk_ce_imp_1;return; // READ
  } else {
    ADDR = PC++;
    RNW = true;
    NextFn = &m65ce02_device::brk_ce_imp_2;return; // READ
  }
  ADDR = SP;
  DAT =  PC >> 8;
  RNW = false;
  NextFn = &m65ce02_device::brk_ce_imp_3;return; // WRITE
}

void m65ce02_device::brk_ce_imp_1() {
    ADDR = SP;
    DAT =  PC >> 8;
    RNW = false;
    NextFn = &m65ce02_device::brk_ce_imp_3;return; // WRITE
}

void m65ce02_device::brk_ce_imp_2() {
    ADDR = SP;
    DAT =  PC >> 8;
    RNW = false;
    NextFn = &m65ce02_device::brk_ce_imp_3;return; // WRITE
}

void m65ce02_device::brk_ce_imp_3() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m65ce02_device::brk_ce_imp_4;return; // WRITE
}

void m65ce02_device::brk_ce_imp_4() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  irq_taken || nmi_state ? P & ~F_B : P;
  RNW = false;
  NextFn = &m65ce02_device::brk_ce_imp_5;return; // WRITE
}

void m65ce02_device::brk_ce_imp_5() {
  dec_SP_ce();
  if (nmi_state) {
    ADDR = 0xfffa;
    RNW = true;
    NextFn = &m65ce02_device::brk_ce_imp_6;return; // READ
  } else {
    ADDR = 0xfffe;
    RNW = true;
    NextFn = &m65ce02_device::brk_ce_imp_8;return; // READ
  }
  irq_taken = false;
  P = (P | F_I) & ~F_D;
  fetch();return; // fetch
}

void m65ce02_device::brk_ce_imp_6() {
    PC = DAT;
    ADDR = 0xfffb;
    RNW = true;
    NextFn = &m65ce02_device::brk_ce_imp_7;return; // READ
}

void m65ce02_device::brk_ce_imp_8() {
    PC = DAT;
    ADDR = 0xffff;
    RNW = true;
    NextFn = &m65ce02_device::brk_ce_imp_9;return; // READ
}

void m65ce02_device::brk_ce_imp_7() {
    PC = set_h(PC, DAT);
    nmi_state = false;
    irq_taken = false;
    P = (P | F_I) & ~F_D;
    fetch();return; // fetch
}

void m65ce02_device::brk_ce_imp_9() {
    PC = set_h(PC, DAT);
    irq_taken = false;
    P = (P | F_I) & ~F_D;
    fetch();return; // fetch
}

// --- op bsr_rw2 --- 
void m65ce02_device::bsr_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bsr_rw2_1;return; // READ
}

void m65ce02_device::bsr_rw2_1() {
  TMP = DAT;
  ADDR = SP;
  DAT =  PC>>8;
  RNW = false;
  NextFn = &m65ce02_device::bsr_rw2_2;return; // WRITE
}

void m65ce02_device::bsr_rw2_2() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m65ce02_device::bsr_rw2_3;return; // WRITE
}

void m65ce02_device::bsr_rw2_3() {
  dec_SP_ce();
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bsr_rw2_4;return; // READ
}

void m65ce02_device::bsr_rw2_4() {
  TMP = set_h(TMP, DAT);
  PC += TMP-1;
  fetch();return; // fetch
}

// --- op bvc_ce_rel --- 
void m65ce02_device::bvc_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bvc_ce_rel_1;return; // READ
}

void m65ce02_device::bvc_ce_rel_1() {
  TMP = DAT;
  if (!(P & F_V)) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bvc_rw2 --- 
void m65ce02_device::bvc_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bvc_rw2_1;return; // READ
}

void m65ce02_device::bvc_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bvc_rw2_2;return; // READ
}

void m65ce02_device::bvc_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (!(P & F_V)) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op bvs_ce_rel --- 
void m65ce02_device::bvs_ce_rel_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bvs_ce_rel_1;return; // READ
}

void m65ce02_device::bvs_ce_rel_1() {
  TMP = DAT;
  if (P & F_V) {
    PC += int8_t(TMP);
  }
  fetch();return; // fetch
}

// --- op bvs_rw2 --- 
void m65ce02_device::bvs_rw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bvs_rw2_1;return; // READ
}

void m65ce02_device::bvs_rw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::bvs_rw2_2;return; // READ
}

void m65ce02_device::bvs_rw2_2() {
  TMP = set_h(TMP, DAT);
  if (P & F_V) {
    PC += TMP-1;
  }
  fetch();return; // fetch
}

// --- op clc_ce_imp --- 
void m65ce02_device::clc_ce_imp_0() {
  P &= ~F_C;
  fetch();return; // fetch
}

// --- op cld_ce_imp --- 
void m65ce02_device::cld_ce_imp_0() {
  P &= ~F_D;
  fetch();return; // fetch
}

// --- op cle_imp --- 
void m65ce02_device::cle_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::cle_imp_1;return; // READ
}

void m65ce02_device::cle_imp_1() {
  P &= ~F_E;
  logerror("CLE\n");
  fetch();return; // fetch
}

// --- op cli_ce_imp --- 
void m65ce02_device::cli_ce_imp_0() {
  PrefetchNextFn = &m65ce02_device::cli_ce_imp_1;
  prefetch();return; // prefetch
}

void m65ce02_device::cli_ce_imp_1() {
  P &= ~F_I;
  postfetch();return; // postfetch
}

// --- op clv_ce_imp --- 
void m65ce02_device::clv_ce_imp_0() {
  P &= ~F_V;
  fetch();return; // fetch
}

// --- op cmp_ce_abx --- 
void m65ce02_device::cmp_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_abx_1;return; // READ
}

void m65ce02_device::cmp_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_abx_2;return; // READ
}

void m65ce02_device::cmp_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_abx_3;return; // READ
}

void m65ce02_device::cmp_ce_abx_3() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_ce_aby --- 
void m65ce02_device::cmp_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_aby_1;return; // READ
}

void m65ce02_device::cmp_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_aby_2;return; // READ
}

void m65ce02_device::cmp_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_aby_3;return; // READ
}

void m65ce02_device::cmp_ce_aby_3() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_ce_idx --- 
void m65ce02_device::cmp_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idx_1;return; // READ
}

void m65ce02_device::cmp_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idx_2;return; // READ
}

void m65ce02_device::cmp_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idx_3;return; // READ
}

void m65ce02_device::cmp_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idx_4;return; // READ
}

void m65ce02_device::cmp_ce_idx_4() {
  do_cmp(A, DAT);
  fetch();return; // fetch
}

// --- op cmp_ce_idy --- 
void m65ce02_device::cmp_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idy_1;return; // READ
}

void m65ce02_device::cmp_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idy_2;return; // READ
}

void m65ce02_device::cmp_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idy_3;return; // READ
}

void m65ce02_device::cmp_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_idy_4;return; // READ
}

void m65ce02_device::cmp_ce_idy_4() {
  do_cmp(A, DAT);
  fetch();return; // fetch
}

// --- op cmp_ce_zpg --- 
void m65ce02_device::cmp_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_zpg_1;return; // READ
}

void m65ce02_device::cmp_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_zpg_2;return; // READ
}

void m65ce02_device::cmp_ce_zpg_2() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_ce_zpx --- 
void m65ce02_device::cmp_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_zpx_1;return; // READ
}

void m65ce02_device::cmp_ce_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_zpx_2;return; // READ
}

void m65ce02_device::cmp_ce_zpx_2() {
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::cmp_ce_zpx_3;return; // READ
}

void m65ce02_device::cmp_ce_zpx_3() {
  TMP = DAT;
  do_cmp(A, TMP);
  fetch();return; // fetch
}

// --- op cmp_idz --- 
void m65ce02_device::cmp_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cmp_idz_1;return; // READ
}

void m65ce02_device::cmp_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::cmp_idz_2;return; // READ
}

void m65ce02_device::cmp_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::cmp_idz_3;return; // READ
}

void m65ce02_device::cmp_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::cmp_idz_4;return; // READ
}

void m65ce02_device::cmp_idz_4() {
  do_cmp(A, DAT);
  fetch();return; // fetch
}

// --- op cpx_ce_zpg --- 
void m65ce02_device::cpx_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cpx_ce_zpg_1;return; // READ
}

void m65ce02_device::cpx_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::cpx_ce_zpg_2;return; // READ
}

void m65ce02_device::cpx_ce_zpg_2() {
  TMP = DAT;
  do_cmp(X, TMP);
  fetch();return; // fetch
}

// --- op cpy_ce_zpg --- 
void m65ce02_device::cpy_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cpy_ce_zpg_1;return; // READ
}

void m65ce02_device::cpy_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::cpy_ce_zpg_2;return; // READ
}

void m65ce02_device::cpy_ce_zpg_2() {
  TMP = DAT;
  do_cmp(Y, TMP);
  fetch();return; // fetch
}

// --- op cpz_aba --- 
void m65ce02_device::cpz_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cpz_aba_1;return; // READ
}

void m65ce02_device::cpz_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cpz_aba_2;return; // READ
}

void m65ce02_device::cpz_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::cpz_aba_3;return; // READ
}

void m65ce02_device::cpz_aba_3() {
  TMP = DAT;
  do_cmp(Z, TMP);
  fetch();return; // fetch
}

// --- op cpz_imm --- 
void m65ce02_device::cpz_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cpz_imm_1;return; // READ
}

void m65ce02_device::cpz_imm_1() {
  TMP = DAT;
  do_cmp(Z, TMP);
  fetch();return; // fetch
}

// --- op cpz_zpg --- 
void m65ce02_device::cpz_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::cpz_zpg_1;return; // READ
}

void m65ce02_device::cpz_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::cpz_zpg_2;return; // READ
}

void m65ce02_device::cpz_zpg_2() {
  TMP = DAT;
  do_cmp(Z, TMP);
  fetch();return; // fetch
}

// --- op dec_ce_aba --- 
void m65ce02_device::dec_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_aba_1;return; // READ
}

void m65ce02_device::dec_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_aba_2;return; // READ
}

void m65ce02_device::dec_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_aba_3;return; // READ
}

void m65ce02_device::dec_ce_aba_3() {
  TMP2 = DAT;
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::dec_ce_aba_4;return; // WRITE
}

void m65ce02_device::dec_ce_aba_4() {
  fetch();return; // fetch
}

// --- op dec_ce_abx --- 
void m65ce02_device::dec_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_abx_1;return; // READ
}

void m65ce02_device::dec_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_abx_2;return; // READ
}

void m65ce02_device::dec_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_abx_3;return; // READ
}

void m65ce02_device::dec_ce_abx_3() {
  TMP2 = DAT;
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::dec_ce_abx_4;return; // WRITE
}

void m65ce02_device::dec_ce_abx_4() {
  fetch();return; // fetch
}

// --- op dec_ce_acc --- 
void m65ce02_device::dec_ce_acc_0() {
  A--;
  set_nz(A);
  fetch();return; // fetch
}

// --- op dec_ce_zpg --- 
void m65ce02_device::dec_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_zpg_1;return; // READ
}

void m65ce02_device::dec_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_zpg_2;return; // READ
}

void m65ce02_device::dec_ce_zpg_2() {
  TMP2 = DAT;
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::dec_ce_zpg_3;return; // WRITE
}

void m65ce02_device::dec_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op dec_ce_zpx --- 
void m65ce02_device::dec_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_zpx_1;return; // READ
}

void m65ce02_device::dec_ce_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::dec_ce_zpx_2;return; // READ
}

void m65ce02_device::dec_ce_zpx_2() {
  TMP2 = DAT;
  TMP2--;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::dec_ce_zpx_3;return; // WRITE
}

void m65ce02_device::dec_ce_zpx_3() {
  fetch();return; // fetch
}

// --- op dew_zpg --- 
void m65ce02_device::dew_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::dew_zpg_1;return; // READ
}

void m65ce02_device::dew_zpg_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::dew_zpg_2;return; // READ
}

void m65ce02_device::dew_zpg_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::dew_zpg_3;return; // READ
}

void m65ce02_device::dew_zpg_3() {
  TMP = set_h(TMP, DAT);
  P &= ~(F_N|F_Z);
  TMP++;
  if (!TMP) {
    P |= F_Z;
  } else {
    if (TMP & 0x8000) {
      P |= F_N;
    }
  }
  TMP2++;
  ADDR = B|TMP2;
  DAT =  TMP;
  RNW = false;
  NextFn = &m65ce02_device::dew_zpg_4;return; // WRITE
}

void m65ce02_device::dew_zpg_4() {
  TMP2++;
  ADDR = B|TMP2;
  DAT =  TMP >> 8;
  RNW = false;
  NextFn = &m65ce02_device::dew_zpg_5;return; // WRITE
}

void m65ce02_device::dew_zpg_5() {
  fetch();return; // fetch
}

// --- op dex_ce_imp --- 
void m65ce02_device::dex_ce_imp_0() {
  X--;
  set_nz(X);
  fetch();return; // fetch
}

// --- op dey_ce_imp --- 
void m65ce02_device::dey_ce_imp_0() {
  Y--;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op dez_imp --- 
void m65ce02_device::dez_imp_0() {
  Z--;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op eor_ce_abx --- 
void m65ce02_device::eor_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_abx_1;return; // READ
}

void m65ce02_device::eor_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_abx_2;return; // READ
}

void m65ce02_device::eor_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_abx_3;return; // READ
}

void m65ce02_device::eor_ce_abx_3() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_ce_aby --- 
void m65ce02_device::eor_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_aby_1;return; // READ
}

void m65ce02_device::eor_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_aby_2;return; // READ
}

void m65ce02_device::eor_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_aby_3;return; // READ
}

void m65ce02_device::eor_ce_aby_3() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_ce_idx --- 
void m65ce02_device::eor_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idx_1;return; // READ
}

void m65ce02_device::eor_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idx_2;return; // READ
}

void m65ce02_device::eor_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idx_3;return; // READ
}

void m65ce02_device::eor_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idx_4;return; // READ
}

void m65ce02_device::eor_ce_idx_4() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_ce_idy --- 
void m65ce02_device::eor_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idy_1;return; // READ
}

void m65ce02_device::eor_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idy_2;return; // READ
}

void m65ce02_device::eor_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idy_3;return; // READ
}

void m65ce02_device::eor_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_idy_4;return; // READ
}

void m65ce02_device::eor_ce_idy_4() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_ce_zpg --- 
void m65ce02_device::eor_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_zpg_1;return; // READ
}

void m65ce02_device::eor_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_zpg_2;return; // READ
}

void m65ce02_device::eor_ce_zpg_2() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_ce_zpx --- 
void m65ce02_device::eor_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_zpx_1;return; // READ
}

void m65ce02_device::eor_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::eor_ce_zpx_2;return; // READ
}

void m65ce02_device::eor_ce_zpx_2() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op eor_idz --- 
void m65ce02_device::eor_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::eor_idz_1;return; // READ
}

void m65ce02_device::eor_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::eor_idz_2;return; // READ
}

void m65ce02_device::eor_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::eor_idz_3;return; // READ
}

void m65ce02_device::eor_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::eor_idz_4;return; // READ
}

void m65ce02_device::eor_idz_4() {
  A ^= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op inc_ce_aba --- 
void m65ce02_device::inc_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_aba_1;return; // READ
}

void m65ce02_device::inc_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_aba_2;return; // READ
}

void m65ce02_device::inc_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_aba_3;return; // READ
}

void m65ce02_device::inc_ce_aba_3() {
  TMP2 = DAT;
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::inc_ce_aba_4;return; // WRITE
}

void m65ce02_device::inc_ce_aba_4() {
  fetch();return; // fetch
}

// --- op inc_ce_abx --- 
void m65ce02_device::inc_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_abx_1;return; // READ
}

void m65ce02_device::inc_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_abx_2;return; // READ
}

void m65ce02_device::inc_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_abx_3;return; // READ
}

void m65ce02_device::inc_ce_abx_3() {
  TMP2 = DAT;
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::inc_ce_abx_4;return; // WRITE
}

void m65ce02_device::inc_ce_abx_4() {
  fetch();return; // fetch
}

// --- op inc_ce_acc --- 
void m65ce02_device::inc_ce_acc_0() {
  A++;
  set_nz(A);
  fetch();return; // fetch
}

// --- op inc_ce_zpg --- 
void m65ce02_device::inc_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_zpg_1;return; // READ
}

void m65ce02_device::inc_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_zpg_2;return; // READ
}

void m65ce02_device::inc_ce_zpg_2() {
  TMP2 = DAT;
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::inc_ce_zpg_3;return; // WRITE
}

void m65ce02_device::inc_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op inc_ce_zpx --- 
void m65ce02_device::inc_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_zpx_1;return; // READ
}

void m65ce02_device::inc_ce_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::inc_ce_zpx_2;return; // READ
}

void m65ce02_device::inc_ce_zpx_2() {
  TMP2 = DAT;
  TMP2++;
  set_nz(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::inc_ce_zpx_3;return; // WRITE
}

void m65ce02_device::inc_ce_zpx_3() {
  fetch();return; // fetch
}

// --- op inw_zpg --- 
void m65ce02_device::inw_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::inw_zpg_1;return; // READ
}

void m65ce02_device::inw_zpg_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::inw_zpg_2;return; // READ
}

void m65ce02_device::inw_zpg_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::inw_zpg_3;return; // READ
}

void m65ce02_device::inw_zpg_3() {
  TMP = set_h(TMP, DAT);
  P &= ~(F_N|F_Z);
  TMP++;
  if (!TMP) {
    P |= F_Z;
  } else {
    if (TMP & 0x8000) {
      P |= F_N;
    }
  }
  TMP2--;
  ADDR = B|TMP2;
  DAT =  TMP;
  RNW = false;
  NextFn = &m65ce02_device::inw_zpg_4;return; // WRITE
}

void m65ce02_device::inw_zpg_4() {
  TMP2++;
  ADDR = B|TMP2;
  DAT =  TMP >> 8;
  RNW = false;
  NextFn = &m65ce02_device::inw_zpg_5;return; // WRITE
}

void m65ce02_device::inw_zpg_5() {
  fetch();return; // fetch
}

// --- op inx_ce_imp --- 
void m65ce02_device::inx_ce_imp_0() {
  X++;
  set_nz(X);
  fetch();return; // fetch
}

// --- op iny_ce_imp --- 
void m65ce02_device::iny_ce_imp_0() {
  Y++;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op inz_imp --- 
void m65ce02_device::inz_imp_0() {
  Z++;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op jmp_ce_iax --- 
void m65ce02_device::jmp_ce_iax_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_iax_1;return; // READ
}

void m65ce02_device::jmp_ce_iax_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_iax_2;return; // READ
}

void m65ce02_device::jmp_ce_iax_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_iax_3;return; // READ
}

void m65ce02_device::jmp_ce_iax_3() {
  PC = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_iax_4;return; // READ
}

void m65ce02_device::jmp_ce_iax_4() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op jmp_ce_ind --- 
void m65ce02_device::jmp_ce_ind_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_ind_1;return; // READ
}

void m65ce02_device::jmp_ce_ind_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_ind_2;return; // READ
}

void m65ce02_device::jmp_ce_ind_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_ind_3;return; // READ
}

void m65ce02_device::jmp_ce_ind_3() {
  PC = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::jmp_ce_ind_4;return; // READ
}

void m65ce02_device::jmp_ce_ind_4() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op jsr_ce_adr --- 
void m65ce02_device::jsr_ce_adr_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jsr_ce_adr_1;return; // READ
}

void m65ce02_device::jsr_ce_adr_1() {
  TMP = DAT;
  ADDR = SP;
  DAT =  PC>>8;
  RNW = false;
  NextFn = &m65ce02_device::jsr_ce_adr_2;return; // WRITE
}

void m65ce02_device::jsr_ce_adr_2() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m65ce02_device::jsr_ce_adr_3;return; // WRITE
}

void m65ce02_device::jsr_ce_adr_3() {
  dec_SP_ce();
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jsr_ce_adr_4;return; // READ
}

void m65ce02_device::jsr_ce_adr_4() {
  TMP = set_h(TMP, DAT);
  PC = TMP;
  fetch();return; // fetch
}

// --- op jsr_iax --- 
void m65ce02_device::jsr_iax_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jsr_iax_1;return; // READ
}

void m65ce02_device::jsr_iax_1() {
  TMP = DAT;
  ADDR = SP;
  DAT =  PC>>8;
  RNW = false;
  NextFn = &m65ce02_device::jsr_iax_2;return; // WRITE
}

void m65ce02_device::jsr_iax_2() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m65ce02_device::jsr_iax_3;return; // WRITE
}

void m65ce02_device::jsr_iax_3() {
  dec_SP_ce();
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jsr_iax_4;return; // READ
}

void m65ce02_device::jsr_iax_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::jsr_iax_5;return; // READ
}

void m65ce02_device::jsr_iax_5() {
  PC = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::jsr_iax_6;return; // READ
}

void m65ce02_device::jsr_iax_6() {
  PC = set_h(PC, DAT);
  PC += X;
  fetch();return; // fetch
}

// --- op jsr_ind --- 
void m65ce02_device::jsr_ind_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jsr_ind_1;return; // READ
}

void m65ce02_device::jsr_ind_1() {
  TMP = DAT;
  ADDR = SP;
  DAT =  PC>>8;
  RNW = false;
  NextFn = &m65ce02_device::jsr_ind_2;return; // WRITE
}

void m65ce02_device::jsr_ind_2() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  PC;
  RNW = false;
  NextFn = &m65ce02_device::jsr_ind_3;return; // WRITE
}

void m65ce02_device::jsr_ind_3() {
  dec_SP_ce();
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::jsr_ind_4;return; // READ
}

void m65ce02_device::jsr_ind_4() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::jsr_ind_5;return; // READ
}

void m65ce02_device::jsr_ind_5() {
  PC = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::jsr_ind_6;return; // READ
}

void m65ce02_device::jsr_ind_6() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op lda_ce_abx --- 
void m65ce02_device::lda_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_abx_1;return; // READ
}

void m65ce02_device::lda_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_abx_2;return; // READ
}

void m65ce02_device::lda_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP + X;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_abx_3;return; // READ
}

void m65ce02_device::lda_ce_abx_3() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_ce_aby --- 
void m65ce02_device::lda_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_aby_1;return; // READ
}

void m65ce02_device::lda_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_aby_2;return; // READ
}

void m65ce02_device::lda_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP + Y;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_aby_3;return; // READ
}

void m65ce02_device::lda_ce_aby_3() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_ce_idx --- 
void m65ce02_device::lda_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idx_1;return; // READ
}

void m65ce02_device::lda_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idx_2;return; // READ
}

void m65ce02_device::lda_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idx_3;return; // READ
}

void m65ce02_device::lda_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idx_4;return; // READ
}

void m65ce02_device::lda_ce_idx_4() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_ce_idy --- 
void m65ce02_device::lda_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idy_1;return; // READ
}

void m65ce02_device::lda_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idy_2;return; // READ
}

void m65ce02_device::lda_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idy_3;return; // READ
}

void m65ce02_device::lda_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_idy_4;return; // READ
}

void m65ce02_device::lda_ce_idy_4() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_ce_zpg --- 
void m65ce02_device::lda_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_zpg_1;return; // READ
}

void m65ce02_device::lda_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_zpg_2;return; // READ
}

void m65ce02_device::lda_ce_zpg_2() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_ce_zpx --- 
void m65ce02_device::lda_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_zpx_1;return; // READ
}

void m65ce02_device::lda_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::lda_ce_zpx_2;return; // READ
}

void m65ce02_device::lda_ce_zpx_2() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_idz --- 
void m65ce02_device::lda_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_idz_1;return; // READ
}

void m65ce02_device::lda_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::lda_idz_2;return; // READ
}

void m65ce02_device::lda_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::lda_idz_3;return; // READ
}

void m65ce02_device::lda_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::lda_idz_4;return; // READ
}

void m65ce02_device::lda_idz_4() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op lda_isy --- 
void m65ce02_device::lda_isy_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::lda_isy_1;return; // READ
}

void m65ce02_device::lda_isy_1() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lda_isy_2;return; // READ
}

void m65ce02_device::lda_isy_2() {
  TMP = DAT;
  if (P & F_E) {
    TMP = set_l(SP, SP+TMP);
  } else {
    TMP = SP + TMP;
  }
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lda_isy_3;return; // READ
}

void m65ce02_device::lda_isy_3() {
  TMP2 = DAT;
  TMP++;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lda_isy_4;return; // READ
}

void m65ce02_device::lda_isy_4() {
  TMP = TMP2 | (DAT << 8);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::lda_isy_5;return; // READ
}

void m65ce02_device::lda_isy_5() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ldx_ce_aby --- 
void m65ce02_device::ldx_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_aby_1;return; // READ
}

void m65ce02_device::ldx_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_aby_2;return; // READ
}

void m65ce02_device::ldx_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP + Y;
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_aby_3;return; // READ
}

void m65ce02_device::ldx_ce_aby_3() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldx_ce_zpg --- 
void m65ce02_device::ldx_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_zpg_1;return; // READ
}

void m65ce02_device::ldx_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_zpg_2;return; // READ
}

void m65ce02_device::ldx_ce_zpg_2() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldx_ce_zpy --- 
void m65ce02_device::ldx_ce_zpy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_zpy_1;return; // READ
}

void m65ce02_device::ldx_ce_zpy_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+Y);
  RNW = true;
  NextFn = &m65ce02_device::ldx_ce_zpy_2;return; // READ
}

void m65ce02_device::ldx_ce_zpy_2() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ldy_ce_abx --- 
void m65ce02_device::ldy_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_abx_1;return; // READ
}

void m65ce02_device::ldy_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_abx_2;return; // READ
}

void m65ce02_device::ldy_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_abx_3;return; // READ
}

void m65ce02_device::ldy_ce_abx_3() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldy_ce_zpg --- 
void m65ce02_device::ldy_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_zpg_1;return; // READ
}

void m65ce02_device::ldy_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_zpg_2;return; // READ
}

void m65ce02_device::ldy_ce_zpg_2() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldy_ce_zpx --- 
void m65ce02_device::ldy_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_zpx_1;return; // READ
}

void m65ce02_device::ldy_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::ldy_ce_zpx_2;return; // READ
}

void m65ce02_device::ldy_ce_zpx_2() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op ldz_aba --- 
void m65ce02_device::ldz_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldz_aba_1;return; // READ
}

void m65ce02_device::ldz_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldz_aba_2;return; // READ
}

void m65ce02_device::ldz_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ldz_aba_3;return; // READ
}

void m65ce02_device::ldz_aba_3() {
  Z = DAT;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op ldz_abx --- 
void m65ce02_device::ldz_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldz_abx_1;return; // READ
}

void m65ce02_device::ldz_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldz_abx_2;return; // READ
}

void m65ce02_device::ldz_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP + X;
  RNW = true;
  NextFn = &m65ce02_device::ldz_abx_3;return; // READ
}

void m65ce02_device::ldz_abx_3() {
  Z = DAT;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op ldz_imm --- 
void m65ce02_device::ldz_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ldz_imm_1;return; // READ
}

void m65ce02_device::ldz_imm_1() {
  Z = DAT;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op lsr_ce_aba --- 
void m65ce02_device::lsr_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_aba_1;return; // READ
}

void m65ce02_device::lsr_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_aba_2;return; // READ
}

void m65ce02_device::lsr_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_aba_3;return; // READ
}

void m65ce02_device::lsr_ce_aba_3() {
  TMP2 = DAT;
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::lsr_ce_aba_4;return; // WRITE
}

void m65ce02_device::lsr_ce_aba_4() {
  fetch();return; // fetch
}

// --- op lsr_ce_abx --- 
void m65ce02_device::lsr_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_abx_1;return; // READ
}

void m65ce02_device::lsr_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_abx_2;return; // READ
}

void m65ce02_device::lsr_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = set_l(TMP, TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_abx_3;return; // READ
}

void m65ce02_device::lsr_ce_abx_3() {
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_abx_4;return; // READ
}

void m65ce02_device::lsr_ce_abx_4() {
  TMP2 = DAT;
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::lsr_ce_abx_5;return; // WRITE
}

void m65ce02_device::lsr_ce_abx_5() {
  fetch();return; // fetch
}

// --- op lsr_ce_acc --- 
void m65ce02_device::lsr_ce_acc_0() {
  A = do_lsr(A);
  fetch();return; // fetch
}

// --- op lsr_ce_zpg --- 
void m65ce02_device::lsr_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_zpg_1;return; // READ
}

void m65ce02_device::lsr_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_zpg_2;return; // READ
}

void m65ce02_device::lsr_ce_zpg_2() {
  TMP2 = DAT;
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::lsr_ce_zpg_3;return; // WRITE
}

void m65ce02_device::lsr_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op lsr_ce_zpx --- 
void m65ce02_device::lsr_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_zpx_1;return; // READ
}

void m65ce02_device::lsr_ce_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::lsr_ce_zpx_2;return; // READ
}

void m65ce02_device::lsr_ce_zpx_2() {
  TMP2 = DAT;
  TMP2 = do_lsr(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::lsr_ce_zpx_3;return; // WRITE
}

void m65ce02_device::lsr_ce_zpx_3() {
  fetch();return; // fetch
}

// --- op neg_acc --- 
void m65ce02_device::neg_acc_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::neg_acc_1;return; // READ
}

void m65ce02_device::neg_acc_1() {
  A = -A;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_ce_abx --- 
void m65ce02_device::ora_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_abx_1;return; // READ
}

void m65ce02_device::ora_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_abx_2;return; // READ
}

void m65ce02_device::ora_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_abx_3;return; // READ
}

void m65ce02_device::ora_ce_abx_3() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_ce_aby --- 
void m65ce02_device::ora_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_aby_1;return; // READ
}

void m65ce02_device::ora_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_aby_2;return; // READ
}

void m65ce02_device::ora_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_aby_3;return; // READ
}

void m65ce02_device::ora_ce_aby_3() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_ce_idx --- 
void m65ce02_device::ora_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idx_1;return; // READ
}

void m65ce02_device::ora_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idx_2;return; // READ
}

void m65ce02_device::ora_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idx_3;return; // READ
}

void m65ce02_device::ora_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idx_4;return; // READ
}

void m65ce02_device::ora_ce_idx_4() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_ce_idy --- 
void m65ce02_device::ora_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idy_1;return; // READ
}

void m65ce02_device::ora_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idy_2;return; // READ
}

void m65ce02_device::ora_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idy_3;return; // READ
}

void m65ce02_device::ora_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_idy_4;return; // READ
}

void m65ce02_device::ora_ce_idy_4() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_ce_zpg --- 
void m65ce02_device::ora_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_zpg_1;return; // READ
}

void m65ce02_device::ora_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_zpg_2;return; // READ
}

void m65ce02_device::ora_ce_zpg_2() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_ce_zpx --- 
void m65ce02_device::ora_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_zpx_1;return; // READ
}

void m65ce02_device::ora_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::ora_ce_zpx_2;return; // READ
}

void m65ce02_device::ora_ce_zpx_2() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op ora_idz --- 
void m65ce02_device::ora_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ora_idz_1;return; // READ
}

void m65ce02_device::ora_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::ora_idz_2;return; // READ
}

void m65ce02_device::ora_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::ora_idz_3;return; // READ
}

void m65ce02_device::ora_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::ora_idz_4;return; // READ
}

void m65ce02_device::ora_idz_4() {
  A |= DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op pha_ce_imp --- 
void m65ce02_device::pha_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::pha_ce_imp_1;return; // READ
}

void m65ce02_device::pha_ce_imp_1() {
  ADDR = SP;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::pha_ce_imp_2;return; // WRITE
}

void m65ce02_device::pha_ce_imp_2() {
  dec_SP_ce();
  fetch();return; // fetch
}

// --- op php_ce_imp --- 
void m65ce02_device::php_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::php_ce_imp_1;return; // READ
}

void m65ce02_device::php_ce_imp_1() {
  ADDR = SP;
  DAT =  P;
  RNW = false;
  NextFn = &m65ce02_device::php_ce_imp_2;return; // WRITE
}

void m65ce02_device::php_ce_imp_2() {
  dec_SP_ce();
  fetch();return; // fetch
}

// --- op phw_aba --- 
void m65ce02_device::phw_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::phw_aba_1;return; // READ
}

void m65ce02_device::phw_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::phw_aba_2;return; // READ
}

void m65ce02_device::phw_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::phw_aba_3;return; // READ
}

void m65ce02_device::phw_aba_3() {
  TMP3 = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::phw_aba_4;return; // READ
}

void m65ce02_device::phw_aba_4() {
  TMP3 = set_h(TMP3, DAT);
  dec_SP_ce();
  ADDR = SP;
  DAT =  TMP3;
  RNW = false;
  NextFn = &m65ce02_device::phw_aba_5;return; // WRITE
}

void m65ce02_device::phw_aba_5() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  TMP3 >> 8;
  RNW = false;
  NextFn = &m65ce02_device::phw_aba_6;return; // WRITE
}

void m65ce02_device::phw_aba_6() {
  fetch();return; // fetch
}

// --- op phw_iw2 --- 
void m65ce02_device::phw_iw2_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::phw_iw2_1;return; // READ
}

void m65ce02_device::phw_iw2_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::phw_iw2_2;return; // READ
}

void m65ce02_device::phw_iw2_2() {
  TMP = set_h(TMP, DAT);
  dec_SP_ce();
  ADDR = SP;
  DAT =  TMP;
  RNW = false;
  NextFn = &m65ce02_device::phw_iw2_3;return; // WRITE
}

void m65ce02_device::phw_iw2_3() {
  dec_SP_ce();
  ADDR = SP;
  DAT =  TMP >> 8;
  RNW = false;
  NextFn = &m65ce02_device::phw_iw2_4;return; // WRITE
}

void m65ce02_device::phw_iw2_4() {
  fetch();return; // fetch
}

// --- op phx_ce_imp --- 
void m65ce02_device::phx_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::phx_ce_imp_1;return; // READ
}

void m65ce02_device::phx_ce_imp_1() {
  ADDR = SP;
  DAT =  X;
  RNW = false;
  NextFn = &m65ce02_device::phx_ce_imp_2;return; // WRITE
}

void m65ce02_device::phx_ce_imp_2() {
  dec_SP_ce();
  fetch();return; // fetch
}

// --- op phy_ce_imp --- 
void m65ce02_device::phy_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::phy_ce_imp_1;return; // READ
}

void m65ce02_device::phy_ce_imp_1() {
  ADDR = SP;
  DAT =  Y;
  RNW = false;
  NextFn = &m65ce02_device::phy_ce_imp_2;return; // WRITE
}

void m65ce02_device::phy_ce_imp_2() {
  dec_SP_ce();
  fetch();return; // fetch
}

// --- op phz_imp --- 
void m65ce02_device::phz_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::phz_imp_1;return; // READ
}

void m65ce02_device::phz_imp_1() {
  ADDR = SP;
  DAT =  Z;
  RNW = false;
  NextFn = &m65ce02_device::phz_imp_2;return; // WRITE
}

void m65ce02_device::phz_imp_2() {
  dec_SP_ce();
  fetch();return; // fetch
}

// --- op pla_ce_imp --- 
void m65ce02_device::pla_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::pla_ce_imp_1;return; // READ
}

void m65ce02_device::pla_ce_imp_1() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::pla_ce_imp_2;return; // READ
}

void m65ce02_device::pla_ce_imp_2() {
  A = DAT;
  set_nz(A);
  fetch();return; // fetch
}

// --- op plp_ce_imp --- 
void m65ce02_device::plp_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::plp_ce_imp_1;return; // READ
}

void m65ce02_device::plp_ce_imp_1() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::plp_ce_imp_2;return; // READ
}

void m65ce02_device::plp_ce_imp_2() {
  TMP = DAT | F_B;
  PrefetchNextFn = &m65ce02_device::plp_ce_imp_3;
  prefetch();return; // prefetch
}

void m65ce02_device::plp_ce_imp_3() {
  P = TMP;
  postfetch();return; // postfetch
}

// --- op plx_ce_imp --- 
void m65ce02_device::plx_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::plx_ce_imp_1;return; // READ
}

void m65ce02_device::plx_ce_imp_1() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::plx_ce_imp_2;return; // READ
}

void m65ce02_device::plx_ce_imp_2() {
  X = DAT;
  set_nz(X);
  fetch();return; // fetch
}

// --- op ply_ce_imp --- 
void m65ce02_device::ply_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::ply_ce_imp_1;return; // READ
}

void m65ce02_device::ply_ce_imp_1() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::ply_ce_imp_2;return; // READ
}

void m65ce02_device::ply_ce_imp_2() {
  Y = DAT;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op plz_imp --- 
void m65ce02_device::plz_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::plz_imp_1;return; // READ
}

void m65ce02_device::plz_imp_1() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::plz_imp_2;return; // READ
}

void m65ce02_device::plz_imp_2() {
  Z = DAT;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op rmb_ce_bzp --- 
void m65ce02_device::rmb_ce_bzp_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rmb_ce_bzp_1;return; // READ
}

void m65ce02_device::rmb_ce_bzp_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::rmb_ce_bzp_2;return; // READ
}

void m65ce02_device::rmb_ce_bzp_2() {
  TMP2 = DAT;
  TMP2 &= ~(1 << ((IR >> 4) & 7));
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::rmb_ce_bzp_3;return; // WRITE
}

void m65ce02_device::rmb_ce_bzp_3() {
  fetch();return; // fetch
}

// --- op rol_ce_aba --- 
void m65ce02_device::rol_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_aba_1;return; // READ
}

void m65ce02_device::rol_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_aba_2;return; // READ
}

void m65ce02_device::rol_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_aba_3;return; // READ
}

void m65ce02_device::rol_ce_aba_3() {
  TMP2 = DAT;
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::rol_ce_aba_4;return; // WRITE
}

void m65ce02_device::rol_ce_aba_4() {
  fetch();return; // fetch
}

// --- op rol_ce_abx --- 
void m65ce02_device::rol_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_abx_1;return; // READ
}

void m65ce02_device::rol_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_abx_2;return; // READ
}

void m65ce02_device::rol_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_abx_3;return; // READ
}

void m65ce02_device::rol_ce_abx_3() {
  TMP2 = DAT;
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::rol_ce_abx_4;return; // WRITE
}

void m65ce02_device::rol_ce_abx_4() {
  fetch();return; // fetch
}

// --- op rol_ce_acc --- 
void m65ce02_device::rol_ce_acc_0() {
  A = do_rol(A);
  fetch();return; // fetch
}

// --- op rol_ce_zpg --- 
void m65ce02_device::rol_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_zpg_1;return; // READ
}

void m65ce02_device::rol_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_zpg_2;return; // READ
}

void m65ce02_device::rol_ce_zpg_2() {
  TMP2 = DAT;
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::rol_ce_zpg_3;return; // WRITE
}

void m65ce02_device::rol_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op rol_ce_zpx --- 
void m65ce02_device::rol_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_zpx_1;return; // READ
}

void m65ce02_device::rol_ce_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::rol_ce_zpx_2;return; // READ
}

void m65ce02_device::rol_ce_zpx_2() {
  TMP2 = DAT;
  TMP2 = do_rol(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::rol_ce_zpx_3;return; // WRITE
}

void m65ce02_device::rol_ce_zpx_3() {
  fetch();return; // fetch
}

// --- op ror_ce_aba --- 
void m65ce02_device::ror_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_aba_1;return; // READ
}

void m65ce02_device::ror_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_aba_2;return; // READ
}

void m65ce02_device::ror_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_aba_3;return; // READ
}

void m65ce02_device::ror_ce_aba_3() {
  TMP2 = DAT;
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::ror_ce_aba_4;return; // WRITE
}

void m65ce02_device::ror_ce_aba_4() {
  fetch();return; // fetch
}

// --- op ror_ce_abx --- 
void m65ce02_device::ror_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_abx_1;return; // READ
}

void m65ce02_device::ror_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_abx_2;return; // READ
}

void m65ce02_device::ror_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_abx_3;return; // READ
}

void m65ce02_device::ror_ce_abx_3() {
  TMP2 = DAT;
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::ror_ce_abx_4;return; // WRITE
}

void m65ce02_device::ror_ce_abx_4() {
  fetch();return; // fetch
}

// --- op ror_ce_acc --- 
void m65ce02_device::ror_ce_acc_0() {
  A = do_ror(A);
  fetch();return; // fetch
}

// --- op ror_ce_zpg --- 
void m65ce02_device::ror_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_zpg_1;return; // READ
}

void m65ce02_device::ror_ce_zpg_1() {
  TMP = B|DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_zpg_2;return; // READ
}

void m65ce02_device::ror_ce_zpg_2() {
  TMP2 = DAT;
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::ror_ce_zpg_3;return; // WRITE
}

void m65ce02_device::ror_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op ror_ce_zpx --- 
void m65ce02_device::ror_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_zpx_1;return; // READ
}

void m65ce02_device::ror_ce_zpx_1() {
  TMP = DAT;
  TMP = B|uint8_t(TMP+X);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::ror_ce_zpx_2;return; // READ
}

void m65ce02_device::ror_ce_zpx_2() {
  TMP2 = DAT;
  TMP2 = do_ror(TMP2);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::ror_ce_zpx_3;return; // WRITE
}

void m65ce02_device::ror_ce_zpx_3() {
  fetch();return; // fetch
}

// --- op row_aba --- 
void m65ce02_device::row_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::row_aba_1;return; // READ
}

void m65ce02_device::row_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::row_aba_2;return; // READ
}

void m65ce02_device::row_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::row_aba_3;return; // READ
}

void m65ce02_device::row_aba_3() {
  TMP3 = DAT;
  ADDR = TMP+1;
  RNW = true;
  NextFn = &m65ce02_device::row_aba_4;return; // READ
}

void m65ce02_device::row_aba_4() {
  TMP3 = set_h(TMP3, DAT);
  TMP2 = P;
  P &= ~(F_C|F_N|F_Z);
  if (TMP3 & 0x8000) {
    P |= F_C;
  }
  TMP3 <<= 1;
  if (TMP2 & F_C) {
    TMP3 |= 0x0001;
  }
  if (!TMP3) {
    P |= F_Z;
  } else {
    if (TMP3 & 0x8000) {
      P |= F_N;
    }
  }
  ADDR = TMP;
  DAT =  TMP3;
  RNW = false;
  NextFn = &m65ce02_device::row_aba_5;return; // WRITE
}

void m65ce02_device::row_aba_5() {
  ADDR = TMP;
  DAT =  TMP3 >> 8;
  RNW = false;
  NextFn = &m65ce02_device::row_aba_6;return; // WRITE
}

void m65ce02_device::row_aba_6() {
  fetch();return; // fetch
}

// --- op rti_ce_imp --- 
void m65ce02_device::rti_ce_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::rti_ce_imp_1;return; // READ
}

void m65ce02_device::rti_ce_imp_1() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rti_ce_imp_2;return; // READ
}

void m65ce02_device::rti_ce_imp_2() {
  P = DAT | F_B;
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rti_ce_imp_3;return; // READ
}

void m65ce02_device::rti_ce_imp_3() {
  PC = DAT;
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rti_ce_imp_4;return; // READ
}

void m65ce02_device::rti_ce_imp_4() {
  PC = set_h(PC, DAT);
  fetch();return; // fetch
}

// --- op rtn_imm --- 
void m65ce02_device::rtn_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rtn_imm_1;return; // READ
}

void m65ce02_device::rtn_imm_1() {
  TMP = DAT;
  if (P & F_E) {
    SP = set_l(SP, SP+TMP);
  } else {
    SP += TMP;
  }
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::rtn_imm_2;return; // READ
}

void m65ce02_device::rtn_imm_2() {
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rtn_imm_3;return; // READ
}

void m65ce02_device::rtn_imm_3() {
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rtn_imm_4;return; // READ
}

void m65ce02_device::rtn_imm_4() {
  PC = DAT;
  inc_SP();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rtn_imm_5;return; // READ
}

void m65ce02_device::rtn_imm_5() {
  PC = set_h(PC, DAT);
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rtn_imm_6;return; // READ
}

void m65ce02_device::rtn_imm_6() {
  fetch();return; // fetch
}

// --- op rts_ce_imp --- 
void m65ce02_device::rts_ce_imp_0() {
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rts_ce_imp_1;return; // READ
}

void m65ce02_device::rts_ce_imp_1() {
  PC = DAT;
  inc_SP_ce();
  ADDR = SP;
  RNW = true;
  NextFn = &m65ce02_device::rts_ce_imp_2;return; // READ
}

void m65ce02_device::rts_ce_imp_2() {
  PC = set_h(PC, DAT);
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::rts_ce_imp_3;return; // READ
}

void m65ce02_device::rts_ce_imp_3() {
  fetch();return; // fetch
}

// --- op sbc_ce_aba --- 
void m65ce02_device::sbc_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_aba_1;return; // READ
}

void m65ce02_device::sbc_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_aba_2;return; // READ
}

void m65ce02_device::sbc_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_aba_3;return; // READ
}

void m65ce02_device::sbc_ce_aba_3() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_abx --- 
void m65ce02_device::sbc_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_abx_1;return; // READ
}

void m65ce02_device::sbc_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_abx_2;return; // READ
}

void m65ce02_device::sbc_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  TMP += X;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_abx_3;return; // READ
}

void m65ce02_device::sbc_ce_abx_3() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_aby --- 
void m65ce02_device::sbc_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_aby_1;return; // READ
}

void m65ce02_device::sbc_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_aby_2;return; // READ
}

void m65ce02_device::sbc_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  TMP += Y;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_aby_3;return; // READ
}

void m65ce02_device::sbc_ce_aby_3() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_idx --- 
void m65ce02_device::sbc_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idx_1;return; // READ
}

void m65ce02_device::sbc_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idx_2;return; // READ
}

void m65ce02_device::sbc_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idx_3;return; // READ
}

void m65ce02_device::sbc_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idx_4;return; // READ
}

void m65ce02_device::sbc_ce_idx_4() {
  do_sbc(DAT);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_idy --- 
void m65ce02_device::sbc_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idy_1;return; // READ
}

void m65ce02_device::sbc_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idy_2;return; // READ
}

void m65ce02_device::sbc_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idy_3;return; // READ
}

void m65ce02_device::sbc_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_idy_4;return; // READ
}

void m65ce02_device::sbc_ce_idy_4() {
  do_sbc(DAT);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_imm --- 
void m65ce02_device::sbc_ce_imm_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_imm_1;return; // READ
}

void m65ce02_device::sbc_ce_imm_1() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_zpg --- 
void m65ce02_device::sbc_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_zpg_1;return; // READ
}

void m65ce02_device::sbc_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_zpg_2;return; // READ
}

void m65ce02_device::sbc_ce_zpg_2() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_ce_zpx --- 
void m65ce02_device::sbc_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_zpx_1;return; // READ
}

void m65ce02_device::sbc_ce_zpx_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_zpx_2;return; // READ
}

void m65ce02_device::sbc_ce_zpx_2() {
  ADDR = B|uint8_t(TMP+X);
  RNW = true;
  NextFn = &m65ce02_device::sbc_ce_zpx_3;return; // READ
}

void m65ce02_device::sbc_ce_zpx_3() {
  TMP = DAT;
  do_sbc(TMP);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sbc_idz --- 
void m65ce02_device::sbc_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sbc_idz_1;return; // READ
}

void m65ce02_device::sbc_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sbc_idz_2;return; // READ
}

void m65ce02_device::sbc_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sbc_idz_3;return; // READ
}

void m65ce02_device::sbc_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  RNW = true;
  NextFn = &m65ce02_device::sbc_idz_4;return; // READ
}

void m65ce02_device::sbc_idz_4() {
  do_sbc(DAT);
  if (P & F_D) {
    set_nz(A);
  }
  fetch();return; // fetch
}

// --- op sec_ce_imp --- 
void m65ce02_device::sec_ce_imp_0() {
  P |= F_C;
  fetch();return; // fetch
}

// --- op sed_ce_imp --- 
void m65ce02_device::sed_ce_imp_0() {
  P |= F_D;
  fetch();return; // fetch
}

// --- op see_imp --- 
void m65ce02_device::see_imp_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::see_imp_1;return; // READ
}

void m65ce02_device::see_imp_1() {
  P |= F_E;
  fetch();return; // fetch
}

// --- op sei_ce_imp --- 
void m65ce02_device::sei_ce_imp_0() {
  PrefetchNextFn = &m65ce02_device::sei_ce_imp_1;
  prefetch();return; // prefetch
}

void m65ce02_device::sei_ce_imp_1() {
  P |= F_I;
  postfetch();return; // postfetch
}

// --- op smb_ce_bzp --- 
void m65ce02_device::smb_ce_bzp_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::smb_ce_bzp_1;return; // READ
}

void m65ce02_device::smb_ce_bzp_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::smb_ce_bzp_2;return; // READ
}

void m65ce02_device::smb_ce_bzp_2() {
  TMP2 = DAT;
  TMP2 |= 1 << ((IR >> 4) & 7);
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::smb_ce_bzp_3;return; // WRITE
}

void m65ce02_device::smb_ce_bzp_3() {
  fetch();return; // fetch
}

// --- op sta_ce_abx --- 
void m65ce02_device::sta_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_abx_1;return; // READ
}

void m65ce02_device::sta_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_abx_2;return; // READ
}

void m65ce02_device::sta_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+X;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_ce_abx_3;return; // WRITE
}

void m65ce02_device::sta_ce_abx_3() {
  fetch();return; // fetch
}

// --- op sta_ce_aby --- 
void m65ce02_device::sta_ce_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_aby_1;return; // READ
}

void m65ce02_device::sta_ce_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_aby_2;return; // READ
}

void m65ce02_device::sta_ce_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_ce_aby_3;return; // WRITE
}

void m65ce02_device::sta_ce_aby_3() {
  fetch();return; // fetch
}

// --- op sta_ce_idx --- 
void m65ce02_device::sta_ce_idx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_idx_1;return; // READ
}

void m65ce02_device::sta_ce_idx_1() {
  TMP2 = DAT;
  TMP2 += X;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_idx_2;return; // READ
}

void m65ce02_device::sta_ce_idx_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_idx_3;return; // READ
}

void m65ce02_device::sta_ce_idx_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_ce_idx_4;return; // WRITE
}

void m65ce02_device::sta_ce_idx_4() {
  fetch();return; // fetch
}

// --- op sta_ce_idy --- 
void m65ce02_device::sta_ce_idy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_idy_1;return; // READ
}

void m65ce02_device::sta_ce_idy_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_idy_2;return; // READ
}

void m65ce02_device::sta_ce_idy_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_idy_3;return; // READ
}

void m65ce02_device::sta_ce_idy_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_ce_idy_4;return; // WRITE
}

void m65ce02_device::sta_ce_idy_4() {
  fetch();return; // fetch
}

// --- op sta_ce_zpg --- 
void m65ce02_device::sta_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_zpg_1;return; // READ
}

void m65ce02_device::sta_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_ce_zpg_2;return; // WRITE
}

void m65ce02_device::sta_ce_zpg_2() {
  fetch();return; // fetch
}

// --- op sta_ce_zpx --- 
void m65ce02_device::sta_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_ce_zpx_1;return; // READ
}

void m65ce02_device::sta_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_ce_zpx_2;return; // WRITE
}

void m65ce02_device::sta_ce_zpx_2() {
  fetch();return; // fetch
}

// --- op sta_idz --- 
void m65ce02_device::sta_idz_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_idz_1;return; // READ
}

void m65ce02_device::sta_idz_1() {
  TMP2 = DAT;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sta_idz_2;return; // READ
}

void m65ce02_device::sta_idz_2() {
  TMP = DAT;
  TMP2++;
  ADDR = B|TMP2;
  RNW = true;
  NextFn = &m65ce02_device::sta_idz_3;return; // READ
}

void m65ce02_device::sta_idz_3() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Z;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_idz_4;return; // WRITE
}

void m65ce02_device::sta_idz_4() {
  fetch();return; // fetch
}

// --- op sta_isy --- 
void m65ce02_device::sta_isy_0() {
  ADDR = PC;
  RNW = true;
  NextFn = &m65ce02_device::sta_isy_1;return; // READ
}

void m65ce02_device::sta_isy_1() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sta_isy_2;return; // READ
}

void m65ce02_device::sta_isy_2() {
  TMP = DAT;
  if (P & F_E) {
    TMP = set_l(SP, SP+TMP);
  } else {
    TMP = SP + TMP;
  }
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sta_isy_3;return; // READ
}

void m65ce02_device::sta_isy_3() {
  TMP2 = DAT;
  TMP++;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::sta_isy_4;return; // READ
}

void m65ce02_device::sta_isy_4() {
  TMP = TMP2 | (DAT << 8);
  ADDR = TMP+Y;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::sta_isy_5;return; // WRITE
}

void m65ce02_device::sta_isy_5() {
  fetch();return; // fetch
}

// --- op stx_aby --- 
void m65ce02_device::stx_aby_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stx_aby_1;return; // READ
}

void m65ce02_device::stx_aby_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stx_aby_2;return; // READ
}

void m65ce02_device::stx_aby_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+Y;
  DAT =  X;
  RNW = false;
  NextFn = &m65ce02_device::stx_aby_3;return; // WRITE
}

void m65ce02_device::stx_aby_3() {
  fetch();return; // fetch
}

// --- op stx_ce_zpg --- 
void m65ce02_device::stx_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stx_ce_zpg_1;return; // READ
}

void m65ce02_device::stx_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  DAT =  X;
  RNW = false;
  NextFn = &m65ce02_device::stx_ce_zpg_2;return; // WRITE
}

void m65ce02_device::stx_ce_zpg_2() {
  fetch();return; // fetch
}

// --- op stx_ce_zpy --- 
void m65ce02_device::stx_ce_zpy_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stx_ce_zpy_1;return; // READ
}

void m65ce02_device::stx_ce_zpy_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+Y);
  DAT =  X;
  RNW = false;
  NextFn = &m65ce02_device::stx_ce_zpy_2;return; // WRITE
}

void m65ce02_device::stx_ce_zpy_2() {
  fetch();return; // fetch
}

// --- op sty_abx --- 
void m65ce02_device::sty_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sty_abx_1;return; // READ
}

void m65ce02_device::sty_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sty_abx_2;return; // READ
}

void m65ce02_device::sty_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+X;
  DAT =  Y;
  RNW = false;
  NextFn = &m65ce02_device::sty_abx_3;return; // WRITE
}

void m65ce02_device::sty_abx_3() {
  fetch();return; // fetch
}

// --- op sty_ce_zpg --- 
void m65ce02_device::sty_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sty_ce_zpg_1;return; // READ
}

void m65ce02_device::sty_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  DAT =  Y;
  RNW = false;
  NextFn = &m65ce02_device::sty_ce_zpg_2;return; // WRITE
}

void m65ce02_device::sty_ce_zpg_2() {
  fetch();return; // fetch
}

// --- op sty_ce_zpx --- 
void m65ce02_device::sty_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::sty_ce_zpx_1;return; // READ
}

void m65ce02_device::sty_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  DAT =  Y;
  RNW = false;
  NextFn = &m65ce02_device::sty_ce_zpx_2;return; // WRITE
}

void m65ce02_device::sty_ce_zpx_2() {
  fetch();return; // fetch
}

// --- op stz_ce_aba --- 
void m65ce02_device::stz_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stz_ce_aba_1;return; // READ
}

void m65ce02_device::stz_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stz_ce_aba_2;return; // READ
}

void m65ce02_device::stz_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::stz_ce_aba_3;return; // WRITE
}

void m65ce02_device::stz_ce_aba_3() {
  fetch();return; // fetch
}

// --- op stz_ce_abx --- 
void m65ce02_device::stz_ce_abx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stz_ce_abx_1;return; // READ
}

void m65ce02_device::stz_ce_abx_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stz_ce_abx_2;return; // READ
}

void m65ce02_device::stz_ce_abx_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP+X;
  DAT =  A;
  RNW = false;
  NextFn = &m65ce02_device::stz_ce_abx_3;return; // WRITE
}

void m65ce02_device::stz_ce_abx_3() {
  fetch();return; // fetch
}

// --- op stz_ce_zpg --- 
void m65ce02_device::stz_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stz_ce_zpg_1;return; // READ
}

void m65ce02_device::stz_ce_zpg_1() {
  TMP = DAT;
  ADDR = B|TMP;
  DAT =  Z;
  RNW = false;
  NextFn = &m65ce02_device::stz_ce_zpg_2;return; // WRITE
}

void m65ce02_device::stz_ce_zpg_2() {
  fetch();return; // fetch
}

// --- op stz_ce_zpx --- 
void m65ce02_device::stz_ce_zpx_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::stz_ce_zpx_1;return; // READ
}

void m65ce02_device::stz_ce_zpx_1() {
  TMP = DAT;
  ADDR = B|uint8_t(TMP+X);
  DAT =  Z;
  RNW = false;
  NextFn = &m65ce02_device::stz_ce_zpx_2;return; // WRITE
}

void m65ce02_device::stz_ce_zpx_2() {
  fetch();return; // fetch
}

// --- op tab_imp --- 
void m65ce02_device::tab_imp_0() {
  B = A << 8;
  fetch();return; // fetch
}

// --- op tax_ce_imp --- 
void m65ce02_device::tax_ce_imp_0() {
  X = A;
  set_nz(X);
  fetch();return; // fetch
}

// --- op tay_ce_imp --- 
void m65ce02_device::tay_ce_imp_0() {
  Y = A;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op taz_imp --- 
void m65ce02_device::taz_imp_0() {
  Z = A;
  set_nz(Z);
  fetch();return; // fetch
}

// --- op tba_imp --- 
void m65ce02_device::tba_imp_0() {
  A = B >> 8;
  set_nz(A);
  fetch();return; // fetch
}

// --- op trb_ce_aba --- 
void m65ce02_device::trb_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::trb_ce_aba_1;return; // READ
}

void m65ce02_device::trb_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::trb_ce_aba_2;return; // READ
}

void m65ce02_device::trb_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::trb_ce_aba_3;return; // READ
}

void m65ce02_device::trb_ce_aba_3() {
  TMP2 = DAT;
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 &= ~A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::trb_ce_aba_4;return; // WRITE
}

void m65ce02_device::trb_ce_aba_4() {
  fetch();return; // fetch
}

// --- op trb_ce_zpg --- 
void m65ce02_device::trb_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::trb_ce_zpg_1;return; // READ
}

void m65ce02_device::trb_ce_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::trb_ce_zpg_2;return; // READ
}

void m65ce02_device::trb_ce_zpg_2() {
  TMP2 = DAT;
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 &= ~A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::trb_ce_zpg_3;return; // WRITE
}

void m65ce02_device::trb_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op tsb_ce_aba --- 
void m65ce02_device::tsb_ce_aba_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::tsb_ce_aba_1;return; // READ
}

void m65ce02_device::tsb_ce_aba_1() {
  TMP = DAT;
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::tsb_ce_aba_2;return; // READ
}

void m65ce02_device::tsb_ce_aba_2() {
  TMP = set_h(TMP, DAT);
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::tsb_ce_aba_3;return; // READ
}

void m65ce02_device::tsb_ce_aba_3() {
  TMP2 = DAT;
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 |= A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::tsb_ce_aba_4;return; // WRITE
}

void m65ce02_device::tsb_ce_aba_4() {
  fetch();return; // fetch
}

// --- op tsb_ce_zpg --- 
void m65ce02_device::tsb_ce_zpg_0() {
  ADDR = PC++;
  RNW = true;
  NextFn = &m65ce02_device::tsb_ce_zpg_1;return; // READ
}

void m65ce02_device::tsb_ce_zpg_1() {
  TMP = DAT;
  ADDR = TMP;
  RNW = true;
  NextFn = &m65ce02_device::tsb_ce_zpg_2;return; // READ
}

void m65ce02_device::tsb_ce_zpg_2() {
  TMP2 = DAT;
  if (A & TMP2) {
    P &= ~F_Z;
  } else {
    P |= F_Z;
  }
  TMP2 |= A;
  ADDR = TMP;
  DAT =  TMP2;
  RNW = false;
  NextFn = &m65ce02_device::tsb_ce_zpg_3;return; // WRITE
}

void m65ce02_device::tsb_ce_zpg_3() {
  fetch();return; // fetch
}

// --- op tsx_ce_imp --- 
void m65ce02_device::tsx_ce_imp_0() {
  X = SP;
  set_nz(X);
  fetch();return; // fetch
}

// --- op tsy_imp --- 
void m65ce02_device::tsy_imp_0() {
  Y = SP >> 8;
  set_nz(Y);
  fetch();return; // fetch
}

// --- op txa_ce_imp --- 
void m65ce02_device::txa_ce_imp_0() {
  A = X;
  set_nz(A);
  fetch();return; // fetch
}

// --- op txs_ce_imp --- 
void m65ce02_device::txs_ce_imp_0() {
  SP = set_l(SP, X);
  fetch_noirq();return; // fetch_noirq
}

// --- op tya_ce_imp --- 
void m65ce02_device::tya_ce_imp_0() {
  A = Y;
  set_nz(A);
  fetch();return; // fetch
}

// --- op tys_imp --- 
void m65ce02_device::tys_imp_0() {
  SP = set_h(SP, Y);
  fetch();return; // fetch
}

// --- op tza_imp --- 
void m65ce02_device::tza_imp_0() {
  A = Z;
  set_nz(A);
  fetch();return; // fetch
}

void m65ce02_device::postfetch_int() {
  switch(IR) {
  case 0x00: brk_ce_imp_0(); break;
  case 0x01: ora_ce_idx_0(); break;
  case 0x02: cle_imp_0(); break;
  case 0x03: see_imp_0(); break;
  case 0x04: tsb_ce_zpg_0(); break;
  case 0x05: ora_ce_zpg_0(); break;
  case 0x06: asl_ce_zpg_0(); break;
  case 0x07: rmb_ce_bzp_0(); break;
  case 0x08: php_ce_imp_0(); break;
  case 0x09: ora_imm_0(); break;
  case 0x0a: asl_ce_acc_0(); break;
  case 0x0b: tsy_imp_0(); break;
  case 0x0c: tsb_ce_aba_0(); break;
  case 0x0d: ora_aba_0(); break;
  case 0x0e: asl_ce_aba_0(); break;
  case 0x0f: bbr_ce_zpb_0(); break;
  case 0x10: bpl_ce_rel_0(); break;
  case 0x11: ora_ce_idy_0(); break;
  case 0x12: ora_idz_0(); break;
  case 0x13: bpl_rw2_0(); break;
  case 0x14: trb_ce_zpg_0(); break;
  case 0x15: ora_ce_zpx_0(); break;
  case 0x16: asl_ce_zpx_0(); break;
  case 0x17: rmb_ce_bzp_0(); break;
  case 0x18: clc_ce_imp_0(); break;
  case 0x19: ora_ce_aby_0(); break;
  case 0x1a: inc_ce_acc_0(); break;
  case 0x1b: inz_imp_0(); break;
  case 0x1c: trb_ce_aba_0(); break;
  case 0x1d: ora_ce_abx_0(); break;
  case 0x1e: asl_ce_abx_0(); break;
  case 0x1f: bbr_ce_zpb_0(); break;
  case 0x20: jsr_ce_adr_0(); break;
  case 0x21: and_ce_idx_0(); break;
  case 0x22: jsr_ind_0(); break;
  case 0x23: jsr_iax_0(); break;
  case 0x24: bit_ce_zpg_0(); break;
  case 0x25: and_ce_zpg_0(); break;
  case 0x26: rol_ce_zpg_0(); break;
  case 0x27: rmb_ce_bzp_0(); break;
  case 0x28: plp_ce_imp_0(); break;
  case 0x29: and_imm_0(); break;
  case 0x2a: rol_ce_acc_0(); break;
  case 0x2b: tys_imp_0(); break;
  case 0x2c: bit_aba_0(); break;
  case 0x2d: and_aba_0(); break;
  case 0x2e: rol_ce_aba_0(); break;
  case 0x2f: bbr_ce_zpb_0(); break;
  case 0x30: bmi_ce_rel_0(); break;
  case 0x31: and_ce_idy_0(); break;
  case 0x32: and_idz_0(); break;
  case 0x33: bmi_rw2_0(); break;
  case 0x34: bit_ce_zpx_0(); break;
  case 0x35: and_ce_zpx_0(); break;
  case 0x36: rol_ce_zpx_0(); break;
  case 0x37: rmb_ce_bzp_0(); break;
  case 0x38: sec_ce_imp_0(); break;
  case 0x39: and_ce_aby_0(); break;
  case 0x3a: dec_ce_acc_0(); break;
  case 0x3b: dez_imp_0(); break;
  case 0x3c: bit_ce_abx_0(); break;
  case 0x3d: and_ce_abx_0(); break;
  case 0x3e: rol_ce_abx_0(); break;
  case 0x3f: bbr_ce_zpb_0(); break;
  case 0x40: rti_ce_imp_0(); break;
  case 0x41: eor_ce_idx_0(); break;
  case 0x42: neg_acc_0(); break;
  case 0x43: asr_acc_0(); break;
  case 0x44: asr_zpg_0(); break;
  case 0x45: eor_ce_zpg_0(); break;
  case 0x46: lsr_ce_zpg_0(); break;
  case 0x47: rmb_ce_bzp_0(); break;
  case 0x48: pha_ce_imp_0(); break;
  case 0x49: eor_imm_0(); break;
  case 0x4a: lsr_ce_acc_0(); break;
  case 0x4b: taz_imp_0(); break;
  case 0x4c: jmp_adr_0(); break;
  case 0x4d: eor_aba_0(); break;
  case 0x4e: lsr_ce_aba_0(); break;
  case 0x4f: bbr_ce_zpb_0(); break;
  case 0x50: bvc_ce_rel_0(); break;
  case 0x51: eor_ce_idy_0(); break;
  case 0x52: eor_idz_0(); break;
  case 0x53: bvc_rw2_0(); break;
  case 0x54: asr_zpx_0(); break;
  case 0x55: eor_ce_zpx_0(); break;
  case 0x56: lsr_ce_zpx_0(); break;
  case 0x57: rmb_ce_bzp_0(); break;
  case 0x58: cli_ce_imp_0(); break;
  case 0x59: eor_ce_aby_0(); break;
  case 0x5a: phy_ce_imp_0(); break;
  case 0x5b: tab_imp_0(); break;
  case 0x5c: aug_iw3_0(); break;
  case 0x5d: eor_ce_abx_0(); break;
  case 0x5e: lsr_ce_abx_0(); break;
  case 0x5f: bbr_ce_zpb_0(); break;
  case 0x60: rts_ce_imp_0(); break;
  case 0x61: adc_ce_idx_0(); break;
  case 0x62: rtn_imm_0(); break;
  case 0x63: bsr_rw2_0(); break;
  case 0x64: stz_ce_zpg_0(); break;
  case 0x65: adc_ce_zpg_0(); break;
  case 0x66: ror_ce_zpg_0(); break;
  case 0x67: rmb_ce_bzp_0(); break;
  case 0x68: pla_ce_imp_0(); break;
  case 0x69: adc_ce_imm_0(); break;
  case 0x6a: ror_ce_acc_0(); break;
  case 0x6b: tza_imp_0(); break;
  case 0x6c: jmp_ce_ind_0(); break;
  case 0x6d: adc_ce_aba_0(); break;
  case 0x6e: ror_ce_aba_0(); break;
  case 0x6f: bbr_ce_zpb_0(); break;
  case 0x70: bvs_ce_rel_0(); break;
  case 0x71: adc_ce_idy_0(); break;
  case 0x72: adc_idz_0(); break;
  case 0x73: bvs_rw2_0(); break;
  case 0x74: stz_ce_zpx_0(); break;
  case 0x75: adc_ce_zpx_0(); break;
  case 0x76: ror_ce_zpx_0(); break;
  case 0x77: rmb_ce_bzp_0(); break;
  case 0x78: sei_ce_imp_0(); break;
  case 0x79: adc_ce_aby_0(); break;
  case 0x7a: ply_ce_imp_0(); break;
  case 0x7b: tba_imp_0(); break;
  case 0x7c: jmp_ce_iax_0(); break;
  case 0x7d: adc_ce_abx_0(); break;
  case 0x7e: ror_ce_abx_0(); break;
  case 0x7f: bbr_ce_zpb_0(); break;
  case 0x80: bra_ce_rel_0(); break;
  case 0x81: sta_ce_idx_0(); break;
  case 0x82: sta_isy_0(); break;
  case 0x83: bra_rw2_0(); break;
  case 0x84: sty_ce_zpg_0(); break;
  case 0x85: sta_ce_zpg_0(); break;
  case 0x86: stx_ce_zpg_0(); break;
  case 0x87: smb_ce_bzp_0(); break;
  case 0x88: dey_ce_imp_0(); break;
  case 0x89: bit_ce_imm_0(); break;
  case 0x8a: txa_ce_imp_0(); break;
  case 0x8b: sty_abx_0(); break;
  case 0x8c: sty_aba_0(); break;
  case 0x8d: sta_aba_0(); break;
  case 0x8e: stx_aba_0(); break;
  case 0x8f: bbs_ce_zpb_0(); break;
  case 0x90: bcc_ce_rel_0(); break;
  case 0x91: sta_ce_idy_0(); break;
  case 0x92: sta_idz_0(); break;
  case 0x93: bcc_rw2_0(); break;
  case 0x94: sty_ce_zpx_0(); break;
  case 0x95: sta_ce_zpx_0(); break;
  case 0x96: stx_ce_zpy_0(); break;
  case 0x97: smb_ce_bzp_0(); break;
  case 0x98: tya_ce_imp_0(); break;
  case 0x99: sta_ce_aby_0(); break;
  case 0x9a: txs_ce_imp_0(); break;
  case 0x9b: stx_aby_0(); break;
  case 0x9c: stz_ce_aba_0(); break;
  case 0x9d: sta_ce_abx_0(); break;
  case 0x9e: stz_ce_abx_0(); break;
  case 0x9f: bbs_ce_zpb_0(); break;
  case 0xa0: ldy_imm_0(); break;
  case 0xa1: lda_ce_idx_0(); break;
  case 0xa2: ldx_imm_0(); break;
  case 0xa3: ldz_imm_0(); break;
  case 0xa4: ldy_ce_zpg_0(); break;
  case 0xa5: lda_ce_zpg_0(); break;
  case 0xa6: ldx_ce_zpg_0(); break;
  case 0xa7: smb_ce_bzp_0(); break;
  case 0xa8: tay_ce_imp_0(); break;
  case 0xa9: lda_imm_0(); break;
  case 0xaa: tax_ce_imp_0(); break;
  case 0xab: ldz_aba_0(); break;
  case 0xac: ldy_aba_0(); break;
  case 0xad: lda_aba_0(); break;
  case 0xae: ldx_aba_0(); break;
  case 0xaf: bbs_ce_zpb_0(); break;
  case 0xb0: bcs_ce_rel_0(); break;
  case 0xb1: lda_ce_idy_0(); break;
  case 0xb2: lda_idz_0(); break;
  case 0xb3: bcs_rw2_0(); break;
  case 0xb4: ldy_ce_zpx_0(); break;
  case 0xb5: lda_ce_zpx_0(); break;
  case 0xb6: ldx_ce_zpy_0(); break;
  case 0xb7: smb_ce_bzp_0(); break;
  case 0xb8: clv_ce_imp_0(); break;
  case 0xb9: lda_ce_aby_0(); break;
  case 0xba: tsx_ce_imp_0(); break;
  case 0xbb: ldz_abx_0(); break;
  case 0xbc: ldy_ce_abx_0(); break;
  case 0xbd: lda_ce_abx_0(); break;
  case 0xbe: ldx_ce_aby_0(); break;
  case 0xbf: bbs_ce_zpb_0(); break;
  case 0xc0: cpy_imm_0(); break;
  case 0xc1: cmp_ce_idx_0(); break;
  case 0xc2: cpz_imm_0(); break;
  case 0xc3: dew_zpg_0(); break;
  case 0xc4: cpy_ce_zpg_0(); break;
  case 0xc5: cmp_ce_zpg_0(); break;
  case 0xc6: dec_ce_zpg_0(); break;
  case 0xc7: smb_ce_bzp_0(); break;
  case 0xc8: iny_ce_imp_0(); break;
  case 0xc9: cmp_imm_0(); break;
  case 0xca: dex_ce_imp_0(); break;
  case 0xcb: asw_aba_0(); break;
  case 0xcc: cpy_aba_0(); break;
  case 0xcd: cmp_aba_0(); break;
  case 0xce: dec_ce_aba_0(); break;
  case 0xcf: bbs_ce_zpb_0(); break;
  case 0xd0: bne_ce_rel_0(); break;
  case 0xd1: cmp_ce_idy_0(); break;
  case 0xd2: cmp_idz_0(); break;
  case 0xd3: bne_rw2_0(); break;
  case 0xd4: cpz_zpg_0(); break;
  case 0xd5: cmp_ce_zpx_0(); break;
  case 0xd6: dec_ce_zpx_0(); break;
  case 0xd7: smb_ce_bzp_0(); break;
  case 0xd8: cld_ce_imp_0(); break;
  case 0xd9: cmp_ce_aby_0(); break;
  case 0xda: phx_ce_imp_0(); break;
  case 0xdb: phz_imp_0(); break;
  case 0xdc: cpz_aba_0(); break;
  case 0xdd: cmp_ce_abx_0(); break;
  case 0xde: dec_ce_abx_0(); break;
  case 0xdf: bbs_ce_zpb_0(); break;
  case 0xe0: cpx_imm_0(); break;
  case 0xe1: sbc_ce_idx_0(); break;
  case 0xe2: lda_isy_0(); break;
  case 0xe3: inw_zpg_0(); break;
  case 0xe4: cpx_ce_zpg_0(); break;
  case 0xe5: sbc_ce_zpg_0(); break;
  case 0xe6: inc_ce_zpg_0(); break;
  case 0xe7: smb_ce_bzp_0(); break;
  case 0xe8: inx_ce_imp_0(); break;
  case 0xe9: sbc_ce_imm_0(); break;
  case 0xea: nop_c_imp_0(); break;
  case 0xeb: row_aba_0(); break;
  case 0xec: cpx_aba_0(); break;
  case 0xed: sbc_ce_aba_0(); break;
  case 0xee: inc_ce_aba_0(); break;
  case 0xef: bbs_ce_zpb_0(); break;
  case 0xf0: beq_ce_rel_0(); break;
  case 0xf1: sbc_ce_idy_0(); break;
  case 0xf2: sbc_idz_0(); break;
  case 0xf3: beq_rw2_0(); break;
  case 0xf4: phw_iw2_0(); break;
  case 0xf5: sbc_ce_zpx_0(); break;
  case 0xf6: inc_ce_zpx_0(); break;
  case 0xf7: smb_ce_bzp_0(); break;
  case 0xf8: sed_ce_imp_0(); break;
  case 0xf9: sbc_ce_aby_0(); break;
  case 0xfa: plx_ce_imp_0(); break;
  case 0xfb: plz_imp_0(); break;
  case 0xfc: phw_aba_0(); break;
  case 0xfd: sbc_ce_abx_0(); break;
  case 0xfe: inc_ce_abx_0(); break;
  case 0xff: bbs_ce_zpb_0(); break;
  default:   reset_c_0(); break;
  }
}

