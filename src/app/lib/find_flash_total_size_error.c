/*
 * Function: find_flash_total_size_error
 * Entry:    00051398
 * Prototype: undefined __stdcall find_flash_total_size_error(int param_1)
 */


/* exclude_from_export */

void find_flash_total_size_error(int param_1)

{
  log_msg_desc desc;
  dword in_stack_ffffffe0;
  uint8_t *in_stack_ffffffe4;
  void *in_stack_ffffffe8;
  undefined4 local_10;
  char *local_c;
  
  local_c = "Buffer size is bigger than page";
  local_10 = 2;
  desc.level = (dword)&local_10;
  desc.domain = 0x1040;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffe0;
  z_impl_z_log_msg_static_create
            (&PTR_s_STREAM_FLASH_0008b888,desc,in_stack_ffffffe4,in_stack_ffffffe8);
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


