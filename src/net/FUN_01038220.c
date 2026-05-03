/*
 * Function: FUN_01038220
 * Entry:    01038220
 * Prototype: undefined __stdcall FUN_01038220(void)
 */


void FUN_01038220(void)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  undefined4 extraout_r2;
  int *piVar4;
  uint uVar5;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 unaff_r6;
  
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getCurrentExceptionNumber();
    uVar5 = uVar5 & 0x1f;
  }
  if (uVar5 == 0) {
    unaff_r6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      unaff_r6 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
    if (bVar2) goto LAB_01038266;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
  }
  else {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x57a,uVar5)
    ;
  }
  do {
    while( true ) {
      FUN_0103a370();
LAB_01038266:
      FUN_01036904((uint *)&DAT_21004b68);
      piVar1 = DAT_21004b30;
      uVar5 = *(byte *)((int)DAT_21004b30 + 0xd) & 0x7f;
      *(char *)((int)DAT_21004b30 + 0xd) = (char)uVar5;
      FUN_01037b1c(&DAT_21004b40,piVar1,extraout_r2,uVar5);
      piVar1 = DAT_21004b30;
      *(byte *)((int)DAT_21004b30 + 0xd) = *(byte *)((int)DAT_21004b30 + 0xd) | 0x80;
      piVar3 = DAT_21004b44;
      if (piVar1 != (int *)&DAT_210043a8) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0xc1,
                   &DAT_210043a8);
    }
    piVar4 = DAT_21004b40;
    if ((int **)DAT_21004b40 == &DAT_21004b40) {
      piVar4 = (int *)0x0;
    }
    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      if ((*(char *)((int)piVar1 + 0xe) != *(char *)((int)piVar4 + 0xe)) &&
         (*(char *)((int)piVar1 + 0xe) < *(char *)((int)piVar4 + 0xe))) {
        piVar3 = (int *)piVar4[1];
        *piVar1 = (int)piVar4;
        piVar1[1] = (int)piVar3;
        *piVar3 = (int)piVar1;
        piVar4[1] = (int)piVar1;
        goto LAB_010382d0;
      }
      if (piVar4 == DAT_21004b44) break;
    }
    *piVar1 = (int)&DAT_21004b40;
    piVar1[1] = (int)DAT_21004b44;
    *DAT_21004b44 = (int)piVar1;
    DAT_21004b44 = piVar1;
LAB_010382d0:
    FUN_01037734(1,piVar3,piVar4,piVar1);
    bVar2 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar2) {
      FUN_0102f3d0(unaff_r6);
      return;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x111,extraout_r3_00);
  } while( true );
}


