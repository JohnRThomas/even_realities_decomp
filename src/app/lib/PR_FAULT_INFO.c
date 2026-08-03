/*
 * Function: PR_FAULT_INFO
 * Entry:    00083f38
 * Prototype: undefined __stdcall PR_FAULT_INFO(void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, dword param_5, uint8_t * param_6, void * param_7)
 */


/* exclude_from_export */

void PR_FAULT_INFO(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  dword param_5,uint8_t *param_6,void *param_7)

{
  log_msg_desc desc;
  
  desc.level = param_3;
  desc.domain = param_2;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = param_5;
  z_impl_z_log_msg_static_create(param_1,desc,param_6,param_7);
  return;
}


