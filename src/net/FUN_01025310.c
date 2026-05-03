/*
 * Function: FUN_01025310
 * Entry:    01025310
 * Prototype: uint __stdcall FUN_01025310(void)
 */


uint FUN_01025310(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::CLOCK_NS.LFCLKSRCCOPY;
  return uVar1 & 3;
}


