/*
 * Function: FUN_01038a44
 * Entry:    01038a44
 * Prototype: undefined8 __stdcall FUN_01038a44(void)
 */


undefined8 FUN_01038a44(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = FUN_010368cc((uint *)&DAT_21004b70);
  if (bVar1) goto LAB_01038a70;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01038a70:
    FUN_01036904((uint *)&DAT_21004b70);
    uVar2 = FUN_010386c0();
    iVar3 = uVar2 + DAT_210044f0;
    iVar4 = DAT_210044f4 + ((int)uVar2 >> 0x1f) + (uint)CARRY4(uVar2,DAT_210044f0);
    bVar1 = FUN_010368e8((uint *)&DAT_21004b70);
    if (bVar1) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(iVar4,iVar3);
}


