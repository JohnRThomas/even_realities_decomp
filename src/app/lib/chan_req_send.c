/*
 * Function: chan_req_send
 * Entry:    000857e8
 * Prototype: int __stdcall chan_req_send(bt_att_chan * chan, bt_att_req * req)
 */


/* exclude_from_export_ai */

int chan_req_send(bt_att_chan *chan,bt_att_req *req)

{
  size_t sVar1;
  int iVar2;
  dword extraout_r1;
  uint uVar3;
  uint uVar4;
  net_buf *buf;
  
  sVar1 = net_buf_frags_len((net_buf *)req->buf);
  uVar4 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
  uVar3 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
  if (uVar3 <= uVar4) {
    uVar4 = uVar3;
  }
  if (uVar4 < sVar1) {
    iVar2 = -0x7a;
  }
  else {
    chan[8].chan = extraout_r1;
    buf = *(net_buf **)(extraout_r1 + 8);
    *(undefined4 *)(extraout_r1 + 8) = 0;
    iVar2 = chan_send(chan,buf);
    if (iVar2 != 0) {
      *(net_buf **)(extraout_r1 + 8) = buf;
      chan[8].chan = 0;
    }
  }
  return iVar2;
}


