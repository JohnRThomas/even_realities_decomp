/*
 * Function: rekey
 * Entry:    00083bbe
 * Prototype: void __stdcall rekey(uint8_t * key, uint8_t * new_key, uint key_size)
 */


/* exclude_from_export_ai */

void rekey(uint8_t *key,uint8_t *new_key,uint key_size)

{
  byte *pbVar1;
  byte *pbVar2;
  size_t n;
  
  pbVar1 = new_key + key_size;
  pbVar2 = key + -1;
  for (; pbVar1 != new_key; new_key = new_key + 1) {
    pbVar2[1] = *new_key ^ 0x36;
    pbVar2[0x41] = *new_key ^ 0x5c;
    pbVar2 = pbVar2 + 1;
  }
  n = 0x40 - key_size;
  if (0x40 < key_size) {
    n = 0;
  }
  memset(key + key_size + 0x40,0x5c,n);
  memset(key + key_size,0x36,n);
  return;
}


