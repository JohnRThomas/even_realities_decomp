/*
 * Function: bt_keys_find
 * Entry:    00061a74
 * Prototype: bt_keys * __stdcall bt_keys_find(bt_keys_type type, uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

bt_keys * bt_keys_find(bt_keys_type type,uint8_t id,bt_addr_le_t *addr)

{
  int iVar1;
  int iVar2;
  
  if (addr == (bt_addr_le_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","addr != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",192);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((((ushort)key_pool.ltk_rand0 & type) != BT_KEYS_PERIPH_LTK) && (key_pool.id == id)) {
    iVar1 = memcmp(&key_pool.addr,addr,7);
    iVar2 = 0;
    if (iVar1 == 0) goto LAB_00061acc;
  }
  if ((DAT_2000b996 & type) == BT_KEYS_PERIPH_LTK) {
    return (bt_keys *)0x0;
  }
  if ((DAT_2000b988 != id) || (iVar2 = memcmp(&DAT_2000b989,addr,7), iVar2 != 0)) {
    return (bt_keys *)0x0;
  }
  iVar2 = 0x5c;
LAB_00061acc:
  return (bt_keys *)(key_pool.addr.a.val + iVar2 + -2);
}


