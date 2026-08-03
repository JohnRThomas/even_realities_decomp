/*
 * Function: hci_le_meta_event
 * Entry:    00056b1c
 * Prototype: void __stdcall hci_le_meta_event(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_le_meta_event(net_buf *buf)

{
  byte *pbVar1;
  
  pbVar1 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,1);
  handle_event((dtls_context_t *)(uint)*pbVar1,(session_t *)buf,
               (dtls_alert_level_t)&PTR_DAT_0008ed50,10);
  return;
}


