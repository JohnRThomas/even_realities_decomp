/*
 * Function: nrf_fuel_gauge_internal_0
 * Entry:    0000c358
 * Prototype: undefined __stdcall nrf_fuel_gauge_internal_0(float param_1, float param_2, float param_3, float param_4, float * param_5, float * param_6, float * param_7, float * param_8)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* exclude_from_export */

void nrf_fuel_gauge_internal_0
               (float param_1,float param_2,float param_3,float param_4,float *param_5,
               float *param_6,float *param_7,float *param_8)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  bool bVar4;
  int *piVar5;
  float *pfVar6;
  float *pfVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  float *pfVar8;
  undefined1 *puVar9;
  int *piVar10;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint extraout_r3;
  uint extraout_r3_00;
  float *pfVar11;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  float *pfVar20;
  int *piVar21;
  float *pfVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float extraout_s12;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  ulonglong uVar39;
  int local_280;
  float *local_27c;
  float *local_278;
  float *local_270;
  int local_26c;
  int local_268;
  undefined1 local_258 [4];
  float local_254 [2];
  undefined4 local_24c;
  int local_248;
  undefined4 uStack_244;
  int local_240;
  float local_23c [12];
  int aiStack_20c [2];
  float afStack_204 [13];
  float local_1d0 [6];
  float local_1b8 [6];
  float local_1a0 [4];
  float local_190 [4];
  float local_180 [11];
  float afStack_154 [8];
  float afStack_134 [4];
  float afStack_124 [9];
  float local_100 [4];
  float local_f0 [4];
  float local_e0 [4];
  float local_d0 [4];
  float local_c0 [4];
  float local_b0 [4];
  float local_a0 [16];
  float fStack_60;
  float *pfVar12;
  
  fVar35 = param_5[0x5d2];
  if (((*(char *)(param_5 + 0x5d3) != '\x01') && (-1 < (int)((uint)(param_3 < fVar35) << 0x1f))) &&
     (fVar35 = param_5[0x5d1], -1 < (int)((uint)(param_5[0x5d1] < param_3) << 0x1f))) {
    fVar35 = param_3;
  }
  pfVar7 = param_5 + 0x11a;
  fVar23 = nrf_fuel_gauge_internal_7(pfVar7);
  pfVar8 = param_5 + 0x11b;
  pfVar13 = param_5 + 0x11c;
  fVar24 = nrf_fuel_gauge_internal_6(pfVar7);
  fVar25 = fminf(fVar35,fVar23);
  fVar25 = fmaxf(fVar25,fVar24);
  local_258[0] = *pfVar7 == fVar25;
  local_258[1] = *pfVar8 == fVar25;
  local_258[2] = *pfVar13 == fVar25;
  nrf_fuel_gauge_internal_5((int)local_258,(int)aiStack_20c,&uStack_244);
  local_26c = local_240;
  if (local_240 == 0) {
    local_23c[0] = nrf_fuel_gauge_internal_4(fVar25,pfVar7,param_5 + 0x5be);
    local_26c = 1;
  }
  else if (0 < local_240) {
    pfVar6 = local_23c;
    piVar5 = aiStack_20c;
    do {
      piVar10 = piVar5 + 1;
      *pfVar6 = param_5[*piVar5 + 0x5bd];
      pfVar6 = pfVar6 + 1;
      piVar5 = piVar10;
    } while (piVar10 != aiStack_20c + local_240);
  }
  local_278 = local_23c;
  fVar25 = fminf(fVar35,fVar23);
  fVar25 = fmaxf(fVar25,fVar24);
  local_258[0] = *pfVar7 == fVar25;
  local_258[1] = *pfVar8 == fVar25;
  local_258[2] = *pfVar13 == fVar25;
  nrf_fuel_gauge_internal_5((int)local_258,(int)aiStack_20c,&uStack_244);
  if (local_240 == 0) {
    nrf_fuel_gauge_internal_1(fVar25,pfVar7,param_5 + 0x5b2,local_254);
    iVar19 = 2;
    local_1b8[0] = local_254[0];
    local_268 = 4;
    iVar16 = iVar19;
LAB_0000c51e:
    local_27c = local_1b8;
    pfVar6 = local_1d0;
    iVar15 = 0;
    do {
      fVar25 = *local_27c;
      local_27c = local_27c + 1;
      fVar25 = fabsf(fVar25);
      iVar15 = iVar15 + 1;
      *pfVar6 = fVar25;
      pfVar6 = pfVar6 + 1;
    } while (iVar15 < iVar19);
    if (0 < iVar16) {
LAB_0000c546:
      local_270 = local_1d0;
      iVar15 = 0;
      do {
        iVar15 = iVar15 + 1;
        *local_270 = -param_4 / *local_270;
        local_270 = local_270 + 1;
      } while (iVar15 < iVar16);
      if (iVar19 < 1) goto LAB_0000c580;
    }
    local_270 = local_1d0;
    iVar16 = 0;
    do {
      fVar25 = expf(*local_270);
      iVar16 = iVar16 + 1;
      *local_270 = fVar25;
      local_270 = local_270 + 1;
    } while (iVar19 != iVar16);
  }
  else {
    iVar19 = local_240 * 2;
    if (0 < local_240) {
      local_268 = local_240 * 4;
      piVar10 = aiStack_20c + local_240;
      piVar5 = aiStack_20c;
      pfVar6 = local_1b8;
      do {
        piVar21 = piVar5 + 1;
        *pfVar6 = param_5[*piVar5 + 0x5b1];
        piVar5 = piVar21;
        pfVar6 = pfVar6 + 1;
      } while (piVar10 != piVar21);
      piVar5 = aiStack_20c;
      pfVar6 = local_1b8 + local_240;
      do {
        piVar21 = piVar5 + 1;
        *pfVar6 = param_5[*piVar5 + 0x5b4];
        piVar5 = piVar21;
        pfVar6 = pfVar6 + 1;
      } while (piVar21 != piVar10);
      iVar16 = iVar19;
      if (0 < iVar19) goto LAB_0000c51e;
      iVar16 = 0x7fffffff;
      goto LAB_0000c546;
    }
    if (0 < iVar19) {
      local_268 = local_240 << 2;
      iVar16 = -0x80000000;
      goto LAB_0000c51e;
    }
    local_268 = local_240 << 2;
  }
