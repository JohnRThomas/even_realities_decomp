/*
 * Function: l2cap_send
 * Entry:    000850f8
 * Prototype: void __stdcall l2cap_send(bt_conn * conn, uint16_t cid, net_buf * buf)
 */


/* exclude_from_export */

void l2cap_send(bt_conn *conn,uint16_t cid,net_buf *buf)

{
  int iVar1;
  
  iVar1 = bt_l2cap_send_cb(conn,5,(net_buf *)(uint)cid,(bt_conn_tx_cb_t)0x0,(void *)0x0);
  if (iVar1 != 0) {
    net_buf_unref((net_buf *)(uint)cid);
    return;
  }
  return;
}


