/*
 * Function: load_whitelist
 * Entry:    000361d0
 * Prototype: undefined4 __stdcall load_whitelist(void)
 */


undefined4 load_whitelist(void)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined1 uStack_15ec;
  byte local_15eb;
  
  memset(&uStack_15ec,0,0x15e2);
  uVar1 = flash_settings_read(0x131000,&uStack_15ec,0x15e2,extraout_r3);
  if (uVar1 == 0) {
    uVar1 = (uint)local_15eb;
    if (uVar1 < 0x65) {
      memcpy(&DAT_2001aefb,&uStack_15ec,0x15e2);
      return 0;
    }
    if (BLE_DEBUG != 0) {
      uVar3 = 0x36;
      pcVar2 = "[%s-%d] error,appCounts is %d \n";
      goto LAB_00036202;
    }
    uVar3 = 0x36;
    pcVar2 = "[%s-%d] error,appCounts is %d \n";
  }
  else {
    if (BLE_DEBUG != 0) {
      uVar3 = 0x30;
      pcVar2 = "[%s-%d] flash_settings_read error,ret is %d \n";
LAB_00036202:
      ble_printk(pcVar2,"load_whitelist",uVar3,uVar1);
      return 0xffffffff;
    }
    uVar3 = 0x30;
    pcVar2 = "[%s-%d] flash_settings_read error,ret is %d \n";
  }
  printk(pcVar2,"load_whitelist",uVar3,uVar1);
  return 0xffffffff;
}


