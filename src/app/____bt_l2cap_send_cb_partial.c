/*
 * Function: $_?_bt_l2cap_send_cb_partial
 * Entry:    00086eb0
 * Prototype: undefined __stdcall $_?_bt_l2cap_send_cb_partial(net_buf * param_1, undefined4 param_2)
 */


void ____bt_l2cap_send_cb_partial(net_buf *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = net_buf_push(param_1,2);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


