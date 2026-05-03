/*
 * Function: FUN_0100ee8c
 * Entry:    0100ee8c
 * Prototype: undefined __stdcall FUN_0100ee8c(int param_1, undefined4 param_2)
 */


void FUN_0100ee8c(int param_1,undefined4 param_2)

{
  *(char *)(param_1 + 0xb) = (char)param_2;
  *(char *)(param_1 + 0xc) = (char)((uint)param_2 >> 8);
  return;
}


