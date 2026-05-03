/*
 * Function: set_box_status
 * Entry:    0002ffc0
 * Prototype: void __stdcall set_box_status(box_status_t status_type, bool new_status)
 */


void set_box_status(box_status_t status_type,bool new_status)

{
  if (status_type < MAX_STATUS_TYPE) {
    if (new_status) {
      nfc_box_status[status_type] = true;
      return;
    }
    nfc_box_status[status_type] = false;
  }
  return;
}


