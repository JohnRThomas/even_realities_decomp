/*
 * Function: mutex_unlock
 * Entry:    0007c9d0
 * Prototype: int __stdcall mutex_unlock(undefined4 * param_1)
 */


/* exclude_from_export */

int mutex_unlock(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return -0x7001;
  }
  if (param_1[1] != 0xa95c5f2c) {
    if ((param_1[1] & 0x3a000000) != 0) {
      DataMemoryBarrier(0x1f);
      *param_1 = 0;
      return 0;
    }
    return -0x7017;
  }
  return -0x7016;
}


