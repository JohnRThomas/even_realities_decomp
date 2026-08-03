/*
 * Function: gatt_indicate
 * Entry:    0005e51c
 * Prototype: int __stdcall gatt_indicate(bt_conn * conn, uint16_t handle, bt_gatt_indicate_params * params)
 */


/* exclude_from_export_ai */

int gatt_indicate(bt_conn *conn,uint16_t handle,bt_gatt_indicate_params *params)

{
  ushort uVar1;
  uint8_t uVar2;
  bool bVar3;
  bt_att_req *req;
  net_buf *buf;
  uint16_t *puVar4;
  bt_att_encode_t encode;
  uint8_t op;
  int iVar5;
  size_t len;
  size_t in_stack_ffffffc8;
  char local_28 [4];
  char *local_24;
  
  uVar2 = bt_gatt_check_perm(conn,(bt_gatt_attr *)params->attr,0x94);
  if (uVar2 == '\0') {
    bVar3 = bt_gatt_is_subscribed(conn,(bt_gatt_attr *)params->attr,2);
    if (bVar3) {
      uVar1 = params->len;
      req = gatt_req_alloc("ould not be retrieved successfully. Shall never occur.\n",(void *)0x0,
                           encode,op,in_stack_ffffffc8);
      len = uVar1 + 2;
      if (req != (bt_att_req *)0x0) {
        *(size_t *)((int)&req->len + 2) = len;
        req->att_op = 0x1d;
        req->encode = (undefined *)0x0;
        req->func = (undefined *)0x85d8d;
        *(bt_gatt_indicate_params **)((int)&req->user_data + 2) = params;
        buf = bt_att_create_pdu(conn,'\x1d',len);
        if (buf != (net_buf *)0x0) {
          bt_att_set_tx_meta_data(buf,(bt_gatt_complete_func_t)0x0,(void *)0x0,1);
          puVar4 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,2);
          *puVar4 = handle;
          net_buf_add((net_buf *)&(buf->field6_0xc).field0,(uint)params->len);
          memcpy(puVar4 + 1,params->data,(uint)params->len);
          req->buf = (undefined *)buf;
          iVar5 = bt_att_req_send(conn,req);
          if (iVar5 == 0) {
            return 0;
          }
          bt_att_req_free(req);
          return iVar5;
        }
        local_24 = "No buffer available to send indication";
        local_28[0] = '\x02';
        local_28[1] = '\0';
        local_28[2] = '\0';
        local_28[3] = '\0';
        LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
        bt_att_req_free(req);
      }
      iVar5 = -0xc;
    }
    else {
      local_24 = "Device is not subscribed to characteristic";
      local_28[0] = '\x02';
      local_28[1] = '\0';
      local_28[2] = '\0';
      local_28[3] = '\0';
      iVar5 = -0x16;
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
    }
  }
  else {
    iVar5 = -1;
    local_24 = "Link is not encrypted";
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
  }
  return iVar5;
}


