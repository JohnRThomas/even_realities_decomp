/*
 * Function: gatt_delayed_store_find
 * Entry:    0005ce40
 * Prototype: ds_peer * __stdcall gatt_delayed_store_find(uint8_t id, bt_addr_le_t * peer_addr)
 */


/* exclude_from_export */

ds_peer * gatt_delayed_store_find(uint8_t id,bt_addr_le_t *peer_addr)

{
  bool bVar1;
  int iVar2;
  bt_addr_le_t *b;
  
  iVar2 = 0;
  b = &gatt_delayed_store.peer_list0.peer;
  while ((b[-1].a.val[5] != id || (bVar1 = bt_addr_le_eq(peer_addr,b), !bVar1))) {
    iVar2 = iVar2 + 0xc;
    b = (bt_addr_le_t *)(b[1].a.val + 4);
    if (iVar2 == 0x24) {
      return (ds_peer *)0x0;
    }
  }
  return (ds_peer *)(gatt_delayed_store.peer_list0.peer.a.val + iVar2 + -2);
}


