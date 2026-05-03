/*
 * Function: stopAudioStreamRecord
 * Entry:    00030cac
 * Prototype: undefined4 __stdcall stopAudioStreamRecord(void)
 */


undefined4 stopAudioStreamRecord(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  undefined1 local_d4;
  undefined1 auStack_d3 [203];
  
  memset(auStack_d3,0,0xcb);
  local_d4 = 3;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a30,&local_d4,(k_timeout_t)0x0);
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
        ble_printk("%s(): enqueue_dmic failed\r\n\n","stopAudioStreamRecord",extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


