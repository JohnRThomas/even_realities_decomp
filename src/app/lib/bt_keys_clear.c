/*
 * Function: bt_keys_clear
 * Entry:    00061cc4
 * Prototype: void __stdcall bt_keys_clear(bt_keys * keys)
 */


/* exclude_from_export_ai */

void bt_keys_clear(bt_keys *keys)

{
  bt_addr_le_t *in_r2;
  bt_addr_le_t *extraout_r2;
  
  if (keys == (bt_keys *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","keys != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",305);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((int)((uint)keys->state << 0x1d) < 0) {
    bt_id_del(keys);
    in_r2 = extraout_r2;
  }
  bt_settings_delete((char *)(uint)keys->id,(char)keys + '\x01',in_r2);
  memset(keys,0,0x5c);
  return;
}


