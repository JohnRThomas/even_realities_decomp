/*
 * Function: FUN_01020aa8
 * Entry:    01020aa8
 * Prototype: int __stdcall FUN_01020aa8(void)
 */


int FUN_01020aa8(void)

{
  int iVar1;
  
  iVar1 = (uint)DAT_21001618 * 4;
  return (DAT_21001614 - DAT_21001610) + *(int *)(&DAT_0103c4b8 + iVar1) +
         (uint)((*(int *)(&DAT_0103c4dc + iVar1) + 999) - *(int *)(&DAT_0103c500 + iVar1)) / 1000;
}


