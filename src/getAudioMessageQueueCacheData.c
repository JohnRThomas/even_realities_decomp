/*
 * Function: getAudioMessageQueueCacheData
 * Entry:    00030900
 * Prototype: undefined4 __stdcall getAudioMessageQueueCacheData(void * param_1)
 */


undefined4 getAudioMessageQueueCacheData(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  
  iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20003a30,param_1,(k_timeout_t)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): dequeue_dmic failed\r\n\n");
      }
      else {
        ble_printk("%s(): dequeue_dmic failed\r\n\n","getAudioMessageQueueCacheData",extraout_r2,
                   BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


