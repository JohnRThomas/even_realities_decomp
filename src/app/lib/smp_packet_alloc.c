/*
 * Function: smp_packet_alloc
 * Entry:    00055990
 * Prototype: net_buf * __stdcall smp_packet_alloc(void)
 */


/* exclude_from_export_ai */

net_buf * smp_packet_alloc(void)

{
  net_buf *pnVar1;
  uint in_r1;
  k_timeout_t timeout;
  
  timeout.ticks._4_4_ = 0;
  timeout.ticks._0_4_ = in_r1;
  pnVar1 = net_buf_alloc((net_buf_pool *)&DAT_20003d88,timeout);
  return pnVar1;
}


