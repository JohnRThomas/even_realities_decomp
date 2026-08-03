/*
 * Function: set_setting
 * Entry:    00056004
 * Prototype: int __stdcall set_setting(char * name, size_t len_rd, settings_read_cb read_cb, void * cb_arg)
 */


/* exclude_from_export */

int set_setting(char *name,size_t len_rd,settings_read_cb read_cb,void *cb_arg)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  log_msg_desc desc_02;
  size_t n;
  int iVar1;
  uint uVar2;
  uint uVar3;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  undefined4 local_50;
  char *local_4c;
  int iStack_48;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_28;
  char *local_24;
  
  if ((int)(DAT_200020d4 << 0x1f) < 0) {
    if (name == (char *)0x0) {
      local_24 = "Insufficient number of arguments";
      local_28 = 2;
      desc_02.level = (dword)&local_28;
      desc_02.domain = 0x1040;
      desc_02.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_02.data_len = in_stack_ffffffc0;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_settings_0008b928,desc_02,in_stack_ffffffc4,in_stack_ffffffc8);
      return -2;
    }
    n = settings_name_next(name,(char **)&stack0xffffffc4);
    iVar1 = strncmp(name,"id",n);
    if (iVar1 == 0) {
      iVar1 = DAT_200020d4 << 0x1c;
      uVar3 = (DAT_200020d4 & 0xf) >> 3;
      if ((int)(DAT_200020d4 << 0x1c) < 0) {
        local_24 = "Ignoring identities stored in flash";
        local_28 = 2;
        desc_01.level = (dword)&local_28;
        desc_01.domain = 0x1080;
        desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc_01.data_len = in_stack_ffffffc0;
        z_impl_z_log_msg_static_create
                  (&PTR_s_bt_settings_0008b928,desc_01,in_stack_ffffffc4,in_stack_ffffffc8);
      }
      else {
        uVar2 = (*(code *)read_cb)(cb_arg,&bt_dev,7);
        if (uVar2 < 7) {
          local_24 = "Invalid length ID address in storage";
          local_28 = 2;
          desc_00.level = (dword)&local_28;
          desc_00.domain = 0x1040;
          desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = uVar3;
          desc_00.data_len = in_stack_ffffffc0;
          z_impl_z_log_msg_static_create
                    (&PTR_s_bt_settings_0008b928,desc_00,in_stack_ffffffc4,in_stack_ffffffc8);
          DAT_20002007 = (byte)((uint)iVar1 >> 0x1f);
          bt_dev._0_3_ = (undefined3)uVar3;
          bt_dev._3_1_ = (undefined1)uVar3;
          uRam20002004 = 0;
        }
        else {
          DAT_20002007 = (byte)(uVar2 / 7);
        }
      }
    }
    else {
      iVar1 = strncmp(name,"name",n);
      if (iVar1 != 0) {
        return -2;
      }
      iStack_48 = (*(code *)read_cb)(cb_arg,&BLE_NAME_LEN,0x1c);
      if (iStack_48 < 0) {
        local_4c = "Failed to read device name from storage (err %zd)";
        local_50 = 3;
        desc.level = (dword)&local_50;
        desc.domain = 0x1840;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffa0;
        z_impl_z_log_msg_static_create
                  (&PTR_s_bt_settings_0008b928,desc,in_stack_ffffffa4,in_stack_ffffffa8);
      }
      else {
        (&BLE_NAME_LEN)[iStack_48] = 0;
      }
    }
  }
  return 0;
}


