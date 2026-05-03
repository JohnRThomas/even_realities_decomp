/*
 * Function: FUN_01025a1c
 * Entry:    01025a1c
 * Prototype: uint __stdcall FUN_01025a1c(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01025a1c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 extraout_r2;
  uint uVar4;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined8 uVar5;
  
  if (param_1 < 4) {
    return param_1 * 4 + 0x4100c1c0;
  }
  uVar1 = param_1 - 4 & 0xff;
  if (uVar1 < 2) {
    return uVar1 * 4 + 0x410111c0;
  }
  uVar5 = FUN_01025edc(0x6c,0x3cd,param_3,param_4);
  puVar3 = (undefined4 *)((ulonglong)uVar5 >> 0x20);
  *puVar3 = unaff_r6;
  puVar3[1] = unaff_r7;
  uVar1 = ((int)(uint)uVar5 >> ((uint)uVar5 & 0xff)) >> 7;
  if (uVar1 < 4) {
    uVar2 = uVar1 + 0x150;
    Peripherals::TIMER0_NS.INTENCLR = 1 << (uVar1 + 0x10 & 0xff);
    (&Peripherals::TIMER0_NS.CC_0_)[uVar1] = 0;
    (&Peripherals::TIMER0_NS.EVENTS_COMPARE_0_)[uVar1] = 0;
  }
  else {
    uVar4 = uVar1 - 4 & 0xff;
    if (1 < uVar4) {
      FUN_01025edc(0x6c,0x430,extraout_r2,uVar4);
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
    Peripherals::RTC0_NS.INTENCLR = 0x10000 << uVar4;
    Peripherals::RTC0_NS.EVTENCLR = 0x10000 << uVar4;
    uVar2 = Peripherals::RTC0_NS.COUNTER;
    uVar2 = (&Peripherals::RTC0_NS.CC_0_)[uVar4] - uVar2;
    if ((uVar2 & 0xfffffe) != 0) {
      (&Peripherals::RTC0_NS.EVENTS_COMPARE_0_)[uVar4] = 0;
      return uVar2;
    }
  }
  return uVar2;
}


