/*
 * Function: FUN_0100fee8
 * Entry:    0100fee8
 * Prototype: int __stdcall FUN_0100fee8(uint param_1)
 */


int FUN_0100fee8(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0x55) + (param_1 >> 1 & 0x55);
  uVar1 = (uVar1 >> 2 & 0x33) + (uVar1 & 0x33);
  return (uVar1 & 0xf) + (uVar1 >> 4);
}


