/*
 * Function: bt_conn_get_security
 * Entry:    00084c9a
 * Prototype: bt_security_t __stdcall bt_conn_get_security(bt_conn * conn)
 */


/* exclude_from_export */

bt_security_t bt_conn_get_security(bt_conn *conn)

{
  return conn->sec_level;
}


