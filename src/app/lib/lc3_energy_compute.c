/*
 * Function: lc3_energy_compute
 * Entry:    0006be10
 * Prototype: bool __stdcall lc3_energy_compute(lc3_dt dt, lc3_srate sr, float * x, float * e)
 */


/* exclude_from_export_ai */

bool lc3_energy_compute(lc3_dt dt,lc3_srate sr,float *x,float *e)

{
  undefined1 uVar1;
  float *pfVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  float *pfVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  undefined *puVar10;
  int *piVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  float fVar14;
  float local_28 [2];
  
  fVar14 = 0.0;
  puVar4 = (&PTR_PendSV_0008f7f0)[dt * 5 + sr];
  local_28[0] = 0.0;
  local_28[1] = 0.0;
  if ((int)puVar4 < 1) {
    puVar4 = (undefined *)0x0;
    puVar8 = puVar4;
  }
  else {
    pfVar6 = e + (int)puVar4;
    pfVar2 = x;
    do {
      fVar12 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      fVar12 = fVar12 * fVar12;
      *e = fVar12;
      e = e + 1;
      fVar14 = fVar14 + fVar12;
    } while (e != pfVar6);
    local_28[0] = fVar14;
    puVar8 = (undefined *)((int)puVar4 << 2);
    e = pfVar6;
  }
  iVar5 = sr + LC3_SRATE_16K;
  if (sr == LC3_SRATE_48K) {
    iVar5 = 6;
  }
  puVar7 = (undefined *)((dt + 3) * iVar5 * 0x14);
  if (0x3f < (int)puVar7) {
    puVar7 = (undefined *)0x40;
  }
  iVar5 = dt * 0x514 + sr * 0x104;
  pfVar2 = e;
  puVar10 = puVar4;
  if ((int)puVar4 < (int)puVar7) {
    piVar11 = (int *)(&DAT_000947e0 + (int)puVar4 * 4 + iVar5);
    pfVar2 = e + ((int)puVar7 - (int)puVar4);
    iVar5 = *(int *)(&DAT_000947e0 + (int)(puVar8 + iVar5));
    do {
      piVar11 = piVar11 + 1;
      iVar9 = *piVar11;
      fVar14 = x[iVar5] * x[iVar5];
      iVar3 = iVar5 + 1;
      if (iVar5 + 1 < iVar9) {
        pfVar6 = x + iVar5 + 1;
        do {
          fVar12 = *pfVar6;
          pfVar6 = pfVar6 + 1;
          fVar14 = fVar14 + fVar12 * fVar12;
          iVar3 = iVar9;
        } while (pfVar6 != x + iVar9);
      }
      fVar12 = (float)VectorSignedToFloat(iVar9 - iVar5,(byte)(in_fpscr >> 0x16) & 3);
      fVar13 = local_28[(int)(puVar7 + (2 - dt) * -2) <= (int)puVar4];
      *e = fVar14 / fVar12;
      e = e + 1;
      local_28[(int)(puVar7 + (2 - dt) * -2) <= (int)puVar4] = fVar13 + fVar14 / fVar12;
      puVar4 = puVar4 + 1;
      iVar5 = iVar3;
      puVar10 = puVar7;
    } while (e != pfVar2);
  }
  fVar12 = local_28[1];
  fVar14 = local_28[0];
  if ((int)puVar10 < 0x40) {
    pfVar2 = memset(pfVar2,0,(0x40 - (int)puVar10) * 4);
  }
  uVar1 = SUB41(pfVar2,0);
  iVar5 = (uint)(fVar14 * 30.0 < fVar12) << 0x1f;
  if (iVar5 < 0) {
    uVar1 = 1;
  }
  if (-1 < iVar5) {
    uVar1 = 0;
  }
  return (bool)uVar1;
}


