/*
 * Function: bt_settings_init
 * Entry:    00056188
 * Prototype: int __stdcall bt_settings_init(void)
 */


/* exclude_from_export */

int bt_settings_init(void)

{
  log_msg_desc desc;
  int iVar1;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  int iStack_18;
  
  iVar1 = settings_subsys_init();
  if (iVar1 != 0) {
    local_1c = "settings_subsys_init failed (err %d)";
    local_20 = 3;
    desc.level = (dword)&local_20;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffd0;
    iStack_18 = iVar1;
    z_impl_z_log_msg_static_create
              (&PTR_s_bt_settings_0008b928,desc,in_stack_ffffffd4,in_stack_ffffffd8);
  }
  return iVar1;
}


