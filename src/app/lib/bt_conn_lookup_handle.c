/*
 * Function: bt_conn_lookup_handle
 * Entry:    00059bb4
 * Prototype: bt_conn * __stdcall bt_conn_lookup_handle(uint16_t handle, bt_conn_type type)
 */


/* exclude_from_export */

bt_conn * bt_conn_lookup_handle(uint16_t handle,bt_conn_type type)

{
  bt_conn *conn;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  uint uStack_20;
  
  conn = conn_lookup_handle(&acl_conns,1,handle);
  if (conn != (bt_conn *)0x0) {
    if ((type & conn->type) != 0) {
      return conn;
    }
    local_24 = "incompatible handle %u";
    local_28 = 3;
    uStack_20 = (uint)handle;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1880,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
    bt_conn_unref(conn);
  }
  return (bt_conn *)0x0;
}


