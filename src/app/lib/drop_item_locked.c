/*
 * Function: drop_item_locked
 * Entry:    00081b66
 * Prototype: bool __stdcall drop_item_locked(mpsc_pbuf_buffer * buffer, uint32_t free_wlen, mpsc_pbuf_generic * * item_to_drop, uint32_t * tmp_wr_idx_shift)
 */


/* exclude_from_export_ai */

bool drop_item_locked(mpsc_pbuf_buffer *buffer,uint32_t free_wlen,mpsc_pbuf_generic **item_to_drop,
                     uint32_t *tmp_wr_idx_shift)

{
  byte bVar1;
  bool bVar2;
  int wlen;
  uint32_t uVar3;
  uint uVar4;
  undefined *puVar5;
  dword dVar6;
  
  dVar6 = buffer->rd_idx;
  puVar5 = buffer->buf;
  if ((puVar5[dVar6] & 3) == 2) {
    uVar4 = *(uint *)(puVar5 + dVar6 * 4);
    *item_to_drop = (mpsc_pbuf_generic *)0x0;
    *tmp_wr_idx_shift = 0;
    if (uVar4 >> 2 == 0) goto LAB_00081b90;
    rd_idx_inc(buffer,uVar4 >> 2);
    buffer->tmp_rd_idx = buffer->rd_idx;
LAB_00081bb4:
    bVar2 = true;
  }
  else {
    *item_to_drop = (mpsc_pbuf_generic *)0x0;
    *tmp_wr_idx_shift = 0;
LAB_00081b90:
    if ((int)(buffer->flags << 0x1e) < 0) {
      wlen = (*(code *)buffer->get_wlen)((mpsc_pbuf_generic *)(puVar5 + dVar6 * 4));
      bVar1 = puVar5[dVar6];
      if ((int)((uint)bVar1 << 0x1f) < 0) {
        if ((bVar1 & 2) == 0) {
          rd_idx_inc(buffer,wlen);
          buffer->tmp_rd_idx = buffer->rd_idx;
          if (free_wlen != 0) {
            *(uint *)(buffer->buf + buffer->tmp_wr_idx * 4) = bVar1 & 2;
          }
          *tmp_wr_idx_shift = wlen + free_wlen;
          uVar3 = idx_inc(buffer,buffer->tmp_wr_idx,wlen + free_wlen);
          buffer->tmp_wr_idx = uVar3;
          buffer->flags = buffer->flags | 8;
          puVar5[dVar6] = puVar5[dVar6] & 0xfe;
          *item_to_drop = (mpsc_pbuf_generic *)(puVar5 + dVar6 * 4);
        }
        else {
          if (free_wlen != 0) {
            add_skip_item(buffer,free_wlen);
          }
          uVar3 = idx_inc(buffer,buffer->wr_idx,wlen);
          buffer->wr_idx = uVar3;
          if (buffer->rd_idx == buffer->tmp_rd_idx) {
            uVar3 = idx_inc(buffer,buffer->rd_idx,wlen);
            buffer->tmp_rd_idx = uVar3;
          }
          buffer->tmp_wr_idx = buffer->tmp_rd_idx;
          buffer->rd_idx = buffer->tmp_rd_idx;
          buffer->flags = buffer->flags | 8;
        }
        goto LAB_00081bb4;
      }
    }
    bVar2 = false;
  }
  return bVar2;
}


