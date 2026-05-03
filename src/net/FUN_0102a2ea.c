/*
 * Function: FUN_0102a2ea
 * Entry:    0102a2ea
 * Prototype: int __stdcall FUN_0102a2ea(ushort param_1, int param_2)
 */


int FUN_0102a2ea(ushort param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0100a518(param_1,3);
  if (((iVar1 == 0) && (iVar2 = FUN_0100a518(param_1,5), iVar2 != 0)) &&
     ((param_2 == 0 || (*(char *)(iVar2 + 0xbd) == '\0')))) {
    iVar1 = iVar2;
  }
  return iVar1;
}


