/*
 * Function: post_drop_action
 * Entry:    00081c54
 * Prototype: void __stdcall post_drop_action(mpsc_pbuf_buffer * buffer, uint32_t prev_tmp_wr_idx, uint32_t tmp_wr_idx_shift)
 */


/* exclude_from_export_ai */

void post_drop_action(mpsc_pbuf_buffer *buffer,uint32_t prev_tmp_wr_idx,uint32_t tmp_wr_idx_shift)

{
  uint32_t uVar1;
  dword extraout_r1;
  
  uVar1 = idx_inc(buffer,prev_tmp_wr_idx,tmp_wr_idx_shift);
  if (buffer->tmp_wr_idx == uVar1) {
    buffer->tmp_wr_idx = extraout_r1;
    buffer->flags = buffer->flags & 0xfffffff7;
  }
  else {
    *(uint32_t *)(buffer->buf + extraout_r1 * 4) = tmp_wr_idx_shift << 2 | 2;
    uVar1 = idx_inc(buffer,buffer->wr_idx,tmp_wr_idx_shift);
    buffer->wr_idx = uVar1;
  }
  return;
}


