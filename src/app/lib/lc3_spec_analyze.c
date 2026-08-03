/*
 * Function: lc3_spec_analyze
 * Entry:    00072748
 * Prototype: void __stdcall lc3_spec_analyze(lc3_dt dt, lc3_srate sr, int nbytes, bool pitch, lc3_tns_data_t * tns, lc3_spec_analysis_t * spec, float * x, uint16_t * xq, lc3_spec_side_t * side)
 */


/* exclude_from_export_ai */

void lc3_spec_analyze(lc3_dt dt,lc3_srate sr,int nbytes,bool pitch,lc3_tns_data_t *tns,
                     lc3_spec_analysis_t *spec,float *x,uint16_t *xq,lc3_spec_side_t *side)

{
  lc3_dt lVar1;
  lc3_srate lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  float *pfVar15;
  bool bVar16;
  uint in_fpscr;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  float fVar23;
  int local_a0 [3];
  int aiStack_94 [2];
  int *local_8c;
  int local_88;
  lc3_dt local_84;
  int local_80;
  int local_7c;
  lc3_srate local_78;
  int local_74;
  int local_6c [16];
  
  iVar9 = sr * (dt + 3) + dt + 3;
  iVar13 = iVar9 * 5;
  iVar11 = (0x10 < iVar13) + 5;
  if (0x20 < iVar13) {
    iVar11 = (0x10 < iVar13) + 6;
  }
  if (0x40 < iVar13) {
    iVar11 = iVar11 + 1;
  }
  if (nbytes < 0x141) {
    iVar13 = (nbytes + -1) / 0xa0;
  }
  else {
    iVar13 = 2;
  }
  local_88 = nbytes;
  local_84 = dt;
  local_78 = sr;
  iVar3 = lc3_bwdet_get_nbits(sr);
  iVar4 = lc3_ltpf_get_nbits(pitch);
  iVar5 = lc3_sns_get_nbits();
  iVar6 = lc3_tns_get_nbits(tns);
  fVar21 = (float)VectorSignedToFloat(*(undefined4 *)spec[1].opaque,(byte)(in_fpscr >> 0x16) & 3);
  uVar22 = FPMaxNum(fVar21 + *(float *)spec->opaque,0xc2200000);
  fVar21 = (float)FPMinNum(uVar22,0x42200000);
  iVar12 = (sr + LC3_SRATE_16K) * 5;
  local_7c = (((((nbytes * 8 - (iVar11 + 3 + iVar13)) - iVar3) - iVar4) - iVar5) - iVar6) + -0xb;
  local_80 = (nbytes * 8) / (int)((sr + LC3_SRATE_16K) * 10);
  if (local_80 < 0x74) {
    local_80 = iVar12 + 0x69 + local_80;
  }
  else {
    local_80 = iVar12 + 0xdc;
  }
  iVar13 = iVar9 * 0x14 >> 2;
  fVar17 = 0.0;
  fVar21 = fVar21 * 0.2 + *(float *)spec->opaque * 0.8;
  local_8c = local_a0;
  iVar9 = -(iVar13 * 4 + 7U & 0xfffff8);
  pfVar8 = x + 4;
  iVar11 = iVar13 + -1;
  piVar14 = (int *)((int)aiStack_94 + iVar9 + 4);
  pfVar15 = pfVar8 + iVar13 * 4;
  piVar7 = (int *)((int)aiStack_94 + iVar9);
  do {
    fVar23 = pfVar8[-4] * pfVar8[-4];
    fVar18 = pfVar8[-3] * pfVar8[-3];
    fVar19 = pfVar8[-2] * pfVar8[-2];
    fVar20 = pfVar8[-1] * pfVar8[-1];
    uVar22 = FPMaxNum(fVar23,fVar18);
    uVar22 = FPMaxNum(uVar22,fVar19);
    uVar22 = FPMaxNum(uVar22,fVar20);
    fVar18 = (float)FPMaxNum(fVar23 + fVar18 + fVar19 + fVar20,0x2edbe6ff);
    fVar17 = (float)FPMaxNum(fVar17,uVar22);
    fVar18 = fVar18 * fVar18;
    uVar10 = ((uint)fVar18 & 0x7fffff) >> 0x12;
    pfVar8 = pfVar8 + 4;
    piVar7 = piVar7 + 1;
    *piVar7 = (((uint)fVar18 >> 0x16) - 0xfe) * 0xc0a9 +
              (uint)*(ushort *)(&DAT_00090ee0 + uVar10 * 4) +
              ((int)((uint)*(ushort *)(&LAB_00090ee2 + uVar10 * 4) * (((uint)fVar18 & 0x3ffff) >> 2)
                    ) >> 0x10);
  } while (pfVar15 != pfVar8);
  fVar18 = (float)VectorSignedToFloat(local_7c,(byte)(in_fpscr >> 0x16) & 3);
  iVar9 = 0xff - local_80;
  iVar12 = 8;
  iVar13 = 0x80;
LAB_00072914:
  iVar4 = iVar9 - iVar13;
  iVar3 = iVar11;
  if (iVar11 < 0) {
    iVar5 = 0;
  }
  else {
    piVar7 = piVar14 + iVar11 + 1;
    do {
      piVar7 = piVar7 + -1;
      if (iVar4 * 0xb6db - *piVar7 == 0 || iVar4 * 0xb6db < *piVar7) {
        iVar5 = 0;
        piVar7 = piVar14 + iVar3 + 1;
        local_74 = iVar4;
        goto LAB_0007296a;
      }
      bVar16 = iVar3 != 0;
      iVar3 = iVar3 + -1;
    } while (bVar16);
    iVar5 = 0;
  }
  goto LAB_0007297e;
  while (iVar5 = iVar5 + 0x2b333, piVar14 != piVar7) {
LAB_0007296a:
    piVar7 = piVar7 + -1;
    iVar6 = *piVar7 + iVar4 * -0xb6db;
    if (-1 < iVar6) {
      if (iVar6 < 0x2b0000) {
        iVar6 = iVar6 + 0x70000;
      }
      else {
        iVar6 = (iVar6 + -0x120000) * 2;
      }
      iVar5 = iVar5 + iVar6;
      if (piVar14 == piVar7) break;
      goto LAB_0007296a;
    }
  }
LAB_0007297e:
  if (iVar5 <= (int)(fVar18 + fVar21 + 0.5) * 0x16666) {
    iVar9 = iVar4;
    iVar3 = iVar11;
  }
  iVar11 = iVar3;
  iVar12 = iVar12 + -1;
  iVar13 = iVar13 >> 1;
  if (iVar12 == 0) goto code_r0x0007298e;
  goto LAB_00072914;
code_r0x0007298e:
  if (fVar17 == 0.0) {
    fVar21 = (float)VectorSignedToFloat(-local_80,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
    iVar13 = (int)fVar21;
LAB_000729ba:
    lVar2 = local_78;
    lVar1 = local_84;
    piVar14 = local_8c;
    iVar12 = 0;
    local_8c[1] = (int)(side + 1);
    *piVar14 = (int)xq;
    quantize(lVar1,lVar2,iVar13,x,(uint16_t *)*piVar14,(int *)piVar14[1]);
    piVar14[1] = 0;
    piVar14[2] = 0;
    *piVar14 = (int)(side + 1);
    iVar11 = compute_nbits(lVar1,lVar2,local_88,xq,(int *)*piVar14,piVar14[1],(bool *)piVar14[2]);
    fVar21 = 0.0;
    iVar9 = iVar13;
  }
  else {
    fVar17 = logf(SQRT(fVar17) * 3.0517927e-05);
    lVar2 = local_78;
    lVar1 = local_84;
    piVar14 = local_8c;
    fVar17 = (float)FPRoundInt(fVar17 * 28.0,0x20,1,0);
    iVar13 = (int)fVar17;
    if (iVar9 < iVar13) goto LAB_000729ba;
    local_8c[1] = (int)(side + 1);
    *piVar14 = (int)xq;
    quantize(lVar1,lVar2,iVar9,x,(uint16_t *)*piVar14,(int *)piVar14[1]);
    piVar14[1] = 0;
    piVar14[2] = 0;
    *piVar14 = (int)(side + 1);
    iVar11 = compute_nbits(lVar1,lVar2,local_88,xq,(int *)*piVar14,piVar14[1],(bool *)piVar14[2]);
    iVar12 = local_7c - iVar11;
  }
  *(int *)spec[1].opaque = iVar12;
  *(float *)spec->opaque = fVar21;
  iVar12 = local_80 + iVar9;
  local_6c[0] = 0x50;
  local_6c[1] = 500;
  local_6c[2] = 0x352;
  local_6c[3] = 0xe6;
  local_6c[4] = 0x401;
  local_6c[5] = 0x6a4;
  local_6c[6] = 0x17c;
  local_6c[7] = 0x60e;
  local_6c[8] = 0x9f6;
  local_6c[9] = 0x212;
  local_6c[10] = 0x81b;
  local_6c[0xb] = 0xd48;
  local_6c[0xc] = 0x2a8;
  local_6c[0xd] = 0xa28;
  local_6c[0xe] = 0x109a;
  iVar13 = local_6c[local_78 * 3];
  if (iVar11 < iVar13) {
    iVar3 = 0x18;
    iVar4 = 0x30;
    iVar13 = (iVar11 + 0x30) * 3;
  }
  else {
    iVar3 = local_6c[local_78 * 3 + 1];
    if (iVar11 < iVar3) {
      iVar4 = (iVar3 - iVar13) * 0x30;
      iVar13 = (iVar3 + (iVar13 + 0x30) * -3) * (iVar11 - iVar13) +
               (iVar3 - iVar13) * (iVar13 + 0x30) * 3;
      iVar3 = iVar4 >> 1;
    }
    else {
      iVar3 = 0x18;
      iVar13 = local_6c[local_78 * 3 + 2];
      if (iVar11 <= local_6c[local_78 * 3 + 2]) {
        iVar13 = iVar11;
      }
      iVar4 = 0x30;
    }
  }
  iVar4 = (iVar13 + iVar3) / iVar4;
  if (iVar11 < local_7c - (iVar4 + 2)) {
    uVar10 = -(uint)(0 < iVar12);
LAB_00072b94:
    if (uVar10 == 0) goto LAB_00072a5c;
  }
  else {
    if (iVar11 <= local_7c) goto LAB_00072a5c;
    uVar10 = (uint)(iVar12 < 0xff);
    if ((0xfd < iVar12) || (iVar11 < iVar4 + local_7c)) goto LAB_00072b94;
    uVar10 = uVar10 + 1;
  }
  piVar14[1] = (int)(side + 1);
  *piVar14 = (int)xq;
  quantize(local_84,local_78,uVar10,x,(uint16_t *)*piVar14,(int *)piVar14[1]);
  iVar12 = local_80 + uVar10 + iVar9;
LAB_00072a5c:
  *(int *)side->opaque = iVar12;
  piVar14[2] = (int)(side + 2);
  *piVar14 = (int)(side + 1);
  piVar14[1] = local_7c;
  compute_nbits(local_84,local_78,local_88,xq,(int *)*piVar14,piVar14[1],(bool *)piVar14[2]);
  return;
}


