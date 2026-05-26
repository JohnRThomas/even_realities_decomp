/*
 * Function: $_FUN_0006b208
 * Entry:    0006b208
 * Prototype: undefined __stdcall $_FUN_0006b208(void)
 */


void __FUN_0006b208(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = Peripherals::WDT0_S.REQSTATUS;
  uVar1 = Peripherals::WDT0_S.EVENTS_TIMEOUT;
  if (uVar1 != 0) {
    Peripherals::WDT0_S.EVENTS_TIMEOUT = 0;
    uVar1 = Peripherals::WDT0_S.EVENTS_TIMEOUT;
                    /* WARNING: Could not recover jumptable at 0x0006b222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_2000be08)(uVar2);
    return;
  }
  return;
}


