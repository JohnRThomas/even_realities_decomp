/*
 * Function: gatt_find_info_encode
 * Entry:    00085f2a
 * Prototype: int __stdcall gatt_find_info_encode(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export */

int gatt_find_info_encode(net_buf *buf,size_t len,void *user_data)

{
  undefined2 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,4);
  *puVar1 = *(undefined2 *)((int)user_data + 8);
  puVar1[1] = *(undefined2 *)((int)user_data + 0xe);
  return 0;
}


