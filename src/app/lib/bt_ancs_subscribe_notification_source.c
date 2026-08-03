/*
 * Function: bt_ancs_subscribe_notification_source
 * Entry:    000522e0
 * Prototype: int __stdcall bt_ancs_subscribe_notification_source(bt_ancs_client * ancs_c, bt_ancs_ns_notif_cb func)
 */


/* exclude_from_export */

int bt_ancs_subscribe_notification_source(bt_ancs_client *ancs_c,bt_ancs_ns_notif_cb func)

{
  log_msg_desc desc;
  bool bVar1;
  int iVar2;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  int iStack_20;
  
  if ((ancs_c == (bt_ancs_client *)0x0) || (func == (bt_ancs_ns_notif_cb)0x0)) {
    iVar2 = -0x16;
  }
  else {
    bVar1 = atomic_test_and_set_bit((atomic_t *)(ancs_c + 4),0);
    if (bVar1) {
      iVar2 = -0x78;
    }
    else {
      *(undefined4 *)(ancs_c + 0x1028) = 0x82dcf;
      *(undefined2 *)(ancs_c + 0x1038) = 1;
      *(undefined2 *)(ancs_c + 0x1034) = *(undefined2 *)(ancs_c + 10);
      *(undefined2 *)(ancs_c + 0x1036) = *(undefined2 *)(ancs_c + 0xc);
      *(uint *)(ancs_c + 0x103c) = *(uint *)(ancs_c + 0x103c) | 1;
      *(bt_ancs_ns_notif_cb *)(ancs_c + 0x1044) = func;
      iVar2 = bt_gatt_subscribe(*(bt_conn **)ancs_c,(bt_gatt_subscribe_params *)(ancs_c + 0x1028));
      if (iVar2 != 0) {
        atomic_clear_bit((atomic_t *)(ancs_c + 4),0);
        local_24 = "Subscribe Notification Source failed (err %d)";
        local_28 = 3;
        desc.level = (dword)&local_28;
        desc.domain = 0x1840;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffc8;
        iStack_20 = iVar2;
        z_impl_z_log_msg_static_create
                  (&PTR_s_ancs_c_0008b898,desc,in_stack_ffffffcc,in_stack_ffffffd0);
      }
    }
  }
  return iVar2;
}


