/*
 * Function: bt_gatt_store_cf
 * Entry:    0005db68
 * Prototype: int __stdcall bt_gatt_store_cf(uint8_t id, bt_addr_le_t * peer)
 */


/* exclude_from_export */

int bt_gatt_store_cf(uint8_t id,bt_addr_le_t *peer)

{
  gatt_cf_cfg *pgVar1;
  int iVar2;
  int bit;
  byte *value;
  size_t val_len;
  char local_28 [4];
  char *local_24;
  int iStack_20;
  byte local_14;
  undefined1 local_13;
  
  pgVar1 = find_cf_cfg_by_addr(id,peer);
  if (pgVar1 == (gatt_cf_cfg *)0x0) {
    value = (byte *)0x0;
    val_len = 0;
  }
  else {
    local_14 = pgVar1->data_CF_NUM_BYTES_;
    local_13 = atomic_test_bit((atomic_t *)((int)&pgVar1->CF_NUM_FLAGS_ + 3),bit);
    val_len = 2;
    value = &local_14;
  }
  iStack_20 = bt_settings_store_cf(id,peer,value,val_len);
  iVar2 = 0;
  if (iStack_20 != 0) {
    local_24 = "Failed to store Client Features (err %d)";
    local_28[0] = '\x03';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    iVar2 = LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_28);
  }
  return iVar2;
}