LAB_0000c580:
  local_27c = local_1b8;
  fVar25 = fminf(fVar35,fVar23);
  fVar25 = fmaxf(fVar25,fVar24);
  local_258[0] = *pfVar7 == fVar25;
  local_258[1] = *pfVar8 == fVar25;
  local_258[2] = *pfVar13 == fVar25;
  nrf_fuel_gauge_internal_5((int)local_258,(int)aiStack_20c,&uStack_244);
  if (local_240 == 0) {
    nrf_fuel_gauge_internal_1(fVar25,pfVar7,param_5 + 0x5b8,local_254);
    iVar16 = 4;
    fVar25 = local_254[0];
  }
  else {
    fVar25 = local_1b8[0];
    if (local_240 < 1) {
      iVar16 = local_240 << 2;
    }
    else {
      iVar16 = local_240 * 4;
      piVar10 = aiStack_20c + local_240;
      piVar5 = aiStack_20c;
      pfVar6 = local_27c;
      do {
        piVar21 = piVar5 + 1;
        *pfVar6 = param_5[*piVar5 + 0x5b7];
        piVar5 = piVar21;
        pfVar6 = pfVar6 + 1;
      } while (piVar10 != piVar21);
      pfVar6 = local_27c + local_240;
      piVar5 = aiStack_20c;
      do {
        piVar21 = piVar5 + 1;
        *pfVar6 = param_5[*piVar5 + 0x5ba];
        pfVar6 = pfVar6 + 1;
        piVar5 = piVar21;
      } while (piVar10 != piVar21);
    }
  }
  fVar23 = fminf(fVar35,fVar23);
  fVar23 = fmaxf(fVar23,fVar24);
  local_258[0] = *pfVar7 == fVar23;
  local_258[1] = *pfVar8 == fVar23;
  local_258[2] = *pfVar13 == fVar23;
  nrf_fuel_gauge_internal_5((int)local_258,(int)aiStack_20c,&uStack_244);
  local_280 = local_240;
  if (local_240 == 0) {
    local_23c[3] = nrf_fuel_gauge_internal_4(fVar23,pfVar7,param_5 + 0x5af);
    local_280 = 1;
  }
  else if (0 < local_240) {
    pfVar13 = local_23c + 3;
    piVar5 = aiStack_20c;
    do {
      piVar10 = piVar5 + 1;
      *pfVar13 = param_5[*piVar5 + 0x5ae];
      pfVar13 = pfVar13 + 1;
      piVar5 = piVar10;
    } while (aiStack_20c + local_240 != piVar10);
  }
  fVar37 = *(float *)((int)local_27c + iVar16);
  fVar23 = fabsf(param_1 - param_5[0x17]);
  fVar24 = fabsf(param_5[0x15] - param_2);
  uVar39 = __aeabi_f2d((uint)fVar24,extraout_r1,extraout_r2,extraout_r3);
  bVar4 = __ltdf2((uint)uVar39,(uint)(uVar39 >> 0x20),0xd2f1a9fc,0x3f70624d);
  if (bVar4) {
    uVar39 = __aeabi_f2d((uint)fVar23,extraout_r1_00,extraout_r2_00,extraout_r3_00);
    bVar4 = __ltdf2((uint)uVar39,(uint)(uVar39 >> 0x20),0xd2f1a9fc,0x3f70624d);
    if ((!bVar4) || (-1 < (int)((uint)(param_3 < 0.0) << 0x1f))) goto LAB_0000c72a;
    fVar23 = fVar23 / fVar24;
  }
  else {
LAB_0000c72a:
    fVar23 = param_5[0x5da];
  }
  fVar24 = param_5[0x5dd] * 0.9999 + fVar23 * 0.0001;
  fVar36 = param_5[0x5dc] * 0.9999 + fVar24 * 0.0001;
  local_23c[6] = -fVar36 + fVar24 * 2.0;
  if (((int)((uint)(param_5[0x5d2] < param_3) << 0x1f) < 0) || (0.0 <= param_3)) {
    memcpy(local_23c + 6,local_23c + 3,local_280 << 2);
  }
  else {
    local_280 = 1;
  }
  memset(afStack_124 + 1,0,0x40);
  fVar30 = local_23c[0];
  fVar33 = param_5[0x5d5];
  afStack_204[1] = 0.0;
  afStack_204[2] = 0.0;
  afStack_204[3] = 0.0;
  afStack_204[4] = 0.0;
  afStack_124[(int)fVar33 * 5 + -4] = 1.0;
  if (0 < local_26c) {
    pfVar13 = local_278;
    do {
      *pfVar13 = *pfVar13 * 3600.0;
      pfVar13 = pfVar13 + 1;
    } while (local_278 + local_26c != pfVar13);
  }
  fVar34 = param_5[1];
  fVar38 = 0.0;
  fVar29 = param_5[0x15];
  fVar31 = *param_5;
  fVar32 = *(float *)((int)local_1d0 + local_268);
  afStack_204[(int)fVar33] = -param_4 / local_23c[0];
  afStack_124[(int)fVar31 * 5 + -4] = local_1d0[0];
  afStack_124[(int)fVar34 * 5 + -4] = fVar32;
  afStack_204[(int)fVar31] = 1.0 - local_1d0[0];
  afStack_204[(int)fVar34] = 1.0 - fVar32;
  afStack_204[8] = fVar32;
  fVar33 = expf(-((fVar29 * 0.0 * param_4) / local_23c[0]));
  local_1a0[0] = afStack_204[1];
  local_1a0[1] = afStack_204[2];
  local_190[0] = afStack_204[1] * 0.0;
  local_190[1] = afStack_204[2] * 0.0;
  local_1a0[2] = afStack_204[3];
  local_1a0[3] = afStack_204[4];
  local_190[2] = afStack_204[3] * 0.0;
  local_190[3] = afStack_204[4] * 0.0;
  fVar29 = param_5[0x15];
  afStack_134[(int)param_5[0x5d4] * 5] = fVar33;
  iVar16 = isnanf(fVar29);
  if (iVar16 == 0) {
    fVar29 = param_5[0x15];
    if (fVar29 < 0.0) {
      fVar38 = -1.0;
    }
    else if (fVar29 != 0.0) {
      fVar38 = 1.0;
    }
  }
  else {
    fVar29 = param_5[0x15];
    fVar38 = DAT_20002d3c;
  }
  iVar19 = (int)param_5[0x5d4];
  fVar31 = param_5[0x5d6];
  fVar32 = param_5[0x5d7];
  fVar34 = param_5[0x5d9];
  local_190[iVar19 + -1] = fVar33 - 1.0;
  pfVar8 = afStack_124 + 1;
  pfVar13 = local_a0;
  iVar16 = 0;
  afStack_204[iVar19] =
       -(((param_4 * 0.0) / fVar30) * fVar33) * (param_5[iVar19 + 0x5d5] * fVar38 + 1.0);
  fVar30 = param_5[0x5d8];
  pfVar20 = afStack_204 + 9;
  pfVar17 = param_5 + 0x10;
  pfVar7 = pfVar8;
  pfVar6 = local_e0;
  pfVar18 = local_1a0;
  pfVar22 = pfVar13;
  do {
    fVar33 = pfVar7[4];
    fVar27 = pfVar7[8];
    fVar28 = pfVar7[0xc];
    fVar26 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    *pfVar20 = fVar32 * fVar33 + fVar26 * fVar31 + fVar27 * fVar30 + fVar28 * fVar34 +
               fVar38 * pfVar18[4] + *pfVar18 * fVar29;
    pfVar20 = pfVar20 + 1;
    pfVar11 = param_5;
    pfVar14 = pfVar6;
    do {
      pfVar12 = pfVar11 + 3;
      pfVar1 = pfVar11 + 2;
      pfVar2 = pfVar11 + 4;
      pfVar3 = pfVar11 + 5;
      pfVar11 = pfVar11 + 4;
      *pfVar14 = fVar33 * *pfVar12 + fVar26 * *pfVar1 + fVar27 * *pfVar2 + fVar28 * *pfVar3;
      pfVar14 = pfVar14 + 4;
    } while (pfVar17 != pfVar11);
    fVar33 = *pfVar6;
    fVar26 = pfVar6[4];
    fVar27 = pfVar6[8];
    fVar28 = pfVar6[0xc];
    pfVar11 = afStack_124 + 1;
    pfVar14 = pfVar22;
    do {
      pfVar12 = pfVar11 + 1;
      *pfVar14 = fVar26 * pfVar11[4] + *pfVar11 * fVar33 + fVar27 * pfVar11[8] +
                 fVar28 * pfVar11[0xc];
      pfVar14 = pfVar14 + 4;
      pfVar11 = pfVar12;
    } while (afStack_124 + 5 != pfVar12);
    iVar16 = iVar16 + 1;
    pfVar22 = pfVar22 + 1;
    pfVar6 = pfVar6 + 1;
    pfVar18 = pfVar18 + 1;
  } while (iVar16 != 4);
  fVar30 = fmaxf(-1.0,afStack_204[iVar19 + 8]);
  fVar33 = param_5[0x5d4];
  fVar30 = fminf(1.0,fVar30);
  fVar38 = param_5[0x5d5];
  afStack_204[(int)fVar33 + 8] = fVar30;
  fVar30 = fmaxf(-0.05,afStack_204[(int)fVar38 + 8]);
  fVar33 = param_5[0x5d5];
  fVar30 = fminf(1.05,fVar30);
  fVar38 = param_5[0x13];
  pfVar18 = afStack_204 + 1;
  afStack_204[(int)fVar33 + 8] = fVar30;
  pfVar7 = pfVar18;
  pfVar6 = afStack_124 + 1;
  do {
    fVar30 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    *pfVar6 = fVar38 * afStack_204[1] * fVar30;
    pfVar6[1] = fVar30 * fVar38 * afStack_204[2];
    pfVar6[2] = fVar30 * fVar38 * afStack_204[3];
    pfVar6[3] = fVar30 * fVar38 * afStack_204[4];
    pfVar6 = pfVar6 + 4;
  } while (afStack_204 + 5 != pfVar7);
  pfVar7 = param_5 + 2;
  do {
    fVar33 = *pfVar13;
    pfVar13 = pfVar13 + 1;
    fVar30 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    *pfVar7 = fVar33 + fVar30;
    pfVar7 = pfVar7 + 1;
  } while (&fStack_60 != pfVar13);
  fVar33 = param_5[0x119];
  pfVar13 = afStack_204 + (int)param_5[0x5d5] + 9;
  fVar30 = param_5[0x51];
  fVar38 = afStack_204[(int)param_5[0x5d5] + 8];
  fVar29 = param_5[0x52] - fVar30;
  if (fVar30 < fVar38) {
    if ((int)((uint)(fVar38 < fVar33) << 0x1f) < 0) {
      if (fVar38 == fVar33) {
        pfVar13 = (float *)&DAT_00000001;
        goto LAB_0000d2ac;
      }
      goto LAB_0000cc1a;
    }
    if (fVar33 <= fVar38) goto LAB_0000d2aa;
    fVar33 = 0.0;
  }
  else {
    iVar16 = (uint)(fVar30 < fVar38) << 0x1f;
    if (fVar33 <= fVar38) {
      if (iVar16 < 0) {
        iVar16 = (uint)(fVar38 < fVar33) << 0x1f;
        if (iVar16 < 0) {
          pfVar13 = (float *)&DAT_00000001;
        }
        if (-1 < iVar16) {
          pfVar13 = (float *)0x0;
        }
      }
      else {
LAB_0000d2aa:
        pfVar13 = (float *)0x0;
      }
LAB_0000d2ac:
      fVar33 = (((param_5[0x328] + param_5[0x25f] * fVar35) -
                (param_5[0x327] + param_5[0x25e] * fVar35)) * (fVar38 - fVar33)) / fVar29 +
               param_5[0x328] + param_5[0x25f] * fVar35;
    }
    else {
      if (iVar16 < 0) {
        iVar16 = (uint)(fVar38 < fVar33) << 0x1f;
        if (iVar16 < 0) {
          pfVar13 = (float *)&DAT_00000001;
        }
        if (-1 < iVar16) {
          pfVar13 = (float *)0x0;
        }
      }
      else {
        pfVar13 = (float *)0x0;
      }
      fVar33 = ((fVar38 - fVar30) *
               ((param_5[0x261] + param_5[0x198] * fVar35) -
               (param_5[0x260] + param_5[0x197] * fVar35))) / fVar29 + param_5[0x260] +
               param_5[0x197] * fVar35;
    }
    if (pfVar13 != (float *)0x0) {
LAB_0000cc1a:
      fVar30 = ceilf((fVar38 - fVar30) / fVar29);
      fVar33 = (afStack_204[(int)param_5[0x5d5] + 8] - param_5[0x51]) / fVar29 - fVar30;
      fVar33 = fVar33 * param_5[(int)(fVar30 + 2.0) + 0x25f] +
               param_5[(int)(fVar30 + 1.0) + 0x25f] * (1.0 - fVar33) +
               fVar35 * (fVar33 * param_5[(int)(fVar30 + 2.0) + 0x196] +
                        param_5[(int)(fVar30 + 1.0) + 0x196] * (1.0 - fVar33));
    }
  }
  iVar16 = isnanf(fVar38);
  fVar30 = afStack_204[(int)param_5[1] + 8];
  fVar29 = afStack_204[(int)*param_5 + 8];
  if (0 < local_280) {
    pfVar13 = local_23c + 6;
    pfVar7 = pfVar13 + local_280;
    pfVar8 = local_278;
    do {
      fVar31 = *pfVar13;
      pfVar13 = pfVar13 + 1;
      *pfVar8 = (float)((uint)(iVar16 == 0) * (int)fVar33) + -fVar30 * fVar37 + -fVar29 * fVar25 +
                -fVar31 * param_2;
      pfVar8 = pfVar8 + 1;
    } while (pfVar7 != pfVar13);
  }
  fVar31 = param_5[0x5d5];
  fVar29 = 0.0;
  afStack_204[1] = 0.0;
  afStack_204[2] = 0.0;
  afStack_204[3] = 0.0;
  afStack_204[4] = 0.0;
  fVar30 = (float)nrf_fuel_gauge_internal_2
                            (fVar38,fVar35,param_5 + 0x51,param_5 + 0x329,param_5 + 0x3f2,
                             (int)(param_5 + 0x5d5));
  fVar33 = *param_5;
  fVar32 = param_5[1];
  fVar38 = param_5[0x5d4];
  afStack_204[(int)fVar31] = fVar30;
  afStack_204[(int)fVar38] = 0.0;
  afStack_204[(int)fVar33] = -fVar25;
  afStack_204[(int)fVar32] = -fVar37;
  pfVar13 = param_5;
  do {
    pfVar8 = pfVar13 + 3;
    pfVar7 = pfVar13 + 2;
    pfVar6 = pfVar13 + 4;
    pfVar22 = pfVar13 + 5;
    fVar25 = *pfVar18;
    pfVar18 = pfVar18 + 1;
    pfVar13 = pfVar13 + 4;
    fVar29 = fVar29 + (afStack_204[2] * *pfVar8 + afStack_204[1] * *pfVar7 +
                       afStack_204[3] * *pfVar6 + afStack_204[4] * *pfVar22) * fVar25;
  } while (pfVar17 != pfVar13);
  pfVar13 = afStack_204 + 5;
  fVar29 = fVar29 + param_5[0x12];
  pfVar8 = pfVar13;
  pfVar7 = param_5 + 2;
  do {
    pfVar6 = pfVar7 + 1;
    *pfVar8 = (afStack_204[2] * pfVar7[4] + afStack_204[1] * *pfVar7 + afStack_204[3] * pfVar7[8] +
              afStack_204[4] * pfVar7[0xc]) / fVar29;
    pfVar8 = pfVar8 + 1;
    pfVar7 = pfVar6;
  } while (param_5 + 6 != pfVar6);
  if (local_280 < 1) {
    local_24c = 1;
    local_248 = local_280;
    iVar16 = nrf_fuel_gauge_internal_3((int)local_258,(int)&local_24c);
    if (iVar16 != 0) {
      afStack_204[5] = 0.0;
      afStack_204[6] = 0.0;
      afStack_204[7] = 0.0;
      afStack_204[8] = 0.0;
    }
  }
  else {
    pfVar8 = local_23c + 3;
    pfVar6 = local_278 + local_280;
    pfVar7 = pfVar8;
    do {
      fVar25 = *local_278;
      local_278 = local_278 + 1;
      *pfVar7 = param_1 - fVar25;
      pfVar7 = pfVar7 + 1;
    } while (pfVar6 != local_278);
    pfVar7 = local_23c + 9;
    pfVar6 = pfVar7;
    do {
      fVar25 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      *pfVar6 = local_23c[3] * fVar25;
      pfVar6 = pfVar6 + 1;
    } while (local_23c + local_280 + 3 != pfVar8);
    local_24c = 1;
    local_248 = local_280;
    pfVar8 = pfVar7 + local_280;
    puVar9 = local_258;
    do {
      fVar25 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      *puVar9 = fVar29 * 100.0 < fVar25;
      puVar9 = puVar9 + 1;
    } while (pfVar8 != pfVar7);
    iVar16 = nrf_fuel_gauge_internal_3((int)local_258,(int)&local_24c);
    if (iVar16 != 0) {
      afStack_204[5] = 0.0;
      afStack_204[6] = 0.0;
      afStack_204[7] = 0.0;
      afStack_204[8] = 0.0;
    }
    pfVar8 = afStack_154 + 1;
    pfVar7 = local_23c + 3;
    pfVar18 = pfVar7 + local_280;
    pfVar6 = pfVar8;
    do {
      fVar25 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      *pfVar6 = afStack_204[5] * fVar25;
      pfVar6[1] = afStack_204[6] * fVar25;
      pfVar6[2] = afStack_204[7] * fVar25;
      pfVar6[3] = afStack_204[8] * fVar25;
      pfVar6 = pfVar6 + 4;
    } while (pfVar18 != pfVar7);
    pfVar7 = local_180;
    pfVar6 = pfVar8;
    do {
      fVar25 = *pfVar6;
      fVar37 = pfVar6[1];
      fVar30 = pfVar6[2];
      fVar33 = pfVar6[3];
      pfVar6 = pfVar6 + 4;
      *pfVar7 = fVar25 + afStack_204[9];
      pfVar7[1] = fVar37 + afStack_204[10];
      pfVar7[2] = fVar30 + afStack_204[0xb];
      pfVar7[3] = fVar33 + afStack_204[0xc];
      pfVar7 = pfVar7 + 4;
    } while (pfVar8 + local_280 * 4 != pfVar6);
    pfVar7 = local_180;
    do {
      pfVar6 = pfVar7 + 4;
      *pfVar8 = *pfVar7;
      pfVar8[1] = pfVar7[1];
      pfVar8[2] = pfVar7[2];
      pfVar8[3] = pfVar7[3];
      pfVar8 = pfVar8 + 4;
      pfVar7 = pfVar6;
    } while (local_180 + local_280 * 4 != pfVar6);
  }
  fVar33 = afStack_204[8];
  fVar30 = afStack_204[7];
  fVar37 = afStack_204[6];
  fVar25 = afStack_204[5];
  fVar38 = fmaxf(-1.0,afStack_154[(int)param_5[0x5d4]]);
  fVar31 = param_5[0x5d4];
  fVar38 = fminf(1.0,fVar38);
  fVar32 = param_5[0x5d5];
  afStack_154[(int)fVar31] = fVar38;
  fVar38 = fmaxf(-0.05,afStack_154[(int)fVar32]);
  fVar31 = param_5[0x5d5];
  fVar38 = fminf(1.05,fVar38);
  afStack_154[(int)fVar31] = fVar38;
  pfVar8 = param_5;
  do {
    fVar38 = *pfVar13;
    pfVar13 = pfVar13 + 1;
    pfVar7 = pfVar8 + 4;
    pfVar8[2] = pfVar8[2] + fVar38 * -(fVar25 * fVar29);
    pfVar8[3] = pfVar8[3] + -fVar38 * fVar29 * fVar37;
    *pfVar7 = pfVar8[4] + -fVar38 * fVar29 * fVar30;
    pfVar8[5] = pfVar8[5] + -fVar38 * fVar29 * fVar33;
    pfVar8 = pfVar7;
  } while (pfVar17 != pfVar7);
  local_24c = 1;
  local_248 = local_280;
  if (0 < local_280) {
    pfVar13 = local_23c + 9;
    pfVar8 = pfVar13 + local_280;
    puVar9 = local_258;
    do {
      fVar25 = *pfVar13;
      pfVar13 = pfVar13 + 1;
      *puVar9 = fVar29 * 100.0 < fVar25;
      puVar9 = puVar9 + 1;
    } while (pfVar8 != pfVar13);
  }
  iVar16 = nrf_fuel_gauge_internal_3((int)local_258,(int)&local_24c);
  if (iVar16 == 0) {
    iVar16 = (int)param_5[0x5d5] + -1;
  }
  else {
    iVar16 = (int)param_5[0x5d5] + -1;
    iVar19 = (int)param_5[0x5d5] + iVar16 * 4;
    param_5[iVar19 + 1] = param_5[iVar19 + 1] * param_5[0x14];
  }
  param_5[0x15] = param_2;
  param_5[0x5d6] = afStack_154[1];
  param_5[0x5d7] = afStack_154[2];
  param_5[0x5d8] = afStack_154[3];
  param_5[0x5d9] = afStack_154[4];
  *param_6 = afStack_154[iVar16 + 1];
  fVar25 = sqrtf(param_5[(int)param_5[0x5d5] * 5 + -3]);
  *param_7 = fVar25 * 3.0;
  param_5[0x17] = param_1;
  param_5[0x5db] = local_23c[6];
  param_5[0x5da] = fVar23;
  param_5[0x5dc] = fVar36;
  param_5[0x5dd] = fVar24;
  iVar16 = isnanf(param_5[0x4b]);
  if (iVar16 != 0) goto LAB_0000d162;
  iVar16 = isnanf(param_2);
  fVar23 = DAT_20002d3c;
  if (iVar16 == 0) {
    if (param_2 < 0.0) {
      fVar23 = -1.0;
    }
    else if (param_2 == 0.0) {
      fVar23 = 0.0;
    }
    else {
      fVar23 = 1.0;
    }
    iVar16 = isnanf(param_5[0x4b]);
    if (iVar16 != 0) goto LAB_0000d34a;
LAB_0000d4ac:
    if (param_5[0x4b] < 0.0) {
      fVar24 = -fVar23;
    }
    else {
      fVar24 = fVar23;
      if (param_5[0x4b] == 0.0) {
        fVar24 = fVar23 * 0.0;
      }
    }
  }
  else {
    iVar16 = isnanf(param_5[0x4b]);
    if (iVar16 == 0) goto LAB_0000d4ac;
LAB_0000d34a:
    fVar24 = fVar23 * DAT_20002d3c;
  }
  fVar25 = DAT_20002d3c;
  if (fVar24 == -1.0) {
    pfVar13 = param_5 + 0x18;
    do {
      pfVar8 = pfVar13 + 1;
      *pfVar13 = fVar25;
      pfVar13[0x19] = fVar25;
      pfVar13 = pfVar8;
    } while (pfVar8 != param_5 + 0x31);
    param_5[0x4f] = 0.0;
    param_5[0x4e] = 0.0;
    if (fVar23 == -1.0) {
      param_5[0x50] = afStack_154[(int)param_5[0x5d5]];
    }
    else {
      param_5[0x50] = fVar25;
    }
  }
