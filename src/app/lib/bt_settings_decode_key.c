/*
 * Function: bt_settings_decode_key
 * Entry:    000844aa
 * Prototype: int __stdcall bt_settings_decode_key(char * key, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

int bt_settings_decode_key(char *key,bt_addr_le_t *addr)

{
  int iVar1;
  uint8_t uVar2;
  char *hex;
  char *pcVar3;
  uint8_t *buf;
  
  iVar1 = settings_name_next(key,(char **)0x0);
  if (iVar1 == 0xd) {
    if (key[0xc] == '0') {
      uVar2 = '\0';
    }
    else {
      if (key[0xc] != '1') goto LAB_000844ec;
      uVar2 = '\x01';
    }
    buf = (addr->a).val + 5;
    addr->type = uVar2;
    hex = key;
    do {
      pcVar3 = hex + 2;
      hex2bin(hex,2,buf,1);
      buf = buf + -1;
      hex = pcVar3;
    } while (pcVar3 != key + 0xc);
    iVar1 = 0;
  }
  else {
LAB_000844ec:
    iVar1 = -0x16;
  }
  return iVar1;
}


