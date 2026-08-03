/*
 * Function: l2cap_chan_le_send
 * Entry:    0005a828
 * Prototype: int __stdcall l2cap_chan_le_send(bt_l2cap_le_chan * ch, net_buf * buf, uint16_t sdu_hdr_len)
 */


/* exclude_from_export */

int l2cap_chan_le_send(bt_l2cap_le_chan *ch,net_buf *buf,uint16_t sdu_hdr_len)

{
  ushort uVar1;
  ushort uVar2;
  atomic_val_t aVar3;
  size_t sVar4;
  size_t sVar5;
  net_buf *buf_00;
  net_buf_pool *pool;
  int iVar6;
  uint extraout_r1;
  uint *puVar7;
  uint uVar8;
  uint len;
  uint uVar9;
  code *pcVar10;
  atomic_t *target;
  net_buf_union *buf_01;
  net_buf_union *buf_02;
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
  buf_01 = &buf->field6_0xc;
  sVar4 = net_buf_simple_headroom(&buf_01->b);
  uVar1 = (buf->field6_0xc).field0.len;
  if (((uVar1 + uVar8 <= (uint)*(ushort *)((int)&ch->rx_queue + 2)) &&
      (sVar5 = net_buf_simple_headroom(&buf_01->b), (uVar8 + 9 & 0xffff) <= sVar5)) &&
     (buf->frags == (net_buf *)0x0)) {
    if (uVar8 != 0) {
      sVar5 = net_buf_frags_len(buf);
      net_buf_push_le16((net_buf *)&buf_01->field0,sVar5 & 0xffff);
    }
    buf_00 = net_buf_ref(buf);
    if (buf_00 == (net_buf *)0x0) {
LAB_0005a8a2:
      *target = *target + 1;
      return -0xb;
    }
    goto LAB_0005a946;
  }
  pool = net_buf_pool_get((uint)buf->pool_id);
  pcVar10 = *(code **)(ch->rx + 0xc);
  if (pcVar10 == (code *)0x0) {
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = extraout_r1;
    buf_00 = net_buf_alloc(pool,timeout);
    if (buf_00 != (net_buf *)0x0) goto LAB_0005a8f0;
    buf_00 = bt_conn_create_pdu_timeout((net_buf_pool *)0x0,4,(k_timeout_t)0x0);
    if (buf_00 == (net_buf *)0x0) goto LAB_0005a8a2;
  }
  else {
    buf_00 = (net_buf *)(*pcVar10)(ch);
    if (buf_00 == (net_buf *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","seg",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",1805);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
LAB_0005a8f0:
    net_buf_reserve((net_buf *)&(buf_00->field6_0xc).field0,9);
  }
  buf_02 = &buf_00->field6_0xc;
  if (uVar8 != 0) {
    sVar5 = net_buf_frags_len(buf);
    net_buf_simple_add_le16(&buf_02->b,(uint16_t)sVar5);
  }
  sVar5 = net_buf_simple_tailroom(&buf_02->b);
  uVar9 = *(ushort *)((int)&ch->rx_queue + 2) - uVar8;
  if (sVar5 < uVar9) {
    uVar9 = net_buf_simple_tailroom(&buf_02->b);
  }
  len = (uint)(buf->field6_0xc).field0.len;
  if ((uVar9 & 0xffff) <= len) {
    len = uVar9 & 0xffff;
  }
  net_buf_add_mem((net_buf *)&buf_02->field0,(buf->field6_0xc).field0.data,len);
  net_buf_simple_pull(&buf_01->b);
LAB_0005a946:
  uVar2 = (buf_00->field6_0xc).field0.len;
  if ((buf == buf_00) || ((buf->field6_0xc).field0.len == 0)) {
    pcVar10 = (code *)0x8522f;
  }
  else {
    pcVar10 = (code *)0x85219;
  }
  iVar6 = bt_l2cap_send_cb((bt_conn *)ch->chan,*(uint16_t *)((int)&ch->rx_work + 2),buf_00,pcVar10,
                           buf->user_data);
  if (iVar6 != 0) {
    *target = *target + 1;
    net_buf_unref(buf_00);
    if (iVar6 == -0x69) {
      (buf->field6_0xc).field0.len = uVar1;
      (buf->field6_0xc).field0.data = (buf->field6_0xc).field0.__buf + (sVar4 & 0xffff);
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


