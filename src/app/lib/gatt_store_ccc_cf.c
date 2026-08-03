/*
 * Function: gatt_store_ccc_cf
 * Entry:    000866f2
 * Prototype: void __stdcall gatt_store_ccc_cf(uint8_t id, bt_addr_le_t * peer_addr)
 */


/* WARNING: Removing unreachable block (ram,0x00086732) */
/* exclude_from_export */

void gatt_store_ccc_cf(uint8_t id,bt_addr_le_t *peer_addr)

{
  bt_addr_le_t *pbVar1;
  bool bVar2;
  ds_peer *pdVar3;
  int bit;
  uint *target;
  
  pdVar3 = gatt_delayed_store_find(id,peer_addr);
  bVar2 = bt_addr_le_is_bonded(id,peer_addr);
  if ((bVar2) && (pdVar3 != (ds_peer *)0x0)) {
    target = &pdVar3->flags;
    bVar2 = atomic_test_and_clear_bit((atomic_t *)target,-2);
    if ((int)((uint)bVar2 << 0x1f) < 0) {
      bt_gatt_store_ccc(id,peer_addr);
    }
    atomic_test_and_clear_bit((atomic_t *)target,-3);
    bVar2 = atomic_test_bit((atomic_t *)target,bit);
    if (!bVar2) {
      pdVar3->id = bVar2;
      (pdVar3->peer).type = '\0';
      (pdVar3->peer).a.val[0] = '\0';
      (pdVar3->peer).a.val[1] = '\0';
      (pdVar3->peer).a.val[2] = '\0';
      pbVar1 = &pdVar3->peer;
      (pbVar1->a).val[2] = '\0';
      (pbVar1->a).val[3] = '\0';
      (pbVar1->a).val[4] = '\0';
      (pbVar1->a).val[5] = '\0';
      *target = 0;
    }
  }
  return;
}


