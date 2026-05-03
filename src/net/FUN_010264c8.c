/*
 * Function: FUN_010264c8
 * Entry:    010264c8
 * Prototype: undefined __stdcall FUN_010264c8(void)
 */


void FUN_010264c8(void)

{
  if ((DAT_21001c89 == '\x02') || (DAT_21001c89 == '\x03')) {
    (**(code **)(DAT_21001c90 + 8))();
  }
  DAT_21001ca6 = 0;
  DAT_21001c88 = 0;
  FUN_010263f8();
  return;
}


