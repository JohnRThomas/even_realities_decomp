/*
 * Function: bt_conn_recv
 * Entry:    00059640
 * Prototype: void __stdcall bt_conn_recv(bt_conn * conn, net_buf * buf, uint8_t flags)
 */


/* exclude_from_export */

void bt_conn_recv(bt_conn *conn,net_buf *buf,uint8_t flags)

{
  size_t sVar1;
  net_buf *buf_00;
  uint uVar2;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  uint uStack_38;
  uint local_34;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  uint local_20;
  char *local_1c;
  
  uVar2 = (uint)flags;
  tx_notify(conn);
  if (uVar2 == 1) {
    if (conn->rx != (net_buf *)0x0) {
      uVar2 = (uint)(buf->field6_0xc).field0.len;
      if (uVar2 != 0) {
        sVar1 = net_buf_simple_tailroom(&(conn->rx->field6_0xc).b);
        if (uVar2 <= sVar1) {
          net_buf_add_mem((net_buf *)&(conn->rx->field6_0xc).field0,(buf->field6_0xc).field0.data,
                          (uint)(buf->field6_0xc).field0.len);
          net_buf_unref(buf);
          goto LAB_0005967a;
        }
        local_1c = "Not enough buffer space for L2CAP data";
        local_20 = 2;
        LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1040,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
                in_stack_ffffffd8);
        bt_l2cap_recv(conn,conn->rx,false);
        conn->rx = (net_buf *)0x0;
      }
      goto LAB_000596de;
    }
    local_1c = "Unexpected L2CAP continuation";
    local_20 = 2;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1040,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
            in_stack_ffffffd8);
  }
  else {
    if (uVar2 == 2) {
      if (conn->rx != (net_buf *)0x0) {
        local_1c = "Unexpected first L2CAP frame";
        local_20 = uVar2;
        LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1040,&local_20,"Unexpected first L2CAP frame",
                in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8);
        bt_conn_reset_rx_state(conn);
      }
      conn->rx = buf;
LAB_0005967a:
      buf_00 = conn->rx;
      uStack_38 = (uint)(buf_00->field6_0xc).field0.len;
      if (uStack_38 < 2) {
        return;
      }
      local_34 = (uint)(ushort)(*(short *)(buf_00->field6_0xc).field0.data + 4);
      if (uStack_38 < local_34) {
        return;
      }
      if (local_34 < uStack_38) {
        local_3c = "ACL len mismatch (%u > %u)";
        local_40 = 4;
        LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x2040,&local_40,4,in_stack_ffffffb0,in_stack_ffffffb4,
                in_stack_ffffffb8);
        bt_conn_reset_rx_state(conn);
        return;
      }
      conn->rx = (net_buf *)0x0;
      bt_l2cap_recv(conn,buf_00,true);
      return;
    }
    local_3c = "Unexpected ACL flags (0x%02x)";
    local_40 = 3;
    uStack_38 = uVar2;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1840,&local_40,3,in_stack_ffffffb0,in_stack_ffffffb4,
            in_stack_ffffffb8);
  }
  bt_conn_reset_rx_state(conn);
LAB_000596de:
  net_buf_unref(buf);
  return;
}


