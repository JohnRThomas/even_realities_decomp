/*
 * Function: mbox_nrf_send
 * Entry:    00064ee8
 * Prototype: int __stdcall mbox_nrf_send(device * dev, uint32_t channel, mbox_msg * msg)
 */


/* exclude_from_export_ai */

int mbox_nrf_send(device *dev,uint32_t channel,mbox_msg *msg)

{
  log_msg_desc desc;
  int iVar1;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  if (msg != (mbox_msg *)0x0) {
    local_14 = "Sending data not supported";
    local_18 = 2;
    desc.level = (dword)&local_18;
    desc.domain = 0x1080;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffd8;
    z_impl_z_log_msg_static_create
              (&PTR_s_mbox_nrfx_ipc_0008b9a8,desc,in_stack_ffffffdc,in_stack_ffffffe0);
  }
  if ((channel < 0x10) && ((int)((*(uint *)(dev->config + 4) >> (channel & 0xff)) << 0x1f) < 0)) {
    iVar1 = 0;
    (&Peripherals::IPC_S.TASKS_SEND_0_)[channel & 0x3f] = 1;
  }
  else {
    iVar1 = -0x16;
  }
  return iVar1;
}


