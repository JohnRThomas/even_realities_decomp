/*
 * Function: FUN_00027f38
 * Entry:    00027f38
 * Prototype: undefined __stdcall FUN_00027f38(undefined4 param_1, undefined4 param_2)
 */


void FUN_00027f38(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined2 extraout_var;
  undefined4 extraout_r3;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_1;
  local_c = param_2;
  iVar1 = FUN_0007fdc4(&DAT_20007f50);
  if ((((iVar1 << 0x1e < 0) && (iVar1 = FUN_0007fdc4(&DAT_20008480), -1 < iVar1 << 0x1e)) &&
      (iVar1 = FUN_0007fdc4(&DAT_20007f4c), -1 < iVar1 << 0x1e)) &&
     (iVar1 = FUN_0007fdc4(&DAT_20007f50), iVar1 << 0x1e < 0)) {
    local_10 = CONCAT22(extraout_var,0x650);
    local_c = CONCAT22(local_c._2_2_,0x101);
    uVar2 = send_response_data_to_msgqueue(&local_10,6);
    send_response_data_to_ble(uVar2,extraout_r1,extraout_r2,extraout_r3);
    DAT_20007f4c = DAT_20007f4c | 2;
  }
  return;
}


