/*
 * Function: FUN_0100b104
 * Entry:    0100b104
 * Prototype: undefined4 __stdcall FUN_0100b104(undefined4 * param_1)
 */


undefined4 FUN_0100b104(undefined4 *param_1)

{
  if (DAT_21000c2c != -1) {
    *param_1 = 0;
    return 0;
  }
  if (DAT_21000c2a != '\x01') {
    *param_1 = &DAT_21000bf8;
    return 1;
  }
  return 0;
}


