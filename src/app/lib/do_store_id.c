/*
 * Function: do_store_id
 * Entry:    00056214
 * Prototype: void __stdcall do_store_id(k_work * work)
 */


/* exclude_from_export_ai */

void do_store_id(k_work *work)

{
  log_msg_desc desc;
  int iVar1;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_20;
  char *local_1c;
  
  iVar1 = bt_settings_store("id",'\0',(bt_addr_le_t *)0x0,&bt_dev,(uint)DAT_20002007 * 7);
  if (iVar1 != 0) {
    local_1c = "Failed to save ID (err %d)";
    local_20 = 3;
    desc.level = (dword)&local_20;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffc8;
    z_impl_z_log_msg_static_create
              (&PTR_s_bt_settings_0008b928,desc,in_stack_ffffffcc,in_stack_ffffffd0);
  }
  return;
}


