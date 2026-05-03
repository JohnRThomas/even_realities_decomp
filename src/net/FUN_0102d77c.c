/*
 * Function: FUN_0102d77c
 * Entry:    0102d77c
 * Prototype: undefined __stdcall FUN_0102d77c(void)
 */


void FUN_0102d77c(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_01031f94();
  FUN_0102fcac();
  FUN_01039ee2((byte *)"Failed to reboot: spinning endlessly...\n",extraout_r1,extraout_r2,
               extraout_r3);
  do {
    FUN_0102f17c();
  } while( true );
}


