/*
 * Function: FUN_0103a576
 * Entry:    0103a576
 * Prototype: undefined __stdcall FUN_0103a576(uint * param_1, int param_2)
 */


void FUN_0103a576(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((int)(param_1[4] << 0x1d) < 0) {
    uVar2 = param_1[10];
    uVar1 = FUN_0103a3be(param_1,param_2);
    if (uVar2 < uVar1) {
      param_1[10] = uVar1;
    }
    else {
      param_1[10] = uVar2;
    }
  }
  return;
}


