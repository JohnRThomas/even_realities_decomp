/*
 * Function: bt_att_create_rsp_pdu
 * Entry:    0005c1e0
 * Prototype: net_buf * __stdcall bt_att_create_rsp_pdu(bt_att_chan * chan, uint8_t op, size_t len)
 */


/* exclude_from_export */

net_buf * bt_att_create_rsp_pdu(bt_att_chan *chan,uint8_t op,size_t len)

{
  net_buf *pnVar1;
  uint uVar2;
  byte local_30 [4];
  char *local_2c;
  bt_att_chan *pbStack_28;
  uint local_24;
  uint uStack_20;
  
  local_24 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
  uVar2 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
  uStack_20 = len + 1;
  if (uVar2 <= local_24) {
    local_24 = uVar2;
  }
  if (local_24 < uStack_20) {
    local_2c = "ATT channel %p MTU too small for RSP (%u < %u)";
    local_30[0] = 5;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    pbStack_28 = chan;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x2880,local_30);
    pnVar1 = (net_buf *)0x0;
  }
  else {
    pnVar1 = bt_att_chan_create_pdu(chan,op,len);
  }
  return pnVar1;
}


