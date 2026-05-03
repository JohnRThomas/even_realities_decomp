/*
 * Function: FUN_01025a4c
 * Entry:    01025a4c
 * Prototype: undefined __stdcall FUN_01025a4c(uint param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025a4c(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 < 4) {
    Peripherals::TIMER0_NS.INTENCLR = 1 << (param_1 + 0x10 & 0xff);
    (&Peripherals::TIMER0_NS.CC_0_)[param_1] = 0;
    (&Peripherals::TIMER0_NS.EVENTS_COMPARE_0_)[param_1] = 0;
  }
  else {
    uVar2 = param_1 - 4 & 0xff;
    if (1 < uVar2) {
      FUN_01025edc(0x6c,0x430,param_3,uVar2);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (((char)DAT_21001bf8 != '\0') && (DAT_21001bf8._1_1_ == param_1)) {
      Peripherals::DPPIC_NS.CHENCLR = 6;
      if ((char)DAT_21001bf8 == '\x01') {
        _DAT_e000e180 = 0x1000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
        _DAT_e000e280 = 0x1000;
        Peripherals::TIMER0_NS.TASKS_STOP = 1;
        DAT_21001c0c = 0;
        Peripherals::TIMER0_NS.INTENCLR = 0xffffffff;
        Peripherals::TIMER0_NS.CC_0_ = 0;
        Peripherals::TIMER0_NS.EVENTS_COMPARE_0_ = 0;
        Peripherals::TIMER0_NS.CC_1_ = 0;
        Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
        Peripherals::TIMER0_NS.CC_2_ = 0;
        Peripherals::TIMER0_NS.EVENTS_COMPARE_2_ = 0;
        Peripherals::TIMER0_NS.CC_3_ = 0;
        Peripherals::TIMER0_NS.EVENTS_COMPARE_3_ = 0;
      }
      DAT_21001bf8._0_1_ = '\0';
      DAT_21001c00 = 0xffffffff;
      DAT_21001c04 = 0xffffffff;
    }
    Peripherals::RTC0_NS.INTENCLR = 0x10000 << uVar2;
    Peripherals::RTC0_NS.EVTENCLR = 0x10000 << uVar2;
    uVar1 = Peripherals::RTC0_NS.COUNTER;
    if (((&Peripherals::RTC0_NS.CC_0_)[uVar2] - uVar1 & 0xfffffe) != 0) {
      (&Peripherals::RTC0_NS.EVENTS_COMPARE_0_)[uVar2] = 0;
      return;
    }
  }
  return;
}


