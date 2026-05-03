/*
 * Function: FUN_010343b0
 * Entry:    010343b0
 * Prototype: undefined __stdcall FUN_010343b0(char param_1, int param_2)
 */


void FUN_010343b0(char param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << DAT_2100645b;
  Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_2100645c | uVar2;
  Peripherals::EGU0_NS.PUBLISH_TRIGGERED_6_ = 0;
  Peripherals::EGU0_NS.PUBLISH_TRIGGERED_7_ = 0;
  Peripherals::EGU0_NS.SUBSCRIBE_TRIGGER_7_ = 0;
  *(undefined4 *)((int)&Peripherals::RADIO_NS.SUBSCRIBE_TXEN + (uint)(byte)(param_1 << 2)) = 0;
  uVar1 = (uint)DAT_2100645a;
  *(undefined4 *)((int)&Peripherals::DPPIC_NS.SUBSCRIBE_CHG_0__EN + (uVar1 * 8 + 4 & 0xff)) = 0;
  Peripherals::EGU0_NS.SUBSCRIBE_TRIGGER_6_ = 0;
  (&Peripherals::DPPIC_NS.CHG_0_)[uVar1] = (&Peripherals::DPPIC_NS.CHG_0_)[uVar1] & ~uVar2;
  if (param_2 != 0) {
    Peripherals::TIMER2_NS.SUBSCRIBE_START = 0;
  }
  return;
}


