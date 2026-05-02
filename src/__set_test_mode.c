/*
 * Function: ?_set_test_mode
 * Entry:    00033d68
 * Prototype: undefined __stdcall ?_set_test_mode(char * param_1, undefined4 param_2, undefined4 param_3)
 */


void __set_test_mode(char *param_1,undefined4 param_2,undefined4 param_3)

{
  if (BLE_DEBUG == 0) {
    printk("set testmode is %d \n");
  }
  else {
    ble_printk("set testmode is %d \n",param_1,param_3,BLE_DEBUG);
  }
  DAT_2001abc2 = (char)param_1;
  return;
}


