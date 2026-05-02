/*
 * Function: cleanStocksIndex
 * Entry:    00038bbc
 * Prototype: undefined __stdcall cleanStocksIndex(void)
 */


void cleanStocksIndex(void)

{
  DAT_20004afb = 0;
  DAT_2001c4e5 = 0;
  if (LOG_LEVEL < 3) {
    return;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("%s():  %s index = %d\n","cleanStocksIndex","cleanStocksIndex",0);
    return;
  }
  printk("%s():  %s index = %d\n","cleanStocksIndex","cleanStocksIndex",0);
  return;
}


