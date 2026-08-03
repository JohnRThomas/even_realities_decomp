/*
 * Function: rd_idx_inc
 * Entry:    00081b10
 * Prototype: void __stdcall rd_idx_inc(mpsc_pbuf_buffer * buffer, int32_t wlen)
 */


/* exclude_from_export_ai */

void rd_idx_inc(mpsc_pbuf_buffer *buffer,int32_t wlen)

{
  uint32_t uVar1;
  
  uVar1 = idx_inc(buffer,buffer->rd_idx,wlen);
  buffer->rd_idx = uVar1;
  buffer->flags = buffer->flags & 0xfffffff7;
  return;
}


