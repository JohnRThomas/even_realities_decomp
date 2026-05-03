/*
 * Function: FUN_0100efc8
 * Entry:    0100efc8
 * Prototype: undefined __stdcall FUN_0100efc8(int param_1, undefined4 param_2)
 */


void FUN_0100efc8(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 10) = (char)param_2;
  *(char *)(param_1 + 0xb) = (char)((uint)param_2 >> 8);
  return;
}


