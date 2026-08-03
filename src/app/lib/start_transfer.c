/*
 * Function: start_transfer
 * Entry:    00062ddc
 * Prototype: int __stdcall start_transfer(dmic_nrfx_pdm_drv_data * drv_data)
 */


/* exclude_from_export */

int start_transfer(dmic_nrfx_pdm_drv_data *drv_data)

{
  log_msg_desc desc;
  nrfx_err_t nVar1;
  int iVar2;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  undefined1 *puStack_18;
  
  nVar1 = nrfx_pdm_start();
  puStack_18 = (undefined1 *)(uint)nVar1;
  if (puStack_18 == &DAT_0bad0000) {
    iVar2 = 0;
  }
  else {
    local_1c = "Failed to start PDM: 0x%08x";
    local_20 = 3;
    desc.level = (dword)&local_20;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 3;
    desc.data_len = in_stack_ffffffd0;
    z_vrfy_z_log_msg_static_create
              (&PTR_s_dmic_nrfx_pdm_0008b950,desc,in_stack_ffffffd4,in_stack_ffffffd8);
    if ((int)((uint)*(byte *)&drv_data[3].mem_slab << 0x1f) < 0) {
      onoff_release((onoff_manager *)drv_data->clk_mgr);
    }
    iVar2 = -5;
    *(undefined1 *)((int)&drv_data[3].mem_slab + 1) = 0;
  }
  return iVar2;
}


