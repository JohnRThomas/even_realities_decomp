/*
 * Function: hci_set_ad
 * Entry:    000587e0
 * Prototype: int __stdcall hci_set_ad(uint16_t hci_op, bt_ad * ad, size_t ad_len)
 */


/* exclude_from_export_ai */

int hci_set_ad(uint16_t hci_op,bt_ad *ad,size_t ad_len)

{
  log_msg_desc desc;
  uint uVar1;
  net_buf *buf;
  undefined1 *buf_00;
  int iVar2;
  uint uVar3;
  size_t n;
  uint8_t *puVar4;
  uint uVar5;
  char *pcVar6;
  bt_ad *pbVar7;
  char cVar8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined4 local_30;
  char *local_2c;
  
  uVar1 = (uint)hci_op;
  buf = bt_hci_cmd_create(hci_op,' ');
  if (buf == (net_buf *)0x0) {
    return -0x69;
  }
  buf_00 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x20);
  memset(buf_00,0,0x20);
  uVar5 = 0;
  pbVar7 = ad + ad_len;
  do {
    pcVar6 = ad->data;
    puVar4 = (uint8_t *)0x0;
    while (puVar4 < (uint8_t *)ad->len) {
      n = (size_t)(byte)pcVar6[1];
      uVar3 = uVar5 + 2;
      cVar8 = *pcVar6;
      if (0x1f < n + uVar3) {
        n = 0x1f - uVar3;
        if ((cVar8 != '\t') || ((int)n < 1)) {
          local_2c = "Too big advertising data";
          local_30 = 2;
          desc.level = (dword)&local_30;
          desc.domain = 0x1040;
          desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
          desc.data_len = uVar1;
          z_impl_z_log_msg_static_create
                    (&PTR_s_bt_adv_0008b8a8,desc,in_stack_ffffffbc,in_stack_ffffffc0);
          net_buf_unref(buf);
          return -0x16;
        }
        cVar8 = '\b';
      }
      buf_00[uVar5 + 1] = (char)n + '\x01';
      buf_00[(uVar5 + 1 & 0xff) + 1] = cVar8;
      in_stack_ffffffbc = puVar4;
      memcpy(buf_00 + (uVar3 & 0xff) + 1,*(void **)(pcVar6 + 4),n);
      uVar5 = (n & 0xff) + 2 + uVar5 & 0xff;
      pcVar6 = pcVar6 + 8;
      puVar4 = in_stack_ffffffbc + 1;
    }
    ad = ad + 1;
    if (pbVar7 == ad) {
      *buf_00 = (char)uVar5;
      iVar2 = bt_hci_cmd_send_sync((uint16_t)uVar1,buf,(net_buf **)0x0);
      return iVar2;
    }
  } while( true );
}


