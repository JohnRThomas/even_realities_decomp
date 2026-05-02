/*
 * Function: $_?_l2cap_chan_tx_give_credits
 * Entry:    0005a798
 * Prototype: void __stdcall $_?_l2cap_chan_tx_give_credits(bt_l2cap_le_chan * chan, uint16_t credits)
 */


void ____l2cap_chan_tx_give_credits(bt_l2cap_le_chan *chan,uint16_t credits)

{
  *(undefined4 *)((int)&chan->rx_work + 2) = 0;
  *(undefined4 *)((int)&chan->rx_queue + 2) = 0;
  *(undefined4 *)((int)&chan->state + 2) = 0;
  *(undefined4 *)((int)&chan->state + 2) = 0;
  k_queue_init((k_queue *)&chan->ident);
  k_work_init_delayable((k_work_delayable *)((int)&chan[1].tx_buf + 1),(void *)0x85095);
  return;
}


