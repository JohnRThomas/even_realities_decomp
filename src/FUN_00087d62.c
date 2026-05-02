/*
 * Function: FUN_00087d62
 * Entry:    00087d62
 * Prototype: undefined4 __stdcall FUN_00087d62(device * param_1, int param_2)
 */


undefined4 FUN_00087d62(device *param_1,int param_2)

{
  if (param_2 != 7) {
    if (param_2 != 0x3a) {
      if (param_2 == 3) {
        lsm6dso_sample_fetch_accel(param_1);
        return 0;
      }
      return 0xffffff7a;
    }
    lsm6dso_sample_fetch_accel(param_1);
  }
  lsm6dso_sample_fetch_gyro(param_1);
  return 0;
}


