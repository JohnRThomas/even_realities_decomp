/*
 * Function: FUN_01029078
 * Entry:    01029078
 * Prototype: undefined4 __stdcall FUN_01029078(int param_1, undefined4 param_2)
 */


undefined4 FUN_01029078(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_01028bb8(param_1,param_2);
  if (iVar1 == 0) {
    FUN_01010fa0();
    FUN_0100c444(0);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


