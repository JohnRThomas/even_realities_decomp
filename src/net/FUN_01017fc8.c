/*
 * Function: FUN_01017fc8
 * Entry:    01017fc8
 * Prototype: undefined4 __stdcall FUN_01017fc8(void)
 */


undefined4 FUN_01017fc8(void)

{
  int iVar1;
  
  iVar1 = FUN_0100df60();
  DAT_2100001c = (undefined1)iVar1;
  if (DAT_2100100c == '\0') {
    FUN_01020d00();
    return 5;
  }
  FUN_010210b0();
  FUN_010204a8();
  DAT_2100100c = 0;
  FUN_01020d00();
  return 5;
}


