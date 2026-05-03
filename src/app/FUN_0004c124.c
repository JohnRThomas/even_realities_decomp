/*
 * Function: FUN_0004c124
 * Entry:    0004c124
 * Prototype: undefined4 __stdcall FUN_0004c124(int param_1)
 */


undefined4 FUN_0004c124(int param_1)

{
  if (0x7c < param_1) {
    param_1 = 0x7d;
  }
  if (param_1 < 0x21) {
    param_1 = 0x21;
  }
  DAT_20002564 = param_1;
  return 0;
}


