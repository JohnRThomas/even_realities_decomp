/*
 * Function: net_buf_alloc
 * Entry:    00086e96
 * Prototype: net_buf * __stdcall net_buf_alloc(net_buf_pool * pool, k_timeout_t timeout)
 */


/* exclude_from_export */

net_buf * net_buf_alloc(net_buf_pool *pool,k_timeout_t timeout)

{
  net_buf *pnVar1;
  undefined4 in_r3;
  k_timeout_t timeout_00;
  
  timeout_00.ticks._0_4_ = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  timeout_00.ticks._4_4_ = in_r3;
  pnVar1 = net_buf_alloc_len(pool,**(size_t **)(*(int *)((int)&pool[1].buf_count + 1) + 4),
                             timeout_00);
  return pnVar1;
}


