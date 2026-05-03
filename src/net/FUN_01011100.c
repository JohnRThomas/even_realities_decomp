/*
 * Function: FUN_01011100
 * Entry:    01011100
 * Prototype: undefined __stdcall FUN_01011100(int param_1, undefined1 * param_2)
 */


void FUN_01011100(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  *param_2 = 6;
  uVar1 = *(undefined1 *)(param_1 + 0xb);
  *(undefined2 *)(param_2 + 3) = *(undefined2 *)(param_1 + 9);
  param_2[5] = uVar1;
  return;
}


