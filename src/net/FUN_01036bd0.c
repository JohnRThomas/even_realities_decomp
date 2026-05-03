/*
 * Function: FUN_01036bd0
 * Entry:    01036bd0
 * Prototype: undefined4 __stdcall FUN_01036bd0(int * param_1, undefined4 param_2, uint param_3, int param_4)
 */


undefined4 FUN_01036bd0(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar5;
  int iVar6;
  int extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  uint uVar7;
  undefined4 uVar8;
  
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getCurrentExceptionNumber();
    uVar7 = uVar7 & 0x1f;
  }
  if (uVar7 == 0) goto LAB_01036bf2;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/mutex.c",0x65,param_4);
  do {
    while( true ) {
      FUN_0103a370();
LAB_01036bf2:
      uVar8 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar8 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = FUN_010368cc((uint *)&DAT_21004b48);
      uVar5 = extraout_r3;
      if (bVar2) break;
LAB_01036c0a:
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,uVar5);
    }
    FUN_01036904((uint *)&DAT_21004b48);
    if (param_1[3] == 0) {
      iVar4 = (int)*(char *)((int)DAT_21004b30 + 0xe);
LAB_01036c54:
      param_1[3] = param_1[3] + 1;
      piVar3 = DAT_21004b30;
      param_1[4] = iVar4;
      param_1[2] = (int)piVar3;
      bVar2 = FUN_010368e8((uint *)&DAT_21004b48);
      uVar5 = extraout_r3_01;
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar8);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
    }
    else {
      piVar3 = (int *)param_1[2];
      if (piVar3 == DAT_21004b30) {
        iVar4 = param_1[4];
        goto LAB_01036c54;
      }
      if (param_3 == 0 && param_4 == 0) {
        bVar2 = FUN_010368e8((uint *)&DAT_21004b48);
        uVar5 = extraout_r3_00;
        if (bVar2) {
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(uVar8);
          }
          InstructionSynchronizationBarrier(0xf);
          return 0xfffffff0;
        }
      }
      else {
        iVar6 = (int)*(char *)((int)piVar3 + 0xe);
        iVar4 = (int)*(char *)((int)DAT_21004b30 + 0xe);
        if (iVar6 <= *(char *)((int)DAT_21004b30 + 0xe)) {
          iVar4 = iVar6;
        }
        if (iVar4 < -0x7f) {
          iVar4 = -0x7f;
        }
        if (iVar4 < iVar6) {
          bVar2 = FUN_0103b984(piVar3,iVar4);
          uVar7 = (uint)bVar2;
          iVar6 = extraout_r3_02;
        }
        iVar4 = FUN_01037d78((uint *)&DAT_21004b48,uVar8,param_1,iVar6,param_3,param_4);
        if (iVar4 == 0) {
          return 0;
        }
        param_4 = 0;
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          param_4 = getBasePriority();
        }
        bVar2 = (bool)isCurrentModePrivileged();
        if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
          setBasePriority(0x40);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar2 = FUN_010368cc((uint *)&DAT_21004b48);
        uVar5 = extraout_r3_03;
        if (!bVar2) goto LAB_01036c0a;
        FUN_01036904((uint *)&DAT_21004b48);
        if ((int *)param_1[2] != (int *)0x0) {
          piVar3 = (int *)*param_1;
          iVar4 = param_1[4];
          if ((param_1 != piVar3) && (piVar3 != (int *)0x0)) {
            if (*(char *)((int)piVar3 + 0xe) <= iVar4) {
              iVar4 = (int)*(char *)((int)piVar3 + 0xe);
            }
            if (iVar4 < -0x7f) {
              iVar4 = -0x7f;
            }
          }
          bVar2 = FUN_0103b984((int *)param_1[2],iVar4);
          if (bVar2) goto LAB_01036d00;
        }
        if (uVar7 != 0) {
LAB_01036d00:
          FUN_010378f0((uint *)&DAT_21004b48,param_4);
          return 0xfffffff5;
        }
        bVar2 = FUN_010368e8((uint *)&DAT_21004b48);
        uVar5 = extraout_r3_04;
        if (bVar2) {
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(param_4);
          }
          InstructionSynchronizationBarrier(0xf);
          return 0xfffffff5;
        }
      }
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,uVar5);
  } while( true );
}


