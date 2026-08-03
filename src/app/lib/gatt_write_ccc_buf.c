/*
 * Function: gatt_write_ccc_buf
 * Entry:    00086326
 * Prototype: int __stdcall gatt_write_ccc_buf(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export_ai */

int gatt_write_ccc_buf(net_buf *buf,size_t len,void *user_data)

{
  undefined2 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,2);
  *puVar1 = *(undefined2 *)((int)user_data + 0xe);
  net_buf_simple_add_le16(&(buf->field6_0xc).b,*(uint16_t *)((int)user_data + 0x10));
  atomic_set_bit((atomic_t *)((int)user_data + 0x14),4);
  return 0;
}


