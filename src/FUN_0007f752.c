/*
 * Function: FUN_0007f752
 * Entry:    0007f752
 * Prototype: int __stdcall FUN_0007f752(byte * param_1)
 */


int FUN_0007f752(byte *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    if ((*param_1 & 0x10) == 0) {
      iVar1 = 6;
    }
    else {
      iVar1 = 3;
    }
    if ((int)((uint)*param_1 << 0x1c) < 0) {
      iVar1 = iVar1 + 1;
    }
    iVar1 = (uint)param_1[1] + (uint)param_1[2] + iVar1;
  }
  return iVar1;
}


