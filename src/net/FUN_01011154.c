/*
 * Function: FUN_01011154
 * Entry:    01011154
 * Prototype: undefined __stdcall FUN_01011154(int param_1, undefined1 * param_2)
 */


void FUN_01011154(int param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  *param_2 = 0x33;
  puVar1 = (undefined4 *)(param_2 + 3);
  puVar4 = (undefined4 *)(param_1 + 9);
  do {
    puVar5 = puVar4 + 4;
    uVar7 = puVar4[1];
    puVar2 = puVar1 + 4;
    uVar6 = puVar4[2];
    uVar3 = puVar4[3];
    *puVar1 = *puVar4;
    puVar1[1] = uVar7;
    puVar1[2] = uVar6;
    puVar1[3] = uVar3;
    puVar1 = puVar2;
    puVar4 = puVar5;
  } while (puVar5 != (undefined4 *)(param_1 + 0x29));
  *(undefined2 *)puVar2 = *(undefined2 *)puVar5;
  return;
}


