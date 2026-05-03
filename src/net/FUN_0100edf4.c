/*
 * Function: FUN_0100edf4
 * Entry:    0100edf4
 * Prototype: undefined __stdcall FUN_0100edf4(byte * param_1, byte param_2)
 */


void FUN_0100edf4(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & 0xdf | (param_2 & 1) << 5;
  return;
}


