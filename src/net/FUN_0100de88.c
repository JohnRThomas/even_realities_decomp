/*
 * Function: FUN_0100de88
 * Entry:    0100de88
 * Prototype: uint __stdcall FUN_0100de88(uint param_1, undefined * param_2)
 */


uint FUN_0100de88(uint param_1,undefined *param_2)

{
  if (&DAT_00001d4b < param_2) {
    return (uint)((int)((ulonglong)param_1 * 0xd1b71759 >> 0x20) << 6) >> 0x10;
  }
  return (uint)((int)((ulonglong)param_1 * 0x51eb851f >> 0x20) << 0xb) >> 0x10;
}


