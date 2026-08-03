/*
 * Function: z_log_msg_init
 * Entry:    000507a8
 * Prototype: void __stdcall z_log_msg_init(void)
 */


/* exclude_from_export */

void z_log_msg_init(void)

{
  mpsc_pbuf_init((mpsc_pbuf_buffer *)&log_buffer,(mpsc_pbuf_buffer_config *)&mpsc_config);
  curr_log_buffer = &log_buffer;
  return;
}


