/*
 * Function: mbox_nrf_init
 * Entry:    00064d94
 * Prototype: int __stdcall mbox_nrf_init(device * dev)
 */


/* exclude_from_export_ai */

int mbox_nrf_init(device *dev)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  undefined *p_context;
  nrfx_ipc_config_t *pnVar1;
  uint uVar2;
  uint *puVar3;
  dword in_stack_ffffff58;
  uint8_t *in_stack_ffffff5c;
  void *in_stack_ffffff60;
  undefined4 local_98;
  char *local_94;
  nrfx_ipc_config_t anStack_8c [16];
  nrfx_ipc_config_t local_4c [16];
  undefined4 local_c;
  
  p_context = dev->data;
  *(device **)(p_context + 0x80) = dev;
  nrfx_ipc_init('\0',(nrfx_ipc_handler_t)0x64f3d,p_context);
  z_arm_irq_priority_set(0x2a,1,0);
  puVar3 = (uint *)dev->config;
  memset(anStack_8c,0,0x84);
  if (0xffff < puVar3[1]) {
    local_94 = "tx_mask too big (or IPC_CONF_NUM too small)";
    local_98 = 2;
    desc.level = (dword)&local_98;
    desc.domain = 0x1080;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffff58;
    z_impl_z_log_msg_static_create
              (&PTR_s_mbox_nrfx_ipc_0008b9a8,desc,in_stack_ffffff5c,in_stack_ffffff60);
  }
  if (0xffff < *puVar3) {
    local_94 = "rx_mask too big (or IPC_CONF_NUM too small)";
    local_98 = 2;
    desc_00.level = (dword)&local_98;
    desc_00.domain = 0x1080;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffff58;
    z_impl_z_log_msg_static_create
              (&PTR_s_mbox_nrfx_ipc_0008b9a8,desc_00,in_stack_ffffff5c,in_stack_ffffff60);
  }
  uVar2 = 0;
  local_c = 0;
  pnVar1 = anStack_8c;
  do {
    if ((int)((puVar3[1] >> (uVar2 & 0xff)) << 0x1f) < 0) {
      *pnVar1 = 1 << (uVar2 & 0xff);
    }
    if ((int)((*puVar3 >> (uVar2 & 0xff)) << 0x1f) < 0) {
      pnVar1[0x10] = 1 << (uVar2 & 0xff);
    }
    uVar2 = uVar2 + 1;
    pnVar1 = pnVar1 + 1;
  } while (uVar2 != 0x10);
  nrfx_ipc_config_load(anStack_8c);
  return 0;
}


