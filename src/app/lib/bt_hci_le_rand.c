/*
 * Function: bt_hci_le_rand
 * Entry:    00057120
 * Prototype: int __stdcall bt_hci_le_rand(void * buffer, size_t len)
 */


/* exclude_from_export */

int bt_hci_le_rand(void *buffer,size_t len)

{
  net_buf *buf;
  int iVar1;
  uint n;
  net_buf *local_1c [2];
  
  local_1c[0] = (net_buf *)len;
  if (DAT_2000209b < '\0') {
    for (; len != 0; len = len - n) {
      n = len;
      if (7 < len) {
        n = 8;
      }
      iVar1 = bt_hci_cmd_send_sync(0x2018,(net_buf *)0x0,local_1c);
      buf = local_1c[0];
      if (iVar1 != 0) {
        return iVar1;
      }
      memcpy(buffer,(local_1c[0]->field6_0xc).field0.data + 1,n);
      net_buf_unref(buf);
      buffer = (void *)((int)buffer + n);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = -0x86;
  }
  return iVar1;
}


