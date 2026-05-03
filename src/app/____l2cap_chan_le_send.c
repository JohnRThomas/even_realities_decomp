/*
 * Function: $_?_l2cap_chan_le_send
 * Entry:    0005a828
 * Prototype: int __stdcall $_?_l2cap_chan_le_send(bt_l2cap_le_chan * ch, net_buf * buf, uint16_t sdu_hdr_len)
 */


int ____l2cap_chan_le_send(bt_l2cap_le_chan *ch,net_buf *buf,uint16_t sdu_hdr_len)

{
  ushort uVar1;
  ushort uVar2;
  atomic_val_t aVar3;
  size_t sVar4;
  size_t sVar5;
  net_buf *buf_00;
  net_buf_pool *pool;
  net_buf_pool *extraout_r0;
  int iVar6;
  uint extraout_r1;
  uint extraout_r1_00;
  uint *puVar7;
  uint uVar8;
  uint len;
  uint uVar9;
  code *pcVar10;
  atomic_t *target;
  net_buf_simple *buf_01;
  net_buf_simple *buf_02;
  k_timeout_t timeout;
  
  uVar8 = (uint)sdu_hdr_len;
  target = (atomic_t *)((int)&ch->state + 2);
  do {
    aVar3 = atomic_get(target);
    if (aVar3 == 0) {
      return -0xb;
    }
  } while (*target != aVar3);
  *target = aVar3 + -1;
  buf_01 = (net_buf_simple *)(buf + 0xc);
  sVar4 = net_buf_simple_headroom(buf_01);
  uVar1 = *(ushort *)(buf + 0x10);
  if (((uVar1 + uVar8 <= (uint)*(ushort *)((int)&ch->rx_queue + 2)) &&
      (sVar5 = net_buf_simple_headroom(buf_01), (uVar8 + 9 & 0xffff) <= sVar5)) &&
     (*(int *)(buf + 4) == 0)) {
    if (uVar8 != 0) {
      sVar5 = net_buf_frags_len(buf);
      ____bt_l2cap_send_cb_partial((net_buf *)buf_01,sVar5 & 0xffff);
    }
    buf_00 = net_buf_ref(buf);
    if (buf_00 == (net_buf *)0x0) goto LAB_0005a8a2;
    goto LAB_0005a946;
  }
  pool = net_buf_pool_get((uint)buf[10]._opaque);
  pcVar10 = *(code **)(ch->rx + 0xc);
  uVar9 = extraout_r1;
  if (pcVar10 == (code *)0x0) {
LAB_0005a8e2:
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = uVar9;
    buf_00 = net_buf_alloc(pool,timeout);
    if (buf_00 != (net_buf *)0x0) goto LAB_0005a8f0;
    buf_00 = bt_conn_create_pdu_timeout((net_buf_pool *)0x0,4,(k_timeout_t)0x0);
    if (buf_00 == (net_buf *)0x0) {
LAB_0005a8a2:
      *target = *target + 1;
      return -0xb;
    }
  }
  else {
    buf_00 = (net_buf *)(*pcVar10)(ch);
    if (buf_00 == (net_buf *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","seg",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",1805);
      k_panic();
      pool = extraout_r0;
      uVar9 = extraout_r1_00;
      goto LAB_0005a8e2;
    }
LAB_0005a8f0:
    net_buf_reserve(buf_00 + 0xc,9);
  }
  buf_02 = (net_buf_simple *)(buf_00 + 0xc);
  if (uVar8 != 0) {
    sVar5 = net_buf_frags_len(buf);
    FUN_00086f1e((net_buf *)buf_02,sVar5 & 0xffff);
  }
  sVar5 = net_buf_simple_tailroom(buf_02);
  uVar9 = *(ushort *)((int)&ch->rx_queue + 2) - uVar8;
  if (sVar5 < uVar9) {
    uVar9 = net_buf_simple_tailroom(buf_02);
  }
  len = (uint)*(ushort *)(buf + 0x10);
  if ((uVar9 & 0xffff) <= (uint)*(ushort *)(buf + 0x10)) {
    len = uVar9 & 0xffff;
  }
  net_buf_add_mem((net_buf *)buf_02,*(void **)(buf + 0xc),len);
  net_buf_simple_pull_le16(buf_01);
LAB_0005a946:
  uVar2 = *(ushort *)(buf_00 + 0x10);
  if ((buf == buf_00) || (*(short *)(buf + 0x10) == 0)) {
    pcVar10 = (code *)0x8522f;
  }
  else {
    pcVar10 = (code *)0x85219;
  }
  iVar6 = bt_l2cap_send_cb((bt_conn *)ch->chan,*(uint16_t *)((int)&ch->rx_work + 2),buf_00,pcVar10,
                           *(void **)(buf + 0x18));
  if (iVar6 != 0) {
    *target = *target + 1;
    net_buf_unref(buf_00);
    if (iVar6 == -0x69) {
      *(ushort *)(buf + 0x10) = uVar1;
      *(size_t *)(buf + 0xc) = *(int *)(buf + 0x14) + (sVar4 & 0xffff);
      return -0xb;
    }
    return iVar6;
  }
  aVar3 = atomic_get(target);
  if (aVar3 == 0) {
    puVar7 = (uint *)((int)&ch->tx_queue + 2);
    *puVar7 = *puVar7 & 0xfffffffe;
    pcVar10 = *(code **)(ch->rx + 0x1c);
    if (pcVar10 != (code *)0x0) {
      (*pcVar10)(ch);
    }
  }
  return uVar2 - uVar8;
}


