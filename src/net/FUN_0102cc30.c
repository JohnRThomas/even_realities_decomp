/*
 * Function: FUN_0102cc30
 * Entry:    0102cc30
 * Prototype: undefined __stdcall FUN_0102cc30(int * param_1, int param_2)
 */


void FUN_0102cc30(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r3;
  int iVar4;
  
  if (param_2 != 0) {
    iVar4 = *param_1;
    uVar1 = FUN_01039f6c(iVar4,param_2);
    uVar2 = FUN_01039efc(iVar4,uVar1,extraout_r2);
    if ((int)(uVar2 << 0x1f) < 0) goto LAB_0102cc5e;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0xaf,
                 uVar2 << 0x1f);
    while( true ) {
      FUN_0103a370();
LAB_0102cc5e:
      uVar2 = FUN_01039f28(iVar4,uVar1);
      uVar3 = FUN_01039efc(iVar4,uVar1 + uVar2,0);
      if (uVar1 == (uVar1 + uVar2) - uVar3) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0xb7,
                   extraout_r3);
    }
    iVar4 = FUN_01039f34(iVar4,uVar1,extraout_r2_00);
    FUN_0103a1b6(iVar4,uVar1);
    return;
  }
  return;
}


