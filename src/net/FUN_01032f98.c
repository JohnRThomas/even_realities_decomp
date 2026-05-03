/*
 * Function: FUN_01032f98
 * Entry:    01032f98
 * Prototype: undefined __stdcall FUN_01032f98(void)
 */


void FUN_01032f98(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::RADIO_NS.INTENSET;
  if (((int)(uVar1 << 0x1b) < 0) && (uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED, uVar1 != 0)) {
    Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
    uVar1 = Peripherals::RADIO_NS.EVENTS_DISABLED;
    if (DAT_210049a0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x01032fb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_210049a0)();
      return;
    }
  }
  return;
}


