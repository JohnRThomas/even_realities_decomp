/*
 * Function: bt_conn_set_security
 * Entry:    00084c52
 * Prototype: int __stdcall bt_conn_set_security(bt_conn * conn, bt_security_t sec)
 */


/* exclude_from_export */

int bt_conn_set_security(bt_conn *conn,bt_security_t sec)

{
  bt_conn_flags *target;
  int iVar1;
  bool in_r2;
  
  if (conn->state == 7) {
    target = &conn->flags;
    if ((int)((uint)sec << 0x18) < 0) {
      *target = *target | BT_CONN_FORCE_PAIR;
    }
    else {
      atomic_set_bit_to((atomic_t *)target,-0x801,in_r2);
    }
    conn->required_sec_level = sec & 0x7f;
    iVar1 = bt_smp_start_security(conn);
    if (iVar1 != 0) {
      conn->required_sec_level = conn->sec_level;
    }
  }
  else {
    iVar1 = -0x80;
  }
  return iVar1;
}


