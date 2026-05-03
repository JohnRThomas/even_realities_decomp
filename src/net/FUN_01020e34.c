/*
 * Function: FUN_01020e34
 * Entry:    01020e34
 * Prototype: undefined __stdcall FUN_01020e34(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020e34(void)

{
  int iVar1;
  short *psVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar3;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar4;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  int unaff_r6;
  
  Peripherals::TIMER0_NS.CC_2_ = 0;
  Peripherals::TIMER0_NS.CC_1_ = 0;
  Peripherals::TIMER0_NS.CC_0_ = 0;
  Peripherals::TIMER0_NS.CC_3_ = 0;
  FUN_01020d00();
  if ((DAT_2100160c < 0x96) || (iVar1 = FUN_010220b4(), iVar1 + 1U < 2)) {
    if (DAT_21001635 != '\0') {
      iVar1 = FUN_010263bc();
      uVar3 = extraout_r2;
      uVar4 = extraout_r3;
      if (iVar1 != 0) goto LAB_01020f0e;
      DAT_21001635 = '\0';
    }
    iVar1 = FUN_010263d4();
    uVar3 = extraout_r2_00;
    uVar4 = extraout_r3_00;
    if (iVar1 == 0) {
      Peripherals::DPPIC_NS.CHENCLR = 0x1df8;
      Peripherals::TIMER0_NS.PUBLISH_COMPARE_1_ = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_START = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
      Peripherals::TIMER0_NS.SUBSCRIBE_CAPTURE_2_ = 0;
      Peripherals::TIMER0_NS.SUBSCRIBE_CAPTURE_1_ = 0;
      FUN_0102638c();
      Peripherals::RADIO_NS.PUBLISH_BCMATCH = 0;
      Peripherals::TIMER0_NS.PUBLISH_COMPARE_0_ = 0;
      DAT_210015fc = 0;
      Peripherals::TIMER0_NS.CC_2_ = 0;
      DAT_21001610 = 0;
      DAT_21001614 = 0;
      Peripherals::TIMER0_NS.CC_1_ = 0;
      Peripherals::TIMER0_NS.CC_0_ = 0;
      Peripherals::TIMER0_NS.CC_3_ = 0;
      Peripherals::TIMER0_NS.EVENTS_COMPARE_2_ = 0;
      Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
      Peripherals::TIMER0_NS.EVENTS_COMPARE_0_ = 0;
      Peripherals::TIMER0_NS.EVENTS_COMPARE_3_ = 0;
      _DAT_e000e180 = 0x100;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      _DAT_e000e280 = 0x100;
      return;
    }
  }
  else {
    FUN_01009500(0x3e,0x4fc,extraout_r2_01,extraout_r3_01);
    uVar3 = extraout_r2_02;
    uVar4 = extraout_r3_02;
  }
  FUN_01009500(0x3e,0x515,uVar3,uVar4);
  uVar3 = extraout_r2_03;
  uVar4 = extraout_r3_03;
LAB_01020f0e:
  FUN_01009500(0x3e,0x512,uVar3,uVar4);
  psVar2 = (short *)(unaff_r6 >> 0x17);
  *psVar2 = (short)(unaff_r6 >> 0x17);
  FUN_0102649c(unaff_r6,((int)psVar2 >> ((uint)psVar2 & 0xff) & 0x80000000U) >> 5,extraout_r2_04,
               extraout_r3_04);
  return;
}


