/*
 * Function: bt_dh_key_gen
 * Entry:    00059120
 * Prototype: int __stdcall bt_dh_key_gen(uint8_t * remote_pk, bt_dh_key_cb_t cb)
 */


/* exclude_from_export_ai */

int bt_dh_key_gen(uint8_t *remote_pk,bt_dh_key_cb_t cb)

{
  log_msg_desc desc;
  net_buf *buf;
  undefined4 *puVar1;
  uint8_t *puVar2;
  int iVar4;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  int iStack_20;
  uint8_t *puVar3;
  
  if (DAT_2000b650 == cb) {
    iVar4 = -0x78;
  }
  else if ((DAT_2000b650 == (bt_dh_key_cb_t)0x0) && (-1 < DAT_200020d4 << 0x1a)) {
    if (DAT_200020d4 << 0x1b < 0) {
      DAT_2000b650 = cb;
      buf = bt_hci_cmd_create(0x2026,'@');
      if (buf == (net_buf *)0x0) {
        iVar4 = -0x69;
      }
      else {
        puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x40);
        puVar3 = remote_pk;
        do {
          puVar2 = puVar3 + 4;
          *puVar1 = *(undefined4 *)puVar3;
          puVar1 = puVar1 + 1;
          puVar3 = puVar2;
        } while (puVar2 != remote_pk + 0x40);
        iVar4 = bt_hci_cmd_send_sync(0x2026,buf,(net_buf **)0x0);
        if (iVar4 == 0) {
          return 0;
        }
      }
      DAT_2000b650 = (bt_dh_key_cb_t)0x0;
      local_24 = "Failed to generate DHKey (err %d)";
      local_28 = 3;
      desc.level = (dword)&local_28;
      desc.domain = 0x1880;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffc8;
      iStack_20 = iVar4;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_ecc_000f1a34_0x40_0008b8d0,desc,in_stack_ffffffcc,in_stack_ffffffd0);
    }
    else {
      iVar4 = -0x7d;
    }
  }
  else {
    iVar4 = -0x10;
  }
  return iVar4;
}


