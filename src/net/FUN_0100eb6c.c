/*
 * Function: FUN_0100eb6c
 * Entry:    0100eb6c
 * Prototype: undefined __stdcall FUN_0100eb6c(int param_1, char param_2)
 */


void FUN_0100eb6c(int param_1,char param_2)

{
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0x3f | param_2 << 6;
  return;
}


