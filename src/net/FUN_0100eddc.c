/*
 * Function: FUN_0100eddc
 * Entry:    0100eddc
 * Prototype: undefined __stdcall FUN_0100eddc(byte * param_1, byte param_2)
 */


void FUN_0100eddc(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & 0xfc | param_2 & 3;
  return;
}


