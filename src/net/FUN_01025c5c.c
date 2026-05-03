/*
 * Function: FUN_01025c5c
 * Entry:    01025c5c
 * Prototype: uint __stdcall FUN_01025c5c(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01025c5c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int extraout_r3;
  int iVar4;
  int unaff_r5;
  int unaff_r6;
  
  if (DAT_21001bfa == -1) {
    uVar3 = FUN_010242d8(6,param_2,param_3);
    return uVar3;
  }
  if ((char)DAT_21001bf8 != '\0') {
    cVar2 = (char)DAT_21001bf8;
    if (((char)DAT_21001bf8 != '\x01') && (cVar2 = DAT_21001c0c, DAT_21001c0c == '\0')) {
      FUN_01025edc(0x6c,0x48d,param_3,0);
      iVar4 = extraout_r3;
      while (iVar4 == 0) {
        FUN_0102aa1e();
        iVar4 = *(int *)(unaff_r5 + 0x100);
      }
      if (unaff_r6 == 0) {
        DAT_21001c08 = DAT_21001c08 & 0xffffffef;
      }
      uVar3 = Peripherals::TEMP_NS.TEMP;
      Peripherals::TEMP_NS.TASKS_STOP = 1;
      Peripherals::TEMP_NS.INTENCLR = 1;
      Peripherals::TEMP_NS.EVENTS_DATARDY = 0;
      _DAT_e000e280 = 0x10000;
      return uVar3;
    }
    DAT_21001c0c = cVar2;
    DAT_21001bf8._0_1_ = '\x02';
    FUN_01025a4c((uint)DAT_21001bf8._1_1_,param_2,param_3);
  }
  uVar3 = Peripherals::TIMER0_NS.INTENSET;
  if (((int)(uVar3 << 0xc) < 0) && (uVar3 = Peripherals::TIMER0_NS.EVENTS_COMPARE_3_, uVar3 != 0)) {
    Peripherals::TIMER0_NS.INTENCLR = 0x80000;
    Peripherals::TIMER0_NS.CC_3_ = 0;
    Peripherals::TIMER0_NS.EVENTS_COMPARE_3_ = 0;
    _DAT_e000e280 = 0x1000;
    FUN_010242d8(3,&DAT_e000e100,0);
    uVar3 = Peripherals::TIMER0_NS.INTENSET;
  }
  else {
    uVar3 = Peripherals::TIMER0_NS.INTENSET;
  }
  uVar3 = uVar3 << 0xd;
  if (((int)uVar3 < 0) && (uVar1 = Peripherals::TIMER0_NS.EVENTS_COMPARE_2_, uVar1 != 0)) {
    Peripherals::TIMER0_NS.INTENCLR = 0x40000;
    Peripherals::TIMER0_NS.CC_2_ = 0;
    Peripherals::TIMER0_NS.EVENTS_COMPARE_2_ = 0;
    _DAT_e000e280 = 0x1000;
    uVar3 = FUN_010242d8(2,&DAT_e000e100,0);
    uVar1 = Peripherals::TIMER0_NS.INTENSET;
  }
  else {
    uVar1 = Peripherals::TIMER0_NS.INTENSET;
  }
  if (((int)(uVar1 << 0xe) < 0) && (uVar1 = Peripherals::TIMER0_NS.EVENTS_COMPARE_1_, uVar1 != 0)) {
    Peripherals::TIMER0_NS.INTENCLR = 0x20000;
    Peripherals::TIMER0_NS.CC_1_ = 0;
    Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
    _DAT_e000e280 = 0x1000;
    uVar3 = FUN_010242d8(1,&DAT_e000e100,0);
    uVar1 = Peripherals::TIMER0_NS.INTENSET;
  }
  else {
    uVar1 = Peripherals::TIMER0_NS.INTENSET;
  }
  if (((int)(uVar1 << 0xf) < 0) && (uVar1 = Peripherals::TIMER0_NS.EVENTS_COMPARE_0_, uVar1 != 0)) {
    Peripherals::TIMER0_NS.INTENCLR = 0x10000;
    Peripherals::TIMER0_NS.CC_0_ = 0;
    Peripherals::TIMER0_NS.EVENTS_COMPARE_0_ = 0;
    DAT_21001c14 = 0;
    _DAT_e000e280 = 0x1000;
    DAT_21001bfa = 0xff;
    Peripherals::TIMER0_NS.SHORTS = 0;
    uVar3 = FUN_010242d8(0,0x1000,0xff);
    return uVar3;
  }
  return uVar3;
}


