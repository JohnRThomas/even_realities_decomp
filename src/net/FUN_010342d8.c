/*
 * Function: FUN_010342d8
 * Entry:    010342d8
 * Prototype: undefined __stdcall FUN_010342d8(char param_1, int param_2)
 */


void FUN_010342d8(char param_1,int param_2)

{
  int extraout_r1;
  uint uVar1;
  uint extraout_r2;
  EGU0_NS *pEVar2;
  EGU0_NS *extraout_r3;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r12;
  uint uVar6;
  
  pEVar2 = &Peripherals::EGU0_NS;
  Peripherals::EGU0_NS.EVENTS_TRIGGERED_6_ = 0;
  uVar1 = Peripherals::EGU0_NS.EVENTS_TRIGGERED_6_;
  Peripherals::EGU0_NS.EVENTS_TRIGGERED_7_ = 0;
  uVar1 = Peripherals::EGU0_NS.EVENTS_TRIGGERED_7_;
  uVar5 = (uint)DAT_2100645c;
  uVar3 = uVar5 | 0x80000000;
  Peripherals::EGU0_NS.PUBLISH_TRIGGERED_6_ = uVar3;
  uVar6 = (uint)DAT_2100645b;
  uVar4 = uVar6 | 0x80000000;
  Peripherals::EGU0_NS.PUBLISH_TRIGGERED_7_ = uVar4;
  uVar1 = (uint)DAT_2100645a;
  (&Peripherals::DPPIC_NS.CHG_0_)[uVar1] = 1 << uVar6 | (&Peripherals::DPPIC_NS.CHG_0_)[uVar1];
  Peripherals::EGU0_NS.SUBSCRIBE_TRIGGER_7_ = uVar3;
  uVar1 = uVar1 * 8 + 4 & 0xff;
  *(uint *)((int)&Peripherals::RADIO_NS.SUBSCRIBE_TXEN + (uint)(byte)(param_1 << 2)) = uVar4;
  if (0x1f < uVar6) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_dppi.h",0x17d,&Peripherals::EGU0_NS);
    FUN_0103a370();
    param_2 = extraout_r1;
    uVar1 = extraout_r2;
    pEVar2 = extraout_r3;
    uVar5 = extraout_r12;
  }
  *(uint *)((int)&Peripherals::DPPIC_NS.SUBSCRIBE_CHG_0__EN + uVar1) = uVar4;
  pEVar2->SUBSCRIBE_TRIGGER_6_ = DAT_2100645d | 0x80000000;
  if (param_2 != 0) {
    Peripherals::TIMER2_NS.SUBSCRIBE_START = uVar3;
  }
  Peripherals::DPPIC_NS.CHENSET = 1 << (uVar5 & 0xff) | 1 << uVar6;
  return;
}


