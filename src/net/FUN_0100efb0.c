/*
 * Function: FUN_0100efb0
 * Entry:    0100efb0
 * Prototype: undefined __stdcall FUN_0100efb0(int param_1, undefined4 param_2)
 */


void FUN_0100efb0(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 4) = (char)param_2;
  *(char *)(param_1 + 5) = (char)((uint)param_2 >> 8);
  return;
}


