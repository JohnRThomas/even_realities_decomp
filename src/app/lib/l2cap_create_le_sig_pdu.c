/*
 * Function: l2cap_create_le_sig_pdu
 * Entry:    0005a6a0
 * Prototype: net_buf * __stdcall l2cap_create_le_sig_pdu(net_buf * buf, uint8_t code, uint8_t ident, uint16_t len)
 */


/* exclude_from_export */

net_buf * l2cap_create_le_sig_pdu(net_buf *buf,uint8_t code,uint8_t ident,uint16_t len)

{
  net_buf_pool *pool;
  net_buf *pnVar1;
  undefined1 *puVar2;
  uint local_18;
  
  local_18 = (uint)len;
  pool = (net_buf_pool *)&DAT_20003c50;
  if (buf != (net_buf *)&DAT_00000006) {
    pool = (net_buf_pool *)0x0;
  }
  pnVar1 = bt_conn_create_pdu_timeout(pool,4,(k_timeout_t)0x10000);
  if (pnVar1 == (net_buf *)0x0) {
    local_18 = 3;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1840,(byte *)&local_18);
    return (net_buf *)0x0;
  }
  puVar2 = net_buf_add((net_buf *)&(pnVar1->field6_0xc).field0,4);
  *puVar2 = (char)buf;
  puVar2[1] = code;
  *(ushort *)(puVar2 + 2) = (ushort)ident;
  return pnVar1;
}


