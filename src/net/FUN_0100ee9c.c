/*
 * Function: FUN_0100ee9c
 * Entry:    0100ee9c
 * Prototype: bool __stdcall FUN_0100ee9c(int param_1, uint param_2)
 */


bool FUN_0100ee9c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)*(ushort *)(param_1 + 7);
  uVar3 = (uint)*(ushort *)(param_1 + 5);
  uVar4 = (uint)*(byte *)(param_1 + 4);
  if (uVar2 - 0xd01 < 7) {
    uVar1 = param_2 & 1;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
LAB_0100eeec:
    if (*(ushort *)(param_1 + 9) < 500) {
      return (ushort)(*(short *)(param_1 + 0xb) - 10U) < 0xc77;
    }
    return false;
  }
  if (((uVar2 - 6 & 0xffff) < 0xc7b) && (uVar4 - 1 < 8)) {
    uVar1 = uVar3;
    if (uVar3 <= uVar2) {
      uVar1 = uVar4;
    }
    if ((uVar3 <= uVar2 && uVar4 <= uVar2) && uVar2 != uVar1) goto LAB_0100eeec;
  }
  return false;
}


