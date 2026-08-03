/*
 * Function: metal_io_block_set
 * Entry:    00088d2c
 * Prototype: int __stdcall metal_io_block_set(metal_io_region * io, ulong offset, uchar value, int len)
 */


/* exclude_from_export */

int metal_io_block_set(metal_io_region *io,ulong offset,uchar value,int len)

{
  uint c;
  uint uVar1;
  size_t n;
  int *buf;
  
  c = (uint)value;
  if (((io->virt == (undefined *)0xffffffff) || (uVar1 = io->size, uVar1 <= offset)) ||
     (buf = (int *)(io->virt + offset), buf == (int *)0x0)) {
    len = 0xffffffde;
  }
  else {
    if (uVar1 < len + offset) {
      len = uVar1 - offset;
    }
    n = len;
    if ((code *)io[1].page_shift == (code *)0x0) {
      while( true ) {
        if (n == 0) goto LAB_00088d62;
        if (((uint)buf & 3) == 0) break;
        *(uchar *)buf = value;
        buf = (int *)((int)buf + 1);
        n = n - 1;
      }
      for (; 3 < (int)n; n = n - 4) {
        *buf = c * 0x1010101;
        buf = buf + 1;
      }
LAB_00088d62:
      memset(buf,c,n);
      DataMemoryBarrier(0x1b);
      return len;
    }
    (*(code *)io[1].page_shift)(io,offset,c,5,len,offset);
  }
  return len;
}


