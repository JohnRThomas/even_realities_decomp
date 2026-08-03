/*
 * Function: deferred_work
 * Entry:    0005a34c
 * Prototype: void __stdcall deferred_work(k_work * work)
 */


/* WARNING: Removing unreachable block (ram,0x0005a450) */
/* WARNING: Removing unreachable block (ram,0x0005a40a) */
/* exclude_from_export */

void deferred_work(k_work *work)

{
  int extraout_r0;
  char *test;
  bool in_r2;
  bool val;
  char *file;
  int line;
  undefined **ppuVar1;
  int iVar2;
  k_work_handler_t **target;
  bt_conn *conn;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  int iStack_28;
  void *local_20;
  sys_snode_t *local_1c;
  
  conn = (bt_conn *)(work + -6);
  if (*(char *)((int)&work[-6].flags + 1) == '\0') {
    bt_l2cap_disconnected(conn);
    for (iVar2 = DAT_2000b6fc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
      if (*(code **)(iVar2 + 4) != (code *)0x0) {
        (**(code **)(iVar2 + 4))(conn,(char)work[-6].flags);
      }
    }
    ppuVar1 = &PTR_ancs_connected_1_0008b79c;
    while( true ) {
      if (&DAT_0008b808 < ppuVar1) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1532);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)0x8b807 < ppuVar1) break;
      if ((code *)ppuVar1[1] != (code *)0x0) {
        (*(code *)ppuVar1[1])(conn,(char)work[-6].flags);
      }
      ppuVar1 = ppuVar1 + 9;
    }
    bt_conn_unref(conn);
    return;
  }
  if (*(char *)((int)&work[-6].node.next + 2) != '\x01') {
    return;
  }
  target = &work[-6].handler;
  atomic_set_bit_to((atomic_t *)target,-0x201,in_r2);
  if (extraout_r0 << 0x16 < 0) {
    local_20 = work[4].queue;
    local_1c = work[5].node.next;
    iStack_28 = send_conn_le_param_update(conn,(bt_le_conn_param *)&local_20);
    if (iStack_28 == 0) {
      atomic_set_bit_to((atomic_t *)target,-0x101,val);
      goto LAB_0005a3fa;
    }
    local_2c = "Send LE param update failed (err %d)";
  }
  else {
    local_20 = (void *)0x280018;
    local_1c = (sys_snode_t *)0x2a0000;
    iStack_28 = send_conn_le_param_update(conn,(bt_le_conn_param *)&local_20);
    if (iStack_28 == 0) {
      *target = (k_work_handler_t *)((uint)*target | 0x100);
      goto LAB_0005a3fa;
    }
    local_2c = "Send auto LE param update failed (err %d)";
  }
  local_30 = 3;
  LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1880,&local_30,3,in_stack_ffffffc0,in_stack_ffffffc4,
          in_stack_ffffffc8);
LAB_0005a3fa:
  *target = (k_work_handler_t *)((uint)*target | 0x80);
  return;
}


