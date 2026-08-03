/*
 * Function: get_usage
 * Entry:    00081ad2
 * Prototype: uint32_t __stdcall get_usage(mpsc_pbuf_buffer * buffer)
 */


/* exclude_from_export_ai */

uint32_t get_usage(mpsc_pbuf_buffer *buffer)

{
  bool bVar1;
  uint32_t in_r1;
  uint32_t local_c;
  
  local_c = in_r1;
  bVar1 = free_space(buffer,&local_c);
  if (bVar1) {
    local_c = (local_c - 1) + buffer->rd_idx;
  }
  return (buffer->size - local_c) - 1;
}


