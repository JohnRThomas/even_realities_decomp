/*
 * Function: FUN_0100f03c
 * Entry:    0100f03c
 * Prototype: undefined __stdcall FUN_0100f03c(int param_1, undefined4 * param_2, undefined4 * param_3)
 */


void FUN_0100f03c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar1 = param_2;
  puVar3 = (undefined4 *)(param_1 + 4);
  do {
    puVar2 = puVar1 + 4;
    uVar6 = puVar1[1];
    puVar4 = puVar3 + 4;
    uVar5 = puVar1[2];
    uVar7 = puVar1[3];
    *puVar3 = *puVar1;
    puVar3[1] = uVar6;
    puVar3[2] = uVar5;
    puVar3[3] = uVar7;
    puVar1 = puVar2;
    puVar3 = puVar4;
  } while (puVar2 != param_2 + 8);
  *(undefined2 *)puVar4 = *(undefined2 *)puVar2;
  uVar5 = param_3[1];
  *(undefined4 *)(param_1 + 0x26) = *param_3;
  *(undefined4 *)(param_1 + 0x2a) = uVar5;
  return;
}


