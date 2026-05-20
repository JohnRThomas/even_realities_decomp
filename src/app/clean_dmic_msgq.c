/*
 * Function: clean_dmic_msgq
 * Entry:    000300b4
 * Prototype: int __stdcall clean_dmic_msgq(void)
 */


int clean_dmic_msgq(void)

{
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = k_msgq_cleanup(&dmic_msgq);
  if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): dmic cleanup failed\n");
    }
    else {
      ble_printk("%s(): dmic cleanup failed\n","clean_dmic_msgq",extraout_r2,BLE_DEBUG);
    }
  }
  return iVar1;
}


