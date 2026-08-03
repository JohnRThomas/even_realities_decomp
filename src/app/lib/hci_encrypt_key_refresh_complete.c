/*
 * Function: hci_encrypt_key_refresh_complete
 * Entry:    000575b4
 * Prototype: void __stdcall hci_encrypt_key_refresh_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_encrypt_key_refresh_complete(net_buf *buf)

{
  ushort handle;
  bt_security_err bVar1;
  bool bVar2;
  bt_conn *conn;
  uint8_t uVar3;
  uint8_t *puVar4;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  uint uStack_38;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  puVar4 = (buf->field6_0xc).field0.data;
  handle = *(ushort *)(puVar4 + 1);
  uVar3 = *puVar4;
  conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_ALL);
  if (conn == (bt_conn *)0x0) {
    local_3c = "Unable to look up conn with handle %u";
    local_40 = 3;
    uStack_38 = (uint)handle;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_40,3,in_stack_ffffffb0,in_stack_ffffffb4,
            in_stack_ffffffb8);
    return;
  }
  if (uVar3 == '\0') {
    uVar3 = puVar4[3];
    conn->encrypt = uVar3;
    if (conn->type == BT_CONN_TYPE_LE) {
      if (uVar3 != '\0') {
        bt_smp_update_keys(conn);
      }
      bVar2 = update_sec_level(conn);
      if (!bVar2) {
        bVar1 = bt_security_err_get('\x05');
        bt_conn_security_changed(conn,'\x05',bVar1);
        local_1c = "Failed to set required security level";
        local_20 = 2;
        LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
                in_stack_ffffffd8);
        bt_conn_disconnect(conn,'\x05');
        goto LAB_00057608;
      }
    }
    bVar1 = bt_security_err_get('\0');
    uVar3 = '\0';
  }
  else {
    bVar1 = bt_security_err_get(uVar3);
  }
  bt_conn_security_changed(conn,uVar3,bVar1);
LAB_00057608:
  bt_conn_unref(conn);
  return;
}


