/*
 * Function: FUN_0102f330
 * Entry:    0102f330
 * Prototype: uint __stdcall FUN_0102f330(uint param_1)
 */


uint FUN_0102f330(uint param_1)

{
  return 1 << (param_1 & 0x1f) & *(uint *)(&DAT_e000e100 + (param_1 >> 5) * 4);
}


