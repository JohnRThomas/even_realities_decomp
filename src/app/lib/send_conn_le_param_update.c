/*
 * Function: send_conn_le_param_update
 * Entry:    0005a2e4
 * Prototype: int __stdcall send_conn_le_param_update(bt_conn * conn, bt_le_conn_param * param)
 */


/* exclude_from_export */

int send_conn_le_param_update(bt_conn *conn,bt_le_conn_param *param)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = bt_le_conn_params_valid(param);
  if (bVar1) {
    if ((((-1 < (int)((uint)(byte)DAT_200020d8 << 0x1e)) ||
         (-1 < (int)((uint)(conn->le).features0 << 0x1e))) || ((int)(conn->flags << 0x15) < 0)) &&
       (conn->role != '\0')) {
      iVar2 = bt_l2cap_update_conn_param(conn,param);
      return iVar2;
    }
    iVar2 = bt_conn_le_conn_update(conn,param);
    if (iVar2 == 0) {
      (conn->le).interval_min = param->interval_min;
      (conn->le).interval_max = param->interval_max;
      (conn->le).pending_latency = param->latency;
      (conn->le).pending_timeout = param->timeout;
    }
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}


