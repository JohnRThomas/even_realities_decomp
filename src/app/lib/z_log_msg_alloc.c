/*
 * Function: z_log_msg_alloc
 * Entry:    000507fc
 * Prototype: log_msg * __stdcall z_log_msg_alloc(uint32_t wlen)
 */


/* exclude_from_export_ai */

log_msg * z_log_msg_alloc(uint32_t wlen)

{
  mpsc_pbuf_generic *pmVar1;
  
  pmVar1 = mpsc_pbuf_alloc((mpsc_pbuf_buffer *)&log_buffer,wlen,(k_timeout_t)0x0);
  return (log_msg *)pmVar1;
}


