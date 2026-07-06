/*
 * Function: is_in_box
 * Entry:    0002ffd8
 * Prototype: bool __stdcall is_in_box(void)
 */


bool is_in_box(void)

{
  bool bVar1;
  
  bVar1 = nfc_box_status[0];
  if ((uint)BOOL_ARRAY_20019a71[2] != (uint)nfc_box_status[0]) {
    if (BLE_DEBUG == 0) {
      printk("[csh_debug_box]isInbox is %d \n",(uint)nfc_box_status[0]);
    }
    else {
      ble_printk("[csh_debug_box]isInbox is %d \n");
    }
  }
  BOOL_ARRAY_20019a71[2] = bVar1;
  return bVar1;
}


