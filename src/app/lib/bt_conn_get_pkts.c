/*
 * Function: bt_conn_get_pkts
 * Entry:    00059538
 * Prototype: k_sem * __stdcall bt_conn_get_pkts(bt_conn * conn)
 */


/* exclude_from_export_ai */

k_sem * bt_conn_get_pkts(bt_conn *conn)

{
  k_sem *pkVar1;
  
  pkVar1 = (k_sem *)&DAT_20002108;
  if (DAT_20002104 == 0) {
    pkVar1 = (k_sem *)0x0;
  }
  return pkVar1;
}


