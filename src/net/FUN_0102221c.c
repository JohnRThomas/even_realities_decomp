/*
 * Function: FUN_0102221c
 * Entry:    0102221c
 * Prototype: undefined __stdcall FUN_0102221c(void)
 */


void FUN_0102221c(void)

{
  if (DAT_210016e0 != (code *)0x0) {
    (*DAT_210016e0)();
    DAT_210016e0 = (code *)0x0;
  }
  FUN_01023284();
  return;
}


