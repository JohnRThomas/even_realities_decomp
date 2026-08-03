/*
 * Function: prep_write_cb
 * Entry:    0005bb60
 * Prototype: uint8_t __stdcall prep_write_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export */

uint8_t prep_write_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  uint8_t uVar1;
  char cVar2;
  net_buf *pnVar3;
  uint extraout_r1;
  uint uVar4;
  undefined8 uVar5;
  k_timeout_t timeout;
  void *pvVar6;
  
  pvVar6 = user_data;
  uVar1 = bt_gatt_check_perm(*(bt_conn **)user_data,attr,0x12a);
  *(uint8_t *)((int)user_data + 0x10) = uVar1;
  if (uVar1 == '\0') {
    uVar4 = extraout_r1;
    if ((int)((uint)attr->perm << 0x19) < 0) {
      uVar5 = (*(code *)attr->write)
                        (*(undefined4 *)user_data,attr,*(undefined4 *)((int)user_data + 8),
                         *(undefined2 *)((int)user_data + 0xc),*(undefined2 *)((int)user_data + 0xe)
                         ,1,pvVar6);
      uVar4 = (uint)((ulonglong)uVar5 >> 0x20);
      if ((uint)uVar5 != 0) {
        if ((uint)uVar5 < 0xffffff01) {
          cVar2 = '\x0e';
        }
        else {
          cVar2 = -(char)uVar5;
        }
        *(char *)((int)user_data + 0x10) = cVar2;
        return '\0';
      }
    }
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = uVar4;
    pnVar3 = net_buf_alloc((net_buf_pool *)&DAT_20003dbc,timeout);
    *(net_buf **)((int)user_data + 4) = pnVar3;
    if (pnVar3 != (net_buf *)0x0) {
      *(uint16_t *)&pnVar3->user_data = handle;
      *(undefined2 *)((int)&pnVar3->user_data + 2) = *(undefined2 *)((int)user_data + 0xe);
      net_buf_add_mem((net_buf *)(*(int *)((int)user_data + 4) + 0xc),*(void **)((int)user_data + 8)
                      ,(uint)*(ushort *)((int)user_data + 0xc));
      *(undefined1 *)((int)user_data + 0x10) = 0;
      return '\x01';
    }
    *(undefined1 *)((int)user_data + 0x10) = 9;
  }
  return '\0';
}


