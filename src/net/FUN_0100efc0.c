/*
 * Function: FUN_0100efc0
 * Entry:    0100efc0
 * Prototype: undefined __stdcall FUN_0100efc0(int param_1, undefined4 param_2)
 */


void FUN_0100efc0(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 8) = (char)param_2;
  *(char *)(param_1 + 9) = (char)((uint)param_2 >> 8);
  return;
}


