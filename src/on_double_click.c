/*
 * Function: on_double_click
 * Entry:    0002acb4
 * Prototype: undefined __stdcall on_double_click(undefined4 param_1, char * param_2, undefined4 param_3)
 */


void on_double_click(undefined4 param_1,char *param_2,undefined4 param_3)

{
  if (BLE_DEBUG == 0) {
    printk("#############################on_double_click################################\n");
  }
  else {
    ble_printk("#############################on_double_click################################\n",
               param_2,param_3,BLE_DEBUG);
  }
  FUN_00033e2c(2);
  return;
}


