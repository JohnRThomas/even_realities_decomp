/*
 * Function: find_cf_cfg_by_addr
 * Entry:    0005ce08
 * Prototype: gatt_cf_cfg * __stdcall find_cf_cfg_by_addr(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

gatt_cf_cfg * find_cf_cfg_by_addr(uint8_t id,bt_addr_le_t *addr)

{
  bool bVar1;
  int iVar2;
  bt_addr_le_t *b;
  
  iVar2 = 0;
  b = (bt_addr_le_t *)&DAT_2000b8b5;
  while ((b[-1].a.val[5] != id || (bVar1 = bt_addr_le_eq(addr,b), !bVar1))) {
    iVar2 = iVar2 + 0x10;
    b = (bt_addr_le_t *)(b[2].a.val + 1);
    if (iVar2 == 0x30) {
      return (gatt_cf_cfg *)0x0;
    }
  }
  return (gatt_cf_cfg *)(&DAT_2000b8b4 + iVar2);
}


