/*
 * Function: FUN_01021064
 * Entry:    01021064
 * Prototype: undefined __stdcall FUN_01021064(uint param_1, uint * param_2)
 */


void FUN_01021064(uint param_1,uint *param_2)

{
  uint uVar1;
  
  Peripherals::RADIO_NS.EVENTS_ADDRESS = param_1 | 0x80000000;
  uVar1 = 1 << (param_1 & 0xff);
  *param_2 = param_1 | 0x80000000;
  Peripherals::DPPIC_NS.CHENSET = uVar1;
  DAT_2100161c = DAT_2100161c | uVar1;
  return;
}


