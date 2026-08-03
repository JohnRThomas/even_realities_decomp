/*
 * Function: sc_restore_rsp
 * Entry:    0008638c
 * Prototype: void __stdcall sc_restore_rsp(bt_conn * conn, bt_gatt_indicate_params * params, uint8_t err)
 */


/* exclude_from_export_ai */

void sc_restore_rsp(bt_conn *conn,bt_gatt_indicate_params *params,uint8_t err)

{
  bool bVar1;
  gatt_cf_cfg *cfg;
  gatt_sc_cfg *pgVar2;
  char acStack_20 [4];
  char *pcStack_1c;
  int iStack_18;
  
  bVar1 = bt_att_fixed_chan_only(conn);
  if (((bVar1) && (cfg = find_cf_cfg(conn), cfg != (gatt_cf_cfg *)0x0)) &&
     ((int)((uint)cfg->data_CF_NUM_BYTES_ << 0x1f) < 0)) {
    set_change_aware(cfg,true);
  }
  if ((err == '\0') &&
     (pgVar2 = find_sc_cfg(conn->id,&(conn->le).dst), pgVar2 != (gatt_sc_cfg *)0x0)) {
    pgVar2->data_start = 0;
    pgVar2->data_end = 0;
    iStack_18 = bt_settings_store_sc(pgVar2->id,&pgVar2->peer,&pgVar2->data_start,4);
    if (iStack_18 != 0) {
      pcStack_1c = "failed to store SC (err %d)";
      acStack_20[0] = '\x03';
      acStack_20[1] = '\0';
      acStack_20[2] = '\0';
      acStack_20[3] = '\0';
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,acStack_20);
    }
    return;
  }
  return;
}


