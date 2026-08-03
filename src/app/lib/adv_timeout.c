/*
 * Function: adv_timeout
 * Entry:    00058d20
 * Prototype: void __stdcall adv_timeout(k_work * work)
 */


/* exclude_from_export */

void adv_timeout(k_work *work)

{
  log_msg_desc desc;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  int iStack_18;
  
  iStack_18 = bt_le_adv_stop();
  if (iStack_18 != 0) {
    local_1c = "Failed to stop advertising: %d";
    local_20 = 3;
    desc.level = (dword)&local_20;
    desc.domain = 0x1880;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffd0;
    z_impl_z_log_msg_static_create(&PTR_s_bt_adv_0008b8a8,desc,in_stack_ffffffd4,in_stack_ffffffd8);
  }
  return;
}


