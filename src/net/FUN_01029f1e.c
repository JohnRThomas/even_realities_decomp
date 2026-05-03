/*
 * Function: FUN_01029f1e
 * Entry:    01029f1e
 * Prototype: uint __stdcall FUN_01029f1e(uint param_1)
 */


uint FUN_01029f1e(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 1;
  if (uVar1 == 0) {
    if (-1 < (int)(param_1 << 0x1e)) {
      uVar1 = 0;
      if ((param_1 & 4) != 0) {
        uVar1 = 8;
      }
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}


