/*
 * Function: FUN_010256f0
 * Entry:    010256f0
 * Prototype: undefined __stdcall FUN_010256f0(void)
 */


void FUN_010256f0(void)

{
  bool bVar1;
  longlong lVar2;
  RTC0_NS *pRVar3;
  RTC0_NS *extraout_r2;
  uint uVar4;
  uint extraout_r3;
  uint uVar5;
  int iVar6;
  
  pRVar3 = &Peripherals::RTC0_NS;
  uVar4 = (uint)(byte)DAT_21001bf8;
  if (uVar4 != 0) goto LAB_01025714;
  Peripherals::RTC0_NS.EVTENCLR = 0x30000;
  Peripherals::RTC0_NS.INTENCLR = 0x30000;
  Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
  do {
    FUN_01025edc(0x6c,0x337,pRVar3,uVar4);
    pRVar3 = extraout_r2;
    uVar4 = extraout_r3;
LAB_01025714:
    pRVar3->EVTENCLR = 0x20000;
    pRVar3->INTENCLR = 0x20000;
  } while (uVar4 != 2);
  iVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar4 = pRVar3->COUNTER;
  uVar5 = pRVar3->EVENTS_OVRFLW;
  while (uVar5 != 0) {
    DAT_21001c08 = DAT_21001c08 + 1;
    pRVar3->EVENTS_OVRFLW = 0;
    uVar4 = pRVar3->COUNTER;
    uVar5 = pRVar3->EVENTS_OVRFLW;
  }
  if (iVar6 == 0) {
    enableIRQinterrupts();
  }
  lVar2 = (ulonglong)DAT_21001c08 * 0x1000000 + 3 + (ulonglong)uVar4;
  uVar4 = (uint)lVar2;
  if (lVar2 != CONCAT44(DAT_21001c04,DAT_21001c00)) {
    uVar5 = Peripherals::RTC0_NS.COUNTER;
    uVar4 = DAT_21001c00;
    if (((DAT_21001c00 - uVar5 & 0xfffffc) != 0) && ((DAT_21001c00 - uVar5 & 0xffffff) < 0x800001))
    {
      FUN_0102546c((uint)lVar2,(int)((ulonglong)lVar2 >> 0x20));
      Peripherals::TIMER0_NS.SHORTS = DAT_21001c14;
      return;
    }
  }
  uVar5 = Peripherals::RTC0_NS.COUNTER;
  if (((uVar4 - uVar5 & 0xfffffe) != 0) && ((uVar4 - uVar5 & 0xffffff) < 0x800001)) {
    Peripherals::DPPIC_NS.CHENCLR = 2;
    DAT_21001c14 = 1;
    DAT_21001bfa = 0;
    Peripherals::TIMER0_NS.TASKS_STOP = 1;
    Peripherals::TIMER0_NS.TASKS_CLEAR = 1;
    Peripherals::RTC0_NS.PUBLISH_COMPARE_0_ = 0x80000002;
    Peripherals::TIMER0_NS.SUBSCRIBE_START = 0x80000002;
    Peripherals::DPPIC_NS.CHENSET = 4;
    DAT_21001bf8 = 0x401;
    Peripherals::TIMER0_NS.SHORTS = 1;
    return;
  }
  DAT_21001c14 = 1;
  DAT_21001bfa = 0;
  Peripherals::TIMER0_NS.SHORTS = 1;
  return;
}


