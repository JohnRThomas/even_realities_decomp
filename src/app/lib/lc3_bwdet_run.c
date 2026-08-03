/*
 * Function: lc3_bwdet_run
 * Entry:    0006bcb8
 * Prototype: lc3_bandwidth __stdcall lc3_bwdet_run(lc3_dt dt, lc3_srate sr, float * e)
 */


/* exclude_from_export_ai */

lc3_bandwidth lc3_bwdet_run(lc3_dt dt,lc3_srate sr,float *e)

{
  byte bVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  lc3_srate lVar7;
  undefined *puVar8;
  lc3_srate lVar9;
  float *pfVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  float afStack_30 [5];
  
  if (sr != LC3_SRATE_8K) {
    lVar9 = LC3_SRATE_8K;
    lVar7 = LC3_SRATE_8K;
    iVar4 = (sr - LC3_SRATE_16K) + dt * 4;
    do {
      iVar5 = (int)*(char *)(&PTR_DAT_0008f770 + iVar4 * 4 + lVar9);
      iVar2 = (int)*(char *)((int)&PTR_DAT_0008f770 + lVar9 * 4 + iVar4 * 0x10 + 1);
      fVar12 = e[iVar5];
      if (iVar5 + 1 < iVar2) {
        pfVar3 = e + iVar5 + 1;
        do {
          fVar11 = *pfVar3;
          pfVar3 = pfVar3 + 1;
          fVar12 = fVar12 + fVar11;
        } while (e + iVar2 != pfVar3);
      }
      if (lVar9 == LC3_SRATE_8K) {
        iVar6 = 0x14;
      }
      else {
        iVar6 = 10;
      }
      fVar11 = (float)VectorSignedToFloat((iVar2 - iVar5) * iVar6,(byte)(in_fpscr >> 0x16) & 3);
      in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar11 == fVar12) << 0x1e |
                 (uint)(fVar12 <= fVar11) << 0x1d;
      bVar1 = (byte)(in_fpscr >> 0x18);
      lVar9 = lVar9 + LC3_SRATE_16K & 0xff;
      if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
        lVar7 = lVar9;
      }
    } while (lVar9 < sr);
    if (sr <= lVar7) {
      return lVar7;
    }
    iVar2 = (int)*(char *)(&PTR_DAT_0008f770 + iVar4 * 4 + lVar7);
    puVar8 = (&PTR_Reset_0008f750)[dt * 4 + lVar7];
    afStack_30[3] = 100.0;
    afStack_30[2] = 100.0;
    afStack_30[1] = 199.52623;
    afStack_30[0] = 31.622776;
    iVar4 = iVar2 - (int)puVar8;
    if (-1 < (int)puVar8) {
      pfVar3 = e + ((iVar4 + 1) - (int)puVar8);
      pfVar10 = e + iVar4 + 1;
      do {
        fVar11 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        fVar12 = *pfVar3;
        pfVar3 = pfVar3 + 1;
        iVar4 = iVar4 + 1;
        if (fVar11 * afStack_30[lVar7] < fVar12) {
          return lVar7;
        }
      } while (iVar4 <= iVar2);
    }
  }
  return sr;
}


