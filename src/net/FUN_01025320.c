/*
 * Function: FUN_01025320
 * Entry:    01025320
 * Prototype: bool __stdcall FUN_01025320(byte param_1)
 */


bool FUN_01025320(byte param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Peripherals::CLOCK_NS.LFCLKSTAT;
  uVar2 = Peripherals::CLOCK_NS.LFCLKSTAT;
  return (uVar1 & 0x10000) != 0 && (uVar2 & 3) == (uint)param_1;
}


