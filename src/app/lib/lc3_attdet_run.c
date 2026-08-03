/*
 * Function: lc3_attdet_run
 * Entry:    0006b598
 * Prototype: bool __stdcall lc3_attdet_run(lc3_dt dt, lc3_srate sr, int nbytes, lc3_attdet_analysis_t * attdet, int16_t * x)
 */


/* exclude_from_export_ai */

bool lc3_attdet_run(lc3_dt dt,lc3_srate sr,int nbytes,lc3_attdet_analysis_t *attdet,int16_t *x)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int16_t *piVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int local_58 [4];
  int local_48 [9];
  
  local_48[0] = 0x3d;
  local_48[1] = 0x95;
  local_48[2] = 0x4b;
  local_48[3] = 0x95;
  local_48[4] = 0x51;
  local_48[5] = 0x7fffffff;
  local_48[6] = 100;
  local_48[7] = 0x7fffffff;
  if (((LC3_SRATE_24K < sr) &&
      (iVar8 = (sr - LC3_SRATE_32K) + dt * 2, local_48[iVar8 * 2] <= nbytes)) &&
     (nbytes <= local_48[iVar8 * 2 + 1])) {
    if (dt == 0) {
      iVar8 = 3;
    }
    else {
      iVar8 = 4;
    }
    iVar9 = (int)x[-2];
    iVar14 = (int)x[-1];
    piVar12 = local_58;
    do {
      sVar1 = x[-4];
      sVar2 = x[-3];
      piVar13 = piVar12 + 1;
      *piVar12 = 0;
      if (sr == LC3_SRATE_32K) {
        iVar11 = 0;
        piVar10 = x + 2;
        iVar5 = iVar9 + iVar14 >> 1;
        iVar6 = (int)sVar2 + (int)sVar1 >> 1;
        do {
          iVar4 = iVar5;
          iVar9 = (int)piVar10[-2];
          iVar14 = (int)piVar10[-1];
          piVar10 = piVar10 + 2;
          iVar5 = iVar9 + iVar14 >> 1;
          iVar6 = (int)((iVar9 + iVar14 & 0xfffffffeU) + iVar5 + iVar4 * -4 + iVar6) >> 3;
          iVar11 = iVar11 + (iVar6 * iVar6 >> 5);
          iVar6 = iVar4;
        } while (x + 0x52 != piVar10);
        x = x + 0x50;
      }
      else {
        iVar11 = 0;
        piVar10 = x + 3;
        iVar5 = (int)x[-6] + (int)x[-5] + (int)sVar1 >> 2;
        iVar6 = sVar2 + iVar9 + iVar14 >> 2;
        do {
          iVar9 = (int)piVar10[-2];
          iVar14 = (int)piVar10[-1];
          iVar4 = piVar10[-3] + iVar9 + iVar14 >> 2;
          iVar5 = iVar4 * 3 + iVar6 * -4 + iVar5 >> 3;
          piVar10 = piVar10 + 3;
          iVar11 = iVar11 + (iVar5 * iVar5 >> 5);
          iVar5 = iVar6;
          iVar6 = iVar4;
        } while (x + 0x7b != piVar10);
        x = x + 0x78;
      }
      *piVar12 = iVar11;
      piVar12 = piVar13;
    } while (piVar13 != local_58 + iVar8);
    iVar9 = *(int *)attdet[1].opaque >> 2;
    if (iVar9 < *(int *)attdet->opaque) {
      iVar9 = *(int *)attdet->opaque;
    }
    uVar7 = (uint)(iVar9 + (iVar9 >> 4) < local_58[0] >> 3);
    iVar14 = iVar9 >> 2;
    if (iVar9 >> 2 < local_58[0]) {
      iVar14 = local_58[0];
    }
    if (iVar14 + (iVar14 >> 4) < local_58[1] >> 3) {
      uVar7 = 2;
    }
    iVar9 = iVar14 >> 2;
    if (iVar14 >> 2 < local_58[1]) {
      iVar9 = local_58[1];
    }
    if (iVar9 + (iVar9 >> 4) < local_58[2] >> 3) {
      uVar7 = 3;
    }
    if (iVar8 == 4) {
      iVar9 = iVar9 >> 2;
      if (iVar9 < local_58[2]) {
        iVar9 = local_58[2];
      }
      local_58[2] = local_58[3];
      if (iVar9 + (iVar9 >> 4) < local_58[3] >> 3) {
        uVar7 = 4;
      }
    }
    if (iVar8 == 3) {
      iVar8 = 1;
    }
    else {
      iVar8 = 2;
    }
    *(int *)attdet->opaque = local_58[2];
    *(int *)attdet[1].opaque = iVar9;
    if (iVar8 < *(int *)attdet[2].opaque) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (uVar7 != 0) {
        bVar3 = true;
      }
    }
    *(uint *)attdet[2].opaque = uVar7;
    return bVar3;
  }
  return false;
}


