/*
 * Function: FUN_0100af18
 * Entry:    0100af18
 * Prototype: undefined __stdcall FUN_0100af18(void)
 */


void FUN_0100af18(void)

{
  Peripherals::ECB_NS.TASKS_STOPECB = 1;
  Peripherals::ECB_NS.INTENCLR = 0xffffffff;
  Peripherals::AAR_NS.TASKS_STOP = 1;
  Peripherals::AAR_NS._512_4_ = 0;
  Peripherals::AAR_NS.INTENCLR = 0xffffffff;
  Peripherals::AAR_NS.ENABLE = 0;
  Peripherals::AAR_NS.NIRK = 1;
  Peripherals::AAR_NS.TASKS_STOP = 1;
  Peripherals::AAR_NS.INTENCLR = 0xffffffff;
  Peripherals::AAR_NS.ENABLE = 0;
  Peripherals::AAR_NS.NIRK = 1;
  Peripherals::DPPIC_NS.CHENCLR = 0x1ff8;
  return;
}


