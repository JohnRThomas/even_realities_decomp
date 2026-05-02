/*
 * Function: init_dmic_msgq
 * Entry:    00030070
 * Prototype: int __stdcall init_dmic_msgq(void)
 */


int init_dmic_msgq(void)

{
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = z_impl_k_msgq_alloc_init((k_msgq *)&DAT_2000855c,200,10);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): dmic init failed\n");
    }
    else {
      ble_printk("%s(): dmic init failed\n","init_dmic_msgq",extraout_r2,BLE_DEBUG);
    }
  }
  return iVar1;
}


