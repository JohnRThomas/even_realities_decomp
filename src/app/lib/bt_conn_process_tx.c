/*
 * Function: bt_conn_process_tx
 * Entry:    0005a494
 * Prototype: void __stdcall bt_conn_process_tx(bt_conn * conn)
 */


/* exclude_from_export */

void bt_conn_process_tx(bt_conn *conn)

{
  bool bVar1;
  int extraout_r0;
  net_buf *pnVar2;
  int iVar3;
  net_buf *buf;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 extraout_r1_00;
  bool in_r2;
  bt_conn_tx *tx;
  byte bVar5;
  k_timeout_t timeout;
  
  if ((conn->state == 0) &&
     (atomic_set_bit_to((atomic_t *)&conn->flags,-0x41,in_r2), extraout_r0 << 0x19 < 0)) {
    conn_cleanup(conn);
    return;
  }
  pnVar2 = k_fifo_peek_head(&conn->tx_queue);
  if (pnVar2 == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",
            917);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    software_interrupt(2);
  }
  pnVar2 = net_buf_ref(pnVar2);
  bVar5 = *(byte *)&pnVar2[1].node.next;
  uVar4 = extraout_r1;
  if ((DAT_20002104 < (pnVar2->field6_0xc).field0.len) || (bVar5 != 0)) {
    while (DAT_20002104 < (pnVar2->field6_0xc).field0.len) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar4;
      buf = bt_conn_create_frag_timeout(0,timeout);
      if (conn->state != 7) {
        net_buf_unref(buf);
        net_buf_unref(pnVar2);
        return;
      }
      buf->user_data = (uint8_t *)0x0;
      *(undefined1 *)&buf[1].node.next = 0;
      *(undefined1 *)((int)&buf[1].node.next + 1) = *(undefined1 *)((int)&pnVar2[1].node.next + 1);
      iVar3 = do_send_frag(conn,pnVar2,(uint8_t)buf);
      if (iVar3 != 0) {
        *(byte *)&pnVar2[1].node.next = bVar5 & 1;
        net_buf_unref(buf);
        goto LAB_0005a56a;
      }
      bVar5 = 1;
      uVar4 = extraout_r1_00;
    }
    *(undefined1 *)&pnVar2[1].node.next = 1;
  }
  iVar3 = do_send_frag(conn,pnVar2,'\0');
LAB_0005a56a:
  net_buf_unref(pnVar2);
  if (iVar3 == -5) {
    tx = (bt_conn_tx *)pnVar2->user_data;
    pnVar2->user_data = (uint8_t *)0x0;
    net_buf_unref(pnVar2);
    if (tx != (bt_conn_tx *)0x0) {
      conn_tx_destroy(conn,tx);
      return;
    }
  }
  return;
}


