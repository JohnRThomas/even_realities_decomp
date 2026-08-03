/*
 * Function: db_hash_set
 * Entry:    0005d538
 * Prototype: int __stdcall db_hash_set(char * name, size_t len_rd, settings_read_cb read_cb, void * cb_arg)
 */


/* exclude_from_export_ai */

int db_hash_set(char *name,size_t len_rd,settings_read_cb read_cb,void *cb_arg)

{
  int iVar1;
  char local_20 [4];
  char *local_1c;
  int iStack_18;
  
  iVar1 = (*(code *)read_cb)(cb_arg,&db_hash,0x10);
  if (iVar1 < 0) {
    local_1c = "Failed to decode value (err %zd)";
    local_20[0] = '\x03';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    iStack_18 = iVar1;
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_20);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


