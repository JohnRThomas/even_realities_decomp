/*
 * Function: k_sys_fatal_error_handler
 * Entry:    00066e24
 * Prototype: void __stdcall k_sys_fatal_error_handler(uint reason, z_arch_esf_t * esf)
 */


/* exclude_from_export */

void k_sys_fatal_error_handler(uint reason,z_arch_esf_t *esf)

{
  log_msg_desc desc;
  void *in_r2;
  code *UNRECOVERED_JUMPTABLE;
  
  z_impl_log_panic();
  desc.level = (dword)&stack0xfffffff0;
  desc.domain = 0x1040;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = reason;
  z_impl_z_log_msg_static_create(&PTR_s_fatal_error_0008b958,desc,(uint8_t *)esf,in_r2);
  sys_arch_reboot(0);
                    /* WARNING: Could not recover jumptable at 0x00066e48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


