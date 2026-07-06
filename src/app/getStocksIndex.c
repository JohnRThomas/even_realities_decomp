/*
 * Function: getStocksIndex
 * Entry:    00038b24
 * Prototype: undefined1 __stdcall getStocksIndex(void)
 */


undefined1 getStocksIndex(void)

{
  DAT_20004afb = DAT_2001c4e5;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  %s index = %d\n","getStocksIndex");
    }
    else {
      ble_printk("%s():  %s index = %d\n","getStocksIndex");
    }
  }
  return DAT_20004afb;
}


