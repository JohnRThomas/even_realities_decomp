/*
 * Function: lc3_ltpf_analyse
 * Entry:    0006cb78
 * Prototype: bool __stdcall lc3_ltpf_analyse(lc3_dt dt, lc3_srate sr, lc3_ltpf_analysis_t * ltpf, int16_t * x, lc3_ltpf_data_t * data)
 */


/* exclude_from_export_ai */

bool lc3_ltpf_analyse(lc3_dt dt,lc3_srate sr,lc3_ltpf_analysis_t *ltpf,int16_t *x,
                     lc3_ltpf_data_t *data)

{
  longlong lVar1;
  int iVar2;
  short *psVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  bool bVar10;
  byte bVar11;
  uint in_fpscr;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  int local_26c;
  float local_1b0 [99];
  
  iVar7 = *(int *)(dt + 0x484);
  iVar8 = iVar7;
  if (iVar7 < 4) {
    iVar8 = 4;
  }
  if (0x5c < iVar7) {
    iVar7 = 0x5d;
  }
  correlate_ltpf(sr,(short *)(sr - 0x22),(int)ltpf,local_1b0,0x62);
  fVar15 = 0.9948454;
  iVar2 = 0;
  iVar5 = 1;
  iVar8 = iVar8 + -4;
  iVar7 = (iVar7 + 4) - iVar8;
  pfVar4 = local_1b0;
  fVar16 = local_1b0[0];
  do {
    pfVar4 = pfVar4 + 1;
    fVar13 = *pfVar4 * fVar15;
    uVar12 = in_fpscr & 0xfffffff | (uint)(fVar13 < fVar16) << 0x1f |
             (uint)(fVar13 == fVar16) << 0x1e;
    in_fpscr = uVar12 | (uint)(NAN(fVar13) || NAN(fVar16)) << 0x1c;
    bVar11 = (byte)(uVar12 >> 0x18);
    fVar15 = fVar15 - 0.005154639;
    if (!(bool)(bVar11 >> 6 & 1) && bVar11 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      iVar2 = iVar5;
      local_1b0[0] = *pfVar4;
      fVar16 = fVar13;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x62);
  pfVar4 = local_1b0 + iVar8;
  fVar16 = *pfVar4;
  if (0 < iVar7) {
    iVar5 = 0;
    iVar6 = 1;
    do {
      pfVar4 = pfVar4 + 1;
      fVar15 = *pfVar4;
      uVar12 = in_fpscr & 0xfffffff | (uint)(fVar15 < fVar16) << 0x1f |
               (uint)(fVar15 == fVar16) << 0x1e;
      in_fpscr = uVar12 | (uint)(NAN(fVar15) || NAN(fVar16)) << 0x1c;
      bVar11 = (byte)(uVar12 >> 0x18);
      bVar9 = bVar11 >> 7;
      bVar10 = (bool)(bVar11 >> 6 & 1);
      bVar11 = (byte)(in_fpscr >> 0x1c) & 1;
      if (!bVar10 && bVar9 == bVar11) {
        iVar5 = iVar6;
      }
      iVar6 = iVar6 + 1;
      fVar16 = (float)((uint)(!bVar10 && bVar9 == bVar11) * (int)fVar15 +
                      (uint)(bVar10 || bVar9 != bVar11) * (int)fVar16);
    } while (iVar6 != iVar7 + 1);
    iVar8 = iVar8 + iVar5;
  }
  in_fpscr = in_fpscr & 0xfffffff;
  uVar12 = in_fpscr | (uint)(local_1b0[0] < 0.0) << 0x1f | (uint)(local_1b0[0] == 0.0) << 0x1e;
  bVar11 = (byte)(uVar12 >> 0x18);
  local_26c = iVar8 + 0x11;
  iVar7 = (int)ltpf >> 4;
  if ((bool)(bVar11 >> 6 & 1) || (bool)(bVar11 >> 7) != NAN(local_1b0[0])) {
    uVar12 = in_fpscr | (uint)(fVar16 < 0.0) << 0x1f | (uint)(fVar16 == 0.0) << 0x1e;
    local_1b0[0] = 0.0;
    bVar11 = (byte)(uVar12 >> 0x18);
    fVar15 = local_1b0[0];
    if ((bool)(bVar11 >> 6 & 1) || (bool)(bVar11 >> 7) != NAN(fVar16)) goto LAB_0006d7f4;
  }
  else {
    lVar1 = (longlong)((int)*(short *)(sr + 0x5e) * (int)*(short *)(sr + 0x5e)) +
            (longlong)((int)*(short *)(sr + 0x5c) * (int)*(short *)(sr + 0x5c)) +
            (longlong)((int)*(short *)(sr + 0x5a) * (int)*(short *)(sr + 0x5a)) +
            (longlong)((int)*(short *)(sr + 0x58) * (int)*(short *)(sr + 0x58)) +
            (longlong)((int)*(short *)(sr + 0x56) * (int)*(short *)(sr + 0x56)) +
            (longlong)((int)*(short *)(sr + 0x54) * (int)*(short *)(sr + 0x54)) +
            (longlong)((int)*(short *)(sr + 0x52) * (int)*(short *)(sr + 0x52)) +
            (longlong)((int)*(short *)(sr + 0x50) * (int)*(short *)(sr + 0x50)) +
            (longlong)((int)*(short *)(sr + 0x4e) * (int)*(short *)(sr + 0x4e)) +
            (longlong)((int)*(short *)(sr + 0x4c) * (int)*(short *)(sr + 0x4c)) +
            (longlong)((int)*(short *)(sr + 0x4a) * (int)*(short *)(sr + 0x4a)) +
            (longlong)((int)*(short *)(sr + 0x48) * (int)*(short *)(sr + 0x48)) +
            (longlong)((int)*(short *)(sr + 0x46) * (int)*(short *)(sr + 0x46)) +
            (longlong)((int)*(short *)(sr + 0x44) * (int)*(short *)(sr + 0x44)) +
            (longlong)((int)*(short *)(sr + 0x42) * (int)*(short *)(sr + 0x42)) +
            (longlong)((int)*(short *)(sr + 0x40) * (int)*(short *)(sr + 0x40)) +
            (longlong)((int)*(short *)(sr + 0x3e) * (int)*(short *)(sr + 0x3e)) +
            (longlong)((int)*(short *)(sr + 0x3c) * (int)*(short *)(sr + 0x3c)) +
            (longlong)((int)*(short *)(sr + 0x3a) * (int)*(short *)(sr + 0x3a)) +
            (longlong)((int)*(short *)(sr + 0x38) * (int)*(short *)(sr + 0x38)) +
            (longlong)((int)*(short *)(sr + 0x36) * (int)*(short *)(sr + 0x36)) +
            (longlong)((int)*(short *)(sr + 0x34) * (int)*(short *)(sr + 0x34)) +
            (longlong)((int)*(short *)(sr + 0x32) * (int)*(short *)(sr + 0x32)) +
            (longlong)((int)*(short *)(sr + 0x30) * (int)*(short *)(sr + 0x30)) +
            (longlong)((int)*(short *)(sr + 0x2e) * (int)*(short *)(sr + 0x2e)) +
            (longlong)((int)*(short *)(sr + 0x2c) * (int)*(short *)(sr + 0x2c)) +
            (longlong)((int)*(short *)(sr + 0x2a) * (int)*(short *)(sr + 0x2a)) +
            (longlong)((int)*(short *)(sr + 0x28) * (int)*(short *)(sr + 0x28)) +
            (longlong)((int)*(short *)(sr + 0x26) * (int)*(short *)(sr + 0x26)) +
            (longlong)((int)*(short *)(sr + 0x24) * (int)*(short *)(sr + 0x24)) +
            (longlong)((int)*(short *)(sr + 0x22) * (int)*(short *)(sr + 0x22)) +
            (longlong)((int)*(short *)(sr + 0x20) * (int)*(short *)(sr + 0x20)) +
            (longlong)((int)*(short *)(sr + 0x1e) * (int)*(short *)(sr + 0x1e)) +
            (longlong)((int)*(short *)(sr + 0x1c) * (int)*(short *)(sr + 0x1c)) +
            (longlong)((int)*(short *)(sr + 0x1a) * (int)*(short *)(sr + 0x1a)) +
            (longlong)((int)*(short *)(sr + 0x18) * (int)*(short *)(sr + 0x18)) +
            (longlong)((int)*(short *)(sr + 0x16) * (int)*(short *)(sr + 0x16)) +
            (longlong)((int)*(short *)(sr + 0x14) * (int)*(short *)(sr + 0x14)) +
            (longlong)((int)*(short *)(sr + 0x12) * (int)*(short *)(sr + 0x12)) +
            (longlong)((int)*(short *)(sr + 0x10) * (int)*(short *)(sr + 0x10)) +
            (longlong)((int)*(short *)(sr + 0xe) * (int)*(short *)(sr + 0xe)) +
            (longlong)((int)*(short *)(sr + 0xc) * (int)*(short *)(sr + 0xc)) +
            (longlong)((int)*(short *)(sr + 10) * (int)*(short *)(sr + 10)) +
            (longlong)((int)*(short *)(sr + 8) * (int)*(short *)(sr + 8)) +
            (longlong)
            ((int)*(short *)(sr + (LC3_SRATE_48K|LC3_SRATE_24K)) *
            (int)*(short *)(sr + (LC3_SRATE_48K|LC3_SRATE_24K))) +
            (longlong)((int)*(short *)(sr + LC3_SRATE_48K) * (int)*(short *)(sr + LC3_SRATE_48K)) +
            (longlong)((int)*(short *)sr * (int)*(short *)sr) +
            (longlong)((int)*(short *)(sr + LC3_SRATE_24K) * (int)*(short *)(sr + LC3_SRATE_24K));
    if (iVar7 == 4) {
      lVar1 = (longlong)((int)*(short *)(sr + 0x7e) * (int)*(short *)(sr + 0x7e)) +
              (longlong)((int)*(short *)(sr + 0x7c) * (int)*(short *)(sr + 0x7c)) +
              (longlong)((int)*(short *)(sr + 0x7a) * (int)*(short *)(sr + 0x7a)) +
              (longlong)((int)*(short *)(sr + 0x78) * (int)*(short *)(sr + 0x78)) +
              (longlong)((int)*(short *)(sr + 0x76) * (int)*(short *)(sr + 0x76)) +
              (longlong)((int)*(short *)(sr + 0x74) * (int)*(short *)(sr + 0x74)) +
              (longlong)((int)*(short *)(sr + 0x72) * (int)*(short *)(sr + 0x72)) +
              (longlong)((int)*(short *)(sr + 0x70) * (int)*(short *)(sr + 0x70)) +
              (longlong)((int)*(short *)(sr + 0x6e) * (int)*(short *)(sr + 0x6e)) +
              (longlong)((int)*(short *)(sr + 0x6c) * (int)*(short *)(sr + 0x6c)) +
              (longlong)((int)*(short *)(sr + 0x6a) * (int)*(short *)(sr + 0x6a)) +
              (longlong)((int)*(short *)(sr + 0x68) * (int)*(short *)(sr + 0x68)) +
              (longlong)((int)*(short *)(sr + 0x66) * (int)*(short *)(sr + 0x66)) +
              (longlong)((int)*(short *)(sr + 100) * (int)*(short *)(sr + 100)) +
              (longlong)((int)*(short *)(sr + 0x62) * (int)*(short *)(sr + 0x62)) +
              (int)*(short *)(sr + 0x60) * (int)*(short *)(sr + 0x60) + lVar1;
    }
    psVar3 = (short *)(sr + (iVar2 + 0x11) * -2);
    fVar15 = (float)VectorSignedToFloat((uint)(lVar1 + 0x20) >> 6 |
                                        (int)((ulonglong)(lVar1 + 0x20) >> 0x20) * 0x4000000,
                                        (byte)(uVar12 >> 0x16) & 3);
    lVar1 = (longlong)((int)psVar3[0x2f] * (int)psVar3[0x2f]) +
            (longlong)((int)psVar3[0x2e] * (int)psVar3[0x2e]) +
            (longlong)((int)psVar3[0x2d] * (int)psVar3[0x2d]) +
            (longlong)((int)psVar3[0x2c] * (int)psVar3[0x2c]) +
            (longlong)((int)psVar3[0x2b] * (int)psVar3[0x2b]) +
            (longlong)((int)psVar3[0x2a] * (int)psVar3[0x2a]) +
            (longlong)((int)psVar3[0x29] * (int)psVar3[0x29]) +
            (longlong)((int)psVar3[0x28] * (int)psVar3[0x28]) +
            (longlong)((int)psVar3[0x27] * (int)psVar3[0x27]) +
            (longlong)((int)psVar3[0x26] * (int)psVar3[0x26]) +
            (longlong)((int)psVar3[0x25] * (int)psVar3[0x25]) +
            (longlong)((int)psVar3[0x24] * (int)psVar3[0x24]) +
            (longlong)((int)psVar3[0x23] * (int)psVar3[0x23]) +
            (longlong)((int)psVar3[0x22] * (int)psVar3[0x22]) +
            (longlong)((int)psVar3[0x21] * (int)psVar3[0x21]) +
            (longlong)((int)psVar3[0x20] * (int)psVar3[0x20]) +
            (longlong)((int)psVar3[0x1f] * (int)psVar3[0x1f]) +
            (longlong)((int)psVar3[0x1e] * (int)psVar3[0x1e]) +
            (longlong)((int)psVar3[0x1d] * (int)psVar3[0x1d]) +
            (longlong)((int)psVar3[0x1c] * (int)psVar3[0x1c]) +
            (longlong)((int)psVar3[0x1b] * (int)psVar3[0x1b]) +
            (longlong)((int)psVar3[0x1a] * (int)psVar3[0x1a]) +
            (longlong)((int)psVar3[0x19] * (int)psVar3[0x19]) +
            (longlong)((int)psVar3[0x18] * (int)psVar3[0x18]) +
            (longlong)((int)psVar3[0x17] * (int)psVar3[0x17]) +
            (longlong)((int)psVar3[0x16] * (int)psVar3[0x16]) +
            (longlong)((int)psVar3[0x15] * (int)psVar3[0x15]) +
            (longlong)((int)psVar3[0x14] * (int)psVar3[0x14]) +
            (longlong)((int)psVar3[0x13] * (int)psVar3[0x13]) +
            (longlong)((int)psVar3[0x12] * (int)psVar3[0x12]) +
            (longlong)((int)psVar3[0x11] * (int)psVar3[0x11]) +
            (longlong)((int)psVar3[0x10] * (int)psVar3[0x10]) +
            (longlong)((int)psVar3[0xf] * (int)psVar3[0xf]) +
            (longlong)((int)psVar3[0xe] * (int)psVar3[0xe]) +
            (longlong)((int)psVar3[0xd] * (int)psVar3[0xd]) +
            (longlong)((int)psVar3[0xc] * (int)psVar3[0xc]) +
            (longlong)((int)psVar3[0xb] * (int)psVar3[0xb]) +
            (longlong)((int)psVar3[10] * (int)psVar3[10]) +
            (longlong)((int)psVar3[9] * (int)psVar3[9]) +
            (longlong)((int)psVar3[8] * (int)psVar3[8]) +
            (longlong)((int)psVar3[7] * (int)psVar3[7]) +
            (longlong)((int)psVar3[6] * (int)psVar3[6]) +
            (longlong)((int)psVar3[5] * (int)psVar3[5]) +
            (longlong)((int)psVar3[4] * (int)psVar3[4]) +
            (longlong)((int)psVar3[3] * (int)psVar3[3]) +
            (longlong)((int)psVar3[2] * (int)psVar3[2]) +
            (longlong)((int)psVar3[1] * (int)psVar3[1]) + (longlong)((int)*psVar3 * (int)*psVar3);
    if (iVar7 == 4) {
      lVar1 = (longlong)((int)psVar3[0x3f] * (int)psVar3[0x3f]) +
              (longlong)((int)psVar3[0x3e] * (int)psVar3[0x3e]) +
              (longlong)((int)psVar3[0x3d] * (int)psVar3[0x3d]) +
              (longlong)((int)psVar3[0x3c] * (int)psVar3[0x3c]) +
              (longlong)((int)psVar3[0x3b] * (int)psVar3[0x3b]) +
              (longlong)((int)psVar3[0x3a] * (int)psVar3[0x3a]) +
              (longlong)((int)psVar3[0x39] * (int)psVar3[0x39]) +
              (longlong)((int)psVar3[0x38] * (int)psVar3[0x38]) +
              (longlong)((int)psVar3[0x37] * (int)psVar3[0x37]) +
              (longlong)((int)psVar3[0x36] * (int)psVar3[0x36]) +
              (longlong)((int)psVar3[0x35] * (int)psVar3[0x35]) +
              (longlong)((int)psVar3[0x34] * (int)psVar3[0x34]) +
              (longlong)((int)psVar3[0x33] * (int)psVar3[0x33]) +
              (longlong)((int)psVar3[0x32] * (int)psVar3[0x32]) +
              (longlong)((int)psVar3[0x31] * (int)psVar3[0x31]) +
              (int)psVar3[0x30] * (int)psVar3[0x30] + lVar1;
    }
    fVar13 = (float)VectorSignedToFloat((uint)(lVar1 + 0x20) >> 6 |
                                        (int)((ulonglong)(lVar1 + 0x20) >> 0x20) * 0x4000000,
                                        (byte)(uVar12 >> 0x16) & 3);
    uVar12 = in_fpscr | (uint)(fVar16 < 0.0) << 0x1f | (uint)(fVar16 == 0.0) << 0x1e;
    local_1b0[0] = local_1b0[0] / SQRT(fVar13 * fVar15);
    bVar11 = (byte)(uVar12 >> 0x18);
    fVar15 = local_1b0[0] * 0.85;
    if ((bool)(bVar11 >> 6 & 1) || (bool)(bVar11 >> 7) != NAN(fVar16)) {
LAB_0006d7f4:
      fVar16 = 0.0;
      goto LAB_0006d79a;
    }
  }
  lVar1 = (longlong)((int)*(short *)(sr + 0x5e) * (int)*(short *)(sr + 0x5e)) +
          (longlong)((int)*(short *)(sr + 0x5c) * (int)*(short *)(sr + 0x5c)) +
          (longlong)((int)*(short *)(sr + 0x5a) * (int)*(short *)(sr + 0x5a)) +
          (longlong)((int)*(short *)(sr + 0x58) * (int)*(short *)(sr + 0x58)) +
          (longlong)((int)*(short *)(sr + 0x56) * (int)*(short *)(sr + 0x56)) +
          (longlong)((int)*(short *)(sr + 0x54) * (int)*(short *)(sr + 0x54)) +
          (longlong)((int)*(short *)(sr + 0x52) * (int)*(short *)(sr + 0x52)) +
          (longlong)((int)*(short *)(sr + 0x50) * (int)*(short *)(sr + 0x50)) +
          (longlong)((int)*(short *)(sr + 0x4e) * (int)*(short *)(sr + 0x4e)) +
          (longlong)((int)*(short *)(sr + 0x4c) * (int)*(short *)(sr + 0x4c)) +
          (longlong)((int)*(short *)(sr + 0x4a) * (int)*(short *)(sr + 0x4a)) +
          (longlong)((int)*(short *)(sr + 0x48) * (int)*(short *)(sr + 0x48)) +
          (longlong)((int)*(short *)(sr + 0x46) * (int)*(short *)(sr + 0x46)) +
          (longlong)((int)*(short *)(sr + 0x44) * (int)*(short *)(sr + 0x44)) +
          (longlong)((int)*(short *)(sr + 0x42) * (int)*(short *)(sr + 0x42)) +
          (longlong)((int)*(short *)(sr + 0x40) * (int)*(short *)(sr + 0x40)) +
          (longlong)((int)*(short *)(sr + 0x3e) * (int)*(short *)(sr + 0x3e)) +
          (longlong)((int)*(short *)(sr + 0x3c) * (int)*(short *)(sr + 0x3c)) +
          (longlong)((int)*(short *)(sr + 0x3a) * (int)*(short *)(sr + 0x3a)) +
          (longlong)((int)*(short *)(sr + 0x38) * (int)*(short *)(sr + 0x38)) +
          (longlong)((int)*(short *)(sr + 0x36) * (int)*(short *)(sr + 0x36)) +
          (longlong)((int)*(short *)(sr + 0x34) * (int)*(short *)(sr + 0x34)) +
          (longlong)((int)*(short *)(sr + 0x32) * (int)*(short *)(sr + 0x32)) +
          (longlong)((int)*(short *)(sr + 0x30) * (int)*(short *)(sr + 0x30)) +
          (longlong)((int)*(short *)(sr + 0x2e) * (int)*(short *)(sr + 0x2e)) +
          (longlong)((int)*(short *)(sr + 0x2c) * (int)*(short *)(sr + 0x2c)) +
          (longlong)((int)*(short *)(sr + 0x2a) * (int)*(short *)(sr + 0x2a)) +
          (longlong)((int)*(short *)(sr + 0x28) * (int)*(short *)(sr + 0x28)) +
          (longlong)((int)*(short *)(sr + 0x26) * (int)*(short *)(sr + 0x26)) +
          (longlong)((int)*(short *)(sr + 0x24) * (int)*(short *)(sr + 0x24)) +
          (longlong)((int)*(short *)(sr + 0x22) * (int)*(short *)(sr + 0x22)) +
          (longlong)((int)*(short *)(sr + 0x20) * (int)*(short *)(sr + 0x20)) +
          (longlong)((int)*(short *)(sr + 0x1e) * (int)*(short *)(sr + 0x1e)) +
          (longlong)((int)*(short *)(sr + 0x1c) * (int)*(short *)(sr + 0x1c)) +
          (longlong)((int)*(short *)(sr + 0x1a) * (int)*(short *)(sr + 0x1a)) +
          (longlong)((int)*(short *)(sr + 0x18) * (int)*(short *)(sr + 0x18)) +
          (longlong)((int)*(short *)(sr + 0x16) * (int)*(short *)(sr + 0x16)) +
          (longlong)((int)*(short *)(sr + 0x14) * (int)*(short *)(sr + 0x14)) +
          (longlong)((int)*(short *)(sr + 0x12) * (int)*(short *)(sr + 0x12)) +
          (longlong)((int)*(short *)(sr + 0x10) * (int)*(short *)(sr + 0x10)) +
          (longlong)((int)*(short *)(sr + 0xe) * (int)*(short *)(sr + 0xe)) +
          (longlong)((int)*(short *)(sr + 0xc) * (int)*(short *)(sr + 0xc)) +
          (longlong)((int)*(short *)(sr + 10) * (int)*(short *)(sr + 10)) +
          (longlong)((int)*(short *)(sr + 8) * (int)*(short *)(sr + 8)) +
          (longlong)
          ((int)*(short *)(sr + (LC3_SRATE_48K|LC3_SRATE_24K)) *
          (int)*(short *)(sr + (LC3_SRATE_48K|LC3_SRATE_24K))) +
          (longlong)((int)*(short *)(sr + LC3_SRATE_48K) * (int)*(short *)(sr + LC3_SRATE_48K)) +
          (longlong)((int)*(short *)(sr + LC3_SRATE_24K) * (int)*(short *)(sr + LC3_SRATE_24K)) +
          (longlong)((int)*(short *)sr * (int)*(short *)sr);
  if (iVar7 == 4) {
    lVar1 = (longlong)((int)*(short *)(sr + 0x7e) * (int)*(short *)(sr + 0x7e)) +
            (longlong)((int)*(short *)(sr + 0x7c) * (int)*(short *)(sr + 0x7c)) +
            (longlong)((int)*(short *)(sr + 0x7a) * (int)*(short *)(sr + 0x7a)) +
            (longlong)((int)*(short *)(sr + 0x78) * (int)*(short *)(sr + 0x78)) +
            (longlong)((int)*(short *)(sr + 0x76) * (int)*(short *)(sr + 0x76)) +
            (longlong)((int)*(short *)(sr + 0x74) * (int)*(short *)(sr + 0x74)) +
            (longlong)((int)*(short *)(sr + 0x72) * (int)*(short *)(sr + 0x72)) +
            (longlong)((int)*(short *)(sr + 0x70) * (int)*(short *)(sr + 0x70)) +
            (longlong)((int)*(short *)(sr + 0x6e) * (int)*(short *)(sr + 0x6e)) +
            (longlong)((int)*(short *)(sr + 0x6c) * (int)*(short *)(sr + 0x6c)) +
            (longlong)((int)*(short *)(sr + 0x6a) * (int)*(short *)(sr + 0x6a)) +
            (longlong)((int)*(short *)(sr + 0x68) * (int)*(short *)(sr + 0x68)) +
            (longlong)((int)*(short *)(sr + 0x66) * (int)*(short *)(sr + 0x66)) +
            (longlong)((int)*(short *)(sr + 100) * (int)*(short *)(sr + 100)) +
            (longlong)((int)*(short *)(sr + 0x62) * (int)*(short *)(sr + 0x62)) +
            (int)*(short *)(sr + 0x60) * (int)*(short *)(sr + 0x60) + lVar1;
  }
  psVar3 = (short *)(sr + local_26c * -2);
  fVar13 = (float)VectorSignedToFloat((uint)(lVar1 + 0x20) >> 6 |
                                      (int)((ulonglong)(lVar1 + 0x20) >> 0x20) * 0x4000000,
                                      (byte)(uVar12 >> 0x16) & 3);
  lVar1 = (longlong)((int)psVar3[0x2f] * (int)psVar3[0x2f]) +
          (longlong)((int)psVar3[0x2e] * (int)psVar3[0x2e]) +
          (longlong)((int)psVar3[0x2d] * (int)psVar3[0x2d]) +
          (longlong)((int)psVar3[0x2c] * (int)psVar3[0x2c]) +
          (longlong)((int)psVar3[0x2b] * (int)psVar3[0x2b]) +
          (longlong)((int)psVar3[0x2a] * (int)psVar3[0x2a]) +
          (longlong)((int)psVar3[0x29] * (int)psVar3[0x29]) +
          (longlong)((int)psVar3[0x28] * (int)psVar3[0x28]) +
          (longlong)((int)psVar3[0x27] * (int)psVar3[0x27]) +
          (longlong)((int)psVar3[0x26] * (int)psVar3[0x26]) +
          (longlong)((int)psVar3[0x25] * (int)psVar3[0x25]) +
          (longlong)((int)psVar3[0x24] * (int)psVar3[0x24]) +
          (longlong)((int)psVar3[0x23] * (int)psVar3[0x23]) +
          (longlong)((int)psVar3[0x22] * (int)psVar3[0x22]) +
          (longlong)((int)psVar3[0x21] * (int)psVar3[0x21]) +
          (longlong)((int)psVar3[0x20] * (int)psVar3[0x20]) +
          (longlong)((int)psVar3[0x1f] * (int)psVar3[0x1f]) +
          (longlong)((int)psVar3[0x1e] * (int)psVar3[0x1e]) +
          (longlong)((int)psVar3[0x1d] * (int)psVar3[0x1d]) +
          (longlong)((int)psVar3[0x1c] * (int)psVar3[0x1c]) +
          (longlong)((int)psVar3[0x1b] * (int)psVar3[0x1b]) +
          (longlong)((int)psVar3[0x1a] * (int)psVar3[0x1a]) +
          (longlong)((int)psVar3[0x19] * (int)psVar3[0x19]) +
          (longlong)((int)psVar3[0x18] * (int)psVar3[0x18]) +
          (longlong)((int)psVar3[0x17] * (int)psVar3[0x17]) +
          (longlong)((int)psVar3[0x16] * (int)psVar3[0x16]) +
          (longlong)((int)psVar3[0x15] * (int)psVar3[0x15]) +
          (longlong)((int)psVar3[0x14] * (int)psVar3[0x14]) +
          (longlong)((int)psVar3[0x13] * (int)psVar3[0x13]) +
          (longlong)((int)psVar3[0x12] * (int)psVar3[0x12]) +
          (longlong)((int)psVar3[0x11] * (int)psVar3[0x11]) +
          (longlong)((int)psVar3[0x10] * (int)psVar3[0x10]) +
          (longlong)((int)psVar3[0xf] * (int)psVar3[0xf]) +
          (longlong)((int)psVar3[0xe] * (int)psVar3[0xe]) +
          (longlong)((int)psVar3[0xd] * (int)psVar3[0xd]) +
          (longlong)((int)psVar3[0xc] * (int)psVar3[0xc]) +
          (longlong)((int)psVar3[0xb] * (int)psVar3[0xb]) +
          (longlong)((int)psVar3[10] * (int)psVar3[10]) +
          (longlong)((int)psVar3[9] * (int)psVar3[9]) +
          (longlong)((int)psVar3[8] * (int)psVar3[8]) +
          (longlong)((int)psVar3[7] * (int)psVar3[7]) +
          (longlong)((int)psVar3[6] * (int)psVar3[6]) +
          (longlong)((int)psVar3[5] * (int)psVar3[5]) +
          (longlong)((int)psVar3[4] * (int)psVar3[4]) +
          (longlong)((int)psVar3[3] * (int)psVar3[3]) +
          (longlong)((int)psVar3[2] * (int)psVar3[2]) +
          (longlong)((int)*psVar3 * (int)*psVar3) + (longlong)((int)psVar3[1] * (int)psVar3[1]);
  if (iVar7 == 4) {
    lVar1 = (longlong)((int)psVar3[0x3f] * (int)psVar3[0x3f]) +
            (longlong)((int)psVar3[0x3e] * (int)psVar3[0x3e]) +
            (longlong)((int)psVar3[0x3d] * (int)psVar3[0x3d]) +
            (longlong)((int)psVar3[0x3c] * (int)psVar3[0x3c]) +
            (longlong)((int)psVar3[0x3b] * (int)psVar3[0x3b]) +
            (longlong)((int)psVar3[0x3a] * (int)psVar3[0x3a]) +
            (longlong)((int)psVar3[0x39] * (int)psVar3[0x39]) +
            (longlong)((int)psVar3[0x38] * (int)psVar3[0x38]) +
            (longlong)((int)psVar3[0x37] * (int)psVar3[0x37]) +
            (longlong)((int)psVar3[0x36] * (int)psVar3[0x36]) +
            (longlong)((int)psVar3[0x35] * (int)psVar3[0x35]) +
            (longlong)((int)psVar3[0x34] * (int)psVar3[0x34]) +
            (longlong)((int)psVar3[0x33] * (int)psVar3[0x33]) +
            (longlong)((int)psVar3[0x32] * (int)psVar3[0x32]) +
            (longlong)((int)psVar3[0x31] * (int)psVar3[0x31]) +
            (int)psVar3[0x30] * (int)psVar3[0x30] + lVar1;
  }
  fVar14 = (float)VectorSignedToFloat((uint)(lVar1 + 0x20) >> 6 |
                                      (int)((ulonglong)(lVar1 + 0x20) >> 0x20) * 0x4000000,
                                      (byte)(uVar12 >> 0x16) & 3);
  fVar16 = fVar16 / SQRT(fVar14 * fVar13);
LAB_0006d79a:
  if (fVar16 <= fVar15) {
    iVar8 = iVar2;
    local_26c = iVar2 + 0x11;
    fVar16 = local_1b0[0];
  }
  *(int *)(dt + 0x484) = iVar8;
  *(int *)x = local_26c;
  return 0.6 < fVar16;
}


