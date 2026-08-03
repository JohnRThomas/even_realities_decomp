/*
 * Function: bt_l2cap_disconnected
 * Entry:    00084fa2
 * Prototype: void __stdcall bt_l2cap_disconnected(bt_conn * conn)
 */


/* exclude_from_export */

void bt_l2cap_disconnected(bt_conn *conn)

{
  int *piVar1;
  bt_l2cap_chan *chan;
  sys_snode_t *psVar2;
  
  piVar1 = (int *)conn->channels;
  if (piVar1 != (int *)0x0) {
    chan = (bt_l2cap_chan *)0x0;
    if (*piVar1 != 0) {
      chan = (bt_l2cap_chan *)(*piVar1 + -8);
    }
    bt_l2cap_chan_del((bt_l2cap_chan *)(piVar1 + -2));
    if (chan != (bt_l2cap_chan *)0x0) {
      while (psVar2 = (chan->node).next, psVar2 != (sys_snode_t *)0x0) {
        bt_l2cap_chan_del(chan);
        chan = (bt_l2cap_chan *)(psVar2 + -2);
      }
      bt_l2cap_chan_del(chan);
      return;
    }
  }
  return;
}


