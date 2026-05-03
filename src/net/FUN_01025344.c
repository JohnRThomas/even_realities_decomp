/*
 * Function: FUN_01025344
 * Entry:    01025344
 * Prototype: undefined __stdcall FUN_01025344(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025344(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_21001c10;
  DAT_21001bf8._0_1_ = 0;
  DAT_21001c08 = 0;
  DAT_21001bfa = 0xff;
  DAT_21001c00 = 0xffffffff;
  DAT_21001c04 = 0xffffffff;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  DAT_21001c0c = 0;
  Peripherals::TIMER0_NS.TASKS_STOP = 1;
  Peripherals::TIMER0_NS.INTENCLR = 0xffffffff;
  Peripherals::TIMER0_NS.CC_0_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_0_ = 0;
  Peripherals::TIMER0_NS.CC_1_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
  Peripherals::TIMER0_NS.CC_2_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_2_ = 0;
  Peripherals::TIMER0_NS.CC_3_ = 0;
  Peripherals::TIMER0_NS.EVENTS_COMPARE_3_ = 0;
  _DAT_e000e180 = 0x20000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000e280 = 0x20000;
  Peripherals::RTC0_NS.TASKS_STOP = 1;
  Peripherals::RTC0_NS.TASKS_CLEAR = 1;
  do {
    uVar1 = Peripherals::RTC0_NS.COUNTER;
  } while (uVar1 != 0);
  Peripherals::RTC0_NS.INTENCLR = 0x30002;
  Peripherals::RTC0_NS.EVTENCLR = 0x30002;
  Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
  Peripherals::RTC0_NS.EVENTS_COMPARE_1_ = 0;
  Peripherals::RTC0_NS.EVENTS_OVRFLW = 0;
  _DAT_e000e100 = 0x20000;
  if (DAT_21001c10 == 0) {
    Peripherals::RTC0_NS.TASKS_START = 1;
  }
  else {
    Peripherals::TIMER0_NS.PUBLISH_COMPARE_0_ = 0x80000000;
    *(undefined4 *)(DAT_21001c10 + 0x80) = 0x80000000;
    Peripherals::RTC0_NS.SUBSCRIBE_START = 0x80000000;
    Peripherals::DPPIC_NS.CHENSET = 1;
    Peripherals::TIMER0_NS.CC_0_ = 5;
    Peripherals::TIMER0_NS.TASKS_START = 1;
    do {
      uVar1 = Peripherals::TIMER0_NS.EVENTS_COMPARE_0_;
    } while (uVar1 == 0);
    Peripherals::DPPIC_NS.CHENCLR = 1;
    Peripherals::TIMER0_NS.TASKS_STOP = 1;
    Peripherals::TIMER0_NS.TASKS_CLEAR = 1;
    Peripherals::TIMER0_NS.EVENTS_COMPARE_0_ = 0;
    Peripherals::TIMER0_NS.CC_0_ = 0;
    Peripherals::TIMER0_NS.PUBLISH_COMPARE_0_ = 0;
    *(undefined4 *)(iVar2 + 0x80) = 0;
    Peripherals::RTC0_NS.SUBSCRIBE_START = 0;
  }
  Peripherals::RTC0_NS.EVTENSET = 0x104;
  Peripherals::RTC0_NS.INTENSET = 2;
  return;
}


