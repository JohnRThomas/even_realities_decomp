/*
 * Function: bt_hci_evt_get_flags
 * Entry:    000845cc
 * Prototype: uint8_t __stdcall bt_hci_evt_get_flags(uint8_t evt)
 */


/* exclude_from_export */

uint8_t bt_hci_evt_get_flags(uint8_t evt)

{
  bool bVar1;
  
  if (evt < 0x10) {
    if (0xd < evt) {
      return '\x01';
    }
    bVar1 = evt == '\x05';
    if (bVar1) {
      evt = '\x03';
    }
  }
  else {
    if (evt == '\x13') {
      return '\x01';
    }
    bVar1 = evt == '\x1a';
    if (bVar1) {
      evt = '\x01';
    }
  }
  if (!bVar1) {
    evt = '\x02';
  }
  return evt;
}


