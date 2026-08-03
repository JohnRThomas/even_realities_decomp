/*
 * Function: read_appearance
 * Entry:    000861d2
 * Prototype: ssize_t __stdcall read_appearance(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset)
 */


/* exclude_from_export_ai */

ssize_t read_appearance(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset)

{
  ssize_t sVar1;
  void *in_stack_ffffffe4;
  uint16_t in_stack_ffffffe8;
  
  bt_get_appearance();
  sVar1 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,(void *)(uint)offset,
                            (short)&stack0xfffffff4 - 6,2,in_stack_ffffffe4,in_stack_ffffffe8);
  return sVar1;
}


