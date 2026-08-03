/*
 * Function: z_log_msg_commit
 * Entry:    00050b58
 * Prototype: void __stdcall z_log_msg_commit(log_msg * msg)
 */


/* exclude_from_export_ai */

void z_log_msg_commit(log_msg *msg)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_20002818)();
  *(undefined4 *)((int)&msg[1].hdr + 2) = uVar1;
  mpsc_pbuf_commit((mpsc_pbuf_buffer *)&log_buffer,(mpsc_pbuf_generic *)msg);
  z_log_msg_post_finalize();
  return;
}


