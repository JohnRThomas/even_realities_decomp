/*
 * Function: set_chunk_used
 * Entry:    000815bc
 * Prototype: void __stdcall set_chunk_used(z_heap * h, chunkid_t c, bool used)
 */


/* exclude_from_export */

void set_chunk_used(z_heap *h,chunkid_t c,bool used)

{
  ushort uVar1;
  z_heap zVar2;
  
  if (0x7fff < (uint)h[2]) {
    if (used) {
      zVar2 = (z_heap)((uint)h[c * 2 + 1] | 1);
    }
    else {
      zVar2 = (z_heap)((uint)h[c * 2 + 1] & 0xfffffffe);
    }
    h[c * 2 + 1] = zVar2;
    return;
  }
  if (used) {
    uVar1 = *(ushort *)&h[c * 2].field_0x2 | 1;
  }
  else {
    uVar1 = *(ushort *)&h[c * 2].field_0x2 & 0xfffe;
  }
  *(ushort *)&h[c * 2].field_0x2 = uVar1;
  return;
}


