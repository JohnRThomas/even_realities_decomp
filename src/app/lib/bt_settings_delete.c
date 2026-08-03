/*
 * Function: bt_settings_delete
 * Entry:    00056430
 * Prototype: int __stdcall bt_settings_delete(char * key, uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

int bt_settings_delete(char *key,uint8_t id,bt_addr_le_t *addr)

{
  int iVar1;
  char *key_00;
  char acStack_38 [4];
  char acStack_34 [40];
  
  if ((bt_addr_le_t *)(uint)id == (bt_addr_le_t *)0x0) {
    iVar1 = snprintk(acStack_34,0x24,"bt/%s","keys");
    if (iVar1 < 0) {
      return -0x16;
    }
  }
  else {
    key_00 = (char *)0x0;
    if (key != (char *)0x0) {
      u8_to_dec(acStack_38,'\x04',(uint8_t)key);
      key_00 = acStack_38;
    }
    bt_settings_encode_key(acStack_34,0x24,"keys",(bt_addr_le_t *)(uint)id,key_00);
  }
  iVar1 = settings_delete(acStack_34);
  return iVar1;
}


