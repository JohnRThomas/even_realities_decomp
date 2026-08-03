/*
 * Function: stream_flash_erase_page
 * Entry:    000513c4
 * Prototype: int __stdcall stream_flash_erase_page(stream_flash_ctx * ctx, off_t off)
 */


/* exclude_from_export_ai */

int stream_flash_erase_page(stream_flash_ctx *ctx,off_t off)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  int iVar1;
  int iVar2;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined4 local_38;
  char *local_34;
  int iStack_30;
  flash_pages_info local_24;
  
  iVar1 = flash_get_page_info_by_offs((device *)ctx->fdev,off,&local_24);
  if (iVar1 == 0) {
    if (ctx->last_erased_page_start_offset != local_24.start_offset) {
      iVar2 = (**(code **)(*(int *)(ctx->fdev + 8) + 8))
                        (ctx->fdev,local_24.start_offset,local_24.size);
      if (iVar2 == 0) {
        ctx->last_erased_page_start_offset = local_24.start_offset;
      }
      else {
        local_34 = "Error %d while erasing page";
        local_38 = 3;
        desc.level = (dword)&local_38;
        desc.domain = 0x1840;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffb8;
        iStack_30 = iVar2;
        z_impl_z_log_msg_static_create
                  (&PTR_s_STREAM_FLASH_0008b888,desc,in_stack_ffffffbc,in_stack_ffffffc0);
        iVar1 = iVar2;
      }
    }
  }
  else {
    local_34 = "Error %d while getting page info";
    local_38 = 3;
    desc_00.level = (dword)&local_38;
    desc_00.domain = 0x1840;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffffb8;
    iStack_30 = iVar1;
    z_impl_z_log_msg_static_create
              (&PTR_s_STREAM_FLASH_0008b888,desc_00,in_stack_ffffffbc,in_stack_ffffffc0);
  }
  return iVar1;
}


