/*
 * Function: FUN_01026284
 * Entry:    01026284
 * Prototype: undefined __stdcall FUN_01026284(undefined4 * param_1, undefined1 param_2, uint param_3)
 */


void FUN_01026284(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  for (; ((uint)param_1 & 3) != 0; param_1 = (undefined4 *)((int)param_1 + 1)) {
    if (param_3 == 0) {
      return;
    }
    *(undefined1 *)param_1 = param_2;
    param_3 = param_3 - 1;
  }
  uVar4 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
  if (param_3 < 4) goto LAB_01026332;
  uVar5 = param_3 - 4;
  iVar1 = ((int)param_1 << 0x1d) >> 0x1f;
  iVar7 = (uVar5 >> 2) + 1;
  puVar3 = param_1;
  uVar6 = param_3;
  if (uVar5 < 0x18) {
LAB_010262fa:
    *puVar3 = uVar4;
    if ((((3 < uVar6 - 4) && (puVar3[1] = uVar4, 3 < uVar6 - 8)) &&
        (puVar3[2] = uVar4, 3 < uVar6 - 0xc)) && (puVar3[3] = uVar4, 3 < uVar6 - 0x10)) {
      puVar3[4] = uVar4;
      if (3 < uVar6 - 0x14) {
        puVar3[5] = uVar4;
      }
    }
  }
  else {
    if ((int)param_1 << 0x1d < 0) {
      *param_1 = uVar4;
      uVar6 = uVar5;
      puVar3 = param_1 + 1;
    }
    uVar5 = iVar7 + iVar1;
    puVar8 = param_1 + -iVar1;
    puVar2 = puVar8 + (uVar5 & 0xfffffffe);
    do {
      *puVar8 = uVar4;
      puVar8[1] = uVar4;
      puVar8 = puVar8 + 2;
    } while (puVar2 != puVar8);
    uVar9 = uVar5 & 0xfffffffe;
    puVar3 = puVar3 + uVar9;
    uVar6 = uVar6 + uVar9 * -4;
    if (uVar5 != uVar9) goto LAB_010262fa;
  }
  param_3 = param_3 & 3;
  param_1 = param_1 + iVar7;
LAB_01026332:
  if (((param_3 != 0) && (*(undefined1 *)param_1 = param_2, param_3 != 1)) &&
     (*(undefined1 *)((int)param_1 + 1) = param_2, param_3 != 2)) {
    *(undefined1 *)((int)param_1 + 2) = param_2;
  }
  return;
}


