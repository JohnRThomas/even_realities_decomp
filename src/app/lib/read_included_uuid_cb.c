/*
 * Function: read_included_uuid_cb
 * Entry:    0005f2b0
 * Prototype: void __stdcall read_included_uuid_cb(bt_conn * conn, uint8_t err, void * pdu, uint16_t length, void * user_data)
 */


/* exclude_from_export_ai */

void read_included_uuid_cb(bt_conn *conn,uint8_t err,void *pdu,uint16_t length,void *user_data)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar5;
  char local_60 [4];
  char *local_5c;
  uint uStack_58;
  undefined1 local_4c [2];
  undefined2 local_4a;
  bt_uuid *local_48;
  undefined2 local_44;
  undefined2 local_42;
  bt_uuid local_40;
  undefined4 auStack_3f [4];
  undefined1 *local_2c;
  undefined1 auStack_28 [8];
  bt_uuid **local_20;
  undefined2 local_1c;
  undefined4 *puVar4;
  
  uStack_58 = (uint)length;
  if (uStack_58 == 0x10) {
    local_44 = *(undefined2 *)((int)user_data + 10);
    local_48 = &local_40;
    local_42 = *(undefined2 *)((int)user_data + 0xc);
    uVar1 = *(undefined2 *)((int)user_data + 8);
    local_40.type = '\x02';
    puVar3 = pdu;
    puVar5 = auStack_3f;
    do {
      puVar4 = puVar3 + 1;
      *puVar5 = *puVar3;
      puVar3 = puVar4;
      puVar5 = puVar5 + 1;
    } while (puVar4 != (undefined4 *)((int)pdu + 0x10));
    if ((*(bt_uuid **)user_data == (bt_uuid *)0x0) ||
       (iVar2 = bt_uuid_cmp(local_48,*(bt_uuid **)user_data), iVar2 == 0)) {
      local_4c[0] = 0;
      local_4a = 0x2802;
      memset(auStack_28,0,0x10);
      local_2c = local_4c;
      local_20 = &local_48;
      local_1c = uVar1;
      iVar2 = (**(code **)((int)user_data + 4))(conn,&local_2c,user_data);
      if (iVar2 == 0) {
        return;
      }
    }
    gatt_discover_next(conn,*(uint16_t *)((int)user_data + 8),user_data);
  }
  else {
    local_5c = "Invalid data len %u";
    local_60[0] = '\x03';
    local_60[1] = '\0';
    local_60[2] = '\0';
    local_60[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_60);
    (**(code **)((int)user_data + 4))(conn,0,user_data);
  }
  return;
}


