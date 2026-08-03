/*
 * Function: le_set_random_address
 * Entry:    000848aa
 * Prototype: void __stdcall le_set_random_address(net_buf * buf, net_buf * * evt)
 */


/* exclude_from_export_ai */

void le_set_random_address(net_buf *buf,net_buf **evt)

{
  int iVar1;
  net_buf *buf_00;
  int extraout_r0;
  
  if ((buf != (net_buf *)0x0) && (evt != (net_buf **)0x0)) {
    iVar1 = memcmp(evt,&DAT_20002069,6);
    if ((iVar1 != 0) && (buf_00 = bt_hci_cmd_create(0x2005,'\x06'), buf_00 != (net_buf *)0x0)) {
      net_buf_add_mem((net_buf *)&(buf_00->field6_0xc).field0,evt,6);
      iVar1 = bt_hci_cmd_send_sync(0x2005,buf_00,(net_buf **)0x0);
      if (iVar1 == 0) {
        bt_addr_copy((bt_addr_t *)&DAT_20002069,(bt_addr_t *)evt);
        *(undefined1 *)(extraout_r0 + -1) = 1;
      }
    }
    return;
  }
  return;
}


