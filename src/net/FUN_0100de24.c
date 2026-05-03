/*
 * Function: FUN_0100de24
 * Entry:    0100de24
 * Prototype: uint __stdcall FUN_0100de24(int param_1, undefined * param_2)
 */


uint FUN_0100de24(int param_1,undefined *param_2)

{
  if (&DAT_00001d4b < param_2) {
    return param_1 * 0x4e2 & 0xffff;
  }
  return param_1 * 100;
}


