/*
 * Function: flash_nrf_read_error_outline
 * Entry:    000644a8
 * Prototype: undefined4 __stdcall flash_nrf_read_error_outline(undefined4 param_1, undefined4 param_2)
 */


/* exclude_from_export */

undefined4 flash_nrf_read_error_outline(undefined4 param_1,undefined4 param_2)

{
  log_msg_desc desc;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  local_14 = "invalid address: 0x%08lx:%zu";
  local_18 = 4;
  desc.level = (dword)&local_18;
  desc.domain = 0x2040;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffd8;
  uStack_10 = param_1;
  local_c = param_2;
  z_impl_z_log_msg_static_create(&PTR_s_flash_nrf_0008b960,desc,in_stack_ffffffdc,in_stack_ffffffe0)
  ;
  return 0xffffffea;
}


