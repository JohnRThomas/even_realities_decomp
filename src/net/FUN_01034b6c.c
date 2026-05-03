/*
 * Function: FUN_01034b6c
 * Entry:    01034b6c
 * Prototype: undefined __stdcall FUN_01034b6c(uint param_1)
 */


void FUN_01034b6c(uint param_1)

{
  Peripherals::DPPIC_NS.CHENCLR = param_1;
  return;
}


