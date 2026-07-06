/*
 * Function: getCalenadrIndex
 * Entry:    00038ce4
 * Prototype: undefined1 __stdcall getCalenadrIndex(void)
 */


undefined1 getCalenadrIndex(void)

{
  DAT_20004b00 = DAT_2001c4e3;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  calendar %s index = %d\n","getCalenadrIndex");
    }
    else {
      ble_printk("%s():  calendar %s index = %d\n","getCalenadrIndex");
    }
  }
  return DAT_20004b00;
}


