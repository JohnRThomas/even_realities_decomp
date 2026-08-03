/*
 * Function: bt_l2cap_create_pdu_timeout
 * Entry:    00084fd2
 * Prototype: net_buf * __stdcall bt_l2cap_create_pdu_timeout(net_buf_pool * pool, size_t reserve, k_timeout_t timeout)
 */


/* exclude_from_export_ai */

net_buf * bt_l2cap_create_pdu_timeout(net_buf_pool *pool,size_t reserve,k_timeout_t timeout)

{
  net_buf *pnVar1;
  
  pnVar1 = bt_conn_create_pdu_timeout(pool,reserve + 4,timeout);
  return pnVar1;
}


