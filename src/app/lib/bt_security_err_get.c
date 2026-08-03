/*
 * Function: bt_security_err_get
 * Entry:    000574fc
 * Prototype: bt_security_err __stdcall bt_security_err_get(uint8_t hci_err)
 */


/* exclude_from_export */

bt_security_err bt_security_err_get(uint8_t hci_err)

{
  bt_security_err bVar1;
  
  if (hci_err < 0x2a) {
    bVar1 = "Unable to store name"[hci_err + 0x15];
  }
  else {
    bVar1 = BT_SECURITY_ERR_UNSPECIFIED;
  }
  return bVar1;
}


