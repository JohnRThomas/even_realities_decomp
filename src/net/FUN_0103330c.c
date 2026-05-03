/*
 * Function: FUN_0103330c
 * Entry:    0103330c
 * Prototype: undefined __stdcall FUN_0103330c(byte * param_1)
 */


void FUN_0103330c(byte *param_1)

{
  Peripherals::RADIO_NS.PCNF0 =
       (uint)param_1[2] << 0x10 | (uint)param_1[1] << 8 | (uint)*param_1 | (uint)param_1[3] << 0x14
       | (uint)param_1[4] << 0x16 | (uint)param_1[5] << 0x18 | (uint)param_1[6] << 0x1a |
       (uint)param_1[7] << 0x1d;
  Peripherals::RADIO_NS.PCNF1 =
       (uint)param_1[10] << 0x10 | (uint)param_1[9] << 8 | (uint)param_1[8] |
       (uint)param_1[0xb] << 0x18 | (uint)param_1[0xc] << 0x19;
  return;
}


