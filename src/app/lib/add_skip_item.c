/*
 * Function: add_skip_item
 * Entry:    00081b28
 * Prototype: void __stdcall add_skip_item(mpsc_pbuf_buffer * buffer, uint32_t wlen)
 */


/* exclude_from_export_ai */

void add_skip_item(mpsc_pbuf_buffer *buffer,uint32_t wlen)

{
  uint32_t uVar1;
  uint uVar2;
  bool bVar3;
  
  *(uint32_t *)(buffer->buf + buffer->tmp_wr_idx * 4) = wlen << 2 | 2;
  uVar1 = idx_inc(buffer,buffer->tmp_wr_idx,wlen);
  uVar2 = buffer->rd_idx;
  bVar3 = uVar1 == uVar2;
  if (bVar3) {
    uVar2 = buffer->flags;
  }
  buffer->tmp_wr_idx = uVar1;
  if (bVar3) {
    buffer->flags = uVar2 | 8;
  }
  uVar1 = idx_inc(buffer,buffer->wr_idx,wlen);
  buffer->wr_idx = uVar1;
  return;
}


