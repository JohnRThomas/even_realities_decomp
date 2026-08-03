/*
 * Function: bt_gatt_change_aware
 * Entry:    00086680
 * Prototype: bool __stdcall bt_gatt_change_aware(bt_conn * conn, bool req)
 */


/* exclude_from_export */

bool bt_gatt_change_aware(bt_conn *conn,bool req)

{
  bool bVar1;
  bool bVar2;
  gatt_cf_cfg *cfg;
  int bit;
  atomic_t *target;
  
  cfg = find_cf_cfg(conn);
  if ((cfg != (gatt_cf_cfg *)0x0) && ((int)((uint)cfg->data_CF_NUM_BYTES_ << 0x1f) < 0)) {
    target = (atomic_t *)((int)&cfg->CF_NUM_FLAGS_ + 3);
    bVar1 = atomic_test_bit(target,bit);
    if (!bVar1) {
      if (!req) {
        return bVar1;
      }
      atomic_test_and_clear_bit(target,-3);
      bVar2 = bt_att_fixed_chan_only(conn);
      if (!bVar2) {
        return bVar1;
      }
      bVar2 = bt_att_out_of_sync_sent_on_fixed(conn);
      if (!bVar2) {
        return bVar1;
      }
      atomic_test_and_clear_bit(target,-3);
      bt_att_clear_out_of_sync_sent(conn);
      set_change_aware(cfg,true);
    }
  }
  return true;
}


