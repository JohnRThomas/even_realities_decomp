/*
 * Function: FUN_0007f38a
 * Entry:    0007f38a
 * Prototype: undefined __stdcall FUN_0007f38a(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0007f38a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_18 = param_1;
  local_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_00018320();
  local_14 = CONCAT31(local_14._1_3_,2);
  local_18 = param_1;
  iVar2 = enqueue_uid_drop_package_(&local_18,extraout_r1,extraout_r2);
  if (iVar2 == 0) {
    k_sem_give((k_sem *)(iVar1 + 0x200));
  }
  return;
}


