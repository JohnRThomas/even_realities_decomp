/*
 * Function: chan_req_sent
 * Entry:    00085ab4
 * Prototype: void __stdcall chan_req_sent(bt_conn * conn, void * user_data, int err)
 */


/* exclude_from_export_ai */

void chan_req_sent(bt_conn *conn,void *user_data,int err)

{
  void *extraout_r1;
  void *pvVar1;
  k_timeout_t delay;
  
  pvVar1 = user_data;
  if (err == 0) {
    tx_meta_data(conn,user_data);
    pvVar1 = extraout_r1;
  }
  if (*(int *)(*(int *)user_data + 0x124) != 0) {
    delay.ticks._4_4_ = 0xf0000;
    delay.ticks._0_4_ = pvVar1;
    k_work_reschedule((k_work_delayable *)(*(int *)user_data + 0x160),delay);
  }
  tx_meta_data_free(user_data);
  return;
}


