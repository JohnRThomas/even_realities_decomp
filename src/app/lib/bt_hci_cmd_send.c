/*
 * Function: bt_hci_cmd_send
 * Entry:    00057684
 * Prototype: int __stdcall bt_hci_cmd_send(uint16_t opcode, net_buf * buf)
 */


/* exclude_from_export */

int bt_hci_cmd_send(uint16_t opcode,net_buf *buf)

{
  int iVar1;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  int iStack_20;
  
  if ((buf == (net_buf *)0x0) && (buf = bt_hci_cmd_create(opcode,'\0'), buf == (net_buf *)0x0)) {
    iVar1 = -0x69;
  }
  else if (opcode == 0xc35) {
    iVar1 = bt_send(buf);
    if (iVar1 != 0) {
      local_24 = "Unable to send to driver (err %d)";
      local_28 = 3;
      iStack_20 = iVar1;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_28,3,in_stack_ffffffc8,in_stack_ffffffcc,
              in_stack_ffffffd0);
      net_buf_unref(buf);
    }
  }
  else {
    net_buf_put((k_fifo *)&DAT_2000214c,buf);
    iVar1 = 0;
  }
  return iVar1;
}


