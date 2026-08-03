/*
 * Function: att_write_rsp
 * Entry:    0005bee0
 * Prototype: uint8_t __stdcall att_write_rsp(bt_att_chan * chan, uint8_t req, uint8_t rsp, uint16_t handle, uint16_t offset, void * value, uint16_t len)
 */


/* exclude_from_export_ai */

uint8_t att_write_rsp(bt_att_chan *chan,uint8_t req,uint8_t rsp,uint16_t handle,uint16_t offset,
                     void *value,uint16_t len)

{
  bool bVar1;
  undefined4 local_30;
  net_buf *local_2c;
  uint8_t local_28;
  void *local_24;
  uint16_t local_20;
  uint16_t local_1e;
  uint8_t local_1c;
  
  bVar1 = bt_gatt_change_aware(*(bt_conn **)chan->att,req != '\0');
  if (bVar1) {
    if (handle == 0) {
      return '\x01';
    }
    memset(&local_30,0,0x18);
    if ((rsp != '\0') && (local_2c = bt_att_chan_create_pdu(chan,rsp,0), local_2c == (net_buf *)0x0)
       ) {
      return '\x11';
    }
    local_30 = *(undefined4 *)chan->att;
    local_1e = offset;
    local_24 = value;
    local_20 = len;
    local_1c = '\x01';
    local_28 = req;
    bt_gatt_foreach_attr(handle,handle,(bt_gatt_attr_func_t)0x85445,&local_30);
    if (local_1c == '\0') {
      if (local_2c != (net_buf *)0x0) {
        bt_att_chan_send_rsp(chan,local_2c);
      }
    }
    else {
      if (rsp != '\0') {
        tx_meta_data_free((bt_att_tx_meta_data *)local_2c->user_data);
        net_buf_unref(local_2c);
        send_err_rsp((bt_l2cap_chan *)chan,(ushort)req,handle);
      }
      if (req == '\x18') {
        return local_1c;
      }
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


