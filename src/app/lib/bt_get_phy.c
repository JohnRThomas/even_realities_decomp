/*
 * Function: bt_get_phy
 * Entry:    00057178
 * Prototype: uint8_t __stdcall bt_get_phy(uint8_t hci_phy)
 */


/* exclude_from_export_ai */

uint8_t bt_get_phy(uint8_t hci_phy)

{
  uint8_t uVar1;
  
  if ((byte)(hci_phy - 1) < 3) {
    uVar1 = (&DAT_000f1431)[(byte)(hci_phy - 1)];
  }
  else {
    uVar1 = '\0';
  }
  return uVar1;
}


