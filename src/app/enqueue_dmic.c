/*
 * Function: enqueue_dmic
 * Entry:    000300f4
 * Prototype: int __stdcall enqueue_dmic(void * param_1)
 */


int enqueue_dmic(void *param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined1 auStack_d8 [204];
  
  memcpy(auStack_d8,&PTR_0008bd7c,200);
  if ((dmic_msgq.used_msgs == 10) &&
     (z_impl_k_msgq_get(&dmic_msgq,auStack_d8,(k_timeout_t)0x0), 0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enqueue_dmic num is full, drop it %d\r\n\n");
    }
    else {
      ble_printk("%s(): enqueue_dmic num is full, drop it %d\r\n\n","enqueue_dmic",10,BLE_DEBUG);
    }
  }
  memcpy(auStack_d8,param_1,200);
  iVar1 = z_impl_k_msgq_put(&dmic_msgq,auStack_d8,(k_timeout_t)0x0);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enqueue_dmic failed\r\n\n");
    }
    else {
      ble_printk("%s(): enqueue_dmic failed\r\n\n","enqueue_dmic",extraout_r2,BLE_DEBUG);
    }
  }
  return iVar1;
}


