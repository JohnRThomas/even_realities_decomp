/*
 * Function: memcpy
 * Entry:    0008a3ce
 * Prototype: void * __stdcall memcpy(void * d, void * s, size_t n)
 */


/* exclude_from_export */

void * memcpy(void *d,void *s,size_t n)

{
  void *pvVar1;
  uint in_r3;
  
  if (n <= in_r3) {
    if (s <= d) {
      if (d < (void *)((int)s + n)) goto LAB_0008a3d4;
      if (s != d) goto LAB_0008a3ec;
    }
    if ((void *)((int)d + n) <= s) {
LAB_0008a3ec:
      pvVar1 = memcpy(d,s,n);
      return pvVar1;
    }
  }
LAB_0008a3d4:
                    /* WARNING: Subroutine does not return */
  __chk_fail();
}


