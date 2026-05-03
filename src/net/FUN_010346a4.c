/*
 * Function: FUN_010346a4
 * Entry:    010346a4
 * Prototype: undefined __stdcall FUN_010346a4(void)
 */


void FUN_010346a4(void)

{
  Peripherals::DPPIC_NS.CHENCLR =
       1 << DAT_2100645b | 1 << DAT_2100645f | 1 << DAT_2100645d | 1 << DAT_2100645c |
       1 << DAT_21006460 | 1;
  return;
}


