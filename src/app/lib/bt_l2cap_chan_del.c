/*
 * Function: bt_l2cap_chan_del
 * Entry:    00084f6e
 * Prototype: void __stdcall bt_l2cap_chan_del(bt_l2cap_chan * chan)
 */


/* exclude_from_export */

void bt_l2cap_chan_del(bt_l2cap_chan *chan)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined *puVar1;
  
  puVar1 = chan->ops;
  if (chan->conn != (bt_conn *)0x0) {
    UNRECOVERED_JUMPTABLE = *(code **)(puVar1 + 4);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)();
    }
    chan->conn = (bt_conn *)0x0;
  }
  *(undefined1 *)&chan[9].conn = 0;
  *(undefined2 *)((int)&chan[9].conn + 2) = 0;
  if ((code *)chan->destroy != (code *)0x0) {
    (*(code *)chan->destroy)(chan);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(puVar1 + 0x20);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00084f9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(chan);
    return;
  }
  return;
}


