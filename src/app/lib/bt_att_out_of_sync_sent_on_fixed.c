/*
 * Function: bt_att_out_of_sync_sent_on_fixed
 * Entry:    00085d4c
 * Prototype: bool __stdcall bt_att_out_of_sync_sent_on_fixed(bt_conn * conn)
 */


/* exclude_from_export */

bool bt_att_out_of_sync_sent_on_fixed(bt_conn *conn)

{
  bool bVar1;
  bt_l2cap_chan *pbVar2;
  
  pbVar2 = bt_l2cap_le_lookup_rx_cid(conn,4);
  bVar1 = false;
  if (pbVar2 != (bt_l2cap_chan *)0x0) {
    bVar1 = SUB41(((uint)pbVar2[0xe].conn & 0x3f) >> 5,0);
  }
  return bVar1;
}


