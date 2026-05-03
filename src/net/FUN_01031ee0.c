/*
 * Function: FUN_01031ee0
 * Entry:    01031ee0
 * Prototype: undefined __stdcall FUN_01031ee0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01031ee0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",599,param_4);
    FUN_0103a370();
  }
  DAT_21004968 = DAT_21004968 | 2;
  return;
}


