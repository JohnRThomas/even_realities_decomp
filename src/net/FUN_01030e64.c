/*
 * Function: FUN_01030e64
 * Entry:    01030e64
 * Prototype: undefined4 __stdcall FUN_01030e64(int param_1, byte * param_2, uint param_3)
 */


undefined4 FUN_01030e64(int param_1,byte *param_2,uint param_3)

{
  int iVar1;
  byte *extraout_r1;
  byte *pbVar2;
  byte *extraout_r1_00;
  byte *extraout_r1_01;
  int *piVar3;
  byte *unaff_r8;
  
  piVar3 = *(int **)(param_1 + 0x10);
  if (piVar3 == (int *)&DAT_21004870) {
    unaff_r8 = (byte *)0x210048b5;
    pbVar2 = param_2;
    for (; param_3 != 0; param_3 = param_3 - iVar1 & 0xffff) {
LAB_01030e92:
      while( true ) {
        FUN_0103705c(piVar3,pbVar2,0xffffffff,0xffffffff);
        iVar1 = FUN_01030d04(unaff_r8,param_2,param_3);
        FUN_01036fe4(piVar3);
        if (iVar1 != 0) break;
        FUN_0103705c((int *)&DAT_21004888,extraout_r1_00,0xffffffff,0xffffffff);
        pbVar2 = extraout_r1_01;
      }
      param_2 = param_2 + iVar1;
      pbVar2 = extraout_r1_00;
    }
    return 0;
  }
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
               "WEST_TOPDIR/zephyr/drivers/entropy/entropy_nrf5.c",0xe4,&DAT_21004870);
  FUN_0103a370();
  pbVar2 = extraout_r1;
  goto LAB_01030e92;
}


