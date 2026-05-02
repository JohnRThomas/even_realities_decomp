/*
 * Function: FUN_00029774
 * Entry:    00029774
 * Prototype: undefined __stdcall FUN_00029774(int param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_00029774(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  pvVar1 = FUN_00018320();
  if ((2 < param_1 - 0xf0U) || (DAT_20003051 == -1)) {
    DAT_20003051 = (char)param_1;
    if ((*(char *)((int)pvVar1 + 0x248) == '\0') && (*(int *)((int)pvVar1 + 0x220) == 0)) {
      if (*(char *)((int)pvVar1 + 0x248) == '\0') {
        k_sem_give((k_sem *)((int)pvVar1 + 0x218));
        k_msleep(1);
        return;
      }
    }
    else {
      local_14 = CONCAT13(local_14._3_1_,0xcb0000);
      local_14._0_2_ = CONCAT11(DAT_20003051,0xf5);
      enqueue_bt_data(&local_14,3);
      DAT_20003051 = -1;
    }
  }
  return;
}


