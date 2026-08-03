/*
 * Function: bt_att_chan_req_send
 * Entry:    0005be24
 * Prototype: int __stdcall bt_att_chan_req_send(bt_att_chan * chan, bt_att_req * req)
 */


/* exclude_from_export_ai */

int bt_att_chan_req_send(bt_att_chan *chan,bt_att_req *req)

{
  int iVar1;
  
  if (chan == (bt_att_chan *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan","WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",
            892);
  }
  else if (req == (bt_att_req *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","req","WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",
            893);
  }
  else if (req->func == (undefined *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","req->func",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",894);
  }
  else {
    if (chan[8].chan == 0) {
      iVar1 = chan_req_send(chan,req);
      return iVar1;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!chan->req",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",895);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


