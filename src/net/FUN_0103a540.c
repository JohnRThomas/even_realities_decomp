/*
 * Function: FUN_0103a540
 * Entry:    0103a540
 * Prototype: undefined __stdcall FUN_0103a540(uint * param_1, int param_2, int param_3)
 */


void FUN_0103a540(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint extraout_r1;
  
  uVar1 = FUN_0103a3e0((int)param_1,param_2,param_3);
  if (*param_1 == uVar1) {
    *param_1 = extraout_r1;
    param_1[4] = param_1[4] & 0xfffffff7;
  }
  else {
    *(uint *)(param_1[8] + extraout_r1 * 4) = param_3 << 2 | 2;
    uVar1 = FUN_0103a3e0((int)param_1,param_1[1],param_3);
    param_1[1] = uVar1;
  }
  return;
}


