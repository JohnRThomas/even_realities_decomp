/*
 * Function: FUN_0102910e
 * Entry:    0102910e
 * Prototype: undefined4 __stdcall FUN_0102910e(byte * param_1, undefined4 param_2)
 */


undefined4 FUN_0102910e(byte *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_01028bb8((int)param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = (uint)*param_1;
    if (uVar3 < 2) {
      bVar1 = FUN_01028a96(uVar3);
      iVar2 = FUN_01010fb8((uint)bVar1,(uint *)(param_1 + 1));
      if (iVar2 == 0) {
        uVar4 = 7;
      }
      else {
        uVar4 = 0;
      }
    }
    else if (uVar3 == 0xff) {
      FUN_0100c444(1);
      uVar4 = 0;
    }
    else {
      uVar4 = 0x12;
    }
  }
  else {
    uVar4 = 0xc;
  }
  return uVar4;
}


