/*
 * Function: bt_keys_get_addr
 * Entry:    00061954
 * Prototype: bt_keys * __stdcall bt_keys_get_addr(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

bt_keys * bt_keys_get_addr(uint8_t id,bt_addr_le_t *addr)

{
  bt_keys *pbVar1;
  
  if (addr == (bt_addr_le_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","addr != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",89);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  pbVar1 = bt_keys_get_addr_impl((uint)id,(undefined4 *)addr);
  return pbVar1;
}


