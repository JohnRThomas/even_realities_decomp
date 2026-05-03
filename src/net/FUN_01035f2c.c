/*
 * Function: FUN_01035f2c
 * Entry:    01035f2c
 * Prototype: undefined4 __stdcall FUN_01035f2c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4, int param_5, int param_6)
 */


undefined4
FUN_01035f2c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 extraout_r3;
  int local_24 [2];
  
  piVar1 = FUN_0103b7b2(param_1,local_24,param_6);
  if (piVar1 == (int *)0x0) {
    uVar4 = 0xfffff82e;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xac);
    if (local_24[0] <= param_5) {
      param_5 = local_24[0];
    }
    uVar5 = (int)piVar1 - *piVar2;
    if ((uint)piVar2[2] <= uVar5) {
      uVar5 = 0xffffffff;
    }
    iVar3 = FUN_0103b2ce(piVar2,uVar5,param_4,param_5);
    if (param_5 != iVar3) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",0x207,
                   extraout_r3);
      FUN_0103a370();
    }
    uVar4 = FUN_01035d7c(param_1,param_2,param_3,(int)piVar1,param_5);
  }
  return uVar4;
}


