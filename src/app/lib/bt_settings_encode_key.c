/*
 * Function: bt_settings_encode_key
 * Entry:    00056128
 * Prototype: void __stdcall bt_settings_encode_key(char * path, size_t path_size, char * subsys, bt_addr_le_t * addr, char * key)
 */


/* exclude_from_export */

void bt_settings_encode_key(char *path,size_t path_size,char *subsys,bt_addr_le_t *addr,char *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = (uint)(addr->a).val[5];
  uVar2 = (uint)(addr->a).val[4];
  uVar3 = (uint)(addr->a).val[3];
  uVar4 = (uint)(addr->a).val[2];
  uVar5 = (uint)(addr->a).val[1];
  uVar6 = (uint)(addr->a).val[0];
  if (key == (char *)0x0) {
    snprintk(path,path_size,"bt/%s/%02x%02x%02x%02x%02x%02x%u",subsys,uVar1,uVar2,uVar3,uVar4,uVar5,
             uVar6,(uint)addr->type);
  }
  else {
    snprintk(path,path_size,"bt/%s/%02x%02x%02x%02x%02x%02x%u/%s",subsys,uVar1,uVar2,uVar3,uVar4,
             uVar5,uVar6,(uint)addr->type,key);
  }
  return;
}


