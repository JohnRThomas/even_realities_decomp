/*
 * Function: FUN_0005279c
 * Entry:    0005279c
 * Prototype: undefined __stdcall FUN_0005279c(void)
 */


void FUN_0005279c(void)

{
  if (DAT_2000ac9c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000527a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_2000ac9c)();
    return;
  }
  return;
}


