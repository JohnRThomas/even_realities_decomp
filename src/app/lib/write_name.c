/*
 * Function: write_name
 * Entry:    00086050
 * Prototype: ssize_t __stdcall write_name(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset, uint8_t flags)
 */


/* exclude_from_export_ai */

ssize_t write_name(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset,
                  uint8_t flags)

{
  uint n;
  bt_gatt_attr *local_2c;
  undefined1 auStack_28 [24];
  
  n = (uint)len;
  local_2c = attr;
  memset(auStack_28,(int)attr,0x18);
  if (offset < 0x1c) {
    if (offset + n < 0x1c) {
      memcpy(&local_2c,buf,n);
      bt_set_name((char *)&local_2c);
    }
    else {
      n = 0xfffffff3;
    }
  }
  else {
    n = 0xfffffff9;
  }
  return n;
}


