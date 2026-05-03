/*
 * Function: FUN_0102fdc8
 * Entry:    0102fdc8
 * Prototype: undefined __stdcall FUN_0102fdc8(undefined4 param_1, uint * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102fdc8(undefined4 param_1,uint *param_2)

{
  _DAT_e000ed98 = param_1;
  _DAT_e000ed9c = (byte)param_2[2] & 0x1f | *param_2 & 0xffffffe0;
  _DAT_e000eda0 = param_2[3] & 0xffffffe0 | (uint)(byte)((byte)param_2[2] >> 5) << 1 | 1;
  return;
}


