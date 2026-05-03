/*
 * Function: FUN_01034bf0
 * Entry:    01034bf0
 * Prototype: undefined __stdcall FUN_01034bf0(undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01034bf0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r1;
  
  if (param_2 == 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/helpers/nrfx_gppi_dppi.c",99,param_4);
    FUN_0103a370();
    param_2 = extraout_r1;
  }
  *(undefined4 *)(param_2 + 0x80) = 0;
  return;
}


