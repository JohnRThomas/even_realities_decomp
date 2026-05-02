/*
 * Function: is_box_lid_closed
 * Entry:    00030010
 * Prototype: bool __stdcall is_box_lid_closed(void)
 */


bool is_box_lid_closed(void)

{
  bool bVar1;
  
  bVar1 = nfc_box_status[1];
  if ((uint)BOOL_ARRAY_20019a71[1] != (uint)nfc_box_status[1]) {
    printk("[csh_debug_box]isLidCLose is %d \n",(uint)nfc_box_status[1]);
  }
  BOOL_ARRAY_20019a71[1] = bVar1;
  return bVar1;
}


