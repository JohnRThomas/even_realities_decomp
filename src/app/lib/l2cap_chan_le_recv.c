/*
 * Function: l2cap_chan_le_recv
 * Entry:    0005ae0c
 * Prototype: void __stdcall l2cap_chan_le_recv(bt_l2cap_le_chan * chan, net_buf * buf)
 */


/* exclude_from_export */

void l2cap_chan_le_recv(bt_l2cap_le_chan *chan,net_buf *buf)

{
  ushort uVar1;
  uint16_t uVar2;
  atomic_val_t aVar3;
  int iVar4;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  int *target;
  int *extraout_r3;
  uint uVar9;
  byte local_40 [4];
  char *local_3c;
  uint uStack_38;
  uint local_34;
  byte local_20 [4];
  char *local_1c;
  
  target = (int *)((int)&chan->_sdu + 2);
  do {
    aVar3 = atomic_get(target);
    if (aVar3 == 0) {
      local_1c = "No credits to receive packet";
      goto LAB_0005aeb0;
    }
    target = extraout_r3;
  } while (*extraout_r3 != aVar3);
  *extraout_r3 = aVar3 + -1;
  uVar9 = (uint)(buf->field6_0xc).field0.len;
  uVar6 = (uint)*(ushort *)((int)&chan->tx_work + 2);
  if (uVar6 < uVar9) {
    local_3c = "PDU size > MPS (%u > %u)";
    uVar7 = 0x2080;
    local_40[0] = 4;
    local_40[1] = 0;
    local_40[2] = 0;
    local_40[3] = 0;
    uStack_38 = uVar9;
    local_34 = uVar6;
LAB_0005ae5c:
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,uVar7,local_40);
  }
  else {
    if (*(int *)((int)&chan[2].rx + 2) != 0) {
LAB_0005ae72:
      l2cap_chan_le_recv_seg(chan,buf);
      return;
    }
    if (uVar9 < 2) {
      uVar6 = 0x1080;
      local_1c = "Too short data packet";
    }
    else {
      uVar2 = net_buf_pull_le16((net_buf *)&(buf->field6_0xc).field0);
      uVar6 = (uint)uVar2;
      if ((ushort)chan->tx_work < uVar6) {
        local_1c = "Invalid SDU length";
      }
      else {
        pcVar8 = *(code **)(chan->rx + 0x10);
        if (pcVar8 == (code *)0x0) {
          uStack_38 = (**(code **)(chan->rx + 0x14))(chan,buf);
          if (-1 < (int)uStack_38) {
            if (*(char *)((int)&chan[2].rtx_sync + 1) != '\x03') {
              return;
            }
            l2cap_chan_send_credits(chan,1);
            return;
          }
          if (uStack_38 == 0xffffff89) {
            return;
          }
          uVar7 = 0x1840;
          local_3c = "err %d";
          local_40[0] = 3;
          local_40[1] = 0;
          local_40[2] = 0;
          local_40[3] = 0;
          goto LAB_0005ae5c;
        }
        iVar4 = (*pcVar8)(chan);
        *(int *)((int)&chan[2].rx + 2) = iVar4;
        if (iVar4 != 0) {
          *(uint16_t *)&chan[2].tx = uVar2;
          uVar1 = (buf->field6_0xc).field0.len;
          sVar5 = net_buf_simple_tailroom((net_buf_simple *)(iVar4 + 0xc));
          if (uVar6 - uVar1 < sVar5) {
            sVar5 = uVar6 - (buf->field6_0xc).field0.len;
          }
          else {
            sVar5 = net_buf_simple_tailroom
                              ((net_buf_simple *)(*(int *)((int)&chan[2].rx + 2) + 0xc));
          }
          uVar6 = (uint)*(ushort *)((int)&chan->tx_work + 2);
          uVar6 = ((uVar6 - 1) + sVar5) / uVar6;
          if ((uVar6 & 0xffff) != 0) {
            l2cap_chan_send_credits(chan,(uint16_t)uVar6);
          }
          goto LAB_0005ae72;
        }
        local_1c = "Unable to allocate buffer for SDU";
      }
LAB_0005aeb0:
      uVar6 = 0x1040;
    }
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,uVar6,local_20);
  }
  bt_l2cap_chan_disconnect((bt_l2cap_chan *)chan);
  return;
}


