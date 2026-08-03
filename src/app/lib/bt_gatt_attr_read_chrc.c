/*
 * Function: bt_gatt_attr_read_chrc
 * Entry:    00086400
 * Prototype: ssize_t __stdcall bt_gatt_attr_read_chrc(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset)
 */


/* exclude_from_export */

ssize_t bt_gatt_attr_read_chrc
                  (bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset)

{
  ssize_t sVar1;
  uint16_t offset_00;
  char *pcVar2;
  undefined4 *puVar4;
  char *pcVar5;
  void *in_stack_ffffffd4;
  uint16_t in_stack_ffffffd8;
  undefined4 local_21 [4];
  char *pcVar3;
  
  puVar4 = (undefined4 *)attr->user_data;
  bt_gatt_attr_value_handle(attr);
  pcVar5 = (char *)*puVar4;
  if (*pcVar5 == '\0') {
    local_21[0]._0_2_ = *(undefined2 *)(pcVar5 + 2);
    offset_00 = 5;
  }
  else {
    puVar4 = local_21;
    pcVar3 = pcVar5 + 1;
    do {
      pcVar2 = pcVar3 + 4;
      *puVar4 = *(undefined4 *)pcVar3;
      puVar4 = puVar4 + 1;
      pcVar3 = pcVar2;
    } while (pcVar2 != pcVar5 + 0x11);
    offset_00 = 0x13;
  }
  sVar1 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,(void *)(uint)offset,
                            (short)&stack0xfffffff0 - 0x14,offset_00,in_stack_ffffffd4,
                            in_stack_ffffffd8);
  return sVar1;
}


