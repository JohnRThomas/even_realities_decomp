/*
 * Function: $_FUN_00068604
 * Entry:    00068604
 * Prototype: undefined __stdcall $_FUN_00068604(void)
 */


void __FUN_00068604(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED;
  if (uVar1 != 0) {
    Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED;
    Peripherals::CLOCK_S.INTENCLR = 1;
    (*DAT_2000bd04)();
  }
  uVar1 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED;
  if (uVar1 != 0) {
    Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED;
    uVar1 = Peripherals::CLOCK_S.LFCLKSTAT;
    uVar1 = Peripherals::CLOCK_S.LFCLKSTAT;
    if ((uVar1 & 3) == 1) {
      Peripherals::CLOCK_S.LFCLKSRC = 2;
      Peripherals::CLOCK_S.TASKS_LFCLKSTART = 1;
    }
    else {
      Peripherals::CLOCK_S.INTENCLR = 2;
      (*DAT_2000bd04)(1);
    }
  }
  uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED;
  if (uVar1 != 0) {
    Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED;
    Peripherals::CLOCK_S.INTENCLR = 0x100;
    (*DAT_2000bd04)(5);
  }
  uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED;
  if (uVar1 != 0) {
    Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED;
    Peripherals::CLOCK_S.INTENCLR = 0x200;
                    /* WARNING: Could not recover jumptable at 0x0006869c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_2000bd04)(6);
    return;
  }
  return;
}


