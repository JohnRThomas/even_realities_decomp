/*
 * Function: bt_l2cap_update_conn_param
 * Entry:    00085294
 * Prototype: int __stdcall bt_l2cap_update_conn_param(bt_conn * conn, bt_le_conn_param * param)
 */


/* exclude_from_export */

int bt_l2cap_update_conn_param(bt_conn *conn,bt_le_conn_param *param)

{
  uint8_t code;
  net_buf *buf;
  undefined2 *puVar1;
  int iVar2;
  undefined2 *extraout_r1;
  uint16_t len;
  
  code = get_ident();
  buf = l2cap_create_le_sig_pdu((net_buf *)&DAT_00000012,code,'\b',len);
  if (buf == (net_buf *)0x0) {
    iVar2 = -0xc;
  }
  else {
    puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,8);
    *puVar1 = *extraout_r1;
    puVar1[1] = extraout_r1[1];
    puVar1[2] = extraout_r1[2];
    puVar1[3] = extraout_r1[3];
    iVar2 = bt_l2cap_send_cb(conn,5,buf,(bt_conn_tx_cb_t)0x0,(void *)0x0);
    if (iVar2 != 0) {
      net_buf_unref(buf);
    }
  }
  return iVar2;
}


