/*
 * Function: id_add
 * Entry:    00061890
 * Prototype: void __stdcall id_add(bt_keys * keys, void * user_data)
 */


/* exclude_from_export */

void id_add(bt_keys *keys,void *user_data)

{
  if (keys == (bt_keys *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","keys != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",0x1af);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  bt_id_add(keys);
  return;
}


