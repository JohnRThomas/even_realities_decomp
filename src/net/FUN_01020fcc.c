/*
 * Function: FUN_01020fcc
 * Entry:    01020fcc
 * Prototype: undefined __stdcall FUN_01020fcc(uint param_1)
 */


void FUN_01020fcc(uint param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  int unaff_r6;
  
  if (param_1 <= DAT_21001614) {
    FUN_01009500(0x3e,0x8d1,&DAT_210015f0,DAT_21001614);
    puVar2 = (undefined2 *)((unaff_r6 >> 0x17) >> (unaff_r6 >> 0x17 & 0xffU));
    *puVar2 = (short)puVar2;
    DAT_210015fc = 2;
    if (DAT_21001619 == '\x01') {
      DAT_21001600 = FUN_01021e54((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608,
                                  (int)puVar2);
    }
    else {
      DAT_21001600 = FUN_01021e94((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608);
    }
    Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
    Peripherals::TIMER0_NS.CC_1_ = DAT_21001614 + DAT_21001600;
    return;
  }
  DAT_21001600 = param_1;
  Peripherals::TIMER0_NS.TASKS_CAPTURE_1_ = 1;
  uVar1 = Peripherals::TIMER0_NS.CC_1_;
  DAT_210015fc = 1;
  if (param_1 <= uVar1 + 5) {
    uVar1 = Peripherals::RADIO_NS.EVENTS_ADDRESS;
    if (uVar1 == 0) {
      Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    }
    return;
  }
  Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
  Peripherals::TIMER0_NS.CC_1_ = param_1;
  Peripherals::TIMER0_NS.PUBLISH_COMPARE_1_ = 0x8000000b;
  return;
}


