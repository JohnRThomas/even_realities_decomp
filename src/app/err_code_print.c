/*
 * Function: err_code_print
 * Entry:    000183a0
 * Prototype: undefined __stdcall err_code_print(undefined4 param_1, undefined4 param_2)
 */


void err_code_print(undefined4 param_1,undefined4 param_2)

{
  char *fmt;
  
  switch(param_2) {
  case 0xa0:
    fmt = "Error: Command ID was not recognized by the Notification Provider.\n";
    break;
  case 0xa1:
    fmt = "Error: Command failed to be parsed on the Notification Provider.\n";
    break;
  case 0xa2:
    fmt = "Error: Parameter does not refer to an existing object on the Notification Provider.\n";
    break;
  case 0xa3:
    fmt = "Error: Perform Notification Action Failed on the Notification Provider.\n";
    break;
  default:
    return;
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
    return;
  }
  ble_printk(fmt);
  return;
}


