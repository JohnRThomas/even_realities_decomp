/*
 * Function: FUN_010379dc
 * Entry:    010379dc
 * Prototype: undefined __stdcall FUN_010379dc(void)
 */


void FUN_010379dc(void)

{
  bool bVar1;
  undefined4 extraout_r3;
  uint uVar2;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = FUN_010368cc((uint *)&DAT_21004b68);
  if (bVar1) {
    FUN_01036904((uint *)&DAT_21004b68);
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1f;
    }
    if (uVar2 == 0) goto LAB_01037a24;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/include/ksched.h",
                 0xfd,uVar2);
  }
  else {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
  }
  while( true ) {
    while( true ) {
      FUN_0103a370();
LAB_01037a24:
      if (*(char *)(DAT_21004b30 + 0xf) != '\x01') break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/include/ksched.h",
                   0xfe,1);
    }
    *(char *)(DAT_21004b30 + 0xf) = *(char *)(DAT_21004b30 + 0xf) + -1;
    bVar1 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar1) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


