/*
 * Function: hi0bits
 * Entry:    0008acc0
 * Prototype: int __stdcall hi0bits(uint param_1)
 */


/* exclude_from_export_ai */

int hi0bits(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0x10000) {
    param_1 = param_1 << 0x10;
    iVar1 = 0x10;
  }
  else {
    iVar1 = 0;
  }
  if (param_1 < 0x1000000) {
    param_1 = param_1 << 8;
    iVar1 = iVar1 + 8;
  }
  if (param_1 < 0x10000000) {
    param_1 = param_1 << 4;
    iVar1 = iVar1 + 4;
  }
  if (param_1 < 0x40000000) {
    if ((int)(param_1 << 2) < 0) {
      return iVar1 + 2;
    }
    if ((int)(param_1 << 3) < 0) {
      return iVar1 + 3;
    }
    iVar1 = 0x20;
  }
  else if (-1 < (int)param_1) {
    return iVar1 + 1;
  }
  return iVar1;
}


