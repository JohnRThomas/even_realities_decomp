/*
 * Function: le_adv_start_add_conn
 * Entry:    0005895c
 * Prototype: int __stdcall le_adv_start_add_conn(bt_le_ext_adv * adv, bt_conn * * out_conn)
 */


/* exclude_from_export_ai */

int le_adv_start_add_conn(bt_le_ext_adv *adv,bt_conn **out_conn)

{
  byte id;
  bool bVar1;
  bt_conn *conn;
  bt_conn_state_t state;
  
  id = adv->id;
  DAT_2000206f = id;
  bVar1 = adv_is_directed(adv);
  if (bVar1) {
    bVar1 = bt_conn_exists_le(id,&adv->target_addr);
    if (bVar1) {
      return -0x16;
    }
    conn = bt_conn_add_le(adv->id,&adv->target_addr);
    if (conn != (bt_conn *)0x0) {
      state = 5;
      goto LAB_00058984;
    }
  }
  else {
    conn = bt_conn_add_le(id,(bt_addr_le_t *)&DAT_000f0b49);
    if (conn != (bt_conn *)0x0) {
      state = 4;
LAB_00058984:
      bt_conn_set_state(conn,state);
      *out_conn = conn;
      return 0;
    }
  }
  return -0xc;
}


