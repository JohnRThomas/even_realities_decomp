/*
 * Function: FUN_0102074c
 * Entry:    0102074c
 * Prototype: undefined __stdcall FUN_0102074c(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102074c(void)

{
  if ((char)DAT_210014dc != '\0') {
    Peripherals::AAR_NS._132_4_ = 0;
    Peripherals::DPPIC_NS.CHENCLR = 0x200;
    Peripherals::AAR_NS.PUBLISH_END = 0;
    Peripherals::AAR_NS._132_4_ = 0;
    Peripherals::RADIO_NS.PUBLISH_RATEBOOST = 0;
    Peripherals::AAR_NS._140_4_ = 0;
    DAT_210014dc._0_1_ = 0;
    ram0x210014dd = 0;
    return;
  }
  ram0x210014dd = 0;
  return;
}


