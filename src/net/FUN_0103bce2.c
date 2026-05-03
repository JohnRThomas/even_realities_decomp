/*
 * Function: FUN_0103bce2
 * Entry:    0103bce2
 * Prototype: undefined __stdcall FUN_0103bce2(int param_1)
 */


void FUN_0103bce2(int param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint *puVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return;
  }
  piVar4 = *(int **)(param_1 + -4);
  puVar5 = (uint *)(piVar4 + 5);
  iVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar6 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc(puVar5);
  if (bVar2) goto LAB_01036610;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01036610:
    FUN_01036904(puVar5);
    FUN_0102cc30(piVar4,param_1 + -4);
    iVar3 = FUN_0103ba90(piVar4 + 3);
    if (iVar3 != 0) break;
    bVar2 = FUN_010368e8(puVar5);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(iVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  FUN_010378f0(puVar5,iVar6);
  return;
}


