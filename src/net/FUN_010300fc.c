/*
 * Function: FUN_010300fc
 * Entry:    010300fc
 * Prototype: undefined __stdcall FUN_010300fc(uint * param_1, int param_2)
 */


void FUN_010300fc(uint *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  int iVar3;
  int extraout_r2;
  undefined4 extraout_r3;
  uint extraout_r3_00;
  uint uVar4;
  
  uVar4 = (uint)DAT_21004fb0;
  uVar2 = 0;
  iVar3 = -0x1fff1300;
  uVar1 = uVar4;
  do {
    if (7 < (int)uVar1) {
      FUN_0102fdc8(DAT_210046a0,&DAT_210046a4);
      uVar1 = FUN_0102fe2c(param_1,param_2,uVar4);
      if (uVar1 != 0xffffffea) {
        return;
      }
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/mpu/arm_mpu.c",0x13a,extraout_r3);
      FUN_0103a370();
      uVar2 = extraout_r1;
      iVar3 = extraout_r2;
      uVar1 = extraout_r3_00;
    }
    *(uint *)(iVar3 + 0x98) = uVar1;
    *(undefined4 *)(iVar3 + 0xa0) = uVar2;
    uVar1 = uVar1 + 1;
  } while( true );
}


