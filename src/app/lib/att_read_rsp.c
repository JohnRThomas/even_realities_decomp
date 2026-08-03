/*
 * Function: att_read_rsp
 * Entry:    0005c698
 * Prototype: uint8_t __stdcall att_read_rsp(bt_att_chan * chan, uint8_t op, uint8_t rsp, uint16_t handle, uint16_t offset)
 */


/* exclude_from_export_ai */

uint8_t att_read_rsp(bt_att_chan *chan,uint8_t op,uint8_t rsp,uint16_t handle,uint16_t offset)

{
  bool bVar1;
  bt_att_chan *local_28;
  uint16_t local_24;
  net_buf *local_20;
  char local_1c;
  
  bVar1 = bt_gatt_change_aware(*(bt_conn **)chan->att,true);
  if (bVar1) {
    if (handle == 0) {
      return '\x01';
    }
    memset(&local_28,0,0x10);
    local_20 = bt_att_create_rsp_pdu(chan,rsp,0);
    if (local_20 == (net_buf *)0x0) {
      return '\x11';
    }
    local_24 = offset;
    local_1c = '\x01';
    local_28 = chan;
    bt_gatt_foreach_attr(handle,handle,(bt_gatt_attr_func_t)0x85731,&local_28);
    if (local_1c == '\0') {
      bt_att_chan_send_rsp(chan,local_20);
    }
    else {
      tx_meta_data_free((bt_att_tx_meta_data *)local_20->user_data);
      net_buf_unref(local_20);
      send_err_rsp((bt_l2cap_chan *)chan,(ushort)op,handle);
    }
  }
  else {
    bVar1 = atomic_test_and_set_bit((atomic_t *)(chan + 8),5);
    if (!bVar1) {
      return '\x12';
    }
  }
  return '\0';
}


