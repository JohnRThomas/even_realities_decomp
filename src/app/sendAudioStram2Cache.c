/*
 * Function: sendAudioStram2Cache
 * Entry:    00030b50
 * Prototype: undefined4 __stdcall sendAudioStram2Cache(void * param_1)
 */


undefined4 sendAudioStram2Cache(void *param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined1 local_dc [2];
  undefined2 local_da;
  undefined1 auStack_d8 [200];
  
  memset(local_dc,0,0xcc);
  if (DAT_20003a54 == 0x12) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): enqueue dmic stream num is full, drop it %d\r\n\n");
      }
      else {
        ble_printk("%s(): enqueue dmic stream num is full, drop it %d\r\n\n","sendAudioStram2Cache",
                   0x12,BLE_DEBUG);
      }
    }
  }
  else {
    memcpy(auStack_d8,param_1,200);
    local_da = 200;
    local_dc[0] = 2;
    iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a30,local_dc,(k_timeout_t)0x0);
    if (iVar1 == 0) {
      k_sem_give((k_sem *)&DAT_200083c4);
      return 0;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): enqueue_dmic failed\r\n\n");
      }
      else {
        ble_printk("%s(): enqueue_dmic failed\r\n\n","sendAudioStram2Cache",extraout_r2,BLE_DEBUG);
      }
    }
  }
  return 0xffffffff;
}


