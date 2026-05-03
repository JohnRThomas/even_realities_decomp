/*
 * Function: FUN_010104a0
 * Entry:    010104a0
 * Prototype: undefined __stdcall FUN_010104a0(int param_1, undefined1 * param_2)
 */


void FUN_010104a0(int param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  
  *param_2 = 0xc;
  uVar1 = *(undefined2 *)(param_1 + -0x2b8);
  param_2[2] = *(undefined1 *)(param_1 + 9);
  *(undefined2 *)(param_2 + 3) = uVar1;
  return;
}


