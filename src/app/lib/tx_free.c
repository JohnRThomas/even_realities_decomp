/*
 * Function: tx_free
 * Entry:    0005a658
 * Prototype: void __stdcall tx_free(bt_conn_tx * tx)
 */


/* exclude_from_export_ai */

void tx_free(bt_conn_tx *tx)

{
  memset(tx,0,0x10);
  k_queue_append(&free_l2cap_channs._queue,tx);
  return;
}


