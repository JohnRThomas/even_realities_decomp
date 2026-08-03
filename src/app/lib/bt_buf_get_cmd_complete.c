/*
 * Function: bt_buf_get_cmd_complete
 * Entry:    00056560
 * Prototype: net_buf * __stdcall bt_buf_get_cmd_complete(k_timeout_t timeout)
 */


/* exclude_from_export_ai */

net_buf * bt_buf_get_cmd_complete(k_timeout_t timeout)

{
  net_buf *pnVar1;
  k_timeout_t timeout_00;
  
  pnVar1 = DAT_20002140;
  DAT_20002140 = (net_buf *)0x0;
  if (pnVar1 != (net_buf *)0x0) {
    (pnVar1->field6_0xc).field0.len = 0;
    *(undefined1 *)&pnVar1->user_data = 1;
    net_buf_reserve((net_buf *)&(pnVar1->field6_0xc).field0,1);
    return pnVar1;
  }
  timeout_00.ticks._4_4_ = (int)timeout.ticks;
  timeout_00.ticks._0_4_ = &DAT_20002140;
  pnVar1 = bt_buf_get_rx(1,timeout_00);
  return pnVar1;
}


