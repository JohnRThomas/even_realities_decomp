/*
 * Function: bt_settings_store_name
 * Entry:    00056344
 * Prototype: int __stdcall bt_settings_store_name(void * value, size_t val_len)
 */


/* exclude_from_export */

int bt_settings_store_name(void *value,size_t val_len)

{
  int iVar1;
  
  iVar1 = bt_settings_store("name",'\0',(bt_addr_le_t *)0x0,value,val_len);
  return iVar1;
}


