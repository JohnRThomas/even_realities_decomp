/*
 * Function: FUN_01010484
 * Entry:    01010484
 * Prototype: undefined __stdcall FUN_01010484(int param_1, undefined1 * param_2)
 */


void FUN_01010484(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  
  *param_2 = 0xb;
  uVar1 = *(undefined1 *)(param_1 + 0xc);
  uVar2 = *(undefined2 *)(param_1 + -0x2b8);
  param_2[2] = *(undefined1 *)(param_1 + 9);
  param_2[5] = uVar1;
  *(undefined2 *)(param_2 + 3) = uVar2;
  return;
}


