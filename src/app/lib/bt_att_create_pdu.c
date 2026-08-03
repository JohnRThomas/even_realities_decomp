/*
 * Function: bt_att_create_pdu
 * Entry:    0005c15c
 * Prototype: net_buf * __stdcall bt_att_create_pdu(bt_conn * conn, uint8_t op, size_t len)
 */


/* exclude_from_export_ai */

net_buf * bt_att_create_pdu(bt_conn *conn,uint8_t op,size_t len)

{
  bt_att *pbVar1;
  bt_att_chan *chan;
  net_buf *pnVar2;
  uint uVar3;
  int *piVar4;
  bt_att_chan *pbVar5;
  bt_att_chan *pbVar6;
  uint uVar7;
  byte local_28 [4];
  char *local_24;
  uint uStack_20;
  
  pbVar1 = att_get(conn);
  if (pbVar1 != (bt_att *)0x0) {
    piVar4 = *(int **)((int)&pbVar1[1].prep_queue + 2);
    if (piVar4 == (int *)0x0) {
      chan = (bt_att_chan *)0x0;
      pbVar5 = (bt_att_chan *)0x0;
    }
    else {
      chan = (bt_att_chan *)(piVar4 + -100);
      pbVar5 = (bt_att_chan *)0x0;
      if (*piVar4 != 0) {
        pbVar5 = (bt_att_chan *)(*piVar4 + -400);
      }
    }
    uStack_20 = len + 1;
    if (chan != (bt_att_chan *)0x0) {
      while( true ) {
        pbVar6 = pbVar5;
        uVar3 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
        uVar7 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
        if (uVar7 <= uVar3) {
          uVar3 = uVar7;
        }
        if (uStack_20 <= uVar3) {
          pnVar2 = bt_att_chan_create_pdu(chan,op,len);
          return pnVar2;
        }
        if (pbVar6 == (bt_att_chan *)0x0) break;
        chan = pbVar6;
        pbVar5 = (bt_att_chan *)0x0;
        if (pbVar6[0xb].chan != 0) {
          pbVar5 = (bt_att_chan *)(pbVar6[0xb].chan - 400);
        }
      }
    }
    local_24 = "No ATT channel for MTU %zu";
    local_28[0] = 3;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1880,local_28);
  }
  return (net_buf *)0x0;
}


