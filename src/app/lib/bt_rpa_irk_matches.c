/*
 * Function: bt_rpa_irk_matches
 * Entry:    00084458
 * Prototype: bool __stdcall bt_rpa_irk_matches(uint8_t * irk, bt_addr_t * addr)
 */


/* exclude_from_export */

bool bt_rpa_irk_matches(uint8_t *irk,bt_addr_t *addr)

{
  bool bVar1;
  int iVar2;
  undefined2 local_24;
  undefined1 local_22;
  undefined3 local_20;
  undefined1 auStack_1d [17];
  
  _local_20 = CONCAT13(auStack_1d[0],*(undefined3 *)(addr->val + 3));
  memset(auStack_1d,0,0xd);
  iVar2 = internal_encrypt_le(irk,(uint8_t *)&local_20,(uint8_t *)&local_20);
  if (iVar2 == 0) {
    local_24 = (undefined2)_local_20;
    local_22 = (undefined1)((uint)_local_20 >> 0x10);
    iVar2 = memcmp(addr,&local_24,3);
    bVar1 = iVar2 == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


