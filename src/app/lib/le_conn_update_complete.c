/*
 * Function: le_conn_update_complete
 * Entry:    00056e84
 * Prototype: void __stdcall le_conn_update_complete(int * buf)
 */


/* exclude_from_export_ai */

void le_conn_update_complete(int *buf)

{
  uchar uVar1;
  ushort handle;
  bt_conn *conn;
  atomic_val_t aVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar3;
  char *pcVar4;
  bt_conn_flags *target;
  k_timeout_t delay;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  uint uStack_28;
  bt_le_conn_param local_20;
  
  pcVar4 = (char *)buf[3];
  handle = *(ushort *)(pcVar4 + 1);
  conn = bt_conn_lookup_handle(handle,BT_CONN_TYPE_LE);
  if (conn == (bt_conn *)0x0) {
    local_2c = "Unable to lookup conn for handle %u";
    local_30 = 3;
    uStack_28 = (uint)handle;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_30,3,in_stack_ffffffc0,in_stack_ffffffc4,
            in_stack_ffffffc8);
    return;
  }
  target = &conn->flags;
  uVar3 = extraout_r1;
  if (*pcVar4 == '\x1a') {
    if (conn->role == '\x01') {
      aVar2 = atomic_or((atomic_t *)target,0x400);
      uVar3 = extraout_r1_00;
      if (-1 < aVar2 << 0x15) {
        local_20.interval_min = (conn->le).interval_min;
        local_20.interval_max = (conn->le).interval_max;
        local_20.latency = (conn->le).pending_latency;
        local_20.timeout = (conn->le).pending_timeout;
        bt_l2cap_update_conn_param(conn,&local_20);
        goto LAB_00056ef0;
      }
      goto LAB_00056ef8;
    }
LAB_00056f20:
    if (((-1 < (int)(*target << 0x17)) || (*pcVar4 != ' ')) ||
       (uVar1 = (conn->le).conn_param_retry_countdown, uVar1 == '\0')) goto LAB_00056f14;
    (conn->le).conn_param_retry_countdown = uVar1 + 0xff;
    delay.ticks._4_4_ = 0x28000;
    delay.ticks._0_4_ = uVar3;
    k_work_schedule(&conn->deferred_work,delay);
  }
  else {
LAB_00056ef8:
    if (*pcVar4 != '\0') goto LAB_00056f20;
    (conn->le).interval = *(ushort *)(pcVar4 + 3);
    (conn->le).latency = *(ushort *)(pcVar4 + 5);
    (conn->le).timeout = *(ushort *)(pcVar4 + 7);
LAB_00056f14:
    atomic_and((atomic_t *)target,-0x101);
  }
  notify_le_param_updated(conn);
LAB_00056ef0:
  bt_conn_unref(conn);
  return;
}


