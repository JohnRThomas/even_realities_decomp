/*
 * Function: bt_settings_store_sc
 * Entry:    000562b4
 * Prototype: int __stdcall bt_settings_store_sc(uint8_t id, bt_addr_le_t * addr, void * value, size_t val_len)
 */


/* exclude_from_export */

int bt_settings_store_sc(uint8_t id,bt_addr_le_t *addr,void *value,size_t val_len)

{
  int iVar1;
  
  iVar1 = bt_settings_store("sc",id,addr,value,val_len);
  return iVar1;
}


