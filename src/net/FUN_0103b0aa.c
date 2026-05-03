/*
 * Function: FUN_0103b0aa
 * Entry:    0103b0aa
 * Prototype: uint __stdcall FUN_0103b0aa(uint param_1)
 */


uint FUN_0103b0aa(uint param_1)

{
  uint uVar1;
  
  if (param_1 >> 5 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (param_1 >> 5 != 1) {
      return 0;
    }
    uVar1 = 0xffff;
  }
  return uVar1 >> (param_1 & 0x1f) & 1;
}


