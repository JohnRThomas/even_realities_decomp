/*
 * Function: FUN_01013170
 * Entry:    01013170
 * Prototype: undefined __stdcall FUN_01013170(int param_1, undefined1 param_2, undefined1 param_3)
 */


void FUN_01013170(int param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)(param_1 + 0x20) = param_2;
  *(undefined1 *)(param_1 + 0x21) = param_3;
  return;
}


