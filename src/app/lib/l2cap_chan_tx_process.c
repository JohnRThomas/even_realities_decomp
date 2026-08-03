/*
 * Function: l2cap_chan_tx_process
 * Entry:    00085094
 * Prototype: void __stdcall l2cap_chan_tx_process(k_work * work)
 */


/* exclude_from_export */

void l2cap_chan_tx_process(k_work *work)

{
  net_buf *pnVar1;
  int iVar2;
  net_buf *in_r1;
  net_buf *extraout_r1;
  k_timeout_t delay;
  k_timeout_t timeout;
  net_buf *local_1c [2];
  
  local_1c[0] = in_r1;
  do {
    pnVar1 = (net_buf *)work[-1].flags;
    if (pnVar1 == (net_buf *)0x0) {
      timeout.ticks._4_4_ = 0;
      timeout.ticks._0_4_ = in_r1;
      pnVar1 = net_buf_get((k_fifo *)(work + -2),timeout);
      if (pnVar1 == (net_buf *)0x0) {
        return;
      }
    }
    else {
      work[-1].flags = 0;
    }
    local_1c[0] = pnVar1;
    iVar2 = l2cap_chan_le_send_sdu
                      ((bt_l2cap_le_chan *)(work + -5),local_1c,*(uint16_t *)pnVar1->user_data);
    in_r1 = extraout_r1;
  } while (-1 < iVar2);
  if (iVar2 == -0xb) {
    work[-1].flags = (uint32_t)local_1c[0];
    delay.ticks._4_4_ = 0x8000;
    delay.ticks._0_4_ = extraout_r1;
    k_work_schedule((k_work_delayable *)work,delay);
    return;
  }
  net_buf_unref(local_1c[0]);
  return;
}


