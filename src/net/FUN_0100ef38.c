/*
 * Function: FUN_0100ef38
 * Entry:    0100ef38
 * Prototype: undefined __stdcall FUN_0100ef38(int param_1, undefined4 * param_2)
 */


void FUN_0100ef38(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = uVar1;
  return;
}


