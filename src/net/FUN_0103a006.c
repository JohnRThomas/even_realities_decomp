/*
 * Function: FUN_0103a006
 * Entry:    0103a006
 * Prototype: undefined __stdcall FUN_0103a006(int param_1, uint param_2)
 */


void FUN_0103a006(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 8);
  uVar1 = FUN_01039f28(param_1,param_2);
  if ((0x7fff < uVar2) && (uVar1 == 1)) {
    return;
  }
  uVar1 = FUN_01039f92(uVar2);
  FUN_01039faa(param_1,param_2,uVar1);
  return;
}


