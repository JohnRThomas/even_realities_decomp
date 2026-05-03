/*
 * Function: FUN_0103a3fc
 * Entry:    0103a3fc
 * Prototype: undefined __stdcall FUN_0103a3fc(int param_1, int param_2)
 */


void FUN_0103a3fc(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0103a3e0(param_1,*(int *)(param_1 + 0xc),param_2);
  *(uint *)(param_1 + 0xc) = uVar1;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffff7;
  return;
}


