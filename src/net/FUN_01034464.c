/*
 * Function: FUN_01034464
 * Entry:    01034464
 * Prototype: undefined __stdcall FUN_01034464(void)
 */


void FUN_01034464(void)

{
  Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_2100645c;
  Peripherals::EGU0_NS.PUBLISH_TRIGGERED_6_ = 0;
  Peripherals::TIMER2_NS.SUBSCRIBE_START = 0;
  return;
}


