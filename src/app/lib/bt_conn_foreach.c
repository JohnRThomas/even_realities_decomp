/*
 * Function: bt_conn_foreach
 * Entry:    00059c0c
 * Prototype: void __stdcall bt_conn_foreach(bt_conn_type type, void * func, void * data)
 */


/* exclude_from_export_ai */

void bt_conn_foreach(bt_conn_type type,void *func,void *data)

{
  bt_conn *conn;
  
  conn = bt_conn_ref(&acl_conns);
  if (conn != (bt_conn *)0x0) {
    if ((type & conn->type) != 0) {
      (*func)(conn,data);
    }
    bt_conn_unref(conn);
    return;
  }
  return;
}


