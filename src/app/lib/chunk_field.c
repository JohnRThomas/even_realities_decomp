/*
 * Function: chunk_field
 * Entry:    00081584
 * Prototype: chunkid_t __stdcall chunk_field(z_heap * h, chunkid_t c, chunk_fields f)
 */


/* exclude_from_export */

chunkid_t chunk_field(z_heap *h,chunkid_t c,chunk_fields f)

{
  z_heap zVar1;
  
  if ((uint)h[2] < 0x8000) {
    zVar1._2_2_ = 0;
    zVar1._0_2_ = *(ushort *)(&h[c * 2].field_0x0 + f * 2);
  }
  else {
    zVar1 = h[c * 2 + f];
  }
  return (chunkid_t)zVar1;
}


