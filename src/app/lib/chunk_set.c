/*
 * Function: chunk_set
 * Entry:    0008159a
 * Prototype: void __stdcall chunk_set(z_heap * h, chunkid_t c, chunk_fields f, chunkid_t val)
 */


/* exclude_from_export */

void chunk_set(z_heap *h,chunkid_t c,chunk_fields f,chunkid_t val)

{
  if ((uint)h[2] < 0x8000) {
    *(short *)(&h[c * 2].field_0x0 + f * 2) = (short)val;
  }
  else {
    h[c * 2 + f] = (z_heap)val;
  }
  return;
}


