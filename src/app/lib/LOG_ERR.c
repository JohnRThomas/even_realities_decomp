/*
 * Function: LOG_ERR
 * Entry:    0008708e
 * Prototype: int __stdcall LOG_ERR(char * * param, int param2, char * param3)
 */


/* exclude_from_export */

int LOG_ERR(char **param,int param2,char *param3)

{
  log_msg_desc desc;
  int extraout_r0;
  dword in_stack_00000000;
  uint8_t *in_stack_00000004;
  void *in_stack_00000008;
  
  desc.level = (dword)param3;
  desc.domain = param2;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_00000000;
  z_impl_z_log_msg_static_create(param,desc,in_stack_00000004,in_stack_00000008);
  return extraout_r0;
}


