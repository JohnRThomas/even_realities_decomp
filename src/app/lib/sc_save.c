/*
 * Function: sc_save
 * Entry:    0005d3d4
 * Prototype: void __stdcall sc_save(uint8_t id, bt_addr_le_t * peer, uint16_t start, uint16_t end)
 */


/* exclude_from_export */

void sc_save(uint8_t id,bt_addr_le_t *peer,uint16_t start,uint16_t end)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  gatt_sc_cfg *pgVar4;
  char local_20 [4];
  char *local_1c;
  
  pgVar4 = find_sc_cfg(id,peer);
  if (pgVar4 == (gatt_sc_cfg *)0x0) {
    pgVar4 = find_sc_cfg('\0',(bt_addr_le_t *)&DAT_000f0b50);
    if (pgVar4 == (gatt_sc_cfg *)0x0) {
      local_1c = "unable to save SC: no cfg left";
      local_20[0] = '\x02';
      local_20[1] = '\0';
      local_20[2] = '\0';
      local_20[3] = '\0';
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_20);
      return;
    }
    pgVar4->id = id;
    bt_addr_le_copy(&pgVar4->peer,peer);
  }
  uVar1 = pgVar4->data_end;
  if (pgVar4->data_start == 0) {
    if (uVar1 == 0) {
      pgVar4->data_start = start;
    }
    else {
LAB_0005d442:
      if (end <= uVar1) {
        return;
      }
    }
  }
  else {
    if (pgVar4->data_start <= start) goto LAB_0005d442;
    pgVar4->data_start = start;
    if (end <= uVar1) goto LAB_0005d424;
  }
  pgVar4->data_end = end;
LAB_0005d424:
  bVar2 = bt_addr_le_is_bonded(pgVar4->id,&pgVar4->peer);
  if (!bVar2) {
    return;
  }
  iVar3 = bt_settings_store_sc(pgVar4->id,&pgVar4->peer,&pgVar4->data_start,4);
  if (iVar3 != 0) {
    local_1c = "failed to store SC (err %d)";
    local_20[0] = '\x03';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_20);
  }
  return;
}


