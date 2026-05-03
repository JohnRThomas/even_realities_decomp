/*
 * Function: FUN_0102dd74
 * Entry:    0102dd74
 * Prototype: undefined4 __stdcall FUN_0102dd74(int param_1, int * param_2, int param_3)
 */


undefined4 FUN_0102dd74(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte local_18 [4];
  char *local_14;
  
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (param_3 == 0)) {
    local_14 = "Invalid instance, endpoint or configuration";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    FUN_0103a612(0x103c034,0x1040,local_18);
    uVar1 = 0xffffffea;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) {
      *param_2 = param_1;
                    /* WARNING: Could not recover jumptable at 0x0102ddc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(iVar2 + 0xc))(param_1,param_2 + 1);
      return uVar1;
    }
    local_14 = "Invalid backend configuration";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    FUN_0103a612(0x103c034,0x1040,local_18);
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


