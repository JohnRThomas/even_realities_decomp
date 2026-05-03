/*
 * Function: FUN_010259ec
 * Entry:    010259ec
 * Prototype: ulonglong __stdcall FUN_010259ec(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_010259ec(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  uint uVar6;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined8 uVar7;
  
  if (param_1 < 4) {
    return CONCAT44(param_2,param_1 * 4 + 0x4100c140);
  }
  uVar1 = param_1 - 4 & 0xff;
  if (uVar1 < 2) {
    return CONCAT44(param_2,uVar1 * 4 + 0x41011140);
  }
  uVar7 = FUN_01025edc(0x6c,0x3cd,param_3,param_4);
  puVar3 = (undefined4 *)((ulonglong)uVar7 >> 0x20);
  *puVar3 = unaff_r6;
  uVar1 = ((int)(uint)uVar7 >> ((uint)uVar7 & 0xff)) >> 5;
  iVar4 = (int)(puVar3 + 1) >> (uVar1 & 0xff);
  if (uVar1 < 4) {
    return CONCAT44(iVar4,uVar1 * 4 + 0x4100c1c0);
  }
  uVar1 = uVar1 - 4 & 0xff;
  if (uVar1 < 2) {
    return CONCAT44(iVar4,uVar1 * 4 + 0x410111c0);
  }
  uVar7 = FUN_01025edc(0x6c,0x3cd,extraout_r2,extraout_r3);
  puVar3 = (undefined4 *)((ulonglong)uVar7 >> 0x20);
  *puVar3 = unaff_r6;
  puVar3[1] = unaff_r7;
  uVar1 = ((int)(uint)uVar7 >> ((uint)uVar7 & 0xff)) >> 7;
  if (uVar1 < 4) {
    uVar2 = uVar1 + 0x150;
    uVar5 = 1 << (uVar1 + 0x10 & 0xff);
    Peripherals::TIMER0_NS.INTENCLR = uVar5;
    (&Peripherals::TIMER0_NS.CC_0_)[uVar1] = 0;
    (&Peripherals::TIMER0_NS.EVENTS_COMPARE_0_)[uVar1] = 0;
  }
  else {
    uVar6 = uVar1 - 4 & 0xff;
    if (1 < uVar6) {
      FUN_01025edc(0x6c,0x430,extraout_r2_00,uVar6);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (((char)DAT_21001bf8 != '\0') && (DAT_21001bf8._1_1_ == uVar1)) {
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
    Peripherals::RTC0_NS.INTENCLR = 0x10000 << uVar6;
    Peripherals::RTC0_NS.EVTENCLR = 0x10000 << uVar6;
    uVar2 = Peripherals::RTC0_NS.COUNTER;
    uVar2 = (&Peripherals::RTC0_NS.CC_0_)[uVar6] - uVar2;
    uVar5 = 0;
    if ((uVar2 & 0xfffffe) != 0) {
      (&Peripherals::RTC0_NS.EVENTS_COMPARE_0_)[uVar6] = 0;
      return (ulonglong)uVar2;
    }
  }
  return CONCAT44(uVar5,uVar2);
}


