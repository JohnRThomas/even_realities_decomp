/*
 * Function: bt_le_adv_resume
 * Entry:    00058d58
 * Prototype: void __stdcall bt_le_adv_resume(void)
 */


/* WARNING: Removing unreachable block (ram,0x00058e38) */
/* exclude_from_export */

void bt_le_adv_resume(void)

{
  log_msg_desc desc;
  bt_le_ext_adv *pbVar1;
  int iVar2;
  int extraout_r0;
  uint extraout_r1;
  uint options;
  bool dir_adv;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  int iStack_28;
  uint8_t uStack_1d;
  bt_conn *local_1c [2];
  
  pbVar1 = bt_le_adv_lookup_legacy();
  if ((((((uint)pbVar1 & 0x4000) != 0) &&
       (pbVar1 = bt_le_adv_lookup_legacy(), -1 < (int)pbVar1 << 0x18)) &&
      (pbVar1 = bt_le_adv_lookup_legacy(), (int)pbVar1 << 0x15 < 0)) &&
     (iVar2 = le_adv_start_add_conn((bt_le_ext_adv *)&bt_dev,local_1c), iVar2 == 0)) {
    adv_is_directed((bt_le_ext_adv *)&bt_dev);
    bt_le_adv_lookup_legacy();
    bt_le_adv_lookup_legacy();
    pbVar1 = bt_le_adv_lookup_legacy();
    options = extraout_r1;
    if ((int)pbVar1 << 0x12 < 0) {
      options = extraout_r1 | 4;
    }
    iStack_28 = bt_id_set_adv_own_addr((bt_le_ext_adv *)&bt_dev,options,dir_adv,&uStack_1d);
    if (iStack_28 == 0) {
      iVar2 = bt_le_adv_set_enable_legacy((bt_le_ext_adv *)&bt_dev,true);
      if (iVar2 == 0) {
        bt_conn_unref(local_1c[0]);
      }
      else {
        bt_conn_set_state(local_1c[0],0);
        atomic_set_bit((atomic_t *)&DAT_20002028,-0x4001);
        bt_conn_unref(local_1c[0]);
        if (extraout_r0 << 0x11 < 0) {
          DAT_20002028 = DAT_20002028 | 0x4000;
        }
      }
    }
    else {
      local_2c = "Controller cannot resume connectable advertising (%d)";
      local_30 = 3;
      desc.level = (dword)&local_30;
      desc.domain = 0x1840;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffc0;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_adv_0008b8a8,desc,in_stack_ffffffc4,in_stack_ffffffc8);
    }
  }
  return;
}


