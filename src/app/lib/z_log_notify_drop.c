/*
 * Function: z_log_notify_drop
 * Entry:    000825d6
 * Prototype: void __stdcall z_log_notify_drop(mpsc_pbuf_buffer * buffer, mpsc_pbuf_generic * item)
 */


/* exclude_from_export */

void z_log_notify_drop(mpsc_pbuf_buffer *buffer,mpsc_pbuf_generic *item)

{
  z_log_dropped(true);
  return;
}


