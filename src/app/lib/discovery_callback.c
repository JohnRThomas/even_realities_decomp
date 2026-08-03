/*
 * Function: discovery_callback
 * Entry:    00051d18
 * Prototype: uint8_t __stdcall discovery_callback(bt_conn * conn, bt_gatt_attr * attr, bt_gatt_discover_params * params)
 */


/* exclude_from_export */

uint8_t discovery_callback(bt_conn *conn,bt_gatt_attr *attr,bt_gatt_discover_params *params)

{
  byte bVar1;
  bt_gatt_dm_attr *pbVar2;
  int iVar3;
  bt_gatt_service_val *pbVar4;
  bt_gatt_chrc *pbVar5;
  bt_uuid *pbVar6;
  uint err;
  char *test;
  bt_uuid *uuid;
  bt_gatt_attr *extraout_r1;
  bt_uuid *uuid_00;
  char *file;
  size_t additional_len;
  int line;
  bt_gatt_chrc *pbVar7;
  bt_gatt_service_val *pbVar8;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  undefined4 local_50;
  char *local_4c;
  uint uStack_48;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  uint8_t *puVar9;
  void *in_stack_ffffffc8;
  undefined4 local_28;
  char *local_24;
  
  if (bt_gatt_dm_inst.conn != conn) {
    local_24 = "Unexpected conn object. Aborting.";
    local_28 = 2;
    LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1040,&local_28,2,in_stack_ffffffc0,in_stack_ffffffc4,
               in_stack_ffffffc8);
    err = 0xfffffff2;
    goto LAB_00051d46;
  }
  bVar1 = (byte)params->_included;
  if (bVar1 == 3) {
    if (attr == (bt_gatt_attr *)0x0) {
LAB_00051e86:
      discovery_complete((bt_gatt_dm *)conn,attr);
      return '\0';
    }
    iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&stack0xffffffc8);
    if (iVar3 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) ((struct bt_uuid_16[]) {{ .uuid = { BT_UUID_TYPE_16 }, .val = (0x2803), }}))) == 0"
              ,"WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",0x19c);
      goto LAB_00051e1e;
    }
    pbVar2 = attr_find_by_handle(&bt_gatt_dm_inst,attr->handle);
    if (pbVar2 == (bt_gatt_dm_attr *)0x0) {
      err = 0xfffffffd;
      goto LAB_00051d46;
    }
    pbVar7 = (bt_gatt_chrc *)attr->user_data;
    pbVar5 = bt_gatt_dm_attr_chrc_val(pbVar2);
    if (pbVar5 == (bt_gatt_chrc *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cur_gatt_chrc != ((void *)0)",
              "WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",0x1a8);
      goto LAB_00051e1e;
    }
    *pbVar5 = *pbVar7;
    pbVar5[1] = pbVar7[1];
    pbVar6 = uuid_store((bt_gatt_dm *)*pbVar5,uuid_00);
    *pbVar5 = (bt_gatt_chrc)pbVar6;
    if (pbVar6 != (bt_uuid *)0x0) {
      return '\x01';
    }
LAB_00051f20:
    err = 0xfffffff4;
