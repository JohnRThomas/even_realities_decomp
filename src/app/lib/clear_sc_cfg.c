/*
 * Function: clear_sc_cfg
 * Entry:    000860e0
 * Prototype: void __stdcall clear_sc_cfg(gatt_sc_cfg * cfg)
 */


/* exclude_from_export_ai */

void clear_sc_cfg(gatt_sc_cfg *cfg)

{
  bt_addr_le_t *pbVar1;
  
  cfg->id = '\0';
  (cfg->peer).type = '\0';
  (cfg->peer).a.val[0] = '\0';
  (cfg->peer).a.val[1] = '\0';
  pbVar1 = &cfg->peer;
  (pbVar1->a).val[2] = '\0';
  (pbVar1->a).val[3] = '\0';
  (pbVar1->a).val[4] = '\0';
  (pbVar1->a).val[5] = '\0';
  cfg->data_start = 0;
  cfg->data_end = 0;
  return;
}


