/*
 * Function: FUN_010252f0
 * Entry:    010252f0
 * Prototype: uint __stdcall FUN_010252f0(void)
 */


uint FUN_010252f0(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::CLOCK_NS.HFCLKRUN;
  return uVar1 & 1;
}


