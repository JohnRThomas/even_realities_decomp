/*
 * Function: z_log_msg_finalize
 * Entry:    0008260c
 * Prototype: void __stdcall z_log_msg_finalize(log_msg * msg, void * source, log_msg_desc desc, void * data)
 */


/* exclude_from_export_ai */

void z_log_msg_finalize(log_msg *msg,void *source,log_msg_desc desc,void *data)

{
  if (msg == (log_msg *)0x0) {
    z_log_dropped(false);
    return;
  }
  if (desc.level != 0) {
    memcpy(&msg[2].padding_Z_LOG_MSG_PADDING_ + ((desc.domain & 0xfffff) >> 9),(void *)desc.level,
           desc.domain >> 0x14);
  }
  msg->hdr = desc.domain;
  *(void **)&msg->padding_Z_LOG_MSG_PADDING_ = source;
  z_log_msg_commit(msg);
  return;
}


