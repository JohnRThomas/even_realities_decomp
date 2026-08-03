/*
 * Function: bt_l2cap_send_cb
 * Entry:    00084fd8
 * Prototype: int __stdcall bt_l2cap_send_cb(bt_conn * conn, uint16_t cid, net_buf * buf, bt_conn_tx_cb_t cb, void * user_data)
 */


/* exclude_from_export_ai */

int bt_l2cap_send_cb(bt_conn *conn,uint16_t cid,net_buf *buf,bt_conn_tx_cb_t cb,void *user_data)

{
  uint16_t uVar1;
  int iVar2;
  k_tid_t puVar3;
  net_buf *data;
  short *psVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  k_timeout_t timeout;
  dword in_stack_ffffffa8;
  uint8_t *in_stack_ffffffac;
  void *in_stack_ffffffb0;
  undefined4 local_48;
  char *local_44;
  uint uStack_40;
  undefined4 local_3c;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  
  psVar4 = net_buf_push((net_buf *)&(buf->field6_0xc).field0,4);
  uVar1 = (buf->field6_0xc).field0.len;
  psVar4[1] = cid;
  *psVar4 = uVar1 - 4;
  uStack_40 = (uint)buf->user_data_size;
  if (uStack_40 < 8) {
    local_44 = "not enough room in user_data %d < %d";
    local_3c = 8;
    local_48 = 4;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x2040,&local_48,4,in_stack_ffffffa8,in_stack_ffffffac,
            in_stack_ffffffb0);
    return -0x16;
  }
  if (conn->state == 7) {
    if (cb == (bt_conn_tx_cb_t)0x0) {
      data = (net_buf *)0x0;
    }
    else {
      puVar3 = k_current_get();
      if (puVar3 == &k_sys_work_q) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xffffffff;
      }
      timeout.ticks._4_4_ = uVar5;
      timeout.ticks._0_4_ = extraout_r1;
      data = k_fifo_get(&free_tx,timeout);
      if (data == (net_buf *)0x0) {
        return -0x69;
      }
      if (conn->state != 7) {
        local_24 = "Disconnected while allocating context";
        local_28 = 2;
        LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1080,&local_28,2,in_stack_ffffffc8,in_stack_ffffffcc,
                in_stack_ffffffd0);
        data->frags = (net_buf *)0x0;
        data->ref = '\0';
        data->flags = '\0';
        data->pool_id = '\0';
        data->user_data_size = '\0';
        (data->field6_0xc).field0.data = (uint8_t *)0x0;
        k_queue_append(&free_tx._queue,data);
        goto LAB_000597d8;
      }
      data->frags = (net_buf *)cb;
      *(void **)&data->ref = user_data;
      (data->field6_0xc).field0.data = (uint8_t *)0x0;
    }
    buf->user_data = (uint8_t *)data;
    iVar2 = 0;
    *(undefined1 *)&buf[1].node.next = 0;
    net_buf_put(&conn->tx_queue,buf);
  }
  else {
    local_24 = "not connected!";
    local_28 = 2;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1040,&local_28,2,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
LAB_000597d8:
    iVar2 = -0x80;
  }
  return iVar2;
}


