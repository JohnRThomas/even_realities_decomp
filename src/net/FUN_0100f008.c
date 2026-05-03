/*
 * Function: FUN_0100f008
 * Entry:    0100f008
 * Prototype: undefined __stdcall FUN_0100f008(int param_1, undefined4 * param_2)
 */


void FUN_0100f008(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  puVar3 = param_2;
  do {
    puVar4 = puVar3 + 4;
    uVar7 = puVar3[1];
    puVar2 = puVar1 + 4;
    uVar6 = puVar3[2];
    uVar5 = puVar3[3];
    *puVar1 = *puVar3;
    puVar1[1] = uVar7;
    puVar1[2] = uVar6;
    puVar1[3] = uVar5;
    puVar1 = puVar2;
    puVar3 = puVar4;
  } while (puVar4 != param_2 + 8);
  *(undefined2 *)puVar2 = *(undefined2 *)puVar4;
  return;
}


