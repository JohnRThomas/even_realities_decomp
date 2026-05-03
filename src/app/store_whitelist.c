/*
 * Function: store_whitelist
 * Entry:    00036ca4
 * Prototype: int __stdcall store_whitelist(void)
 */


int store_whitelist(void)

{
  int iVar1;
  char *extraout_r1;
  undefined4 extraout_r2;
  char cVar2;
  
  cVar2 = '\x03';
  do {
    iVar1 = FUN_0002478c(0x131000,0x2001aefb,(char *)0x15e2);
    if (iVar1 == 0) {
      dump_whitelist();
      break;
    }
    z_impl_k_sleep((k_timeout_t)0xa4);
    if (BLE_DEBUG == 0) {
      printk("write to flash failed, should retry ! \n");
    }
    else {
      ble_printk("write to flash failed, should retry ! \n",extraout_r1,extraout_r2,BLE_DEBUG);
    }
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  if (BLE_DEBUG == 0) {
    printk("[%s-%d] flash_settings_write_and_verify ret is %d \n","store_whitelist",0x24,iVar1);
  }
  else {
    ble_printk("[%s-%d] flash_settings_write_and_verify ret is %d \n","store_whitelist",0x24,iVar1);
  }
  return iVar1;
}


