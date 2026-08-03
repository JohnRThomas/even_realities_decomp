/*
 * Function: read_ppcp
 * Entry:    0005d160
 * Prototype: ssize_t __stdcall read_ppcp(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset)
 */


/* exclude_from_export_ai */

ssize_t read_ppcp(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset)

{
  ssize_t sVar1;
  
  sVar1 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,(void *)(uint)offset,
                            (short)&stack0xffffffe8 + 8,8,attr,0x18);
  return sVar1;
}


