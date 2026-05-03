/*
 * Function: FUN_0102b474
 * Entry:    0102b474
 * Prototype: undefined4 __stdcall FUN_0102b474(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0102b474(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x60) = 0x102b38d;
  *(undefined1 **)(param_1 + 100) = &LAB_0102b330_1;
  DAT_21004604 = param_1;
  if (1 < DAT_21000580) {
    FUN_01039ee2((byte *)"exit\n\n",param_2,param_3,DAT_21000580);
  }
  return 0;
}


