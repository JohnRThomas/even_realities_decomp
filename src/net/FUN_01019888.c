/*
 * Function: FUN_01019888
 * Entry:    01019888
 * Prototype: bool __stdcall FUN_01019888(void)
 */


bool FUN_01019888(void)

{
  if (DAT_21000fe4 == 3) {
    return DAT_21000fe6 == '\x01';
  }
  if (1 < DAT_21000fe4 - 1) {
    return false;
  }
  return (DAT_21000fe5 & 0xfd) == 1;
}


