/*
 * Function: hci_id_add
 * Entry:    0008478a
 * Prototype: int __stdcall hci_id_add(uint8_t id, bt_addr_le_t * addr, uint8_t * peer_irk)
 */


/* exclude_from_export_ai */

int hci_id_add(uint8_t id,bt_addr_le_t *addr,uint8_t *peer_irk)

{
  net_buf *buf;
  bt_addr_le_t *dst;
  int extraout_r0;
  int iVar1;
  uint8_t *extraout_r2;
  uint8_t *puVar2;
  undefined4 *puVar4;
  uint8_t *puVar3;
  
  if (id == '\0') {
    buf = bt_hci_cmd_create(0x2027,'\'');
    if (buf != (net_buf *)0x0) {
      dst = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x27);
      bt_addr_le_copy(dst,addr);
      puVar3 = extraout_r2;
      puVar4 = (undefined4 *)(extraout_r0 + 7);
      do {
        puVar2 = puVar3 + 4;
        *puVar4 = *(undefined4 *)puVar3;
        puVar3 = puVar2;
        puVar4 = puVar4 + 1;
      } while (puVar2 != peer_irk + 0x10);
      memset(dst[3].a.val + 1,0,0x10);
      iVar1 = bt_hci_cmd_send_sync(0x2027,buf,(net_buf **)0x0);
      return iVar1;
    }
    iVar1 = -0x69;
  }
  else {
    iVar1 = -0x16;
  }
  return iVar1;
}


