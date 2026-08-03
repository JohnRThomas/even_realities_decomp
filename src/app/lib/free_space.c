/*
 * Function: free_space
 * Entry:    00081aac
 * Prototype: bool __stdcall free_space(mpsc_pbuf_buffer * buffer, uint32_t * res)
 */


/* exclude_from_export_ai */

bool free_space(mpsc_pbuf_buffer *buffer,uint32_t *res)

{
  uint32_t uVar1;
  uint uVar2;
  uint32_t uVar3;
  
  if ((buffer->flags & 8) == 0) {
    uVar2 = buffer->tmp_wr_idx;
    if (uVar2 < buffer->rd_idx) {
      uVar1 = 0;
      uVar3 = buffer->rd_idx - uVar2;
    }
    else {
      uVar1 = 1;
      uVar3 = buffer->size - uVar2;
    }
  }
  else {
    uVar1 = 0;
    uVar3 = uVar1;
  }
  *res = uVar3;
  return SUB41(uVar1,0);
}


