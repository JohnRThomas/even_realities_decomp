/*
 * Function: FUN_00033770
 * Entry:    00033770
 * Prototype: byte __stdcall FUN_00033770(byte param_1)
 */


byte FUN_00033770(byte param_1)

{
  DAT_2001abc3 = DAT_2001abc3 & 0x80 | param_1 & 0x7f;
  return param_1 & 0x7f;
}


