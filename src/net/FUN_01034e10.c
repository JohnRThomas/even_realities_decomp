/*
 * Function: FUN_01034e10
 * Entry:    01034e10
 * Prototype: int __stdcall FUN_01034e10(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_01034e10(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (7 < param_1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_gpiote.h",0x2aa,param_4);
    param_1 = FUN_0103a370();
  }
  return param_1 * 4 + 0x100;
}


