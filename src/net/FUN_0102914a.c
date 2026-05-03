/*
 * Function: FUN_0102914a
 * Entry:    0102914a
 * Prototype: undefined4 __stdcall FUN_0102914a(byte * param_1, undefined4 param_2)
 */


undefined4 FUN_0102914a(byte *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint *extraout_r1;
  uint uVar4;
  
  iVar2 = FUN_01028bb8((int)param_1,param_2);
  if (iVar2 == 0) {
    uVar4 = (uint)*param_1;
    if (uVar4 < 2) {
      bVar1 = FUN_01028a96(uVar4);
      iVar2 = FUN_01011034((uint)bVar1,extraout_r1);
      if (iVar2 == 0) {
        uVar3 = 0x12;
      }
      else {
        uVar3 = 0;
      }
    }
    else if (uVar4 == 0xff) {
      FUN_0100c444(0);
      uVar3 = 0;
    }
    else {
      uVar3 = 0x12;
    }
  }
  else {
    uVar3 = 0xc;
  }
  return uVar3;
}


