/*
 * Function: db_changed
 * Entry:    0005d95c
 * Prototype: void __stdcall db_changed(void)
 */


/* exclude_from_export */

void db_changed(void)

{
  bool bVar1;
  bt_conn *conn;
  undefined4 extraout_r1;
  gatt_cf_cfg *cfg;
  int iVar2;
  k_timeout_t timeout;
  
  atomic_test_and_clear_bit((atomic_t *)&DAT_20006628,-9);
  timeout.ticks._4_4_ = 0x148;
  timeout.ticks._0_4_ = extraout_r1;
  bt_long_wq_reschedule(&db_hash.work,timeout);
  iVar2 = 0;
  cfg = (gatt_cf_cfg *)&DAT_2000b8b4;
  do {
    bVar1 = bt_addr_le_eq(&cfg->peer,(bt_addr_le_t *)&DAT_000f0b50);
    if ((!bVar1) && ((int)((uint)cfg->data_CF_NUM_BYTES_ << 0x1f) < 0)) {
      conn = bt_conn_lookup_addr_le('\0',&cfg->peer);
      if (conn != (bt_conn *)0x0) {
        bt_att_clear_out_of_sync_sent(conn);
        bt_conn_unref(conn);
      }
      atomic_test_and_clear_bit((atomic_t *)((int)&cfg->CF_NUM_FLAGS_ + 3),-3);
      set_change_aware(cfg,false);
    }
    iVar2 = iVar2 + 1;
    cfg = (gatt_cf_cfg *)(cfg[1].peer.a.val + 1);
  } while (iVar2 != 3);
  return;
}


