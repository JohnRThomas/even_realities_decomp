/*
 * Function: setNewsIndex
 * Entry:    00038c50
 * Prototype: undefined4 __stdcall setNewsIndex(byte param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 setNewsIndex(byte param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_20004afd = param_1;
  DAT_2001c4e4 = param_1;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s():  %s index = %d\n","setNewsIndex","setNewsIndex",(uint)param_1,param_4);
    }
    else {
      ble_printk("%s():  %s index = %d\n","setNewsIndex","setNewsIndex",(uint)param_1);
    }
  }
  return 0;
}


