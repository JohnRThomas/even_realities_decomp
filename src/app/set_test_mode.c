/*
 * Function: ?_set_test_mode
 * Entry:    00033d68
 * Prototype: undefined __stdcall ?_set_test_mode(undefined4 param_1)
 */


void __set_test_mode(undefined4 param_1)

{
  if (BLE_DEBUG == 0) {
    printk("set testmode is %d \n",param_1);
  }
  else {
    ble_printk("set testmode is %d \n");
  }
  DAT_2001abc2 = (char)param_1;
  return;
}


