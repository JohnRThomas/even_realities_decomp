/*
 * Function: l2cap_chan_le_send_sdu
 * Entry:    0008500a
 * Prototype: int __stdcall l2cap_chan_le_send_sdu(bt_l2cap_le_chan * ch, net_buf * * buf, uint16_t sent)
 */


/* exclude_from_export */

int l2cap_chan_le_send_sdu(bt_l2cap_le_chan *ch,net_buf **buf,uint16_t sent)

{
  size_t sVar1;
  uint uVar2;
  undefined4 *extraout_r1;
  net_buf *buf_00;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)sent;
  buf_00 = *buf;
  sVar1 = net_buf_frags_len(buf_00);
  iVar3 = uVar4 + sVar1;
  if ((int)(uint)(ushort)ch->rx_queue < iVar3) {
    uVar4 = 0xffffff86;
  }
  else {
    if (((buf_00->field6_0xc).field0.len == 0) && (buf_00->frags != (net_buf *)0x0)) {
      buf_00 = buf_00->frags;
    }
    if (uVar4 == 0) {
      uVar2 = l2cap_chan_le_send(ch,buf_00,2);
      if ((int)uVar2 < 0) {
LAB_00085046:
        if (uVar2 == 0xfffffff5) {
          *(uint *)buf_00->user_data = uVar4;
        }
        *extraout_r1 = buf_00;
        return uVar2;
      }
      uVar4 = uVar2 & 0xffff;
    }
    for (; (int)uVar4 < iVar3; uVar4 = uVar4 + uVar2 & 0xffff) {
      if ((buf_00->field6_0xc).field0.len == 0) {
        buf_00 = net_buf_frag_del((net_buf *)0x0,buf_00);
      }
      uVar2 = l2cap_chan_le_send(ch,buf_00,0);
      if ((int)uVar2 < 0) goto LAB_00085046;
    }
    net_buf_unref(buf_00);
  }
  return uVar4;
}


