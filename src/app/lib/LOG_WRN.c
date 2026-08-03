/*
 * Function: LOG_WRN
 * Entry:    00085594
 * Prototype: void __stdcall LOG_WRN(void * param_1, uint param_2, byte * param_3, ...)
 */


/* exclude_from_export */

void LOG_WRN(void *param_1,uint param_2,byte *param_3,...)

{
  log_msg_desc desc;
  dword in_stack_00000000;
  uint8_t *in_stack_00000004;
  void *in_stack_00000008;
  
  desc.level = (dword)param_3;
  desc.domain = param_2;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_00000000;
  z_impl_z_log_msg_static_create(param_1,desc,in_stack_00000004,in_stack_00000008);
  return;
}


