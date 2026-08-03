/*
 * Function: set_all_change_unaware
 * Entry:    0005dbc8
 * Prototype: void __stdcall set_all_change_unaware(void)
 */


/* exclude_from_export */

void set_all_change_unaware(void)

{
  bool bVar1;
  gatt_cf_cfg *cfg;
  int iVar2;
  
  iVar2 = 0;
  cfg = (gatt_cf_cfg *)&DAT_2000b8b4;
  do {
    bVar1 = bt_addr_le_eq(&cfg->peer,(bt_addr_le_t *)&DAT_000f0b50);
    if (!bVar1) {
      set_change_aware_no_store(cfg,false);
      bt_gatt_store_cf(cfg->id,&cfg->peer);
    }
    iVar2 = iVar2 + 1;
    cfg = (gatt_cf_cfg *)(cfg[1].peer.a.val + 1);
  } while (iVar2 != 3);
  return;
}


