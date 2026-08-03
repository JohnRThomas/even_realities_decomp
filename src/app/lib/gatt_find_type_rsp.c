/*
 * Function: gatt_find_type_rsp
 * Entry:    0005eea0
 * Prototype: void __stdcall gatt_find_type_rsp(bt_conn * conn, uint8_t err, void * pdu, uint16_t length, void * user_data)
 */


/* exclude_from_export */

void gatt_find_type_rsp(bt_conn *conn,uint8_t err,void *pdu,uint16_t length,void *user_data)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  code *pcVar6;
  ushort *puVar7;
  ushort last_handle;
  ushort *puVar9;
  char local_70 [4];
  char *local_6c;
  uint uStack_68;
  undefined1 local_5c [2];
  undefined2 local_5a;
  char *local_58;
  ushort local_54;
  char local_50;
  undefined4 uStack_4f;
  undefined1 *local_3c [3];
  char **local_30;
  ushort local_2c;
  ushort *puVar8;
  
  if (err != '\0') {
    pcVar6 = *(code **)((int)user_data + 4);
    goto LAB_0005eeba;
  }
  uVar2 = (uint)*(byte *)pdu;
  cVar5 = '\0';
  if (uVar2 == 6) {
LAB_0005eefa:
    last_handle = 0;
    puVar9 = (ushort *)((int)pdu + 1);
    local_50 = cVar5;
    for (uVar2 = length - 1; uVar2 = uVar2 & 0xffff, *(byte *)pdu <= uVar2;
        uVar2 = uVar2 - *(byte *)pdu) {
      memset(local_3c,0,0x14);
      uVar1 = *puVar9;
      if (((uVar1 == 0) || (last_handle = puVar9[1], last_handle == 0)) || (last_handle < uVar1))
      goto LAB_0005eeec;
      if (local_50 == '\0') {
        uStack_4f._1_2_ = puVar9[2];
      }
      else if (local_50 == '\x02') {
        puVar4 = &uStack_4f;
        puVar7 = puVar9 + 2;
        do {
          puVar8 = puVar7 + 2;
          *puVar4 = *(undefined4 *)puVar7;
          puVar4 = puVar4 + 1;
          puVar7 = puVar8;
        } while (puVar8 != puVar9 + 10);
      }
      local_5a = 0x2801;
      if (*(char *)((int)user_data + 0x10) == '\0') {
        local_5a = 0x2800;
      }
      local_58 = &local_50;
      local_3c[0] = local_5c;
      local_30 = &local_58;
      local_5c[0] = 0;
      local_54 = last_handle;
      local_2c = uVar1;
      iVar3 = (**(code **)((int)user_data + 4))(conn,local_3c,user_data);
      if (iVar3 == 0) {
        return;
      }
      puVar9 = (ushort *)((int)puVar9 + (uint)*(byte *)pdu);
    }
    if ((uVar2 == 0) && (last_handle != 0)) {
      gatt_discover_next(conn,last_handle,user_data);
      return;
    }
  }
  else {
    if (uVar2 == 0x14) {
      cVar5 = '\x02';
      goto LAB_0005eefa;
    }
    local_6c = "Invalid data len %u";
    local_70[0] = '\x03';
    local_70[1] = '\0';
    local_70[2] = '\0';
    local_70[3] = '\0';
    uStack_68 = uVar2;
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_70);
  }
LAB_0005eeec:
  pcVar6 = *(code **)((int)user_data + 4);
LAB_0005eeba:
  (*pcVar6)(conn,0,user_data);
  return;
}


