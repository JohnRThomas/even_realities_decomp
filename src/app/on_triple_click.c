/*
 * Function: on_triple_click
 * Entry:    0002ad5c
 * Prototype: undefined __stdcall on_triple_click(void)
 */


void on_triple_click(void)

{
  if (BLE_DEBUG == 0) {
    printk("#############################on_triple_click################################\n");
  }
  else {
    ble_printk("#############################on_triple_click################################\n");
  }
  if (DAT_20019a59 == '\0') {
    __exit_silent_mode();
    return;
  }
  __enter_silent_mode();
  return;
}


