/*
 * Function: bt_hci_le_enh_conn_complete
 * Entry:    000571f0
 * Prototype: void __stdcall bt_hci_le_enh_conn_complete(bt_hci_evt_le_enh_conn_complete * evt)
 */


/* exclude_from_export_ai */

void bt_hci_le_enh_conn_complete(bt_hci_evt_le_enh_conn_complete *evt)

{
  uint16_t handle;
  bool bVar1;
  bt_le_ext_adv *pbVar2;
  bt_conn *conn;
  bt_addr_le_t *pbVar3;
  net_buf *buf;
  ushort *puVar4;
  int iVar5;
  bt_addr_le_t *peer_addr;
  bt_addr_le_t *extraout_r1;
  bt_addr_le_t *extraout_r1_00;
  bt_addr_le_t *extraout_r1_01;
  bt_addr_le_t *extraout_r1_02;
  uchar extraout_r2;
  size_t extraout_r2_00;
  size_t extraout_r2_01;
  size_t extraout_r2_02;
  size_t extraout_r2_03;
  size_t len;
  int extraout_r2_04;
  byte bVar6;
  uint uVar7;
  bt_addr_le_t *addr;
  bool bVar8;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  undefined1 *local_50;
  char *local_4c;
  uint uStack_48;
  undefined2 local_44;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_28;
  char *local_24;
  
  handle = evt->handle;
  bVar8 = DAT_200108f4 == (handle | 0xf000);
  if (bVar8) {
    DAT_200108f4 = 0;
  }
  bt_id_pending_keys_update();
  bVar6 = evt->status;
  uVar7 = (uint)bVar6;
  if (uVar7 != 0) {
    if (uVar7 != 0x3c) {
      local_4c = "Unexpected status 0x%02x";
      local_50 = (undefined1 *)0x3;
      uStack_48 = uVar7;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1880,&local_50,3,in_stack_ffffffa0,in_stack_ffffffa4,
              in_stack_ffffffa8);
      return;
    }
    pbVar2 = bt_le_adv_lookup_legacy();
    atomic_and((atomic_t *)&pbVar2->BT_ADV_NUM_FLAGS_,-0x81);
    conn = find_pending_connect('\0',peer_addr);
    if (conn == (bt_conn *)0x0) {
      local_24 = "No pending peripheral connection";
      local_28 = 2;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_28,2,in_stack_ffffffc0,in_stack_ffffffc4,
              in_stack_ffffffc8);
      return;
    }
    conn->err = bVar6;
    bt_conn_set_state(conn,0);
    goto LAB_0005725c;
  }
  addr = &evt->peer_addr;
  if (evt->role == 1) {
    bVar6 = DAT_2000206f;
  }
  bVar1 = bt_addr_le_is_resolved(addr);
  if (bVar1) {
    bt_addr_le_copy_resolved((bt_addr_le_t *)&stack0xffffffc8,addr);
    bt_addr_copy((bt_addr_t *)&stack0xffffffc1,&evt->peer_rpa);
    pbVar3 = extraout_r1;
    len = extraout_r2_00;
  }
  else {
    pbVar3 = bt_lookup_id_addr(bVar6,addr);
    bt_addr_le_copy((bt_addr_le_t *)&stack0xffffffc8,pbVar3);
    bt_addr_le_copy((bt_addr_le_t *)&stack0xffffffc0,addr);
    pbVar3 = extraout_r1_00;
    len = extraout_r2_01;
  }
  if (evt->role == 1) {
    conn = find_pending_connect((char)&stack0xffffffe8 + 0xe0,pbVar3);
    pbVar3 = extraout_r1_01;
    len = extraout_r2_02;
    if (evt->role == 1) {
      pbVar2 = bt_le_adv_lookup_legacy();
      atomic_and((atomic_t *)&pbVar2->BT_ADV_NUM_FLAGS_,-0x81);
      bt_le_lim_adv_cancel_timeout(pbVar2);
      pbVar3 = extraout_r1_02;
      len = extraout_r2_03;
    }
    if (conn != (bt_conn *)0x0) {
      conn->handle = evt->handle;
      bt_addr_le_copy(&(conn->le).dst,(bt_addr_le_t *)&stack0xffffffc8);
      (conn->le).interval = evt->interval;
      (conn->le).latency = evt->latency;
      (conn->le).timeout = evt->supv_timeout;
      bVar6 = evt->role;
      conn->err = extraout_r2;
      *(undefined1 **)&(conn->le).phy = &DAT_001b0101;
      (conn->rv).version = 'H';
      (conn->rv)._pad = '\x01';
      (conn->rv).manufacturer = 0x1b;
      conn->role = bVar6;
      (conn->rv).subversion = 0x148;
      if (bVar6 == 1) {
        bt_addr_le_copy(&(conn->le).init_addr,(bt_addr_le_t *)&stack0xffffffc0);
        bt_le_adv_lookup_legacy();
        bt_addr_le_copy(&(conn->le).resp_addr,(bt_addr_le_t *)((int)&bt_dev + (uint)conn->id * 7));
        if (*(int *)(extraout_r2_04 + 0xe4) << 0x19 < 0) {
          bt_le_adv_resume();
        }
      }
      bt_conn_set_state(conn,7);
      if (bVar8) {
        bt_conn_set_state(conn,1);
      }
      bt_conn_connected(conn);
      if (((conn->state == 7) && (-1 < (int)(conn->flags << 0x12))) &&
         ((conn->role == '\0' || ((int)((uint)(byte)DAT_200020d8 << 0x1c) < 0)))) {
        buf = bt_hci_cmd_create(0x2016,'\x02');
        if (buf == (net_buf *)0x0) {
          iVar5 = -0x69;
        }
        else {
          puVar4 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,2);
          *puVar4 = conn->handle;
          iVar5 = bt_hci_cmd_send_sync(0x2016,buf,(net_buf **)0x0);
          if (iVar5 == 0) goto LAB_0005725c;
        }
        local_4c = "Failed read remote features (%d)";
        local_50 = (undefined1 *)0x3;
        uStack_48 = iVar5;
        LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_50,3,in_stack_ffffffa0,in_stack_ffffffa4,
                in_stack_ffffffa8);
      }
LAB_0005725c:
      bt_conn_unref(conn);
      return;
    }
  }
  uStack_48 = bt_addr_le_to_str(addr,(char *)pbVar3,len);
  local_4c = "No pending conn for peer %s";
  local_44 = 0x200;
  local_50 = &DAT_01000003;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1c40,&local_50,&DAT_01000003,in_stack_ffffffa0,
          in_stack_ffffffa4,in_stack_ffffffa8);
  bt_hci_disconnect(handle,'\x13');
  return;
}


