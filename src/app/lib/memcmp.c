/*
 * Function: memcmp
 * Entry:    0008a394
 * Prototype: int __stdcall memcmp(void * m1, void * m2, size_t n)
 */


/* exclude_from_export */

int memcmp(void *m1,void *m2,size_t n)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)((int)m2 + -1);
  pbVar2 = (byte *)(n + (int)m1);
  while( true ) {
    if (m1 == pbVar2) {
      return 0;
    }
    pbVar1 = pbVar1 + 1;
    if ((uint)*(byte *)m1 != (uint)*pbVar1) break;
    m1 = (void *)((int)m1 + 1);
  }
  return (uint)*(byte *)m1 - (uint)*pbVar1;
}


