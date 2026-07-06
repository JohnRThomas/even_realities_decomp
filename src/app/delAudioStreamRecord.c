/*
 * Function: delAudioStreamRecord
 * Entry:    00030d18
 * Prototype: undefined4 __stdcall delAudioStreamRecord(undefined1 param_1)
 */


undefined4 delAudioStreamRecord(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_dc;
  undefined1 uStack_db;
  undefined2 local_da;
  undefined1 local_d8;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): received audio delete command\n","delAudioStreamRecord");
    }
    else {
      ble_printk("%s(): received audio delete command\n");
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
        printk("%s(): enqueue_dmic failed\r\n\n","delAudioStreamRecord");
      }
      else {
        ble_printk("%s(): enqueue_dmic failed\r\n\n");
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


