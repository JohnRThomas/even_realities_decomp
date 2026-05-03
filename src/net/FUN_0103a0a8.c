/*
 * Function: FUN_0103a0a8
 * Entry:    0103a0a8
 * Prototype: undefined __stdcall FUN_0103a0a8(int param_1, int param_2, int param_3)
 */


void FUN_0103a0a8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_01039f28(param_1,param_2);
  iVar2 = (param_2 - param_3) + uVar1;
  FUN_01039f64(param_1,param_2,param_3 - param_2);
  FUN_01039f64(param_1,param_3,iVar2);
  FUN_01039f12(param_1,param_3,0,param_3 - param_2);
  uVar1 = FUN_01039f28(param_1,param_3);
  FUN_01039f12(param_1,param_3 + uVar1,0,iVar2);
  return;
}


