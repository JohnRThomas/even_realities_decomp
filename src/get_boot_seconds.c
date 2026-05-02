/*
 * Function: get_boot_seconds
 * Entry:    0004d544
 * Prototype: int __stdcall get_boot_seconds(void)
 */


int get_boot_seconds(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = get_bootSeconds();
  uVar2 = __aeabi_ldivmod((uint)uVar2,(uint)((ulonglong)uVar2 >> 0x20),1000,0);
  iVar1 = (int)uVar2 - DAT_2000aa90;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): [csh_debug] bootSeconds is %d\n");
    }
    else {
      ble_printk("%s(): [csh_debug] bootSeconds is %d\n","get_boot_seconds",iVar1,BLE_DEBUG);
    }
  }
  return iVar1;
}


