/*
 * Function: FUN_01034490
 * Entry:    01034490
 * Prototype: undefined __stdcall FUN_01034490(void)
 */


void FUN_01034490(void)

{
  uint uVar1;
  
  Peripherals::EGU0_NS.EVENTS_TRIGGERED_6_ = 0;
  uVar1 = Peripherals::EGU0_NS.EVENTS_TRIGGERED_6_;
  uVar1 = DAT_2100645e | 0x80000000;
  Peripherals::TIMER2_NS.PUBLISH_COMPARE_1_ = uVar1;
  Peripherals::RADIO_NS.SUBSCRIBE_TXEN = uVar1;
  Peripherals::EGU0_NS.SUBSCRIBE_TRIGGER_6_ = DAT_2100645d | 0x80000000;
  Peripherals::DPPIC_NS.CHENSET = 1 << (uint)DAT_2100645e;
  return;
}


