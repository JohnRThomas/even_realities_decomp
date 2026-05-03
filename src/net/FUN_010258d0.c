/*
 * Function: FUN_010258d0
 * Entry:    010258d0
 * Prototype: uint __stdcall FUN_010258d0(uint param_1, undefined4 param_2, uint param_3)
 */


/* WARNING: Control flow encountered bad instruction data */

uint FUN_010258d0(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint *extraout_r1;
  uint *puVar2;
  uint uVar3;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar4;
  uint uVar5;
  uint extraout_r3;
  uint extraout_r3_00;
  uint uVar6;
  TIMER0_NS *unaff_r5;
  uint unaff_r6;
  
  uVar3 = param_3 & 0xffffff;
  if (param_1 < 4) {
    if ((DAT_21001c04 == -1 && DAT_21001c00 == -1) && (DAT_21001c0c == '\0')) {
      FUN_01025edc(0x6c,900,uVar3,&DAT_21001bf8);
      puVar2 = extraout_r1;
      uVar3 = extraout_r2;
      uVar4 = extraout_r3;
    }
    else {
      if (((char)DAT_21001bf8 == '\x02') && (3 < DAT_21001bf8._1_1_)) {
        do {
        } while ((&Peripherals::RTC0_NS.EVENTS_COMPARE_0_)[(byte)(DAT_21001bf8._1_1_ - 4)] == 0);
      }
      unaff_r5 = &Peripherals::TIMER0_NS;
      uVar4 = 1;
      unaff_r6 = 1 << (param_1 + 0x10 & 0xff);
      puVar2 = &Peripherals::TIMER0_NS.TASKS_START + param_1;
      Peripherals::TIMER0_NS.INTENCLR = unaff_r6;
      (&Peripherals::TIMER0_NS.TASKS_CAPTURE_0_)[param_1] = 1;
      if ((uVar3 - (&Peripherals::TIMER0_NS.CC_0_)[param_1] & 0xffffff) < 3) {
        (&Peripherals::TIMER0_NS.CC_0_)[param_1] = 0;
        return 0;
      }
    }
    puVar2[0x150] = uVar3;
    unaff_r5->INTENSET = unaff_r6;
    return uVar4;
  }
  uVar4 = param_1 - 4 & 0xff;
  if (uVar4 < 2) {
    if (((char)DAT_21001bf8 == '\0') || (uVar5 = (uint)DAT_21001bf8._1_1_, uVar5 != param_1)) {
      uVar6 = 0x10000 << uVar4;
      Peripherals::RTC0_NS.INTENCLR = uVar6;
      Peripherals::RTC0_NS.EVTENCLR = uVar6;
      (&Peripherals::RTC0_NS.EVENTS_COMPARE_0_)[uVar4] = 0;
      uVar5 = Peripherals::RTC0_NS.COUNTER;
      uVar1 = (uint)((uVar3 - uVar5 & 0xffffff) < 0x800001);
      if ((uVar3 - uVar5 & 0xfffffe) == 0) {
        uVar1 = 0;
      }
      if (uVar1 == 0) {
        return 0;
      }
      (&Peripherals::RTC0_NS.CC_0_)[uVar4] = uVar3;
      Peripherals::RTC0_NS.INTENSET = uVar6;
      Peripherals::RTC0_NS.EVTENSET = uVar6;
      return uVar1;
    }
  }
  else {
    FUN_01025edc(0x6c,0x3a7,uVar3,param_1 - 4);
    uVar3 = extraout_r2_00;
    uVar5 = extraout_r3_00;
  }
  FUN_01025edc(0x6c,0x3a3,uVar3,uVar5);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


