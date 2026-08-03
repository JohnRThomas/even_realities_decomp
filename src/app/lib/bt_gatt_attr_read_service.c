/*
 * Function: bt_gatt_attr_read_service
 * Entry:    00086140
 * Prototype: ssize_t __stdcall bt_gatt_attr_read_service(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset)
 */


/* exclude_from_export_ai */

ssize_t bt_gatt_attr_read_service
                  (bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset)

{
  ssize_t sVar1;
  void *in_stack_00000004;
  uint16_t in_stack_00000008;
  
  if (*attr->user_data != '\0') {
    sVar1 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,(void *)(uint)offset,
                              (short)attr->user_data + 1,0x10,in_stack_00000004,in_stack_00000008);
    return sVar1;
  }
  sVar1 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,(void *)(uint)offset,
                            (short)&stack0xffffffe8 + 0xe,2,attr,(uint16_t)buf);
  return sVar1;
}


