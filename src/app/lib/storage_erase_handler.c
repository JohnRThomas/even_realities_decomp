/*
 * Function: storage_erase_handler
 * Entry:    000558b0
 * Prototype: int __stdcall storage_erase_handler(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int storage_erase_handler(smp_streamer *ctxt)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  bool bVar1;
  int iVar2;
  device *pdVar3;
  undefined *puVar4;
  dword in_stack_ffffffd0;
  flash_area *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_18;
  char *local_14;
  
  puVar4 = ctxt->writer;
  iVar2 = flash_area_open('\t',(flash_area **)&stack0xffffffd4);
  if (iVar2 < 0) {
    iVar2 = 2;
    local_18 = 2;
    local_14 = "Failed to open flash area";
    desc_01.level = (dword)&local_18;
    desc_01.domain = 0x1040;
    desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_01.data_len = in_stack_ffffffd0;
    z_impl_z_log_msg_static_create
              (&PTR_s_mcumgr_zbasic_grp_0008b9d0,desc_01,&in_stack_ffffffd4->fa_id,in_stack_ffffffd8
              );
  }
  else {
    pdVar3 = flash_area_get_device(in_stack_ffffffd4);
    if (pdVar3 == (device *)0x0) {
      local_14 = "Failed to get flash area device";
      local_18 = 2;
      desc_00.level = (dword)&local_18;
      desc_00.domain = 0x1040;
      desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_00.data_len = in_stack_ffffffd0;
      z_impl_z_log_msg_static_create
                (&PTR_s_mcumgr_zbasic_grp_0008b9d0,desc_00,&in_stack_ffffffd4->fa_id,
                 in_stack_ffffffd8);
      flash_area_close(in_stack_ffffffd4);
      iVar2 = 3;
    }
    else {
      iVar2 = flash_area_erase(in_stack_ffffffd4,0,in_stack_ffffffd4->fa_size);
      if (iVar2 < 0) {
        local_14 = "Failed to erase flash area";
        local_18 = 2;
        desc.level = (dword)&local_18;
        desc.domain = 0x1040;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffd0;
        z_impl_z_log_msg_static_create
                  (&PTR_s_mcumgr_zbasic_grp_0008b9d0,desc,&in_stack_ffffffd4->fa_id,
                   in_stack_ffffffd8);
        flash_area_close(in_stack_ffffffd4);
        iVar2 = 4;
      }
      else {
        flash_area_close(in_stack_ffffffd4);
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
  }
  bVar1 = smp_add_cmd_err((zcbor_state_t *)(puVar4 + 4),0x3f,(uint16_t)iVar2);
  if (bVar1) {
    return 0;
  }
  return 7;
}


