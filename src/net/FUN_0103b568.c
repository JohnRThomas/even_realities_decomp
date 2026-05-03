/*
 * Function: FUN_0103b568
 * Entry:    0103b568
 * Prototype: uint __stdcall FUN_0103b568(int param_1, undefined4 param_2)
 */


uint FUN_0103b568(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char acStack_38 [32];
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  local_18 = uVar2;
  local_14 = param_2;
  FUN_0103bd64(acStack_38,param_1,0x20);
  uVar1 = FUN_01035be4(param_1,uVar2,0x35,(int)acStack_38,0x28);
  return uVar1 & (int)uVar1 >> 0x1f;
}


