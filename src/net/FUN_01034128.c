/*
 * Function: FUN_01034128
 * Entry:    01034128
 * Prototype: undefined4 __stdcall FUN_01034128(void)
 */


undefined4 FUN_01034128(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((DAT_21006458 == '\x04') || (DAT_21006458 == '\x05')) {
    FUN_010343b0('\x01',0);
    FUN_010330c8();
    uVar1 = Peripherals::RADIO_NS.SHORTS;
    Peripherals::RADIO_NS.SHORTS = 0;
    Peripherals::RADIO_NS.INTENCLR = 0xffffffff;
    DAT_210049a0 = 0;
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
    Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    do {
      uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
    } while (uVar1 == 0);
    uVar2 = 0;
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
    DAT_21006458 = '\0';
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


