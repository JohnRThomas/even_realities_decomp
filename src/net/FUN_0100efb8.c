/*
 * Function: FUN_0100efb8
 * Entry:    0100efb8
 * Prototype: undefined __stdcall FUN_0100efb8(int param_1, undefined4 param_2)
 */


void FUN_0100efb8(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 6) = (char)param_2;
  *(char *)(param_1 + 7) = (char)((uint)param_2 >> 8);
  return;
}


