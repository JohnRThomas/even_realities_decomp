/*
 * Function: FUN_0007f50c
 * Entry:    0007f50c
 * Prototype: undefined __stdcall FUN_0007f50c(byte * param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0007f50c(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_00018320();
  local_14 = CONCAT22((short)param_2,CONCAT11(1,*param_1));
  ble_process_req_dispatch(iVar1,(byte *)&local_14,param_1);
  return;
}


