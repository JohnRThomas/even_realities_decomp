/*
 * Function: rx_work_handler
 * Entry:    00056964
 * Prototype: void __stdcall rx_work_handler(k_work * work)
 */


/* exclude_from_export */

void rx_work_handler(k_work *work)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  byte bVar4;
  net_buf *buf;
  ushort *puVar5;
  int iVar6;
  bt_conn *conn;
  byte *pbVar7;
  uint uVar8;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  uint uStack_20;
  uint local_1c;
  
  buf = net_buf_slist_get((sys_slist_t *)&DAT_20002144);
  if (buf == (net_buf *)0x0) {
    return;
  }
  uVar8 = (uint)*(byte *)&buf->user_data;
  if (uVar8 == 1) {
    if ((buf->field6_0xc).field0.len < 2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->len >= sizeof(*hdr)",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",2653);
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(0);
      }
      software_interrupt(2);
    }
    pbVar7 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,2);
    bVar4 = bt_hci_evt_get_flags(*pbVar7);
    if (-1 < (int)((uint)bVar4 << 0x1e)) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","bt_hci_evt_get_flags(hdr->evt) & (1UL << (1))",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",2657);
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(0);
      }
      software_interrupt(2);
    }
    handle_event((dtls_context_t *)(uint)*pbVar7,(session_t *)buf,0x8ed20,6);
  }
  else {
    if (uVar8 == 3) {
      if ((buf->field6_0xc).field0.len < 4) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->len >= sizeof(*hdr)",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",512);
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          setBasePriority(0);
        }
        software_interrupt(2);
      }
      puVar5 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,4);
      uVar1 = puVar5[1];
      uVar2 = *puVar5;
      iVar6 = net_buf_id(buf);
      *(ushort *)(&DAT_200108f6 + iVar6 * 2) = (ushort)(((uint)uVar2 << 0x14) >> 0x14);
      uVar8 = (uint)(buf->field6_0xc).field0.len;
      if (uVar1 != uVar8) {
        local_24 = "ACL data length mismatch (%u != %u)";
        local_28 = 4;
        uStack_20 = uVar8;
        local_1c = (uint)uVar1;
        LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x2040,&local_28,4,in_stack_ffffffc8,in_stack_ffffffcc,
                in_stack_ffffffd0);
        goto LAB_000569e8;
      }
      iVar6 = net_buf_id(buf);
      conn = bt_conn_lookup_handle(*(uint16_t *)(&DAT_200108f6 + iVar6 * 2),BT_CONN_TYPE_ALL);
      if (conn != (bt_conn *)0x0) {
        bt_conn_recv(conn,buf,(byte)(uVar2 >> 0xc));
        bt_conn_unref(conn);
        goto LAB_00056a3e;
      }
      iVar6 = net_buf_id(buf);
      uVar8 = (uint)*(ushort *)(&DAT_200108f6 + iVar6 * 2);
      local_24 = "Unable to find conn for handle %u";
    }
    else {
      local_24 = "Unknown buf type %u";
    }
    local_28 = 3;
    uStack_20 = uVar8;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
  }
LAB_000569e8:
  net_buf_unref(buf);
LAB_00056a3e:
  if ((DAT_20002144 != 0) &&
     (uStack_20 = k_work_submit_to_queue((k_work_q *)&DAT_200060e8,(k_work *)&DAT_200029a0),
     (int)uStack_20 < 0)) {
    local_24 = "Could not submit rx_work: %d";
    local_28 = 3;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
  }
  return;
}


