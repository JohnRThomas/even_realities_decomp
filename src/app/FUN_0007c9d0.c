/*
 * Function: FUN_0007c9d0
 * Entry:    0007c9d0
 * Prototype: undefined4 __stdcall FUN_0007c9d0(undefined4 * param_1)
 */


undefined4 FUN_0007c9d0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0xffff8fff;
  }
  if (param_1[1] != 0xa95c5f2c) {
    if ((param_1[1] & 0x3a000000) != 0) {
      DataMemoryBarrier(0x1f);
      *param_1 = 0;
      return 0;
    }
    return 0xffff8fe9;
  }
  return 0xffff8fea;
}


