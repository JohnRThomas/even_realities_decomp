/*
 * Function: FUN_0100ef08
 * Entry:    0100ef08
 * Prototype: undefined __stdcall FUN_0100ef08(int param_1, undefined4 * param_2)
 */


void FUN_0100ef08(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 1);
  return;
}


