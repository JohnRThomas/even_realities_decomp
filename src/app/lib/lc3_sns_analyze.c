/*
 * Function: lc3_sns_analyze
 * Entry:    0006fa20
 * Prototype: void __stdcall lc3_sns_analyze(lc3_dt dt, lc3_srate sr, float * eb, bool att, lc3_sns_data_t * data, float * x, float * y)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* exclude_from_export_ai */

void lc3_sns_analyze(lc3_dt dt,lc3_srate sr,float *eb,bool att,lc3_sns_data_t *data,float *x,
                    float *y)

{
  bool bVar1;
  int iVar2;
  float *pfVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  lc3_srate sr_00;
  float fVar12;
  int iVar13;
  uint uVar14;
  lc3_dt dt_00;
  int iVar15;
  int iVar16;
  byte bVar17;
  bool bVar18;
  byte bVar19;
  uint in_fpscr;
  uint uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  undefined4 uVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float local_33c;
  float local_328;
  float local_324;
  float local_320;
  float local_31c;
  float local_318;
  float local_314;
  float local_310;
  float local_30c;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8 [4];
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2c4;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8 [15];
  float local_26c;
  float local_268 [62];
  uint auStack_170 [2];
  float local_168 [10];
  int local_140;
  float local_13c;
  float local_138;
  float local_134;
  uint local_130;
  float local_12c;
  float local_128 [9];
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8 [15];
  float local_ac;
  float local_a8 [15];
  float local_6c;
  float fStack_68;
  
  iVar9 = *(int *)(&DAT_000948e0 + dt * 0x514 + sr * 0x104);
  if (0x3f < iVar9) {
    iVar9 = 0x40;
  }
  iVar2 = 0x40 - iVar9;
  if (iVar2 == 0) {
    iVar16 = 0;
  }
  else {
    iVar16 = iVar2 * 4;
    pfVar7 = eb;
    pfVar3 = local_168;
    do {
      pfVar10 = pfVar7 + 1;
      fVar12 = *pfVar7;
      pfVar3[1] = fVar12;
      *pfVar3 = fVar12;
      pfVar7 = pfVar10;
      pfVar3 = pfVar3 + 2;
    } while (eb + iVar2 != pfVar10);
  }
  memcpy(local_168 + iVar2 * 2,(void *)((int)eb + iVar16),(iVar9 - iVar2) * 4);
  fVar22 = 0.0;
  pfVar3 = (float *)(&DAT_000904dc + sr * 0x100);
  pfVar7 = local_168;
  fVar12 = local_168[0];
  fVar21 = local_168[0];
  do {
    fVar34 = pfVar7[1] * 0.25;
    pfVar10 = pfVar7 + 3;
    fVar29 = fVar12 * 0.25;
    fVar12 = pfVar7[2];
    fVar27 = (fVar34 + fVar21 * 0.5 + fVar29) * *pfVar3;
    fVar29 = fVar21 * 0.25;
    fVar21 = *pfVar10;
    fVar29 = (fVar12 * 0.25 + pfVar7[1] * 0.5 + fVar29) * pfVar3[1];
    fVar34 = (fVar34 + fVar12 * 0.5 + fVar21 * 0.25) * pfVar3[2];
    pfVar7[1] = fVar29;
    *pfVar7 = fVar27;
    pfVar7[2] = fVar34;
    fVar22 = fVar29 + fVar34 + fVar22 + fVar27;
    pfVar3 = pfVar3 + 3;
    pfVar7 = pfVar10;
  } while (&local_6c != pfVar10);
  local_6c = (fVar12 * 0.25 + fVar21 * 0.75) * *(float *)(&DAT_000905d8 + sr * 0x100);
  uVar48 = FPMaxNum((fVar22 + local_6c) * 1.5625e-06,0x2f800000);
  pfVar7 = local_168;
  do {
    fVar12 = (float)FPMaxNum(uVar48,*pfVar7);
    fVar12 = frexpf(fVar12,(int *)local_268);
    fVar21 = (float)VectorSignedToFloat(local_268[0],(byte)(in_fpscr >> 0x16) & 3);
    *pfVar7 = ((fVar21 - 3.5056736) +
              fVar12 * (fVar12 * (fVar12 * (fVar12 * -1.2947968 + 5.11769) + -8.422953) + 8.105579))
              * 0.5;
    pfVar7 = pfVar7 + 1;
  } while (&fStack_68 != pfVar7);
  fVar34 = (local_168[4] + local_168[7]) * 0.16666667 + (local_168[3] + local_168[8]) * 0.083333336
           + (local_168[6] + local_168[5]) * 0.25;
  fVar30 = (local_12c + local_138) * 0.16666667 + (local_128[0] + local_13c) * 0.083333336 +
           ((float)local_130 + local_134) * 0.25;
  fVar22 = (local_13c + local_168[8]) * 0.16666667 + (local_138 + local_168[7]) * 0.083333336 +
           ((float)local_140 + local_168[9]) * 0.25;
  fVar29 = (local_168[0] + local_168[3]) * 0.16666667 + (local_168[0] + local_168[4]) * 0.083333336
           + (local_168[1] + local_168[2]) * 0.25;
  fVar27 = (local_128[7] + local_128[4]) * 0.16666667 + (local_128[8] + local_128[3]) * 0.083333336
           + (local_128[6] + local_128[5]) * 0.25;
  fVar21 = (local_128[3] + local_128[0]) * 0.16666667 + (local_128[4] + local_12c) * 0.083333336 +
           (local_128[2] + local_128[1]) * 0.25;
  fVar26 = (local_fc + local_128[8]) * 0.16666667 + (local_f8 + local_128[7]) * 0.083333336 +
           (local_100 + local_104) * 0.25;
  fVar28 = (local_ec + local_f8) * 0.16666667 + (local_e8[0] + local_fc) * 0.083333336 +
           (local_f0 + local_f4) * 0.25;
  fVar23 = (local_e8[7] + local_e8[4]) * 0.16666667 + (local_e8[8] + local_e8[3]) * 0.083333336 +
           (local_e8[6] + local_e8[5]) * 0.25;
  fVar12 = (local_e8[3] + local_e8[0]) * 0.16666667 + (local_e8[4] + local_ec) * 0.083333336 +
           (local_e8[2] + local_e8[1]) * 0.25;
  fVar46 = (local_e8[8] + local_e8[0xb]) * 0.16666667 + (local_e8[0xc] + local_e8[7]) * 0.083333336
           + (local_e8[9] + local_e8[10]) * 0.25;
  fVar35 = (local_e8[0xc] + local_ac) * 0.16666667 + (local_a8[0] + local_e8[0xb]) * 0.083333336 +
           (local_e8[0xd] + local_e8[0xe]) * 0.25;
  fVar24 = (local_a8[0] + local_a8[3]) * 0.16666667 + (local_ac + local_a8[4]) * 0.083333336 +
           (local_a8[2] + local_a8[1]) * 0.25;
  fVar47 = (local_a8[4] + local_a8[7]) * 0.16666667 + (local_a8[3] + local_a8[8]) * 0.083333336 +
           (local_a8[6] + local_a8[5]) * 0.25;
  fVar36 = (local_a8[0xb] + local_a8[8]) * 0.16666667 + (local_a8[0xc] + local_a8[7]) * 0.083333336
           + (local_a8[10] + local_a8[9]) * 0.25;
  fVar25 = (local_6c + local_a8[0xc]) * 0.16666667 + (local_a8[0xb] + local_6c) * 0.083333336 +
           (local_a8[0xd] + local_a8[0xe]) * 0.25;
  fVar37 = fVar25 + fVar36 + fVar35 + fVar23 + fVar12 + fVar28 + fVar26 + fVar27 + fVar21 + fVar30 +
                                                                                            fVar22 +
                                                                                            fVar29 +
                                                                                            fVar34 +
                                      fVar46 + fVar24 + fVar47;
  local_328 = (fVar29 + -fVar37 * 0.0625) * 0.85;
  local_320 = (fVar22 + -fVar37 * 0.0625) * 0.85;
  local_31c = (fVar30 + -fVar37 * 0.0625) * 0.85;
  local_324 = (fVar34 + -fVar37 * 0.0625) * 0.85;
  local_318 = (fVar21 + -fVar37 * 0.0625) * 0.85;
  local_314 = (fVar27 + -fVar37 * 0.0625) * 0.85;
  local_310 = (fVar26 + -fVar37 * 0.0625) * 0.85;
  local_30c = (fVar28 + -fVar37 * 0.0625) * 0.85;
  local_308 = (fVar12 + -fVar37 * 0.0625) * 0.85;
  local_304 = (fVar23 + -fVar37 * 0.0625) * 0.85;
  local_300 = (fVar46 + -fVar37 * 0.0625) * 0.85;
  local_2fc = (fVar35 + -fVar37 * 0.0625) * 0.85;
  local_2f8 = (fVar24 + -fVar37 * 0.0625) * 0.85;
  local_2f4 = (fVar47 + -fVar37 * 0.0625) * 0.85;
  local_2f0 = (fVar36 + -fVar37 * 0.0625) * 0.85;
  local_2ec = (fVar25 + -fVar37 * 0.0625) * 0.85;
  if (att) {
    fVar21 = local_324 + local_328 + local_320;
    fVar12 = fVar21 + local_31c + local_318;
    fVar25 = (fVar21 + local_31c) * 0.25;
    fVar34 = (float)((uint)(dt == 0) * 0x3e99999a + (uint)(dt != 0) * 0x3f000000);
    fVar28 = (local_314 - local_328) + fVar12;
    fVar22 = (local_310 - local_324) + fVar28;
    fVar30 = (local_30c - local_320) + fVar22;
    fVar35 = (local_308 - local_31c) + fVar30;
    fVar29 = (local_304 - local_318) + fVar35;
    fVar36 = (local_300 - local_314) + fVar29;
    fVar27 = (local_2fc - local_310) + fVar36;
    fVar37 = (local_2f8 - local_30c) + fVar27;
    fVar46 = (local_2f4 - local_308) + fVar37;
    fVar23 = (local_2f0 - local_304) + fVar46;
    fVar24 = (local_2ec - local_300) + fVar23;
    local_2fc = fVar24 - local_2fc;
    fVar26 = (fVar25 + fVar21 * 0.33333334 + fVar12 * 0.2 + fVar28 * 0.2 + fVar22 * 0.2 +
              fVar30 * 0.2 + fVar35 * 0.2 + fVar29 * 0.2 + fVar36 * 0.2 + fVar27 * 0.2 +
              fVar37 * 0.2 + fVar46 * 0.2 + fVar23 * 0.2 + fVar24 * 0.2 + local_2fc * 0.25 +
             (local_2fc - local_2f8) * 0.33333334) * 0.0625;
    local_324 = (fVar25 - fVar26) * fVar34;
    local_2f0 = fVar34 * (-fVar26 + local_2fc * 0.25);
    local_328 = fVar34 * (-fVar26 + fVar21 * 0.33333334);
    local_2ec = (-fVar26 + (local_2fc - local_2f8) * 0.33333334) * fVar34;
    local_320 = fVar34 * (-fVar26 + fVar12 * 0.2);
    local_31c = fVar34 * (-fVar26 + fVar28 * 0.2);
    local_318 = fVar34 * (-fVar26 + fVar22 * 0.2);
    local_314 = fVar34 * (-fVar26 + fVar30 * 0.2);
    local_310 = fVar34 * (-fVar26 + fVar35 * 0.2);
    local_30c = fVar34 * (-fVar26 + fVar29 * 0.2);
    local_308 = fVar34 * (-fVar26 + fVar36 * 0.2);
    local_304 = fVar34 * (-fVar26 + fVar27 * 0.2);
    local_300 = fVar34 * (-fVar26 + fVar37 * 0.2);
    local_2fc = fVar34 * (-fVar26 + fVar46 * 0.2);
    local_2f8 = fVar34 * (-fVar26 + fVar23 * 0.2);
    local_2f4 = fVar34 * (-fVar26 + fVar24 * 0.2);
  }
  iVar9 = 0;
  pfVar7 = (float *)&DAT_000943e0;
  pfVar3 = (float *)&DAT_00093fe0;
  *(undefined4 *)data->opaque = 0;
  *(undefined4 *)data[1].opaque = 0;
  fVar12 = 0.0;
  fVar21 = 0.0;
  do {
    while( true ) {
      fVar22 = (local_324 - pfVar7[1]) * (local_324 - pfVar7[1]) +
               (local_328 - *pfVar7) * (local_328 - *pfVar7) +
               (local_320 - pfVar7[2]) * (local_320 - pfVar7[2]) +
               (local_31c - pfVar7[3]) * (local_31c - pfVar7[3]) +
               (local_318 - pfVar7[4]) * (local_318 - pfVar7[4]) +
               (local_314 - pfVar7[5]) * (local_314 - pfVar7[5]) +
               (local_310 - pfVar7[6]) * (local_310 - pfVar7[6]) +
               (local_30c - pfVar7[7]) * (local_30c - pfVar7[7]);
      fVar29 = (local_304 - pfVar3[1]) * (local_304 - pfVar3[1]) +
               (local_308 - *pfVar3) * (local_308 - *pfVar3) +
               (local_300 - pfVar3[2]) * (local_300 - pfVar3[2]) +
               (local_2fc - pfVar3[3]) * (local_2fc - pfVar3[3]) +
               (local_2f8 - pfVar3[4]) * (local_2f8 - pfVar3[4]) +
               (local_2f4 - pfVar3[5]) * (local_2f4 - pfVar3[5]) +
               (local_2f0 - pfVar3[6]) * (local_2f0 - pfVar3[6]) +
               (local_2ec - pfVar3[7]) * (local_2ec - pfVar3[7]);
      if (iVar9 != 0) break;
      *(undefined4 *)data->opaque = 0;
      *(undefined4 *)data[1].opaque = 0;
      iVar9 = 1;
      pfVar7 = pfVar7 + 8;
      pfVar3 = pfVar3 + 8;
      fVar12 = fVar22;
      fVar21 = fVar29;
    }
    if (fVar22 < fVar12) {
      *(int *)data->opaque = iVar9;
      fVar12 = fVar22;
    }
    uVar6 = in_fpscr & 0xfffffff | (uint)(fVar21 < fVar29) << 0x1f |
            (uint)(fVar21 == fVar29) << 0x1e;
    in_fpscr = uVar6 | (uint)(NAN(fVar21) || NAN(fVar29)) << 0x1c;
    bVar19 = (byte)(uVar6 >> 0x18);
    if (!(bool)(bVar19 >> 6 & 1) && bVar19 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      *(int *)data[1].opaque = iVar9;
      fVar21 = fVar29;
    }
    iVar9 = iVar9 + 1;
    pfVar7 = pfVar7 + 8;
    pfVar3 = pfVar3 + 8;
  } while (iVar9 != 0x20);
  dt_00 = *(lc3_dt *)data->opaque;
  sr_00 = *(lc3_srate *)data[1].opaque;
  fVar36 = (float)(&DAT_000943e0)[dt_00 * 8];
  fVar35 = (float)(&DAT_00093fe0)[sr_00 * 8];
  fVar30 = (float)(&DAT_000943e4)[dt_00 * 8];
  fVar28 = (float)(&DAT_00093fe4)[sr_00 * 8];
  fVar26 = (float)(&DAT_000943e8)[dt_00 * 8];
  fVar25 = (float)(&DAT_00093fe8)[sr_00 * 8];
  fVar24 = (float)(&DAT_000943ec)[dt_00 * 8];
  fVar23 = (float)(&DAT_00093fec)[sr_00 * 8];
  fVar34 = (float)(&DAT_000943f0)[dt_00 * 8];
  fVar27 = (float)(&DAT_00093ff0)[sr_00 * 8];
  fVar29 = (float)(&DAT_000943f4)[dt_00 * 8];
  fVar22 = (float)(&DAT_00093ff4)[sr_00 * 8];
  fVar21 = (float)(&DAT_000943f8)[dt_00 * 8];
  fVar12 = (float)(&DAT_000943fc)[dt_00 * 8];
  fVar37 = (float)(&DAT_00093ff8)[sr_00 * 8];
  fVar46 = (float)(&DAT_00093ffc)[sr_00 * 8];
  pfVar7 = local_2e8;
  pfVar3 = (float *)&DAT_000909dc;
  do {
    pfVar10 = pfVar3 + 1;
    *pfVar7 = (local_320 - fVar26) * pfVar3[0x20] + pfVar3[0x10] * (local_324 - fVar30) +
              *pfVar3 * (local_328 - fVar36) + pfVar3[0x30] * (local_31c - fVar24) +
              (local_318 - fVar34) * pfVar3[0x40] + (local_314 - fVar29) * pfVar3[0x50] +
              (local_310 - fVar21) * pfVar3[0x60] + (local_30c - fVar12) * pfVar3[0x70] +
              pfVar3[0x80] * (local_308 - fVar35) + (local_304 - fVar28) * pfVar3[0x90] +
              (local_300 - fVar25) * pfVar3[0xa0] + (local_2fc - fVar23) * pfVar3[0xb0] +
              (local_2f8 - fVar27) * pfVar3[0xc0] + (local_2f4 - fVar22) * pfVar3[0xd0] +
              (local_2f0 - fVar37) * pfVar3[0xe0] + (local_2ec - fVar46) * pfVar3[0xf0];
    pfVar7 = pfVar7 + 1;
    pfVar3 = pfVar10;
  } while (pfVar10 != (float *)&DAT_00090a1c);
  local_2a8[1] = ABS(local_2e8[1]);
  local_2a8[0] = ABS(local_2e8[0]);
  local_2a8[2] = ABS(local_2e8[2]);
  local_2a8[3] = ABS(local_2e8[3]);
  local_2a8[4] = ABS(local_2d8);
  local_2a8[5] = ABS(local_2d4);
  local_2a8[6] = ABS(local_2d0);
  local_2a8[7] = ABS(local_2cc);
  local_2a8[8] = ABS(local_2c8);
  local_2a8[9] = ABS(local_2c4);
  local_2a8[10] = ABS(local_2c0);
  local_2a8[0xb] = ABS(local_2bc);
  local_2a8[0xc] = ABS(local_2b8);
  local_2a8[0xd] = ABS(local_2b4);
  local_2a8[0xe] = ABS(local_2b0);
  local_26c = ABS(local_2ac);
  fVar21 = (float)FPMaxNum(local_26c +
                           local_2a8[0xe] +
                           local_2a8[0xd] +
                           local_2a8[0xc] +
                           local_2a8[0xb] +
                           local_2a8[10] +
                           local_2a8[9] +
                           local_2a8[8] +
                           local_2a8[7] +
                           local_2a8[6] +
                           local_2a8[5] +
                           local_2a8[4] + local_2a8[3] + local_2a8[2] + local_2a8[1] + local_2a8[0],
                           0xc01ceb3);
  fVar21 = 5.0 / fVar21;
  fVar24 = (float)FPRoundInt(fVar21 * local_2a8[0],0x20,2,0);
  fVar36 = (float)FPRoundInt(fVar21 * local_2a8[0xc],0x20,2,0);
  fVar25 = (float)FPRoundInt(fVar21 * local_2a8[1],0x20,2,0);
  fVar26 = (float)FPRoundInt(fVar21 * local_2a8[0xd],0x20,2,0);
  fVar38 = (float)FPRoundInt(local_26c * fVar21,0x20,2,0);
  fVar28 = (float)FPRoundInt(fVar21 * local_2a8[0xe],0x20,2,0);
  local_a8[0] = (float)(int)fVar24;
  fVar23 = (float)FPRoundInt(fVar21 * local_2a8[2],0x20,2,0);
  local_a8[1] = (float)(int)fVar25;
  local_a8[2] = (float)(int)fVar23;
  fVar34 = (float)FPRoundInt(fVar21 * local_2a8[3],0x20,2,0);
  fVar30 = (float)VectorSignedToFloat((int)local_a8[1] * (int)local_a8[1],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar37 = (float)VectorSignedToFloat((int)local_a8[0] * (int)local_a8[0],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[3] = (float)(int)fVar34;
  fVar27 = (float)FPRoundInt(fVar21 * local_2a8[4],0x20,2,0);
  fVar39 = (float)VectorSignedToFloat((int)local_a8[2] * (int)local_a8[2],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[4] = (float)(int)fVar27;
  fVar29 = (float)FPRoundInt(fVar21 * local_2a8[5],0x20,2,0);
  fVar40 = (float)VectorSignedToFloat((int)local_a8[3] * (int)local_a8[3],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[5] = (float)(int)fVar29;
  fVar22 = (float)FPRoundInt(fVar21 * local_2a8[6],0x20,2,0);
  fVar46 = (float)VectorSignedToFloat((int)local_a8[4] * (int)local_a8[4],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[6] = (float)(int)fVar22;
  fVar12 = (float)FPRoundInt(fVar21 * local_2a8[7],0x20,2,0);
  fVar41 = (float)VectorSignedToFloat((int)local_a8[5] * (int)local_a8[5],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[7] = (float)(int)fVar12;
  fVar49 = (float)FPRoundInt(fVar21 * local_2a8[8],0x20,2,0);
  fVar47 = (float)VectorSignedToFloat((int)local_a8[6] * (int)local_a8[6],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[8] = (float)(int)fVar49;
  fVar50 = (float)FPRoundInt(fVar21 * local_2a8[9],0x20,2,0);
  fVar42 = (float)VectorSignedToFloat((int)local_a8[7] * (int)local_a8[7],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[9] = (float)(int)fVar50;
  fVar51 = (float)FPRoundInt(fVar21 * local_2a8[10],0x20,2,0);
  fVar31 = (float)VectorSignedToFloat((int)local_a8[8] * (int)local_a8[8],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[10] = (float)(int)fVar51;
  fVar43 = (float)VectorSignedToFloat((int)local_a8[9] * (int)local_a8[9],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar52 = (float)FPRoundInt(fVar21 * local_2a8[0xb],0x20,2,0);
  local_a8[0xb] = (float)(int)fVar52;
  fVar32 = (float)VectorSignedToFloat((int)local_a8[10] * (int)local_a8[10],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[0xc] = (float)(int)fVar36;
  fVar44 = (float)VectorSignedToFloat((int)local_a8[0xb] * (int)local_a8[0xb],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[0xd] = (float)(int)fVar26;
  fVar33 = (float)VectorSignedToFloat((int)local_a8[0xc] * (int)local_a8[0xc],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_a8[0xe] = (float)(int)fVar28;
  fVar45 = (float)VectorSignedToFloat((int)local_a8[0xd] * (int)local_a8[0xd],
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_6c = (float)(int)fVar38;
  fVar35 = (float)VectorSignedToFloat((int)local_a8[0xe] * (int)local_a8[0xe],
                                      (byte)(in_fpscr >> 0x16) & 3);
  iVar9 = (int)local_a8[1] + (int)local_a8[0] + (int)local_a8[2] + (int)local_a8[3] +
          (int)local_a8[4] + (int)local_a8[5] + (int)local_a8[6] + (int)local_a8[7] +
          (int)local_a8[8] + (int)local_a8[9] + (int)local_a8[10] + (int)local_a8[0xb] +
          (int)local_a8[0xc] + (int)local_a8[0xd] + (int)local_a8[0xe] + (int)local_6c;
  fVar21 = (float)VectorSignedToFloat((int)local_6c * (int)local_6c,(byte)(in_fpscr >> 0x16) & 3);
  fVar22 = local_2a8[1] * fVar25 + local_2a8[0] * fVar24 + local_2a8[2] * fVar23 +
           local_2a8[3] * fVar34 + local_2a8[4] * fVar27 + local_2a8[5] * fVar29 +
           local_2a8[6] * fVar22 + local_2a8[7] * fVar12 + local_2a8[8] * fVar49 +
           local_2a8[9] * fVar50 + local_2a8[10] * fVar51 + local_2a8[0xb] * fVar52 +
           local_2a8[0xc] * fVar36 + local_2a8[0xd] * fVar26 + local_2a8[0xe] * fVar28 +
           local_26c * fVar38;
  fVar21 = fVar21 + fVar35 + fVar45 + fVar33 + fVar44 + fVar32 + fVar43 + fVar31 + fVar42 + fVar47 +
                                                                                            fVar41 +
                                                                                            fVar46 +
                                                                                            fVar40 +
                                                                                            fVar39 +
                                                                                            fVar30 +
                                                                                            fVar37;
  fVar12 = fVar22;
  if (iVar9 < 6) {
    do {
      while( true ) {
        fVar12 = (float)VectorSignedToFloat((int)local_a8[0] << 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar29 = (float)VectorSignedToFloat((int)local_a8[1] << 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar23 = (local_2a8[0] + fVar22) * (local_2a8[0] + fVar22);
        fVar24 = fVar12 + 1.0 + fVar21;
        fVar34 = (local_2a8[1] + fVar22) * (local_2a8[1] + fVar22);
        fVar12 = fVar29 + 1.0 + fVar21;
        bVar18 = fVar12 * fVar23 < fVar34 * fVar24;
        in_fpscr = in_fpscr & 0xfffffff;
        fVar27 = (float)VectorSignedToFloat((int)local_a8[2] << 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar29 = (local_2a8[2] + fVar22) * (local_2a8[2] + fVar22);
        fVar27 = fVar27 + 1.0 + fVar21;
        if (!bVar18) {
          fVar34 = fVar23;
          fVar12 = fVar24;
        }
        bVar1 = fVar27 * fVar34 < fVar29 * fVar12;
        uVar6 = (uint)bVar18;
        if (!bVar1) {
          fVar29 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_a8[3] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar27 = fVar12;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar12 = (local_2a8[3] + fVar22) * (local_2a8[3] + fVar22);
        bVar18 = fVar34 * fVar29 < fVar12 * fVar27;
        if (bVar1) {
          uVar6 = 2;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_a8[4] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar12 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[4] + fVar22) * (local_2a8[4] + fVar22);
        bVar1 = fVar27 * fVar12 < fVar29 * fVar34;
        if (bVar18) {
          uVar6 = 3;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_a8[5] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar12;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar12 = (local_2a8[5] + fVar22) * (local_2a8[5] + fVar22);
        bVar18 = fVar34 * fVar29 < fVar12 * fVar27;
        if (bVar1) {
          uVar6 = 4;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_a8[6] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar12 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[6] + fVar22) * (local_2a8[6] + fVar22);
        bVar1 = fVar27 * fVar12 < fVar29 * fVar34;
        if (bVar18) {
          uVar6 = 5;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_a8[7] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar12;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar12 = (local_2a8[7] + fVar22) * (local_2a8[7] + fVar22);
        bVar18 = fVar34 * fVar29 < fVar12 * fVar27;
        if (bVar1) {
          uVar6 = 6;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_a8[8] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar12 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[8] + fVar22) * (local_2a8[8] + fVar22);
        bVar1 = fVar27 * fVar12 < fVar29 * fVar34;
        if (bVar18) {
          uVar6 = 7;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_a8[9] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar12;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar12 = (local_2a8[9] + fVar22) * (local_2a8[9] + fVar22);
        bVar18 = fVar34 * fVar29 < fVar12 * fVar27;
        if (bVar1) {
          uVar6 = 8;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_a8[10] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar12 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[10] + fVar22) * (local_2a8[10] + fVar22);
        bVar1 = fVar27 * fVar12 < fVar29 * fVar34;
        if (bVar18) {
          uVar6 = 9;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_a8[0xb] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar12;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar12 = (local_2a8[0xb] + fVar22) * (local_2a8[0xb] + fVar22);
        bVar18 = fVar34 * fVar29 < fVar12 * fVar27;
        if (bVar1) {
          uVar6 = 10;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_a8[0xc] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar12 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[0xc] + fVar22) * (local_2a8[0xc] + fVar22);
        bVar1 = fVar27 * fVar12 < fVar29 * fVar34;
        if (bVar18) {
          uVar6 = 0xb;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_a8[0xd] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar12;
        }
        fVar12 = fVar34 + 1.0 + fVar21;
        fVar34 = (local_2a8[0xd] + fVar22) * (local_2a8[0xd] + fVar22);
        bVar18 = fVar12 * fVar29 < fVar34 * fVar27;
        if (bVar1) {
          uVar6 = 0xc;
        }
        if (!bVar18) {
          fVar12 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_a8[0xe] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar34 = fVar29;
        }
        fVar29 = (local_2a8[0xe] + fVar22) * (local_2a8[0xe] + fVar22);
        fVar27 = fVar27 + 1.0 + fVar21;
        bVar1 = fVar27 * fVar34 < fVar29 * fVar12;
        if (bVar18) {
          uVar6 = 0xd;
        }
        if (!bVar1) {
          fVar27 = fVar12;
        }
        fVar23 = (float)VectorSignedToFloat((int)local_6c * 2,(byte)(in_fpscr >> 0x16) & 3);
        fVar12 = local_26c + fVar22;
        if (!bVar1) {
          fVar29 = fVar34;
        }
        if (bVar1) {
          uVar6 = 0xe;
        }
        if ((fVar23 + 1.0 + fVar21) * fVar29 < fVar12 * fVar12 * fVar27) break;
        fVar22 = fVar22 + local_2a8[uVar6];
        fVar12 = (float)VectorSignedToFloat((int)local_a8[uVar6] * 2 + 1,
                                            (byte)(in_fpscr >> 0x16) & 3);
        iVar9 = iVar9 + 1;
        fVar21 = fVar21 + fVar12;
        local_a8[uVar6] = (float)((int)local_a8[uVar6] + 1);
        fVar12 = fVar22;
        if (iVar9 == 6) goto LAB_00070c2a;
      }
      fVar22 = (float)VectorSignedToFloat((int)local_6c * 2 + 1,(byte)(in_fpscr >> 0x16) & 3);
      iVar9 = iVar9 + 1;
      fVar21 = fVar21 + fVar22;
      local_6c = (float)((int)local_6c + 1);
      fVar22 = fVar12;
    } while (iVar9 != 6);
  }
LAB_00070c2a:
  local_e8[0] = local_a8[0];
  local_e8[1] = local_a8[1];
  local_e8[2] = local_a8[2];
  local_e8[3] = local_a8[3];
  local_e8[4] = local_a8[4];
  local_e8[5] = local_a8[5];
  local_e8[6] = local_a8[6];
  local_e8[7] = local_a8[7];
  local_e8[8] = local_a8[8];
  local_e8[9] = local_a8[9];
  local_e8[10] = local_a8[10];
  local_e8[0xb] = local_a8[0xb];
  iVar9 = 2;
  local_e8[0xc] = local_a8[0xc];
  local_e8[0xd] = local_a8[0xd];
  local_e8[0xe] = local_a8[0xe];
  local_ac = local_6c;
  while( true ) {
    fVar22 = (float)VectorSignedToFloat((int)local_e8[0] << 1,(byte)(in_fpscr >> 0x16) & 3);
    fVar29 = (float)VectorSignedToFloat((int)local_e8[1] << 1,(byte)(in_fpscr >> 0x16) & 3);
    fVar23 = (local_2a8[0] + fVar12) * (local_2a8[0] + fVar12);
    fVar24 = fVar22 + 1.0 + fVar21;
    fVar34 = (local_2a8[1] + fVar12) * (local_2a8[1] + fVar12);
    fVar22 = fVar29 + 1.0 + fVar21;
    bVar18 = fVar22 * fVar23 < fVar34 * fVar24;
    in_fpscr = in_fpscr & 0xfffffff;
    fVar27 = (float)VectorSignedToFloat((int)local_e8[2] << 1,(byte)(in_fpscr >> 0x16) & 3);
    fVar29 = (local_2a8[2] + fVar12) * (local_2a8[2] + fVar12);
    fVar27 = fVar27 + 1.0 + fVar21;
    if (!bVar18) {
      fVar34 = fVar23;
      fVar22 = fVar24;
    }
    bVar1 = fVar27 * fVar34 < fVar29 * fVar22;
    uVar6 = (uint)bVar18;
    if (!bVar1) {
      fVar29 = fVar34;
    }
    fVar34 = (float)VectorSignedToFloat((int)local_e8[3] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar1) {
      fVar27 = fVar22;
    }
    fVar34 = fVar34 + 1.0 + fVar21;
    fVar22 = (local_2a8[3] + fVar12) * (local_2a8[3] + fVar12);
    bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
    if (bVar1) {
      uVar6 = 2;
    }
    if (!bVar18) {
      fVar34 = fVar27;
    }
    fVar27 = (float)VectorSignedToFloat((int)local_e8[4] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar18) {
      fVar22 = fVar29;
    }
    fVar27 = fVar27 + 1.0 + fVar21;
    fVar29 = (local_2a8[4] + fVar12) * (local_2a8[4] + fVar12);
    bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
    if (bVar18) {
      uVar6 = 3;
    }
    if (!bVar1) {
      fVar27 = fVar34;
    }
    fVar34 = (float)VectorSignedToFloat((int)local_e8[5] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar1) {
      fVar29 = fVar22;
    }
    fVar34 = fVar34 + 1.0 + fVar21;
    fVar22 = (local_2a8[5] + fVar12) * (local_2a8[5] + fVar12);
    bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
    if (bVar1) {
      uVar6 = 4;
    }
    if (!bVar18) {
      fVar34 = fVar27;
    }
    fVar27 = (float)VectorSignedToFloat((int)local_e8[6] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar18) {
      fVar22 = fVar29;
    }
    fVar27 = fVar27 + 1.0 + fVar21;
    fVar29 = (local_2a8[6] + fVar12) * (local_2a8[6] + fVar12);
    bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
    if (bVar18) {
      uVar6 = 5;
    }
    if (!bVar1) {
      fVar27 = fVar34;
    }
    fVar34 = (float)VectorSignedToFloat((int)local_e8[7] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar1) {
      fVar29 = fVar22;
    }
    fVar34 = fVar34 + 1.0 + fVar21;
    fVar22 = (local_2a8[7] + fVar12) * (local_2a8[7] + fVar12);
    bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
    if (bVar1) {
      uVar6 = 6;
    }
    if (!bVar18) {
      fVar34 = fVar27;
    }
    fVar27 = (float)VectorSignedToFloat((int)local_e8[8] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar18) {
      fVar22 = fVar29;
    }
    fVar27 = fVar27 + 1.0 + fVar21;
    fVar29 = (local_2a8[8] + fVar12) * (local_2a8[8] + fVar12);
    bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
    if (bVar18) {
      uVar6 = 7;
    }
    if (!bVar1) {
      fVar27 = fVar34;
    }
    fVar34 = (float)VectorSignedToFloat((int)local_e8[9] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar1) {
      fVar29 = fVar22;
    }
    fVar34 = fVar34 + 1.0 + fVar21;
    fVar22 = (local_2a8[9] + fVar12) * (local_2a8[9] + fVar12);
    bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
    if (bVar1) {
      uVar6 = 8;
    }
    if (!bVar18) {
      fVar34 = fVar27;
    }
    fVar27 = (float)VectorSignedToFloat((int)local_e8[10] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar18) {
      fVar22 = fVar29;
    }
    fVar27 = fVar27 + 1.0 + fVar21;
    fVar29 = (local_2a8[10] + fVar12) * (local_2a8[10] + fVar12);
    bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
    if (bVar18) {
      uVar6 = 9;
    }
    if (!bVar1) {
      fVar27 = fVar34;
    }
    fVar34 = (float)VectorSignedToFloat((int)local_e8[0xb] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar1) {
      fVar29 = fVar22;
    }
    fVar34 = fVar34 + 1.0 + fVar21;
    fVar22 = (local_2a8[0xb] + fVar12) * (local_2a8[0xb] + fVar12);
    bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
    if (bVar1) {
      uVar6 = 10;
    }
    if (!bVar18) {
      fVar34 = fVar27;
    }
    fVar27 = (float)VectorSignedToFloat((int)local_e8[0xc] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar18) {
      fVar22 = fVar29;
    }
    fVar27 = fVar27 + 1.0 + fVar21;
    fVar29 = (local_2a8[0xc] + fVar12) * (local_2a8[0xc] + fVar12);
    bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
    if (bVar18) {
      uVar6 = 0xb;
    }
    if (!bVar1) {
      fVar27 = fVar34;
    }
    fVar34 = (float)VectorSignedToFloat((int)local_e8[0xd] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar1) {
      fVar29 = fVar22;
    }
    fVar34 = fVar34 + 1.0 + fVar21;
    fVar22 = (local_2a8[0xd] + fVar12) * (local_2a8[0xd] + fVar12);
    bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
    if (bVar1) {
      uVar6 = 0xc;
    }
    if (!bVar18) {
      fVar34 = fVar27;
    }
    fVar27 = (float)VectorSignedToFloat((int)local_e8[0xe] << 1,(byte)(in_fpscr >> 0x16) & 3);
    if (!bVar18) {
      fVar22 = fVar29;
    }
    fVar29 = (local_2a8[0xe] + fVar12) * (local_2a8[0xe] + fVar12);
    fVar27 = fVar27 + 1.0 + fVar21;
    bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
    if (bVar18) {
      uVar6 = 0xd;
    }
    if (!bVar1) {
      fVar27 = fVar34;
    }
    fVar23 = (float)VectorSignedToFloat((int)local_ac * 2,(byte)(in_fpscr >> 0x16) & 3);
    fVar34 = local_26c + fVar12;
    if (!bVar1) {
      fVar29 = fVar22;
    }
    if (bVar1) {
      uVar6 = 0xe;
    }
    if (fVar34 * fVar34 * fVar27 <= (fVar23 + 1.0 + fVar21) * fVar29) {
      fVar22 = (float)VectorSignedToFloat((int)local_e8[uVar6] * 2 + 1,(byte)(in_fpscr >> 0x16) & 3)
      ;
      local_e8[uVar6] = (float)((int)local_e8[uVar6] + 1);
      fVar12 = fVar12 + local_2a8[uVar6];
    }
    else {
      fVar22 = (float)VectorSignedToFloat((int)local_ac * 2 + 1,(byte)(in_fpscr >> 0x16) & 3);
      local_ac = (float)((int)local_ac + 1);
      fVar12 = fVar34;
    }
    fVar21 = fVar21 + fVar22;
    if (iVar9 == 1) break;
    iVar9 = 1;
  }
  local_128[0] = local_e8[0];
  local_128[1] = local_e8[1];
  local_128[2] = local_e8[2];
  local_128[3] = local_e8[3];
  local_128[4] = local_e8[4];
  local_128[5] = local_e8[5];
  local_128[6] = local_e8[6];
  local_128[7] = local_e8[7];
  local_128[8] = local_e8[8];
  local_104 = local_e8[9];
  local_100 = 0.0;
  local_fc = 0.0;
  local_f8 = 0.0;
  local_f4 = 0.0;
  local_f0 = 0.0;
  local_ec = 0.0;
  fVar29 = (float)VectorSignedToFloat((int)local_e8[0xb] * (int)local_e8[0xb],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar23 = (float)VectorSignedToFloat((int)local_e8[10] * (int)local_e8[10],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar28 = (float)VectorSignedToFloat(local_e8[0xb],(byte)(in_fpscr >> 0x16) & 3);
  fVar24 = (float)VectorSignedToFloat(local_e8[10],(byte)(in_fpscr >> 0x16) & 3);
  fVar30 = (float)VectorSignedToFloat(local_e8[0xc],(byte)(in_fpscr >> 0x16) & 3);
  fVar35 = (float)VectorSignedToFloat(local_e8[0xd],(byte)(in_fpscr >> 0x16) & 3);
  fVar27 = (float)VectorSignedToFloat((int)local_e8[0xc] * (int)local_e8[0xc],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar36 = (float)VectorSignedToFloat(local_e8[0xe],(byte)(in_fpscr >> 0x16) & 3);
  fVar25 = (float)VectorSignedToFloat((int)local_e8[0xd] * (int)local_e8[0xd],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar22 = (float)VectorSignedToFloat((int)local_e8[0xe] * (int)local_e8[0xe],
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar34 = (float)VectorSignedToFloat((int)local_ac * (int)local_ac,(byte)(in_fpscr >> 0x16) & 3);
  fVar26 = (float)VectorSignedToFloat(local_ac,(byte)(in_fpscr >> 0x16) & 3);
  iVar9 = (((((8 - (int)local_e8[10]) - (int)local_e8[0xb]) - (int)local_e8[0xc]) -
           (int)local_e8[0xd]) - (int)local_e8[0xe]) - (int)local_ac;
  fVar12 = fVar12 - (fVar28 * local_2a8[0xb] + local_2a8[10] * fVar24 + local_2a8[0xc] * fVar30 +
                     local_2a8[0xd] * fVar35 + local_2a8[0xe] * fVar36 + local_26c * fVar26);
  fVar21 = fVar21 - (fVar34 + fVar22 + fVar25 + fVar27 + fVar29 + fVar23);
  fVar22 = fVar12;
  if (iVar9 < 10) {
    do {
      while( true ) {
        fVar22 = (float)VectorSignedToFloat((int)local_128[0] << 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar29 = (float)VectorSignedToFloat((int)local_128[1] << 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar23 = (local_2a8[0] + fVar12) * (local_2a8[0] + fVar12);
        fVar24 = fVar22 + 1.0 + fVar21;
        fVar34 = (local_2a8[1] + fVar12) * (local_2a8[1] + fVar12);
        fVar22 = fVar29 + 1.0 + fVar21;
        bVar18 = fVar22 * fVar23 < fVar34 * fVar24;
        fVar27 = (float)VectorSignedToFloat((int)local_128[2] << 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar29 = (local_2a8[2] + fVar12) * (local_2a8[2] + fVar12);
        fVar27 = fVar27 + 1.0 + fVar21;
        if (!bVar18) {
          fVar34 = fVar23;
          fVar22 = fVar24;
        }
        bVar1 = fVar27 * fVar34 < fVar29 * fVar22;
        if (bVar18) {
          iVar2 = 4;
        }
        else {
          iVar2 = 0;
        }
        if (!bVar1) {
          fVar29 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_128[3] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar27 = fVar22;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar22 = (local_2a8[3] + fVar12) * (local_2a8[3] + fVar12);
        bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
        if (bVar1) {
          iVar2 = 8;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_128[4] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar22 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[4] + fVar12) * (local_2a8[4] + fVar12);
        bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
        if (bVar18) {
          iVar2 = 0xc;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_128[5] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar22;
        }
        fVar34 = fVar34 + 1.0 + fVar21;
        fVar22 = (local_2a8[5] + fVar12) * (local_2a8[5] + fVar12);
        bVar18 = fVar34 * fVar29 < fVar22 * fVar27;
        if (bVar1) {
          iVar2 = 0x10;
        }
        if (!bVar18) {
          fVar34 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_128[6] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar22 = fVar29;
        }
        fVar27 = fVar27 + 1.0 + fVar21;
        fVar29 = (local_2a8[6] + fVar12) * (local_2a8[6] + fVar12);
        bVar1 = fVar27 * fVar22 < fVar29 * fVar34;
        if (bVar18) {
          iVar2 = 0x14;
        }
        if (!bVar1) {
          fVar27 = fVar34;
        }
        fVar34 = (float)VectorSignedToFloat((int)local_128[7] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar1) {
          fVar29 = fVar22;
        }
        fVar22 = fVar34 + 1.0 + fVar21;
        fVar34 = (local_2a8[7] + fVar12) * (local_2a8[7] + fVar12);
        bVar18 = fVar22 * fVar29 < fVar34 * fVar27;
        if (bVar1) {
          iVar2 = 0x18;
        }
        if (!bVar18) {
          fVar22 = fVar27;
        }
        fVar27 = (float)VectorSignedToFloat((int)local_128[8] << 1,(byte)(in_fpscr >> 0x16) & 3);
        if (!bVar18) {
          fVar34 = fVar29;
        }
        fVar29 = (local_2a8[8] + fVar12) * (local_2a8[8] + fVar12);
        fVar27 = fVar27 + 1.0 + fVar21;
        bVar1 = fVar27 * fVar34 < fVar29 * fVar22;
        if (bVar18) {
          iVar2 = 0x1c;
        }
        if (!bVar1) {
          fVar27 = fVar22;
        }
        fVar23 = (float)VectorSignedToFloat((int)local_104 * 2,(byte)(in_fpscr >> 0x16) & 3);
        fVar22 = local_2a8[9] + fVar12;
        if (!bVar1) {
          fVar29 = fVar34;
        }
        if (bVar1) {
          iVar2 = 0x20;
        }
        if ((fVar23 + 1.0 + fVar21) * fVar29 < fVar22 * fVar22 * fVar27) break;
        fVar22 = fVar12 + *(float *)((int)local_2a8 + iVar2);
        fVar12 = (float)VectorSignedToFloat(*(int *)((int)local_128 + iVar2) * 2 + 1,
                                            (byte)(in_fpscr >> 0x16) & 3);
        iVar9 = iVar9 + 1;
        fVar21 = fVar21 + fVar12;
        *(int *)((int)local_128 + iVar2) = *(int *)((int)local_128 + iVar2) + 1;
        fVar12 = fVar22;
        if (iVar9 == 10) goto LAB_00071406;
      }
      fVar12 = (float)VectorSignedToFloat((int)local_104 * 2 + 1,(byte)(in_fpscr >> 0x16) & 3);
      iVar9 = iVar9 + 1;
      fVar21 = fVar21 + fVar12;
      local_104 = (float)((int)local_104 + 1);
      fVar12 = fVar22;
    } while (iVar9 != 10);
  }
LAB_00071406:
  local_168[0] = local_128[0];
  local_168[1] = local_128[1];
  local_168[2] = local_128[2];
  local_168[3] = local_128[3];
  local_168[4] = local_128[4];
  local_168[5] = local_128[5];
  local_168[6] = local_128[6];
  local_168[7] = local_128[7];
  local_168[8] = local_128[8];
  local_168[9] = local_104;
  local_140 = 0;
  local_13c = 0.0;
  local_138 = 0.0;
  local_134 = 0.0;
  local_130 = 0;
  local_12c = 0.0;
  fVar12 = (float)VectorSignedToFloat(0,(byte)(in_fpscr >> 0x16) & 3);
  fVar29 = (float)VectorSignedToFloat(0,(byte)(in_fpscr >> 0x16) & 3);
  fVar23 = fVar12 + 1.0 + fVar21;
  fVar26 = (fVar22 + local_2a8[10]) * (fVar22 + local_2a8[10]);
  fVar28 = (fVar22 + local_2a8[0xb]) * (fVar22 + local_2a8[0xb]);
  fVar12 = (float)VectorSignedToFloat(0,(byte)(in_fpscr >> 0x16) & 3);
  fVar24 = fVar29 + 1.0 + fVar21;
  fVar27 = fVar23 * fVar28;
  fVar34 = fVar24 * fVar26;
  fVar12 = fVar12 + 1.0 + fVar21;
  fVar29 = (fVar22 + local_2a8[0xc]) * (fVar22 + local_2a8[0xc]);
  fVar25 = (float)((uint)(fVar34 < fVar27) * (int)fVar24 + (uint)(fVar27 <= fVar34) * (int)fVar23);
  fVar26 = (float)((uint)(fVar34 < fVar27) * (int)fVar28 + (uint)(fVar27 <= fVar34) * (int)fVar26);
  fVar23 = fVar29 * fVar25;
  fVar24 = fVar26 * fVar12;
  uVar6 = in_fpscr | (uint)(fVar23 < fVar24) << 0x1f | (uint)(fVar23 == fVar24) << 0x1e;
  uVar20 = uVar6 | (uint)(NAN(fVar23) || NAN(fVar24)) << 0x1c;
  if (fVar34 < fVar27) {
    iVar9 = 4;
  }
  else {
    iVar9 = 0;
  }
  bVar19 = (byte)(uVar6 >> 0x18);
  bVar17 = bVar19 >> 7;
  bVar18 = (bool)(bVar19 >> 6 & 1);
  bVar19 = (byte)(uVar20 >> 0x1c) & 1;
  if (bVar18 || bVar17 != bVar19) {
    fVar12 = fVar25;
  }
  fVar27 = (float)VectorSignedToFloat(0,(byte)(uVar20 >> 0x16) & 3);
  fVar34 = (fVar22 + local_2a8[0xd]) * (fVar22 + local_2a8[0xd]);
  fVar27 = fVar27 + 1.0 + fVar21;
  if (bVar18 || bVar17 != bVar19) {
    fVar29 = fVar26;
  }
  fVar23 = fVar34 * fVar12;
  fVar24 = fVar29 * fVar27;
  uVar6 = in_fpscr | (uint)(fVar23 < fVar24) << 0x1f | (uint)(fVar23 == fVar24) << 0x1e;
  uVar20 = uVar6 | (uint)(NAN(fVar23) || NAN(fVar24)) << 0x1c;
  if (!bVar18 && bVar17 == bVar19) {
    iVar9 = 8;
  }
  bVar19 = (byte)(uVar6 >> 0x18);
  bVar17 = bVar19 >> 7;
  bVar18 = (bool)(bVar19 >> 6 & 1);
  bVar19 = (byte)(uVar20 >> 0x1c) & 1;
  if (bVar18 || bVar17 != bVar19) {
    fVar27 = fVar12;
  }
  fVar12 = (float)VectorSignedToFloat(0,(byte)(uVar20 >> 0x16) & 3);
  if (bVar18 || bVar17 != bVar19) {
    fVar34 = fVar29;
  }
  fVar29 = (fVar22 + local_2a8[0xe]) * (fVar22 + local_2a8[0xe]);
  fVar12 = fVar12 + 1.0 + fVar21;
  fVar23 = fVar29 * fVar27;
  fVar24 = fVar34 * fVar12;
  uVar6 = in_fpscr | (uint)(fVar23 < fVar24) << 0x1f | (uint)(fVar23 == fVar24) << 0x1e;
  uVar20 = uVar6 | (uint)(NAN(fVar23) || NAN(fVar24)) << 0x1c;
  if (!bVar18 && bVar17 == bVar19) {
    iVar9 = 0xc;
  }
  bVar19 = (byte)(uVar6 >> 0x18);
  bVar17 = bVar19 >> 7;
  bVar18 = (bool)(bVar19 >> 6 & 1);
  bVar19 = (byte)(uVar20 >> 0x1c) & 1;
  if (bVar18 || bVar17 != bVar19) {
    fVar12 = fVar27;
  }
  fVar27 = (float)VectorSignedToFloat(0,(byte)(uVar20 >> 0x16) & 3);
  if (bVar18 || bVar17 != bVar19) {
    fVar29 = fVar34;
  }
  if (!bVar18 && bVar17 == bVar19) {
    iVar9 = 0x10;
  }
  if ((fVar27 + 1.0 + fVar21) * fVar29 < (local_26c + fVar22) * (local_26c + fVar22) * fVar12) {
    iVar9 = 0x14;
  }
  *(int *)((int)&local_140 + iVar9) = *(int *)((int)&local_140 + iVar9) + 1;
  if (local_2e8[0] < 0.0) {
    local_168[0] = (float)-(int)local_128[0];
    local_128[0] = (float)-(int)local_128[0];
    local_e8[0] = (float)-(int)local_e8[0];
    local_a8[0] = (float)-(int)local_a8[0];
  }
  if (local_2e8[1] < 0.0) {
    local_168[1] = (float)-(int)local_128[1];
    local_128[1] = (float)-(int)local_128[1];
    local_e8[1] = (float)-(int)local_e8[1];
    local_a8[1] = (float)-(int)local_a8[1];
  }
  if (local_2e8[2] < 0.0) {
    local_168[2] = (float)-(int)local_128[2];
    local_128[2] = (float)-(int)local_128[2];
    local_e8[2] = (float)-(int)local_e8[2];
    local_a8[2] = (float)-(int)local_a8[2];
  }
  if (local_2e8[3] < 0.0) {
    local_168[3] = (float)-(int)local_128[3];
    local_128[3] = (float)-(int)local_128[3];
    local_e8[3] = (float)-(int)local_e8[3];
    local_a8[3] = (float)-(int)local_a8[3];
  }
  if (local_2d8 < 0.0) {
    local_168[4] = (float)-(int)local_128[4];
    local_128[4] = (float)-(int)local_128[4];
    local_e8[4] = (float)-(int)local_e8[4];
    local_a8[4] = (float)-(int)local_a8[4];
  }
  if (local_2d4 < 0.0) {
    local_168[5] = (float)-(int)local_128[5];
    local_128[5] = (float)-(int)local_128[5];
    local_e8[5] = (float)-(int)local_e8[5];
    local_a8[5] = (float)-(int)local_a8[5];
  }
  if (local_2d0 < 0.0) {
    local_168[6] = (float)-(int)local_128[6];
    local_128[6] = (float)-(int)local_128[6];
    local_e8[6] = (float)-(int)local_e8[6];
    local_a8[6] = (float)-(int)local_a8[6];
  }
  if (local_2cc < 0.0) {
    local_168[7] = (float)-(int)local_128[7];
    local_128[7] = (float)-(int)local_128[7];
    local_e8[7] = (float)-(int)local_e8[7];
    local_a8[7] = (float)-(int)local_a8[7];
  }
  if (local_2c8 < 0.0) {
    local_168[8] = (float)-(int)local_128[8];
    local_128[8] = (float)-(int)local_128[8];
    local_e8[8] = (float)-(int)local_e8[8];
    local_a8[8] = (float)-(int)local_a8[8];
  }
  if (local_2c4 < 0.0) {
    local_168[9] = (float)-(int)local_104;
    local_104 = (float)-(int)local_104;
    local_e8[9] = (float)-(int)local_e8[9];
    local_a8[9] = (float)-(int)local_a8[9];
  }
  if (local_2c0 < 0.0) {
    local_140 = -local_140;
    local_100 = 0.0;
    local_e8[10] = (float)-(int)local_e8[10];
    local_a8[10] = (float)-(int)local_a8[10];
  }
  local_100 = 0.0;
  if (local_2bc < 0.0) {
    local_13c = (float)-(int)local_13c;
    local_fc = 0.0;
    local_e8[0xb] = (float)-(int)local_e8[0xb];
    local_a8[0xb] = (float)-(int)local_a8[0xb];
  }
  local_fc = 0.0;
  if (local_2b8 < 0.0) {
    local_138 = (float)-(int)local_138;
    local_f8 = 0.0;
    local_e8[0xc] = (float)-(int)local_e8[0xc];
    local_a8[0xc] = (float)-(int)local_a8[0xc];
  }
  local_f8 = 0.0;
  if (local_2b4 < 0.0) {
    local_134 = (float)-(int)local_134;
    local_f4 = 0.0;
    local_e8[0xd] = (float)-(int)local_e8[0xd];
    local_a8[0xd] = (float)-(int)local_a8[0xd];
  }
  local_f4 = 0.0;
  if (local_2b0 < 0.0) {
    local_130 = -local_130;
    local_f0 = 0.0;
    local_e8[0xe] = (float)-(int)local_e8[0xe];
    local_a8[0xe] = (float)-(int)local_a8[0xe];
  }
  local_f0 = 0.0;
  if (local_2ac < 0.0) {
    local_12c = (float)-(int)local_12c;
    local_ec = 0.0;
    local_ac = (float)-(int)local_ac;
    local_6c = (float)-(int)local_6c;
  }
  local_ec = 0.0;
  pfVar7 = local_268;
  pfVar3 = local_168;
  pfVar10 = pfVar7;
  local_168[0] = local_128[0];
  local_168[1] = local_128[1];
  local_168[2] = local_128[2];
  local_168[3] = local_128[3];
  local_168[4] = local_128[4];
  local_168[5] = local_128[5];
  local_168[6] = local_128[6];
  local_168[7] = local_128[7];
  local_168[8] = local_128[8];
  local_168[9] = local_104;
  do {
    fVar12 = pfVar3[1];
    pfVar11 = pfVar10 + 0x10;
    fVar21 = *pfVar3;
    fVar31 = (float)VectorSignedToFloat(fVar12,(byte)(in_fpscr >> 0x16) & 3);
    fVar22 = pfVar3[2];
    fVar47 = (float)VectorSignedToFloat(fVar21,(byte)(in_fpscr >> 0x16) & 3);
    fVar29 = pfVar3[3];
    fVar32 = (float)VectorSignedToFloat(fVar22,(byte)(in_fpscr >> 0x16) & 3);
    fVar27 = pfVar3[4];
    fVar33 = (float)VectorSignedToFloat(fVar29,(byte)(in_fpscr >> 0x16) & 3);
    fVar34 = pfVar3[5];
    fVar38 = (float)VectorSignedToFloat(fVar27,(byte)(in_fpscr >> 0x16) & 3);
    fVar23 = pfVar3[6];
    fVar39 = (float)VectorSignedToFloat(fVar34,(byte)(in_fpscr >> 0x16) & 3);
    fVar24 = pfVar3[7];
    fVar40 = (float)VectorSignedToFloat(fVar23,(byte)(in_fpscr >> 0x16) & 3);
    fVar25 = pfVar3[8];
    fVar41 = (float)VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
    fVar26 = pfVar3[9];
    fVar42 = (float)VectorSignedToFloat(fVar25,(byte)(in_fpscr >> 0x16) & 3);
    fVar28 = pfVar3[10];
    fVar43 = (float)VectorSignedToFloat(fVar26,(byte)(in_fpscr >> 0x16) & 3);
    fVar30 = pfVar3[0xb];
    fVar44 = (float)VectorSignedToFloat(fVar28,(byte)(in_fpscr >> 0x16) & 3);
    fVar35 = pfVar3[0xc];
    fVar45 = (float)VectorSignedToFloat(fVar30,(byte)(in_fpscr >> 0x16) & 3);
    fVar36 = pfVar3[0xd];
    fVar49 = (float)VectorSignedToFloat(fVar35,(byte)(in_fpscr >> 0x16) & 3);
    fVar37 = pfVar3[0xe];
    fVar50 = (float)VectorSignedToFloat(fVar36,(byte)(in_fpscr >> 0x16) & 3);
    fVar46 = pfVar3[0xf];
    fVar51 = (float)VectorSignedToFloat(fVar37,(byte)(in_fpscr >> 0x16) & 3);
    fVar52 = (float)VectorSignedToFloat(fVar46,(byte)(in_fpscr >> 0x16) & 3);
    fVar12 = (float)VectorSignedToFloat((int)fVar46 * (int)fVar46 +
                                        (int)fVar37 * (int)fVar37 +
                                        (int)fVar36 * (int)fVar36 +
                                        (int)fVar35 * (int)fVar35 +
                                        (int)fVar30 * (int)fVar30 +
                                        (int)fVar28 * (int)fVar28 +
                                        (int)fVar26 * (int)fVar26 +
                                        (int)fVar25 * (int)fVar25 +
                                        (int)fVar24 * (int)fVar24 +
                                        (int)fVar23 * (int)fVar23 +
                                        (int)fVar34 * (int)fVar34 +
                                        (int)fVar27 * (int)fVar27 +
                                        (int)fVar29 * (int)fVar29 +
                                        (int)fVar22 * (int)fVar22 +
                                        (int)fVar21 * (int)fVar21 + (int)fVar12 * (int)fVar12,
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar12 = 1.0 / SQRT(fVar12);
    *pfVar10 = fVar47 * fVar12;
    pfVar10[1] = fVar31 * fVar12;
    pfVar10[2] = fVar32 * fVar12;
    pfVar10[3] = fVar33 * fVar12;
    pfVar10[4] = fVar38 * fVar12;
    pfVar10[5] = fVar39 * fVar12;
    pfVar10[6] = fVar40 * fVar12;
    pfVar10[7] = fVar41 * fVar12;
    pfVar10[8] = fVar42 * fVar12;
    pfVar10[9] = fVar43 * fVar12;
    pfVar10[10] = fVar44 * fVar12;
    pfVar10[0xb] = fVar45 * fVar12;
    pfVar10[0xc] = fVar49 * fVar12;
    pfVar10[0xd] = fVar50 * fVar12;
    pfVar10[0xe] = fVar51 * fVar12;
    pfVar10[0xf] = fVar52 * fVar12;
    pfVar3 = pfVar3 + 0x10;
    pfVar10 = pfVar11;
  } while (pfVar11 != local_168);
  iVar9 = 0;
  local_33c = INFINITY;
  *(undefined4 *)data[2].opaque = 0;
  *(undefined4 *)data[3].opaque = 0;
  do {
    if (0 < (int)(&DAT_00093f78)[iVar9 * 2]) {
      iVar16 = 0;
      fVar12 = INFINITY;
      iVar2 = 0;
      pfVar3 = (float *)(&DAT_00093f7c)[iVar9 * 2];
      do {
        fVar46 = *pfVar3;
        pfVar3 = pfVar3 + 1;
        fVar47 = local_2e8[1] + -pfVar7[1] * fVar46;
        fVar21 = local_2e8[0] + -*pfVar7 * fVar46;
        fVar22 = local_2e8[2] + -pfVar7[2] * fVar46;
        fVar29 = local_2e8[3] + -pfVar7[3] * fVar46;
        fVar27 = local_2d8 + -pfVar7[4] * fVar46;
        fVar34 = local_2d4 + -pfVar7[5] * fVar46;
        fVar23 = local_2d0 + -pfVar7[6] * fVar46;
        fVar24 = local_2cc + -pfVar7[7] * fVar46;
        fVar25 = local_2c8 + fVar46 * -pfVar7[8];
        fVar26 = local_2c4 + -pfVar7[9] * fVar46;
        fVar28 = local_2c0 + -pfVar7[10] * fVar46;
        fVar30 = local_2bc + -pfVar7[0xb] * fVar46;
        fVar36 = local_2b8 + -pfVar7[0xc] * fVar46;
        fVar37 = local_2b4 + -pfVar7[0xd] * fVar46;
        fVar35 = local_2b0 + -pfVar7[0xe] * fVar46;
        fVar46 = local_2ac + -pfVar7[0xf] * fVar46;
        fVar21 = fVar47 * fVar47 + fVar21 * fVar21 + fVar22 * fVar22 + fVar29 * fVar29 +
                 fVar27 * fVar27 + fVar34 * fVar34 + fVar23 * fVar23 + fVar24 * fVar24 +
                 fVar25 * fVar25 + fVar26 * fVar26 + fVar28 * fVar28 + fVar30 * fVar30 +
                 fVar36 * fVar36 + fVar37 * fVar37 + fVar35 * fVar35 + fVar46 * fVar46;
        if ((int)((uint)(fVar21 < fVar12) << 0x1f) < 0) {
          fVar12 = fVar21;
          iVar16 = iVar2;
        }
        iVar2 = iVar2 + 1;
      } while ((&DAT_00093f78)[iVar9 * 2] != iVar2);
      if (fVar12 < local_33c) {
        *(int *)data[3].opaque = iVar16;
        *(int *)data[2].opaque = iVar9;
        local_33c = fVar12;
      }
    }
    iVar9 = iVar9 + 1;
    pfVar7 = pfVar7 + 0x10;
  } while (iVar9 != 4);
  iVar9 = *(int *)data[2].opaque;
  compute_scale_factors
            (dt_00,sr_00,local_268 + iVar9 * 0x10,SUB41(iVar9,0),*(float **)data[3].opaque);
  if (iVar9 < 2) {
    iVar2 = 0x28;
  }
  else {
    iVar2 = 0x40;
  }
  iVar2 = iVar9 * 0x40 + iVar2;
  uVar6 = *(uint *)((int)auStack_170 + iVar2 + 4);
  if (iVar9 < 2) {
    iVar16 = 10;
  }
  else {
    iVar16 = 0x10;
  }
  puVar5 = (uint *)((int)auStack_170 + iVar2 + 4);
  if (uVar6 == 0) {
    iVar13 = 0;
    do {
      iVar2 = iVar13;
      puVar4 = puVar5;
      puVar5 = puVar4 + -1;
      uVar6 = *puVar5;
      iVar13 = iVar2 + 1;
    } while (uVar6 == 0);
    iVar2 = iVar2 + 2;
    *(undefined4 *)data[4].opaque = 0;
    data[6].opaque[0] = (byte)(uVar6 >> 0x1f);
    uVar8 = (uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f);
    if (iVar2 < iVar16) {
      uVar20 = puVar4[-2];
      if (uVar20 != 0) goto LAB_00071ac8;
      uVar6 = 0;
LAB_00071ad4:
      if ((int)uVar20 < 0) {
        uVar20 = -uVar20;
      }
      iVar13 = iVar2 * 0xb + uVar8;
      uVar8 = uVar8 + uVar20;
      uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + iVar13 * 4);
      iVar13 = iVar2 + 1;
      if (iVar13 < iVar16) goto LAB_00071b0c;
      goto LAB_00071dfa;
    }
  }
  else {
    uVar20 = *(uint *)((int)auStack_170 + iVar2);
    *(undefined4 *)data[4].opaque = 0;
    uVar8 = uVar6;
    if ((int)uVar6 < 0) {
      uVar8 = -uVar6;
    }
    data[6].opaque[0] = (byte)(uVar6 >> 0x1f);
    if (uVar20 != 0) {
      iVar2 = 1;
LAB_00071ac8:
      uVar6 = uVar6 >> 0x1f;
      data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
      goto LAB_00071ad4;
    }
    iVar2 = 1;
    iVar13 = 2;
    uVar6 = *(uint *)(&LAB_00093cb8 + (uVar8 + 0xb) * 4);
LAB_00071b0c:
    uVar20 = puVar5[-2];
    if (uVar20 != 0) {
      uVar6 = (uint)data[6].opaque[0] | uVar6 << 1;
      data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
    }
    if ((int)uVar20 < 0) {
      uVar20 = -uVar20;
    }
    uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + (iVar13 * 0xb + uVar8) * 4);
    if (iVar2 + 2 < iVar16) {
      uVar14 = puVar5[-3];
      if (uVar14 != 0) {
        uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
        data[6].opaque[0] = (byte)(uVar14 >> 0x1f);
      }
      uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 2) * 0xb + uVar20 + uVar8) * 4);
      if ((int)uVar14 < 0) {
        uVar14 = -uVar14;
      }
      iVar13 = uVar20 + uVar8 + uVar14;
      if (iVar2 + 3 < iVar16) {
        uVar20 = puVar5[-4];
        if (uVar20 != 0) {
          uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
          data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
        }
        uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 3) * 0xb + iVar13) * 4);
        if ((int)uVar20 < 0) {
          uVar20 = -uVar20;
        }
        iVar13 = iVar13 + uVar20;
        if (iVar2 + 4 < iVar16) {
          uVar20 = puVar5[-5];
          if (uVar20 != 0) {
            uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
            data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
          }
          uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 4) * 0xb + iVar13) * 4);
          if ((int)uVar20 < 0) {
            uVar20 = -uVar20;
          }
          iVar13 = iVar13 + uVar20;
          if (iVar2 + 5 < iVar16) {
            uVar20 = puVar5[-6];
            if (uVar20 != 0) {
              uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
              data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
            }
            uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 5) * 0xb + iVar13) * 4);
            if ((int)uVar20 < 0) {
              uVar20 = -uVar20;
            }
            iVar13 = iVar13 + uVar20;
            if (iVar2 + 6 < iVar16) {
              uVar20 = puVar5[-7];
              if (uVar20 != 0) {
                uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
              }
              uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 6) * 0xb + iVar13) * 4);
              if ((int)uVar20 < 0) {
                uVar20 = -uVar20;
              }
              iVar13 = iVar13 + uVar20;
              if (iVar2 + 7 < iVar16) {
                uVar20 = puVar5[-8];
                if (uVar20 != 0) {
                  uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                  data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                }
                if ((int)uVar20 < 0) {
                  uVar20 = -uVar20;
                }
                iVar15 = iVar13 + uVar20;
                uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 7) * 0xb + iVar13) * 4);
                if (iVar2 + 8 < iVar16) {
                  uVar20 = puVar5[-9];
                  if (uVar20 != 0) {
                    uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                    data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                  }
                  uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 8) * 0xb + iVar15) * 4);
                  if ((int)uVar20 < 0) {
                    uVar20 = -uVar20;
                  }
                  iVar15 = uVar20 + iVar15;
                  if (iVar2 + 9 < iVar16) {
                    uVar20 = puVar5[-10];
                    if (uVar20 != 0) {
                      uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                      data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                    }
                    if ((int)uVar20 < 0) {
                      uVar20 = -uVar20;
                    }
                    uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 9) * 0xb + iVar15) * 4);
                    iVar15 = uVar20 + iVar15;
                    if (iVar2 != 6) {
                      uVar20 = puVar5[-0xb];
                      if (uVar20 != 0) {
                        uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                        data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                      }
                      if ((int)uVar20 < 0) {
                        uVar20 = -uVar20;
                      }
                      uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 10) * 0xb + iVar15) * 4);
                      iVar15 = iVar15 + uVar20;
                      if (iVar2 != 5) {
                        uVar20 = puVar5[-0xc];
                        if (uVar20 != 0) {
                          uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                          data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                        }
                        if ((int)uVar20 < 0) {
                          uVar20 = -uVar20;
                        }
                        uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + ((iVar2 + 0xb) * 0xb + iVar15) * 4)
                        ;
                        iVar15 = iVar15 + uVar20;
                        if (iVar2 != 4) {
                          uVar20 = puVar5[-0xd];
                          if (uVar20 != 0) {
                            uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                            data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                          }
                          if ((int)uVar20 < 0) {
                            uVar20 = -uVar20;
                          }
                          uVar6 = uVar6 + *(int *)(&LAB_00093cb8 +
                                                  ((iVar2 + 0xc) * 0xb + iVar15) * 4);
                          iVar15 = iVar15 + uVar20;
                          if (iVar2 != 3) {
                            uVar20 = puVar5[-0xe];
                            if (uVar20 != 0) {
                              uVar6 = (uint)data[6].opaque[0] | uVar6 * 2;
                              data[6].opaque[0] = (byte)(uVar20 >> 0x1f);
                            }
                            if ((int)uVar20 < 0) {
                              uVar20 = -uVar20;
                            }
                            uVar6 = uVar6 + *(int *)(&LAB_00093cb8 +
                                                    ((iVar2 + 0xd) * 0xb + iVar15) * 4);
                            if (iVar2 == 1) {
                              if (puVar5[-0xf] != 0) {
                                bVar19 = data[6].opaque[0];
                                data[6].opaque[0] = (byte)(puVar5[-0xf] >> 0x1f);
                                uVar6 = (uint)bVar19 | uVar6 * 2;
                              }
                              uVar6 = uVar6 + *(int *)(&LAB_00093cb8 + (uVar20 + iVar15 + 0xa5) * 4)
                              ;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_00071dfa:
    *(uint *)data[4].opaque = uVar6;
  }
  if (iVar9 != 0) goto LAB_00071e04;
  if (local_12c == 0.0) {
    pfVar7 = &local_12c;
    iVar2 = 0;
    do {
      iVar9 = iVar2;
      puVar5 = (uint *)pfVar7;
      pfVar7 = (float *)(puVar5 + -1);
      uVar6 = (uint)*pfVar7;
      iVar2 = iVar9 + 1;
    } while (uVar6 == 0);
    iVar9 = iVar9 + 2;
    *(undefined4 *)data[5].opaque = 0;
    data[6].opaque[1] = (byte)(uVar6 >> 0x1f);
    fVar12 = (float)((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f));
    if (5 < iVar9) goto LAB_00071e04;
    uVar6 = puVar5[-2];
    if (uVar6 != 0) goto LAB_000720bc;
    uVar20 = 0;
LAB_000720c8:
    iVar2 = iVar9 * 0xb + (int)fVar12;
    fVar12 = (float)((int)fVar12 + ((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f)));
    uVar20 = uVar20 + *(int *)(&LAB_00093cb8 + iVar2 * 4);
    iVar2 = iVar9 + 1;
    if (iVar9 != 5) goto LAB_000720ee;
  }
  else {
    data[6].opaque[1] = (byte)((uint)local_12c >> 0x1f);
    fVar12 = local_12c;
    if ((int)local_12c < 0) {
      fVar12 = (float)-(int)local_12c;
    }
    if (local_130 != 0) {
      iVar9 = 1;
      pfVar7 = &local_12c;
      uVar6 = local_130;
LAB_000720bc:
      uVar20 = (uint)data[6].opaque[1];
      data[6].opaque[1] = (byte)(uVar6 >> 0x1f);
      goto LAB_000720c8;
    }
    iVar9 = 1;
    iVar2 = 2;
    uVar20 = *(uint *)(&LAB_00093cb8 + ((int)fVar12 + 0xbU) * 4);
    pfVar7 = &local_12c;
LAB_000720ee:
    uVar6 = (uint)pfVar7[-2];
    if (uVar6 != 0) {
      uVar20 = (uint)data[6].opaque[1] | uVar20 << 1;
      data[6].opaque[1] = (byte)(uVar6 >> 0x1f);
    }
    if ((int)uVar6 < 0) {
      uVar6 = -uVar6;
    }
    uVar20 = uVar20 + *(int *)(&LAB_00093cb8 + (iVar2 * 0xb + (int)fVar12) * 4);
    if (iVar9 != 4) {
      uVar8 = (uint)pfVar7[-3];
      if (uVar8 != 0) {
        uVar20 = (uint)data[6].opaque[1] | uVar20 * 2;
        data[6].opaque[1] = (byte)(uVar8 >> 0x1f);
      }
      if ((int)uVar8 < 0) {
        uVar8 = -uVar8;
      }
      uVar20 = uVar20 + *(int *)(&LAB_00093cb8 + ((iVar9 + 2) * 0xb + uVar6 + (int)fVar12) * 4);
      iVar2 = uVar8 + uVar6 + (int)fVar12;
      if (iVar9 != 3) {
        uVar6 = (uint)pfVar7[-4];
        if (uVar6 != 0) {
          uVar20 = (uint)data[6].opaque[1] | uVar20 * 2;
          data[6].opaque[1] = (byte)(uVar6 >> 0x1f);
        }
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        uVar20 = uVar20 + *(int *)(&LAB_00093cb8 + ((iVar9 + 3) * 0xb + iVar2) * 4);
        if (iVar9 == 1) {
          if (pfVar7[-5] != 0.0) {
            bVar19 = data[6].opaque[1];
            data[6].opaque[1] = (byte)((uint)pfVar7[-5] >> 0x1f);
            uVar20 = (uint)bVar19 | uVar20 * 2;
          }
          uVar20 = uVar20 + *(int *)(&LAB_00093cb8 + (uVar6 + iVar2 + 0x37) * 4);
        }
      }
    }
  }
  *(uint *)data[5].opaque = uVar20;
LAB_00071e04:
  spectral_shaping(dt,sr,&local_328,false,x,y);
  return;
}


