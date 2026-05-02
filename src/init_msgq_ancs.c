/*
 * Function: init_msgq_ancs
 * Entry:    00018c64
 * Prototype: int __stdcall init_msgq_ancs(void)
 */


int init_msgq_ancs(void)

{
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = z_impl_k_msgq_alloc_init((k_msgq *)&GLOBAL_STATE.sem_4.count,0x1b4,10);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): k_msgq alloc failed\n");
    }
    else {
      ble_printk("%s(): k_msgq alloc failed\n","init_msgq_ancs",extraout_r2,BLE_DEBUG);
    }
  }
  return iVar1;
}


