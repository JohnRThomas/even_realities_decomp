/*
 * Function: bt_att_status
 * Entry:    00085824
 * Prototype: void __stdcall bt_att_status(bt_l2cap_chan * ch, atomic_t * status)
 */


/* exclude_from_export */

void bt_att_status(bt_l2cap_chan *ch,atomic_t *status)

{
  bt_att_req *req;
  int iVar1;
  undefined *puVar2;
  
  if ((((*status << 0x1f < 0) && (ch[-1].destroy != (undefined *)0x0)) &&
      (ch[0xe].ops == (undefined *)0x0)) &&
     ((req = (bt_att_req *)sys_slist_get((sys_slist_t *)(ch[-1].destroy + 4)),
      req != (bt_att_req *)0x0 &&
      (iVar1 = bt_att_chan_req_send((bt_att_chan *)&ch[-1].destroy,req), iVar1 < 0)))) {
    puVar2 = ch[-1].destroy;
    req->node = *(undefined **)(puVar2 + 4);
    *(bt_att_req **)(puVar2 + 4) = req;
    if (*(int *)(puVar2 + 8) == 0) {
      *(bt_att_req **)(puVar2 + 8) = req;
    }
  }
  return;
}


