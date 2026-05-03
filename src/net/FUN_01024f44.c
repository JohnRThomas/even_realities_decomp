/*
 * Function: FUN_01024f44
 * Entry:    01024f44
 * Prototype: undefined __stdcall FUN_01024f44(void)
 */


void FUN_01024f44(void)

{
  byte bVar1;
  
  FUN_01024ee4();
  bVar1 = FUN_010252d0();
  if (bVar1 == 0) {
    DAT_21001bdd = 3;
    Peripherals::CLOCK_NS.INTENSET = 1;
  }
  else {
    Peripherals::CLOCK_NS.TASKS_CAL = 1;
    DAT_21001bdd = 4;
  }
  DAT_21001bde = 0;
  return;
}


