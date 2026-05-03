/*
 * Function: FUN_0100e838
 * Entry:    0100e838
 * Prototype: undefined __stdcall FUN_0100e838(byte * param_1, byte param_2)
 */


void FUN_0100e838(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & 0xbf | (param_2 & 1) << 6;
  return;
}


