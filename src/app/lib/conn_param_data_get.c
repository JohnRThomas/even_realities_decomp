/*
 * Function: conn_param_data_get
 * Entry:    00055a88
 * Prototype: conn_param_data * __stdcall conn_param_data_get(bt_conn * conn)
 */


/* exclude_from_export_ai */

conn_param_data * conn_param_data_get(bt_conn *conn)

{
  conn_param_data *pcVar1;
  
  if (bt_smp == conn) {
    pcVar1 = (conn_param_data *)&bt_smp;
  }
  else {
    pcVar1 = (conn_param_data *)0x0;
  }
  return pcVar1;
}


