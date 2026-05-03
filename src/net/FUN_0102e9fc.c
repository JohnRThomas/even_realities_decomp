/*
 * Function: FUN_0102e9fc
 * Entry:    0102e9fc
 * Prototype: undefined __stdcall FUN_0102e9fc(int param_1, undefined4 param_2, undefined1 param_3)
 */


void FUN_0102e9fc(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 extraout_r1;
  undefined1 extraout_r2;
  char cVar1;
  char extraout_r3;
  
  cVar1 = (char)(param_1 + -0x103c0ac >> 4) + '\x01';
  if (param_1 == 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/include/zephyr/logging/log_backend.h",0xdf,0xf6);
    param_1 = FUN_0103a370();
    param_2 = extraout_r1;
    param_3 = extraout_r2;
    cVar1 = extraout_r3;
  }
  *(char *)(*(int *)(param_1 + 4) + 4) = cVar1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 6) = param_3;
  **(undefined4 **)(param_1 + 4) = param_2;
  *(undefined1 *)(*(int *)(param_1 + 4) + 5) = 1;
  if (DAT_21004fac == '\0') {
    FUN_01036fe4((int *)&DAT_21000944);
  }
  DAT_21004fac = 1;
  return;
}


