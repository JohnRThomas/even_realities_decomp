/*
 * Function: FUN_010200b0
 * Entry:    010200b0
 * Prototype: undefined __stdcall FUN_010200b0(uint param_1)
 */


void FUN_010200b0(uint param_1)

{
  *(byte *)((int)&DAT_21000020 + (param_1 >> 3)) =
       *(byte *)((int)&DAT_21000020 + (param_1 >> 3)) & ~(byte)(1 << (param_1 & 7));
  return;
}


