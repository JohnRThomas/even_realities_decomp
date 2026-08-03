/*
 * Function: bt_recv
 * Entry:    00057ad4
 * Prototype: int __stdcall bt_recv(net_buf * buf)
 */


/* exclude_from_export */

int bt_recv(net_buf *buf)

{
  byte bVar1;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 uStack_20;
  char *pcStack_1c;
  uint uStack_18;
  
  uStack_18 = (uint)*(byte *)&buf->user_data;
  if (uStack_18 == 1) {
    bVar1 = bt_hci_evt_get_flags(*(buf->field6_0xc).field0.data);
    if ((int)((uint)bVar1 << 0x1f) < 0) {
      hci_event_prio(buf);
    }
    if (-1 < (int)((uint)bVar1 << 0x1e)) {
      return 0;
    }
  }
  else if (uStack_18 != 3) {
    pcStack_1c = "Invalid buf type %u";
    uStack_20 = 3;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&uStack_20,3,in_stack_ffffffd0,in_stack_ffffffd4,
            in_stack_ffffffd8);
    net_buf_unref(buf);
    return -0x16;
  }
  rx_queue_put(buf);
  return 0;
}


