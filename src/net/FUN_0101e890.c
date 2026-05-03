/*
 * Function: FUN_0101e890
 * Entry:    0101e890
 * Prototype: int __stdcall FUN_0101e890(int param_1)
 */


int FUN_0101e890(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x1c2) == '\0') {
    iVar1 = FUN_0100a518(*(ushort *)(param_1 + 0x17c),1);
    return iVar1;
  }
  return 0;
}


