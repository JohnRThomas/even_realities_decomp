/*
 * Function: tx_notify
 * Entry:    0008522e
 * Prototype: void __stdcall tx_notify(bt_conn * conn)
 */


/* exclude_from_export_ai */

void tx_notify(bt_conn *conn)

{
  uint16_t cid;
  bt_l2cap_le_chan *ch;
  bt_conn_tx *in_r1;
  int in_r2;
  code *pcVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = (code *)in_r1->user_data;
  uVar2 = in_r1->pending_no_cb;
  cid = *(uint16_t *)&in_r1->cb;
  tx_free(in_r1);
  if (in_r2 == 0) {
    ch = (bt_l2cap_le_chan *)bt_l2cap_le_lookup_tx_cid(conn,cid);
    if (ch != (bt_l2cap_le_chan *)0x0) {
      pcVar1 = *(code **)(ch->rx + 0x18);
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)();
      }
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
        (*UNRECOVERED_JUMPTABLE)(conn,uVar2,0);
      }
      l2cap_chan_tx_resume(ch);
      return;
    }
  }
  else if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00085254. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(conn,uVar2);
    return;
  }
  return;
}


