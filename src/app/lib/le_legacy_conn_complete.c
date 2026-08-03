/*
 * Function: le_legacy_conn_complete
 * Entry:    00057454
 * Prototype: void __stdcall le_legacy_conn_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void le_legacy_conn_complete(net_buf *buf)

{
  byte *pbVar1;
  bt_addr_t *src;
  bt_hci_evt_le_enh_conn_complete local_28;
  
  pbVar1 = (buf->field6_0xc).field0.data;
  local_28.status = *pbVar1;
  local_28.handle = *(word *)(pbVar1 + 1);
  local_28.role = pbVar1[3];
  local_28.interval = *(word *)(pbVar1 + 0xb);
  local_28.latency = *(word *)(pbVar1 + 0xd);
  local_28.supv_timeout = *(word *)(pbVar1 + 0xf);
  local_28.clock_accuracy = pbVar1[0x11];
  bt_addr_le_copy(&local_28.peer_addr,(bt_addr_le_t *)(pbVar1 + 4));
  bt_addr_copy(&local_28.local_rpa,(bt_addr_t *)&DAT_000f0b5d);
  bt_addr_copy(&local_28.peer_rpa,src);
  bt_hci_le_enh_conn_complete(&local_28);
  return;
}


