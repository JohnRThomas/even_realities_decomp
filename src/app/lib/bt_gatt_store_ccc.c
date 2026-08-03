/*
 * Function: bt_gatt_store_ccc
 * Entry:    0005fab8
 * Prototype: int __stdcall bt_gatt_store_ccc(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

int bt_gatt_store_ccc(uint8_t id,bt_addr_le_t *addr)

{
  int iVar1;
  undefined1 *value;
  size_t val_len;
  char local_f0 [4];
  char *local_ec;
  int iStack_e8;
  bt_addr_le_t *local_dc;
  uint8_t local_d8;
  undefined1 auStack_d4 [192];
  int local_14;
  
  local_14 = 0;
  local_dc = addr;
  local_d8 = id;
  bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5d5d5,&local_dc);
  if (local_14 == 0) {
    value = (undefined1 *)0x0;
    val_len = 0;
  }
  else {
    val_len = local_14 << 2;
    value = auStack_d4;
  }
  iVar1 = bt_settings_store_ccc(id,addr,value,val_len);
  if (iVar1 != 0) {
    local_ec = "Failed to store CCCs (err %d)";
    local_f0[0] = '\x03';
    local_f0[1] = '\0';
    local_f0[2] = '\0';
    local_f0[3] = '\0';
    iStack_e8 = iVar1;
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_f0);
  }
  return iVar1;
}


