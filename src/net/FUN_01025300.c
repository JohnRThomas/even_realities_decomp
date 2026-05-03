/*
 * Function: FUN_01025300
 * Entry:    01025300
 * Prototype: uint __stdcall FUN_01025300(void)
 */


uint FUN_01025300(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::CLOCK_NS.LFCLKRUN;
  return uVar1 & 1;
}


