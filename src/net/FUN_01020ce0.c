/*
 * Function: FUN_01020ce0
 * Entry:    01020ce0
 * Prototype: undefined __stdcall FUN_01020ce0(uint param_1)
 */


void FUN_01020ce0(uint param_1)

{
  Peripherals::RADIO_NS.PREFIX0 = param_1 >> 0x18;
  Peripherals::RADIO_NS.BASE0 = param_1 << 8;
  return;
}


