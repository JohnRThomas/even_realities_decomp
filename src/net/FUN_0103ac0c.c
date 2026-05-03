/*
 * Function: FUN_0103ac0c
 * Entry:    0103ac0c
 * Prototype: uint * __stdcall FUN_0103ac0c(uint * param_1, undefined4 param_2, uint param_3, uint * param_4)
 */


/* WARNING: Type propagation algorithm not settling */

uint * FUN_0103ac0c(uint *param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r1;
  int extraout_r1_00;
  int iVar3;
  int extraout_r1_01;
  undefined4 extraout_r1_02;
  int extraout_r1_03;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar4;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  uint *puVar5;
  uint *puVar6;
  code *unaff_r8;
  undefined4 unaff_r10;
  uint *local_30;
  uint *puStack_2c;
  uint uStack_28;
  uint *local_24;
  
  puStack_2c = (uint *)**(undefined4 **)(param_1[0xb] + 4);
  local_30 = param_1;
  uStack_28 = param_3;
  local_24 = puStack_2c;
  FUN_0103bac4((longlong *)&local_30,puStack_2c,param_3,(int)param_4);
  puVar6 = puStack_2c;
  puVar5 = local_30;
  if (param_1 == (uint *)0x0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf.c",0xf8,
                 extraout_r3);
  }
  else {
    unaff_r8 = (code *)(param_1 + 7);
    unaff_r10 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      unaff_r10 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc((uint *)unaff_r8);
    if (bVar1) goto LAB_010305e6;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3_00);
  }
  do {
    while( true ) {
      FUN_0103a370();
LAB_010305e6:
      FUN_01036904((uint *)unaff_r8);
      if (*(ushort *)((int)param_1 + 0x22) != 0) break;
      bVar1 = FUN_010368e8((uint *)unaff_r8);
      uVar4 = extraout_r3_03;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(unaff_r10);
        }
        InstructionSynchronizationBarrier(0xf);
        param_4 = FUN_01036f34(param_1,extraout_r1_02,param_3,(uint)param_4);
        iVar3 = extraout_r1_03;
        if (param_4 == (uint *)0x0) {
          return (uint *)0x0;
        }
        goto LAB_01030626;
      }
LAB_01030610:
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0xf0,uVar4);
    }
    if (((ushort)param_1[8] <= *(ushort *)((int)param_1 + 0x22)) ||
       (param_4 = FUN_01036f34(param_1,extraout_r1,0,0), param_4 == (uint *)0x0)) {
      param_4 = (uint *)(uint)*(ushort *)((int)param_1 + 0x22);
      *(ushort *)((int)param_1 + 0x22) = *(ushort *)((int)param_1 + 0x22) - 1;
      bVar1 = FUN_010368e8((uint *)unaff_r8);
      uVar4 = extraout_r3_02;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(unaff_r10);
        }
        InstructionSynchronizationBarrier(0xf);
        param_4 = (uint *)(((uint)(ushort)param_1[8] - (int)param_4) *
                           ((byte)param_1[9] + 0x1b & 0xfffffffc) + param_1[0xc]);
        *(char *)((int)param_4 + 10) = (char)((int)(param_1 + -0x8400265) >> 2) * -0x3b;
        *(char *)((int)param_4 + 0xb) = (char)param_1[9];
        iVar3 = extraout_r1_01;
        goto LAB_01030626;
      }
      goto LAB_01030610;
    }
    bVar1 = FUN_010368e8((uint *)unaff_r8);
    uVar4 = extraout_r3_01;
    if (!bVar1) goto LAB_01030610;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(unaff_r10);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar3 = extraout_r1_00;
LAB_01030626:
    param_1 = local_24;
    if (local_24 == (uint *)0x0) {
      param_4[5] = 0;
LAB_010306ec:
      param_4[1] = 0;
      *(undefined2 *)(param_4 + 2) = 1;
      *(undefined2 *)(param_4 + 4) = 0;
      *(short *)((int)param_4 + 0x12) = (short)local_24;
      param_4[3] = param_4[5];
      return param_4;
    }
    FUN_0103bb0c((int *)&local_30,iVar3,(uint)puVar5,(uint)puVar6);
    puVar5 = (uint *)&DAT_21000994;
    unaff_r8 = *(code **)**(undefined4 **)
                           (&DAT_210009c0 + (uint)*(byte *)((int)param_4 + 10) * 0x34);
    uVar2 = (*unaff_r8)(param_4,&local_24,local_30,puStack_2c);
    param_4[5] = uVar2;
    if (uVar2 == 0) {
      FUN_0103b9d0((uint *)(&DAT_21000994 + (uint)*(byte *)((int)param_4 + 10) * 0x34),param_4);
      return (uint *)0x0;
    }
    if (param_1 <= local_24) goto LAB_010306ec;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x14f,
                 local_24);
    puVar6 = (uint *)&Reserved6;
  } while( true );
}


