/*
 * Function: bt_conn_set_state
 * Entry:    000599b0
 * Prototype: void __stdcall bt_conn_set_state(bt_conn * conn, bt_conn_state_t state)
 */


/* exclude_from_export */

void bt_conn_set_state(bt_conn *conn,bt_conn_state_t state)

{
  bool bVar1;
  uint uVar2;
  k_sem *sem;
  k_spinlock_key_t kVar3;
  undefined4 uVar4;
  undefined4 extraout_r1;
  bt_conn_tx *tx;
  sys_snode_t *psVar5;
  undefined1 *puVar6;
  char *pcVar7;
  k_timeout_t delay;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined1 *local_28;
  char *local_24;
  char *pcStack_20;
  undefined2 local_1c;
  
  pcVar7 = (char *)(uint)conn->state;
  if (pcVar7 == (char *)(uint)state) {
    if (pcVar7 < (char *)0x9) {
      pcStack_20 = (&PTR_s_disconnected_000bf655_0xa_0008edb0)[(int)pcVar7];
    }
    else {
      pcStack_20 = "(unknown)";
    }
    local_24 = "no transition %s";
    uVar4 = 0x1c80;
    local_1c = 0x200;
    puVar6 = &DAT_01000003;
    local_28 = &DAT_01000003;
LAB_000599ea:
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,uVar4,&local_28,puVar6,in_stack_ffffffc8,in_stack_ffffffcc,
            in_stack_ffffffd0);
  }
  else {
    conn->state = state;
    if ((pcVar7 == (char *)0x0) && (conn->type != BT_CONN_TYPE_ISO)) {
      bt_conn_ref(conn);
    }
    switch(conn->state) {
    case 0:
      if (conn->type == BT_CONN_TYPE_SCO) goto switchD_00059ab0_caseD_3;
      switch(pcVar7) {
      case (char *)0x0:
      case (char *)0x7:
      case (char *)0x8:
        local_24 = "Invalid (%u) old state";
        goto LAB_00059b2c;
      case (char *)0x1:
        tx_notify(conn);
        if (conn->type == BT_CONN_TYPE_LE) {
          kVar3 = k_spin_lock((k_spinlock *)&conn->deferred_work);
          if ((kVar3 & 0xc) != 0) {
            k_work_cancel_delayable(&conn->deferred_work);
          }
        }
        conn->flags = conn->flags | BT_CONN_CLEANUP;
        k_poll_signal_raise(&conn_change,0);
        break;
      case (char *)0x2:
      case (char *)0x5:
      case (char *)0x6:
        if (conn->err != '\0') {
          notify_connected(conn);
        }
      case (char *)0x3:
      case (char *)0x4:
switchD_00059ab0_caseD_3:
        bt_conn_unref(conn);
      }
      break;
    case 1:
      do {
        uVar4 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar4 = getBasePriority();
        }
        bVar1 = (bool)isCurrentModePrivileged();
        if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
          setBasePriority(0x20);
        }
        InstructionSynchronizationBarrier(0xf);
        if (conn->pending_no_cb == 0) {
          tx = (bt_conn_tx *)conn->tx_pending;
          if (tx == (bt_conn_tx *)0x0) {
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              setBasePriority(uVar4);
            }
            InstructionSynchronizationBarrier(0xf);
            return;
          }
          psVar5 = (tx->node).next;
          if (tx == *(bt_conn_tx **)&conn->field_0x18) {
            *(sys_snode_t **)&conn->field_0x18 = psVar5;
          }
          conn->tx_pending = psVar5;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar4);
          }
          InstructionSynchronizationBarrier(0xf);
          uVar4 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            uVar4 = getBasePriority();
          }
          bVar1 = (bool)isCurrentModePrivileged();
          if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
            setBasePriority(0x20);
          }
          InstructionSynchronizationBarrier(0xf);
          conn->pending_no_cb = tx->pending_no_cb;
          tx->pending_no_cb = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar4);
          }
          InstructionSynchronizationBarrier(0xf);
          conn_tx_destroy(conn,tx);
        }
        else {
          conn->pending_no_cb = conn->pending_no_cb - 1;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar4);
          }
          InstructionSynchronizationBarrier(0xf);
        }
        sem = (k_sem *)&DAT_20002108;
        if (DAT_20002104 == 0) {
          sem = (k_sem *)0x0;
        }
        k_sem_give(sem);
      } while( true );
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
      break;
    case 7:
      if (conn->type != BT_CONN_TYPE_SCO) {
        k_queue_init(&(conn->tx_queue)._queue);
        k_poll_signal_raise(&conn_change,0);
        conn->channels = 0;
        *(undefined4 *)&conn->field_0x58 = 0;
        if (conn->role == '\x01') {
          if (conn->type == BT_CONN_TYPE_LE) {
            (conn->le).conn_param_retry_countdown = '\x03';
          }
          delay.ticks._4_4_ = 0x28000;
          delay.ticks._0_4_ = extraout_r1;
          k_work_schedule(&conn->deferred_work,delay);
        }
      }
      break;
    default:
      local_24 = "no valid (%u) state was set";
LAB_00059b2c:
      puVar6 = (undefined1 *)0x3;
      uVar4 = 0x1880;
      local_28 = (undefined1 *)0x3;
      pcStack_20 = (char *)(uint)state;
      goto LAB_000599ea;
    }
  }
  return;
}


