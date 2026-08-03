/*
 * Function: z_log_msg_local_claim
 * Entry:    0005080c
 * Prototype: log_msg_generic * __stdcall z_log_msg_local_claim(void)
 */


/* exclude_from_export_ai */

log_msg_generic * z_log_msg_local_claim(void)

{
  mpsc_pbuf_generic *pmVar1;
  
  pmVar1 = mpsc_pbuf_claim((mpsc_pbuf_buffer *)&log_buffer);
  return (log_msg_generic *)pmVar1;
}


