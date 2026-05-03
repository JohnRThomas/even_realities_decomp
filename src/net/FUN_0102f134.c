/*
 * Function: FUN_0102f134
 * Entry:    0102f134
 * Prototype: undefined __stdcall FUN_0102f134(uint param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0102f134(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 extraout_r3;
  
  uVar1 = FUN_0102f330(param_1);
  if (uVar1 != 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/arch/common/sw_isr_common.c"
                 ,0x55,extraout_r3);
    FUN_0103a370();
  }
  *(undefined4 *)(&DAT_2100076c + param_1 * 8) = param_3;
  *(undefined4 *)(&DAT_21000770 + param_1 * 8) = param_2;
  return;
}


