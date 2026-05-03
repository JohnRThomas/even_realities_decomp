/*
 * Function: FUN_0100ff48
 * Entry:    0100ff48
 * Prototype: uint __stdcall FUN_0100ff48(uint param_1)
 */


uint FUN_0100ff48(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 ^ (int)(param_1 << 0x10) >> 0x11 & 0xffffU;
  uVar1 = (uVar1 & 0x5555) + (uVar1 >> 1 & 0x5555);
  uVar1 = (uVar1 & 0x3333) + (uVar1 >> 2 & 0x3333);
  uVar1 = (uVar1 & 0xf0f) + (uVar1 >> 4 & 0xf0f);
  return uVar1 + (uVar1 >> 8) & 0xff;
}


