/*
 * Function: FUN_0102502c
 * Entry:    0102502c
 * Prototype: undefined __stdcall FUN_0102502c(void)
 */


void FUN_0102502c(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  if (DAT_21001bf5 != '\0') {
    uVar1 = Peripherals::CLOCK_NS.EVENTS_HFCLKSTARTED;
    uVar2 = Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED;
    if (((uVar1 != 0) && (Peripherals::CLOCK_NS.INTENCLR = 1, DAT_21001bdc != '\0')) &&
       (DAT_21001bdc = '\0', DAT_21001bd8 != (code *)0x0)) {
      (*DAT_21001bd8)();
      DAT_21001bd8 = (code *)0x0;
    }
    if (uVar2 != 0) {
      Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED = 0;
      Peripherals::CLOCK_NS.INTENCLR = 2;
      FUN_01024fdc();
    }
    cVar3 = DAT_21001bf4;
    uVar2 = Peripherals::CLOCK_NS.EVENTS_DONE;
    if ((uVar1 != 0) && (DAT_21001bdd == 3)) {
      DAT_21001bdd = 4;
      Peripherals::CLOCK_NS.TASKS_CAL = 1;
    }
    if (uVar2 != 0) {
      Peripherals::CLOCK_NS.EVENTS_DONE = 0;
      if (DAT_21001bdd != 4) {
        FUN_01025edc(0x6d,0x1d7,0,(uint)DAT_21001bdd);
      }
      DAT_21001bdd = 2;
      FUN_01024f78();
    }
    if (cVar3 != '\0') {
      DAT_21001bf4 = 0;
      if (DAT_21001bdd == 2) {
        FUN_01024f44();
      }
      FUN_01024f78();
      return;
    }
  }
  return;
}


