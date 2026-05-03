/*
 * Function: FUN_01025884
 * Entry:    01025884
 * Prototype: longlong __stdcall FUN_01025884(void)
 */


longlong FUN_01025884(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar3 = Peripherals::RTC0_NS.COUNTER;
  uVar2 = Peripherals::RTC0_NS.EVENTS_OVRFLW;
  while (uVar2 != 0) {
    DAT_21001c08 = DAT_21001c08 + 1;
    Peripherals::RTC0_NS.EVENTS_OVRFLW = 0;
    uVar3 = Peripherals::RTC0_NS.COUNTER;
    uVar2 = Peripherals::RTC0_NS.EVENTS_OVRFLW;
  }
  if (iVar4 == 0) {
    enableIRQinterrupts();
  }
  return (ulonglong)DAT_21001c08 * 0x1000000 + (ulonglong)uVar3;
}


