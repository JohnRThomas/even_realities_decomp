/*
 * Function: l2cap_chan_sdu_sent
 * Entry:    00085218
 * Prototype: void __stdcall l2cap_chan_sdu_sent(bt_conn * conn, void * user_data, int err)
 */


/* exclude_from_export_ai */

void l2cap_chan_sdu_sent(bt_conn *conn,void *user_data,int err)

{
  bt_l2cap_le_chan *ch;
  
  if ((err == 0) &&
     (ch = (bt_l2cap_le_chan *)bt_l2cap_le_lookup_tx_cid(conn,*(uint16_t *)((int)user_data + 4)),
     ch != (bt_l2cap_le_chan *)0x0)) {
    l2cap_chan_tx_resume(ch);
    return;
  }
  return;
}


