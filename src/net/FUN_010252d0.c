/*
 * Function: FUN_010252d0
 * Entry:    010252d0
 * Prototype: byte __stdcall FUN_010252d0(void)
 */


byte FUN_010252d0(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = Peripherals::CLOCK_NS.EVENTS_HFCLKSTARTED;
  bVar2 = DAT_21001bf7;
  if (uVar1 != 0) {
    bVar2 = 1;
  }
  return bVar2 & 1;
}


