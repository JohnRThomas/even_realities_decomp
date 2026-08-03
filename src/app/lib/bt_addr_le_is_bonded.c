/*
 * Function: bt_addr_le_is_bonded
 * Entry:    0008474a
 * Prototype: bool __stdcall bt_addr_le_is_bonded(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

bool bt_addr_le_is_bonded(uint8_t id,bt_addr_le_t *addr)

{
  bool bVar1;
  bt_keys *pbVar2;
  
  pbVar2 = bt_keys_find_addr(id,addr);
  bVar1 = false;
  if ((pbVar2 != (bt_keys *)0x0) && (bVar1 = false, (short)pbVar2->ltk_rand0 != 0)) {
    bVar1 = true;
  }
  return bVar1;
}


