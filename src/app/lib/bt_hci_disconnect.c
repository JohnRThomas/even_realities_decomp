/*
 * Function: bt_hci_disconnect
 * Entry:    00084690
 * Prototype: int __stdcall bt_hci_disconnect(uint16_t handle, uint8_t reason)
 */


/* exclude_from_export */

int bt_hci_disconnect(uint16_t handle,uint8_t reason)

{
  net_buf *buf;
  uint16_t *puVar1;
  int iVar2;
  
  buf = bt_hci_cmd_create(0x406,'\x03');
  if (buf != (net_buf *)0x0) {
    puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,3);
    *puVar1 = handle;
    *(uint8_t *)(puVar1 + 1) = reason;
    iVar2 = bt_hci_cmd_send_sync(0x406,buf,(net_buf **)0x0);
    return iVar2;
  }
  return -0x69;
}


