/*
 * Function: le_remote_feat_complete
 * Entry:    00056b3c
 * Prototype: void __stdcall le_remote_feat_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void le_remote_feat_complete(net_buf *buf)

{
  ushort handle;
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  bt_conn *conn;
  uint8_t *puVar4;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  uint uStack_20;
  
  puVar4 = (buf->field6_0xc).field0.data;
  handle = *(ushort *)(puVar4 + 1);
  conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_LE);
  if (conn == (bt_conn *)0x0) {
    local_24 = "Unable to lookup conn for handle %u";
    local_28 = 3;
    uStack_20 = (uint)handle;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
  }
  else {
    if (*puVar4 == '\0') {
      uVar1 = puVar4[4];
      uVar2 = puVar4[5];
      uVar3 = puVar4[6];
      (conn->le).features0 = puVar4[3];
      (conn->le).features1 = uVar1;
      (conn->le).features2 = uVar2;
      (conn->le).features3 = uVar3;
      uVar1 = puVar4[8];
      uVar2 = puVar4[9];
      uVar3 = puVar4[10];
      (conn->le).features4 = puVar4[7];
      (conn->le).features5 = uVar1;
      (conn->le).features6 = uVar2;
      (conn->le).features7 = uVar3;
    }
    atomic_or((atomic_t *)&conn->flags,0x2000);
    bt_conn_unref(conn);
  }
  return;
}


