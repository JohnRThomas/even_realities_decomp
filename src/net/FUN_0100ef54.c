/*
 * Function: FUN_0100ef54
 * Entry:    0100ef54
 * Prototype: undefined __stdcall FUN_0100ef54(int param_1, undefined4 * param_2)
 */


void FUN_0100ef54(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0xe) = *param_2;
  *(undefined4 *)(param_1 + 0x12) = uVar1;
  return;
}


