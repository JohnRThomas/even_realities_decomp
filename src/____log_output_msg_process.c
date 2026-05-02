/*
 * Function: $_?_log_output_msg_process
 * Entry:    00051098
 * Prototype: void __stdcall $_?_log_output_msg_process(log_output * log_output, log_msg * msg, uint32_t flags)
 */


void ____log_output_msg_process(log_output *log_output,log_msg *msg,uint32_t flags)

{
  dword dVar1;
  uint32_t source_id;
  byte *domain;
  uint uVar2;
  byte *source;
  uint32_t flags_00;
  
  dVar1 = msg->hdr;
  flags_00 = *(uint32_t *)((int)&msg[1].hdr + 2);
  if ((*(int *)&msg->padding_Z_LOG_MSG_PADDING_ != 0) &&
     (source_id = (*(int *)&msg->padding_Z_LOG_MSG_PADDING_ + -0x8b820) * 0x2000 >> 0x10,
     -1 < (int)source_id)) {
    log_source_name_get(((uint)(byte)msg->hdr << 0x1a) >> 0x1d,source_id);
  }
  domain = &msg[2].padding_Z_LOG_MSG_PADDING_;
  uVar2 = (msg->hdr << 0xc) >> 0x15;
  source = domain + uVar2;
  if (uVar2 == 0) {
    domain = (byte *)0x0;
  }
  prefix_print(log_output,flags_00,false,(ulonglong)(((uint)(ushort)dVar1 << 0x17) >> 0x1d) << 0x20,
               (char *)domain,(char *)source,
               (k_tid_t)(((uint)*(ushort *)((int)&msg->hdr + 2) << 0x10) >> 0x14),(uint8_t)flags);
  return;
}


