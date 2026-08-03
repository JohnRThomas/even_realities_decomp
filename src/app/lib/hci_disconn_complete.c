/*
 * Function: hci_disconn_complete
 * Entry:    000568a8
 * Prototype: void __stdcall hci_disconn_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_disconn_complete(net_buf *buf)

{
  ushort handle;
  bt_conn *conn;
  uint8_t *puVar1;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  uint uStack_20;
  
  puVar1 = (buf->field6_0xc).field0.data;
  if (*puVar1 == '\0') {
    handle = *(ushort *)(puVar1 + 1);
    conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_ALL);
    if (conn == (bt_conn *)0x0) {
      local_24 = "Unable to look up conn with handle %u";
      local_28 = 3;
      uStack_20 = (uint)handle;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
              in_stack_ffffffd0);
    }
    else {
      conn->err = puVar1[3];
      bt_conn_set_state(conn,0);
      bt_conn_unref(conn);
    }
  }
  return;
}


