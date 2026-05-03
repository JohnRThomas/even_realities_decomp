/*
 * Function: FUN_01038e14
 * Entry:    01038e14
 * Prototype: undefined __stdcall FUN_01038e14(int param_1, int param_2, undefined4 param_3)
 */


void FUN_01038e14(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int iVar6;
  
  iVar2 = param_2 * 0x14 + param_1;
LAB_01038e26:
  if (param_2 != 0) {
    iVar6 = iVar2 + -0x14;
    uVar4 = *(byte *)(iVar2 + -7) & 0x3f;
    *(undefined4 *)(iVar2 + -0xc) = 0;
    switch(uVar4) {
    case 0:
      goto switchD_01038e40_caseD_0;
    case 1:
      if (*(int *)(iVar2 + -4) != 0) goto LAB_01038eb0;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0xbe,0);
      goto LAB_01038e62;
    case 2:
      if (*(int *)(iVar2 + -4) != 0) goto LAB_01038eb0;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0xb6,0);
      goto LAB_01038e62;
    default:
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0xcf,uVar4)
      ;
      goto LAB_01038e62;
    case 4:
      goto switchD_01038e40_caseD_4;
    case 8:
      if (*(int *)(iVar2 + -4) != 0) goto LAB_01038eb0;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0xc2,0);
      goto LAB_01038e62;
    }
  }
  return;
switchD_01038e40_caseD_0:
  bVar1 = FUN_010368e8((uint *)&DAT_21004b78);
  if (bVar1) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(param_3);
    }
    InstructionSynchronizationBarrier(0xf);
    param_3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      param_3 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc((uint *)&DAT_21004b78);
    param_2 = param_2 + -1;
    if (bVar1) goto LAB_01038f0a;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3_00);
  }
  else {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3);
  }
LAB_01038e62:
  while( true ) {
    iVar2 = FUN_0103a370();
switchD_01038e40_caseD_4:
    if (*(int *)(iVar2 + -4) != 0) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0xba,0);
  }
LAB_01038eb0:
  iVar5 = *(int *)(iVar2 + -0x14);
  if (iVar5 != 0) {
    piVar3 = *(int **)(iVar2 + -0x10);
    *piVar3 = iVar5;
    *(int **)(iVar5 + 4) = piVar3;
    *(undefined4 *)(iVar2 + -0x14) = 0;
    *(undefined4 *)(iVar2 + -0x10) = 0;
  }
  goto switchD_01038e40_caseD_0;
LAB_01038f0a:
  FUN_01036904((uint *)&DAT_21004b78);
  iVar2 = iVar6;
  goto LAB_01038e26;
}


