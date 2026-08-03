/*
 * Function: do_send_frag
 * Entry:    00059378
 * Prototype: int __stdcall do_send_frag(bt_conn * conn, net_buf * buf, uint8_t flags)
 */


/* exclude_from_export */

int do_send_frag(bt_conn *conn,net_buf *buf,uint8_t flags)

{
  bool bVar1;
  ushort uVar2;
  k_sem *pkVar3;
  int iVar4;
  size_t sVar5;
  ushort *puVar6;
  net_buf *buf_00;
  uint extraout_r1;
  undefined4 uVar7;
  ushort in_r3;
  uint uVar8;
  bt_conn_tx *tx;
  uint *unaff_r10;
  net_buf_union *buf_01;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  int iStack_38;
  uint local_2c;
  
  buf_00 = (net_buf *)(uint)flags;
  pkVar3 = (k_sem *)&DAT_20002108;
  if (DAT_20002104 == 0) {
    pkVar3 = (k_sem *)0x0;
  }
  timeout.ticks._4_4_ = 0;
  timeout.ticks._0_4_ = buf;
  iVar4 = z_impl_k_sem_take(pkVar3,timeout);
  if (iVar4 == 0) {
    if (buf_00 == (net_buf *)0x0) {
      timeout_00.ticks._4_4_ = 0;
      timeout_00.ticks._0_4_ = extraout_r1;
      buf_00 = net_buf_get(&conn->tx_queue,timeout_00);
    }
    else {
      local_2c = (uint)DAT_20002104;
      buf_01 = &buf_00->field6_0xc;
      sVar5 = net_buf_simple_tailroom(&buf_01->b);
      uVar2 = DAT_20002104;
      if (sVar5 <= local_2c) {
        sVar5 = net_buf_simple_tailroom(&buf_01->b);
        uVar2 = (ushort)sVar5;
      }
      local_2c = (uint)uVar2;
      net_buf_add_mem((net_buf *)&buf_01->field0,(buf->field6_0xc).field0.data,local_2c);
      net_buf_simple_pull(&(buf->field6_0xc).b);
    }
    tx = (bt_conn_tx *)buf_00->user_data;
    if (conn->state == 7) {
      uVar7 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar7 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      if (tx == (bt_conn_tx *)0x0) {
        iVar4 = *(int *)&conn->field_0x18;
        if (iVar4 == 0) {
          uVar8 = conn->pending_no_cb;
          unaff_r10 = &conn->pending_no_cb;
        }
        else {
          unaff_r10 = (uint *)(iVar4 + 0xc);
          uVar8 = *(uint *)(iVar4 + 0xc);
        }
        *unaff_r10 = uVar8 + 1;
      }
      else {
        (tx->node).next = (sys_snode_t *)0x0;
        if (*(undefined4 **)&conn->field_0x18 == (undefined4 *)0x0) {
          conn->tx_pending = tx;
          *(bt_conn_tx **)&conn->field_0x18 = tx;
        }
        else {
          **(undefined4 **)&conn->field_0x18 = tx;
          *(bt_conn_tx **)&conn->field_0x18 = tx;
        }
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar7);
      }
      InstructionSynchronizationBarrier(0xf);
      puVar6 = net_buf_push((net_buf *)&(buf_00->field6_0xc).field0,4);
      *puVar6 = conn->handle | (in_r3 & 0xfd) << 0xc;
      puVar6[1] = (buf_00->field6_0xc).field0.len - 4;
      *(undefined1 *)&buf_00->user_data = 2;
      iStack_38 = bt_send(buf_00);
      if (iStack_38 == 0) {
        return 0;
      }
      local_3c = "Unable to send to driver (err %d)";
      local_40 = 3;
      LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1840,&local_40,3,in_stack_ffffffb0,in_stack_ffffffb4,
              in_stack_ffffffb8);
      uVar7 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar7 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      if (tx == (bt_conn_tx *)0x0) {
        if (*unaff_r10 == 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","*pending_no_cb > 0",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",627);
                    /* WARNING: Subroutine does not return */
          k_panic();
        }
        *unaff_r10 = *unaff_r10 - 1;
      }
      else {
        sys_slist_find_and_remove((sys_slist_t *)&conn->tx_pending,(sys_snode_t *)tx);
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar7);
      }
      InstructionSynchronizationBarrier(0xf);
      iVar4 = -5;
    }
    else {
      iVar4 = -0x80;
    }
    pkVar3 = (k_sem *)&DAT_20002108;
    if (DAT_20002104 == 0) {
      pkVar3 = (k_sem *)0x0;
    }
    k_sem_give(pkVar3);
    if (tx != (bt_conn_tx *)0x0) {
      buf_00->user_data = (uint8_t *)0x0;
      conn_tx_destroy(conn,tx);
    }
  }
  else {
    iVar4 = -0x69;
  }
  return iVar4;
}


