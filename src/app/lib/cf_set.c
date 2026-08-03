/*
 * Function: cf_set
 * Entry:    0005d9d0
 * Prototype: int __stdcall cf_set(char * name, size_t len_rd, settings_read_cb read_cb, void * cb_arg)
 */


/* exclude_from_export_ai */

int cf_set(char *name,size_t len_rd,settings_read_cb read_cb,void *cb_arg)

{
  int iVar1;
  ulong uVar2;
  gatt_cf_cfg *cfg;
  undefined1 *local_58;
  char *local_54;
  char *pcStack_50;
  undefined2 local_4c;
  byte local_48;
  byte local_47;
  char *local_44;
  bt_addr_le_t abStack_40 [3];
  char local_28 [4];
  char *local_24;
  
  if (name == (char *)0x0) {
    local_24 = "Insufficient number of arguments";
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_28);
  }
  else {
    iVar1 = bt_settings_decode_key(name,abStack_40);
    if (iVar1 == 0) {
      settings_name_next(name,&local_44);
      if ((local_44 == (char *)0x0) || (uVar2 = strtoul(local_44,(char **)0x0,10), uVar2 == 0)) {
        cfg = find_cf_cfg_by_addr('\0',abStack_40);
        if (cfg == (gatt_cf_cfg *)0x0) {
          cfg = find_cf_cfg((bt_conn *)0x0);
          if (cfg == (gatt_cf_cfg *)0x0) {
            local_24 = "Unable to restore CF: no cfg left";
            local_28[0] = '\x02';
            local_28[1] = '\0';
            local_28[2] = '\0';
            local_28[3] = '\0';
            LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_28);
            return -0xc;
          }
          cfg->id = 0;
          bt_addr_le_copy(&cfg->peer,abStack_40);
        }
        if (len_rd != 0) {
          iVar1 = (*(code *)read_cb)(cb_arg,&local_48,2);
          if (iVar1 < 0) {
            local_54 = "Failed to decode value (err %zd)";
            local_58 = (undefined1 *)0x3;
            pcStack_50 = (char *)iVar1;
            LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,(char *)&local_58);
            return iVar1;
          }
          cfg->data_CF_NUM_BYTES_ = local_48;
          if (iVar1 == 2) {
            pcStack_50 = (char *)(uint)local_47;
            if (pcStack_50 < 2) {
              set_change_aware_no_store(cfg,(bool)(local_47 & 1));
              return 0;
            }
            local_54 = 
            "Read back bad change-aware value: 0x%x, defaulting peer status to change-unaware";
            local_58 = (undefined1 *)0x3;
            LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1880,(char *)&local_58);
          }
          else {
            local_24 = 
            "Change-aware status not found in settings, defaulting peer status to change-unaware";
            local_28[0] = '\x02';
            local_28[1] = '\0';
            local_28[2] = '\0';
            local_28[3] = '\0';
            LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
          }
          set_change_aware(cfg,false);
          return 0;
        }
        clear_cf_cfg(cfg);
        return 0;
      }
      local_54 = "Invalid local identity %lu";
      local_58 = (undefined1 *)0x3;
      pcStack_50 = (char *)uVar2;
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,(char *)&local_58);
    }
    else {
      local_54 = "Unable to decode address %s";
      local_4c = 0x200;
      local_58 = &DAT_01000003;
      pcStack_50 = name;
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1c40,(char *)&local_58);
    }
  }
  return -0x16;
}


