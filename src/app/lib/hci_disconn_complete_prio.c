/*
 * Function: hci_disconn_complete_prio
 * Entry:    000566b8
 * Prototype: void __stdcall hci_disconn_complete_prio(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_disconn_complete_prio(net_buf *buf)

{
  ushort handle;
  bt_conn *conn;
  uint8_t *puVar1;
  
  puVar1 = (buf->field6_0xc).field0.data;
  handle = *(ushort *)(puVar1 + 1);
  if (*puVar1 == '\0') {
    conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_ALL);
    if (conn != (bt_conn *)0x0) {
      bt_conn_set_state(conn,1);
      bt_conn_unref(conn);
      return;
    }
    if (DAT_200108f4 == 0) {
      DAT_200108f4 = ~((ushort)~(ushort)(((uint)handle << 0x14) >> 0x10) >> 4);
    }
  }
  return;
}


