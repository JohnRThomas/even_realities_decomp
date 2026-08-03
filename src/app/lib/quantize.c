/*
 * Function: quantize
 * Entry:    0007240c
 * Prototype: void __stdcall quantize(lc3_dt dt, lc3_srate sr, int g_int, float * x, uint16_t * xq, int * nq)
 */


/* exclude_from_export */

void quantize(lc3_dt dt,lc3_srate sr,int g_int,float *x,uint16_t *xq,int *nq)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  undefined *puVar8;
  float fVar9;
  float fVar10;
  
  uVar4 = (g_int ^ g_int >> 0x1f) - (g_int >> 0x1f);
  iVar5 = (int)uVar4 >> 6;
  puVar8 = (&PTR_DAT_00090ddc)[uVar4 & 0x3f];
  if (iVar5 != 0) {
    iVar5 = iVar5 + -1;
    do {
      iVar5 = iVar5 + -1;
      puVar8 = (undefined *)((float)puVar8 * 193.06978);
    } while (iVar5 != -1);
  }
  if (-1 < g_int) {
    puVar8 = (undefined *)(1.0 / (float)puVar8);
  }
  iVar7 = 0;
  iVar5 = (sr * (dt + 3) + dt + 3) * 0x14;
  *nq = iVar5;
  pfVar6 = x + 1;
  do {
    while( true ) {
      pfVar6[-1] = pfVar6[-1] * (float)puVar8;
      fVar10 = x[1];
      x[1] = (float)puVar8 * fVar10;
      fVar9 = (float)FPMinNum(ABS(pfVar6[-1]) + 0.375,0x46fffe00);
      iVar1 = (uint)(pfVar6[-1] < 0.0) << 0x1f;
      if (iVar1 < 0) {
        dt = 1;
      }
      if (-1 < iVar1) {
        dt = 0;
      }
      fVar10 = (float)FPMinNum(ABS((float)puVar8 * fVar10) + 0.375,0x46fffe00);
      uVar4 = (uint)(0.0 < fVar9) * (int)fVar9 & 0xffff;
      if (uVar4 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = dt & 1;
      }
      uVar2 = uVar2 + uVar4 * 2;
      xq[iVar7] = (uint16_t)uVar2;
      iVar1 = (uint)(x[1] < 0.0) << 0x1f;
      if (iVar1 < 0) {
        uVar2 = 1;
      }
      if (-1 < iVar1) {
        uVar2 = 0;
      }
      uVar3 = (uint)(0.0 < fVar10) * (int)fVar10 & 0xffff;
      if (uVar3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 1;
      }
      dt = uVar2 + uVar3 * 2;
      xq[iVar7 + 1] = (uint16_t)dt;
      if (uVar4 != 0 || uVar3 != 0) break;
      iVar7 = iVar7 + 2;
      *nq = *nq + -2;
      x = x + 2;
      pfVar6 = pfVar6 + 2;
      if (iVar5 <= iVar7) {
        return;
      }
    }
    iVar7 = iVar7 + 2;
    *nq = iVar5;
    x = x + 2;
    pfVar6 = pfVar6 + 2;
  } while (iVar5 - iVar7 != 0 && iVar7 <= iVar5);
  return;
}


