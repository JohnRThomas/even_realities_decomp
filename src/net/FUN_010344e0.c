/*
 * Function: FUN_010344e0
 * Entry:    010344e0
 * Prototype: undefined __stdcall FUN_010344e0(void)
 */


void FUN_010344e0(void)

{
  Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_2100645e;
  Peripherals::TIMER2_NS.PUBLISH_COMPARE_1_ = 0;
  Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
  Peripherals::EGU0_NS.SUBSCRIBE_TRIGGER_6_ = 0;
  return;
}


