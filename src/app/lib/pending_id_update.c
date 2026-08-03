/*
 * Function: pending_id_update
 * Entry:    000848f0
 * Prototype: void __stdcall pending_id_update(bt_keys * keys, void * data)
 */


/* exclude_from_export */

void pending_id_update(bt_keys *keys,void *data)

{
  byte bVar1;
  
  bVar1 = keys->state;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    keys->state = bVar1 & 0xfe;
    bt_id_add(keys);
    return;
  }
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    keys->state = bVar1 & 0xfd;
    bt_id_del(keys);
    return;
  }
  return;
}


