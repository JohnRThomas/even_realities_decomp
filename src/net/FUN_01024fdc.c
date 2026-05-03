/*
 * Function: FUN_01024fdc
 * Entry:    01024fdc
 * Prototype: undefined __stdcall FUN_01024fdc(void)
 */


void FUN_01024fdc(void)

{
  bool bVar1;
  int iVar2;
  
  if ((DAT_21001bec == '\0') && (bVar1 = FUN_01025320((byte)DAT_21001bf0 & 3), bVar1)) {
    iVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar2 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if (DAT_21001bdd == '\0') {
      DAT_21001bdd = '\x01';
      if (iVar2 == 0) {
        enableIRQinterrupts();
      }
      Peripherals::CLOCK_NS.INTENCLR = 0x80;
      Peripherals::CLOCK_NS.EVENTS_DONE = 0;
      DAT_21001bf4 = 0;
      FUN_01024f44();
      Peripherals::CLOCK_NS.INTENSET = 0x80;
    }
    else if (iVar2 == 0) {
      enableIRQinterrupts();
    }
  }
  return;
}


