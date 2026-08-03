/*
 * Function: l2cap_chan_le_recv_seg
 * Entry:    0005acb0
 * Prototype: void __stdcall l2cap_chan_le_recv_seg(bt_l2cap_le_chan * chan, net_buf * buf)
 */


/* exclude_from_export */

void l2cap_chan_le_recv_seg(bt_l2cap_le_chan *chan,net_buf *buf)

{
  char cVar1;
  size_t sVar2;
  atomic_t *target;
  atomic_val_t aVar3;
  int iVar4;
  int extraout_r1;
  short sVar5;
  net_buf *buf_00;
  byte local_28 [4];
  char *local_24;
  
  sVar2 = net_buf_frags_len(*(net_buf **)((int)&chan[2].rx + 2));
  sVar5 = (short)sVar2;
  if ((sVar2 & 0xffff) != 0) {
    sVar5 = *(short *)(extraout_r1 + 0x18);
  }
  if ((uint)(ushort)chan[2].tx < (uint)(buf->field6_0xc).field0.len + (sVar2 & 0xffff)) {
    local_24 = "SDU length mismatch";
  }
  else {
    *(short *)(extraout_r1 + 0x18) = sVar5 + 1;
    sVar2 = net_buf_append_bytes
                      (*(net_buf **)((int)&chan[2].rx + 2),(uint)(buf->field6_0xc).field0.len,
                       (buf->field6_0xc).field0.data,(k_timeout_t)0x84e51,(net_buf_allocator_cb)0x0,
                       (void *)((int)&UNK_00084e50 + 1));
    if ((uint)(buf->field6_0xc).field0.len == (sVar2 & 0xffff)) {
      buf_00 = *(net_buf **)((int)&chan[2].rx + 2);
      sVar2 = net_buf_frags_len(buf_00);
      target = (atomic_t *)((int)&chan->_sdu + 2);
      if ((ushort)chan[2].tx <= sVar2) {
        cVar1 = *(char *)((int)&chan[2].rtx_sync + 1);
        *(undefined4 *)((int)&chan[2].rx + 2) = 0;
        *(undefined2 *)&chan[2].tx = 0;
        if (cVar1 == '\x03') {
          aVar3 = atomic_get(target);
          if (aVar3 == 0) {
            iVar4 = (**(code **)(chan->rx + 0x14))(chan,buf_00);
            if (iVar4 < 0) {
              if (iVar4 == -0x77) {
                return;
              }
              LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1840,&stack0xffffffb8);
              bt_l2cap_chan_disconnect((bt_l2cap_chan *)chan);
            }
            else if (*(char *)((int)&chan[2].rtx_sync + 1) == '\x03') {
              l2cap_chan_send_credits(chan,1);
            }
            net_buf_unref(buf_00);
            return;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","atomic_get(&chan->rx.credits) == 0",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",2460);
        }
        else {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                  "bt_l2cap_chan_get_state(&chan->chan) == BT_L2CAP_CONNECTED",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",2459);
        }
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      aVar3 = atomic_get(target);
      if (aVar3 != 0) {
        return;
      }
      l2cap_chan_send_credits(chan,1);
      return;
    }
    local_24 = "Unable to store SDU";
  }
  local_28[0] = 2;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1040,local_28);
  bt_l2cap_chan_disconnect((bt_l2cap_chan *)chan);
  return;
}


