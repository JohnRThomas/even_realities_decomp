/*
 * Function: bt_gatt_discover
 * Entry:    0005ec78
 * Prototype: int __stdcall bt_gatt_discover(bt_conn * conn, bt_gatt_discover_params * params)
 */


/* exclude_from_export */

int bt_gatt_discover(bt_conn *conn,bt_gatt_discover_params *params)

{
  char cVar1;
  bt_uuid *u1;
  int iVar2;
  char *test;
  char *test_00;
  char *test_01;
  char *test_02;
  code *func;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  code *encode;
  char local_38 [4];
  char *local_34;
  uint8_t uVar3;
  size_t len;
  bt_att_chan_opt in_stack_ffffffd8;
  bt_uuid local_24 [2];
  undefined2 local_22;
  bt_uuid local_20 [2];
  undefined2 local_1e;
  bt_uuid local_1c [2];
  undefined2 local_1a;
  
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c"
            ,4495);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
  }
  else if ((params == (bt_gatt_discover_params *)0x0) || (params->func == (undefined *)0x0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params && params->func",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x1190);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
  }
  else if ((*(ushort *)&params->attr_handle == 0) || (params->end_handle == 0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(params->start_handle && params->end_handle)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x1191);
    _ASSERT("\tinvalid parameters\n\n",test_01,file_01,line_01);
  }
  else {
    if (*(ushort *)&params->attr_handle <= params->end_handle) {
      if (conn->state != 7) {
        return -0x80;
      }
      switch((char)params->_included) {
      case '\0':
      case '\x01':
        if (params->uuid == (char *)0x0) {
          uVar3 = '\x10';
          len = 4;
          encode = (code *)0x85f67;
          func = (code *)0x5eea1;
        }
        else {
          cVar1 = *params->uuid;
          if (cVar1 == '\0') {
            len = 8;
          }
          else {
            if (cVar1 != '\x02') {
              local_34 = "Unknown UUID type %u";
              goto LAB_0005ed32;
            }
            len = 0x16;
          }
          uVar3 = '\x06';
          func = (code *)0x86523;
          encode = (code *)0x8621f;
        }
        break;
      case '\x04':
        if ((bt_uuid *)params->uuid != (bt_uuid *)0x0) {
          in_stack_ffffffd8 = CONCAT22(0x2800,(short)((uint)in_stack_ffffffd8 >> 8) << 8);
          iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,(bt_uuid *)&stack0xffffffd8);
          if (iVar2 == 0) {
            return -0x16;
          }
          local_24[0].type = '\0';
          local_22 = 0x2801;
          iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,local_24);
          if (iVar2 == 0) {
            return -0x16;
          }
          local_20[0].type = '\0';
          local_1e = 0x2802;
          iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,local_20);
          if (iVar2 == 0) {
            return -0x16;
          }
          local_1c[0].type = '\0';
          local_1a = 0x2803;
          iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,local_1c);
          if (iVar2 == 0) {
            return -0x16;
          }
        }
      case '\x05':
        uVar3 = '\x04';
        len = 4;
        func = (code *)0x5f369;
        encode = (code *)0x85f2b;
        break;
      case '\x06':
        u1 = (bt_uuid *)params->uuid;
        if (u1 == (bt_uuid *)0x0) {
          return -0x16;
        }
        uVar3 = u1->type;
        if (uVar3 != '\0') {
          return -0x16;
        }
        in_stack_ffffffd8 = CONCAT22(0x2900,(ushort)in_stack_ffffffd8 & 0xff00);
        iVar2 = bt_uuid_cmp(u1,(bt_uuid *)&stack0xffffffd8);
        if (iVar2 != 0) {
          local_22 = 0x2902;
          local_24[0].type = uVar3;
          iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,local_24);
          if (iVar2 != 0) {
            local_1e = 0x2903;
            local_20[0].type = uVar3;
            iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,local_20);
            if (iVar2 != 0) {
              local_1a = 0x2904;
              local_1c[0].type = uVar3;
              iVar2 = bt_uuid_cmp((bt_uuid *)params->uuid,local_1c);
              if (iVar2 != 0) {
                return -0x16;
              }
            }
          }
        }
      case '\x02':
      case '\x03':
        func = (code *)0x5efc5;
        uVar3 = '\b';
        len = 4;
        encode = (code *)0x85f97;
        break;
      default:
        local_34 = "Invalid discovery type: %u";
LAB_0005ed32:
        local_38[0] = '\x03';
        local_38[1] = '\0';
        local_38[2] = '\0';
        local_38[3] = '\0';
        LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_38);
        return -0x16;
      }
      iVar2 = gatt_req_send(conn,func,params,encode,uVar3,len,in_stack_ffffffd8);
      return iVar2;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(params->start_handle <= params->end_handle)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",4499);
    _ASSERT("\tinvalid parameters\n\n",test_02,file_02,line_02);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


