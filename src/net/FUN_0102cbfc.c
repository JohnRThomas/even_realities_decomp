/*
 * Function: FUN_0102cbfc
 * Entry:    0102cbfc
 * Prototype: undefined __stdcall FUN_0102cbfc(undefined * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0102cbfc(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *extraout_r1;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  
  FUN_0103847c();
  iVar1 = FUN_0103be10();
  *(undefined4 *)(iVar1 + 8) = extraout_r3;
  (*(code *)param_1)(param_2,param_3,param_4);
  FUN_0102fd40(*(int **)(iVar1 + 8));
  if (extraout_r1 != (int *)0x0) {
    iVar1 = *extraout_r1;
    uVar2 = FUN_01039f6c(iVar1,(int)extraout_r1);
    uVar3 = FUN_01039efc(iVar1,uVar2,extraout_r2);
    if ((int)(uVar3 << 0x1f) < 0) goto LAB_0102cc5e;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0xaf,
                 uVar3 << 0x1f);
    while( true ) {
      FUN_0103a370();
LAB_0102cc5e:
      uVar3 = FUN_01039f28(iVar1,uVar2);
      uVar4 = FUN_01039efc(iVar1,uVar2 + uVar3,0);
      if (uVar2 == (uVar2 + uVar3) - uVar4) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0xb7,
                   extraout_r3_00);
    }
    iVar1 = FUN_01039f34(iVar1,uVar2,extraout_r2_00);
    FUN_0103a1b6(iVar1,uVar2);
    return;
  }
  return;
}


