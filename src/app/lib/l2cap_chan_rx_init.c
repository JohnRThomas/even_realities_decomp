/*
 * Function: l2cap_chan_rx_init
 * Entry:    0005a730
 * Prototype: void __stdcall l2cap_chan_rx_init(bt_l2cap_le_chan * chan)
 */


/* exclude_from_export */

void l2cap_chan_rx_init(bt_l2cap_le_chan *chan)

{
  dword dVar1;
  uint uVar2;
  uint uVar3;
  byte local_10 [4];
  char *local_c;
  
  if ((short)chan->tx_work == 0) {
    *(undefined2 *)&chan->tx_work = 0x1f0;
  }
  uVar2 = (uint)(ushort)chan->tx_work;
  dVar1 = chan->rx;
  uVar3 = uVar2;
  if (0x1ef < uVar2) {
    uVar3 = 0x1f0;
  }
  *(short *)((int)&chan->tx_work + 2) = (short)(uVar3 + 2);
  if ((*(int *)(dVar1 + 0x10) == 0) && ((uVar3 + 2 & 0xffff) <= uVar2 + 1)) {
    local_c = "Segmentation disabled but MTU > MPS, truncating MTU";
    local_10[0] = 2;
    local_10[1] = 0;
    local_10[2] = 0;
    local_10[3] = 0;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1080,local_10);
    *(short *)&chan->tx_work = *(short *)((int)&chan->tx_work + 2) + -2;
  }
  *(undefined4 *)((int)&chan->_sdu + 2) = 1;
  return;
}


