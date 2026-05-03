/*
 * Function: FUN_01034c7c
 * Entry:    01034c7c
 * Prototype: ushort __stdcall FUN_01034c7c(uint param_1)
 */


ushort FUN_01034c7c(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_01034c68(param_1);
  return *(ushort *)((int)&DAT_210006a8 + (uVar1 + 8) * 2) & 1;
}


