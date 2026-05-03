/*
 * Function: FUN_0100ebfc
 * Entry:    0100ebfc
 * Prototype: char __stdcall FUN_0100ebfc(int param_1)
 */


char FUN_0100ebfc(int param_1)

{
  return (*(char *)(param_1 + 1) + -1) - (*(byte *)(param_1 + 3) & 0x3f);
}


