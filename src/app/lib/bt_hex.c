/*
 * Function: bt_hex
 * Entry:    00055f44
 * Prototype: char * __stdcall bt_hex(void * buf, size_t len)
 */


/* exclude_from_export_ai */

char * bt_hex(void *buf,size_t len)

{
  char *pcVar1;
  byte *pbVar2;
  
  if (0x3f < len) {
    len = 0x40;
  }
  pbVar2 = (byte *)((int)buf + len);
  pcVar1 = &DAT_2001e1e4;
  for (; buf != pbVar2; buf = (void *)((int)buf + 1)) {
    *pcVar1 = "0123456789abcdef"[*(byte *)buf >> 4];
    pcVar1[1] = "0123456789abcdef"[*(byte *)buf & 0xf];
    pcVar1 = pcVar1 + 2;
  }
  (&DAT_2001e1e4)[len] = 0;
  return &DAT_2001e1e4;
}


