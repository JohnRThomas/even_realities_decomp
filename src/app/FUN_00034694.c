/*
 * Function: FUN_00034694
 * Entry:    00034694
 * Prototype: int __stdcall FUN_00034694(device * param_1)
 */


int FUN_00034694(device *param_1)

{
  if (param_1 != (device *)0x0) {
    if (DAT_20002428 != param_1) {
      DAT_20002428 = param_1;
    }
    DAT_2000242c = 1;
    return 0;
  }
  return -1;
}


