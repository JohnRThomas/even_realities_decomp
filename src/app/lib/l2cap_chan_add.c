/*
 * Function: l2cap_chan_add
 * Entry:    0005ab20
 * Prototype: bool __stdcall l2cap_chan_add(bt_conn * conn, bt_l2cap_chan * chan, bt_l2cap_chan_destroy_t destroy)
 */


/* exclude_from_export */

bool l2cap_chan_add(bt_conn *conn,bt_l2cap_chan *chan,bt_l2cap_chan_destroy_t destroy)

{
  bool bVar1;
  bt_l2cap_chan *pbVar2;
  uint uVar3;
  int extraout_r1;
  undefined *extraout_r2;
  sys_snode_t *psVar4;
  byte local_18 [4];
  char *local_14;
  
  if (*(short *)&chan[1].conn == 0) {
    uVar3 = 0x40;
    do {
      pbVar2 = bt_l2cap_le_lookup_rx_cid(conn,(uint16_t)uVar3);
      if (pbVar2 == (bt_l2cap_chan *)0x0) {
        *(short *)&chan[1].conn = (short)extraout_r1;
        destroy = extraout_r2;
        goto LAB_0005ab38;
      }
      uVar3 = extraout_r1 + 1U & 0xffff;
    } while (uVar3 != 0x80);
    local_14 = "Unable to allocate L2CAP channel ID";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1040,local_18);
    bVar1 = false;
  }
  else {
LAB_0005ab38:
    chan->BT_L2CAP_NUM_STATUS_ = 0;
    (chan->node).next = (sys_snode_t *)0x0;
    psVar4 = &chan->node;
    if (*(undefined4 **)&conn->field_0x58 == (undefined4 *)0x0) {
      conn->channels = psVar4;
      *(sys_snode_t **)&conn->field_0x58 = psVar4;
    }
    else {
      **(undefined4 **)&conn->field_0x58 = psVar4;
      *(sys_snode_t **)&conn->field_0x58 = psVar4;
    }
    chan->conn = conn;
    chan->destroy = destroy;
    k_work_init_delayable((k_work_delayable *)&chan[9].destroy,(void *)0x5a7d1);
    if ((ushort)(*(short *)&chan[1].conn - 0x40U) < 0x40) {
      k_work_init((k_work *)&chan[6].BT_L2CAP_NUM_STATUS_,(void *)0x8533b);
      k_queue_init((k_queue *)&chan[7].destroy);
      *(undefined1 *)&chan[9].conn = 1;
    }
    bVar1 = true;
  }
  return bVar1;
}


