/*
 * Function: bt_rpmsg_send
 * Entry:    000633a8
 * Prototype: int __stdcall bt_rpmsg_send(net_buf * buf)
 */


/* exclude_from_export_ai */

int bt_rpmsg_send(net_buf *buf)

{
  byte val;
  uint uVar1;
  char acStack_20 [4];
  char *pcStack_1c;
  uint uStack_18;
  
  val = *(byte *)&buf->user_data;
  uVar1 = (uint)val;
  if (uVar1 == 2) {
LAB_000633e6:
    net_buf_push_u8((net_buf *)&(buf->field6_0xc).field0,val);
    uVar1 = ipc_service_send((ipc_ept *)&DAT_2000ba64,(buf->field6_0xc).field0.data,
                             (uint)(buf->field6_0xc).field0.len);
    if (-1 < (int)uVar1) goto LAB_000633d8;
    pcStack_1c = "Failed to send (err %d)";
    uStack_18 = uVar1;
  }
  else {
    if (uVar1 == 4) {
      val = 5;
      goto LAB_000633e6;
    }
    if (uVar1 == 0) {
      val = 1;
      goto LAB_000633e6;
    }
    pcStack_1c = "Unknown type %u";
    uStack_18 = uVar1;
  }
  acStack_20[0] = '\x03';
  acStack_20[1] = '\0';
  acStack_20[2] = '\0';
  acStack_20[3] = '\0';
  LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1840,acStack_20);
LAB_000633d8:
  net_buf_unref(buf);
  return 0;
}


