/*
 * Function: bt_settings_store
 * Entry:    000561c4
 * Prototype: int __stdcall bt_settings_store(char * key, uint8_t id, bt_addr_le_t * addr, void * value, size_t val_len)
 */


/* exclude_from_export */

int bt_settings_store(char *key,uint8_t id,bt_addr_le_t *addr,void *value,size_t val_len)

{
  int iVar1;
  char *key_00;
  char acStack_38 [4];
  char acStack_34 [36];
  
  if (addr == (bt_addr_le_t *)0x0) {
    iVar1 = snprintk(acStack_34,0x24,"bt/%s",key);
    if (iVar1 < 0) {
      return -0x16;
    }
  }
  else {
    key_00 = (char *)0x0;
    if (id != '\0') {
      u8_to_dec(acStack_38,'\x04',id);
      key_00 = acStack_38;
    }
    bt_settings_encode_key(acStack_34,0x24,key,addr,key_00);
  }
  iVar1 = settings_save_one(acStack_34,value,val_len);
  return iVar1;
}


