/*
 * Function: find_sc_cfg
 * Entry:    0005ce78
 * Prototype: gatt_sc_cfg * __stdcall find_sc_cfg(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

gatt_sc_cfg * find_sc_cfg(uint8_t id,bt_addr_le_t *addr)

{
  bool bVar1;
  int iVar2;
  bt_addr_le_t *a;
  
  iVar2 = 0;
  a = &sc_cfg.peer;
  while ((a[-1].a.val[5] != id || (bVar1 = bt_addr_le_eq(a,addr), !bVar1))) {
    iVar2 = iVar2 + 0xc;
    a = (bt_addr_le_t *)(a[1].a.val + 4);
    if (iVar2 == 0x24) {
      return (gatt_sc_cfg *)0x0;
    }
  }
  return (gatt_sc_cfg *)(sc_cfg.peer.a.val + iVar2 + -2);
}


