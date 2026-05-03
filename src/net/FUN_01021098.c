/*
 * Function: FUN_01021098
 * Entry:    01021098
 * Prototype: undefined __stdcall FUN_01021098(uint param_1)
 */


void FUN_01021098(uint param_1)

{
  uint uVar1;
  
  Peripherals::RADIO_NS.BCC = param_1;
  uVar1 = Peripherals::RADIO_NS.SHORTS;
  Peripherals::RADIO_NS.SHORTS = uVar1 | 0x40;
  return;
}


