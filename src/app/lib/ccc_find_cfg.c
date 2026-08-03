/*
 * Function: ccc_find_cfg
 * Entry:    00085e7a
 * Prototype: bt_gatt_ccc_cfg * __stdcall ccc_find_cfg(_bt_gatt_ccc * ccc, bt_addr_le_t * addr, uint8_t id)
 */


/* exclude_from_export_ai */

bt_gatt_ccc_cfg * ccc_find_cfg(_bt_gatt_ccc *ccc,bt_addr_le_t *addr,uint8_t id)

{
  bool bVar1;
  
  if ((uint8_t)*ccc == id) {
    bVar1 = bt_addr_le_eq((bt_addr_le_t *)((int)ccc + 1),addr);
    if (!bVar1) {
      ccc = (_bt_gatt_ccc *)0x0;
    }
  }
  else {
    ccc = (_bt_gatt_ccc *)0x0;
  }
  return ccc;
}


