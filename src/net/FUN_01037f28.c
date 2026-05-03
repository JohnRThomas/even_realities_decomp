/*
 * Function: FUN_01037f28
 * Entry:    01037f28
 * Prototype: undefined __stdcall FUN_01037f28(int * param_1)
 */


void FUN_01037f28(int *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar3;
  int iVar4;
  int extraout_r2;
  undefined4 extraout_r3;
  uint uVar5;
  undefined4 extraout_r3_00;
  undefined4 uVar6;
  
  FUN_01038898(param_1 + 6);
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
  if (bVar2) goto LAB_01037f5c;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01037f5c:
    FUN_01036904((uint *)&DAT_21004b68);
    iVar4 = (int)*(char *)((int)param_1 + 0xd);
    uVar3 = extraout_r1;
    if (iVar4 < 0) {
      uVar5 = *(byte *)((int)param_1 + 0xd) & 0x7f;
      *(char *)((int)param_1 + 0xd) = (char)uVar5;
      FUN_01037b1c(&DAT_21004b40,param_1,iVar4,uVar5);
      uVar3 = extraout_r1_00;
      iVar4 = extraout_r2;
    }
    piVar1 = DAT_21004b30;
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x10;
    FUN_01037734((uint)((int)piVar1 - (int)param_1 == 0),uVar3,iVar4,(int)piVar1 - (int)param_1);
    bVar2 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  if (DAT_21004b30 != param_1) {
    return;
  }
  iVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar4 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0103ba5c(iVar4);
  return;
}


