/*
 * Function: l2cap_accept
 * Entry:    0005a714
 * Prototype: int __stdcall l2cap_accept(bt_conn * conn, bt_l2cap_chan * * chan)
 */


/* exclude_from_export */

int l2cap_accept(bt_conn *conn,bt_l2cap_chan **chan)

{
  int iVar1;
  
  if (DAT_200063f0 != 0) {
    iVar1 = l2cap_accept_error((int *)conn,(int)chan);
    return iVar1;
  }
  DAT_200063f4 = &PTR_BYTE_0008edf4;
  *chan = (bt_l2cap_chan *)&DAT_200063f0;
  return 0;
}


