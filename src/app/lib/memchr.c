/*
 * Function: memchr
 * Entry:    0008a378
 * Prototype: void * __stdcall memchr(void * s, int c, size_t n)
 */


/* exclude_from_export */

void * memchr(void *s,int c,size_t n)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = s;
  do {
    pbVar2 = pbVar1;
    if (pbVar2 == (byte *)(n + (int)s)) {
      return (void *)0x0;
    }
    pbVar1 = pbVar2 + 1;
  } while ((uint)*pbVar2 != (c & 0xffU));
  return pbVar2;
}


