/*
 * Function: FUN_0100de4c
 * Entry:    0100de4c
 * Prototype: uint __stdcall FUN_0100de4c(uint param_1, undefined * param_2)
 */


uint FUN_0100de4c(uint param_1,undefined *param_2)

{
  if (&DAT_00001d4b < param_2) {
    return (uint)((int)((ulonglong)param_1 * 0xd1b71759 >> 0x20) << 0xe) >> 0x18;
  }
  return (uint)((int)((ulonglong)param_1 * 0x51eb851f >> 0x20) << 0x13) >> 0x18;
}


