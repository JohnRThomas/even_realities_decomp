/*
 * Function: setCalenadrIndex
 * Entry:    00038d30
 * Prototype: undefined4 __stdcall setCalenadrIndex(byte param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 setCalenadrIndex(byte param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_20004b00 = param_1;
  DAT_2001c4e3 = param_1;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): calendar %s index = %d\n","setCalenadrIndex","setCalenadrIndex",(uint)param_1,
             param_4);
    }
    else {
      ble_printk("%s(): calendar %s index = %d\n","setCalenadrIndex","setCalenadrIndex",
                 (uint)param_1);
    }
  }
  return 0;
}


