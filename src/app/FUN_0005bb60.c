/*
 * Function: $_?_FUN_0005bb60
 * Entry:    0005bb60
 * Prototype: undefined4 __stdcall $_?_FUN_0005bb60(bt_gatt_attr * param_1, undefined2 param_2, undefined4 * param_3)
 */


undefined4 ____FUN_0005bb60(bt_gatt_attr *param_1,undefined2 param_2,undefined4 *param_3)

{
  uint8_t uVar1;
  char cVar2;
  net_buf *pnVar3;
  uint extraout_r1;
  uint uVar4;
  k_timeout_t timeout;
  undefined8 uVar5;
  undefined4 *puVar6;
  
  puVar6 = param_3;
  uVar1 = bt_gatt_check_perm((bt_conn *)*param_3,param_1,0x12a);
  *(uint8_t *)(param_3 + 4) = uVar1;
  if (uVar1 == '\0') {
    uVar4 = extraout_r1;
    if ((int)((uint)param_1->perm << 0x19) < 0) {
      uVar5 = (*(code *)param_1->write)
                        (*param_3,param_1,param_3[2],*(undefined2 *)(param_3 + 3),
                         *(undefined2 *)((int)param_3 + 0xe),1,puVar6);
      uVar4 = (uint)((ulonglong)uVar5 >> 0x20);
      if ((uint)uVar5 != 0) {
        if ((uint)uVar5 < 0xffffff01) {
          cVar2 = '\x0e';
        }
        else {
          cVar2 = -(char)uVar5;
        }
        *(char *)(param_3 + 4) = cVar2;
        return 0;
      }
    }
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = uVar4;
    pnVar3 = net_buf_alloc((net_buf_pool *)&DAT_20003dbc,timeout);
    param_3[1] = pnVar3;
    if (pnVar3 != (net_buf *)0x0) {
      *(undefined2 *)&pnVar3->user_data = param_2;
      *(undefined2 *)((int)&pnVar3->user_data + 2) = *(undefined2 *)((int)param_3 + 0xe);
      net_buf_add_mem((net_buf *)(param_3[1] + 0xc),(void *)param_3[2],
                      (uint)*(ushort *)(param_3 + 3));
      *(undefined1 *)(param_3 + 4) = 0;
      return 1;
    }
    *(undefined1 *)(param_3 + 4) = 9;
  }
  return 0;
}


