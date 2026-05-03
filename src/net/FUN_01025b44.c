/*
 * Function: FUN_01025b44
 * Entry:    01025b44
 * Prototype: undefined __stdcall FUN_01025b44(void)
 */


void FUN_01025b44(void)

{
  if ((char)DAT_21001bf8 == '\0') {
    Peripherals::RTC0_NS.EVTENCLR = 0x30000;
    Peripherals::RTC0_NS.INTENCLR = 0x30000;
    Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
  }
  else {
    Peripherals::RTC0_NS.EVTENCLR = 0x20000;
    Peripherals::RTC0_NS.INTENCLR = 0x20000;
  }
  Peripherals::TIMER0_NS.INTENCLR = 0xffffffff;
  Peripherals::TIMER0_NS.CC_0_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_0_ = 0;
  Peripherals::TIMER0_NS.CC_1_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
  Peripherals::TIMER0_NS.CC_2_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_2_ = 0;
  Peripherals::TIMER0_NS.CC_3_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_3_ = 0;
  return;
}


