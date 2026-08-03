/*
 * Function: sys_memcpy_swap
 * Entry:    00061f30
 * Prototype: void __stdcall sys_memcpy_swap(void * dst, void * src, size_t length)
 */


/* exclude_from_export */

void sys_memcpy_swap(void *dst,void *src,size_t length)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  char *test;
  undefined1 *puVar3;
  char *file;
  int line;
  bool bVar4;
  
  if (src < dst) {
    bVar4 = (void *)((int)src + length) <= dst;
  }
  else {
    if (dst == src) goto LAB_00061f40;
    bVar4 = (undefined1 *)((int)dst + length) <= src;
  }
  if (bVar4) {
    puVar1 = dst;
    puVar3 = (undefined1 *)((int)src + (length - 1));
    do {
      puVar2 = puVar1 + 1;
      *puVar1 = *puVar3;
      puVar1 = puVar2;
      puVar3 = puVar3 + -1;
    } while ((undefined1 *)((int)dst + length) != puVar2);
    return;
  }
LAB_00061f40:
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
          "((psrc < pdst && (psrc + length) <= pdst) || (psrc > pdst && (pdst + length) <= psrc))",
          "WEST_TOPDIR/zephyr/include/zephyr/sys/byteorder.h",533);
  _ASSERT("\tSource and destination buffers must not overlap\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


