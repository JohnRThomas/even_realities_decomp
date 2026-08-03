/*
 * Function: le_conn_param_req
 * Entry:    000577d4
 * Prototype: void __stdcall le_conn_param_req(net_buf * buf)
 */


/* exclude_from_export_ai */

void le_conn_param_req(net_buf *buf)

{
  ushort handle;
  bool bVar1;
  bt_conn *conn;
  net_buf *buf_00;
  ushort *puVar2;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  uint uStack_28;
  bt_le_conn_param local_20;
  
  puVar2 = (ushort *)(buf->field6_0xc).field0.data;
  local_20.interval_min = puVar2[1];
  handle = *puVar2;
  local_20.interval_max = puVar2[2];
  local_20.latency = puVar2[3];
  local_20.timeout = puVar2[4];
  conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_LE);
  if (conn == (bt_conn *)0x0) {
    local_2c = "Unable to lookup conn for handle %u";
    local_30 = 3;
    uStack_28 = (uint)handle;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_30,3,in_stack_ffffffc0,in_stack_ffffffc4,
            in_stack_ffffffc8);
    le_conn_param_neg_reply(handle,'\x02');
  }
  else {
    bVar1 = le_param_req(conn,&local_20);
    if (bVar1) {
      buf_00 = bt_hci_cmd_create(0x2020,'\x0e');
      if (buf_00 != (net_buf *)0x0) {
        puVar2 = net_buf_add((net_buf *)&(buf_00->field6_0xc).field0,0xe);
        *puVar2 = handle;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[1] = local_20.interval_min;
        puVar2[2] = local_20.interval_max;
        puVar2[3] = local_20.latency;
        puVar2[4] = local_20.timeout;
        bt_hci_cmd_send(0x2020,buf_00);
      }
    }
    else {
      le_conn_param_neg_reply(handle,'\x1e');
    }
    bt_conn_unref(conn);
  }
  return;
}


