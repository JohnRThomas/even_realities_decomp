/*
 * Function: bt_conn_create_pdu_timeout
 * Entry:    00059c98
 * Prototype: net_buf * __stdcall bt_conn_create_pdu_timeout(net_buf_pool * pool, size_t reserve, k_timeout_t timeout)
 */


/* exclude_from_export */

net_buf * bt_conn_create_pdu_timeout(net_buf_pool *pool,size_t reserve,k_timeout_t timeout)

{
  bool bVar1;
  net_buf *pnVar2;
  k_timeout_t timeout_00;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  timeout_00.ticks._4_4_ = (undefined4)timeout.ticks;
  bVar1 = k_is_in_isr();
  if (bVar1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!k_is_in_isr()",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1373);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (pool == (net_buf_pool *)0x0) {
    pool = (net_buf_pool *)&DAT_20003c1c;
  }
  timeout_00.ticks._0_4_ = &DAT_20003c1c;
  pnVar2 = net_buf_alloc(pool,timeout_00);
  if (pnVar2 == (net_buf *)0x0) {
    local_1c = "Unable to allocate buffer within timeout";
    local_20 = 2;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1080,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
            in_stack_ffffffd8);
  }
  else {
    net_buf_reserve((net_buf *)&(pnVar2->field6_0xc).field0,reserve + 5);
  }
  return pnVar2;
}


