/*
 * Function: memset
 * Entry:    0008a428
 * Prototype: void * __stdcall memset(void * buf, int c, size_t n)
 */


/* exclude_from_export */

void * memset(void *buf,int c,size_t n)

{
  undefined1 *puVar1;
  
  for (puVar1 = buf; puVar1 != (undefined1 *)(n + (int)buf); puVar1 = puVar1 + 1) {
    *puVar1 = (char)c;
  }
  return buf;
}


