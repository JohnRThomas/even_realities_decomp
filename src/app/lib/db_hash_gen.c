/*
 * Function: db_hash_gen
 * Entry:    0005de54
 * Prototype: void __stdcall db_hash_gen(void)
 */


/* exclude_from_export */

void db_hash_gen(void)

{
  uchar uVar1;
  int iVar2;
  db_hash *pdVar3;
  uchar *puVar4;
  uint8_t local_140 [32];
  char local_120 [4];
  char *local_11c;
  undefined auStack_118 [96];
  undefined auStack_b8 [176];
  
  local_140[0] = '\0';
  local_140[1] = '\0';
  local_140[2] = '\0';
  local_140[3] = '\0';
  local_140[4] = '\0';
  local_140[5] = '\0';
  local_140[6] = '\0';
  local_140[7] = '\0';
  local_140[8] = '\0';
  local_140[9] = '\0';
  local_140[10] = '\0';
  local_140[0xb] = '\0';
  local_140[0xc] = '\0';
  local_140[0xd] = '\0';
  local_140[0xe] = '\0';
  local_140[0xf] = '\0';
  iVar2 = tc_cmac_setup(auStack_118,local_140,auStack_b8);
  if (iVar2 == 0) {
    local_11c = "Unable to setup AES CMAC";
  }
  else {
    bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x85dc5,auStack_118);
    iVar2 = tc_cmac_final(&DAT_20006560,auStack_118);
    if (iVar2 != 0) {
      iVar2 = 0;
      pdVar3 = &db_hash;
      puVar4 = &DAT_20006560;
      do {
        uVar1 = *puVar4;
        pdVar3 = (db_hash *)((int)&pdVar3[-1].sync_sem.poll_events.prev + 3);
        iVar2 = iVar2 + 1;
        *puVar4 = pdVar3->stored_hash;
        pdVar3->stored_hash = uVar1;
        puVar4 = puVar4 + 1;
      } while (iVar2 != 8);
      atomic_set_bit((atomic_t *)&DAT_20006628,8);
      return;
    }
    local_11c = "Unable to calculate hash";
  }
  local_120[0] = '\x02';
  local_120[1] = '\0';
  local_120[2] = '\0';
  local_120[3] = '\0';
  LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_120);
  return;
}


