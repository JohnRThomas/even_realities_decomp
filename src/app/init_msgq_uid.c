/*
 * Function: init_msgq_uid
 * Entry:    00018f58
 * Prototype: int __stdcall init_msgq_uid(void)
 */


int init_msgq_uid(void)

{
  int iVar1;
  
  iVar1 = z_impl_k_msgq_alloc_init((k_msgq *)&DAT_20006c18,8,10);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): k_msgq alloc failed\n","init_msgq_uid");
    }
    else {
      ble_printk("%s(): k_msgq alloc failed\n");
    }
  }
  return iVar1;
}


