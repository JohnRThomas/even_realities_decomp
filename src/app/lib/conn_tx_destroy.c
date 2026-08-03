/*
 * Function: conn_tx_destroy
 * Entry:    0005932c
 * Prototype: void __stdcall conn_tx_destroy(bt_conn * conn, bt_conn_tx * tx)
 */


/* exclude_from_export */

void conn_tx_destroy(bt_conn *conn,bt_conn_tx *tx)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined *puVar1;
  
  if (tx == (bt_conn_tx *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","tx","WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",
            70);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  UNRECOVERED_JUMPTABLE = (code *)tx->cb;
  puVar1 = tx->user_data;
  tx->pending_no_cb = 0;
  tx->cb = (undefined *)0x0;
  tx->user_data = (undefined *)0x0;
  k_queue_append(&free_tx._queue,tx);
                    /* WARNING: Could not recover jumptable at 0x00059366. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(conn,puVar1,0xffffff92);
  return;
}


