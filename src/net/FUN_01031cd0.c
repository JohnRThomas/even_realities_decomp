/*
 * Function: FUN_01031cd0
 * Entry:    01031cd0
 * Prototype: undefined __stdcall FUN_01031cd0(int param_1, undefined4 param_2, uint param_3, uint param_4, undefined4 param_5, undefined4 param_6)
 */


void FUN_01031cd0(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  uint extraout_r2;
  uint extraout_r3;
  
  uVar1 = 1;
  if (param_1 != 1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",0x18d,param_4);
    uVar1 = FUN_0103a370();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
  }
  FUN_01031bac(uVar1,param_5,param_3,param_4,param_5,param_6,'\0');
  return;
}


