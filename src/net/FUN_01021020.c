/*
 * Function: FUN_01021020
 * Entry:    01021020
 * Prototype: undefined __stdcall FUN_01021020(int param_1)
 */


void FUN_01021020(int param_1)

{
  DAT_210015fc = 2;
  if (DAT_21001619 == '\x01') {
    DAT_21001600 = FUN_01021e54((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608,param_1);
  }
  else {
    DAT_21001600 = FUN_01021e94((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608);
  }
  Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
  Peripherals::TIMER0_NS.CC_1_ = DAT_21001614 + DAT_21001600;
  return;
}


