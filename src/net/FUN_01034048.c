/*
 * Function: FUN_01034048
 * Entry:    01034048
 * Prototype: undefined4 __stdcall FUN_01034048(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01034048(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint extraout_r3;
  
  if (DAT_21006458 == '\0') {
    Peripherals::RADIO_NS.INTENCLR = 0xffffffff;
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    uVar2 = Peripherals::RADIO_NS.EVENTS_DISABLED;
    DAT_210049a0 = 0x1033615;
    Peripherals::RADIO_NS.SHORTS = 0x117;
    Peripherals::RADIO_NS.INTENSET = 0x10;
    DAT_21006458 = '\x04';
    Peripherals::RADIO_NS.RXADDRESSES = (uint)DAT_21000696;
    uVar2 = DAT_21000697 + 0x960;
    if (0x9c4 < uVar2) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_radio.h",0x6b7,uVar2);
      FUN_0103a370();
      uVar2 = extraout_r3;
    }
    Peripherals::RADIO_NS.FREQUENCY = uVar2 - 0x960;
    Peripherals::RADIO_NS.PACKETPTR = 0x2100625e;
    _DAT_e000e280 = 0x100;
    FUN_0102f2ec('\b');
    Peripherals::RADIO_NS.EVENTS_ADDRESS = 0;
    uVar2 = Peripherals::RADIO_NS.EVENTS_ADDRESS;
    Peripherals::RADIO_NS.EVENTS_PAYLOAD = 0;
    uVar2 = Peripherals::RADIO_NS.EVENTS_PAYLOAD;
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    uVar2 = Peripherals::RADIO_NS.EVENTS_DISABLED;
    FUN_010342d8('\x01',0);
    FUN_01033148();
    Peripherals::EGU0_NS.TASKS_TRIGGER_6_ = 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}


