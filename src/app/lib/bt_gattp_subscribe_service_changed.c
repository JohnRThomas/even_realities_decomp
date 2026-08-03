/*
 * Function: bt_gattp_subscribe_service_changed
 * Entry:    000526c4
 * Prototype: int __stdcall bt_gattp_subscribe_service_changed(bt_gattp * gattp, bt_gattp_indicate_cb func)
 */


/* exclude_from_export */

int bt_gattp_subscribe_service_changed(bt_gattp *gattp,bt_gattp_indicate_cb func)

{
  log_msg_desc desc;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  int iStack_20;
  
  if (((gattp == (bt_gattp *)0x0) || (*gattp == 0)) || (func == (bt_gattp_indicate_cb)0x0)) {
    iVar1 = -0x16;
  }
  else {
    puVar3 = (uint *)(gattp + 10);
    uVar2 = *puVar3;
    *puVar3 = uVar2 | 1;
    if ((uVar2 & 1) == 0) {
      gattp[9] = (bt_gattp)func;
      gattp[2] = 0x8304d;
      *(undefined2 *)(gattp + 6) = 2;
      gattp[5] = gattp[1];
      gattp[7] = gattp[7] | 1;
      iVar1 = bt_gatt_subscribe((bt_conn *)*gattp,gattp + 2);
      if (iVar1 != 0) {
        *puVar3 = *puVar3 & 0xfffffffe;
        local_24 = "Subscribe Service Changed failed (err %d)";
        local_28 = 3;
        desc.level = (dword)&local_28;
        desc.domain = 0x1840;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffc8;
        iStack_20 = iVar1;
        z_impl_z_log_msg_static_create
                  (&PTR_s_gattp_0008b970,desc,in_stack_ffffffcc,in_stack_ffffffd0);
      }
    }
    else {
      iVar1 = -0x78;
    }
  }
  return iVar1;
}


