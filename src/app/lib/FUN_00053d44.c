/*
 * Function: FUN_00053d44
 * Entry:    00053d44
 * Prototype: undefined __stdcall FUN_00053d44(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void FUN_00053d44(void)

{
  bool bVar1;
  char cVar2;
  undefined8 extraout_d0;
  undefined8 extraout_d4;
  undefined8 unaff_d14;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setThreadModePrivileged(1);
    bVar1 = (bool)isThreadMode();
    if (bVar1) {
      cVar2 = isUsingMainStack();
      setStackMode(cVar2 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  setMainStackPointerLimit(0);
  setProcStackPointerLimit(0);
  z_arm_reset();
  _DAT_e000ed94 = 0;
  DataSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(&DAT_20031868);
  }
  z_arm_prep_c();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(0x2002d728);
  }
  cVar2 = isThreadModePrivileged();
  isUsingMainStack();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setThreadModePrivileged(cVar2 == '\x01');
    bVar1 = (bool)isThreadMode();
    if (bVar1) {
      cVar2 = isUsingMainStack();
      setStackMode(cVar2 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  z_arm_prep_c();
  vcx3(5,2,unaff_d14,extraout_d4,extraout_d0,0,0x40,0);
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


