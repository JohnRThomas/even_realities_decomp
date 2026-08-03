/*
 * Function: bt_att_chan_create_pdu
 * Entry:    0005b89c
 * Prototype: net_buf * __stdcall bt_att_chan_create_pdu(bt_att_chan * chan, uint8_t op, size_t len)
 */


/* exclude_from_export_ai */

net_buf * bt_att_chan_create_pdu(bt_att_chan *chan,uint8_t op,size_t len)

{
  att_type_t aVar1;
  net_buf *buf;
  uint8_t *puVar2;
  k_tid_t puVar3;
  net_buf *pnVar4;
  bt_att_chan *pbVar5;
  uint uVar6;
  undefined4 extraout_r1;
  bt_att_chan *pbVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  byte local_48 [4];
  char *local_44;
  bt_att_chan *pbStack_40;
  bt_att_chan *local_3c;
  byte local_28 [4];
  char *local_24;
  
  pbVar5 = (bt_att_chan *)(uint)op;
  pbVar7 = (bt_att_chan *)(uint)*(ushort *)((int)&chan->timeout_work + 2);
  pbStack_40 = (bt_att_chan *)(uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
  if (pbVar7 <= pbStack_40) {
    pbStack_40 = pbVar7;
  }
  if (pbStack_40 < (bt_att_chan *)(len + 1)) {
    local_44 = "ATT MTU exceeded, max %u, wanted %zu";
    uVar6 = 0x2080;
    local_48[0] = 4;
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_3c = (bt_att_chan *)(len + 1);
    goto LAB_0005b8d0;
  }
  aVar1 = att_op_get_type(op);
  if (aVar1 == 2) {
    if ((pbVar5 == (bt_att_chan *)&DAT_0000000f) || (pbVar5 == (bt_att_chan *)&DAT_00000021))
    goto LAB_0005b98e;
    if (chan[9].chan == 0) {
      pnVar4 = (net_buf *)&chan[9].chan;
      if ((net_buf *)chan[9].att == (net_buf *)0x0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan->rsp_buf",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",717);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      buf = net_buf_ref((net_buf *)chan[9].att);
      net_buf_reset(buf);
      net_buf_reserve((net_buf *)&(buf->field6_0xc).field0,9);
      goto LAB_0005b97a;
    }
    local_44 = "already processing a REQ/RSP on chan %p";
    pbStack_40 = chan;
  }
  else {
    if (aVar1 == 4) {
LAB_0005b98e:
      uVar8 = 0xf0000;
      uVar9 = 0;
    }
    else {
      uVar8 = 0xffffffff;
      uVar9 = 0xffffffff;
    }
    timeout_00.ticks._4_4_ = uVar9;
    timeout_00.ticks._0_4_ = uVar8;
    buf = bt_l2cap_create_pdu_timeout((net_buf_pool *)0x0,0,timeout_00);
    if (buf != (net_buf *)0x0) {
      puVar3 = k_current_get();
      if (puVar3 == &k_sys_work_q) {
        uVar8 = 0;
      }
      timeout.ticks._4_4_ = uVar8;
      timeout.ticks._0_4_ = extraout_r1;
      pnVar4 = k_fifo_get(&gatt_prep_queue,timeout);
      if (pnVar4 == (net_buf *)0x0) {
        local_24 = "Unable to allocate ATT TX meta";
        local_28[0] = 2;
        local_28[1] = 0;
        local_28[2] = 0;
        local_28[3] = 0;
        LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1080,local_28);
        net_buf_unref(buf);
        return (net_buf *)0x0;
      }
LAB_0005b97a:
      (pnVar4->node).next = (sys_snode_t *)chan;
      buf->user_data = (uint8_t *)pnVar4;
      puVar2 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,1);
      *puVar2 = op;
      return buf;
    }
    local_44 = "Unable to allocate buffer for op 0x%02x";
    pbStack_40 = pbVar5;
  }
  uVar6 = 0x1840;
  local_48[0] = 3;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
LAB_0005b8d0:
  LOG_WRN(&PTR_s_bt_att_0008b8b0,uVar6,local_48);
  return (net_buf *)0x0;
}


