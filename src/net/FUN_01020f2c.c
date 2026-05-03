/*
 * Function: FUN_01020f2c
 * Entry:    01020f2c
 * Prototype: undefined __stdcall FUN_01020f2c(uint param_1)
 */


void FUN_01020f2c(uint param_1)

{
  Peripherals::RADIO_NS.CRCINIT = param_1;
  return;
}


