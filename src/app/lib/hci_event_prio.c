/*
 * Function: hci_event_prio
 * Entry:    00057a30
 * Prototype: void __stdcall hci_event_prio(net_buf * buf)
 */


/* exclude_from_export */

void hci_event_prio(net_buf *buf)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  size_t sVar4;
  byte *pbVar5;
  
  sVar4 = net_buf_simple_headroom(&(buf->field6_0xc).b);
  uVar1 = (buf->field6_0xc).field0.len;
  if (uVar1 < 2) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->len >= sizeof(*hdr)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",3717);
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0);
    }
    software_interrupt(2);
  }
  pbVar5 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,2);
  bVar3 = bt_hci_evt_get_flags(*pbVar5);
  if (-1 < (int)((uint)bVar3 << 0x1f)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","evt_flags & (1UL << (0))",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",3721);
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0);
    }
    software_interrupt(2);
  }
  handle_event((dtls_context_t *)(uint)*pbVar5,(session_t *)buf,0x8ecf8,5);
  if ((int)((uint)bVar3 << 0x1e) < 0) {
    (buf->field6_0xc).field0.len = uVar1;
    (buf->field6_0xc).field0.data = (buf->field6_0xc).field0.__buf + (sVar4 & 0xffff);
    return;
  }
  net_buf_unref(buf);
  return;
}


