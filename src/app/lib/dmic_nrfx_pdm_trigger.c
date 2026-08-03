/*
 * Function: dmic_nrfx_pdm_trigger
 * Entry:    00062e38
 * Prototype: int __stdcall dmic_nrfx_pdm_trigger(device * dev, dmic_trigger cmd)
 */


/* exclude_from_export */

int dmic_nrfx_pdm_trigger(device *dev,dmic_trigger cmd)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  uint uVar1;
  undefined *puVar2;
  dmic_nrfx_pdm_drv_data *drv_data;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  int iStack_38;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  puVar2 = dev->data;
  switch(cmd) {
  case 0:
  case 2:
    if (puVar2[0x51] != '\0') {
      puVar2[0x52] = 1;
      nrfx_pdm_stop();
    }
    break;
  case 1:
  case 3:
    if (-1 < (int)((uint)(byte)puVar2[0x50] << 0x1e)) {
      local_1c = "Device is not configured";
      local_20 = 2;
      desc_01.level = (dword)&local_20;
      desc_01.domain = 0x1040;
      desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 2;
      desc_01.data_len = in_stack_ffffffd0;
      z_vrfy_z_log_msg_static_create
                (&PTR_s_dmic_nrfx_pdm_0008b950,desc_01,in_stack_ffffffd4,in_stack_ffffffd8);
      return -5;
    }
    if (puVar2[0x51] == '\0') {
      puVar2[0x52] = 0;
      drv_data = (dmic_nrfx_pdm_drv_data *)dev->data;
      *(undefined1 *)((int)&drv_data[3].mem_slab + 1) = 1;
      if (-1 < (int)((uint)*(byte *)&drv_data[3].mem_slab << 0x1f)) {
        uVar1 = start_transfer(drv_data);
        return uVar1 & (int)uVar1 >> 0x1f;
      }
      drv_data->rx_queue = 0;
      drv_data->mem_slab = &LAB_00086f60_1;
      drv_data->block_size = 3;
      iStack_38 = onoff_request((onoff_manager *)drv_data->clk_mgr,
                                (onoff_client *)&drv_data->clk_cli);
      if (iStack_38 < 0) {
        *(undefined1 *)((int)&drv_data[3].mem_slab + 1) = 0;
        local_3c = "Failed to request clock: %d";
        local_40 = 3;
        desc_00.level = (dword)&local_40;
        desc_00.domain = 0x1840;
        desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = (dword)"Failed to request clock: %d";
        desc_00.data_len = in_stack_ffffffb0;
        z_vrfy_z_log_msg_static_create
                  (&PTR_s_dmic_nrfx_pdm_0008b950,desc_00,in_stack_ffffffb4,in_stack_ffffffb8);
        return -5;
      }
    }
    break;
  default:
    local_3c = "Invalid command: %d";
    local_40 = 3;
    desc.level = (dword)&local_40;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 3;
    desc.data_len = in_stack_ffffffb0;
    iStack_38 = cmd;
    z_vrfy_z_log_msg_static_create
              (&PTR_s_dmic_nrfx_pdm_0008b950,desc,in_stack_ffffffb4,in_stack_ffffffb8);
    return -0x16;
  }
  return 0;
}


