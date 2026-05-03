/*
 * Function: on_triple_click
 * Entry:    0002ad5c
 * Prototype: undefined __stdcall on_triple_click(undefined4 param_1, char * param_2, undefined4 param_3)
 */


void on_triple_click(undefined4 param_1,char *param_2,undefined4 param_3)

{
  if (BLE_DEBUG == 0) {
    printk("#############################on_triple_click################################\n");
  }
  else {
    ble_printk("#############################on_triple_click################################\n",
               param_2,param_3,BLE_DEBUG);
  }
  if (DAT_20019a59 == '\0') {
    __exit_silent_mode();
    return;
  }
  __enter_silent_mode();
  return;
}


