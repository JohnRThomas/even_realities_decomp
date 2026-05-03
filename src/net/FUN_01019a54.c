/*
 * Function: FUN_01019a54
 * Entry:    01019a54
 * Prototype: undefined4 __stdcall FUN_01019a54(void)
 */


undefined4 FUN_01019a54(void)

{
  if (DAT_21000ff4 != 0) {
    DAT_21000ff4 = 0;
    DAT_21000ff9 = 0;
    Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_21000ff8;
    return 0;
  }
  return 0xc;
}


