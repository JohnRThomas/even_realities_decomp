/*
 * Function: gatt_read_group_encode
 * Entry:    0008621e
 * Prototype: int __stdcall gatt_read_group_encode(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export */

int gatt_read_group_encode(net_buf *buf,size_t len,void *user_data)

{
  undefined2 *puVar1;
  char *pcVar2;
  undefined2 uVar3;
  net_buf_union *buf_00;
  
  buf_00 = &buf->field6_0xc;
  puVar1 = net_buf_add((net_buf *)&buf_00->field0,6);
  *puVar1 = *(undefined2 *)((int)user_data + 8);
  puVar1[1] = *(undefined2 *)((int)user_data + 0xe);
  uVar3 = 0x2801;
  if (*(char *)((int)user_data + 0x10) == '\0') {
    uVar3 = 0x2800;
  }
  puVar1[2] = uVar3;
  pcVar2 = *(char **)user_data;
  if (*pcVar2 == '\0') {
    net_buf_simple_add_le16(&buf_00->b,*(uint16_t *)(pcVar2 + 2));
  }
  else if (*pcVar2 == '\x02') {
    net_buf_add_mem((net_buf *)&buf_00->field0,pcVar2 + 1,0x10);
  }
  return 0;
}


