/*
 * Function: bt_gatt_attr_read
 * Entry:    000860ea
 * Prototype: ssize_t __stdcall bt_gatt_attr_read(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t buf_len, uint16_t offset, void * value, uint16_t value_len)
 */


/* exclude_from_export */

ssize_t bt_gatt_attr_read(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t buf_len,
                         uint16_t offset,void *value,uint16_t value_len)

{
  bt_gatt_attr *pbVar1;
  uint n;
  
  if ((void *)(uint)offset < buf) {
    n = 0xfffffff9;
  }
  else {
    pbVar1 = (bt_gatt_attr *)((int)(uint)offset - (int)buf);
    if ((int)attr <= (int)pbVar1) {
      pbVar1 = attr;
    }
    n = (uint)pbVar1 & 0xffff;
    memcpy(conn,(void *)((uint)buf_len + (int)buf),n);
  }
  return n;
}


