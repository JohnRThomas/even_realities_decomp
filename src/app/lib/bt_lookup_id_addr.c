/*
 * Function: bt_lookup_id_addr
 * Entry:    00084892
 * Prototype: bt_addr_le_t * __stdcall bt_lookup_id_addr(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

bt_addr_le_t * bt_lookup_id_addr(uint8_t id,bt_addr_le_t *addr)

{
  bt_keys *pbVar1;
  
  if (id == '\0') {
    if ((addr != (bt_addr_le_t *)0x0) &&
       (pbVar1 = bt_keys_find_irk('\0',addr), pbVar1 != (bt_keys *)0x0)) {
      addr = &pbVar1->addr;
    }
  }
  else {
    addr = (bt_addr_le_t *)0x0;
  }
  return addr;
}


