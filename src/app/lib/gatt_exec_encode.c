/*
 * Function: gatt_exec_encode
 * Entry:    00085f54
 * Prototype: int __stdcall gatt_exec_encode(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export */

int gatt_exec_encode(net_buf *buf,size_t len,void *user_data)

{
  bt_att_exec_write_req *req;
  
  req = net_buf_add((net_buf *)&(buf->field6_0xc).field0,1);
  req->flags = '\x01';
  return 0;
}


