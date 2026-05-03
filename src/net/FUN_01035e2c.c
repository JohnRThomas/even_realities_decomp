/*
 * Function: FUN_01035e2c
 * Entry:    01035e2c
 * Prototype: undefined __stdcall FUN_01035e2c(int * param_1, undefined4 param_2, uint param_3, undefined4 param_4)
 */


void FUN_01035e2c(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  byte *pbVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r3;
  undefined4 *puVar4;
  int *piVar5;
  undefined8 uVar6;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  puVar4 = *(undefined4 **)(*param_1 + 0x24);
  piVar5 = puVar4 + 0x16;
  uStack_20 = param_3;
  local_1c = param_4;
  FUN_0103b686(piVar5,param_2);
  if (*(int *)(puVar4[0x28] + 0x18) != 1) {
    thunk_FUN_01036fe4(piVar5);
    return;
  }
  puVar1 = (undefined4 *)FUN_0103b410(puVar4[0x29],(ushort *)((int)&uStack_20 + 2),&local_1c);
  thunk_FUN_01036fe4(piVar5);
  uVar3 = extraout_r1;
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  do {
    puVar1[2] = uStack_20 >> 0x10;
    FUN_0103b686(piVar5,uVar3);
    pbVar2 = FUN_0103b5d0(puVar4,0,puVar1[1],-1);
    thunk_FUN_01036fe4(piVar5);
    uVar3 = extraout_r1_00;
    if (pbVar2 != (byte *)0x0) {
      if (*(int *)(pbVar2 + 0x28) == -1) {
        *(undefined4 *)(pbVar2 + 0x28) = *puVar1;
      }
      uVar6 = (**(code **)(pbVar2 + 0x2c))
                        (pbVar2,puVar1 + 4,*(undefined2 *)(puVar1 + 3),*puVar1,
                         *(undefined4 *)(pbVar2 + 0x3c));
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 < 0) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",0x245,
                     extraout_r3);
        FUN_0103a370();
        uVar3 = extraout_r1_01;
      }
    }
    FUN_0103b686(piVar5,uVar3);
    if (-1 < (int)puVar1[2]) {
      if (*(int *)(puVar4[0x28] + 0x18) != 1) {
LAB_01035ee8:
        FUN_0103b48a((int *)puVar4[0x29]);
        thunk_FUN_01036fe4(piVar5);
        return;
      }
      FUN_01035bac(puVar4[0x29],uStack_20 >> 0x10,local_1c);
    }
    if ((*(int *)(puVar4[0x28] + 0x18) != 1) ||
       (puVar1 = (undefined4 *)FUN_0103b410(puVar4[0x29],(ushort *)((int)&uStack_20 + 2),&local_1c),
       puVar1 == (undefined4 *)0x0)) goto LAB_01035ee8;
    thunk_FUN_01036fe4(piVar5);
    uVar3 = extraout_r1_02;
  } while( true );
}


