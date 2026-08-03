/*
 * Function: read_name
 * Entry:    000861a8
 * Prototype: ssize_t __stdcall read_name(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset)
 */


/* exclude_from_export_ai */

ssize_t read_name(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset)

{
  void *buf_00;
  char *s;
  size_t sVar1;
  ssize_t sVar2;
  void *in_stack_00000004;
  uint16_t in_stack_00000008;
  
  buf_00 = (void *)(uint)offset;
  s = bt_get_name();
  sVar1 = strlen(s);
  offset = (uint16_t)sVar1;
  sVar2 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,buf_00,(uint16_t)s,offset,
                            in_stack_00000004,in_stack_00000008);
  return sVar2;
}


