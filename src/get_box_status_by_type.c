/*
 * Function: get_box_status_by_type
 * Entry:    0002ffb0
 * Prototype: bool __stdcall get_box_status_by_type(box_status_t param_1)
 */


bool get_box_status_by_type(box_status_t param_1)

{
  undefined1 uVar1;
  
  if (param_1 < MAX_STATUS_TYPE) {
    uVar1 = nfc_box_status[param_1];
  }
  else {
    uVar1 = 0xfe;
  }
  return (bool)uVar1;
}


