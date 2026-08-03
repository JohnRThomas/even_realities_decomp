/*
 * Function: att_get
 * Entry:    0005b838
 * Prototype: bt_att * __stdcall att_get(bt_conn * conn)
 */


/* exclude_from_export_ai */

bt_att * att_get(bt_conn *conn)

{
  bt_l2cap_chan *pbVar1;
  uint uVar2;
  
  if (conn->state == 7) {
    pbVar1 = bt_l2cap_le_lookup_rx_cid(conn,4);
    if ((pbVar1 != (bt_l2cap_chan *)0x0) && ((int)pbVar1[0xe].conn << 0x1d < 0)) {
      return (bt_att *)pbVar1[-1].destroy;
    }
    uVar2 = 0x1040;
  }
  else {
    uVar2 = 0x1080;
  }
  LOG_WRN(&PTR_s_bt_att_0008b8b0,uVar2,&stack0xfffffff0,2,conn);
  return (bt_att *)0x0;
}


