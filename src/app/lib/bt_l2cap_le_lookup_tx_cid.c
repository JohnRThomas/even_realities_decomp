/*
 * Function: bt_l2cap_le_lookup_tx_cid
 * Entry:    00085206
 * Prototype: bt_l2cap_chan * __stdcall bt_l2cap_le_lookup_tx_cid(bt_conn * conn, uint16_t cid)
 */


/* exclude_from_export */

bt_l2cap_chan * bt_l2cap_le_lookup_tx_cid(bt_conn *conn,uint16_t cid)

{
  int *piVar1;
  bt_l2cap_chan *pbVar2;
  
  for (piVar1 = (int *)conn->channels;
      (pbVar2 = (bt_l2cap_chan *)0x0, piVar1 != (int *)0x0 &&
      (pbVar2 = (bt_l2cap_chan *)(piVar1 + -2), *(uint16_t *)(piVar1 + 7) != cid));
      piVar1 = (int *)*piVar1) {
  }
  return pbVar2;
}


