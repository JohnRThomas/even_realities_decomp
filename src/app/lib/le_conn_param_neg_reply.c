/*
 * Function: le_conn_param_neg_reply
 * Entry:    0008470e
 * Prototype: void __stdcall le_conn_param_neg_reply(uint16_t handle, uint8_t reason)
 */


/* exclude_from_export */

void le_conn_param_neg_reply(uint16_t handle,uint8_t reason)

{
  net_buf *buf;
  uint16_t *puVar1;
  uint8_t *extraout_r1;
  void *extraout_r2;
  
  buf = bt_hci_cmd_create(0x2021,'\x03');
  if (buf == (net_buf *)0x0) {
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&stack0xfffffff0,2,0,extraout_r1,extraout_r2);
    return;
  }
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,3);
  *puVar1 = handle;
  *(uint8_t *)(puVar1 + 1) = reason;
  bt_hci_cmd_send(0x2021,buf);
  return;
}


