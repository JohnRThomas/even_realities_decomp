/*
 * Function: bt_keys_get_type
 * Entry:    00061c7c
 * Prototype: bt_keys * __stdcall bt_keys_get_type(bt_keys_type type, uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

bt_keys * bt_keys_get_type(bt_keys_type type,uint8_t id,bt_addr_le_t *addr)

{
  bt_keys *pbVar1;
  
  if (addr == (bt_addr_le_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","addr != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",210);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  pbVar1 = bt_keys_find(type,id,addr);
  if ((pbVar1 == (bt_keys *)0x0) && (pbVar1 = bt_keys_get_addr(id,addr), pbVar1 != (bt_keys *)0x0))
  {
    bt_keys_find_addr((uint8_t)pbVar1,(bt_addr_le_t *)type);
  }
  return pbVar1;
}


