/*
 * Function: bt_le_adv_start_legacy
 * Entry:    000589e0
 * Prototype: int __stdcall bt_le_adv_start_legacy(bt_le_ext_adv * adv, bt_le_adv_param * param, bt_data * ad, size_t ad_len, bt_data * sd, size_t sd_len)
 */


/* exclude_from_export */

int bt_le_adv_start_legacy
              (bt_le_ext_adv *adv,bt_le_adv_param *param,bt_data *ad,size_t ad_len,bt_data *sd,
              size_t sd_len)

{
  log_msg_desc desc;
  bt_conn *conn;
  bool bVar1;
  byte bVar2;
  bt_le_ext_adv *pbVar3;
  bt_le_ext_adv *pbVar4;
  int iVar5;
  net_buf *buf;
  bt_le_adv_param *param_00;
  int bit;
  bt_data *ad_00;
  undefined1 uVar7;
  dword dVar8;
  bool val;
  dword *target;
  undefined *puVar9;
  dword in_stack_ffffff90;
  bt_le_ext_adv *in_stack_ffffff94;
  undefined1 *in_stack_ffffff98;
  adv_name_type in_stack_ffffff9c;
  bt_conn *local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c [4];
  undefined3 uStack_48;
  undefined1 local_45;
  undefined1 uStack_44;
  uint8_t uStack_43;
  undefined1 uStack_42;
  undefined4 local_30;
  char *local_2c;
  undefined1 *puVar6;
  
  puVar9 = param->peer;
  local_54 = (bt_conn *)0x0;
  pbVar3 = bt_le_adv_lookup_legacy();
  if (-1 < (int)pbVar3 << 0x1d) {
    return -0xb;
  }
  bVar1 = valid_adv_ext_param(param_00);
  if ((!bVar1) || (pbVar3 = bt_le_adv_lookup_legacy(), pbVar3 == (bt_le_ext_adv *)0x0)) {
    return -0x16;
  }
  target = &adv->BT_ADV_NUM_FLAGS_;
  pbVar4 = bt_le_adv_lookup_legacy();
  local_4c = (undefined1  [4])(((uint)pbVar4 & 0xff) >> 7);
  if ((int)pbVar4 << 0x18 < 0) {
    return -0x78;
  }
  uStack_48 = SUB43(local_4c,0);
  local_45 = SUB41(local_4c,0);
  uStack_44 = 0;
  uStack_43 = 0;
  uStack_42 = 0;
  local_50 = (undefined2)param_00->interval_min;
  local_4e = (undefined2)param_00->interval_max;
  uStack_43 = get_adv_channel_map(param_00->options);
  atomic_set_bit(&DAT_200020d4,bit);
  DAT_2000206f = param_00->id;
  adv->id = DAT_2000206f;
  iVar5 = bt_id_set_adv_own_addr(adv,param_00->options,puVar9 != (undefined *)0x0,local_4c + 1);
  if (iVar5 != 0) {
    return iVar5;
  }
  if (puVar9 == (undefined *)0x0) {
    bt_addr_le_copy(&adv->target_addr,(bt_addr_le_t *)&DAT_000f0b50);
    bVar2 = get_adv_type((uint8_t)param_00);
    puVar6 = (undefined1 *)(uint)bVar2;
    dVar8 = param_00->options;
    if (-1 < (int)(dVar8 << 0x1f)) goto LAB_00058aa2;
    local_4c = (undefined1  [4])((uint)local_4c & 0xffffff00);
  }
  else {
    bt_addr_le_copy(&adv->target_addr,(bt_addr_le_t *)param_00->peer);
    bVar2 = get_adv_type((uint8_t)param_00);
    puVar6 = (undefined1 *)(uint)bVar2;
    dVar8 = param_00->options;
    if ((int)(dVar8 << 0x1f) < 0) {
      if ((dVar8 & 0x10) == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 4;
      }
      local_4c[0] = uVar7;
      bt_addr_le_copy((bt_addr_le_t *)(local_4c + 2),(bt_addr_le_t *)param_00->peer);
      pbVar3 = (bt_le_ext_adv *)0x0;
    }
    else {
LAB_00058aa2:
      if ((((int)(dVar8 << 0x16) < 0) || (sd != (bt_data *)0x0)) || (puVar6 == &DAT_00000002)) {
        local_4c[0] = 2;
      }
      else {
        local_4c[0] = 3;
        pbVar3 = (bt_le_ext_adv *)0x0;
      }
    }
  }
  buf = bt_hci_cmd_create(0x2006,'\x0f');
  if (buf == (net_buf *)0x0) {
    return -0x69;
  }
  net_buf_add_mem((net_buf *)&(buf->field6_0xc).field0,&local_50,0xf);
  iVar5 = bt_hci_cmd_send_sync(0x2006,buf,(net_buf **)0x0);
  if (iVar5 != 0) {
    return iVar5;
  }
  bVar1 = SUB41(pbVar3,0);
  if ((puVar9 == (undefined *)0x0) &&
     (in_stack_ffffff98 = puVar6,
     iVar5 = le_adv_update(adv,ad_00,ad_len,sd,sd_len,bVar1,SUB41(puVar6,0),in_stack_ffffff9c),
     in_stack_ffffff90 = sd_len, in_stack_ffffff94 = pbVar3, iVar5 != 0)) {
    return iVar5;
  }
  if (((int)(param_00->options << 0x1f) < 0) &&
     (iVar5 = le_adv_start_add_conn(adv,&local_54), iVar5 != 0)) {
    if (iVar5 != -0xc) {
      return iVar5;
    }
    if (puVar9 != (undefined *)0x0) {
      return -0xc;
    }
    if ((int)(param_00->options << 0x1e) < 0) {
      return -0xc;
    }
  }
  else {
    iVar5 = bt_le_adv_set_enable_legacy(adv,true);
    if (iVar5 != 0) {
      local_2c = "Failed to start advertiser";
      local_30 = 2;
      desc.level = (dword)&local_30;
      desc.domain = 0x1040;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffff90;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_adv_0008b8a8,desc,&in_stack_ffffff94->id,in_stack_ffffff98);
      conn = local_54;
      if (local_54 == (bt_conn *)0x0) {
        return iVar5;
      }
      bt_conn_set_state(local_54,0);
      bt_conn_unref(conn);
      return iVar5;
    }
    if (local_54 != (bt_conn *)0x0) {
      bt_conn_unref(local_54);
    }
    val = false;
    if (puVar9 != (undefined *)0x0) goto LAB_00058bba;
  }
  val = SUB41(((param_00->options ^ 2) & 3) >> 1,0);
LAB_00058bba:
  atomic_set_bit_to((atomic_t *)target,0xe,val);
  atomic_set_bit_to((atomic_t *)target,8,puVar6 == &DAT_00000001);
  atomic_set_bit_to((atomic_t *)target,9,puVar6 == &DAT_00000002);
  atomic_set_bit_to((atomic_t *)target,10,(bool)((byte)param_00->options & 1));
  atomic_set_bit_to((atomic_t *)target,0xb,bVar1);
  atomic_set_bit_to((atomic_t *)target,0xd,SUB41((param_00->options << 0x1d) >> 0x1f,0));
  return 0;
}


