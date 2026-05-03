/*
 * Function: FUN_0102a0a8
 * Entry:    0102a0a8
 * Prototype: uint __stdcall FUN_0102a0a8(uint param_1)
 */


uint FUN_0102a0a8(uint param_1)

{
  uint uVar1;
  
  if (((param_1 != 1) && (param_1 != 2)) && (uVar1 = param_1 & 0xc, param_1 = 0, uVar1 != 0)) {
    param_1 = 4;
  }
  return param_1;
}


