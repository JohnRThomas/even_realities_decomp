/*
 * Function: bt_conn_create_frag_timeout
 * Entry:    0005a488
 * Prototype: net_buf * __stdcall bt_conn_create_frag_timeout(size_t reserve, k_timeout_t timeout)
 */


/* exclude_from_export */

net_buf * bt_conn_create_frag_timeout(size_t reserve,k_timeout_t timeout)

{
  net_buf *pnVar1;
  undefined4 in_r3;
  k_timeout_t timeout_00;
  
  timeout_00.ticks._0_4_ = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  timeout_00.ticks._4_4_ = in_r3;
  pnVar1 = bt_conn_create_pdu_timeout((net_buf_pool *)&DAT_20003cb8,reserve,timeout_00);
  return pnVar1;
}


