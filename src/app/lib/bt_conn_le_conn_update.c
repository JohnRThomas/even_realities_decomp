/*
 * Function: bt_conn_le_conn_update
 * Entry:    00084ce2
 * Prototype: int __stdcall bt_conn_le_conn_update(bt_conn * conn, bt_le_conn_param * param)
 */


/* exclude_from_export */

int bt_conn_le_conn_update(bt_conn *conn,bt_le_conn_param *param)

{
  net_buf *buf;
  ushort *buf_00;
  int iVar1;
  
  buf = bt_hci_cmd_create(0x2013,'\x0e');
  if (buf != (net_buf *)0x0) {
    buf_00 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0xe);
    memset(buf_00,0,0xe);
    *buf_00 = conn->handle;
    buf_00[1] = param->interval_min;
    buf_00[2] = param->interval_max;
    buf_00[3] = param->latency;
    buf_00[4] = param->timeout;
    iVar1 = bt_hci_cmd_send_sync(0x2013,buf,(net_buf **)0x0);
    return iVar1;
  }
  return -0x69;
}


