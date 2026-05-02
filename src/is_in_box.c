/*
 * Function: is_in_box
 * Entry:    0002ffd8
 * Prototype: bool __stdcall is_in_box(void)
 */


bool is_in_box(void)

{
  bool bVar1;
  undefined4 in_r2;
  
  bVar1 = nfc_box_status[0];
  if ((char *)(uint)BOOL_ARRAY_20019a71[2] != (char *)(uint)nfc_box_status[0]) {
    if (BLE_DEBUG == 0) {
      printk("[csh_debug_box]isInbox is %d \n");
    }
    else {
      ble_printk("[csh_debug_box]isInbox is %d \n",(char *)(uint)nfc_box_status[0],in_r2,BLE_DEBUG);
    }
  }
  BOOL_ARRAY_20019a71[2] = bVar1;
  return bVar1;
}


