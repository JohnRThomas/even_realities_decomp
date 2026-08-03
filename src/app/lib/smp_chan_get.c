/*
 * Function: smp_chan_get
 * Entry:    00086832
 * Prototype: bt_smp * __stdcall smp_chan_get(bt_conn * conn)
 */


/* exclude_from_export_ai */

bt_smp * smp_chan_get(bt_conn *conn)

{
  bt_l2cap_chan *pbVar1;
  bt_smp *pbVar2;
  
  pbVar1 = bt_l2cap_le_lookup_rx_cid(conn,6);
  if (pbVar1 == (bt_l2cap_chan *)0x0) {
    pbVar2 = (bt_smp *)LOG_SML_CHANNEL_ERR();
    return pbVar2;
  }
  return (bt_smp *)(pbVar1 + -0xc);
}


