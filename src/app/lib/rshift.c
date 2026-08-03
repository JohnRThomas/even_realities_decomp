/*
 * Function: rshift
 * Entry:    0008aa4e
 * Prototype: undefined __stdcall rshift(int param_1, uint param_2)
 */


/* exclude_from_export_ai */

void rshift(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar3 = (int)param_2 >> 5;
  if (iVar3 < iVar4) {
    puVar6 = (uint *)(param_1 + 0x14);
    uVar1 = param_2 & 0x1f;
    puVar7 = puVar6 + iVar4;
    puVar5 = puVar6 + iVar3;
    if (uVar1 == 0) {
      puVar8 = (uint *)(param_1 + 0x10);
      for (puVar2 = puVar5; puVar2 < puVar7; puVar2 = puVar2 + 1) {
        puVar8 = puVar8 + 1;
        *puVar8 = *puVar2;
      }
      iVar3 = (iVar4 - iVar3) * 4;
      if (puVar7 < (uint *)((int)puVar5 - 3U)) {
        iVar3 = 0;
      }
      puVar5 = (uint *)(iVar3 + (int)puVar6);
    }
    else {
      uVar9 = puVar6[iVar3];
      puVar2 = puVar6;
      puVar8 = puVar5;
      while( true ) {
        uVar9 = uVar9 >> uVar1;
        puVar8 = puVar8 + 1;
        if (puVar7 <= puVar8) break;
        *puVar2 = *puVar8 << (0x20 - uVar1 & 0xff) | uVar9;
        uVar9 = *puVar8;
        puVar2 = puVar2 + 1;
      }
      iVar3 = (iVar4 - iVar3) * 4 + -4;
      if (puVar7 < (uint *)((int)puVar5 + 1U)) {
        iVar3 = 0;
      }
      puVar5 = (uint *)((int)puVar6 + iVar3);
      *(uint *)((int)puVar6 + iVar3) = uVar9;
      if (uVar9 != 0) {
        puVar5 = puVar5 + 1;
      }
    }
    *(int *)(param_1 + 0x10) = (int)puVar5 - (int)puVar6 >> 2;
    if (puVar5 != puVar6) {
      return;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


