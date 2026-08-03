/*
 * Function: bt_att_req_send
 * Entry:    0005cd3c
 * Prototype: int __stdcall bt_att_req_send(bt_conn * conn, bt_att_req * req)
 */


/* exclude_from_export_ai */

int bt_att_req_send(bt_conn *conn,bt_att_req *req)

{
  bt_att *att;
  int uVar2;
  
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",
            0xf38);
  }
  else {
    if (req != (bt_att_req *)0x0) {
      att = att_get(conn);
      if (att == (bt_att *)0x0) {
        uVar2 = -0x80;
      }
      else {
        req->node = (undefined *)0x0;
        if ((undefined4 *)att->tx_queue == (undefined4 *)0x0) {
          att->reqs = (undefined *)req;
          att->tx_queue = (dword)req;
        }
        else {
          *(undefined4 *)att->tx_queue = req;
          att->tx_queue = (dword)req;
        }
        att_req_send_process(att);
        uVar2 = 0;
      }
      return uVar2;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","req","WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",
            0xf39);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


