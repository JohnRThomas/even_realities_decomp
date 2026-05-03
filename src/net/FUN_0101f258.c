/*
 * Function: FUN_0101f258
 * Entry:    0101f258
 * Prototype: undefined4 __stdcall FUN_0101f258(short * param_1)
 */


undefined4 FUN_0101f258(short *param_1)

{
  if (((ushort)(*param_1 - 0x1bU) < 0xe1) && ((ushort)(param_1[1] - 0x148U) < 0x4149)) {
    DAT_21001208._0_2_ = *param_1;
    DAT_21001208._2_2_ = param_1[1];
    return 0;
  }
  return 0x12;
}


