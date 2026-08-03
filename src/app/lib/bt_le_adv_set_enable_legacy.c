/*
 * Function: bt_le_adv_set_enable_legacy
 * Entry:    00084a8a
 * Prototype: int __stdcall bt_le_adv_set_enable_legacy(bt_le_ext_adv * adv, bool enable)
 */


/* exclude_from_export */

int bt_le_adv_set_enable_legacy(bt_le_ext_adv *adv,bool enable)

{
  net_buf *buf;
  int iVar1;
  bt_hci_cmd_state_set abStack_1c [3];
  
  buf = bt_hci_cmd_create(0x200a,'\x01');
  if (buf == (net_buf *)0x0) {
    iVar1 = -0x69;
  }
  else {
    net_buf_add_u8((net_buf *)&(buf->field6_0xc).field0,enable);
    bt_hci_cmd_state_set_init(buf,abStack_1c,(atomic_t *)&adv->BT_ADV_NUM_FLAGS_,7,enable);
    iVar1 = bt_hci_cmd_send_sync(0x200a,buf,(net_buf **)0x0);
  }
  return iVar1;
}


