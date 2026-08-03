/*
 * Function: gatt_cancel_encode
 * Entry:    00085f42
 * Prototype: int __stdcall gatt_cancel_encode(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export */

int gatt_cancel_encode(net_buf *buf,size_t len,void *user_data)

{
  undefined1 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,1);
  *puVar1 = 0;
  return 0;
}


