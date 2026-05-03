/*
 * Function: FUN_01012c24
 * Entry:    01012c24
 * Prototype: undefined __stdcall FUN_01012c24(int param_1, undefined4 * param_2)
 */


void FUN_01012c24(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  
  *(undefined4 *)(param_1 + 0x13) = *param_2;
  uVar1 = *(undefined2 *)(param_2 + 1);
  *(undefined1 *)(param_1 + 0x19) = 1;
  *(undefined2 *)(param_1 + 0x17) = uVar1;
  return;
}


