/*
 * Function: sc_set
 * Entry:    0005d1b0
 * Prototype: int __stdcall sc_set(char * name, size_t len_rd, settings_read_cb read_cb, void * cb_arg)
 */


/* exclude_from_export_ai */

int sc_set(char *name,size_t len_rd,settings_read_cb read_cb,void *cb_arg)

{
  bt_addr_le_t *pbVar1;
  int iVar2;
  gatt_sc_cfg *pgVar3;
  undefined1 *local_58;
  char *local_54;
  char *pcStack_50;
  undefined2 local_4c;
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
    iVar2 = bt_settings_decode_key(name,abStack_40);
    if (iVar2 == 0) {
      settings_name_next(name,&local_44);
      if ((local_44 == (char *)0x0) ||
         (pcStack_50 = (char *)strtoul(local_44,(char **)0x0,10), pcStack_50 == (char *)0x0)) {
        pgVar3 = find_sc_cfg('\0',abStack_40);
        if (pgVar3 == (gatt_sc_cfg *)0x0) {
          if (len_rd == 0) {
            return 0;
          }
          pgVar3 = find_sc_cfg('\0',(bt_addr_le_t *)&DAT_000f0b50);
          if (pgVar3 == (gatt_sc_cfg *)0x0) {
            local_24 = "Unable to restore SC: no cfg left";
            local_28[0] = '\x02';
            local_28[1] = '\0';
            local_28[2] = '\0';
            local_28[3] = '\0';
            LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_28);
            return -0xc;
          }
          pgVar3->id = '\0';
          bt_addr_le_copy(&pgVar3->peer,abStack_40);
        }
        else if (len_rd == 0) {
          pgVar3->id = '\0';
          (pgVar3->peer).type = '\0';
          (pgVar3->peer).a.val[0] = '\0';
          (pgVar3->peer).a.val[1] = '\0';
          pbVar1 = &pgVar3->peer;
          (pbVar1->a).val[2] = '\0';
          (pbVar1->a).val[3] = '\0';
          (pbVar1->a).val[4] = '\0';
          (pbVar1->a).val[5] = '\0';
          pgVar3->data_start = 0;
          pgVar3->data_end = 0;
          return 0;
        }
        iVar2 = (*(code *)read_cb)(cb_arg,&pgVar3->data_start,4);
        if (-1 < iVar2) {
          return 0;
        }
        local_54 = "Failed to decode value (err %zd)";
        local_58 = (undefined1 *)0x3;
        pcStack_50 = (char *)iVar2;
        LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,(char *)&local_58);
        return iVar2;
      }
      local_54 = "Invalid local identity %lu";
      local_58 = (undefined1 *)0x3;
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


