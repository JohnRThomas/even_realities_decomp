/*
 * Function: FUN_01027844
 * Entry:    01027844
 * Prototype: int __stdcall FUN_01027844(int param_1)
 */


int FUN_01027844(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = (*(ushort *)(param_1 + 4) & 0x7fff) + param_1 + 0x18;
  bVar1 = FUN_01027112(*(ushort *)(param_1 + 4),*(short *)(param_1 + 6));
  if (bVar1) {
    iVar2 = 0;
  }
  else if (*(short *)(param_1 + 10) != 0) {
    iVar2 = 0;
  }
  return iVar2;
}


