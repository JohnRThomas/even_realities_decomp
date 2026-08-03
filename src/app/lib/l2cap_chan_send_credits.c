/*
 * Function: l2cap_chan_send_credits
 * Entry:    0005a9f8
 * Prototype: void __stdcall l2cap_chan_send_credits(bt_l2cap_le_chan * chan, uint16_t credits)
 */


/* exclude_from_export */

void l2cap_chan_send_credits(bt_l2cap_le_chan *chan,uint16_t credits)

{
  undefined2 uVar1;
  uint8_t code;
  net_buf *pnVar2;
  atomic_val_t aVar3;
  undefined2 *puVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  uint uVar5;
  uint extraout_r1_03;
  uint extraout_r1_04;
  net_buf *buf;
  uint16_t len;
  code *UNRECOVERED_JUMPTABLE;
  uint *extraout_r3;
  uint *puVar6;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  byte local_18 [4];
  char *local_14;
  
  if (*(char *)((int)&chan[2].rtx_sync + 1) == '\x03') {
    code = get_ident();
    pnVar2 = l2cap_create_le_sig_pdu((net_buf *)&DAT_00000016,code,'\x04',len);
    if (pnVar2 == (net_buf *)0x0) {
      local_14 = "Unable to send credits update";
      puVar6 = (uint *)((int)&chan->tx_queue + 2);
      local_18[0] = 2;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1040,local_18);
      *puVar6 = *puVar6 | 2;
      pnVar2 = *(net_buf **)((int)&chan[2].rx + 2);
      uVar5 = extraout_r1;
      if (pnVar2 != (net_buf *)0x0) {
        net_buf_unref(pnVar2);
        *(undefined4 *)((int)&chan[2].rx + 2) = 0;
        *(undefined2 *)&chan[2].tx = 0;
        uVar5 = extraout_r1_00;
      }
      pnVar2 = *(net_buf **)((int)&chan[1].tx_queue + 1);
      if (pnVar2 != (net_buf *)0x0) {
        net_buf_unref(pnVar2);
        *(undefined4 *)((int)&chan[1].tx_queue + 1) = 0;
        uVar5 = extraout_r1_01;
      }
      while (timeout.ticks._4_4_ = 0, timeout.ticks._0_4_ = uVar5,
            pnVar2 = net_buf_get((k_fifo *)&chan->ident,timeout), pnVar2 != (net_buf *)0x0) {
        net_buf_unref(pnVar2);
        uVar5 = extraout_r1_03;
      }
      uVar5 = extraout_r1_02;
      while (timeout_00.ticks._4_4_ = 0, timeout_00.ticks._0_4_ = uVar5,
            pnVar2 = net_buf_get((k_fifo *)&chan[2]._sdu_len,timeout_00), pnVar2 != (net_buf *)0x0)
      {
        net_buf_unref(pnVar2);
        uVar5 = extraout_r1_04;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(chan->rx + 0x1c);
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0005aaaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(chan,puVar6);
        return;
      }
      return;
    }
    aVar3 = atomic_get((atomic_t *)((int)&chan->_sdu + 2));
    if (aVar3 == 0) {
      *extraout_r3 = (uint)credits;
      puVar4 = net_buf_add((net_buf *)&(pnVar2->field6_0xc).field0,4);
      uVar1 = *(undefined2 *)((int)&chan->tx_buf + 2);
      puVar4[1] = credits;
      *puVar4 = uVar1;
      l2cap_send((bt_conn *)chan->chan,(uint16_t)pnVar2,buf);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","atomic_get(&chan->rx.credits) == 0",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",0x905);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "bt_l2cap_chan_get_state(&chan->chan) == BT_L2CAP_CONNECTED",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",2296);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


