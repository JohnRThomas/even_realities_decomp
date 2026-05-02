/*
 * Function: getCalenadrIndex
 * Entry:    00038ce4
 * Prototype: byte __stdcall getCalenadrIndex(void)
 */


byte getCalenadrIndex(void)

{
  DAT_20004b00 = DAT_2001c4e3;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  calendar %s index = %d\n","getCalenadrIndex");
    }
    else {
      ble_printk("%s():  calendar %s index = %d\n","getCalenadrIndex","getCalenadrIndex",
                 (uint)DAT_2001c4e3);
    }
  }
  return DAT_20004b00;
}


