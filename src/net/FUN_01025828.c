/*
 * Function: FUN_01025828
 * Entry:    01025828
 * Prototype: uint __stdcall FUN_01025828(void)
 */


uint FUN_01025828(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::RTC0_NS.COUNTER;
  return uVar1;
}


