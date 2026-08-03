/*
 * Function: commit_settings
 * Entry:    00056370
 * Prototype: int __stdcall commit_settings(void)
 */


/* exclude_from_export */

int commit_settings(void)

{
  log_msg_desc desc;
  int iVar1;
  uint uVar2;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  if ((DAT_200020d4 & 1) != 0) {
    if (BLE_NAME_LEN == 0) {
      bt_set_name("Even G1");
    }
    if ((DAT_20002007 == '\0') &&
       ((iVar1 = bt_setup_public_id_addr(), iVar1 != 0 ||
        ((DAT_20002007 == '\0' && (iVar1 = bt_setup_random_id_addr(), iVar1 != 0)))))) {
      local_1c = "Unable to setup an identity address";
      local_20 = 2;
      desc.level = (dword)&local_20;
      desc.domain = 0x1040;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffd0;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_settings_0008b928,desc,in_stack_ffffffd4,in_stack_ffffffd8);
      return iVar1;
    }
    if (-1 < (int)(DAT_200020d4 << 0x1d)) {
      bt_dev_show_info();
    }
    uVar2 = DAT_200020d4 & 0xfffeffff;
    iVar1 = DAT_200020d4 << 0xf;
    DAT_200020d4 = uVar2;
    if (iVar1 < 0) {
      bt_settings_store_id();
    }
  }
  return 0;
}


