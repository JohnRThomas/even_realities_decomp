/*
 * Function: bt_gatt_is_subscribed
 * Entry:    0005e388
 * Prototype: bool __stdcall bt_gatt_is_subscribed(bt_conn * conn, bt_gatt_attr * attr, uint16_t ccc_type)
 */


/* exclude_from_export_ai */

bool bt_gatt_is_subscribed(bt_conn *conn,bt_gatt_attr *attr,uint16_t ccc_type)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  char *test;
  char *test_00;
  char *test_01;
  char *test_02;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  undefined4 in_r3;
  int line;
  int line_00;
  int line_01;
  int line_02;
  uint8_t *puVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = (uint)ccc_type;
  local_28 = conn;
  local_24 = attr;
  local_1c = in_r3;
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c"
            ,3353);
    _ASSERT("\tinvalid parameter\n\n",test,file,line);
  }
  else {
    if (attr != (bt_gatt_attr *)0x0) {
      if (conn->state == 7) {
        local_1c._0_2_ = (ushort)in_r3 & 0xff00;
        local_1c = CONCAT22(0x2803,(ushort)local_1c);
        iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_1c);
        if (iVar3 == 0) {
          if ((attr->user_data[6] & 0x30) == 0) {
            return false;
          }
          attr = bt_gatt_attr_next(attr);
          if (attr == (bt_gatt_attr *)0x0) {
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","attr",
                    "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",3371);
            _ASSERT("\tNo more attributes\n\n",test_01,file_01,line_01);
            goto LAB_0005e3ac;
          }
        }
        local_1c._0_2_ = (ushort)local_1c & 0xff00;
        local_1c = CONCAT22(0x2902,(ushort)local_1c);
        iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_1c);
        if ((iVar3 != 0) && (attr = bt_gatt_attr_next(attr), attr == (bt_gatt_attr *)0x0)) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","attr",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0xd31);
          _ASSERT("\tNo more attributes\n\n",test_02,file_02,line_02);
          goto LAB_0005e3ac;
        }
        do {
          uVar1 = (ushort)local_28;
          local_28 = (bt_conn *)CONCAT22(0x2902,uVar1 & 0xff00);
          iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_28);
          if (iVar3 == 0) {
LAB_0005e476:
            local_1c._0_2_ = (ushort)local_1c & 0xff00;
            local_1c = CONCAT22(0x2902,(ushort)local_1c);
            iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_1c);
            if (iVar3 != 0) {
              return false;
            }
            puVar4 = attr->user_data;
            bVar2 = bt_conn_is_peer_addr_le(conn,*puVar4,(bt_addr_le_t *)(puVar4 + 1));
            if (!bVar2) {
              return false;
            }
            return (ccc_type & *(ushort *)(puVar4 + 8)) != 0;
          }
          uVar1 = (ushort)local_24;
          local_24 = (bt_gatt_attr *)CONCAT22(0x2803,uVar1 & 0xff00);
          iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_24);
          if (iVar3 == 0) goto LAB_0005e476;
          uVar1 = (ushort)local_20;
          local_20 = CONCAT22(0x2800,uVar1 & 0xff00);
          iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_20);
          if (iVar3 == 0) goto LAB_0005e476;
          local_1c._0_2_ = (ushort)local_1c & 0xff00;
          local_1c = CONCAT22(0x2801,(ushort)local_1c);
          iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_1c);
          if (iVar3 == 0) goto LAB_0005e476;
          attr = bt_gatt_attr_next(attr);
        } while (attr != (bt_gatt_attr *)0x0);
      }
      return false;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","attr","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c"
            ,0xd1a);
    _ASSERT("\tinvalid parameter\n\n",test_00,file_00,line_00);
  }
LAB_0005e3ac:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