LAB_0000d162:
  fVar24 = fabsf(param_2);
  fVar25 = fabsf(param_5[0x4b]);
  fVar25 = fVar25 * 5.0;
  fVar23 = extraout_s12;
  if (fVar25 < fVar24) {
    fVar23 = 0.0;
  }
  fVar37 = fVar23;
  if (fVar24 <= fVar25) {
    fVar37 = param_5[0x4f];
  }
  param_5[0x4f] = param_4 + fVar37;
  fVar36 = param_5[0x4a] + 1.0;
  fVar37 = afStack_154[(int)param_5[0x5d5]];
  iVar16 = (int)param_5[0x4a];
  if (fVar24 <= fVar25) {
    fVar23 = param_5[0x4e];
  }
  fVar24 = fVar37 - param_5[0x4d];
  param_5[0x4b] = param_2;
  param_5[0x4c] = fVar35;
  param_5[0x4d] = fVar37;
  param_5[0x4e] = fVar24 + fVar23;
  param_5[iVar16 + 0x17] = fVar24;
  param_5[iVar16 + 0x30] = param_4;
  param_5[0x4a] = (float)((uint)(25.0 < fVar36) * 0x3f800000 + (uint)(fVar36 <= 25.0) * (int)fVar36)
  ;
  param_8[2] = fVar33;
  param_8[3] = fVar35;
  *param_8 = local_23c[0];
  param_8[1] = local_23c[6];
  return;
}


