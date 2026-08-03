/*
 * Function: quorem
 * Entry:    0008a934
 * Prototype: uint __stdcall quorem(void * param_1, void * param_2)
 */


/* exclude_from_export_ai */

uint quorem(void *param_1,void *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar14;
  uint *puVar13;
  
  if (*(int *)((int)param_1 + 0x10) < *(int *)((int)param_2 + 0x10)) {
    uVar7 = 0;
  }
  else {
    iVar5 = *(int *)((int)param_2 + 0x10) + -1;
    puVar6 = (uint *)((int)param_1 + 0x14);
    puVar8 = (uint *)((int)param_2 + 0x14);
    puVar9 = puVar8 + iVar5;
    puVar2 = puVar6 + iVar5;
    uVar7 = puVar6[iVar5] / (puVar8[iVar5] + 1);
    if (puVar8[iVar5] + 1 <= puVar6[iVar5]) {
      uVar10 = 0;
      iVar11 = 0;
      puVar12 = puVar8;
      puVar14 = puVar6;
      do {
        puVar13 = puVar12 + 1;
        uVar1 = uVar7 * (*puVar12 & 0xffff) + uVar10;
        uVar3 = uVar7 * (*puVar12 >> 0x10) + (uVar1 >> 0x10);
        uVar10 = uVar3 >> 0x10;
        uVar1 = ((*puVar14 & 0xffff) - (uVar1 & 0xffff)) + iVar11;
        iVar4 = (((int)uVar1 >> 0x10) - (uVar3 & 0xffff)) + (*puVar14 >> 0x10);
        iVar11 = iVar4 >> 0x10;
        *puVar14 = uVar1 & 0xffff | iVar4 * 0x10000;
        puVar12 = puVar13;
        puVar14 = puVar14 + 1;
      } while (puVar13 <= puVar9);
      if (puVar6[iVar5] == 0) {
        while ((puVar2 = puVar2 + -1, puVar6 < puVar2 && (*puVar2 == 0))) {
          iVar5 = iVar5 + -1;
        }
        *(int *)((int)param_1 + 0x10) = iVar5;
      }
    }
    iVar11 = cmp(param_1,param_2);
    if (-1 < iVar11) {
      iVar11 = 0;
      puVar2 = puVar6;
      do {
        puVar12 = puVar8 + 1;
        uVar10 = ((*puVar2 & 0xffff) - (*puVar8 & 0xffff)) + iVar11;
        iVar4 = (((int)uVar10 >> 0x10) - (*puVar8 >> 0x10)) + (*puVar2 >> 0x10);
        iVar11 = iVar4 >> 0x10;
        *puVar2 = uVar10 & 0xffff | iVar4 * 0x10000;
        puVar2 = puVar2 + 1;
        puVar8 = puVar12;
      } while (puVar12 <= puVar9);
      puVar8 = puVar6 + iVar5;
      if (puVar6[iVar5] == 0) {
        while ((puVar8 = puVar8 + -1, puVar6 < puVar8 && (*puVar8 == 0))) {
          iVar5 = iVar5 + -1;
        }
        *(int *)((int)param_1 + 0x10) = iVar5;
      }
      uVar7 = uVar7 + 1;
    }
  }
  return uVar7;
}


