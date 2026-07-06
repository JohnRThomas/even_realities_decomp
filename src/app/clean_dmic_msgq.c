/*
 * Function: clean_dmic_msgq
 * Entry:    000300b4
 * Prototype: int __stdcall clean_dmic_msgq(void)
 */


int clean_dmic_msgq(void)

{
  int iVar1;
  
  iVar1 = k_msgq_cleanup(&dmic_msgq);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): dmic cleanup failed\n","clean_dmic_msgq");
    }
    else {
      ble_printk("%s(): dmic cleanup failed\n");
    }
  }
  return iVar1;
}


