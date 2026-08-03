/*
 * Function: system_off
 * Entry:    00066fa0
 * Prototype: void __stdcall system_off(void)
 */


/* exclude_from_export */

void system_off(void)

{
  log_msg_desc desc;
  dword in_r0;
  uint8_t *in_r1;
  void *in_r2;
  
  desc.level = (dword)&stack0xfffffff0;
  desc.domain = 0x1080;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_r0;
  z_impl_z_log_msg_static_create(&PTR_s_power_manager_0008ba18,desc,in_r1,in_r2);
  return;
}


