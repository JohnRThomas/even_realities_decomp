/*
 * Function: FUN_01034434
 * Entry:    01034434
 * Prototype: undefined __stdcall FUN_01034434(void)
 */


void FUN_01034434(void)

{
  uint uVar1;
  
  uVar1 = DAT_2100645c | 0x80000000;
  Peripherals::EGU0_NS.PUBLISH_TRIGGERED_6_ = uVar1;
  Peripherals::TIMER2_NS.SUBSCRIBE_START = uVar1;
  Peripherals::DPPIC_NS.CHENSET = 1 << (uint)DAT_2100645c;
  return;
}


