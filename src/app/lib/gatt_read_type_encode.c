/*
 * Function: gatt_read_type_encode
 * Entry:    00085f96
 * Prototype: int __stdcall gatt_read_type_encode(net_buf * buf, size_t len, bt_gatt_discover_params * user_data)
 */


/* exclude_from_export */

int gatt_read_type_encode(net_buf *buf,size_t len,bt_gatt_discover_params *user_data)

{
  char cVar1;
  undefined2 *puVar2;
  uint16_t val;
  
  puVar2 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,4);
  *puVar2 = *(undefined2 *)&user_data->attr_handle;
  puVar2[1] = user_data->end_handle;
  cVar1 = (char)user_data->_included;
  if (cVar1 == '\x02') {
    val = 0x2802;
  }
  else if (cVar1 == '\x03') {
    val = 0x2803;
  }
  else {
    val = *(uint16_t *)(user_data->uuid + 2);
  }
  net_buf_simple_add_le16(&(buf->field6_0xc).b,val);
  return 0;
}


