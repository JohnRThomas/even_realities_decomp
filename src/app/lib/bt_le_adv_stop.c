/*
 * Function: bt_le_adv_stop
 * Entry:    00058ca8
 * Prototype: int __stdcall bt_le_adv_stop(void)
 */


/* exclude_from_export */

int bt_le_adv_stop(void)

{
  bool bVar1;
  bt_le_ext_adv *pbVar2;
  bt_conn *conn;
  int iVar3;
  bt_addr_le_t *peer;
  bt_conn_state_t state;
  
  bt_le_lim_adv_cancel_timeout((bt_le_ext_adv *)&bt_dev);
  atomic_set_bit(&DAT_20002028,-0x4001);
  pbVar2 = bt_le_adv_lookup_legacy();
  if ((int)pbVar2 << 0x18 < 0) {
    pbVar2 = bt_le_adv_lookup_legacy();
    if ((int)pbVar2 << 0x15 < 0) {
      bVar1 = adv_is_directed((bt_le_ext_adv *)&bt_dev);
      if (bVar1) {
        state = 5;
        peer = (bt_addr_le_t *)&DAT_20002021;
      }
      else {
        state = 4;
        peer = (bt_addr_le_t *)&DAT_000f0b49;
      }
      conn = bt_conn_lookup_state_le(bt_dev,peer,state);
      if (conn != (bt_conn *)0x0) {
        conn->err = '\0';
        bt_conn_set_state(conn,0);
        bt_conn_unref(conn);
      }
    }
    iVar3 = bt_le_adv_set_enable_legacy((bt_le_ext_adv *)&bt_dev,false);
    return iVar3;
  }
  return ((uint)pbVar2 & 0xff) >> 7;
}


