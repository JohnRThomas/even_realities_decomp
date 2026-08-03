/*
 * Function: keys_set
 * Entry:    00061d10
 * Prototype: int __stdcall keys_set(char * name, size_t len_rd, settings_read_cb read_cb, void * cb_arg)
 */


/* exclude_from_export_ai */

int keys_set(char *name,size_t len_rd,settings_read_cb read_cb,void *cb_arg)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  log_msg_desc desc_02;
  log_msg_desc desc_03;
  log_msg_desc desc_04;
  int iVar1;
  int iVar2;
  bt_keys *pbVar3;
  undefined4 uVar4;
  char *str;
  char *str_00;
  size_t len;
  size_t len_00;
  dword in_stack_ffffff68;
  uint8_t *in_stack_ffffff6c;
  void *in_stack_ffffff70;
  undefined1 *local_88;
  char *local_84;
  char *pcStack_80;
  undefined4 local_7c;
  dword in_stack_ffffff88;
  uint8_t *in_stack_ffffff8c;
  void *in_stack_ffffff90;
  undefined1 auStack_68 [16];
  undefined4 local_58;
  char *local_54;
  
  if (name == (char *)0x0) {
    local_54 = "Insufficient number of arguments";
    local_58 = 2;
    desc_04.level = (dword)&local_58;
    desc_04.domain = 0x1040;
    desc_04.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_04.data_len = in_stack_ffffff88;
    z_impl_z_log_msg_static_create
              (&PTR_s_bt_keys_0008b908,desc_04,in_stack_ffffff8c,in_stack_ffffff90);
  }
  else {
    iVar1 = (*(code *)read_cb)(cb_arg,auStack_68,0x50);
    if (iVar1 < 0) {
      local_84 = "Failed to read value (err %zd)";
      local_88 = (undefined1 *)0x3;
      desc_03.level = (dword)&local_88;
      desc_03.domain = 0x1840;
      desc_03.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_03.data_len = in_stack_ffffff68;
      pcStack_80 = (char *)iVar1;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_keys_0008b908,desc_03,in_stack_ffffff6c,in_stack_ffffff70);
    }
    else {
      iVar2 = bt_settings_decode_key(name,(bt_addr_le_t *)&stack0xffffff90);
      if (iVar2 == 0) {
        settings_name_next(name,(char **)&stack0xffffff8c);
        if ((in_stack_ffffff8c == (uint8_t *)0x0) ||
           (pcStack_80 = (char *)strtoul((char *)in_stack_ffffff8c,(char **)0x0,10),
           pcStack_80 == (char *)0x0)) {
          if (iVar1 == 0) {
            pbVar3 = bt_keys_find(0x3f,'\0',(bt_addr_le_t *)&stack0xffffff90);
            if (pbVar3 == (bt_keys *)0x0) {
              pcStack_80 = (char *)bt_addr_le_to_str((bt_addr_le_t *)&stack0xffffff90,str,len);
              local_84 = "Unable to find deleted keys for %s";
              local_7c = CONCAT22(local_7c._2_2_,0x200);
              local_88 = &DAT_01000003;
              desc_01.level = (dword)&local_88;
              desc_01.domain = 0x1c80;
              desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
              desc_01.data_len = in_stack_ffffff68;
              z_impl_z_log_msg_static_create
                        (&PTR_s_bt_keys_0008b908,desc_01,in_stack_ffffff6c,in_stack_ffffff70);
              return 0;
            }
            memset(pbVar3,0,0x5c);
            return 0;
          }
          pbVar3 = bt_keys_get_addr_impl(0,(undefined4 *)&stack0xffffff90);
          if (pbVar3 != (bt_keys *)0x0) {
            if (iVar1 != 0x50) {
              local_84 = "Invalid key length %zd != %zu";
              local_7c = 0x50;
              local_88 = (undefined1 *)0x4;
              desc.level = (dword)&local_88;
              desc.domain = 0x2040;
              desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
              desc.data_len = in_stack_ffffff68;
              pcStack_80 = (char *)iVar1;
              z_impl_z_log_msg_static_create
                        (&PTR_s_bt_keys_0008b908,desc,in_stack_ffffff6c,in_stack_ffffff70);
              bt_keys_clear(pbVar3);
              return -0x16;
            }
            memcpy(&pbVar3->keys,auStack_68,0x50);
            return 0;
          }
          pcStack_80 = (char *)bt_addr_le_to_str((bt_addr_le_t *)&stack0xffffff90,str_00,len_00);
          local_84 = "Failed to allocate keys for %s";
          local_7c = CONCAT22(local_7c._2_2_,0x200);
          local_88 = &DAT_01000003;
          desc_00.level = (dword)&local_88;
          desc_00.domain = 0x1c40;
          desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
          desc_00.data_len = in_stack_ffffff68;
          z_impl_z_log_msg_static_create
                    (&PTR_s_bt_keys_0008b908,desc_00,in_stack_ffffff6c,in_stack_ffffff70);
          return -0xc;
        }
        local_84 = "Invalid local identity %lu";
        local_88 = (undefined1 *)0x3;
        uVar4 = 0x1840;
      }
      else {
        local_84 = "Unable to decode address %s";
        local_7c = CONCAT22(local_7c._2_2_,0x200);
        local_88 = &DAT_01000003;
        uVar4 = 0x1c40;
        pcStack_80 = name;
      }
      desc_02.level = (dword)&local_88;
      desc_02.domain = uVar4;
      desc_02.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_02.data_len = in_stack_ffffff68;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_keys_0008b908,desc_02,in_stack_ffffff6c,in_stack_ffffff70);
    }
  }
  return -0x16;
}


