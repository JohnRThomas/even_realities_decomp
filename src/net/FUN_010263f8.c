/*
 * Function: FUN_010263f8
 * Entry:    010263f8
 * Prototype: undefined __stdcall FUN_010263f8(void)
 */


void FUN_010263f8(void)

{
  if (DAT_21001c88 == '\0') {
    if ((DAT_21001c89 == '\x01') && (DAT_21001c89 = '\x02', DAT_21001c8c != (code *)0x0)) {
      (*DAT_21001c8c)();
      DAT_21001c8c = (code *)0x0;
    }
    if ((DAT_21001c89 == '\x03') && (DAT_21001c89 = '\0', DAT_21001c8c != (code *)0x0)) {
      (**(code **)(DAT_21001c90 + 0x14))();
      (*DAT_21001c8c)();
      DAT_21001c8c = (code *)0x0;
    }
  }
  return;
}


