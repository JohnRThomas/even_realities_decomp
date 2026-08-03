/*
 * Function: smp_notify_finished
 * Entry:    00084444
 * Prototype: void __stdcall smp_notify_finished(bt_conn * conn, void * user_data)
 */


/* exclude_from_export_ai */

void smp_notify_finished(bt_conn *conn,void *user_data)

{
  conn_param_data *pcVar1;
  
  pcVar1 = conn_param_data_get(conn);
  if (pcVar1 != (conn_param_data *)0x0) {
    k_sem_give((k_sem *)(pcVar1 + 6));
    return;
  }
  return;
}


