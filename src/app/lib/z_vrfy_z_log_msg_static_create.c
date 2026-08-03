/*
 * Function: z_vrfy_z_log_msg_static_create
 * Entry:    00086f5a
 * Prototype: void __stdcall z_vrfy_z_log_msg_static_create(void * source, log_msg_desc desc, uint8_t * package, void * data)
 */


/* exclude_from_export */

void z_vrfy_z_log_msg_static_create(void *source,log_msg_desc desc,uint8_t *package,void *data)

{
  log_msg_desc desc_00;
  
  desc_00.level = desc.level;
  desc_00.domain = desc.domain;
  desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc_00.data_len = desc.data_len;
  z_impl_z_log_msg_static_create(source,desc_00,package,data);
  return;
}


