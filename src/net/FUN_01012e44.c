/*
 * Function: FUN_01012e44
 * Entry:    01012e44
 * Prototype: uint __stdcall FUN_01012e44(int param_1)
 */


uint FUN_01012e44(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar3 = (uint)uVar1;
  uVar2 = uVar3 & 0x10;
  if ((uVar1 & 0x10) != 0) {
    if ((uVar1 & 4) == 0) {
      uVar2 = 0x1f;
    }
    else {
      uVar2 = 0;
    }
    return uVar2;
  }
  if (-1 < (int)(uVar3 << 0x1e)) {
    if (-1 < (int)(uVar3 << 0x1f)) {
      uVar1 = FUN_0100acd0();
      return (uint)uVar1;
    }
    uVar2 = 0xee;
  }
  return uVar2;
}


