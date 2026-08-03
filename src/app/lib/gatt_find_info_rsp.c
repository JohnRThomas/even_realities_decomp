/*
 * Function: gatt_find_info_rsp
 * Entry:    0005f368
 * Prototype: void __stdcall gatt_find_info_rsp(bt_conn * conn, uint8_t err, void * pdu, uint16_t length, void * user_data)
 */


/* exclude_from_export_ai */

void gatt_find_info_rsp(bt_conn *conn,uint8_t err,void *pdu,uint16_t length,void *user_data)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined4 *puVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar9;
  char local_78 [4];
  char *local_74;
  uint uStack_70;
  uint local_64;
  uint local_60;
  bt_conn *local_5c;
  bt_uuid local_58 [2];
  undefined2 local_56;
  bt_uuid local_54 [2];
  undefined2 local_52;
  bt_uuid local_50;
  undefined4 uStack_4f;
  undefined4 local_3c;
  undefined1 auStack_38 [12];
  undefined2 local_2c;
  ushort *puVar8;
  
  local_5c = conn;
  if (err == '\0') {
    bVar4 = *(byte *)pdu;
    uVar2 = (uint)bVar4;
    if (uVar2 == 1) {
      uVar2 = 4;
      bVar4 = 0;
    }
    else {
      if (uVar2 != 2) {
        local_74 = "Invalid format %u";
        local_78[0] = '\x03';
        local_78[1] = '\0';
        local_78[2] = '\0';
        local_78[3] = '\0';
        uStack_70 = uVar2;
        LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_78);
        goto LAB_0005f39e;
      }
      uVar2 = 0x12;
    }
    uVar6 = length - 1 & 0xffff;
    local_50.type = bVar4;
    if (uVar2 <= uVar6) {
      bVar1 = false;
      uVar6 = uVar6 / uVar2;
      puVar9 = (ushort *)((int)pdu + 1);
      local_60 = 0;
      do {
        if (uVar6 == 0) {
          gatt_discover_next(local_5c,(uint16_t)local_60,user_data);
          return;
        }
        local_64 = (uint)*puVar9;
        local_60 = local_64;
        if (bVar1) {
LAB_0005f498:
          bVar1 = false;
        }
        else {
          if (local_50.type == 0) {
            uStack_4f._1_2_ = puVar9[1];
          }
          else if (local_50.type == 2) {
            puVar5 = &uStack_4f;
            puVar7 = puVar9 + 1;
            do {
              puVar8 = puVar7 + 2;
              *puVar5 = *(undefined4 *)puVar7;
              puVar5 = puVar5 + 1;
              puVar7 = puVar8;
            } while (puVar8 != puVar9 + 9);
          }
          if ((*(bt_uuid **)user_data != (bt_uuid *)0x0) &&
             (iVar3 = bt_uuid_cmp(&local_50,*(bt_uuid **)user_data), iVar3 != 0)) goto LAB_0005f498;
          if (*(char *)((int)user_data + 0x10) == '\x04') {
            local_58[0].type = '\0';
            local_56 = 0x2800;
            iVar3 = bt_uuid_cmp(&local_50,local_58);
            if (iVar3 != 0) {
              local_54[0].type = '\0';
              local_52 = 0x2801;
              iVar3 = bt_uuid_cmp(&local_50,local_54);
              if (iVar3 != 0) {
                local_3c._0_2_ = (ushort)local_3c & 0xff00;
                local_3c = (bt_uuid *)CONCAT22(0x2802,(ushort)local_3c);
                iVar3 = bt_uuid_cmp(&local_50,(bt_uuid *)&local_3c);
                if (iVar3 != 0) {
                  local_3c._0_2_ = (ushort)local_3c & 0xff00;
                  local_3c = (bt_uuid *)CONCAT22(0x2803,(ushort)local_3c);
                  iVar3 = bt_uuid_cmp(&local_50,(bt_uuid *)&local_3c);
                  if (iVar3 != 0) goto LAB_0005f4a4;
                  bVar1 = true;
                  goto LAB_0005f49c;
                }
              }
            }
            goto LAB_0005f498;
          }
LAB_0005f4a4:
          memset(auStack_38,0,0x10);
          local_2c = (undefined2)local_64;
          local_3c = &local_50;
          iVar3 = (**(code **)((int)user_data + 4))(local_5c,&local_3c,user_data);
          if (iVar3 == 0) {
            return;
          }
        }
LAB_0005f49c:
        uVar6 = uVar6 - 1;
        puVar9 = (ushort *)((int)puVar9 + uVar2);
      } while( true );
    }
  }
LAB_0005f39e:
  (**(code **)((int)user_data + 4))(local_5c,0,user_data);
  return;
}


