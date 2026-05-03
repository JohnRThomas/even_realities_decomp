/*
 * Function: FUN_01012e68
 * Entry:    01012e68
 * Prototype: uint __stdcall FUN_01012e68(int param_1)
 */


uint FUN_01012e68(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar3 = (uint)uVar1;
  uVar2 = uVar3 & 0x10;
  if ((uVar1 & 0x10) == 0) {
    if ((-1 < (int)(uVar3 << 0x1e)) && (uVar2 = uVar3 & 1, (uVar1 & 1) == 0)) {
      uVar1 = FUN_0100acd0();
      return (uint)(uVar1 != 0);
    }
  }
  else {
    uVar2 = ((uVar3 ^ 4) << 0x1d) >> 0x1f;
  }
  return uVar2;
}


