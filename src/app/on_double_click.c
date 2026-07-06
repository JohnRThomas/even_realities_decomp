/*
 * Function: on_double_click
 * Entry:    0002acb4
 * Prototype: undefined __stdcall on_double_click(void)
 */


void on_double_click(void)

{
  if (BLE_DEBUG == 0) {
    printk("#############################on_double_click################################\n");
  }
  else {
    ble_printk("#############################on_double_click################################\n");
  }
  FUN_00033e2c(2);
  return;
}


