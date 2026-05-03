/*
 * Function: FUN_0100ef84
 * Entry:    0100ef84
 * Prototype: undefined __stdcall FUN_0100ef84(int param_1, undefined4 * param_2)
 */


void FUN_0100ef84(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}


