/*
 * Function: setStocksIndex
 * Entry:    00038b70
 * Prototype: undefined4 __stdcall setStocksIndex(byte param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 setStocksIndex(byte param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_20004afb = param_1;
  DAT_2001c4e5 = param_1;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  %s index = %d\n","setStocksIndex","setStocksIndex",(uint)param_1,param_4);
    }
    else {
      ble_printk("%s():  %s index = %d\n","setStocksIndex","setStocksIndex",(uint)param_1);
    }
  }
  return 0;
}


