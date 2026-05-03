/*
 * Function: FUN_01037478
 * Entry:    01037478
 * Prototype: undefined __stdcall FUN_01037478(undefined1 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01037478(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == (undefined1 *)0x0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x2b9,param_4
                );
    param_1 = (undefined1 *)FUN_0103a370();
  }
  FUN_0103bdee(param_1,0,0xb8);
  return;
}


