/*
 * Function: FUN_01034cc8
 * Entry:    01034cc8
 * Prototype: uint __stdcall FUN_01034cc8(uint param_1)
 */


uint FUN_01034cc8(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_01034c68(param_1);
  return ((uint)*(ushort *)((int)&DAT_210006a8 + (uVar1 + 8) * 2) << 0x1e) >> 0x1f;
}


