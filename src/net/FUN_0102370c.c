/*
 * Function: FUN_0102370c
 * Entry:    0102370c
 * Prototype: longlong __stdcall FUN_0102370c(int param_1)
 */


longlong FUN_0102370c(int param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = param_1 * 0x20;
  lVar2 = FUN_01024c5c(*(uint *)(&DAT_210017c8 + iVar1),*(uint *)(&DAT_210017cc + iVar1));
  return lVar2 + (ulonglong)
                 CONCAT14(CARRY4((uint)*(ushort *)(&DAT_210017d6 + iVar1),
                                 (uint)(byte)(&DAT_210017d4)[iVar1]),
                          (uint)*(ushort *)(&DAT_210017d6 + iVar1) +
                          (uint)(byte)(&DAT_210017d4)[iVar1] + 1);
}


