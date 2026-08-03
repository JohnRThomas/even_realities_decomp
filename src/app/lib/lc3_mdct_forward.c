/*
 * Function: lc3_mdct_forward
 * Entry:    0006ec60
 * Prototype: void __stdcall lc3_mdct_forward(lc3_dt dt, lc3_srate sr, lc3_srate sr_dst, float * x, float * d, float * y)
 */


/* exclude_from_export_ai */

void lc3_mdct_forward(lc3_dt dt,lc3_srate sr,lc3_srate sr_dst,float *x,float *d,float *y)

{
  float *pfVar1;
  float *pfVar2;
  lc3_complex *plVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float **ppfVar8;
  float **ppfVar9;
  float *pfVar10;
  int iVar11;
  float **ppfVar12;
  float **ppfVar13;
  float *pfVar14;
  uint in_fpscr;
  float *pfVar15;
  float *pfVar16;
  float fVar17;
  float *pfVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float *local_58;
  int local_54;
  float *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int *local_40;
  float *local_3c;
  float **local_38;
  float *local_34;
  
  iVar11 = sr_dst + LC3_SRATE_16K;
  if (sr_dst == LC3_SRATE_48K) {
    iVar11 = 6;
  }
  iVar5 = sr + LC3_SRATE_16K;
  if (sr == LC3_SRATE_48K) {
    iVar5 = 6;
  }
  iVar5 = (dt + 3) * iVar5;
  local_38 = &local_58 + iVar5 * -0x14;
  local_40 = *(int **)(&DAT_20002cb0 + (dt * 5 + sr) * 4);
  local_48 = iVar5 * 0x14;
  local_44 = iVar5 * 10;
  if (dt == 0) {
    uVar6 = (uint)(iVar5 * 0x1cc) / 0x1e;
  }
  else {
    uVar6 = iVar5 * 100 >> 3;
  }
  local_34 = *(float **)(&DAT_20002c88 + (dt * 5 + sr) * 4);
  pfVar1 = x + (local_48 - uVar6);
  local_54 = (local_48 - uVar6) * 4;
  pfVar4 = local_34 + iVar5 * 0x14;
  local_4c = iVar5 * 0x50;
  local_50 = pfVar4 + uVar6;
  local_58 = d + uVar6;
  ppfVar8 = local_38 + iVar5 * 10;
  pfVar10 = pfVar1;
  pfVar16 = pfVar1;
  ppfVar12 = ppfVar8;
  pfVar18 = pfVar4;
  ppfVar13 = ppfVar8;
  pfVar14 = pfVar4;
  pfVar2 = d;
  pfVar15 = local_34;
  if (x < pfVar1) {
    do {
      fVar20 = *pfVar10;
      fVar19 = pfVar2[1];
      ppfVar12[-1] = (float *)(-(pfVar18[-1] * pfVar16[-1]) + *pfVar2 * *pfVar15);
      *pfVar2 = fVar20;
      *ppfVar13 = (float *)(*pfVar14 * fVar20);
      fVar20 = pfVar16[-2];
      fVar24 = pfVar18[-2];
      fVar21 = pfVar15[1];
      fVar22 = pfVar10[1];
      pfVar2[1] = fVar22;
      ppfVar12[-2] = (float *)(-(fVar24 * fVar20) + fVar19 * fVar21);
      pfVar16 = pfVar16 + -2;
      ppfVar13[1] = (float *)(pfVar14[1] * fVar22);
      ppfVar12 = ppfVar12 + -2;
      pfVar18 = pfVar18 + -2;
      pfVar2 = pfVar2 + 2;
      pfVar14 = pfVar14 + 2;
      pfVar10 = pfVar10 + 2;
      pfVar15 = pfVar15 + 2;
      ppfVar13 = ppfVar13 + 2;
    } while (x < pfVar16);
    iVar7 = (local_54 - 1U & 0xfffffff8) + 8;
    d = (float *)((int)d + iVar7);
    pfVar10 = (float *)((int)pfVar1 - iVar7);
    local_34 = (float *)((int)local_34 + iVar7);
    pfVar14 = (float *)((int)pfVar4 - iVar7);
    pfVar1 = (float *)((int)pfVar1 + iVar7);
    pfVar4 = (float *)((int)pfVar4 + iVar7);
    ppfVar13 = (float **)((int)ppfVar8 + iVar7);
    ppfVar8 = (float **)((int)ppfVar8 - iVar7);
  }
  pfVar10 = pfVar10 + iVar5 * 0x14;
  pfVar15 = local_58;
  pfVar16 = local_50;
  pfVar2 = local_34;
  if (pfVar1 < pfVar10) {
    do {
      fVar22 = pfVar14[-1];
      fVar24 = pfVar15[-1];
      fVar21 = *pfVar2;
      fVar20 = *d;
      fVar19 = *pfVar1;
      *d = fVar19;
      fVar25 = pfVar10[-1];
      ppfVar8[-1] = (float *)(-(fVar22 * fVar24) + fVar20 * fVar21);
      fVar20 = *pfVar4;
      pfVar15[-1] = fVar25;
      *ppfVar13 = (float *)(fVar25 * pfVar16[-1] + fVar19 * fVar20);
      fVar20 = pfVar15[-2];
      fVar24 = pfVar14[-2];
      fVar21 = pfVar2[1];
      fVar22 = pfVar1[1];
      fVar19 = d[1];
      d[1] = fVar22;
      fVar25 = pfVar10[-2];
      ppfVar8[-2] = (float *)(-(fVar24 * fVar20) + fVar19 * fVar21);
      fVar20 = pfVar4[1];
      pfVar15[-2] = fVar25;
      pfVar1 = pfVar1 + 2;
      pfVar10 = pfVar10 + -2;
      pfVar14 = pfVar14 + -2;
      ppfVar8 = ppfVar8 + -2;
      ppfVar13[1] = (float *)(fVar25 * pfVar16[-2] + fVar22 * fVar20);
      pfVar15 = pfVar15 + -2;
      pfVar16 = pfVar16 + -2;
      pfVar4 = pfVar4 + 2;
      d = d + 2;
      pfVar2 = pfVar2 + 2;
      ppfVar13 = ppfVar13 + 2;
    } while (pfVar1 < pfVar10);
  }
  pfVar2 = (float *)local_40[1];
  pfVar14 = pfVar2 + *local_40 * 2;
  ppfVar13 = local_38;
  ppfVar8 = local_38 + *local_40 * 2;
  if (local_38 < local_38 + *local_40 * 2) {
    do {
      pfVar18 = ppfVar8[-2];
      fVar22 = pfVar14[-2];
      pfVar16 = *ppfVar13;
      pfVar15 = ppfVar8[-1];
      pfVar10 = ppfVar13[1];
      fVar19 = pfVar14[-1];
      fVar21 = pfVar2[1];
      fVar20 = *pfVar2;
      ppfVar9 = ppfVar8 + -2;
      ppfVar12 = ppfVar13 + 2;
      *ppfVar13 = (float *)(fVar21 * (float)pfVar16 + -fVar20 * (float)pfVar15);
      pfVar2 = pfVar2 + 2;
      ppfVar13[1] = (float *)(fVar21 * (float)pfVar15 + fVar20 * (float)pfVar16);
      pfVar14 = pfVar14 + -2;
      *ppfVar9 = (float *)(fVar22 * (float)pfVar10 + -fVar19 * (float)pfVar18);
      ppfVar8[-1] = (float *)-(fVar22 * (float)pfVar18 + fVar19 * (float)pfVar10);
      ppfVar13 = ppfVar12;
      ppfVar8 = ppfVar9;
    } while (ppfVar12 < ppfVar9);
  }
  local_3c = x;
  plVar3 = fft((lc3_complex *)local_38,local_44,(lc3_complex *)local_38,(lc3_complex *)y);
  fVar19 = (float)VectorSignedToFloat((dt + 3) * iVar11 * 0x14,(byte)(in_fpscr >> 0x16) & 3);
  fVar20 = (float)VectorSignedToFloat(local_48 * local_48,(byte)(in_fpscr >> 0x16) & 3);
  fVar20 = SQRT((fVar19 + fVar19) / fVar20);
  iVar11 = *local_40 >> 1;
  pfVar14 = y + *local_40;
  pfVar2 = (float *)(local_40[1] + iVar11 * 8);
  if (y < pfVar14) {
    pfVar16 = (float *)(plVar3 + iVar11 * 2 + -4);
    pfVar18 = pfVar2 + -4;
    pfVar10 = (float *)(plVar3 + iVar11 * 2);
    pfVar15 = pfVar14;
    do {
      fVar19 = pfVar10[1];
      fVar22 = *pfVar10;
      fVar23 = *pfVar2;
      fVar17 = pfVar16[3];
      fVar26 = pfVar18[2];
      fVar24 = pfVar16[2];
      fVar21 = pfVar2[1];
      fVar25 = pfVar18[3];
      pfVar4 = pfVar14 + -2;
      *pfVar15 = fVar20 * (fVar22 * fVar23 + fVar19 * fVar21);
      pfVar15[1] = fVar20 * (-(fVar26 * fVar17) + fVar24 * fVar25);
      pfVar14[-1] = fVar20 * (-(fVar23 * fVar19) + fVar21 * fVar22);
      *pfVar4 = fVar20 * (fVar24 * fVar26 + fVar25 * fVar17);
      pfVar16 = pfVar16 + -2;
      pfVar18 = pfVar18 + -2;
      pfVar14 = pfVar4;
      pfVar2 = pfVar2 + 2;
      pfVar10 = pfVar10 + 2;
      pfVar15 = pfVar15 + 2;
    } while (y < pfVar4);
  }
  return;
}


