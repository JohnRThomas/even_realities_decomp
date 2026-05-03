/*
 * Function: FUN_0100afb0
 * Entry:    0100afb0
 * Prototype: undefined __stdcall FUN_0100afb0(void)
 */


void FUN_0100afb0(void)

{
  FUN_0100af18();
  FUN_0100af60();
  Peripherals::DPPIC_NS.CHENCLR = 0x1ff8;
  return;
}


