/*
 * Function: FUN_01025ba4
 * Entry:    01025ba4
 * Prototype: undefined __stdcall FUN_01025ba4(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025ba4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = Peripherals::RTC0_NS.INTENSET;
  if (((int)(uVar1 << 0xf) < 0) && (uVar1 = Peripherals::RTC0_NS.EVENTS_COMPARE_0_, uVar1 != 0)) {
    Peripherals::RTC0_NS.EVENTS_COMPARE_0_ = 0;
    uVar2 = Peripherals::RTC0_NS.CC_0_;
    uVar1 = Peripherals::RTC0_NS.COUNTER;
    uVar3 = uVar2 - uVar1 & 0xfffffe;
    if ((uVar3 == 0) || (0x800000 < (uVar2 - uVar1 & 0xffffff))) {
      Peripherals::RTC0_NS.INTENCLR = 0x10000;
      FUN_010242d8(4,uVar3,0x10000);
    }
  }
  uVar1 = Peripherals::RTC0_NS.INTENSET;
  if (((int)(uVar1 << 0xe) < 0) && (uVar1 = Peripherals::RTC0_NS.EVENTS_COMPARE_1_, uVar1 != 0)) {
    Peripherals::RTC0_NS.EVENTS_COMPARE_1_ = 0;
    uVar2 = Peripherals::RTC0_NS.CC_1_;
    uVar1 = Peripherals::RTC0_NS.COUNTER;
    uVar3 = uVar2 - uVar1 & 0xfffffe;
    if ((uVar3 == 0) || (0x800000 < (uVar2 - uVar1 & 0xffffff))) {
      Peripherals::RTC0_NS.INTENCLR = 0x20000;
      FUN_010242d8(5,uVar3,0x20000);
    }
  }
  uVar1 = Peripherals::RTC0_NS.EVENTS_OVRFLW;
  if (uVar1 != 0) {
    Peripherals::RTC0_NS.EVENTS_OVRFLW = 0;
    DAT_21001c08 = DAT_21001c08 + 1;
  }
  _DAT_e000e280 = 0x20000;
  return;
}


