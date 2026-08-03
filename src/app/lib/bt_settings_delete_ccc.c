/*
 * Function: bt_settings_delete_ccc
 * Entry:    00056318
 * Prototype: int __stdcall bt_settings_delete_ccc(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

int bt_settings_delete_ccc(uint8_t id,bt_addr_le_t *addr)

{
  int iVar1;
  char *key;
  char acStack_38 [4];
  char acStack_34 [40];
  
  if (addr == (bt_addr_le_t *)0x0) {
    iVar1 = snprintk(acStack_34,0x24,"bt/%s","ccc");
    if (iVar1 < 0) {
      return -0x16;
    }
  }
  else {
    key = (char *)0x0;
    if (id != '\0') {
      u8_to_dec(acStack_38,'\x04',id);
      key = acStack_38;
    }
    bt_settings_encode_key(acStack_34,0x24,"ccc",addr,key);
  }
  iVar1 = settings_delete(acStack_34);
  return iVar1;
}


