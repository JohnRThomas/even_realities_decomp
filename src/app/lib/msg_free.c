/*
 * Function: msg_free
 * Entry:    00050818
 * Prototype: void __stdcall msg_free(mpsc_pbuf_buffer * buffer, log_msg_generic * msg)
 */


/* exclude_from_export_ai */

void msg_free(mpsc_pbuf_buffer *buffer,log_msg_generic *msg)

{
  mpsc_pbuf_free(curr_log_buffer,(mpsc_pbuf_generic *)buffer);
  return;
}


