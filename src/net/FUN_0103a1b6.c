/*
 * Function: FUN_0103a1b6
 * Entry:    0103a1b6
 * Prototype: undefined __stdcall FUN_0103a1b6(int param_1, int param_2)
 */


void FUN_0103a1b6(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r2;
  
  uVar1 = FUN_01039f28(param_1,param_2);
  uVar2 = FUN_01039efc(param_1,param_2 + uVar1,1);
  if (-1 < (int)(uVar2 << 0x1f)) {
    FUN_0103a006(param_1,param_2 + uVar1);
    uVar1 = FUN_01039f28(param_1,param_2);
    FUN_0103a0f6(param_1,param_2,param_2 + uVar1);
  }
  uVar1 = FUN_01039efc(param_1,param_2,0);
  uVar2 = FUN_01039efc(param_1,param_2 - uVar1,1);
  if ((uVar2 & extraout_r2) == 0) {
    FUN_0103a006(param_1,param_2 - uVar1);
    uVar1 = FUN_01039efc(param_1,param_2,0);
    FUN_0103a0f6(param_1,param_2 - uVar1,param_2);
    uVar1 = FUN_01039efc(param_1,param_2,0);
    param_2 = param_2 - uVar1;
  }
  FUN_0103a132(param_1,param_2);
  return;
}


