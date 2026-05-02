/*
 * Function: delAudioStreamRecord
 * Entry:    00030d18
 * Prototype: undefined4 __stdcall delAudioStreamRecord(undefined1 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 delAudioStreamRecord(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  undefined1 local_dc;
  undefined1 uStack_db;
  undefined2 local_da;
  undefined1 local_d8;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): received audio delete command\n");
    }
    else {
      ble_printk("%s(): received audio delete command\n","delAudioStreamRecord",param_3,BLE_DEBUG);
    }
  }
  memset(&uStack_db,0,0xcb);
  local_da = 1;
  local_dc = 4;
  local_d8 = param_1;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a30,&local_dc,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    k_sem_give((k_sem *)&DAT_200083c4);
    uVar2 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): enqueue_dmic failed\r\n\n");
      }
      else {
        ble_printk("%s(): enqueue_dmic failed\r\n\n","delAudioStreamRecord",extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


