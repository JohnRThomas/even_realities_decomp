/*
 * Function: FUN_0100df38
 * Entry:    0100df38
 * Prototype: int __stdcall FUN_0100df38(int param_1)
 */


int FUN_0100df38(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -DAT_21000ea6;
  if (0x14 < iVar1) {
    return 0x14;
  }
  if (-0x80 < iVar1) {
    return (int)(char)iVar1;
  }
  return -0x7f;
}


