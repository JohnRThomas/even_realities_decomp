/*
 * Function: FUN_0103afcc
 * Entry:    0103afcc
 * Prototype: uint __stdcall FUN_0103afcc(uint * param_1)
 */


uint FUN_0103afcc(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1 >> 4 & 0xf0f0f0f | (*param_1 & 0xf0f0f0f) << 4;
  uVar1 = uVar1 >> 2 & 0x33333333 | (uVar1 & 0x33333333) << 2;
  return uVar1 >> 1 & 0x55555555 | (uVar1 & 0x55555555) << 1;
}


