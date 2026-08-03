/*
 * Function: bt_gatt_dm_start
 * Entry:    0005202c
 * Prototype: int __stdcall bt_gatt_dm_start(bt_conn * conn, bt_uuid * svc_uuid, bt_gatt_dm_cb * cb, void * context)
 */


/* exclude_from_export */

int bt_gatt_dm_start(bt_conn *conn,bt_uuid *svc_uuid,bt_gatt_dm_cb *cb,void *context)

{
  uint uVar1;
  size_t n;
  int iVar2;
  uint uVar3;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  int iStack_20;
  void *pvStack_18;
  
  if (((svc_uuid == (bt_uuid *)0x0) || ((svc_uuid->type & 0xfd) == 0)) &&
     (cb != (bt_gatt_dm_cb *)0x0)) {
    uVar1 = DAT_2000ac6c | 1;
    uVar3 = DAT_2000ac6c & 1;
    DAT_2000ac6c = uVar1;
    if (uVar3 == 0) {
      DAT_2000ac94 = svc_uuid != (bt_uuid *)0x0;
      bt_gatt_dm_inst.conn = conn;
      bt_gatt_dm_inst.context = context;
      DAT_2000ac68 = uVar3;
      DAT_2000ac84 = uVar3;
      DAT_2000ac88 = uVar3;
      DAT_2000ac8c = uVar3;
      bt_gatt_dm_cb_ptr = cb;
      pvStack_18 = context;
      if ((bool)DAT_2000ac94) {
        n = get_uuid_size((bt_uuid *)(uint)svc_uuid->type);
        memcpy(&DAT_2000ac70,svc_uuid,n);
        bt_gatt_dm_inst.discover_params = (dword)&DAT_2000ac70;
      }
      else {
        bt_gatt_dm_inst.discover_params = 0;
      }
      bt_gatt_dm_inst.attrs_CONFIG_BT_GATT_DM_MAX_ATTRS_ = 0x51d19;
      bt_gatt_dm_inst.cur_attr_id._0_2_ = 1;
      bt_gatt_dm_inst.STATE_NUM_._2_2_ = 0xffff;
      bt_gatt_dm_inst.uuid._0_1_ = 0;
      iVar2 = bt_gatt_discover(conn,(bt_gatt_discover_params *)&bt_gatt_dm_inst.discover_params);
      if (iVar2 != 0) {
        local_24 = "Discover failed, error: %d.";
        local_28 = 3;
        iStack_20 = iVar2;
        LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc
                   ,in_stack_ffffffd0);
        atomic_and((atomic_t *)&DAT_2000ac6c,-2);
      }
    }
    else {
      iVar2 = -0x78;
    }
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}


