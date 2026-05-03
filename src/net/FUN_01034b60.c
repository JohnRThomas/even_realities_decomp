/*
 * Function: FUN_01034b60
 * Entry:    01034b60
 * Prototype: undefined __stdcall FUN_01034b60(uint param_1)
 */


void FUN_01034b60(uint param_1)

{
  Peripherals::DPPIC_NS.CHENSET = param_1;
  return;
}


