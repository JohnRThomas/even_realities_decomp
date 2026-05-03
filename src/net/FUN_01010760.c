/*
 * Function: FUN_01010760
 * Entry:    01010760
 * Prototype: undefined __stdcall FUN_01010760(int param_1, undefined1 * param_2)
 */


void FUN_01010760(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  *param_2 = 7;
  uVar3 = *(undefined4 *)(param_1 + 0xd);
  *(undefined4 *)(param_2 + 3) = *(undefined4 *)(param_1 + 9);
  uVar2 = *(undefined2 *)(param_1 + 0x11);
  uVar1 = *(undefined1 *)(param_1 + 0x13);
  *(undefined4 *)(param_2 + 7) = uVar3;
  *(undefined2 *)(param_2 + 0xb) = uVar2;
  param_2[0xd] = uVar1;
  return;
}


