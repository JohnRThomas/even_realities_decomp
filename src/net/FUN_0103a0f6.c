/*
 * Function: FUN_0103a0f6
 * Entry:    0103a0f6
 * Prototype: undefined __stdcall FUN_0103a0f6(int param_1, int param_2, int param_3)
 */


void FUN_0103a0f6(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_01039f28(param_1,param_2);
  uVar2 = FUN_01039f28(param_1,param_3);
  FUN_01039f64(param_1,param_2,uVar1 + uVar2);
  uVar3 = FUN_01039f28(param_1,param_3);
  FUN_01039f12(param_1,param_3 + uVar3,0,uVar1 + uVar2);
  return;
}


