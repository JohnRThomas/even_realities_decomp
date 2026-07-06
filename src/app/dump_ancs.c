/*
 * Function: dump_ancs
 * Entry:    0004d3f8
 * Prototype: undefined __stdcall dump_ancs(undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


void dump_ancs(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (BLE_DEBUG == 0) {
    printk("app_identifier:(%s)\n",param_2 + 0x10);
  }
  else {
    ble_printk("app_identifier:(%s)\n");
  }
  if (BLE_DEBUG == 0) {
    printk("message:(%s)\n",param_2 + 0x90);
  }
  else {
    ble_printk("message:(%s)\n");
  }
  if (BLE_DEBUG != 0) {
    ble_printk("uid :(%d)\n");
    return;
  }
  printk("uid :(%d)\n",*(undefined4 *)(param_2 + 8));
  return;
}


