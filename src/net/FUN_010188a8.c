/*
 * Function: FUN_010188a8
 * Entry:    010188a8
 * Prototype: undefined __stdcall FUN_010188a8(void)
 */


void FUN_010188a8(void)

{
  int iVar1;
  
  iVar1 = FUN_0100df60();
  DAT_2100001c = (undefined1)iVar1;
  if (DAT_2100100c == '\0') {
    FUN_01020d00();
    FUN_0101877c();
    return;
  }
  FUN_010210b0();
  FUN_010204a8();
  DAT_2100100c = 0;
  FUN_01020d00();
  FUN_0101877c();
  return;
}


