/*
 * Function: FUN_00023d38
 * Entry:    00023d38
 * Prototype: undefined __stdcall FUN_00023d38(byte * param_1, size_t param_2, int param_3)
 */


void FUN_00023d38(byte *param_1,size_t param_2,int param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  
  if (param_3 != 0) {
    FUN_0004d44c("BLE-rec",(int)param_1,param_2);
  }
  iVar1 = spec_ble_command_hook(param_1,param_2);
  if (iVar1 != 0) {
    FUN_0007f50c(param_1,param_2,extraout_r2);
    return;
  }
  return;
}


