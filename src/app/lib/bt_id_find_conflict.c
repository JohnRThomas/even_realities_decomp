/*
 * Function: bt_id_find_conflict
 * Entry:    000582e8
 * Prototype: bt_keys * __stdcall bt_id_find_conflict(bt_keys * candidate)
 */


/* exclude_from_export */

bt_keys * bt_id_find_conflict(bt_keys *candidate)

{
  bt_keys *local_10;
  bt_keys *local_c;
  
  local_c = (bt_keys *)0x0;
  local_10 = candidate;
  bt_keys_foreach_type(BT_KEYS_LTK,(void *)0x58085,&local_10);
  return local_c;
}


