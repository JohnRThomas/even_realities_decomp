/*
 * Function: FUN_0100e808
 * Entry:    0100e808
 * Prototype: undefined __stdcall FUN_0100e808(int param_1, undefined4 * param_2)
 */


void FUN_0100e808(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 3) = *param_2;
  *(undefined2 *)(param_1 + 7) = *(undefined2 *)(param_2 + 1);
  return;
}


