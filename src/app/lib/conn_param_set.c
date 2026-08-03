/*
 * Function: conn_param_set
 * Entry:    000843fe
 * Prototype: void __stdcall conn_param_set(bt_conn * conn, bt_le_conn_param * param)
 */


/* exclude_from_export */

void conn_param_set(bt_conn *conn,bt_le_conn_param *param)

{
  conn_param_data *pcVar1;
  int iVar2;
  k_work_delayable *dwork;
  bt_le_conn_param *param_00;
  undefined4 extraout_r1;
  k_timeout_t delay;
  
  pcVar1 = conn_param_data_get(conn);
  if (pcVar1 == (conn_param_data *)0x0) {
    return;
  }
  iVar2 = bt_conn_le_param_update(conn,param_00);
  dwork = (k_work_delayable *)((int)&pcVar1[3].conn + 2);
  if ((iVar2 != 0) && (iVar2 != -0x78)) {
    delay.ticks._4_4_ = 0x8000;
    delay.ticks._0_4_ = extraout_r1;
    k_work_reschedule(dwork,delay);
    return;
  }
  k_work_cancel_delayable(dwork);
  return;
}


