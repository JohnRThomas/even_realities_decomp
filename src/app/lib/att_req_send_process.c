/*
 * Function: att_req_send_process
 * Entry:    00085866
 * Prototype: void __stdcall att_req_send_process(bt_att * att)
 */


/* exclude_from_export_ai */

void att_req_send_process(bt_att *att)

{
  int iVar1;
  int *piVar2;
  bt_att_chan *pbVar3;
  bt_att_req *req;
  bt_att_chan *pbVar4;
  bt_att_chan *pbVar5;
  bt_att_chan *chan;
  
  piVar2 = *(int **)((int)&att[1].prep_queue + 2);
  if (piVar2 == (int *)0x0) {
    return;
  }
  pbVar4 = (bt_att_chan *)0x0;
  if (*piVar2 != 0) {
    pbVar4 = (bt_att_chan *)(*piVar2 + -400);
  }
  pbVar3 = (bt_att_chan *)0x0;
  req = (bt_att_req *)0x0;
  chan = (bt_att_chan *)(piVar2 + -100);
  while( true ) {
    pbVar5 = pbVar4;
    if ((chan[8].chan == 0) &&
       (((req != (bt_att_req *)0x0 || (pbVar3 == (bt_att_chan *)0x0)) &&
        (req = (bt_att_req *)sys_slist_get((sys_slist_t *)&att->reqs), pbVar3 = chan,
        req != (bt_att_req *)0x0)))) {
      iVar1 = bt_att_chan_req_send(chan,req);
      if (-1 < iVar1) {
        return;
      }
      req->node = att->reqs;
      att->reqs = (undefined *)req;
      if (att->tx_queue == 0) {
        att->tx_queue = (dword)req;
      }
    }
    if (pbVar5 == (bt_att_chan *)0x0) break;
    pbVar4 = (bt_att_chan *)0x0;
    chan = pbVar5;
    if (pbVar5[0xb].chan != 0) {
      pbVar4 = (bt_att_chan *)(pbVar5[0xb].chan - 400);
    }
  }
  return;
}


