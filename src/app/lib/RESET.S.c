/*
 * Function: RESET.S
 * Entry:    00053d56
 * Prototype: undefined __stdcall RESET.S(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void RESET_S(void)

{
  char cVar1;
  bool bVar2;
  undefined8 extraout_d0;
  undefined8 extraout_d4;
  undefined8 unaff_d14;
  
  z_arm_reset();
  _DAT_e000ed94 = 0;
  DataSynchronizationBarrier(0xf);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setMainStackPointer(&DAT_20031868);
  }
  z_arm_prep_c();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x20);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setProcessStackPointer(0x2002d728);
  }
  cVar1 = isThreadModePrivileged();
  isUsingMainStack();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(cVar1 == '\x01');
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar1 = isUsingMainStack();
      setStackMode(cVar1 == '\x01');
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


