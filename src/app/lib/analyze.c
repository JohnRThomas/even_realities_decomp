/*
 * Function: analyze
 * Entry:    0006de28
 * Prototype: bool __stdcall analyze(int param_1, int param_2, char * param_3, undefined4 param_4, char * param_5)
 */


/* WARNING: Type propagation algorithm not settling */
/* exclude_from_export_ai */

bool analyze(int param_1,int param_2,char *param_3,undefined4 param_4,char *param_5)

{
  uint uVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  short sVar5;
  longlong lVar6;
  undefined1 *puVar7;
  bool bVar8;
  void *pvVar9;
  int iVar10;
  float *pfVar11;
  short *psVar12;
  undefined4 uVar13;
  char cVar14;
  int iVar15;
  byte *pbVar16;
  int iVar17;
  undefined2 *puVar18;
  size_t n;
  byte *pbVar19;
  int iVar20;
  short *psVar21;
  char *pcVar22;
  uint uVar23;
  undefined2 *puVar24;
  byte bVar25;
  bool bVar26;
  byte bVar27;
  uint in_fpscr;
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
  lc3_ltpf_data_t *in_stack_ffffff68;
  undefined2 auStack_90 [2];
  undefined2 *local_8c;
  int local_88;
  undefined1 *local_84;
  float local_80;
  lc3_ltpf_analysis_t *local_7c;
  float local_78 [2];
  float afStack_70 [17];
  
  local_88 = param_1;
  if (param_1 == 0) {
    memmove(param_3 + 0x20,param_3 + 0xe0,0x240);
    pcVar22 = param_3 + 0x260;
    (*(code *)(&PTR_FUN_0006dd40_1_000904c8)[param_2])(param_3 + 0x10,param_4,pcVar22,0x60);
    local_7c = (lc3_ltpf_analysis_t *)&Reserved5;
    iVar10 = 0x60;
    local_84 = (undefined1 *)0xc0;
    iVar20 = 6;
    n = 0x104;
    iVar15 = -0x58;
    local_80 = 1.34525e-43;
  }
  else {
    memmove(param_3 + 0x20,param_3 + 0x120,0x200);
    pcVar22 = param_3 + 0x220;
    (*(code *)(&PTR_FUN_0006dd40_1_000904c8)[param_2])(param_3 + 0x10,param_4,pcVar22,0x80);
    iVar10 = 0x80;
    local_7c = (lc3_ltpf_analysis_t *)&IRQ;
    iVar20 = 8;
    local_84 = (undefined1 *)0x100;
    n = 0xe4;
    iVar15 = -0x30;
    local_80 = 1.79366e-43;
  }
  psVar21 = (short *)(pcVar22 + iVar15);
  pvVar9 = memmove(param_3 + 800,param_3 + 800 + iVar10,n);
  psVar12 = psVar21 + -1;
  for (pcVar22 = (char *)((int)pvVar9 + n); pcVar22 < param_3 + 0x484; pcVar22 = pcVar22 + 2) {
    psVar2 = psVar12 + 1;
    psVar3 = psVar12 + -1;
    sVar5 = *psVar12;
    psVar4 = psVar12 + -2;
    psVar12 = psVar12 + 2;
    *(short *)pcVar22 =
         (short)((uint)(((int)*psVar4 + (int)*psVar12) * 0x1fa9 +
                       sVar5 * 0x482d + ((int)*psVar3 + (int)*psVar2) * 0x3c40) >> 0x10);
  }
  bVar8 = lc3_ltpf_analyse((lc3_dt)param_3,(lc3_srate)((int)pvVar9 + n),local_7c,(int16_t *)local_78
                           ,in_stack_ffffff68);
  fVar38 = local_80;
  puVar7 = local_84;
  if (!bVar8) {
    if (*param_3 == '\0') {
      fVar38 = 0.0;
      uVar23 = 0;
      cVar14 = '\0';
    }
    else {
      fVar38 = 0.0;
      uVar23 = 0;
      cVar14 = bVar8;
    }
    goto LAB_0006def6;
  }
  pbVar16 = (byte *)(((int)local_78[0] + -2) * 2);
  pbVar19 = pbVar16;
  if ((int)pbVar16 < 0x20) {
    pbVar19 = (byte *)0x20;
  }
  if ((int)(pbVar16 + 8) < 0xe5) {
    iVar10 = (int)(pbVar16 + 8) - (int)pbVar19;
  }
  else {
    iVar10 = 0xe4 - (int)pbVar19;
  }
  local_84 = &stack0xffffff68;
  local_7c = (lc3_ltpf_analysis_t *)pbVar19;
  local_8c = auStack_90 + -(int)puVar7;
  *(int *)(&stack0xffffff68 + (int)puVar7 * -2) = iVar10 + 9;
  correlate_ltpf((int)psVar21,psVar21 + (4 - (int)pbVar19),(int)fVar38,local_78 + 1,
                 *(int *)(&stack0xffffff68 + (int)puVar7 * -2));
  fVar38 = local_80;
  if (iVar10 < 1) {
    iVar10 = 0x10;
  }
  else {
    iVar15 = 0;
    iVar17 = 1;
    pfVar11 = afStack_70 + 4;
    do {
      fVar36 = *pfVar11;
      pfVar11 = pfVar11 + 1;
      uVar23 = in_fpscr & 0xfffffff | (uint)(fVar36 < afStack_70[3]) << 0x1f |
               (uint)(fVar36 == afStack_70[3]) << 0x1e;
      in_fpscr = uVar23 | (uint)(NAN(fVar36) || NAN(afStack_70[3])) << 0x1c;
      bVar27 = (byte)(uVar23 >> 0x18);
      bVar25 = bVar27 >> 7;
      bVar26 = (bool)(bVar27 >> 6 & 1);
      bVar27 = (byte)(in_fpscr >> 0x1c) & 1;
      if (!bVar26 && bVar25 == bVar27) {
        iVar15 = iVar17;
      }
      iVar17 = iVar17 + 1;
      afStack_70[3] =
           (float)((uint)(!bVar26 && bVar25 == bVar27) * (int)fVar36 +
                  (uint)(bVar26 || bVar25 != bVar27) * (int)afStack_70[3]);
    } while (iVar10 + 1 != iVar17);
    local_7c = (lc3_ltpf_analysis_t *)((int)local_7c + iVar15);
    iVar10 = (iVar15 + 4) * 4;
  }
  fVar31 = *(float *)((int)&local_7c + iVar10);
  fVar30 = *(float *)((int)&local_80 + iVar10);
  fVar32 = *(float *)((int)local_78 + iVar10);
  fVar29 = *(float *)((int)local_78 + iVar10 + 4);
  fVar33 = *(float *)((int)afStack_70 + iVar10);
  fVar34 = *(float *)((int)afStack_70 + iVar10 + 4);
  fVar35 = *(float *)((int)afStack_70 + iVar10 + 8);
  fVar36 = fVar31 * -0.047296323 + fVar30 * 0.015357277 + fVar32 * 0.083578855 + fVar29 * 0.8986383
           + fVar33 * 0.083578855 + fVar34 * -0.047296323 + fVar35 * 0.015357277;
  if ((int)local_7c < 0x7f) {
    fVar28 = *(float *)((int)afStack_70 + iVar10 + 0xc);
    fVar37 = fVar30 * 0.0027454717 + fVar28 * -0.0028745611 + fVar31 * 0.0045983344 +
             fVar32 * -0.07544047 + fVar29 * 0.8174887 + fVar33 * 0.33018258 + fVar34 * -0.105835915
             + fVar35 * 0.02868234;
    bVar26 = fVar36 < fVar37;
    in_fpscr = in_fpscr & 0xfffffff;
    if (bVar26) {
      fVar36 = fVar37;
    }
    uVar23 = (uint)bVar26;
    if (local_7c != (lc3_ltpf_analysis_t *)0x20) {
      fVar37 = fVar29 * 0.8174887 + *(float *)((int)&local_84 + iVar10) * -0.0028745611 +
               fVar30 * 0.02868234 + fVar31 * -0.105835915 + fVar32 * 0.33018258 +
               fVar33 * -0.07544047 + fVar34 * 0.0045983344 + fVar35 * 0.0027454717;
      uVar1 = in_fpscr | (uint)(fVar37 < fVar36) << 0x1f | (uint)(fVar37 == fVar36) << 0x1e;
      in_fpscr = uVar1 | (uint)(NAN(fVar37) || NAN(fVar36)) << 0x1c;
      bVar27 = (byte)(uVar1 >> 0x18);
      if (!(bool)(bVar27 >> 6 & 1) && bVar27 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        uVar23 = 0xffffffff;
        fVar36 = fVar37;
      }
    }
LAB_0006e410:
    fVar37 = (fVar30 + fVar28) * -0.003001251 + fVar31 * 0.02950385 + fVar32 * -0.13030502 +
             fVar29 * 0.603297 + fVar33 * 0.603297 + fVar34 * -0.13030502 + fVar35 * 0.02950385;
    in_fpscr = in_fpscr & 0xfffffff;
    if (fVar36 < fVar37) {
      uVar23 = 2;
      fVar36 = fVar37;
    }
    if (local_7c == (lc3_ltpf_analysis_t *)0x20) {
LAB_0006e4c4:
      fVar28 = fVar30 * -0.0028745611 + fVar28 * 0.0027454717 + fVar31 * 0.02868234 +
               fVar32 * -0.105835915 + fVar29 * 0.33018258 + fVar33 * 0.8174887 +
               fVar34 * -0.07544047 + fVar35 * 0.0045983344;
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar36 < fVar28) {
        uVar23 = 3;
        fVar36 = fVar28;
      }
      if ((local_7c != (lc3_ltpf_analysis_t *)0x20) &&
         (fVar36 < fVar29 * 0.33018258 + *(float *)((int)&local_84 + iVar10) * 0.0027454717 +
                   fVar30 * 0.0045983344 + fVar31 * -0.07544047 + fVar32 * 0.8174887 +
                   fVar33 * -0.105835915 + fVar34 * 0.02868234 + fVar35 * -0.0028745611)) {
        uVar23 = 0xfffffffd;
      }
    }
    else {
      fVar37 = fVar29 * 0.603297 + *(float *)((int)&local_84 + iVar10) * -0.003001251 +
               fVar30 * 0.02950385 + fVar31 * -0.13030502 + fVar32 * 0.603297 + fVar33 * -0.13030502
               + fVar34 * 0.02950385 + fVar35 * -0.003001251;
      uVar1 = in_fpscr | (uint)(fVar37 < fVar36) << 0x1f | (uint)(fVar37 == fVar36) << 0x1e;
      in_fpscr = uVar1 | (uint)(NAN(fVar37) || NAN(fVar36)) << 0x1c;
      bVar27 = (byte)(uVar1 >> 0x18);
      if (!(bool)(bVar27 >> 6 & 1) && bVar27 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        uVar23 = 0xfffffffe;
        fVar36 = fVar37;
      }
      if ((int)local_7c < 0x7f) goto LAB_0006e4c4;
    }
    local_7c = (lc3_ltpf_analysis_t *)((int)local_7c + ((int)uVar23 >> 0x1f));
    iVar10 = ((int)uVar23 >> 0x1d & 4U) + uVar23;
    uVar23 = iVar10 + (int)local_7c * 4;
    if ((int)local_7c < 0x7f) {
      pbVar19 = (byte *)(uVar23 - 0x80);
    }
    else {
      if (0x9c < (int)local_7c) goto LAB_0006e076;
      pbVar19 = (byte *)((iVar10 >> 1) + (int)local_7c * 2 + 0x7e);
    }
  }
  else {
    if ((int)local_7c < 0x9d) {
      fVar28 = *(float *)((int)afStack_70 + iVar10 + 0xc);
      uVar23 = 0;
      goto LAB_0006e410;
    }
    uVar23 = (int)local_7c << 2;
LAB_0006e076:
    pbVar19 = (byte *)((int)local_7c + 0x118) + 3;
  }
  *(byte **)(param_5 + 4) = pbVar19;
  interpolate_ltpf(psVar21,(int)local_80,0,(undefined2 *)((int)auStack_90 + -(int)puVar7));
  puVar18 = local_8c;
  interpolate_ltpf(psVar21 + -((int)uVar23 >> 2),(int)fVar38,uVar23 & 3,local_8c);
  iVar10 = (int)afStack_70 + -(int)puVar7;
  iVar17 = 0;
  lVar6 = 0;
  iVar15 = iVar10;
  puVar24 = puVar18 + 0x10;
  do {
    iVar17 = iVar17 + 1;
    lVar6 = (longlong)((int)*(short *)(iVar15 + -2) * (int)(short)puVar24[-1]) +
            (longlong)((int)*(short *)(iVar15 + -4) * (int)(short)puVar24[-2]) +
            (longlong)((int)*(short *)(iVar15 + -6) * (int)(short)puVar24[-3]) +
            (longlong)((int)*(short *)(iVar15 + -8) * (int)(short)puVar24[-4]) +
            (longlong)((int)*(short *)(iVar15 + -10) * (int)(short)puVar24[-5]) +
            (longlong)((int)*(short *)(iVar15 + -0xc) * (int)(short)puVar24[-6]) +
            (longlong)((int)*(short *)(iVar15 + -0xe) * (int)(short)puVar24[-7]) +
            (longlong)((int)*(short *)(iVar15 + -0x10) * (int)(short)puVar24[-8]) +
            (longlong)((int)*(short *)(iVar15 + -0x12) * (int)(short)puVar24[-9]) +
            (longlong)((int)*(short *)(iVar15 + -0x14) * (int)(short)puVar24[-10]) +
            (longlong)((int)*(short *)(iVar15 + -0x16) * (int)(short)puVar24[-0xb]) +
            (longlong)((int)*(short *)(iVar15 + -0x18) * (int)(short)puVar24[-0xc]) +
            (longlong)((int)*(short *)(iVar15 + -0x1a) * (int)(short)puVar24[-0xd]) +
            (longlong)((int)*(short *)(iVar15 + -0x1c) * (int)(short)puVar24[-0xe]) +
            (longlong)((int)*(short *)(iVar15 + -0x1e) * (int)(short)puVar24[-0xf]) +
            (int)*(short *)(iVar15 + -0x20) * (int)(short)puVar24[-0x10] + lVar6;
    iVar15 = iVar15 + 0x20;
    puVar24 = puVar24 + 0x10;
  } while (iVar17 < iVar20);
  fVar38 = (float)VectorSignedToFloat((uint)(lVar6 + 0x20) >> 6 |
                                      (int)((ulonglong)(lVar6 + 0x20) >> 0x20) * 0x4000000,
                                      (byte)(in_fpscr >> 0x16) & 3);
  iVar15 = 0;
  lVar6 = 0;
  do {
    iVar15 = iVar15 + 1;
    lVar6 = (longlong)((int)*(short *)(iVar10 + -2) * (int)*(short *)(iVar10 + -2)) +
            (longlong)((int)*(short *)(iVar10 + -4) * (int)*(short *)(iVar10 + -4)) +
            (longlong)((int)*(short *)(iVar10 + -6) * (int)*(short *)(iVar10 + -6)) +
            (longlong)((int)*(short *)(iVar10 + -8) * (int)*(short *)(iVar10 + -8)) +
            (longlong)((int)*(short *)(iVar10 + -10) * (int)*(short *)(iVar10 + -10)) +
            (longlong)((int)*(short *)(iVar10 + -0xc) * (int)*(short *)(iVar10 + -0xc)) +
            (longlong)((int)*(short *)(iVar10 + -0xe) * (int)*(short *)(iVar10 + -0xe)) +
            (longlong)((int)*(short *)(iVar10 + -0x10) * (int)*(short *)(iVar10 + -0x10)) +
            (longlong)((int)*(short *)(iVar10 + -0x12) * (int)*(short *)(iVar10 + -0x12)) +
            (longlong)((int)*(short *)(iVar10 + -0x14) * (int)*(short *)(iVar10 + -0x14)) +
            (longlong)((int)*(short *)(iVar10 + -0x16) * (int)*(short *)(iVar10 + -0x16)) +
            (longlong)((int)*(short *)(iVar10 + -0x18) * (int)*(short *)(iVar10 + -0x18)) +
            (longlong)((int)*(short *)(iVar10 + -0x1a) * (int)*(short *)(iVar10 + -0x1a)) +
            (longlong)((int)*(short *)(iVar10 + -0x1c) * (int)*(short *)(iVar10 + -0x1c)) +
            (longlong)((int)*(short *)(iVar10 + -0x1e) * (int)*(short *)(iVar10 + -0x1e)) +
            (int)*(short *)(iVar10 + -0x20) * (int)*(short *)(iVar10 + -0x20) + lVar6;
    iVar10 = iVar10 + 0x20;
  } while (iVar15 < iVar20);
  fVar36 = (float)VectorSignedToFloat((uint)(lVar6 + 0x20) >> 6 |
                                      (int)((ulonglong)(lVar6 + 0x20) >> 0x20) * 0x4000000,
                                      (byte)(in_fpscr >> 0x16) & 3);
  iVar10 = 0;
  lVar6 = 0;
  puVar18 = puVar18 + 0x10;
  do {
    iVar10 = iVar10 + 1;
    lVar6 = (longlong)((int)(short)puVar18[-1] * (int)(short)puVar18[-1]) +
            (longlong)((int)(short)puVar18[-2] * (int)(short)puVar18[-2]) +
            (longlong)((int)(short)puVar18[-3] * (int)(short)puVar18[-3]) +
            (longlong)((int)(short)puVar18[-4] * (int)(short)puVar18[-4]) +
            (longlong)((int)(short)puVar18[-5] * (int)(short)puVar18[-5]) +
            (longlong)((int)(short)puVar18[-6] * (int)(short)puVar18[-6]) +
            (longlong)((int)(short)puVar18[-7] * (int)(short)puVar18[-7]) +
            (longlong)((int)(short)puVar18[-8] * (int)(short)puVar18[-8]) +
            (longlong)((int)(short)puVar18[-9] * (int)(short)puVar18[-9]) +
            (longlong)((int)(short)puVar18[-10] * (int)(short)puVar18[-10]) +
            (longlong)((int)(short)puVar18[-0xb] * (int)(short)puVar18[-0xb]) +
            (longlong)((int)(short)puVar18[-0xc] * (int)(short)puVar18[-0xc]) +
            (longlong)((int)(short)puVar18[-0xd] * (int)(short)puVar18[-0xd]) +
            (longlong)((int)(short)puVar18[-0xe] * (int)(short)puVar18[-0xe]) +
            (longlong)((int)(short)puVar18[-0xf] * (int)(short)puVar18[-0xf]) +
            (int)(short)puVar18[-0x10] * (int)(short)puVar18[-0x10] + lVar6;
    puVar18 = puVar18 + 0x10;
  } while (iVar10 < iVar20);
  fVar29 = (float)VectorSignedToFloat((uint)(lVar6 + 0x20) >> 6 |
                                      (int)((ulonglong)(lVar6 + 0x20) >> 0x20) * 0x4000000,
                                      (byte)(in_fpscr >> 0x16) & 3);
  cVar14 = *param_3;
  fVar38 = fVar38 / SQRT(fVar29 * fVar36);
  if (cVar14 == '\0') {
    if (((local_88 == 1) || (0.94 < *(float *)(param_3 + 0xc))) && (0.94 < *(float *)(param_3 + 8)))
    {
      cVar14 = 0.94 < fVar38;
    }
  }
  else if (fVar38 <= 0.9) {
    if (0.84 < fVar38) {
      iVar10 = *(int *)(param_3 + 4);
      if (iVar10 < (int)uVar23) {
        iVar10 = uVar23 - iVar10;
      }
      else {
        iVar10 = iVar10 - uVar23;
      }
      if (iVar10 < 8) {
        cVar14 = -0.1 < fVar38 - *(float *)(param_3 + 8);
        goto LAB_0006def6;
      }
    }
    cVar14 = '\0';
  }
LAB_0006def6:
  *param_5 = cVar14;
  uVar13 = *(undefined4 *)(param_3 + 8);
  *param_3 = cVar14;
  *(float *)(param_3 + 8) = fVar38;
  *(uint *)(param_3 + 4) = uVar23;
  *(undefined4 *)(param_3 + 0xc) = uVar13;
  return bVar8;
}


