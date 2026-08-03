/*
 * Function: bt_settings_store_ccc
 * Entry:    000562fc
 * Prototype: int __stdcall bt_settings_store_ccc(uint8_t id, bt_addr_le_t * addr, void * value, size_t val_len)
 */


/* exclude_from_export */

int bt_settings_store_ccc(uint8_t id,bt_addr_le_t *addr,void *value,size_t val_len)

{
  int iVar1;
  
  iVar1 = bt_settings_store("ccc",id,addr,value,val_len);
  return iVar1;
}


