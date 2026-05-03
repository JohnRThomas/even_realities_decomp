/*
 * Function: FUN_0100e828
 * Entry:    0100e828
 * Prototype: undefined __stdcall FUN_0100e828(int param_1, undefined4 * param_2)
 */


void FUN_0100e828(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 9) = *param_2;
  *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)(param_2 + 1);
  return;
}


