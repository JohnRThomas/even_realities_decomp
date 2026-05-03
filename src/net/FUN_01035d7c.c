/*
 * Function: FUN_01035d7c
 * Entry:    01035d7c
 * Prototype: undefined4 __stdcall FUN_01035d7c(int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5)
 */


undefined4
FUN_01035d7c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar5;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  
  uVar5 = *(uint *)(param_4 + -8);
  piVar1 = *(int **)(param_1 + 0xac);
  local_20 = 0;
  local_1a = 0;
  local_1c = (undefined2)param_5;
  uVar4 = (param_4 + -0x10) - *piVar1;
  if ((uint)piVar1[2] <= uVar4) {
    uVar4 = 0xffffffff;
  }
  local_28 = param_2;
  uStack_24 = param_3;
  iVar2 = FUN_0103b2ce(piVar1,uVar4,&local_28,0x10);
  uVar5 = uVar5 & 0xffff;
  uVar3 = extraout_r1;
  if (iVar2 == 0x10) goto LAB_01035dd2;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
               "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",0x1af,
               extraout_r3);
  while( true ) {
    FUN_0103a370();
    uVar3 = extraout_r1_00;
LAB_01035dd2:
    FUN_0103b686((int *)(param_1 + 0x58),uVar3);
    uVar3 = FUN_0103b406(*(int *)(param_1 + 0xa8),uVar5);
    if ((*(int *)(*(int *)(param_1 + 0xa0) + 0x18) != 1) ||
       (iVar2 = FUN_01035bac(*(int *)(param_1 + 0xa8),uVar5,uVar3), iVar2 == 0)) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",0x1bc,
                 extraout_r3_00);
  }
  FUN_0103b48a(*(int **)(param_1 + 0xa8));
  FUN_01036fe4((int *)(param_1 + 0x58));
  return param_5;
}


