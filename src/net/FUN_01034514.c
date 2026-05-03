/*
 * Function: FUN_01034514
 * Entry:    01034514
 * Prototype: undefined __stdcall FUN_01034514(void)
 */


void FUN_01034514(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_21006460 | 0x80000000;
  Peripherals::RADIO_NS.PUBLISH_ADDRESS = uVar2;
  uVar1 = DAT_2100645f | 0x80000000;
  Peripherals::TIMER2_NS.PUBLISH_COMPARE_0_ = uVar1;
  Peripherals::TIMER2_NS.SUBSCRIBE_SHUTDOWN = uVar2;
  Peripherals::RADIO_NS.SUBSCRIBE_DISABLE = uVar1;
  Peripherals::DPPIC_NS.CHENSET = 1 << (uint)DAT_21006460 | 1 << (uint)DAT_2100645f;
  return;
}


