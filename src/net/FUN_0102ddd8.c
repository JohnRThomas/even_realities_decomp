/*
 * Function: FUN_0102ddd8
 * Entry:    0102ddd8
 * Prototype: undefined4 __stdcall FUN_0102ddd8(int * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0102ddd8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  byte local_18 [4];
  char *local_14;
  
  if (param_1 == (int *)0x0) {
    local_14 = "Invalid endpoint";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    FUN_0103a612(0x103c034,0x1040,local_18);
    uVar1 = 0xffffffea;
  }
  else {
    iVar2 = *param_1;
    if (iVar2 == 0) {
      local_14 = "Endpoint not registered\n";
      local_18[0] = 2;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      FUN_0103a612(0x103c034,0x1040,local_18);
      uVar1 = 0xfffffffe;
    }
    else {
      if ((*(int *)(iVar2 + 8) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar2 + 8) + 8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0102de4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*UNRECOVERED_JUMPTABLE)(iVar2,param_1[1],param_2,param_3);
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
  }
  return uVar1;
}


