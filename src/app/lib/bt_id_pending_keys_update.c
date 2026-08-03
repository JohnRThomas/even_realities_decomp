/*
 * Function: bt_id_pending_keys_update
 * Entry:    000582bc
 * Prototype: void __stdcall bt_id_pending_keys_update(void)
 */


/* exclude_from_export */

void bt_id_pending_keys_update(void)

{
  uint uVar1;
  
  uVar1 = DAT_200020d4;
  DAT_200020d4 = DAT_200020d4 & 0xffff7fff;
  if (-1 < (int)(uVar1 << 0x10)) {
    return;
  }
  bt_keys_foreach_type(BT_KEYS_LTK,(void *)0x848f1,(void *)0x0);
  return;
}


