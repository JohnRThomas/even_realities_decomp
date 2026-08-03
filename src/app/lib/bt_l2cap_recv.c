/*
 * Function: bt_l2cap_recv
 * Entry:    0005af70
 * Prototype: void __stdcall bt_l2cap_recv(bt_conn * conn, net_buf * buf, bool complete)
 */


/* exclude_from_export */

void bt_l2cap_recv(bt_conn *conn,net_buf *buf,bool complete)

{
  void *pvVar1;
  bt_l2cap_le_chan *chan;
  atomic_val_t aVar2;
  uint uVar3;
  byte local_40 [4];
  char *local_3c;
  byte local_20 [4];
  char *local_1c;
  
  if ((buf->field6_0xc).field0.len < 4) {
    uVar3 = 0x1040;
    local_1c = "Too small L2CAP PDU received";
  }
  else {
    pvVar1 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,4);
    chan = (bt_l2cap_le_chan *)bt_l2cap_le_lookup_rx_cid(conn,*(uint16_t *)((int)pvVar1 + 2));
    if (chan == (bt_l2cap_le_chan *)0x0) {
      local_3c = "Ignoring data for unknown channel ID 0x%04x";
      local_40[0] = 3;
      local_40[1] = 0;
      local_40[2] = 0;
      local_40[3] = 0;
      LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1880,local_40);
      goto LAB_0005afce;
    }
    if (0x3f < (ushort)(*(short *)((int)&chan->tx_buf + 2) - 0x40U)) {
      (**(code **)(chan->rx + 0x14))(chan,buf);
      goto LAB_0005afce;
    }
    if (!complete) {
      bt_l2cap_chan_disconnect((bt_l2cap_chan *)chan);
      goto LAB_0005afce;
    }
    if (*(char *)((int)&chan[2].rtx_sync + 1) == '\x04') {
      local_1c = "Ignoring data received while disconnecting";
    }
    else {
      aVar2 = atomic_get((atomic_t *)((int)&chan->tx_queue + 2));
      if (-1 < aVar2 << 0x1e) {
        if ((ushort)(*(short *)((int)&chan[2].rtx_sync + 3) - 0x80U) < 0x80) {
          net_buf_put((k_fifo *)&chan[2]._sdu_len,buf);
          k_work_submit((k_work *)&chan[2].tx_queue);
          return;
        }
        l2cap_chan_le_recv(chan,buf);
        goto LAB_0005afce;
      }
      local_1c = "Ignoring data received while channel has shutdown";
    }
    uVar3 = 0x1080;
  }
  local_20[0] = 2;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,uVar3,local_20);
LAB_0005afce:
  net_buf_unref(buf);
  return;
}


