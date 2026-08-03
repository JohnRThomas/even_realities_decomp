/*
 * Function: bt_smp_accept
 * Entry:    0005febc
 * Prototype: int __stdcall bt_smp_accept(bt_conn * conn, bt_l2cap_chan * * chan)
 */


/* exclude_from_export */

int bt_smp_accept(bt_conn *conn,bt_l2cap_chan **chan)

{
  int iVar1;
  
  if (DAT_20006720 != 0) {
    iVar1 = bt_smp_accept_error(conn);
    return iVar1;
  }
  DAT_20006724 = &PTR_bt_smp_connected_1_0008f070;
  *chan = (bt_l2cap_chan *)&DAT_20006720;
  return 0;
}


