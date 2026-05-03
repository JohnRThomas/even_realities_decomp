/*
 * Function: FUN_01034560
 * Entry:    01034560
 * Prototype: undefined __stdcall FUN_01034560(void)
 */


void FUN_01034560(void)

{
  Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_21006460 | 1 << DAT_2100645f;
  Peripherals::RADIO_NS.PUBLISH_ADDRESS = 0;
  Peripherals::TIMER2_NS.PUBLISH_COMPARE_0_ = 0;
  Peripherals::TIMER2_NS.SUBSCRIBE_SHUTDOWN = 0;
  Peripherals::RADIO_NS.SUBSCRIBE_DISABLE = 0;
  return;
}


