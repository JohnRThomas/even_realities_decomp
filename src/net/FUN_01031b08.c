/*
 * Function: FUN_01031b08
 * Entry:    01031b08
 * Prototype: undefined4 __stdcall FUN_01031b08(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_01031b08(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (1 < param_1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",0x8d,param_4);
    param_1 = FUN_0103a370();
  }
  uVar1 = 0x41016044;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}


