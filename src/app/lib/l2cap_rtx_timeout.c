/*
 * Function: l2cap_rtx_timeout
 * Entry:    0005a7d0
 * Prototype: undefined __stdcall l2cap_rtx_timeout(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* exclude_from_export */

void l2cap_rtx_timeout(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bt_l2cap_le_chan *chan;
  bt_conn *conn;
  byte local_28 [4];
  char *local_24;
  bt_l2cap_le_chan *pbStack_20;
  undefined4 uStack_18;
  
  chan = (bt_l2cap_le_chan *)(param_1 + -0xc0);
  conn = *(bt_conn **)(param_1 + -0xc0);
  local_24 = "chan %p timeout";
  local_28[0] = 3;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  pbStack_20 = chan;
  uStack_18 = param_4;
  LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1840,local_28);
  bt_l2cap_chan_remove(conn,(bt_l2cap_chan *)chan);
  do {
    bt_l2cap_chan_del((bt_l2cap_chan *)chan);
    chan = __l2cap_lookup_ident(conn,(ushort)*(byte *)((int)&chan[3].chan + 1),true);
  } while (chan != (bt_l2cap_le_chan *)0x0);
  return;
}


