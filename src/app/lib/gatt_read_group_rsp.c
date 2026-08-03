/*
 * Function: gatt_read_group_rsp
 * Entry:    00086522
 * Prototype: void __stdcall gatt_read_group_rsp(bt_conn * conn, uint8_t err, void * pdu, uint16_t length, void * user_data)
 */


/* exclude_from_export */

void gatt_read_group_rsp(bt_conn *conn,uint8_t err,void *pdu,uint16_t length,void *user_data)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_48 [2];
  undefined2 local_46;
  undefined4 local_44;
  ushort local_40;
  undefined1 *local_3c;
  undefined1 auStack_38 [8];
  undefined4 *local_30;
  undefined2 local_2c;
  
  if ((err == '\0') && (uVar4 = length & 3, (length & 3) == 0)) {
    puVar3 = (undefined2 *)((int)pdu + (length & 0x3fc));
    uVar5 = uVar4;
    do {
      if (pdu == puVar3) {
        gatt_discover_next(conn,(uint16_t)uVar5,user_data);
        return;
      }
      local_40 = *(ushort *)((int)pdu + 2);
      if (*(char *)((int)user_data + 0x10) == '\0') {
        local_46 = 0x2800;
      }
      else {
        local_46 = 0x2801;
      }
      uVar5 = (uint)local_40;
      local_44 = *(undefined4 *)user_data;
      uVar1 = *(undefined2 *)pdu;
      local_48[0] = (undefined1)uVar4;
      memset(auStack_38,0,0x10);
      local_30 = &local_44;
      local_3c = local_48;
      local_2c = uVar1;
      iVar2 = (**(code **)((int)user_data + 4))(conn,&local_3c,user_data);
      pdu = (void *)((int)pdu + 4);
    } while (iVar2 != 0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00086544. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)user_data + 4))(conn,0,user_data);
  return;
}


