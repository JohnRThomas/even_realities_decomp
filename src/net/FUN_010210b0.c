/*
 * Function: FUN_010210b0
 * Entry:    010210b0
 * Prototype: undefined __stdcall FUN_010210b0(void)
 */


void FUN_010210b0(void)

{
  uint uVar1;
  
  uVar1 = Peripherals::RADIO_NS.SHORTS;
  Peripherals::RADIO_NS.SHORTS = uVar1 & 0xffffffbf;
  Peripherals::RADIO_NS.BCC = 0;
  return;
}


