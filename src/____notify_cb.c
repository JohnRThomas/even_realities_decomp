/*
 * Function: $_?_notify_cb
 * Entry:    0005eb3c
 * Prototype: uint8_t __stdcall $_?_notify_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


uint8_t ____notify_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  bool bVar1;
  uint8_t uVar2;
  bt_conn *pbVar3;
  int iVar4;
  uint16_t *puVar5;
  bt_addr_le_t *a;
  uint8_t *puVar6;
  uint uVar7;
  
  if (attr->write != (undefined *)0x5d711) {
    return '\x01';
  }
  puVar6 = attr->user_data;
  if (puVar6 == &DAT_20002a40) {
    iVar4 = 0;
    a = &sc_cfg.peer;
    do {
      bVar1 = bt_addr_le_eq(a,(bt_addr_le_t *)&DAT_000f0b50);
      if (!bVar1) {
        pbVar3 = bt_conn_lookup_state_le(a[-1].a.val[5],a,7);
        if (pbVar3 == (bt_conn *)0x0) {
          puVar5 = *(uint16_t **)(*(int *)((int)user_data + 0x10) + 0x10);
          sc_save(a[-1].a.val[5],a,*puVar5,puVar5[1]);
        }
        else {
          bt_conn_unref(pbVar3);
        }
      }
      iVar4 = iVar4 + 1;
      a = (bt_addr_le_t *)(a[1].a.val + 4);
    } while (iVar4 != 3);
  }
  if (*(short *)(puVar6 + 8) != *(short *)((int)user_data + 0xc)) {
    return '\x01';
  }
  pbVar3 = bt_conn_lookup_addr_le(*puVar6,(bt_addr_le_t *)(puVar6 + 1));
  if (pbVar3 == (bt_conn *)0x0) {
    return '\x01';
  }
  if ((pbVar3->state == 7) &&
     ((*(code **)(puVar6 + 0x14) == (code *)0x0 ||
      (iVar4 = (**(code **)(puVar6 + 0x14))(pbVar3,attr), iVar4 != 0)))) {
    uVar2 = bt_gatt_check_perm(pbVar3,attr,0x94);
    if (uVar2 == '\0') {
      if (*(short *)((int)user_data + 0xc) == 2) {
        uVar7 = *(ushort *)(puVar6 + 8) & 2;
        if ((*(ushort *)(puVar6 + 8) & 2) != 0) {
          iVar4 = gatt_indicate(pbVar3,*(uint16_t *)((int)user_data + 4),
                                *(bt_gatt_indicate_params **)((int)user_data + 0x10));
          if (iVar4 != 0) goto LAB_0005ec50;
          *(char *)(*(int *)((int)user_data + 0x10) + 0x16) =
               *(char *)(*(int *)((int)user_data + 0x10) + 0x16) + '\x01';
          uVar7 = 0;
        }
      }
      else {
        if (*(short *)((int)user_data + 0xc) != 1) {
          bt_conn_unref(pbVar3);
          *(undefined4 *)((int)user_data + 8) = 0;
          return '\x01';
        }
        uVar7 = *(ushort *)(puVar6 + 8) & 1;
        if ((*(ushort *)(puVar6 + 8) & 1) != 0) {
          iVar4 = bt_att_send(pbVar3,(net_buf *)(uint)*(ushort *)((int)user_data + 4));
LAB_0005ec50:
          bt_conn_unref(pbVar3);
          *(int *)((int)user_data + 8) = iVar4;
          if (-1 < iVar4) {
            return '\x01';
          }
          return '\0';
        }
      }
      bt_conn_unref(pbVar3);
      *(uint *)((int)user_data + 8) = uVar7;
      return '\x01';
    }
    LOG_ERR(0x8b8d8);
  }
  bt_conn_unref(pbVar3);
  return '\x01';
}


