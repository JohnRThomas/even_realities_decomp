/*
 * Function: hci_hardware_error
 * Entry:    00056874
 * Prototype: void __stdcall hci_hardware_error(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_hardware_error(net_buf *buf)

{
  byte *pbVar1;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 uStack_18;
  char *pcStack_14;
  uint uStack_10;
  
  pbVar1 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,1);
  uStack_10 = (uint)*pbVar1;
  pcStack_14 = "Hardware error, hardware code: %d";
  uStack_18 = 3;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&uStack_18,3,in_stack_ffffffd8,in_stack_ffffffdc,
          in_stack_ffffffe0);
  return;
}


