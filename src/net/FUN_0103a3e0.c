/*
 * Function: FUN_0103a3e0
 * Entry:    0103a3e0
 * Prototype: uint __stdcall FUN_0103a3e0(int param_1, int param_2, int param_3)
 */


uint FUN_0103a3e0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_3 + param_2;
  uVar2 = *(uint *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x10) << 0x1f < 0) {
    uVar1 = uVar1 & uVar2 - 1;
  }
  else if (uVar2 <= uVar1) {
    uVar1 = uVar1 - uVar2;
  }
  return uVar1;
}


