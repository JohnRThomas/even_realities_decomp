/*
 * Function: enqueue_bt_data
 * Entry:    00017fec
 * Prototype: int __stdcall enqueue_bt_data(void * param_1, undefined1 param_2)
 */


int enqueue_bt_data(void *param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 local_114;
  undefined1 auStack_113 [263];
  
  memset(&local_114,0,0x101);
  if (DAT_20003abc == 0x60) {
    z_impl_k_msgq_get((k_msgq *)&DAT_20003a98,&local_114,(k_timeout_t)0x0);
    if (BLE_DEBUG == 0) {
      printk("enqueue_bt_data drop package! \n");
    }
    else {
      ble_printk("enqueue_bt_data drop package! \n");
    }
  }
  local_114 = param_2;
  memcpy(auStack_113,param_1,0x100);
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a98,&local_114,(k_timeout_t)0x0);
  if (iVar1 != 0) {
    if (BLE_DEBUG == 0) {
      printk("enqueue_bt_data failed !\n");
    }
    else {
      ble_printk("enqueue_bt_data failed !\n");
    }
  }
  return iVar1;
}


