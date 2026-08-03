/*
 * Function: att_find_type_req
 * Entry:    0005c7fc
 * Prototype: uint8_t __stdcall att_find_type_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_find_type_req(bt_att_chan *chan,net_buf *buf)

{
  undefined1 uVar1;
  uint16_t end_handle;
  ushort uVar2;
  uint16_t *puVar3;
  int iVar4;
  uint16_t start_handle;
  uint8_t *puVar5;
  bt_uuid local_38 [2];
  uint16_t local_36;
  undefined4 local_34;
  net_buf *local_30;
  int local_2c;
  uint8_t *puStack_28;
  undefined1 local_24;
  char local_23;
  
  puVar3 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,6);
  start_handle = *puVar3;
  end_handle = puVar3[1];
  puVar5 = (buf->field6_0xc).field0.data;
  if (start_handle != 0) {
    if (end_handle == 0) {
      start_handle = 0;
    }
    else if (start_handle <= end_handle) {
      local_38[0].type = '\0';
      uVar2 = (ushort)local_34;
      local_34 = (bt_att_chan *)CONCAT22(0x2800,uVar2 & 0xff00);
      local_36 = puVar3[2];
      iVar4 = bt_uuid_cmp(local_38,(bt_uuid *)&local_34);
      if (iVar4 == 0) {
        uVar1 = *(undefined1 *)((int)&buf->field6_0xc + 4);
        memset(&local_34,0,0x14);
        local_30 = bt_att_create_rsp_pdu(chan,'\a',0);
        if (local_30 == (net_buf *)0x0) {
          return '\x11';
        }
        local_23 = '\n';
        local_34 = chan;
        local_2c = iVar4;
        puStack_28 = puVar5;
        local_24 = uVar1;
        bt_gatt_foreach_attr(start_handle,end_handle,(bt_gatt_attr_func_t)0x5b67d,&local_34);
        if (local_23 == '\0') {
          bt_att_chan_send_rsp(chan,local_30);
          return '\0';
        }
        tx_meta_data_free((bt_att_tx_meta_data *)local_30->user_data);
        net_buf_unref(local_30);
      }
    }
  }
  send_err_rsp((bt_l2cap_chan *)chan,6,start_handle);
  return '\0';
}


