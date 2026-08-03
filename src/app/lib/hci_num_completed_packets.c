/*
 * Function: hci_num_completed_packets
 * Entry:    00056d30
 * Prototype: void __stdcall hci_num_completed_packets(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_num_completed_packets(net_buf *buf)

{
  ushort handle;
  short sVar1;
  bool bVar2;
  bt_conn *conn;
  k_sem *sem;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  dword in_stack_ffffff98;
  uint8_t *in_stack_ffffff9c;
  void *in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  uint local_50;
  char *local_4c;
  uint uStack_48;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  
  pbVar9 = (buf->field6_0xc).field0.data;
  uVar4 = (uint)(buf->field6_0xc).field0.len;
  uVar6 = (uint)*pbVar9 * 4 + 1;
  if (uVar4 < uVar6) {
    local_50 = (uint)*pbVar9;
    local_4c = (char *)uVar6;
    uStack_48 = uVar4;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x2840,&stack0xffffffa8,5,in_stack_ffffff98,
            in_stack_ffffff9c,in_stack_ffffffa0);
  }
  else {
    for (iVar8 = 0; iVar8 < (int)(uint)*pbVar9; iVar8 = iVar8 + 1) {
      handle = *(ushort *)(pbVar9 + iVar8 * 4 + 1);
      sVar1 = *(short *)(pbVar9 + iVar8 * 4 + 3);
      conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_ALL);
      if (conn == (bt_conn *)0x0) {
        local_4c = "No connection for handle %u";
        local_50 = 3;
        uStack_48 = (uint)handle;
        LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_50,3,(dword)in_stack_ffffffa0,
                in_stack_ffffffa4,in_stack_ffffffa8);
      }
      else {
        for (; sVar1 != 0; sVar1 = sVar1 + -1) {
          uVar5 = 0;
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            uVar5 = getBasePriority();
          }
          bVar2 = (bool)isCurrentModePrivileged();
          if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
            setBasePriority(0x20);
          }
          InstructionSynchronizationBarrier(0xf);
          if (conn->pending_no_cb == 0) {
            puVar7 = (undefined4 *)conn->tx_pending;
            if (puVar7 == (undefined4 *)0x0) {
              bVar2 = (bool)isCurrentModePrivileged();
              if (bVar2) {
                setBasePriority(uVar5);
              }
              InstructionSynchronizationBarrier(0xf);
              local_2c = "packets count mismatch";
              local_30 = 2;
              LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_30,2,in_stack_ffffffc0,
                      in_stack_ffffffc4,in_stack_ffffffc8);
              break;
            }
            uVar3 = *puVar7;
            conn->tx_pending = uVar3;
            if (puVar7 == *(undefined4 **)&conn->field_0x18) {
              *(undefined4 *)&conn->field_0x18 = uVar3;
            }
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              setBasePriority(uVar5);
            }
            InstructionSynchronizationBarrier(0xf);
            uVar5 = 0;
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              uVar5 = getBasePriority();
            }
            bVar2 = (bool)isCurrentModePrivileged();
            if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
              setBasePriority(0x20);
            }
            InstructionSynchronizationBarrier(0xf);
            conn->pending_no_cb = puVar7[3];
            puVar7[3] = 0;
            *puVar7 = 0;
            if (*(undefined4 **)&conn->field_0x24 == (undefined4 *)0x0) {
              conn->tx_complete = puVar7;
              *(undefined4 **)&conn->field_0x24 = puVar7;
            }
            else {
              **(undefined4 **)&conn->field_0x24 = puVar7;
              *(undefined4 **)&conn->field_0x24 = puVar7;
            }
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              setBasePriority(uVar5);
            }
            InstructionSynchronizationBarrier(0xf);
            k_work_submit(&conn->tx_complete_work);
          }
          else {
            conn->pending_no_cb = conn->pending_no_cb - 1;
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              setBasePriority(uVar5);
            }
            InstructionSynchronizationBarrier(0xf);
          }
          sem = bt_conn_get_pkts(conn);
          k_sem_give(sem);
        }
        bt_conn_unref(conn);
      }
    }
  }
  return;
}


