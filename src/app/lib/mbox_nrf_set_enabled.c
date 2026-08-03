/*
 * Function: mbox_nrf_set_enabled
 * Entry:    00064e48
 * Prototype: int __stdcall mbox_nrf_set_enabled(device * dev, uint32_t channel, bool enable)
 */


/* exclude_from_export */

int mbox_nrf_set_enabled(device *dev,uint32_t channel,bool enable)

{
  log_msg_desc desc;
  uint uVar1;
  undefined *puVar2;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  puVar2 = dev->data;
  if ((0xf < channel) || (-1 < (int)((*(uint *)dev->config >> (channel & 0xff)) << 0x1f))) {
    return -0x16;
  }
  uVar1 = *(uint *)(puVar2 + 0x84) >> (channel & 0xff) & 1;
  if (enable) {
    if (uVar1 == 0) {
      if (*(int *)(puVar2 + channel * 4) == 0) {
        local_14 = "Enabling channel without a registered callback\n";
        local_18 = 2;
        desc.level = (dword)&local_18;
        desc.domain = 0x1080;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffd8;
        z_impl_z_log_msg_static_create
                  (&PTR_s_mbox_nrfx_ipc_0008b9a8,desc,in_stack_ffffffdc,in_stack_ffffffe0);
      }
      if (*(int *)(puVar2 + 0x84) == 0) {
        arch_irq_enable(0x2a);
      }
      *(uint *)(puVar2 + 0x84) = *(uint *)(puVar2 + 0x84) | 1 << (channel & 0xff);
      nrfx_ipc_receive_event_enable((uint8_t)channel);
      goto LAB_00064ec8;
    }
  }
  else if (uVar1 != 0) {
    nrfx_ipc_receive_event_disable((uint8_t)channel);
    *(uint *)(puVar2 + 0x84) = *(uint *)(puVar2 + 0x84) & ~(1 << (channel & 0xff));
LAB_00064ec8:
    if (*(int *)(puVar2 + 0x84) == 0) {
      arch_irq_disable(0x2a);
    }
    return 0;
  }
  return -0x78;
}


