/*
 * Function: FUN_0100ddd0
 * Entry:    0100ddd0
 * Prototype: uint __stdcall FUN_0100ddd0(uint param_1)
 */


uint FUN_0100ddd0(uint param_1)

{
  if (&DAT_00001770 < (undefined *)(param_1 - 1000)) {
    return (uint)((int)((ulonglong)param_1 * 0xd1b71759 >> 0x20) << 6) >> 0x10;
  }
  return param_1 / 1000 + 0xd00 & 0xffff;
}


