/*
 * Function: keys_add_id
 * Entry:    000847ec
 * Prototype: void __stdcall keys_add_id(bt_keys * keys, void * data)
 */


/* exclude_from_export */

void keys_add_id(bt_keys *keys,void *data)

{
  if ((int)((uint)keys->state << 0x1d) < 0) {
    hci_id_add(keys->id,&keys->addr,(uint8_t *)((int)&keys->irk_val0 + 2));
    return;
  }
  return;
}


