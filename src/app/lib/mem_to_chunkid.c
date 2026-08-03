/*
 * Function: mem_to_chunkid
 * Entry:    000815f4
 * Prototype: chunkid_t __stdcall mem_to_chunkid(z_heap * h, void * p)
 */


/* exclude_from_export */

chunkid_t mem_to_chunkid(z_heap *h,void *p)

{
  int iVar1;
  
  if ((uint)h[2] < 0x8000) {
    iVar1 = 4;
  }
  else {
    iVar1 = 8;
  }
  return (uint)((int)p + (-(int)h - iVar1)) >> 3;
}


