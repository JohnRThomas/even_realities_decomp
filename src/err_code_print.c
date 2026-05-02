/*
 * Function: err_code_print
 * Entry:    000183a0
 * Prototype: undefined __stdcall err_code_print(undefined4 param_1, int param_2, undefined4 param_3)
 */


void err_code_print(undefined4 param_1,int param_2,undefined4 param_3)

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
  ble_printk(fmt,(char *)(param_2 + -0xa0),param_3,BLE_DEBUG);
  return;
}


