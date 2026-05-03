/*
 * Function: FUN_01031adc
 * Entry:    01031adc
 * Prototype: int __stdcall FUN_01031adc(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_01031adc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (1 < param_1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",0x86,param_4);
    param_1 = FUN_0103a370();
  }
  return param_1 * 4 + 0x41016140;
}


