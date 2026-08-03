/*
 * Function: addr_res_enable
 * Entry:    00084808
 * Prototype: int __stdcall addr_res_enable(uint8_t enable)
 */


/* exclude_from_export_ai */

int addr_res_enable(uint8_t enable)

{
  net_buf *buf;
  int iVar1;
  
  buf = bt_hci_cmd_create(0x202d,'\x01');
  if (buf != (net_buf *)0x0) {
    net_buf_add_u8((net_buf *)&(buf->field6_0xc).field0,enable);
    iVar1 = bt_hci_cmd_send_sync(0x202d,buf,(net_buf **)0x0);
    return iVar1;
  }
  return -0x69;
}


