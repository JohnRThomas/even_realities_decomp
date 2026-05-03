/*
 * Function: FUN_0103a414
 * Entry:    0103a414
 * Prototype: undefined __stdcall FUN_0103a414(uint * param_1, int param_2)
 */


void FUN_0103a414(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  *(uint *)(param_1[8] + *param_1 * 4) = param_2 << 2 | 2;
  uVar1 = FUN_0103a3e0((int)param_1,*param_1,param_2);
  uVar2 = param_1[3];
  bVar3 = uVar1 == uVar2;
  if (bVar3) {
    uVar2 = param_1[4];
  }
  *param_1 = uVar1;
  if (bVar3) {
    param_1[4] = uVar2 | 8;
  }
  uVar1 = FUN_0103a3e0((int)param_1,param_1[1],param_2);
  param_1[1] = uVar1;
  return;
}


