/*
 * Function: FUN_0101e5a8
 * Entry:    0101e5a8
 * Prototype: int __stdcall FUN_0101e5a8(void)
 */


int FUN_0101e5a8(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_2100113c;
  if (DAT_2100113c != 0) {
    do {
      iVar1 = iVar2;
      iVar2 = *(int *)(iVar1 + 0x18);
    } while (iVar2 != 0);
    return iVar1;
  }
  return 0;
}


