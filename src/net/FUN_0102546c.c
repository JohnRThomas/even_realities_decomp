/*
 * Function: FUN_0102546c
 * Entry:    0102546c
 * Prototype: undefined __stdcall FUN_0102546c(uint param_1, int param_2)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x010255f2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102546c(uint param_1,int param_2)

{
  uint uVar1;
  undefined8 uVar2;
  RTC0_NS *pRVar3;
  RTC0_NS *pRVar4;
  RTC0_NS *extraout_r3;
  uint uVar5;
  undefined8 uVar6;
  
  uVar2 = CONCAT44(DAT_21001c04,DAT_21001c00);
  uVar6 = CONCAT44(param_2,param_1);
  uVar5 = (uint)(byte)DAT_21001bf8;
  if (uVar5 == 1) {
    if (DAT_21001c04 == param_2 && DAT_21001c00 == param_1) goto LAB_0102557e;
    Peripherals::DPPIC_NS.CHENCLR = 6;
LAB_01025594:
    pRVar3 = &Peripherals::RTC0_NS;
    Peripherals::RTC0_NS.EVTENCLR = 0x20000;
    Peripherals::RTC0_NS.INTENCLR = 0x20000;
    Peripherals::RTC0_NS.INTENCLR = 0x10000;
    Peripherals::RTC0_NS.EVTENCLR = 0x10000;
    Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
    uVar1 = Peripherals::RTC0_NS.COUNTER;
    pRVar4 = (RTC0_NS *)((param_1 & 0xffffff) - uVar1);
    if ((((uint)pRVar4 & 0xfffffe) == 0) ||
       (pRVar4 = (RTC0_NS *)((uint)pRVar4 & 0xffffff), (RTC0_NS *)0x800000 < pRVar4)) {
LAB_010254c4:
      uVar6 = FUN_01025edc(0x6c,0x30e,pRVar3,pRVar4);
      pRVar4 = extraout_r3;
      goto LAB_010254ce;
    }
    Peripherals::RTC0_NS.CC_0_ = param_1 & 0xffffff;
    Peripherals::RTC0_NS.EVTENSET = 0x10000;
    if (uVar5 != 0) {
      do {
        uVar5 = Peripherals::RTC0_NS.COUNTER;
      } while ((DAT_21001c00 - uVar5 & 0xfffffe) == 0);
    }
  }
  else {
    Peripherals::DPPIC_NS.CHENCLR = 6;
    if (uVar5 != 0) goto LAB_01025594;
    pRVar4 = &Peripherals::RTC0_NS;
    Peripherals::RTC0_NS.EVTENCLR = 0x30000;
    Peripherals::RTC0_NS.INTENCLR = 0x30000;
    Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
    Peripherals::RTC0_NS.INTENCLR = 0x10000;
    Peripherals::RTC0_NS.EVTENCLR = 0x10000;
    Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
    uVar5 = param_1 & 0xffffff;
    uVar1 = Peripherals::RTC0_NS.COUNTER;
    pRVar3 = (RTC0_NS *)(uVar5 - uVar1);
    if ((((uint)pRVar3 & 0xfffffe) == 0) ||
       (pRVar3 = (RTC0_NS *)((uint)pRVar3 & 0xffffff), (RTC0_NS *)0x800000 < pRVar3))
    goto LAB_010254c4;
LAB_010254ce:
    pRVar4->CC_0_ = uVar5;
    pRVar4->EVTENSET = 0x10000;
  }
  DAT_21001c14 = 1;
  DAT_21001bfa = 0;
  _DAT_e000e180 = 0x1000;
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
  uVar5 = Peripherals::TIMER0_NS.MODE;
  Peripherals::TIMER0_NS.MODE = uVar5 & 0xfffffffc;
  uVar5 = Peripherals::TIMER0_NS.BITMODE;
  Peripherals::TIMER0_NS.BITMODE = uVar5 & 0xfffffffc | 2;
  Peripherals::TIMER0_NS.PRESCALER = 4;
  Peripherals::TIMER0_NS.TASKS_CLEAR = 1;
  Peripherals::TIMER0_NS.SHORTS = 1;
  _DAT_e000e280 = 0x1000;
  _DAT_e000e100 = 0x1000;
  Peripherals::RTC0_NS.PUBLISH_COMPARE_0_ = 0x80000002;
  Peripherals::TIMER0_NS.SUBSCRIBE_START = 0x80000002;
  Peripherals::DPPIC_NS.CHENSET = 4;
  DAT_21001bf8 = 0x401;
  uVar2 = uVar6;
LAB_0102557e:
  DAT_21001c04 = (int)((ulonglong)uVar2 >> 0x20);
  DAT_21001c00 = (uint)uVar2;
  return;
}


