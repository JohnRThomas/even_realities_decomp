/*
 * Function: FUN_0100df60
 * Entry:    0100df60
 * Prototype: int __stdcall FUN_0100df60(void)
 */


int FUN_0100df60(void)

{
  int iVar1;
  char local_9 [5];
  
  local_9[0] = '\x7f';
  iVar1 = FUN_010210cc(local_9);
  if (iVar1 == 0) {
    iVar1 = (int)local_9[0];
  }
  else {
    iVar1 = (int)-DAT_21000ea7 + (int)local_9[0];
    if (iVar1 < 0x15) {
      if (-0x80 < iVar1) {
        return (int)(char)iVar1;
      }
      iVar1 = -0x7f;
    }
    else {
      iVar1 = 0x14;
    }
  }
  return iVar1;
}


