/*
 * Function: FUN_0102d7ac
 * Entry:    0102d7ac
 * Prototype: undefined __stdcall FUN_0102d7ac(void)
 */


void FUN_0102d7ac(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::IPC_NS.PUBLISH_RECEIVE_11_;
  Peripherals::IPC_NS.PUBLISH_RECEIVE_11_ = uVar1 & 0x7fffffff;
  Peripherals::RTC1_NS.EVENTS_COMPARE_3_ = 0;
  uVar1 = Peripherals::RTC1_NS.EVENTS_COMPARE_3_;
  return;
}


