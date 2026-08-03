/*
 * Function: le_phy_update_complete
 * Entry:    0005718c
 * Prototype: void __stdcall le_phy_update_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void le_phy_update_complete(net_buf *buf)

{
  ushort handle;
  uint8_t uVar1;
  bt_conn *conn;
  uint8_t *puVar2;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  uint uStack_20;
  
  puVar2 = (buf->field6_0xc).field0.data;
  handle = *(ushort *)(puVar2 + 1);
  conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_LE);
  if (conn == (bt_conn *)0x0) {
    local_24 = "Unable to lookup conn for handle %u";
    local_28 = 3;
    uStack_20 = (uint)handle;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
  }
  else {
    uVar1 = bt_get_phy(puVar2[3]);
    (conn->le).phy.tx_phy = uVar1;
    uVar1 = bt_get_phy(puVar2[4]);
    (conn->le).phy.rx_phy = uVar1;
    notify_le_phy_updated(conn);
    bt_conn_unref(conn);
  }
  return;
}


