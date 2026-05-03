/*
 * Function: FUN_0102f4d8
 * Entry:    0102f4d8
 * Prototype: uint __stdcall FUN_0102f4d8(uint param_1, uint param_2)
 */


uint FUN_0102f4d8(uint param_1,uint param_2)

{
  uint uVar1;
  
  if ((DAT_21004b30 != 0) &&
     ((uVar1 = *(uint *)(DAT_21004b30 + 0x78), param_1 == 0xffffffea ||
      ((uVar1 - 0x40 <= param_1 && (param_1 < uVar1)))))) {
    if (uVar1 <= param_2) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0;
}


