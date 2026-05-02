/*
 * Function: FUN_00033b18
 * Entry:    00033b18
 * Prototype: undefined __stdcall FUN_00033b18(void)
 */


void FUN_00033b18(void)

{
  longlong lVar1;
  
  lVar1 = FUN_00080638();
  DAT_20004af0 = (int)(lVar1 + 10000);
  DAT_20004af4 = (int)((ulonglong)(lVar1 + 10000) >> 0x20);
  return;
}


