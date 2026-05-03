/*
 * Function: FUN_0100d280
 * Entry:    0100d280
 * Prototype: undefined * __stdcall FUN_0100d280(uint param_1)
 */


undefined * FUN_0100d280(uint param_1)

{
  if (param_1 < DAT_21000d19) {
    return &DAT_21000d1a + param_1 * 0x10;
  }
  return (undefined *)0x0;
}


