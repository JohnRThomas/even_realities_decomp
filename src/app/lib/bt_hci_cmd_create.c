/*
 * Function: bt_hci_cmd_create
 * Entry:    00084670
 * Prototype: net_buf * __stdcall bt_hci_cmd_create(uint16_t opcode, uint8_t param_len)
 */


/* exclude_from_export_ai */

net_buf * bt_hci_cmd_create(uint16_t opcode,uint8_t param_len)

{
  uint16_t *in_r2;
  
  *in_r2 = opcode;
  *(undefined1 *)((int)in_r2 + 3) = 0;
  *(undefined1 *)(in_r2 + 1) = 0;
  *(undefined1 *)(in_r2 + 2) = 0;
  *(undefined1 *)((int)in_r2 + 5) = 0;
  *(undefined1 *)(in_r2 + 3) = 0;
  *(undefined1 *)((int)in_r2 + 7) = 0;
  return (net_buf *)0x0;
}


