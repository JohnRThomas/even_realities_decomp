/*
 * Function: FUN_0102fd40
 * Entry:    0102fd40
 * Prototype: undefined __stdcall FUN_0102fd40(int * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102fd40(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  uint extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar4;
  undefined4 extraout_r2;
  undefined4 uVar5;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  uint uVar6;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar7;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  int *piVar8;
  undefined4 uVar9;
  
  if (DAT_21004b30 == param_1) {
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = getCurrentExceptionNumber();
      uVar6 = uVar6 & 0x1f;
    }
    if (uVar6 != 0) {
      _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
      _DAT_e000ed24 = _DAT_e000ed24 & 0xffff7fff;
    }
  }
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = FUN_010368cc((uint *)&DAT_21004b68);
  if (bVar1) goto LAB_010384b8;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  do {
    while( true ) {
      FUN_0103a370();
LAB_010384b8:
      FUN_01036904((uint *)&DAT_21004b68);
      if (-1 < (int)((uint)*(byte *)(param_1 + 3) << 0x1f)) break;
      bVar1 = FUN_010368e8((uint *)&DAT_21004b68);
      uVar3 = extraout_r3_00;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar9);
        }
        InstructionSynchronizationBarrier(0xf);
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x6d7,
                     extraout_r3_00);
      }
      else {
LAB_010384cc:
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0,uVar3);
      }
    }
    uVar6 = (uint)*(byte *)((int)param_1 + 0xd);
    if ((int)(uVar6 << 0x1c) < 0) {
LAB_010384fc:
      bVar1 = FUN_010368e8((uint *)&DAT_21004b68);
      uVar3 = extraout_r3_01;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar9);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
      }
      goto LAB_010384cc;
    }
    uVar2 = uVar6 & 0xffffffdf | 8;
    uVar4 = (uint)(*(byte *)((int)param_1 + 0xd) >> 7);
    if (uVar4 == 0) {
      *(char *)((int)param_1 + 0xd) = (char)uVar2;
      uVar3 = 0;
    }
    else {
      uVar6 = uVar6 & 0x5f | 8;
      *(char *)((int)param_1 + 0xd) = (char)uVar6;
      FUN_01037b1c(&DAT_21004b40,param_1,uVar4,uVar6);
      uVar2 = extraout_r1_00;
      uVar3 = extraout_r2_00;
    }
    if (param_1[2] != 0) {
      FUN_01037fd4(param_1,uVar2,uVar3,param_1[2]);
    }
    FUN_01038898(param_1 + 6);
    uVar3 = extraout_r1;
    uVar5 = extraout_r2;
    uVar7 = extraout_r3_02;
    while ((piVar8 = (int *)param_1[0x16], piVar8 != param_1 + 0x16 && (piVar8 != (int *)0x0))) {
      FUN_01037fd4(piVar8,uVar3,uVar5,uVar7);
      FUN_01038898(piVar8 + 6);
      piVar8[0x24] = 0;
      FUN_0103778c(piVar8);
      uVar3 = extraout_r1_01;
      uVar5 = extraout_r2_01;
      uVar7 = extraout_r3_04;
    }
    FUN_01037734(1,uVar3,uVar5,uVar7);
    if (DAT_21004b30 != param_1) goto LAB_010384fc;
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = getCurrentExceptionNumber();
      uVar6 = uVar6 & 0x1f;
    }
    if (uVar6 != 0) goto LAB_010384fc;
    bVar1 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar1) {
      FUN_0102f3d0(uVar9);
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x70d,
                   extraout_r3_05);
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x111,extraout_r3_03);
    }
  } while( true );
}


