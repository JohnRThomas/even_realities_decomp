/*
 * Function: att_read_group_req
 * Entry:    0005c44c
 * Prototype: uint8_t __stdcall att_read_group_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_read_group_req(bt_att_chan *chan,net_buf *buf)

{
  uint16_t end_handle;
  bool bVar1;
  uint16_t *puVar2;
  int iVar3;
  uint16_t start_handle;
  ushort uVar4;
  ushort uVar5;
  bt_uuid local_44 [2];
  undefined2 local_42;
  bt_uuid abStack_40 [20];
  undefined4 local_2c;
  bt_uuid *pbStack_28;
  net_buf *local_24;
  char *local_20;
  undefined4 local_1c;
  
  uVar4 = (buf->field6_0xc).field0.len - 4;
  uVar5 = uVar4 & 0xff;
  if ((uVar5 != 2) && (uVar5 != 0x10)) {
    return '\x04';
  }
  puVar2 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,4);
  start_handle = *puVar2;
  end_handle = puVar2[1];
  bVar1 = bt_uuid_create(abStack_40,(uint8_t *)(puVar2 + 2),(uint8_t)uVar4);
  if (!bVar1) {
    return '\x0e';
  }
  if (start_handle != 0) {
    if (end_handle == 0) {
      start_handle = 0;
    }
    else if (start_handle <= end_handle) {
      local_44[0].type = '\0';
      local_42 = 0x2800;
      iVar3 = bt_uuid_cmp(abStack_40,local_44);
      if (iVar3 != 0) {
        uVar4 = (ushort)local_2c;
        local_2c = (bt_att_chan *)CONCAT22(0x2801,uVar4 & 0xff00);
        iVar3 = bt_uuid_cmp(abStack_40,(bt_uuid *)&local_2c);
        if (iVar3 != 0) goto LAB_0005c520;
      }
      memset(&local_2c,0,0x14);
      local_24 = bt_att_create_rsp_pdu(chan,'\x11',1);
      if (local_24 == (net_buf *)0x0) {
        return '\x11';
      }
      local_2c = chan;
      pbStack_28 = abStack_40;
      local_20 = net_buf_add((net_buf *)&(local_24->field6_0xc).field0,1);
      *local_20 = '\0';
      local_1c = 0;
      bt_gatt_foreach_attr(start_handle,end_handle,(bt_gatt_attr_func_t)0x5b9fd,&local_2c);
      if (*local_20 != '\0') {
        bt_att_chan_send_rsp(chan,local_24);
        return '\0';
      }
      tx_meta_data_free((bt_att_tx_meta_data *)local_24->user_data);
      net_buf_unref(local_24);
    }
  }
LAB_0005c520:
  send_err_rsp((bt_l2cap_chan *)chan,0x10,start_handle);
  return '\0';
}


