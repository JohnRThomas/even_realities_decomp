/*
 * Function: l2cap_chan_tx_give_credits
 * Entry:    00084f04
 * Prototype: void __stdcall l2cap_chan_tx_give_credits(bt_l2cap_chan * chan, uint16_t credits)
 */


/* exclude_from_export */

void l2cap_chan_tx_give_credits(bt_l2cap_chan *chan,uint16_t credits)

{
  uint uVar1;
  
  chan[2].ops = chan[2].ops + credits;
  uVar1 = chan->BT_L2CAP_NUM_STATUS_;
  chan->BT_L2CAP_NUM_STATUS_ = uVar1 | 1;
  if ((-1 < (int)(uVar1 << 0x1f)) && (*(code **)(chan->ops + 0x1c) != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00084f3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(chan->ops + 0x1c))();
    return;
  }
  return;
}


