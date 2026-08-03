/*
 * Function: bt_buf_get_evt
 * Entry:    00056598
 * Prototype: net_buf * __stdcall bt_buf_get_evt(uint8_t evt, bool discardable, k_timeout_t timeout)
 */


/* exclude_from_export_ai */

net_buf * bt_buf_get_evt(uint8_t evt,bool discardable,k_timeout_t timeout)

{
  net_buf *pnVar1;
  net_buf_pool *pool;
  undefined4 uVar2;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  
  uVar2 = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  timeout_00.ticks._4_4_ = (undefined4)timeout.ticks;
  if (evt < 0x10) {
    if (0xd < evt) {
      pnVar1 = bt_buf_get_cmd_complete(timeout);
      return pnVar1;
    }
  }
  else if (evt == '\x13') {
    pool = (net_buf_pool *)&DAT_20003d54;
    goto LAB_000565b8;
  }
  if (!discardable) {
    timeout_01.ticks._4_4_ = timeout_00.ticks._4_4_;
    timeout_01.ticks._0_4_ = uVar2;
    pnVar1 = bt_buf_get_rx(1,timeout_01);
    return pnVar1;
  }
  pool = (net_buf_pool *)&DAT_20003c84;
LAB_000565b8:
  timeout_00.ticks._0_4_ = uVar2;
  pnVar1 = net_buf_alloc(pool,timeout_00);
  if (pnVar1 == (net_buf *)0x0) {
    pnVar1 = (net_buf *)0x0;
  }
  else {
    net_buf_reserve((net_buf *)&(pnVar1->field6_0xc).field0,1);
    *(undefined1 *)&pnVar1->user_data = 1;
  }
  return pnVar1;
}


