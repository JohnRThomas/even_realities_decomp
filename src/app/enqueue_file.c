/*
 * Function: enqueue_file
 * Entry:    000255cc
 * Prototype: int __stdcall enqueue_file(void * param_1, size_t param_2)
 */


int enqueue_file(void *param_1,size_t param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined1 auStack_dc [200];
  undefined1 local_14;
  
  if ((DAT_200083a4 == 0x1e) &&
     (z_impl_k_msgq_get((k_msgq *)&DAT_20008380,auStack_dc,(k_timeout_t)0x0), 0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enqueue_file is full\n");
    }
    else {
      ble_printk("%s(): enqueue_file is full\n","enqueue_file",extraout_r2,BLE_DEBUG);
    }
  }
  memcpy(auStack_dc,param_1,param_2);
  local_14 = (undefined1)param_2;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20008380,auStack_dc,(k_timeout_t)0x0);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enqueue_file failed\r\n\n");
    }
    else {
      ble_printk("%s(): enqueue_file failed\r\n\n","enqueue_file",extraout_r2_00,BLE_DEBUG);
    }
  }
  return iVar1;
}


