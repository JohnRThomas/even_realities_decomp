/*
 * Function: chan_cfm_sent
 * Entry:    00085ade
 * Prototype: void __stdcall chan_cfm_sent(bt_conn * conn, void * user_data, int err)
 */


/* exclude_from_export_ai */

void chan_cfm_sent(bt_conn *conn,void *user_data,int err)

{
  if (err == 0) {
    tx_meta_data(conn,user_data);
  }
  atomic_clear_bit((atomic_t *)(*(int *)user_data + 0x120),1);
  tx_meta_data_free(user_data);
  return;
}


