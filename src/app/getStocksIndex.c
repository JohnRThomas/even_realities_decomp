/*
 * Function: getStocksIndex
 * Entry:    00038b24
 * Prototype: byte __stdcall getStocksIndex(void)
 */


byte getStocksIndex(void)

{
  DAT_20004afb = DAT_2001c4e5;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  %s index = %d\n","getStocksIndex");
    }
    else {
      ble_printk("%s():  %s index = %d\n","getStocksIndex","getStocksIndex",(uint)DAT_2001c4e5);
    }
  }
  return DAT_20004afb;
}


