/*
 * Function: FUN_010291b8
 * Entry:    010291b8
 * Prototype: undefined4 __stdcall FUN_010291b8(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_010291b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  
  bVar1 = FUN_01028cc2(param_1,param_2,param_3);
  if ((bVar1) && (cVar2 = FUN_0100cf0c(), cVar2 != '\0')) {
    uVar3 = 0xc;
  }
  else {
    FUN_0100ced8();
    uVar3 = 0;
  }
  return uVar3;
}


