/*
 * Function: bt_keys_foreach_type
 * Entry:    00061a04
 * Prototype: void __stdcall bt_keys_foreach_type(bt_keys_type type, void * func, void * data)
 */


/* exclude_from_export */

void bt_keys_foreach_type(bt_keys_type type,void *func,void *data)

{
  if (func == (void *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","func != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",0xb3);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (((ushort)key_pool.ltk_rand0 & type) != BT_KEYS_PERIPH_LTK) {
    (*func)(&key_pool,data);
  }
  if ((DAT_2000b996 & type) != BT_KEYS_PERIPH_LTK) {
                    /* WARNING: Could not recover jumptable at 0x00061a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*func)(&DAT_2000b988,data);
    return;
  }
  return;
}


