/*
 * Function: region_allocate_and_init_error
 * Entry:    00053ed0
 * Prototype: undefined4 __stdcall region_allocate_and_init_error(undefined4 param_1)
 */


/* exclude_from_export */

undefined4 region_allocate_and_init_error(undefined4 param_1)

{
  log_msg_desc desc;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  undefined4 uStack_10;
  
  local_14 = "Failed to allocate new MPU region %u\n";
  local_18 = 3;
  desc.level = (dword)&local_18;
  desc.domain = 0x1840;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffd8;
  uStack_10 = param_1;
  z_impl_z_log_msg_static_create(&PTR_s_mpu_0008b9d8,desc,in_stack_ffffffdc,in_stack_ffffffe0);
  return 0xffffffea;
}


