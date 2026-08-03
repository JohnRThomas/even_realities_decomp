/*
 * Function: bytes_to_chunksz
 * Entry:    00081608
 * Prototype: chunksz_t __stdcall bytes_to_chunksz(z_heap * h, size_t bytes)
 */


/* exclude_from_export */

chunksz_t bytes_to_chunksz(z_heap *h,size_t bytes)

{
  int iVar1;
  
  if (h < (z_heap *)0x8000) {
    iVar1 = 4;
  }
  else {
    iVar1 = 8;
  }
  return bytes + 7 + iVar1 >> 3;
}


