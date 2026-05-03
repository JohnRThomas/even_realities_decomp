/*
 * Function: FUN_01024f0c
 * Entry:    01024f0c
 * Prototype: undefined4 __stdcall FUN_01024f0c(undefined * param_1)
 */


undefined4 FUN_01024f0c(undefined *param_1)

{
  byte bVar1;
  
  if (DAT_21001bd0 == '\0') {
    DAT_21001bd0 = '\x01';
    DAT_21001bd8 = (code *)param_1;
    FUN_01024ee4();
    bVar1 = FUN_010252d0();
    if (bVar1 == 0) {
      DAT_21001bdc = 1;
      Peripherals::CLOCK_NS.INTENSET = 1;
    }
    else if (DAT_21001bd8 != (code *)0x0) {
      (*DAT_21001bd8)();
      DAT_21001bd8 = (code *)0x0;
    }
  }
  return 0;
}


