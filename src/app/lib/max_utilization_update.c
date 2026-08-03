/*
 * Function: max_utilization_update
 * Entry:    00081c8a
 * Prototype: void __stdcall max_utilization_update(mpsc_pbuf_buffer * buffer)
 */


/* exclude_from_export_ai */

void max_utilization_update(mpsc_pbuf_buffer *buffer)

{
  uint32_t uVar1;
  uint uVar2;
  
  if ((int)(buffer->flags << 0x1d) < 0) {
    uVar2 = buffer->max_usage;
    uVar1 = get_usage(buffer);
    if (uVar2 < uVar1) {
      buffer->max_usage = uVar1;
    }
    else {
      buffer->max_usage = uVar2;
    }
  }
  return;
}


