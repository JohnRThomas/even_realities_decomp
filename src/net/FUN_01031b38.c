/*
 * Function: FUN_01031b38
 * Entry:    01031b38
 * Prototype: uint __stdcall FUN_01031b38(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_01031b38(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (1 < param_1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",0xc3,param_4);
    param_1 = FUN_0103a370();
  }
  return (&Peripherals::RTC1_NS.CC_0_)[param_1];
}


