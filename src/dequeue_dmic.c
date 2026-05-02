/*
 * Function: dequeue_dmic
 * Entry:    00030198
 * Prototype: int __stdcall dequeue_dmic(void * param_1)
 */


int dequeue_dmic(void *param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined1 auStack_d8 [204];
  
  memcpy(auStack_d8,&DAT_0008bd7c,200);
  iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_2000855c,auStack_d8,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    memcpy(param_1,auStack_d8,200);
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): dequeue_dmic failed\r\n\n");
    }
    else {
      ble_printk("%s(): dequeue_dmic failed\r\n\n","dequeue_dmic",extraout_r2,BLE_DEBUG);
    }
  }
  return iVar1;
}


