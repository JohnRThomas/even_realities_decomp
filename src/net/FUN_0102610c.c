/*
 * Function: FUN_0102610c
 * Entry:    0102610c
 * Prototype: undefined __stdcall FUN_0102610c(undefined4 * param_1, undefined4 * param_2, uint param_3)
 */


void FUN_0102610c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  if ((uint)((int)param_1 - (int)param_2) < param_3) {
    if (param_3 != 0) {
      puVar3 = (undefined4 *)((int)param_2 + param_3);
      puVar4 = (undefined1 *)(param_3 + (int)param_1);
      do {
        puVar3 = (undefined4 *)((int)puVar3 + -1);
        puVar4 = puVar4 + -1;
        *puVar4 = *(undefined1 *)puVar3;
      } while (puVar3 != param_2);
      return;
    }
  }
  else if (param_3 != 0) {
    if (((uint)((int)param_1 - ((int)param_2 + 1)) < 3) || (param_3 - 1 < 8)) {
      puVar4 = (undefined1 *)((int)param_2 + -1);
      puVar3 = param_1;
      do {
        puVar4 = puVar4 + 1;
        puVar1 = (undefined4 *)((int)puVar3 + 1);
        *(undefined1 *)puVar3 = *puVar4;
        puVar3 = puVar1;
      } while (puVar1 != (undefined4 *)(param_3 + (int)param_1));
      return;
    }
    puVar3 = param_2;
    puVar1 = param_1;
    do {
      puVar5 = puVar3 + 1;
      *puVar1 = *puVar3;
      puVar3 = puVar5;
      puVar1 = puVar1 + 1;
    } while (puVar5 != (undefined4 *)((param_3 & 0xfffffffc) + (int)param_2));
    uVar2 = param_3 & 0xfffffffc;
    if (((param_3 != uVar2) &&
        (*(undefined1 *)((int)param_1 + uVar2) = *(undefined1 *)((int)param_2 + uVar2),
        (param_3 & 3) != 1)) &&
       (*(undefined1 *)((int)param_1 + uVar2 + 1) = *(undefined1 *)((int)param_2 + uVar2 + 1),
       (param_3 & 3) != 2)) {
      *(undefined1 *)((int)param_1 + uVar2 + 2) = *(undefined1 *)((int)param_2 + uVar2 + 2);
    }
  }
  return;
}