LAB_00051d46:
    discovery_complete_error(&bt_gatt_dm_inst,err);
    return '\0';
  }
  if (bVar1 < 4) {
    if (bVar1 != 2) {
      if (attr == (bt_gatt_attr *)0x0) {
        discovery_complete_not_found(&bt_gatt_dm_inst);
        return '\0';
      }
      pbVar8 = (bt_gatt_service_val *)attr->user_data;
      pbVar2 = attr_store((bt_gatt_dm *)attr,(bt_gatt_attr *)&NMI,(size_t)params);
      puVar9 = (uint8_t *)CONCAT22(0x2800,(ushort)in_stack_ffffffc4 & 0xff00);
      iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&stack0xffffffc4);
      if (iVar3 != 0) {
        in_stack_ffffffc8 = (void *)CONCAT22(0x2801,(ushort)in_stack_ffffffc8 & 0xff00);
        iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&stack0xffffffc8);
        if (iVar3 != 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                  "bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) ((struct bt_uuid_16[]) {{ .uuid = { BT_UUID_TYPE_16 }, .val = (0x2800), }}))) == 0 || bt_uuid_cmp(attr->uuid, ((struct bt_uuid *) ((struct bt_uuid_16[]) {{ .uuid = { BT_UUID_TYPE_16 }, .val = (0x2801), }}))) == 0"
                  ,"WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",295);
          goto LAB_00051e1e;
        }
      }
      if (pbVar2 == (bt_gatt_dm_attr *)0x0) {
        local_24 = "Not enough memory for service attribute.";
LAB_00051e28:
        local_28 = 2;
        LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1040,&local_28,2,in_stack_ffffffc0,puVar9,
                   in_stack_ffffffc8);
      }
      else {
        pbVar4 = bt_gatt_dm_attr_service_val(pbVar2);
        if (pbVar4 == (bt_gatt_service_val *)0x0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cur_service_val != ((void *)0)",
                  "WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",315);
          goto LAB_00051e1e;
        }
        *pbVar4 = *pbVar8;
        pbVar4[1] = pbVar8[1];
        conn = (bt_conn *)uuid_store((bt_gatt_dm *)*pbVar4,uuid);
        *pbVar4 = (bt_gatt_service_val)conn;
        if (conn == (bt_conn *)0x0) {
          local_24 = "Not enough memory for service attribute data.";
          goto LAB_00051e28;
        }
        bt_gatt_dm_inst.STATE_NUM_._2_2_ = (short)pbVar4[1];
        attr = extraout_r1;
        if ((short)pbVar2[1] == bt_gatt_dm_inst.STATE_NUM_._2_2_) goto LAB_00051e86;
        bt_gatt_dm_inst.discover_params = 0;
        bt_gatt_dm_inst.uuid._0_1_ = 5;
        bt_gatt_dm_inst.cur_attr_id._0_2_ = (short)pbVar2[1] + 1;
        uStack_48 = bt_gatt_discover(bt_gatt_dm_inst.conn,
                                     (bt_gatt_discover_params *)&bt_gatt_dm_inst.discover_params);
        if (uStack_48 == 0) {
          return '\0';
        }
        local_4c = "Descriptor discover failed, error: %d.";
        local_50 = 3;
        LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1840,&local_50,3,in_stack_ffffffa0,in_stack_ffffffa4
                   ,in_stack_ffffffa8);
      }
      err = 0xfffffff4;
      goto LAB_00051d46;
    }
  }
  else if (bVar1 == 5) {
    if (attr == (bt_gatt_attr *)0x0) {
      if (DAT_2000ac68 < 2) goto LAB_00051e86;
      bt_gatt_dm_inst.cur_attr_id._0_2_ = (short)bt_gatt_dm_inst.u32 + 1;
      bt_gatt_dm_inst.uuid._0_1_ = 3;
      err = bt_gatt_discover(conn,(bt_gatt_discover_params *)&bt_gatt_dm_inst.discover_params);
      if (err == 0) {
        return '\0';
      }
      local_4c = "Characteristic discover failed, error: %d.";
      local_50 = 3;
      uStack_48 = err;
      LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1840,&local_50,
                 "Characteristic discover failed, error: %d.",in_stack_ffffffa0,in_stack_ffffffa4,
                 in_stack_ffffffa8);
      goto LAB_00051d46;
    }
    iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&stack0xffffffc8);
    if (iVar3 == 0) {
      pbVar2 = attr_store((bt_gatt_dm *)attr,(bt_gatt_attr *)&NMI,additional_len);
      pbVar5 = bt_gatt_dm_attr_chrc_val(pbVar2);
      *pbVar5 = *pbVar2;
      return '\x01';
    }
    pbVar2 = attr_store((bt_gatt_dm *)attr,(bt_gatt_attr *)0x0,additional_len);
    if (pbVar2 != (bt_gatt_dm_attr *)0x0) {
      return '\x01';
    }
    uStack_48 = (uint)attr->handle;
    local_4c = "Not enough memory for next attribute descriptor at handle %u.";
    local_50 = 3;
    LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1840,&local_50,3,in_stack_ffffffa0,in_stack_ffffffa4,
               in_stack_ffffffa8);
    goto LAB_00051f20;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",466);
  _ASSERT("\tUnknown param type.\n",test,file,line);
LAB_00051e1e:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


