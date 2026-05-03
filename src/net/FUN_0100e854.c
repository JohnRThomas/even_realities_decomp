/*
 * Function: FUN_0100e854
 * Entry:    0100e854
 * Prototype: undefined __stdcall FUN_0100e854(byte * param_1, char param_2)
 */


void FUN_0100e854(byte *param_1,char param_2)

{
  *param_1 = *param_1 & 0x7f | param_2 << 7;
  return;
}


