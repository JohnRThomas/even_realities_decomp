/*
 * Function: bt_att_encrypt_change
 * Entry:    00085c6c
 * Prototype: void __stdcall bt_att_encrypt_change(bt_l2cap_chan * chan, uint8_t hci_status)
 */


/* exclude_from_export_ai */

void bt_att_encrypt_change(bt_l2cap_chan *chan,uint8_t hci_status)

{
  net_buf *buf;
  int iVar1;
  uint8_t err;
  bt_conn *conn;
  undefined *puVar2;
  undefined **chan_00;
  
  chan_00 = &chan[-1].destroy;
  conn = chan->conn;
  if (chan[-1].destroy == (undefined *)0x0) {
    return;
  }
  if (hci_status == '\0') {
    bt_gatt_encrypt_change(conn);
    if (conn->sec_level == 1) {
      return;
    }
    puVar2 = chan[0xe].ops;
    if (puVar2 == (undefined *)0x0) {
      return;
    }
    if (-1 < (int)((uint)(byte)puVar2[0x10] << 0x1f)) {
      return;
    }
    if (*(int *)(puVar2 + 0xc) != 0) {
      buf = bt_att_chan_create_pdu((bt_att_chan *)chan_00,puVar2[0x11],*(size_t *)(puVar2 + 0x14));
      if (buf != (net_buf *)0x0) {
        iVar1 = (**(code **)(puVar2 + 0xc))
                          (buf,*(undefined4 *)(puVar2 + 0x14),*(undefined4 *)(puVar2 + 0x18));
        if ((iVar1 == 0) && (iVar1 = chan_send((bt_att_chan *)chan_00,buf), iVar1 == 0)) {
          return;
        }
        tx_meta_data_free((bt_att_tx_meta_data *)buf->user_data);
        net_buf_unref(buf);
      }
      err = '\x0e';
      goto LAB_00085cd6;
    }
  }
  else {
    if (chan[0xe].ops == (undefined *)0x0) {
      return;
    }
    if (-1 < (int)((uint)(byte)chan[0xe].ops[0x10] << 0x1f)) {
      return;
    }
  }
  err = '\x05';
LAB_00085cd6:
  att_handle_rsp((bt_att_chan *)chan_00,(void *)0x0,0,err);
  return;
}


