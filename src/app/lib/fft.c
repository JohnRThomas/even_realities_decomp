/*
 * Function: fft
 * Entry:    0006e670
 * Prototype: lc3_complex * __stdcall fft(lc3_complex * x, int n, lc3_complex * y0, lc3_complex * y1)
 */


/* exclude_from_export */

lc3_complex * fft(lc3_complex *x,int n,lc3_complex *y0,lc3_complex *y1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  lc3_complex **pplVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  lc3_complex *plVar14;
  lc3_complex *plVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  uint uVar21;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  float *pfVar25;
  float *pfVar26;
  uint uVar27;
  int *piVar28;
  float *pfVar29;
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
  float *local_a0;
  float *local_9c;
  float *local_98;
  float *local_94;
  uint local_90;
  int local_8c;
  int local_7c;
  uint local_78;
  lc3_complex *local_60 [3];
  
  local_60[0] = y1;
  local_60[1] = y0;
  local_90 = (uint)n / 5;
  pfVar6 = (float *)(x + local_90 * 2);
  pfVar20 = pfVar6 + local_90 * 6;
  pfVar23 = pfVar20 + local_90 * -4;
  pfVar25 = pfVar23 + local_90 * 2;
  plVar14 = x + 2;
  pfVar7 = (float *)y1;
  do {
    fVar33 = *pfVar6 + *pfVar20;
    fVar39 = *pfVar23 + *pfVar25;
    fVar35 = *pfVar23 - *pfVar25;
    fVar32 = pfVar6[1] + pfVar20[1];
    fVar36 = pfVar6[1] - pfVar20[1];
    fVar38 = pfVar23[1] + pfVar25[1];
    fVar37 = *pfVar6 - *pfVar20;
    fVar34 = pfVar23[1] - pfVar25[1];
    fVar30 = fVar36 * 0.95105654;
    fVar36 = fVar36 * 0.58778524;
    fVar31 = fVar37 * -0.95105654;
    fVar37 = fVar37 * -0.58778524;
    *pfVar7 = (float)plVar14[-2] + fVar33 + fVar39;
    plVar15 = plVar14 + 2;
    pfVar7[1] = (float)plVar14[-1] + fVar32 + fVar38;
    pfVar7[2] = (float)plVar14[-2] + fVar30 + fVar33 * 0.309017 + fVar39 * -0.809017 +
                fVar34 * 0.58778524;
    pfVar7[3] = (float)plVar14[-1] + fVar31 + fVar32 * 0.309017 + fVar38 * -0.809017 +
                fVar35 * -0.58778524;
    pfVar7[4] = (float)plVar14[-2] + fVar36 + fVar33 * -0.809017 + fVar39 * 0.309017 +
                fVar34 * -0.95105654;
    pfVar7[5] = (float)plVar14[-1] + fVar37 + fVar32 * -0.809017 + fVar38 * 0.309017 +
                fVar35 * 0.95105654;
    pfVar7[6] = ((fVar39 * 0.309017 + fVar33 * -0.809017 + (float)plVar14[-2]) - fVar36) +
                -fVar34 * -0.95105654;
    pfVar7[7] = ((fVar38 * 0.309017 + fVar32 * -0.809017 + (float)plVar14[-1]) - fVar37) +
                -fVar35 * 0.95105654;
    pfVar7[8] = (((float)plVar14[-2] + fVar39 * -0.809017 + fVar33 * 0.309017) - fVar30) +
                -fVar34 * 0.58778524;
    pfVar6 = pfVar6 + 2;
    pfVar20 = pfVar20 + 2;
    pfVar23 = pfVar23 + 2;
    pfVar25 = pfVar25 + 2;
    pfVar7[9] = (((float)plVar14[-1] + fVar38 * -0.809017 + fVar32 * 0.309017) - fVar31) +
                -fVar35 * -0.58778524;
    plVar14 = plVar15;
    pfVar7 = pfVar7 + 10;
  } while (x + 2 + local_90 * 2 != plVar15);
  if ((local_90 - 1 & local_90) == 0) {
    local_7c = 0;
    local_78 = 0;
  }
  else {
    local_7c = 0;
    uVar27 = local_90;
    pfVar7 = (float *)y0;
    y0 = y1;
    uVar21 = 0;
    piVar28 = &DAT_20002d14;
    while( true ) {
      y1 = (lc3_complex *)pfVar7;
      local_90 = (int)uVar27 / 3;
      local_78 = uVar21 ^ 1;
      iVar16 = *(int *)*piVar28;
      pfVar7 = (float *)((int *)*piVar28)[1];
      local_a0 = (float *)(y0 + iVar16 * local_90 * 2);
      pfVar6 = pfVar7 + iVar16 * 4;
      local_9c = (float *)(y0 + iVar16 * local_90 * 4);
      pfVar20 = (float *)(y1 + iVar16 * 2);
      pfVar23 = (float *)(y1 + iVar16 * 4);
      if ((2 < (int)uVar27) && (0 < iVar16)) {
        pfVar25 = (float *)(y0 + 2);
        local_8c = 0;
        local_98 = (float *)y1;
        local_94 = (float *)y0;
        do {
          pfVar25 = pfVar25 + iVar16 * 2;
          pfVar22 = local_94 + 2;
          pfVar8 = pfVar6;
          pfVar10 = pfVar6 + iVar16 * 4;
          pfVar19 = pfVar7;
          pfVar24 = pfVar23;
          pfVar26 = pfVar20;
          pfVar29 = local_98;
          pfVar13 = local_a0;
          pfVar17 = local_9c;
          do {
            *pfVar29 = *pfVar17 * pfVar19[2] + *pfVar13 * *pfVar19 + pfVar22[-2] +
                       -pfVar13[1] * pfVar19[1] + -pfVar17[1] * pfVar19[3];
            pfVar29[1] = pfVar22[-1] + *pfVar13 * pfVar19[1] + pfVar13[1] * *pfVar19 +
                         pfVar17[1] * pfVar19[2] + *pfVar17 * pfVar19[3];
            *pfVar26 = pfVar22[-2] + *pfVar17 * pfVar8[2] + *pfVar13 * *pfVar8 +
                       -pfVar13[1] * pfVar8[1] + -pfVar17[1] * pfVar8[3];
            pfVar26[1] = pfVar22[-1] + *pfVar13 * pfVar8[1] + pfVar13[1] * *pfVar8 +
                         pfVar17[1] * pfVar8[2] + *pfVar17 * pfVar8[3];
            *pfVar24 = pfVar22[-2] + *pfVar17 * pfVar10[2] + *pfVar13 * *pfVar10 +
                       -pfVar13[1] * pfVar10[1] + -pfVar17[1] * pfVar10[3];
            pfVar2 = pfVar10 + 1;
            fVar30 = *pfVar10;
            pfVar1 = pfVar22 + -1;
            pfVar3 = pfVar10 + 2;
            pfVar4 = pfVar10 + 3;
            pfVar22 = pfVar22 + 2;
            pfVar8 = pfVar8 + 4;
            pfVar10 = pfVar10 + 4;
            pfVar19 = pfVar19 + 4;
            pfVar29 = pfVar29 + 2;
            pfVar26 = pfVar26 + 2;
            pfVar24[1] = *pfVar1 + *pfVar13 * *pfVar2 + pfVar13[1] * fVar30 + pfVar17[1] * *pfVar3 +
                         *pfVar17 * *pfVar4;
            pfVar24 = pfVar24 + 2;
            pfVar13 = pfVar13 + 2;
            pfVar17 = pfVar17 + 2;
          } while (pfVar25 != pfVar22);
          local_94 = local_94 + iVar16 * 2;
          local_8c = local_8c + 1;
          local_a0 = local_a0 + iVar16 * 2;
          local_9c = local_9c + iVar16 * 2;
          pfVar20 = pfVar20 + iVar16 * 6;
          local_98 = local_98 + iVar16 * 6;
          pfVar23 = pfVar23 + iVar16 * 6;
        } while (local_8c < (int)local_90);
      }
      local_7c = local_7c + 1;
      if ((local_90 - 1 & local_90) == 0) break;
      uVar27 = local_90;
      pfVar7 = (float *)local_60[uVar21];
      y0 = y1;
      uVar21 = local_78;
      piVar28 = piVar28 + 1;
    }
    if ((int)uVar27 < 6) {
      return (lc3_complex *)(float *)y1;
    }
  }
  iVar16 = 0;
  while( true ) {
    pfVar7 = (float *)y0;
    local_90 = (int)local_90 >> 1;
    iVar12 = **(int **)(&DAT_20002cd8 + iVar16 * 4 + local_7c * 4);
    iVar18 = (*(int **)(&DAT_20002cd8 + iVar16 * 4 + local_7c * 4))[1];
    pfVar20 = pfVar7 + iVar12 * 2;
    pfVar6 = (float *)(y1 + iVar12 * local_90 * 2);
    if (0 < iVar12) {
      uVar27 = 0;
      pfVar13 = (float *)(y1 + 2);
      pfVar25 = pfVar7;
      pfVar23 = pfVar13;
      while( true ) {
        pfVar23 = pfVar23 + iVar12 * 2;
        iVar9 = iVar18;
        iVar11 = iVar18 + 4;
        pfVar10 = pfVar20;
        pfVar19 = pfVar25;
        pfVar8 = pfVar6;
        do {
          *pfVar19 = pfVar13[-2] + *pfVar8 * *(float *)(iVar11 + -4) +
                     -pfVar8[1] * *(float *)(iVar9 + 4);
          pfVar19[1] = pfVar13[-1] +
                       *pfVar8 * *(float *)(iVar9 + 4) + pfVar8[1] * *(float *)(iVar11 + -4);
          *pfVar10 = pfVar13[-2] + pfVar8[1] * *(float *)(iVar9 + 4) +
                     -*pfVar8 * *(float *)(iVar11 + -4);
          pfVar29 = (float *)(iVar9 + 4);
          pfVar24 = (float *)(iVar11 + -4);
          pfVar26 = pfVar13 + -1;
          pfVar13 = pfVar13 + 2;
          iVar9 = iVar9 + 8;
          iVar11 = iVar11 + 8;
          pfVar19 = pfVar19 + 2;
          pfVar10[1] = *pfVar26 - (*pfVar8 * *pfVar29 + pfVar8[1] * *pfVar24);
          pfVar10 = pfVar10 + 2;
          pfVar8 = pfVar8 + 2;
        } while (pfVar23 != pfVar13);
        uVar27 = uVar27 + 1;
        y1 = y1 + iVar12 * 2;
        pfVar6 = pfVar6 + iVar12 * 2;
        pfVar25 = pfVar25 + iVar12 * 4;
        pfVar20 = pfVar20 + iVar12 * 4;
        if (local_90 == uVar27) break;
        pfVar13 = (float *)(y1 + 2);
      }
    }
    iVar16 = iVar16 + 3;
    if (local_90 == 1) break;
    pplVar5 = local_60 + local_78;
    local_78 = local_78 ^ 1;
    y0 = *pplVar5;
    y1 = (lc3_complex *)pfVar7;
  }
  return (lc3_complex *)pfVar7;
}


