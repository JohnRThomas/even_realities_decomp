/*
 * Function: bt_ancs_subscribe_data_source
 * Entry:    00052388
 * Prototype: int __stdcall bt_ancs_subscribe_data_source(bt_ancs_client * ancs_c, bt_ancs_ds_notif_cb func)
 */


/* exclude_from_export */

int bt_ancs_subscribe_data_source(bt_ancs_client *ancs_c,bt_ancs_ds_notif_cb func)

{
  log_msg_desc desc;
  bool bVar1;
  int iVar2;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  int iStack_28;
  
  if ((ancs_c == (bt_ancs_client *)0x0) || (func == (bt_ancs_ds_notif_cb)0x0)) {
    iVar2 = -0x16;
  }
  else {
    bVar1 = atomic_test_and_set_bit((atomic_t *)(ancs_c + 4),1);
    if (bVar1) {
      iVar2 = -0x78;
    }
    else {
      *(undefined1 **)(ancs_c + 0x1048) = &LAB_00082d5c_1;
      *(undefined2 *)(ancs_c + 0x1058) = 1;
      *(undefined2 *)(ancs_c + 0x1054) = *(undefined2 *)(ancs_c + 0xe);
      *(undefined2 *)(ancs_c + 0x1056) = *(undefined2 *)(ancs_c + 0x10);
      *(uint *)(ancs_c + 0x105c) = *(uint *)(ancs_c + 0x105c) | 1;
      *(bt_ancs_ds_notif_cb *)(ancs_c + 0x1064) = func;
      iVar2 = bt_gatt_subscribe(*(bt_conn **)ancs_c,(bt_gatt_subscribe_params *)(ancs_c + 0x1048));
      if (iVar2 != 0) {
        atomic_clear_bit((atomic_t *)(ancs_c + 4),1);
        local_2c = "Subscribe Data Source failed (err %d)";
        local_30 = 3;
        desc.level = (dword)&local_30;
        desc.domain = 0x1840;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffc0;
        iStack_28 = iVar2;
        z_impl_z_log_msg_static_create
                  (&PTR_s_ancs_c_0008b898,desc,in_stack_ffffffc4,in_stack_ffffffc8);
      }
    }
  }
  return iVar2;
}


