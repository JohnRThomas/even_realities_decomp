/*
 * Function: gatt_req_send
 * Entry:    000862a6
 * Prototype: int __stdcall gatt_req_send(bt_conn * conn, bt_att_func_t func, void * params, bt_att_encode_t encode, uint8_t op, size_t len, bt_att_chan_opt chan_opt)
 */


/* exclude_from_export_ai */

int gatt_req_send(bt_conn *conn,bt_att_func_t func,void *params,bt_att_encode_t encode,uint8_t op,
                 size_t len,bt_att_chan_opt chan_opt)

{
  bt_att_req *req;
  net_buf *buf;
  int iVar1;
  size_t unaff_r4;
  
  req = gatt_req_alloc("ould not be retrieved successfully. Shall never occur.\n",(void *)0x0,params
                       ,(uint8_t)encode,unaff_r4);
  if (req != (bt_att_req *)0x0) {
    req->func = func;
    req->att_op = op;
    *(size_t *)((int)&req->len + 2) = len;
    req->encode = encode;
    *(void **)((int)&req->user_data + 2) = params;
    buf = bt_att_create_pdu(conn,op,len);
    if (buf != (net_buf *)0x0) {
      bt_att_set_tx_meta_data(buf,(bt_gatt_complete_func_t)0x0,(void *)0x0,1);
      req->buf = (undefined *)buf;
      iVar1 = (*(code *)encode)(buf,len,params);
      if ((iVar1 == 0) && (iVar1 = bt_att_req_send(conn,req), iVar1 == 0)) {
        return 0;
      }
      bt_att_req_free(req);
      return iVar1;
    }
    bt_att_req_free(req);
  }
  return -0xc;
}


