/*
 * Function: gatt_read_type_rsp
 * Entry:    0005efc4
 * Prototype: void __stdcall gatt_read_type_rsp(bt_conn * conn, uint8_t err, void * pdu, uint16_t length, void * user_data)
 */


/* WARNING: Type propagation algorithm not settling */
/* exclude_from_export_ai */

void gatt_read_type_rsp(bt_conn *conn,uint8_t err,void *pdu,uint16_t length,void *user_data)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 *puVar6;
  undefined1 *puVar8;
  uint uVar9;
  uint16_t last_handle;
  uint16_t *puVar10;
  char local_78 [4];
  char *local_74;
  bt_att_chan_opt in_stack_ffffff98;
  undefined1 local_5c [2];
  undefined2 local_5a;
  undefined1 *local_58;
  uint16_t local_54;
  uint16_t local_52;
  undefined1 local_50 [2];
  uint16_t local_4e;
  undefined1 local_4c;
  undefined2 local_4a;
  undefined1 *local_3c;
  undefined1 auStack_38 [8];
  undefined1 **local_30;
  uint16_t local_2c;
  undefined4 *puVar7;
  
  uVar9 = (uint)length;
  if (err != '\0') {
    pcVar5 = *(code **)((int)user_data + 4);
    goto LAB_0005efda;
  }
  if (*(char *)((int)user_data + 0x10) == '\x02') {
    if (*(char *)pdu == '\x06') {
      uVar3 = 2;
LAB_0005f01a:
      last_handle = 0;
      local_50[0] = uVar3;
      puVar10 = (uint16_t *)((int)pdu + 1);
      for (uVar9 = uVar9 - 1; uVar9 = uVar9 & 0xffff, *(byte *)pdu <= uVar9;
          uVar9 = uVar9 - *(byte *)pdu) {
        last_handle = *puVar10;
        if (last_handle == 0) goto switchD_0005f216_caseD_1;
        local_54 = puVar10[1];
        local_52 = puVar10[2];
        if (local_50[0] == '\0') {
          local_58 = local_50;
          local_4e = puVar10[3];
        }
        else if (local_50[0] == '\x02') {
          *(uint16_t *)((int)user_data + 10) = local_54;
          *(uint16_t *)((int)user_data + 0xc) = local_52;
          *(uint16_t *)((int)user_data + 8) = last_handle;
          uVar9 = gatt_req_send(conn,(bt_att_func_t)0x5f2b1,user_data,(bt_att_encode_t)0x85f17,'\n',
                                2,in_stack_ffffff98);
          last_handle = (uint16_t)uVar9;
          if ((uVar9 & 0xffff) == 0) {
            return;
          }
          goto LAB_0005f038;
        }
        if ((*(bt_uuid **)user_data == (bt_uuid *)0x0) ||
           (iVar2 = bt_uuid_cmp((bt_uuid *)local_50,*(bt_uuid **)user_data), iVar2 == 0)) {
          local_5c[0] = 0;
          local_5a = 0x2802;
          memset(auStack_38,0,0x10);
          local_3c = local_5c;
          local_30 = &local_58;
          local_2c = last_handle;
          iVar2 = (**(code **)((int)user_data + 4))(conn,&local_3c,user_data);
          if (iVar2 == 0) {
            return;
          }
        }
        puVar10 = (uint16_t *)((int)puVar10 + (uint)*(byte *)pdu);
      }
      goto LAB_0005f02e;
    }
    uVar3 = 0;
    if (*(char *)pdu == '\b') goto LAB_0005f01a;
LAB_0005f002:
    local_78[0] = '\x03';
    local_78[1] = '\0';
    local_78[2] = '\0';
    local_78[3] = '\0';
    local_74 = "Invalid data len %u";
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_78);
  }
  else {
    if (*(char *)((int)user_data + 0x10) == '\x03') {
      uVar3 = 0;
      if (*(char *)pdu != '\a') {
        if (*(char *)pdu != '\x15') goto LAB_0005f002;
        uVar3 = 2;
      }
      last_handle = 0;
      local_50[0] = uVar3;
      puVar10 = (uint16_t *)((int)pdu + 1);
      for (uVar9 = uVar9 - 1; uVar9 = uVar9 & 0xffff, *(byte *)pdu <= uVar9;
          uVar9 = uVar9 - *(byte *)pdu) {
        last_handle = *puVar10;
        if (last_handle == 0) goto switchD_0005f216_caseD_1;
        if (local_50[0] == '\0') {
          local_4e = *(uint16_t *)((int)puVar10 + 5);
        }
        else if (local_50[0] == '\x02') {
          puVar4 = (undefined4 *)((int)local_50 + 1);
          puVar6 = (undefined4 *)((int)puVar10 + 5);
          do {
            puVar7 = puVar6 + 1;
            *puVar4 = *puVar6;
            puVar4 = puVar4 + 1;
            puVar6 = puVar7;
          } while (puVar7 != (undefined4 *)((int)puVar10 + 0x15));
        }
        if ((*(bt_uuid **)user_data == (bt_uuid *)0x0) ||
           (iVar2 = bt_uuid_cmp((bt_uuid *)local_50,*(bt_uuid **)user_data), iVar2 == 0)) {
          local_54 = *(uint16_t *)((int)puVar10 + 3);
          local_52 = CONCAT11(local_52._1_1_,(char)puVar10[1]);
          local_5c[0] = 0;
          local_58 = local_50;
          local_5a = 0x2803;
          memset(auStack_38,0,0x10);
          local_3c = local_5c;
          local_30 = &local_58;
          local_2c = last_handle;
          iVar2 = (**(code **)((int)user_data + 4))(conn,&local_3c,user_data);
          if (iVar2 == 0) {
            return;
          }
        }
        puVar10 = (uint16_t *)((int)puVar10 + (uint)*(byte *)pdu);
      }
    }
    else {
      if (**(char **)user_data != '\0') goto switchD_0005f216_caseD_1;
      uVar1 = *(undefined2 *)(*(char **)user_data + 2);
      puVar10 = (uint16_t *)((int)pdu + 1);
      last_handle = 0;
      for (uVar9 = uVar9 - 1; uVar9 = uVar9 & 0xffff, *(byte *)pdu <= uVar9;
          uVar9 = uVar9 - *(byte *)pdu) {
        last_handle = *puVar10;
        if (last_handle == 0) goto switchD_0005f216_caseD_1;
        switch(uVar1) {
        case 0x2900:
        case 0x2902:
        case 0x2903:
          local_50 = (undefined1  [2])puVar10[1];
          break;
        default:
          goto switchD_0005f216_caseD_1;
        case 0x2904:
          local_50 = (undefined1  [2])puVar10[1];
          local_4e = puVar10[2];
          local_4c = (undefined1)puVar10[3];
          local_4a = *(undefined2 *)((int)puVar10 + 7);
        }
        puVar8 = *(undefined1 **)user_data;
        memset(auStack_38,0,0x10);
        local_30 = (undefined1 **)local_50;
        local_3c = puVar8;
        local_2c = last_handle;
        iVar2 = (**(code **)((int)user_data + 4))(conn,&local_3c,user_data);
        if (iVar2 == 0) {
          return;
        }
        puVar10 = (uint16_t *)((int)puVar10 + (uint)*(byte *)pdu);
      }
    }
LAB_0005f02e:
    if ((uVar9 == 0) && (last_handle != 0)) {
LAB_0005f038:
      gatt_discover_next(conn,last_handle,user_data);
      return;
    }
  }
switchD_0005f216_caseD_1:
  pcVar5 = *(code **)((int)user_data + 4);
LAB_0005efda:
  (*pcVar5)(conn,0,user_data);
  return;
}


