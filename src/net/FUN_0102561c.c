/*
 * Function: FUN_0102561c
 * Entry:    0102561c
 * Prototype: undefined __stdcall FUN_0102561c(uint param_1, int param_2, undefined4 param_3)
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0102561c(uint param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  RTC0_NS *pRVar2;
  RTC0_NS *extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar3;
  int extraout_r3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_r12;
  uint uVar7;
  undefined8 uVar8;
  
  uVar1 = DAT_21001c00;
  uVar8 = CONCAT44(param_2,param_1);
  uVar6 = (uint)(byte)DAT_21001bf8;
  if (uVar6 == 2) {
    if (DAT_21001c04 == param_2 && DAT_21001c00 == param_1) {
      return;
    }
  }
  else {
    iVar4 = DAT_21001c04;
    if (DAT_21001c04 == param_2 && DAT_21001c00 == param_1) goto LAB_010256cc;
  }
  if (DAT_21001c0c != '\0') {
    pRVar2 = &Peripherals::RTC0_NS;
    Peripherals::DPPIC_NS.CHENCLR = 6;
    Peripherals::RTC0_NS.INTENCLR = 0x10000;
    uVar7 = param_1 & 0xffffff;
    Peripherals::RTC0_NS.EVTENCLR = 0x10000;
    Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
    uVar3 = Peripherals::RTC0_NS.COUNTER;
    uVar3 = uVar7 - uVar3;
    uVar5 = uVar3 & 0xffffff;
    if ((0x800000 < uVar5) || (uVar5 = 0xfffffe, (uVar3 & 0xfffffe) == 0)) {
      uVar7 = 0x102567f;
      uVar8 = FUN_01025edc(0x6c,0x32c,&Peripherals::RTC0_NS,uVar3);
      pRVar2 = extraout_r2;
      uVar6 = extraout_r12;
    }
    pRVar2->CC_0_ = uVar7;
    pRVar2->EVTENSET = 0x10000;
    if (uVar6 != 0) {
      do {
      } while ((uVar1 - pRVar2->COUNTER & uVar5) == 0);
    }
    DAT_21001c00 = (int)uVar8;
    DAT_21001c04 = (int)((ulonglong)uVar8 >> 0x20);
    Peripherals::RTC0_NS.PUBLISH_COMPARE_0_ = 0x80000001;
    Peripherals::TIMER0_NS.SUBSCRIBE_CLEAR = 0x80000001;
    Peripherals::DPPIC_NS.CHENSET = 2;
    DAT_21001bf8 = 0x402;
    return;
  }
  FUN_01025edc(0x6c,800,param_3,0);
  param_3 = extraout_r2_00;
  iVar4 = extraout_r3;
LAB_010256cc:
  FUN_01025edc(0x6c,0x31c,param_3,iVar4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


