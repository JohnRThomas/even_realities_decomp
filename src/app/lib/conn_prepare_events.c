/*
 * Function: conn_prepare_events
 * Entry:    00059870
 * Prototype: int __stdcall conn_prepare_events(bt_conn * conn, k_poll_event * events)
 */


/* exclude_from_export_ai */

int conn_prepare_events(bt_conn *conn,k_poll_event *events)

{
  int extraout_r0;
  uint32_t type;
  k_fifo *obj;
  
  sys_dlist_init((sys_dlist_t *)&conn_change);
  k_poll_event_init((k_poll_event *)conn,1,0,&conn_change);
  if (acl_conns.ref != 0) {
    if ((acl_conns.state == 0) &&
       (atomic_set_bit_to((atomic_t *)&acl_conns.flags,-0x41,SUB41(acl_conns.ref,0)),
       extraout_r0 << 0x19 < 0)) {
      conn_cleanup(&acl_conns);
    }
    else if ((acl_conns.state == 7) && (DAT_20002104 != 0)) {
      if ((acl_conns.tx_queue._queue.data_q.head == (sys_sfnode_t *)0x0) || (DAT_20002110 != 0)) {
        type = 4;
        obj = &acl_conns.tx_queue;
      }
      else {
        type = 2;
        obj = (k_fifo *)&DAT_20002108;
      }
      k_poll_event_init((k_poll_event *)&conn->tx_pending,type,0,obj);
      *(undefined1 *)&conn->tx_complete = 1;
      return 2;
    }
  }
  return 1;
}


