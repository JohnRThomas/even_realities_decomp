/*
 * Function: bt_att_sent
 * Entry:    000858fe
 * Prototype: void __stdcall bt_att_sent(bt_l2cap_chan * ch)
 */


/* exclude_from_export */

void bt_att_sent(bt_l2cap_chan *ch)

{
  bt_att_req *req;
  int iVar1;
  undefined *puVar2;
  undefined **chan;
  
  puVar2 = ch[-1].destroy;
  chan = &ch[-1].destroy;
  atomic_clear_bit((atomic_t *)(ch + 0xe),4);
  if (puVar2 != (undefined *)0x0) {
    if ((ch[0xe].ops == (undefined *)0x0) && (*(int *)(puVar2 + 4) != 0)) {
      req = (bt_att_req *)sys_slist_get((sys_slist_t *)(puVar2 + 4));
      iVar1 = chan_req_send((bt_att_chan *)chan,req);
      if (-1 < iVar1) {
        return;
      }
      req->node = *(undefined **)(puVar2 + 4);
      *(bt_att_req **)(puVar2 + 4) = req;
      if (*(int *)(puVar2 + 8) == 0) {
        *(bt_att_req **)(puVar2 + 8) = req;
      }
    }
    iVar1 = process_queue((bt_att_chan *)chan,(k_fifo *)&ch[0xe].node);
    if (iVar1 != 0) {
      process_queue((bt_att_chan *)chan,(k_fifo *)(puVar2 + 0xc));
      return;
    }
  }
  return;
}


