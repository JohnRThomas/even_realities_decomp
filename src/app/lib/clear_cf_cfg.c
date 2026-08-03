/*
 * Function: clear_cf_cfg
 * Entry:    0005d648
 * Prototype: void __stdcall clear_cf_cfg(gatt_cf_cfg * cfg)
 */


/* exclude_from_export_ai */

void clear_cf_cfg(gatt_cf_cfg *cfg)

{
  int extraout_r2;
  
  bt_addr_le_copy(&cfg->peer,(bt_addr_le_t *)&DAT_000f0b50);
  *(undefined1 *)(extraout_r2 + 8) = 0;
  *(undefined4 *)(extraout_r2 + 0xc) = 0;
  return;
}


