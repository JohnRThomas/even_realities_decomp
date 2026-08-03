/*
 * Function: bt_gatt_cancel
 * Entry:    000865dc
 * Prototype: void __stdcall bt_gatt_cancel(bt_conn * conn, void * params)
 */


/* exclude_from_export_ai */

void bt_gatt_cancel(bt_conn *conn,void *params)

{
  bt_att_req *req;
  code *pcVar1;
  void *pvVar2;
  
  pvVar2 = params;
  z_sched_lock();
  req = bt_att_find_req_by_user_data(conn,params);
  if (req == (bt_att_req *)0x0) {
    k_sched_unlock();
    return;
  }
  pcVar1 = (code *)req->func;
  bt_att_req_cancel(conn,req);
  k_sched_unlock();
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(conn,0xe,0,0,params,pvVar2);
  }
  return;
}


