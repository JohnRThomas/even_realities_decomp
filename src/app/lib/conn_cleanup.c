/*
 * Function: conn_cleanup
 * Entry:    000595ac
 * Prototype: void __stdcall conn_cleanup(bt_conn * conn)
 */


/* exclude_from_export */

void conn_cleanup(bt_conn *conn)

{
  net_buf *buf;
  uint in_r1;
  char *test;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  char *file;
  int line;
  bt_conn_tx *tx;
  k_timeout_t timeout;
  k_timeout_t delay;
  
  do {
    do {
      timeout.ticks._4_4_ = 0;
      timeout.ticks._0_4_ = in_r1;
      buf = net_buf_get(&conn->tx_queue,timeout);
      if (buf == (net_buf *)0x0) {
        if (conn->tx_pending == 0) {
          if (conn->pending_no_cb == 0) {
            bt_conn_reset_rx_state(conn);
            delay.ticks._4_4_ = 0;
            delay.ticks._0_4_ = extraout_r1_01;
            k_work_reschedule(&conn->deferred_work,delay);
            return;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn->pending_no_cb == 0",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",788);
        }
        else {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","sys_slist_is_empty(&conn->tx_pending)",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",787);
          _ASSERT("\tPending TX packets\n",test,file,line);
        }
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      tx = (bt_conn_tx *)buf->user_data;
      buf->user_data = (uint8_t *)0x0;
      net_buf_unref(buf);
      in_r1 = extraout_r1;
    } while (tx == (bt_conn_tx *)0x0);
    conn_tx_destroy(conn,tx);
    in_r1 = extraout_r1_00;
  } while( true );
}


