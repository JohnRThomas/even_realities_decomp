/*
 * Function: FUN_01033174
 * Entry:    01033174
 * Prototype: undefined __stdcall FUN_01033174(void)
 */


void FUN_01033174(void)

{
  uint uVar1;
  
  *(undefined4 *)(DAT_21000698 + 0x10) = 1;
  FUN_01034464();
  FUN_010220e4();
  FUN_010220b4();
  FUN_010343b0('\x01',0);
  Peripherals::RADIO_NS.SHORTS = 0x113;
  (*DAT_2100499c)(DAT_21004aa5);
  Peripherals::RADIO_NS.PACKETPTR = 0x2100625e;
  Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
  uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
  Peripherals::RADIO_NS.TASKS_DISABLE = 1;
  do {
    uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
  } while (uVar1 == 0);
  Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
  uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
  Peripherals::RADIO_NS.SHORTS = 0x117;
  FUN_010342d8('\x01',0);
  FUN_01033148();
  Peripherals::EGU0_NS.TASKS_TRIGGER_6_ = 1;
  return;
}


