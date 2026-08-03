/*
 * Function: bt_conn_le_param_update
 * Entry:    00084d32
 * Prototype: int __stdcall bt_conn_le_param_update(bt_conn * conn, bt_le_conn_param * param)
 */


/* exclude_from_export_ai */

int bt_conn_le_param_update(bt_conn *conn,bt_le_conn_param *param)

{
  ushort uVar1;
  bt_conn_flags *target;
  uint uVar2;
  int iVar3;
  
  uVar1 = (conn->le).interval;
  target = &conn->flags;
  if ((((uVar1 < param->interval_min) || (param->interval_max < uVar1)) ||
      ((conn->le).latency != param->latency)) || ((conn->le).timeout != param->timeout)) {
    uVar2 = (*target &
            (BT_CONN_PERIPHERAL_PARAM_UPDATE|BT_CONN_CLEANUP|BT_CONN_BR_PAIRING_INITIATOR|
             BT_CONN_BR_NOBOND|BT_CONN_BR_PAIRING|BT_CONN_USER|BT_CONN_BR_LEGACY_SECURE|
            BT_CONN_AUTO_CONNECT)) >> 7;
    if ((int)(*target << 0x18) < 0) {
      iVar3 = send_conn_le_param_update(conn,param);
      return iVar3;
    }
    (conn->le).interval_min = param->interval_min;
    (conn->le).interval_max = param->interval_max;
    (conn->le).pending_latency = param->latency;
    (conn->le).pending_timeout = param->timeout;
    *target = *target | BT_CONN_PERIPHERAL_PARAM_SET;
  }
  else {
    atomic_set_bit_to((atomic_t *)target,-0x201,SUB21(param->timeout,0));
    uVar2 = 0xffffff88;
  }
  return uVar2;
}


