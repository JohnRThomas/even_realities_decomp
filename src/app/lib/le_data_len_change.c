/*
 * Function: le_data_len_change
 * Entry:    00056778
 * Prototype: void __stdcall le_data_len_change(net_buf * buf)
 */


/* exclude_from_export_ai */

void le_data_len_change(net_buf *buf)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  bt_conn *conn;
  ushort *puVar4;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 uStack_28;
  char *pcStack_24;
  uint uStack_20;
  
  puVar4 = (ushort *)(buf->field6_0xc).field0.data;
  uVar1 = *puVar4;
  conn = bt_conn_lookup_handle(uVar1,BT_CONN_TYPE_LE);
  if (conn == (bt_conn *)0x0) {
    pcStack_24 = "Unable to lookup conn for handle %u";
    uStack_28 = 3;
    uStack_20 = (uint)uVar1;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&uStack_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
  }
  else {
    uVar1 = puVar4[3];
    uVar2 = puVar4[2];
    uVar3 = puVar4[4];
    (conn->le)._pad4 = puVar4[1];
    (conn->rv).version = (char)uVar2;
    (conn->rv)._pad = (char)(uVar2 >> 8);
    (conn->rv).manufacturer = uVar1;
    (conn->rv).subversion = uVar3;
    notify_le_data_len_updated(conn);
    bt_conn_unref(conn);
  }
  return;
}


