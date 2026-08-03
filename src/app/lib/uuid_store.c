/*
 * Function: uuid_store
 * Entry:    00051cc8
 * Prototype: bt_uuid * __stdcall uuid_store(bt_gatt_dm * dm, bt_uuid * uuid)
 */


/* exclude_from_export */

bt_uuid * uuid_store(bt_gatt_dm *dm,bt_uuid *uuid)

{
  bt_gatt_dm *dm_00;
  bt_uuid *d;
  size_t len;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  if (dm == (bt_gatt_dm *)0x0) {
    local_14 = "Uninitialized UUID.";
  }
  else {
    dm_00 = (bt_gatt_dm *)get_uuid_size((bt_uuid *)(uint)*(byte *)&dm->conn);
    d = user_data_alloc(dm_00,len);
    if (d != (bt_uuid *)0x0) {
      memcpy(d,dm,(size_t)dm_00);
      return d;
    }
    local_14 = "No space for a UUID.";
  }
  local_18 = 2;
  LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1040,&local_18,2,in_stack_ffffffd8,in_stack_ffffffdc,
             in_stack_ffffffe0);
  return (bt_uuid *)0x0;
}


