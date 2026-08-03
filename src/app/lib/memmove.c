/*
 * Function: memmove
 * Entry:    0008a3f4
 * Prototype: void * __stdcall memmove(void * d, void * s, size_t n)
 */


/* exclude_from_export */

void * memmove(void *d,void *s,size_t n)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)((int)s + n);
  if ((s < d) && (d < puVar2)) {
    puVar1 = (undefined1 *)(n + (int)d);
    while (puVar1 != d) {
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
      *puVar1 = *puVar2;
    }
  }
  else {
    puVar1 = (undefined1 *)((int)d + -1);
    for (; s != puVar2; s = (void *)((int)s + 1)) {
      puVar1 = puVar1 + 1;
      *puVar1 = *(undefined1 *)s;
    }
  }
  return d;
}


