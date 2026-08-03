/*
 * Function: db_hash_store
 * Entry:    0005d4fc
 * Prototype: void __stdcall db_hash_store(void)
 */


/* exclude_from_export */

void db_hash_store(void)

{
  char local_20 [4];
  char *local_1c;
  int iStack_18;
  
  iStack_18 = bt_settings_store_hash(&DAT_20006560,0x10);
  if (iStack_18 != 0) {
    local_1c = "Failed to save Database Hash (err %d)";
    local_20[0] = '\x03';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_20);
  }
  return;
}


