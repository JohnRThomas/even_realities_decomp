/*
 * Function: FUN_010293c8
 * Entry:    010293c8
 * Prototype: undefined4 __stdcall FUN_010293c8(byte * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_010293c8(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint *extraout_r1;
  
  bVar1 = FUN_01028cc2((int)param_1,param_2,param_3);
  if ((bVar1) && (cVar2 = FUN_0100cf0c(), cVar2 != '\0')) {
    uVar3 = 0xc;
  }
  else {
    bVar1 = FUN_01028a96((uint)*param_1);
    bVar1 = FUN_0100d420((uint)bVar1,extraout_r1,param_1[7]);
    if (bVar1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 2;
    }
  }
  return uVar3;
}


