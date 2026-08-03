/*
 * Function: bt_att_connected
 * Entry:    0005bea8
 * Prototype: void __stdcall bt_att_connected(bt_l2cap_chan * chan)
 */


/* exclude_from_export */

void bt_att_connected(bt_l2cap_chan *chan)

{
  chan[0xe].conn = (bt_conn *)((uint)chan[0xe].conn | 4);
  att_chan_mtu_updated((bt_att_chan *)&chan[-1].destroy);
  k_work_init_delayable((k_work_delayable *)&chan[0x11].ops,(void *)0x5cbcd);
  bt_gatt_connected(chan->conn);
  return;
}


