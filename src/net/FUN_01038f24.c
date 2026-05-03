/*
 * Function: FUN_01038f24
 * Entry:    01038f24
 * Prototype: undefined4 __stdcall FUN_01038f24(int * param_1, int param_2, uint param_3, uint param_4)
 */


undefined4 FUN_01038f24(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int extraout_r1;
  char *pcVar6;
  char *extraout_r2;
  undefined4 uVar7;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar8;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  uint uVar9;
  
  iVar2 = DAT_21004b30;
  uVar7 = 1;
  pcVar6 = (char *)(DAT_21004b30 + 0x60);
  *(undefined1 *)(DAT_21004b30 + 0x60) = 1;
  *(undefined1 *)(iVar2 + 0x61) = 1;
  uVar9 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar9 = getCurrentExceptionNumber();
    uVar9 = uVar9 & 0x1f;
  }
  piVar4 = param_1;
  if (uVar9 == 0) goto LAB_01038f62;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x12d,1);
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          piVar4 = (int *)FUN_0103a370();
          param_2 = extraout_r1;
          pcVar6 = extraout_r2;
          uVar7 = extraout_r3;
LAB_01038f62:
          if (piVar4 != (int *)0x0) break;
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x12e,
                       uVar7);
        }
        if (-1 < param_2) break;
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x12f,
                     uVar7);
      }
      iVar5 = FUN_01038c68(piVar4,param_2,pcVar6,(uint)(param_3 == 0 && param_4 == 0));
      uVar7 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar7 = getBasePriority();
      }
      bVar3 = (bool)isCurrentModePrivileged();
      if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar3 = FUN_010368cc((uint *)&DAT_21004b78);
      uVar8 = extraout_r3_00;
      if (bVar3) break;
LAB_01038fb4:
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,uVar8);
    }
    FUN_01036904((uint *)&DAT_21004b78);
    if (*(char *)(iVar2 + 0x60) == '\0') {
      FUN_01038e14((int)param_1,iVar5,uVar7);
      bVar3 = FUN_010368e8((uint *)&DAT_21004b78);
      uVar8 = extraout_r3_01;
      if (bVar3) {
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          setBasePriority(uVar7);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
    }
    else {
      *(char *)(iVar2 + 0x60) = (char)uVar9;
      if ((param_3 | param_4) == 0) {
        bVar3 = FUN_010368e8((uint *)&DAT_21004b78);
        uVar8 = extraout_r3_02;
        if (bVar3) {
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            setBasePriority(uVar7);
          }
          InstructionSynchronizationBarrier(0xf);
          return 0xfffffff5;
        }
      }
      else {
        uVar7 = FUN_01037d78((uint *)&DAT_21004b78,uVar7,(int *)&DAT_21000758,param_3 | param_4,
                             param_3,param_4);
        param_4 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          param_4 = getBasePriority();
        }
        bVar3 = (bool)isCurrentModePrivileged();
        if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
          setBasePriority(0x40);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar3 = FUN_010368cc((uint *)&DAT_21004b78);
        uVar8 = extraout_r3_03;
        if (!bVar3) goto LAB_01038fb4;
        FUN_01036904((uint *)&DAT_21004b78);
        FUN_01038e14((int)param_1,iVar5,param_4);
        bVar3 = FUN_010368e8((uint *)&DAT_21004b78);
        uVar8 = extraout_r3_04;
        if (bVar3) {
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            setBasePriority(param_4);
          }
          InstructionSynchronizationBarrier(0xf);
          return uVar7;
        }
      }
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,uVar8);
  } while( true );
}


