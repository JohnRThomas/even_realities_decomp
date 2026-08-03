/*
 * Function: bt_gatt_clear_sc
 * Entry:    0005d2f0
 * Prototype: int __stdcall bt_gatt_clear_sc(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

int bt_gatt_clear_sc(uint8_t id,bt_addr_le_t *addr)

{
  gatt_sc_cfg *cfg;
  int iVar1;
  char local_20 [4];
  char *local_1c;
  int iStack_18;
  
  cfg = find_sc_cfg(id,addr);
  if (cfg != (gatt_sc_cfg *)0x0) {
    iVar1 = bt_settings_delete_sc(cfg->id,&cfg->peer);
    if (iVar1 != 0) {
      local_1c = "failed to delete SC (err %d)";
      local_20[0] = '\x03';
      local_20[1] = '\0';
      local_20[2] = '\0';
      local_20[3] = '\0';
      iStack_18 = iVar1;
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_20);
    }
    clear_sc_cfg(cfg);
  }
  return 0;
}


