/*
 * Function: FUN_01037fd4
 * Entry:    01037fd4
 * Prototype: undefined __stdcall FUN_01037fd4(int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01037fd4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  iVar1 = param_1[2];
  if (iVar1 == 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x2d2,
                 param_4);
    iVar1 = FUN_0103a370();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
  }
  FUN_01037b1c(iVar1,param_1,param_3,param_4);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
  param_1[2] = 0;
  return;
}


