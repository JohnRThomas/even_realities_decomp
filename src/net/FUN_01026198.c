/*
 * Function: FUN_01026198
 * Entry:    01026198
 * Prototype: undefined __stdcall FUN_01026198(undefined4 * param_1, undefined4 * param_2, uint param_3)
 */


void FUN_01026198(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  if ((((uint)param_2 ^ (uint)param_1) & 3) == 0) {
    for (; ((uint)param_1 & 3) != 0; param_1 = (undefined4 *)((int)param_1 + 1)) {
      if (param_3 == 0) {
        return;
      }
      param_3 = param_3 - 1;
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    if (3 < param_3) {
      uVar6 = param_3 - 4 >> 2;
      if (((((uint)param_2 | (uint)param_1) & 7) == 0) && (0x2b < param_3 - 4)) {
        uVar5 = uVar6 + 1;
        puVar1 = param_1;
        puVar3 = param_2 + -2;
        do {
          uVar4 = puVar3[3];
          puVar2 = puVar1 + 2;
          *puVar1 = puVar3[2];
          puVar1[1] = uVar4;
          puVar1 = puVar2;
          puVar3 = puVar3 + 2;
        } while (puVar2 != param_1 + (uVar5 & 0xfffffffe));
        if ((uVar5 & 1) != 0) {
          param_1[uVar5 & 0xfffffffe] = param_2[uVar5 & 0xfffffffe];
        }
      }
      else {
        puVar1 = param_1 + -1;
        puVar3 = param_2;
        do {
          puVar2 = puVar3 + 1;
          puVar1 = puVar1 + 1;
          *puVar1 = *puVar3;
          puVar3 = puVar2;
        } while (puVar2 != param_2 + uVar6 + 1);
      }
      param_3 = param_3 & 3;
      param_1 = param_1 + uVar6 + 1;
      param_2 = param_2 + uVar6 + 1;
    }
  }
  if (param_3 != 0) {
    if (2 < param_3 - 1) {
      puVar1 = param_2;
      puVar3 = param_1;
      do {
        puVar2 = puVar1 + 1;
        *puVar3 = *puVar1;
        puVar1 = puVar2;
        puVar3 = puVar3 + 1;
      } while (puVar2 != (undefined4 *)((param_3 & 0xfffffffc) + (int)param_2));
      uVar6 = param_3 & 0xfffffffc;
      bVar7 = param_3 == uVar6;
      param_1 = (undefined4 *)((int)param_1 + uVar6);
      param_2 = (undefined4 *)((int)param_2 + uVar6);
      param_3 = param_3 & 3;
      if (bVar7) {
        return;
      }
    }
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    if ((param_3 != 1) &&
       (*(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1), param_3 != 2)) {
      *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
    }
  }
  return;
}


