/*
 * Function: FUN_01020d00
 * Entry:    01020d00
 * Prototype: undefined __stdcall FUN_01020d00(void)
 */


/* WARNING: Removing unreachable block (ram,0x01020dd2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020d00(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 uVar6;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar7;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  char local_11;
  
  FUN_010264c8();
  iVar3 = FUN_0102650c();
  uVar2 = Peripherals::RADIO_NS.INTENSET;
  Peripherals::RADIO_NS.INTENCLR = 0x10;
  Peripherals::RADIO_NS.SHORTS = 0x100000;
  Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
  Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
  Peripherals::RADIO_NS.SUBSCRIBE_START = 0;
  Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
  Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
  DAT_21001625 = 0;
  uVar1 = Peripherals::RADIO_NS.STATE;
  if ((uVar1 & 0xff) == 0) {
LAB_01020d4c:
    if (DAT_2100160c < 0x96) goto LAB_01020d5c;
    if (DAT_210015f9 != '\x01') {
      if (DAT_210015f9 != '\x02') goto LAB_01020d5c;
      goto LAB_01020e00;
    }
  }
  else {
    local_11 = -1;
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    do {
      uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
      if (uVar1 != 0) break;
      local_11 = local_11 + -1;
    } while (local_11 != '\0');
    if (local_11 != '\0') goto LAB_01020d4c;
    FUN_01009500(0x3e,0x840,&Peripherals::RADIO_NS,0);
LAB_01020e00:
    iVar4 = FUN_010220e4();
    if (iVar4 + 1U < 2) goto LAB_01020d5c;
    FUN_01009500(0x3e,0x857,extraout_r2,extraout_r3);
  }
  iVar4 = FUN_010220d8();
  if (iVar4 + 1U < 2) {
LAB_01020d5c:
    DAT_210015f7 = 0;
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    DAT_210015f9 = 0;
    if (DAT_21001634 != '\0') {
      Peripherals::RADIO_NS._428_4_ = 0;
      DAT_21001634 = '\0';
      uVar1 = Peripherals::RADIO_NS.PCNF0;
      Peripherals::RADIO_NS.PCNF0 = uVar1 & 0xfff0ffff;
      DAT_21001604 = DAT_21001604 & 0xfffffffc;
      Peripherals::RADIO_NS.DFEMODE = DAT_21001604;
      Peripherals::RADIO_NS.DFECTRL1 = 0x23280;
    }
    if ((uVar2 & 0x10) != 0) {
      Peripherals::RADIO_NS.INTENSET = 0x10;
    }
    if (iVar3 != 0) {
      Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    }
    if (DAT_21001636 != '\0') {
      Peripherals::RADIO_NS.TASKS_DISABLE = 1;
      DAT_21001636 = '\0';
    }
    return;
  }
  puVar5 = (undefined2 *)FUN_01009500(0x3e,0x851,extraout_r2_00,extraout_r3_00);
  *puVar5 = (short)puVar5;
  Peripherals::TIMER0_NS.CC_2_ = 0;
  Peripherals::TIMER0_NS.CC_1_ = 0;
  Peripherals::TIMER0_NS.CC_0_ = 0;
  Peripherals::TIMER0_NS.CC_3_ = 0;
  FUN_01020d00();
  if ((DAT_2100160c < 0x96) || (iVar3 = FUN_010220b4(), iVar3 + 1U < 2)) {
    if (DAT_21001635 != '\0') {
      iVar3 = FUN_010263bc();
      uVar6 = extraout_r2_01;
      uVar7 = extraout_r3_01;
      if (iVar3 != 0) goto LAB_01020f0e;
      DAT_21001635 = '\0';
    }
    iVar3 = FUN_010263d4();
    uVar6 = extraout_r2_02;
    uVar7 = extraout_r3_02;
    if (iVar3 == 0) {
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
    FUN_01009500(0x3e,0x4fc,extraout_r2_03,extraout_r3_03);
    uVar6 = extraout_r2_04;
    uVar7 = extraout_r3_04;
  }
  FUN_01009500(0x3e,0x515,uVar6,uVar7);
  uVar6 = extraout_r2_05;
  uVar7 = extraout_r3_05;
LAB_01020f0e:
  FUN_01009500(0x3e,0x512,uVar6,uVar7);
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  _MasterStackPointer = 0;
  FUN_0102649c(uVar2 & 0x10,0,extraout_r2_06,extraout_r3_06);
  return;
}


