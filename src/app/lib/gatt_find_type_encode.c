/*
 * Function: gatt_find_type_encode
 * Entry:    00085f66
 * Prototype: int __stdcall gatt_find_type_encode(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export */

int gatt_find_type_encode(net_buf *buf,size_t len,void *user_data)

{
  undefined2 *puVar1;
  uint16_t val;
  
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,4);
  *puVar1 = *(undefined2 *)((int)user_data + 8);
  puVar1[1] = *(undefined2 *)((int)user_data + 0xe);
  if (*(char *)((int)user_data + 0x10) == '\0') {
    val = 0x2800;
  }
  else {
    val = 0x2801;
  }
  net_buf_simple_add_le16(&(buf->field6_0xc).b,val);
  return 0;
}


