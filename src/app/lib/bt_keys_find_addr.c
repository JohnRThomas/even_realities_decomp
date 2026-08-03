/*
 * Function: bt_keys_find_addr
 * Entry:    00061c4c
 * Prototype: bt_keys * __stdcall bt_keys_find_addr(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

bt_keys * bt_keys_find_addr(uint8_t id,bt_addr_le_t *addr)

{
  bt_keys *pbVar1;
  
  pbVar1 = (bt_keys *)(uint)id;
  if (pbVar1 == (bt_keys *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","keys != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",0x12a);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(ushort *)&pbVar1->ltk_rand0 = (ushort)addr | (ushort)pbVar1->ltk_rand0;
  return pbVar1;
}


