/*
 * Function: FUN_01025834
 * Entry:    01025834
 * Prototype: longlong __stdcall FUN_01025834(void)
 */


longlong FUN_01025834(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar2 = Peripherals::RTC0_NS.COUNTER;
  uVar3 = Peripherals::RTC0_NS.EVENTS_OVRFLW;
  uVar4 = DAT_21001c08;
  while (uVar3 != 0) {
    uVar4 = uVar4 + 1;
    Peripherals::RTC0_NS.EVENTS_OVRFLW = 0;
    uVar2 = Peripherals::RTC0_NS.COUNTER;
    uVar3 = Peripherals::RTC0_NS.EVENTS_OVRFLW;
  }
  if (iVar5 == 0) {
    enableIRQinterrupts();
  }
  DAT_21001c08 = uVar4;
  uVar3 = FUN_01024c40(uVar2);
  return (ulonglong)uVar4 * 512000000 + (ulonglong)uVar3;
}


