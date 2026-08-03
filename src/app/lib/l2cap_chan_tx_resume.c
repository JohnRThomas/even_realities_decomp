/*
 * Function: l2cap_chan_tx_resume
 * Entry:    00084ed8
 * Prototype: void __stdcall l2cap_chan_tx_resume(bt_l2cap_le_chan * ch)
 */


/* exclude_from_export */

void l2cap_chan_tx_resume(bt_l2cap_le_chan *ch)

{
  atomic_val_t aVar1;
  uint extraout_r1;
  k_timeout_t delay;
  
  aVar1 = atomic_get((atomic_t *)((int)&ch->state + 2));
  if ((aVar1 != 0) && ((*(int *)(extraout_r1 + 0x30) != 0 || (*(int *)(extraout_r1 + 0x4c) != 0))))
  {
    delay.ticks._4_4_ = 0;
    delay.ticks._0_4_ = extraout_r1;
    k_work_reschedule((k_work_delayable *)(extraout_r1 + 0x50),delay);
    return;
  }
  return;
}


