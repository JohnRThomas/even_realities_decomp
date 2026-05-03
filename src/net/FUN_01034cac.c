/*
 * Function: FUN_01034cac
 * Entry:    01034cac
 * Prototype: ushort __stdcall FUN_01034cac(uint param_1)
 */


ushort FUN_01034cac(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar3 = FUN_01034c68(param_1);
  uVar1 = *(ushort *)((int)&DAT_210006a8 + (uVar3 + 8) * 2);
  uVar2 = uVar1 & 0x1c;
  if ((uVar1 & 0x1c) != 0) {
    uVar2 = 1;
  }
  return uVar2;
}


