/*
 * Function: FUN_0102fff4
 * Entry:    0102fff4
 * Prototype: undefined __stdcall FUN_0102fff4(uint * param_1, int param_2)
 */


void FUN_0102fff4(uint *param_1,int param_2)

{
  uint uVar1;
  undefined4 extraout_r3;
  
  uVar1 = FUN_0102fe2c(param_1,param_2,(uint)DAT_21004fb0);
  DAT_21004fb0 = (byte)uVar1;
  if (uVar1 == 0xffffffea) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/mpu/arm_mpu.c",0x11b,extraout_r3);
    FUN_0103a370();
  }
  return;
}


