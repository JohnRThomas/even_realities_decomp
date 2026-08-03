/*
 * Function: idx_inc
 * Entry:    00081af4
 * Prototype: uint32_t __stdcall idx_inc(mpsc_pbuf_buffer * buffer, uint32_t idx, int32_t val)
 */


/* exclude_from_export_ai */

uint32_t idx_inc(mpsc_pbuf_buffer *buffer,uint32_t idx,int32_t val)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = val + idx;
  uVar2 = buffer->size;
  if ((int)(buffer->flags << 0x1f) < 0) {
    uVar1 = uVar1 & uVar2 - 1;
  }
  else if (uVar2 <= uVar1) {
    uVar1 = uVar1 - uVar2;
  }
  return uVar1;
}


