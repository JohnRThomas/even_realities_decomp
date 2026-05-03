/*
 * Function: is_box_charging
 * Entry:    00030038
 * Prototype: bool __stdcall is_box_charging(void)
 */


bool is_box_charging(void)

{
  bool bVar1;
  
  bVar1 = nfc_box_status[2];
  if ((uint)BOOL_ARRAY_20019a71[0] != (uint)nfc_box_status[2]) {
    printk("[csh_debug_box] isInCharge is %d \n",(uint)nfc_box_status[2]);
  }
  BOOL_ARRAY_20019a71[0] = bVar1;
  return bVar1;
}


