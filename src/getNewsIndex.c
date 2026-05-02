/*
 * Function: getNewsIndex
 * Entry:    00038c04
 * Prototype: byte __stdcall getNewsIndex(void)
 */


byte getNewsIndex(void)

{
  DAT_20004afd = DAT_2001c4e4;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  %s index = %d\n","getNewsIndex");
    }
    else {
      ble_printk("%s():  %s index = %d\n","getNewsIndex","getNewsIndex",(uint)DAT_2001c4e4);
    }
  }
  return DAT_20004afd;
}


