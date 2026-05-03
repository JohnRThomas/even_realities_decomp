/*
 * Function: FUN_0100cf18
 * Entry:    0100cf18
 * Prototype: undefined4 __stdcall FUN_0100cf18(short param_1)
 */


undefined4 FUN_0100cf18(short param_1)

{
  if ((ushort)(param_1 - 1U) < 0xa1b8) {
    DAT_21000ea4 = param_1;
    return 1;
  }
  return 0;
}


